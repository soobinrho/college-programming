/*
 *    Soobin Rho
 *    October 29, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5b: Graphics Classes
 */

#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QApplication>

class Window : public QWidget {
    // This is used by the Meta-Object Compiler.
    // "If it finds one or more class declarations that contain
    // the Q_OBJECT macro, it produces a C++ source file containing
    // the meta-object code for those classes. Among other things,
    // meta-object code is required for the signals and slots
    // mechanism, the run-time type information, and
    // the dynamic property system."
    // Source:
    //   https://doc.qt.io/qt-6/moc.html
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window() {}
    void paintEvent(QPaintEvent *event);
};
