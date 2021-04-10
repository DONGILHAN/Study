import cv2
import pyautogui as AG

font = cv2.FONT_ITALIC


def faceDetect():

    face_cascade = cv2.CascadeClassifier('haarcascade_frontface.xml')
    eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

    try:
        cam = cv2.VideoCapture(0)
    except:
        print("camera loading error")
        return


    #while brk_flag == 0:
    detect_left = 0 #왼쪽시선 감지
    detect_right = 0 #오른쪽시선 감지
    detect_blink = 0 #깜빡임 감지
    detect_up = 0 #위 감지
    detect_down = 0 #아래 감지

    while True:
        #brk_flag = 0
        ret, frame = cam.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)


        for (x, y, w, h) in faces:

            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

            h /= 2
            h= int(h)

            roi_gray = gray[y:y + h, x:x + w]
            roi_color = frame[y:y + h, x:x + w]
            eyes = eye_cascade.detectMultiScale(roi_gray)

            #깜빡임 감지
            if eyes is ():
                print('blink detected')
                detect_right = 0
                detect_left = 0
                detect_up = 0
                detect_blink += 1
                if detect_blink == 2:
                    print('BLINK')
                    AG.doubleClick()
                    detect_blink = 0
            #깜빡임 감지 끝


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


            #오른쪽 눈
            find_y = int(eh_a[0]/3)
            if find_y is 0:
                find_y = 1
            roi_eye = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]
            ret, eye_binary = cv2.threshold(roi_eye, 70, 255, cv2.THRESH_BINARY_INV)

            divide_x = int(ew_a[0]/3)
            if divide_x is 0:
                break
            else:
                divide_2x = divide_x * 2

            divide_y = int(find_y / 3)
            if divide_y is 0:
                break
            else:
                divide_2y = divide_y * 2

            #좌우구분 roi
            #roi_eye_1 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + divide_x]
            roi_eye_2 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0] + divide_x:ex_a[0] + divide_2x]
            roi_eye_3 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0] + divide_2x:ex_a[0] + ew_a[0]]

            #ret, eye_binary_1 = cv2.threshold(roi_eye_1, 35, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_2 = cv2.threshold(roi_eye_2, 70, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_3 = cv2.threshold(roi_eye_3, 70, 255, cv2.THRESH_BINARY_INV)

            #cv2.imshow('eye_binary_1', eye_binary_1)
            cv2.imshow('eye_binary_2', eye_binary_2)
            cv2.imshow('eye_binary_3', eye_binary_3)
            #좌우구분 roi 끝

            #상하구분 roi
            roi_updown_1 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + divide_y+5, ex_a[0]:ex_a[0] + ew_a[0]]
            roi_updown_2 = roi_gray[ey_a[0] + find_y + divide_y:ey_a[0] + find_y + divide_2y, ex_a[0]:ex_a[0] + ew_a[0]]
            roi_updown_3 = roi_gray[ey_a[0] + find_y + divide_2y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]

            ret, updown_binary_1 = cv2.threshold(roi_updown_1, 70, 255, cv2.THRESH_BINARY_INV)
            ret, updown_binary_2 = cv2.threshold(roi_updown_2, 70, 255, cv2.THRESH_BINARY_INV)
            ret, updown_binary_3 = cv2.threshold(roi_updown_3, 70, 255, cv2.THRESH_BINARY_INV)

            cv2.imshow('up1', updown_binary_1)
            cv2.imshow('up2', updown_binary_2)
            cv2.imshow('up3', updown_binary_3)
            #상하구분 roi 끝


            #오른쪽감지 알고리즘
            binary_right_height = eye_binary_3.shape[0]
            binary_right_width = eye_binary_3.shape[1]

            detect_black_right = 0
            detect_white_right = 0
            for y in range(0,binary_right_height):
                for x in range(0, binary_right_width):
                    find_right = eye_binary_3[y,x]
                    if find_right == 0:
                        detect_black_right += 1
                    else:
                        detect_white_right += 1

            if detect_white_right < 10:
                print('right detected')
                detect_right += 1
                detect_left = 0
                detect_up = 0
                detect_blink = 0
                detect_down = 0
                if detect_right == 3:
                    print('RIGHT')
                    currentMouseX, currentMouseY = AG.position()
                    AG.moveTo(currentMouseX + 300, currentMouseY, 0.5)
                    detect_right = 0
            #오른쪽감지 알고리즘 끝

            #왼쪽감지 알고리즘
            binary_left_height = eye_binary_2.shape[0]
            binary_left_width = eye_binary_2.shape[1]

            detect_black_left = 0
            detect_white_left = 0
            for y in range(0,binary_left_height):
                for x in range(0, binary_left_width):
                    find_left = eye_binary_2[y,x]
                    if find_left == 0:
                        detect_black_left += 1
                    else:
                        detect_white_left += 1

            if detect_white_left < 10:
                print('left detected')
                detect_left += 1
                detect_right = 0
                detect_up = 0
                detect_blink = 0
                detect_down = 0
                if detect_left == 3:
                    print('LEFT')
                    currentMouseX, currentMouseY = AG.position()
                    AG.moveTo(currentMouseX - 300, currentMouseY, 0.5)
                    detect_left = 0
            #왼쪽감지 알고리즘 끝

            #위 감지 알고리즘
            binary_up_height = updown_binary_3.shape[0]
            binary_up_width = updown_binary_3.shape[1]

            detect_black_up = 0
            detect_white_up = 0
            for y in range(0,binary_up_height):
                for x in range(0, binary_up_width):
                    find_up = updown_binary_3[y,x]
                    if find_up == 0:
                        detect_black_up += 1
                    else:
                        detect_white_up += 1

            if detect_white_up == 0 :
                print('up detected')
                detect_up += 1
                detect_right = 0
                detect_left = 0
                detect_down = 0
                detect_blink = 0
                if detect_up == 3:
                    print('up')
                    currentMouseX, currentMouseY = AG.position()
                    AG.moveTo(currentMouseX, currentMouseY - 300, 0.5)
                    detect_up = 0
            #위 감지 알고리즘 끝

            '''
            #아래 감지 알고리즘
            binary_down_height = updown_binary_1.shape[0]
            binary_down_width = updown_binary_1.shape[1]

            detect_black_down = 0
            detect_white_down = 0
            for y in range(0,binary_down_height):
                for x in range(0, binary_down_width):
                    find_up = updown_binary_1[y,x]
                    if find_up == 0:
                        detect_black_down += 1
                    else:
                        detect_white_down += 1

            if detect_white_down < 10:
                print('down detected')
                detect_down += 1
                detect_up = 0
                detect_right = 0
                detect_left = 0
                detect_blink = 0
                if detect_down == 3:
                    print('DOWN')
                    currentMouseX, currentMouseY = AG.position()
                    AG.moveTo(currentMouseX, currentMouseY + 300, 0.5)
                    detect_down = 0
            #아래 감지 알고리즘 끝
            '''


            #눈동자 좌표찾기
            contours, _ = cv2.findContours(eye_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            contours = sorted(contours, key=lambda x: cv2.contourArea(x), reverse=True)
            test_x, test_y = eye_binary.shape
            for cnt in contours:
                (a, b, c, d) = cv2.boundingRect(cnt)
                cv2.line(eye_binary, (a + int(c / 2), 0), (a + int(c / 2), test_x), (0, 255, 0), 2)
                cv2.line(eye_binary, (0, b + int(d / 2)), (test_y, b + int(d / 2)), (0, 255, 0), 2)
                break
            #눈동자 좌표찾기 끝

            cv2.imshow('eye_binary', eye_binary)
            cv2.imshow('roi_eye', roi_eye)
            cv2.rectangle(roi_color, (ex_a[0], ey_a[0]), (ex_a[0] + ew_a[0], ey_a[0] + eh_a[0]), (0, 255, 0), 2)

            #오른쪽눈 끝

        cv2.imshow("frame", frame)

        k = cv2.waitKey(30)

        if k == 27:
            break

    cam.release()
    cv2.destroyAllWindows()

circles= None
faceDetect()