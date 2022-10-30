/*
 *    Soobin Rho
 *    October 26, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5:
 *      Graphics Classes
 */

#include "paintwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    /*
     *    Drill:
     *    1. Resize the window to 600 by 400.
     *    2. Set the window title as "My window".
     *    3. Add the examples from 12.7 one by one.
     *    4. Make one minor change for every subsection example:
     *         I chose to change the color of
     *         every subsection example.
     */

    QApplication a(argc, argv);
    PaintWindow window;

    // This is how to link an image from Qt Resource System
    // By the way, "By default, rcc embeds the resource files
    // into executables in the form of C++ arrays."
    // Source:
    //   https://doc.qt.io/qt-6/resources.html#runtime-api
    window.setWindowIcon(QIcon(":/images/favicon.png"));
    window.setWindowTitle("My window");
    window.resize(600, 400);
    window.show();
    return a.exec();
}
