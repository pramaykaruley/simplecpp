#include<iostream>
#include <turtleSim.h>

using namespace simplecpp;

int main(int, char **) {
    unsigned nSteps {0};

    std::cout << "Enter number of steps: ";
    std::cin >> nSteps;

    for(auto stepIdx {0u}; stepIdx < nSteps; stepIdx ++) {
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
        wait(50);   // Wait for 50 milliseconds
    }
    return 0;
}
