# include <canvas.h>

using namespace std::string_literals;

ImageCanvas::ImageCanvas(const QString imageFileName, const unsigned width, const unsigned height)
    : img(width, height, QImage::Format_RGB32) {
        auto backGroundColour = QColor(243,243,244);
        img.fill(backGroundColour);
        fileName = imageFileName;
}

ImageCanvas::~ImageCanvas() {    
    auto saveImageToFile = !fileName.isEmpty();
    if(saveImageToFile) {
        qDebug() << "Saving to file ";        
        img.save(fileName);
    }
}

std::string ImageCanvas::toString() {
    return "This is ImageCanvas"s + fileName.toStdString();
}

void ImageCanvas::drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth) {
    QPen pen(lineColor);    
    pen.setWidth(lineWidth);

    QPainter painter(&img);
    painter.setPen(pen);
    painter.drawLine(start, end);        
    // painter.end();
}