#include <canvas.h>

using namespace std::string_literals;

std::string Canvas::toString() {
    return "This is Canvas"s;
}

std::unique_ptr<Canvas> Canvas::createCanvas(std::string fileName, const unsigned width, const unsigned height) {
    QString fName(fileName.c_str());

    if(fName.isEmpty()) {
        return std::make_unique<WindowCanvas>(width, height);
    }
    else if(fName.endsWith(".txt", Qt::CaseInsensitive)) {
        return std::make_unique<TraceCanvas>();
    }
    else {
        return std::make_unique<ImageCanvas>(fName, width, height);
    }    
}

namespace simplecpp{
    std::unique_ptr<QGuiApplication> theApp;
    std::unique_ptr<Canvas> theCanvas;

    void initCanvas(const unsigned width, const unsigned height) {
        auto argc {0};
        char *argv = nullptr;

        theApp = std::make_unique<QGuiApplication>(argc, &argv);
        theCanvas = Canvas::createCanvas(std::string(), width, height);
    }

    void closeCanvas() {
        theCanvas->close();
        theApp->processEvents();    // Process any residual events
        theApp->quit();

        theCanvas.reset(nullptr);
        theApp.reset(nullptr);
    }
}