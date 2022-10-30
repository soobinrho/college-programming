/*
 *    Soobin Rho
 *    October 26, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw5:
 *      Graphics Classes
 */

/*
 * Copyright 2022 Soobin Rho
 *
 * I wrote this copyright notice based on GNU's "How to Use GNU
 * Licenses for Your Own Software" article:
 *   https://www.gnu.org/licenses/gpl-howto.html
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
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
