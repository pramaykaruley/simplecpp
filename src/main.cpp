#include<iostream>
#include <canvas.h>

int main(int argc, char *argv[])
{
    std::cout << "Running main" << std::endl;

    auto obj = canvasFactory::makeCanvas("");
    std::cout << obj->toString() << std::endl;

    return 0;
}
