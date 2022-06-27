#include <string>
#include <canvas.h>

// Factory method for constructing canvas
std::unique_ptr<Canvas> canvasFactory::makeCanvas(std::string canvasType) {
    if(canvasType == "Trace") {
        return std::make_unique<TraceCanvas>();
    }
    else 
    {
        return std::make_unique<QtCanvas>();
    }        
}
    

