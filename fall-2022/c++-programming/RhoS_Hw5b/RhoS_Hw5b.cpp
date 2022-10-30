/*
 *    Soobin Rho
 *    October 29, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5b: Graphics Classes
 *    Practicing grid layouts with images
 */

#include "RhoS_Hw5b.h"

int main(int argc, char *argv[]) {
    // This initialization is required for all .cpp files in Qt.
    // Source:
    //   https://wiki.qt.io/Qt_for_Beginners
    QApplication a(argc,argv);

    Window window;
    window.show();

    // Again, this statement is required for all .cpp files in Qt
    return a.exec();
}

Window::Window(QWidget *parent) : QWidget(parent) {
    /*
     *    Definition for the Window class constructor
     */

    resize(800,1000);
    setWindowTitle("RhoS_Hw5b");

    // This is how to link an image from Qt Resource System
    // By the way, "By default, rcc embeds the resource files
    // into executables in the form of C++ arrays."
    // Source:
    //   https://doc.qt.io/qt-6/resources.html#runtime-api
    QIcon iconNsustain {":/images/cool.png"};
    setWindowIcon(iconNsustain);
    setBackgroundRole(QPalette::Window);
    setForegroundRole(QPalette::WindowText);
    setAutoFillBackground(true);
}

void Window::paintEvent(QPaintEvent *event) {
    /*
     *    Drawings grids and images
     */

    // Initialize
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const int WIDTH {800};
    const int HEIGHT {800};
    const int MARKWIDTH {100};
    const int MARKHEIGHT {100};

    int xCoordinate {0};
    int yCoordinate {0};
    int totalPixels {0};
    bool isDone {false};
    bool isTimeToInsertImage {false};
    while (!isDone) {
        if (xCoordinate%MARKWIDTH==0 && yCoordinate%MARKHEIGHT==0) {
            // -------------------------------------------------------------
            // 1. Make 64 grids, each having the size of 100x100
            // -------------------------------------------------------------
            painter.drawRect(xCoordinate,yCoordinate,MARKWIDTH,MARKHEIGHT);

            // -------------------------------------------------------------
            // 2. Mark diagonal squares as red
            // -------------------------------------------------------------
            if (xCoordinate==yCoordinate) {
                painter.fillRect(xCoordinate,yCoordinate,MARKWIDTH,MARKHEIGHT,Qt::red);
            }

            // -------------------------------------------------------------
            // 3. Place three copies of a 200x200 image
            // -------------------------------------------------------------
            if (isTimeToInsertImage) {
                QImage imgCool {":/images/cool.png"};
                painter.drawImage(QRectF(xCoordinate,yCoordinate,MARKWIDTH*2,MARKHEIGHT*2), imgCool);
                isTimeToInsertImage = false;
            }
        }

        // Check if the total number of pixels reached one thirds, two thirds, or three thirds.
        // This is for the instruction that tells us to put exactly three copies of the image.
        if (totalPixels%(WIDTH*HEIGHT/3)==0) isTimeToInsertImage = true;

        // Increment loop variables
        ++totalPixels;
        ++xCoordinate;
        if (totalPixels>(WIDTH*HEIGHT-1)) isDone = true;
        else if (totalPixels%WIDTH==0) {
            xCoordinate = 0;
            ++yCoordinate;
        }
    }

    // -------------------------------------------------------------
    // 4. Place a 100x100 image
    // -------------------------------------------------------------
    QImage imgVeryCool {":/images/verycool.png"};
    painter.drawImage(QRectF(0,0,MARKWIDTH,MARKHEIGHT), imgVeryCool);

    painter.end();
    QWidget::paintEvent(event);
}
