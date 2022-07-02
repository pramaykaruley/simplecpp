#include<iostream>
#include <canvas.h>
#include <turtleSim.h>

using namespace simplecpp;

int main(int argc, char **argv) {
    unsigned nSteps {0};

    std::cout << "Enter number of steps: ";
    std::cin >> nSteps;

    for(int stepIdx = 0; stepIdx < nSteps; stepIdx ++) {
        auto action = rand() % 5;

        switch (action)
        {
        case 0:
            left(90);            
            break;
        case 1:
            right(90);
            break;
        default:
            forward(20);
            break;
        }
        QThread::msleep(50);
    }

    //std::cout << "Close the window to exit.\n";
    //QGuiApplication::exec();
    return 0;
}
