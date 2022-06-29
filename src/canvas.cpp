#include <canvas.h>

using namespace std::string_literals;

std::string Canvas::toString() {
    return "This is Canvas"s;
}

std::unique_ptr<Canvas> Canvas::createCanvas(std::string fileName) {
    QString fName(fileName.c_str());

    auto width  {800u};
    auto height {600u};

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
