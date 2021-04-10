import cv2
import numpy as np

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

    while True:
        #brk_flag = 0
        ret, frame = cam.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)


        for (x, y, w, h) in faces:

            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
            cv2.putText(frame, "Detected Face", (x - 5, y - 5), font, 0.5, (255, 255, 0), 2)

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

            #오른쪽 눈
            find_y = int(eh_a[0]/3)
            if find_y is 0:
                find_y = 1
            roi_eye = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + ew_a[0]]

            divide_x = int(ew_a[0]/3)
            if divide_x is 0:
                break
            else:
                divide_2x = divide_x * 2

            #roi_eye_1 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0]:ex_a[0] + divide_x]
            roi_eye_2 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0] + divide_x:ex_a[0] + divide_2x]
            roi_eye_3 = roi_gray[ey_a[0] + find_y:ey_a[0] + find_y + find_y, ex_a[0] + divide_2x:ex_a[0] + ew_a[0]]

            ret, eye_binary = cv2.threshold(roi_eye, 60, 255, cv2.THRESH_BINARY_INV)
            #ret, eye_binary_1 = cv2.threshold(roi_eye_1, 35, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_2 = cv2.threshold(roi_eye_2, 60, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_3 = cv2.threshold(roi_eye_3, 60, 255, cv2.THRESH_BINARY_INV)


            #오른쪽감지 알고리즘
            binary3_height = eye_binary_3.shape[0]
            binary3_width = eye_binary_3.shape[1]

            detect_black_3 = 0
            detect_white_3 = 0
            for y in range(0,binary3_height):
                for x in range(0, binary3_width):
                    detect_3 = eye_binary_3[y,x]
                    if detect_3 == 0:
                        detect_black_3 += 1
                    else:
                        detect_white_3 += 1

            if detect_white_3 < 10:
                print('right detected')
                detect_right += 1
                detect_left = 0
                if detect_right == 10:
                    print('RIGHT')
                    detect_right = 0


            #print('eye_3_black : {} '.format(detect_black_3))
            #오른쪽감지 알고리즘 끝

            #cv2.imshow('eye_binary_1', eye_binary_1)
            cv2.imshow('eye_binary_2', eye_binary_2)
            cv2.imshow('eye_binary_3', eye_binary_3)

            cv2.imshow('eye_binary', eye_binary)
            cv2.imshow('roi_eye', roi_eye)
            cv2.rectangle(roi_color, (ex_a[0], ey_a[0]), (ex_a[0] + ew_a[0], ey_a[0] + eh_a[0]), (0, 255, 0), 2)

            #오른쪽눈 끝


            #왼쪽 눈
            find_y_L = int(eh_a[1]/3)
            if find_y_L is 0:
                find_y_L = 1
            roi_eye_L = roi_gray[ey_a[1] + find_y_L:ey_a[1] + find_y_L + find_y_L, ex_a[1]:ex_a[1] + ew_a[1]]

            divide_x_L = int(ew_a[1]/3)
            if divide_x_L is 0:
                break
            else:
                divide_2x_L = divide_x_L * 2

            #roi_eye_L1 = roi_gray[ey_a[1] + find_y_L:ey_a[1] + find_y_L + find_y_L, ex_a[1]:ex_a[1] + divide_x_L]
            roi_eye_L2 = roi_gray[ey_a[1] + find_y_L:ey_a[1] + find_y_L + find_y_L, ex_a[1] + divide_x_L:ex_a[1] + divide_2x_L]
            roi_eye_L3 = roi_gray[ey_a[1] + find_y_L:ey_a[1] + find_y_L + find_y_L, ex_a[1] + divide_2x_L:ex_a[1] + ew_a[1]]

            ret, eye_binary_L = cv2.threshold(roi_eye_L, 40, 255, cv2.THRESH_BINARY_INV)
            #ret, eye_binary_L1 = cv2.threshold(roi_eye_L1, 35, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_L2 = cv2.threshold(roi_eye_L2, 60, 255, cv2.THRESH_BINARY_INV)
            ret, eye_binary_L3 = cv2.threshold(roi_eye_L3, 60, 255, cv2.THRESH_BINARY_INV)

            #왼쪽감지 알고리즘
            binary3_height_L = eye_binary_L3.shape[0]
            binary3_width_L = eye_binary_L3.shape[1]

            detect_black_L3 = 0
            detect_white_L3 = 0
            for y in range(0,binary3_height_L):
                for x in range(0, binary3_width_L):
                    detect_L3 = eye_binary_L3[y,x]
                    if detect_L3 == 0:
                        detect_black_L3 += 1
                    else:
                        detect_white_L3 += 1

            if detect_white_L3 > 10:
                print('left detected')
                detect_left += 1
                detect_right =0
                if detect_left == 10:
                    print('LEFT')
                    detect_left = 0


            #print('eye_3_black : {} '.format(detect_black_3))
            #왼쪽감지 알고리즘 끝


            #cv2.imshow('eye_binary_1', eye_binary_L1)
            cv2.imshow('eye_binary_L2', eye_binary_L2)
            cv2.imshow('eye_binary_L3', eye_binary_L3)

            cv2.imshow('eye_binary_L', eye_binary_L)
            cv2.imshow('roi_eye_L', roi_eye_L)
            cv2.rectangle(roi_color, (ex_a[1], ey_a[1]), (ex_a[1] + ew_a[1], ey_a[1] + eh_a[1]), (255, 255, 0), 2)


        cv2.imshow("frame", frame)

        k = cv2.waitKey(30)

        if k == 27:
            break

    cam.release()
    cv2.destroyAllWindows()

circles= None
faceDetect()