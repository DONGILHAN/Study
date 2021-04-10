import cv2
import pyautogui as AG
import pkg_resources.py2_warn
font = cv2.FONT_ITALIC



def faceDetect():

    face_cascade = cv2.CascadeClassifier('haarcascade_frontface.xml')
    eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

    try:
        cam = cv2.VideoCapture(0)
    except:
        print("camera loading error")
        return

    mode = 0
    first_flag = 0
    blinksearch = 0
    binary_threshold = 70

    while True:
        ret, frame = cam.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # 강제종료 감지
        break_x, break_y = 40, 40
        break_frame = gray[1:break_x, 1:break_y]
        ret, break_binary = cv2.threshold(break_frame, 1, 255, cv2.THRESH_BINARY_INV)

        break_height = break_binary.shape[0]
        break_width = break_binary.shape[1]

        break_black = 0
        break_white = 0
        for break_yy in range(0, break_height):
            for break_xx in range(0, break_width):
                find_break = break_binary[break_yy, break_xx]
                if find_break == 0:
                    break_black += 1
                else:
                    break_white += 1
        if break_white > 100:
            break
        # 강제종료 감지 끝


        if mode == 0:

            faces = face_cascade.detectMultiScale(gray, 1.3, 5)

            for (x, y, w, h) in faces:
                cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
                frame_x = x
                frame_y = y


                h /= 2
                h= int(h)

                roi_gray = gray[y:y + h, x:x + w]
                roi_color = frame[y:y + h, x:x + w]
                eyes = eye_cascade.detectMultiScale(roi_gray)

                ex_a = [1, 1]
                ey_a = [1, 1]
                ew_a = [1, 1]
                eh_a = [1, 1]

                eye_count = 0

                for (ex, ey, ew, eh) in eyes:

                    ex_a[eye_count] = ex
                    ey_a[eye_count] = ey
                    ew_a[eye_count] = ew
                    eh_a[eye_count] = eh

                    eye_count += 1
                    if eye_count is 2:
                        break

                for i in range(len(ex_a) - 1, 0, -1):
                    for j in range(i):
                        if ex_a[j] > ex_a[j + 1]:
                            ex_a[j], ex_a[j + 1] = ex_a[j + 1], ex_a[j]
                            ey_a[j], ey_a[j + 1] = ey_a[j + 1], ey_a[j]
                            ew_a[j], ew_a[j + 1] = ew_a[j + 1], ew_a[j]
                            eh_a[j], eh_a[j + 1] = eh_a[j + 1], eh_a[j]

                # 오른쪽 눈
                find_y = int(eh_a[0] / 3)
                if find_y is 0:
                    find_y = 1
                roi_eye = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]
                roi_eye_color = roi_color[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]
                ret, eye_binary = cv2.threshold(roi_eye, binary_threshold, 255, cv2.THRESH_BINARY_INV)
                cv2.imshow('eye_binary', eye_binary)
                # 오른쪽눈 끝


                cv2.imshow('roi_eye', roi_eye_color)

                # 눈동자 좌표찾기
                contours, _ = cv2.findContours(eye_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
                contours = sorted(contours, key=lambda x: cv2.contourArea(x), reverse=True)
                # test_y, test_x = eye_binary.shape
                for cnt in contours:
                    (a, b, c, d) = cv2.boundingRect(cnt)
                    cv2.rectangle(roi_eye_color, (a, b), (a + c, b + d), (0, 0, 255), 1)
                    contour_x = int((a + a + c) / 2)
                    contour_y = int((b + b + d) / 2)
                    real_x = frame_x + ex_a[0] + contour_x
                    real_y = frame_y + ey_a[0] + find_y + contour_y
                    cv2.circle(frame, (real_x, real_y), 1, (0, 0, 255), 2)
                    #print(real_x, real_y)
                    break
                # 눈동자 좌표찾기 끝




        elif mode == 1:



            roi_gray = gray[y:y + h, x:x + w]
            roi_color = frame[y:y + h, x:x + w]


            roi_eye = roi_gray[ey_a[0] : ey_a[0] + eh_a[0], ex_a[0]:ex_a[0] + ew_a[0]]

            roi_eye_color = roi_color[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]
            ret, eye_binary = cv2.threshold(roi_eye, binary_threshold, 255, cv2.THRESH_BINARY_INV)


            #깜빡임 감지
            binary_height = eye_binary.shape[0]
            binary_width = eye_binary.shape[1]

            detect_black = 0
            detect_white = 0
            for blink_y in range(0,binary_height):
                for blink_x in range(0, binary_width):
                    find_blink = eye_binary[blink_y,blink_x]

                    if find_blink == 0:
                        detect_black += 1
                    else:
                        detect_white += 1

            if detect_white < 30:
                print('blink detected')
                blinksearch += 1
                if blinksearch ==3:
                    AG.click()
                    print("BLINK")
                    blinksearch = 0

            #깜빡임 감지 끝
            

            cv2.imshow('eye_binary', eye_binary)

            #눈동자 좌표찾기
            contours, _ = cv2.findContours(eye_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            contours = sorted(contours, key=lambda x: cv2.contourArea(x), reverse=True)

            if first_flag == 0:
                for cnt in contours:
                    (a, b, c, d) = cv2.boundingRect(cnt)
                    cv2.rectangle(roi_eye_color, (a,b),(a+c,b+d),(0,0,255),1)
                    contour_x = int((a+a+c)/2)
                    contour_y = int((b+b+d)/2)
                    eye_x = frame_x + ex_a[0] + contour_x
                    eye_y = frame_y + ey_a[0] + find_y + contour_y
                    cv2.circle(frame, (eye_x, eye_y), 1, (0, 0, 255), 2)
                    k = cv2.waitKey(30)
                    if k == 13:
                        first_flag = 1
                    break
            elif first_flag ==1:
                for cnt in contours:
                    (a, b, c, d) = cv2.boundingRect(cnt)
                    cv2.rectangle(roi_eye_color, (a,b),(a+c,b+d),(0,0,255),1)
                    contour_x = int((a+a+c)/2)
                    contour_y = int((b+b+d)/2)
                    now_eye_x = frame_x + ex_a[0] + contour_x
                    now_eye_y = frame_y + ey_a[0] + find_y + contour_y
                    cv2.circle(frame, (eye_x, eye_y), 1, (0, 0, 255), 2)
                    cv2.circle(frame, (now_eye_x, now_eye_y), 1, (0, 0, 255), 2)
                    cv2.line(frame, (eye_x, eye_y), (now_eye_x, now_eye_y), (0, 0, 100), 2)
                    move_x = now_eye_x - eye_x
                    move_y = now_eye_y - eye_y
                    currentMouseX, currentMouseY = AG.position()
                    if (abs(move_x) < 3 and abs(move_y) < 3):
                        break
                    elif (abs(move_x) > 10 or abs(move_y) > 10):
                        break
                    else:
                        AG.moveTo(currentMouseX - move_x, currentMouseY + move_y)
                        blinksearch = 0
                        #print(move_x, move_y)

                    break

            #눈동자 좌표찾기 끝


            cv2.imshow('roi_eye', roi_eye_color)

        cv2.imshow("frame", frame)
        cv2.imshow('frame_binary', break_binary)

        k = cv2.waitKey(30)

        if k == 49:
            mode = 1
        elif k == 50:
            mode = 0
            first_flag = 0
        elif k == 51:
            break

    cam.release()
    cv2.destroyAllWindows()


faceDetect()

