#include<iostream>
#include <canvas.h>

typedef QPoint XPoint ;
typedef QColor Color;


int main(int argc, char *argv[])
{
    std::cout << "Running main" << std::endl;

    auto obj = canvasFactory::makeCanvas("");
    std::cout << "Created canvas" << std::endl;

    XPoint x(10,10), y(200, 300);

    obj->drawLine(x, y, Color("darkCyan"), 10);

    std::cout << obj->toString() << std::endl;
    return 0;
}
