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
    keyboard_flag = 0

    while True:
        #brk_flag = 0
        ret, frame = cam.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
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

            #깜빡임 감지
            if eyes is ():
                print('blink detected')
                detect_right = 0
                detect_left = 0
                detect_up = 0
                detect_blink += 1
                if detect_blink == 2:
                    print('BLINK')
                    currentMouseX, currentMouseY = AG.position()
                    if ( currentMouseX == 740 and currentMouseY == 255 ):
                        print('keyboard Mode')
                        AG.click()
                        AG.moveTo(480,254)
                    elif (currentMouseX == 310 and currentMouseY == 154):
                        AG.moveTo(1750, 15)
                        AG.click( clicks= 3, interval= 0.5 )
                    AG.click()
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
            roi_eye_color = roi_color[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]
            ret, eye_binary = cv2.threshold(roi_eye, 45, 255, cv2.THRESH_BINARY_INV)


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
            ret, eye_binary_2 = cv2.threshold(roi_eye_2, 40, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_3 = cv2.threshold(roi_eye_3, 40, 255, cv2.THRESH_BINARY_INV)

            #cv2.imshow('eye_binary_1', eye_binary_1)
            cv2.imshow('eye_binary', eye_binary)
            cv2.imshow('eye_binary_2', eye_binary_2)
            cv2.imshow('eye_binary_3', eye_binary_3)
            #좌우구분 roi 끝

            #상하구분 roi
            roi_updown_1 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + divide_y+5, ex_a[0]:ex_a[0] + ew_a[0]]
            roi_updown_2 = roi_gray[ey_a[0] + find_y + divide_y:ey_a[0] + find_y + divide_2y, ex_a[0]:ex_a[0] + ew_a[0]]
            roi_updown_3 = roi_gray[ey_a[0] + find_y + divide_2y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]

            ret, updown_binary_1 = cv2.threshold(roi_updown_1, 50, 255, cv2.THRESH_BINARY_INV)
            ret, updown_binary_2 = cv2.threshold(roi_updown_2, 50, 255, cv2.THRESH_BINARY_INV)
            ret, updown_binary_3 = cv2.threshold(roi_updown_3, 40, 255, cv2.THRESH_BINARY_INV)

            #cv2.imshow('up1', updown_binary_1)
            #cv2.imshow('up2', updown_binary_2)
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
                    if currentMouseX == 23:
                        if currentMouseY == 66:
                            AG.moveTo(240, 66, 0.2)
                        else:
                            AG.moveTo(240, 135, 0.2)
                    elif currentMouseX == 240:
                        if currentMouseY == 66:
                            AG.moveTo(460, 66, 0.2)
                        else:
                            AG.moveTo(460, 135, 0.2)
                    elif currentMouseX == 460:
                        if currentMouseY == 66:
                            AG.moveTo(700, 66, 0.2)
                        else:
                            AG.moveTo(700, 135, 0.2)
                    elif currentMouseX == 700:
                        if currentMouseY == 66:
                            AG.moveTo(23, 66, 0.2)
                        else:
                            AG.moveTo(23, 135, 0.2)
                    elif currentMouseX == 610:
                        AG.moveTo(740, 255, 0.2)
                    elif currentMouseX == 740:
                        AG.moveTo(610, 255, 0.2)
                    else:
                        AG.moveTo(currentMouseX + 85, currentMouseY, 0.2)
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

                    if currentMouseX == 23:
                        if currentMouseY == 66:
                            AG.moveTo(700, 66, 0.2)
                        else:
                            AG.moveTo(700, 135, 0.2)
                    elif currentMouseX == 240:
                        if currentMouseY == 66:
                            AG.moveTo(23, 66, 0.2)
                        else:
                            AG.moveTo(23, 135, 0.2)
                    elif currentMouseX == 460:
                        if currentMouseY == 66:
                            AG.moveTo(240, 66, 0.2)
                        else:
                            AG.moveTo(240, 135, 0.2)
                    elif currentMouseX == 700:
                        if currentMouseY == 66:
                            AG.moveTo(460, 66, 0.2)
                        else:
                            AG.moveTo(460, 135, 0.2)
                    elif currentMouseX == 610:
                        AG.moveTo(740, 255, 0.2)
                    elif currentMouseX == 740:
                        AG.moveTo(610, 255, 0.2)
                    else:
                        AG.moveTo(currentMouseX - 85, currentMouseY, 0.2)
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

                    if currentMouseY == 66:
                        if currentMouseX == 23:
                            AG.moveTo(23, 196, 0.2)
                        elif currentMouseX == 240:
                            AG.moveTo(240, 135, 0.2)
                        elif currentMouseX == 460:
                            AG.moveTo(610, 255, 0.2)
                        elif currentMouseX == 700:
                            AG.moveTo(740, 255, 0.2)
                        else:
                            AG.moveTo(23, 66, 0.2)
                    elif currentMouseY == 135:
                        if currentMouseX == 23:
                            AG.moveTo(23, 66, 0.2)
                        elif currentMouseX == 240:
                            AG.moveTo(240, 66, 0.2)
                        elif currentMouseX == 460:
                            AG.moveTo(460, 66, 0.2)
                        elif currentMouseX == 700:
                            AG.moveTo(700, 66, 0.2)
                        else:
                            AG.moveTo(23, 66, 0.2)
                    elif currentMouseY == 196:
                        AG.moveTo(23, 135, 0.2)
                    elif currentMouseY == 255:
                        if currentMouseX == 610:
                            AG.moveTo(460, 135, 0.2)
                        else:
                            AG.moveTo(700, 135, 0.2)
                    else:
                        AG.moveTo(currentMouseX, currentMouseY - 50, 0.2)
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
            #test_y, test_x = eye_binary.shape
            for cnt in contours:
                (a, b, c, d) = cv2.boundingRect(cnt)
                cv2.rectangle(roi_eye_color, (a,b),(a+c,b+d),(0,0,255),1)
                contour_x = int((a+a+c)/2)
                contour_y = int((b+b+d)/2)
                real_x = frame_x + ex_a[0] + contour_x
                real_y = frame_y + ey_a[0] + find_y + contour_y
                cv2.circle(frame, (real_x, real_y), 1, (0, 0, 255), 2)
                break
            #눈동자 좌표찾기 끝

            #cv2.imshow('eye_binary', eye_binary)
            cv2.imshow('roi_eye', roi_eye_color)
            cv2.rectangle(roi_color, (ex_a[0], ey_a[0]), (ex_a[0] + ew_a[0], ey_a[0] + eh_a[0]), (0, 255, 0), 2)

            #오른쪽눈 끝

        cv2.imshow("frame", frame)

        k = cv2.waitKey(30)

        if k == 27:
            break

    cam.release()
    cv2.destroyAllWindows()

circles= None
AG.moveTo(23, 66)
faceDetect()