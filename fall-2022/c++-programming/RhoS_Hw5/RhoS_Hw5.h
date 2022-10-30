/*
 *    Soobin Rho
 *    October 29, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5:
 *      Graphics Classes
 *
 *    This is the header file.
 */

#include <QWidget>
#include <QPainter>
#include <QImage>

class PaintWindow : public QWidget {
    Q_OBJECT

public:
    PaintWindow(QWidget *parent = nullptr) : QWidget(parent) {};
    ~PaintWindow() {}
    void paintEvent(QPaintEvent *event);
};
