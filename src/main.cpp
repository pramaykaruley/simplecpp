#include<iostream>
#include <canvas.h>

int main(int argc, char *argv[])
{
    
    QGuiApplication app(argc, argv);

    auto obj = Canvas::createCanvas();        

    XPoint x(10,10), y(200, 300);

    obj->drawLine(x, y, Color("darkCyan"), 10);
    return 0;
}
