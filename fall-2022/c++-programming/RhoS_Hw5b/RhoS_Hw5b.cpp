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

    // -------------------------------------------------------------
    // 1. Make an instance of the Window class
    // -------------------------------------------------------------
    Window window;
    window.show();

    // Again, this statement is required for all .cpp files in Qt
    return a.exec();
}

Window::Window(QWidget *parent) : QWidget(parent) {
    /*
     *    Definition for the Window class constructor
     */

    // -------------------------------------------------------------
    // 2. Set the window's title, size, and icon
    // -------------------------------------------------------------
    setWindowTitle("RhoS_Hw5b");
    resize(800,1000);

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

    // -------------------------------------------------------------
    // 3. Insert an image
    // -------------------------------------------------------------
    QImage imgTree {":/images/favicon.png"};
    painter.drawImage(QRectF(190,170,200,200), imgTree);

    // -------------------------------------------------------------
    // 4. Draw an x-axis and y-axis
    // -------------------------------------------------------------
    const double xSTART = 220.0;
    const double xEND = 360.0;
    const double ySTART = 30.0;
    const double yEND = 130.0;
    QPainterPath axisPath;
    axisPath.moveTo(xSTART,ySTART);
    axisPath.lineTo(xSTART,yEND);
    axisPath.lineTo(xEND,yEND);
    painter.drawPath(axisPath);

    // Sub-axis for x-axis
    for (int i=static_cast<int>(xSTART); i<=xEND; i+=10) {
        painter.drawLine(i,yEND,i,yEND-3);
    }

    // Sub-axis for y-axis
    for (int i=static_cast<int>(ySTART); i<=yEND; i+=10) {
        painter.drawLine(xSTART,i,xSTART+3,i);
    }

    // -------------------------------------------------------------
    // 5. Insert texts
    // -------------------------------------------------------------
    painter.drawText(245,145,"This is a graph.");
    painter.setFont(QFont("Arial",10,-1,true));
    painter.drawText(500,370,"Soobin Rho");

    // -------------------------------------------------------------
    // 6. Draw a yellow box
    // -------------------------------------------------------------
    painter.fillRect(40,30,140,100,Qt::yellow);

    // -------------------------------------------------------------
    // 7. Draw a green polygon
    // -------------------------------------------------------------
    QPainterPath greenPolygonPath;
    greenPolygonPath.moveTo(400,30);
    greenPolygonPath.lineTo(400,130);
    greenPolygonPath.lineTo(540,130);
    greenPolygonPath.lineTo(540,80);
    greenPolygonPath.closeSubpath();
    painter.fillPath(greenPolygonPath,QBrush(Qt::green));

    // -------------------------------------------------------------
    // 8. Draw a triangle with discontinuous lines
    // -------------------------------------------------------------
    QPainterPath yellowTrianglePath;
    yellowTrianglePath.moveTo(540,80);
    yellowTrianglePath.lineTo(540,30);
    yellowTrianglePath.lineTo(400,30);
    yellowTrianglePath.closeSubpath();
    QPen penBackup = painter.pen();
    QPen penDiscontinuous = painter.pen();
    penDiscontinuous.setStyle(Qt::DashLine);
    painter.setPen(penDiscontinuous);
    painter.drawPath(yellowTrianglePath);

    // -------------------------------------------------------------
    // 9. Draw a sine wave
    // -------------------------------------------------------------
    QPainterPath sinePath;
    sinePath.moveTo(0.0, 270.0);

    // QRectF left, top, width, height, starting angle, sweeping length
    sinePath.arcTo(0.0, 200.0, 300, 150, -180, -180);
    sinePath.arcTo(300.0, 200.0, 270, 150, 180, 180);
    painter.setPen(penBackup);
    painter.drawPath(sinePath);

    painter.end();
    QWidget::paintEvent(event);
}

QSize RenderArea::minimumSizeHint() const {
    return QSize(300, 300);
}

QSize RenderArea::sizeHint() const {
    return QSize(600, 400);
}
