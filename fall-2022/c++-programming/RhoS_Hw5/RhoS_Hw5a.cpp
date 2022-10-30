/*
 *    Soobin Rho
 *    October 29, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5: Graphics Classes
 */

#include "RhoS_Hw5a.h"

int main(int argc, char *argv[]) {
    /*
     *    An exercise for using basic Qt Graphics Classes.
     */

    // This initialization is required for all .cpp files in Qt.
    // Source:
    //   https://wiki.qt.io/Qt_for_Beginners
    QApplication a(argc, argv); 

    // -------------------------------------------------------------
    // 1. Make an instance of the Window class
    // -------------------------------------------------------------
    Window window;
    window.show();

    // Again, this statement is required for all .cpp files in Qt
    return a.exec();
}

// --------------------------------------------------------------
// Definitions for the RenderArea class constructor and functions
// --------------------------------------------------------------
RenderArea::RenderArea(QWidget *parent) : QWidget(parent) {
    // They don't look nice now, but will someday be useful for
    // future assignments, so I've commented these out.
    // setBackgroundRole(QPalette::Base);
    // setForegroundRole(QPalette::Text);
    // setAutoFillBackground(true);
}

void RenderArea::paintEvent(QPaintEvent *event) {
    /*
     *    Drawings with the QPainter class.
     */

    // Initialize
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // QPainterPath path;
    // path.addRect(20, 20, 60, 60);
    //
    // path.moveTo(0, 0);
    // path.cubicTo(99, 0,  50, 50,  99, 99);
    // path.cubicTo(0, 99,  50, 50,  0, 0);
    //
    // QPainter painter(this);
    // painter.fillRect(0, 0, 100, 100, Qt::white);
    // painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                        // Qt::FlatCap, Qt::MiterJoin));
    // painter.setBrush(QColor(122, 163, 39));
    //
    // painter.drawPath(path);

    // Insert an image
    QImage imgNsustain {":/images/nsustain.png"};
    painter.drawImage(QPointF(20, 30), imgNsustain);

    // Draw a sine curve
    QPainterPath roundRectPath;
    roundRectPath.moveTo(80.0, 35.0);
    roundRectPath.arcTo(70.0, 30.0, 10.0, 10.0, 0.0, 180.0);
    roundRectPath.lineTo(25.0, 30.0);
    roundRectPath.arcTo(20.0, 30.0, 10.0, 10.0, 180.0, 0.0);
    roundRectPath.lineTo(20.0, 65.0);
    roundRectPath.arcTo(20.0, 60.0, 10.0, 10.0, 0.0, 180.0);
    roundRectPath.lineTo(75.0, 70.0);
    roundRectPath.arcTo(70.0, 60.0, 10.0, 10.0, 180.0, 0.0);
    roundRectPath.closeSubpath();
    painter.drawPath(roundRectPath);

    painter.drawEllipse(QPoint(100,150),50,20);

    QRectF drawingRect(50, 200, 100, 50);
    int startAngle = 90 * 16;
    int spanAngle = 180 * 16;
    painter.drawArc(drawingRect, startAngle, spanAngle);

    QRectF drawingRectPie(150, 200, 100, 50);
    startAngle = 60 * 16;
    spanAngle = 70 * 16;
    painter.drawPie(drawingRectPie, startAngle, spanAngle);

    painter.end();

    QWidget::paintEvent(event);
}

QSize RenderArea::minimumSizeHint() const {
    return QSize(300, 300);
}

QSize RenderArea::sizeHint() const {
    return QSize(600, 400);
}

Window::Window(QWidget *parent) : QWidget(parent) {
    /*
     *    Definition for the Window class constructor
     */

    // -------------------------------------------------------------
    // 2. Set the window's title, size, and icon
    // -------------------------------------------------------------
    setWindowTitle("RhoS_Hw5");
    resize(600, 400);

    // This is how to link an image from Qt Resource System
    // By the way, "By default, rcc embeds the resource files
    // into executables in the form of C++ arrays."
    // Source:
    //   https://doc.qt.io/qt-6/resources.html#runtime-api
    QIcon iconNsustain {":/images/favicon.png"};
    setWindowIcon(iconNsustain);
    setBackgroundRole(QPalette::Window);
    setForegroundRole(QPalette::WindowText);
    setAutoFillBackground(true);

    // Initialize a RenderArea.
    // Source:
    //   https://doc.qt.io/qt-6/qtwidgets-painting-basicdrawing-example.html
    renderArea = new RenderArea;
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(renderArea,0,0);
    setLayout(mainLayout);
}


