#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Windows.h> // For sending key presses
#include <iostream>

using namespace cv;
using namespace std;

void pressKey() {
    // Simulate pressing the 'E' key
    keybd_event(VK_E, 0, 0, 0); // Key down
    keybd_event(VK_E, 0, KEYEVENTF_KEYUP, 0); // Key up
    Sleep(35); // Delay 35 milliseconds
    cout << "Pressed 'E'" << endl;
}

bool detectMotionInColors(const Mat& image, const Mat& prevImage) {
    // Define color ranges for blue and red
    Scalar blueLower(100, 150, 150);
    Scalar blueUpper(140, 255, 255);

    Scalar redLower1(0, 100, 100);
    Scalar redUpper1(10, 255, 255);
    Scalar redLower2(160, 100, 100);
    Scalar redUpper2(180, 255, 255);

    Mat hsv, blueMask, redMask1, redMask2, redMask, prevHsv, prevBlueMask, prevRedMask1, prevRedMask2, prevRedMask, blueDiffMask, redDiffMask, combinedDiffMask;

    // Convert the image to HSV
    cvtColor(image, hsv, COLOR_BGR2HSV);
    inRange(hsv, blueLower, blueUpper, blueMask);
    inRange(hsv, redLower1, redUpper1, redMask1);
    inRange(hsv, redLower2, redUpper2, redMask2);
    bitwise_or(redMask1, redMask2, redMask);

    if (!prevImage.empty()) {
        cvtColor(prevImage, prevHsv, COLOR_BGR2HSV);
        inRange(prevHsv, blueLower, blueUpper, prevBlueMask);
        inRange(prevHsv, redLower1, redUpper1, prevRedMask1);
        inRange(prevHsv, redLower2, redUpper2, prevRedMask2);
        bitwise_or(prevRedMask1, prevRedMask2, prevRedMask);

        // Find the absolute difference between the masks
        absdiff(blueMask, prevBlueMask, blueDiffMask);
        absdiff(redMask, prevRedMask, redDiffMask);
        bitwise_and(blueDiffMask, redDiffMask, combinedDiffMask);

        int diffDetection = countNonZero(combinedDiffMask);

        if (diffDetection > 15) {
            return true;
        }
    }

    return false;
}

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int roiSize = 55; // Size of ROI

    Mat prevImage;
    bool motionDetected = false;

    namedWindow("Screen", WINDOW_NORMAL);

    while (true) {
        // Capture the screen
        HWND desktop = GetDesktopWindow();
        HDC desktopDC = GetDC(desktop);
        HDC memoryDC = CreateCompatibleDC(desktopDC);
        HBITMAP bitmap = CreateCompatibleBitmap(desktopDC, screenWidth, screenHeight);
        SelectObject(memoryDC, bitmap);

        BitBlt(memoryDC, 0, 0, screenWidth, screenHeight, desktopDC, 0, 0, SRCCOPY);

        BITMAPINFOHEADER bitmapInfo;
        bitmapInfo.biSize = sizeof(BITMAPINFOHEADER);
        bitmapInfo.biWidth = screenWidth;
        bitmapInfo.biHeight = -screenHeight; // Negative to indicate top-down DIB
        bitmapInfo.biPlanes = 1;
        bitmapInfo.biBitCount = 24;
        bitmapInfo.biCompression = BI_RGB;
        bitmapInfo.biSizeImage = 0;
        bitmapInfo.biXPelsPerMeter = 0;
        bitmapInfo.biYPelsPerMeter = 0;
        bitmapInfo.biClrUsed = 0;
        bitmapInfo.biClrImportant = 0;

        vector<uchar> buffer(screenWidth * screenHeight * 3);
        GetDIBits(desktopDC, bitmap, 0, screenHeight, buffer.data(), (BITMAPINFO*)&bitmapInfo, DIB_RGB_COLORS);

        Mat screenShot(screenHeight, screenWidth, CV_8UC3, buffer.data());

        if (detectMotionInColors(screenShot, prevImage)) {
            if (!motionDetected) {
                pressKey();
                motionDetected = true;
            }
        } else {
            motionDetected = false;
        }

        imshow("Screen", screenShot);

        prevImage = screenShot.clone();

        if (waitKey(1) == 'q') {
            break;
        }

        Sleep(10); // Delay
    }

    return 0;
}

