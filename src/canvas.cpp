#include <canvas.h>
#include <simplecppmainwindow.h>
#include <QApplication>

namespace simplecpp {
std::unique_ptr<QApplication> appObj;
std::unique_ptr<SimpleCppMainWindow> winObj;

void initCanvas(const char *title, const int width, const int height){

    // Construct command-line arguments for the application
    auto argc {1};
    auto cmd {"simplecpp"};
    const char *argv[2];
    argv[0] = cmd;
    argv[1] = nullptr;

    // Initialize the application
    appObj = std::make_unique<QApplication>(argc, reinterpret_cast<char**>(&argv));

    // Create and open application window
    winObj = std::make_unique<SimpleCppMainWindow> (title, width, height);
    winObj->show();

}

void closeCanvas(){
    // Close application window
    winObj->close();
    winObj.reset(nullptr);

    // Close application
    appObj->exit();
    appObj.reset(nullptr);

}

void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth)
{
    winObj->drawLine(start, end, lineColor, lineWidth);
}


}
