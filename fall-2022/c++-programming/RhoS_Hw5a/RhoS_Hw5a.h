/*
 *    Soobin Rho
 *    October 29, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5: Graphics Classes
 */

#include <QSize>
#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QGridLayout>
#include <QPainterPath>
#include <QApplication>
#include <QGuiApplication>

class RenderArea : public QWidget {
    Q_OBJECT

public:
    RenderArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    // "All the widgets will initially be allocated an amount of space
    // in accordance with their QWidget::sizePolicy() and QWidget::sizeHint()."
    // Source:
    //   https://doc.qt.io/qt-6/layout.html
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
};

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

private:
    RenderArea *renderArea;
};
