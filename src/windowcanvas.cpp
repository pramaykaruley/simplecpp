# include <canvas.h>

using namespace std::string_literals;

WindowCanvas::WindowCanvas(const unsigned width, const unsigned height)
    : ImageCanvas(QString(), width, height),       
      screenBuffer(new QBackingStore(this)) {
        setGeometry(100, 100, width, height);
    // show();

    // Issue: show() raises follow up events only after a certain duration. 
    // Workaround: Wait for events to appear in the event queue
    // QThread::sleep(1);

    // QGuiApplication::processEvents();
    // QGuiApplication::exec();
}

std::string WindowCanvas::toString() {
    return "This is WindowCanvas"s;
}

void WindowCanvas::drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth) {
    ImageCanvas::drawLine(start, end, lineColor, lineWidth);

    QPoint topLeft(std::min(start.x(), end.x()), std::min(start.y(), end.y()));
    QPoint bottomRight(std::max(start.x(), end.x()), std::max(start.y(), end.y()));

    update(QRect(topLeft, bottomRight));   // Raise event to redraw screen area containing line
    // QGuiApplication::processEvents();
}

void WindowCanvas::exposeEvent(QExposeEvent *) {
    renderNow();
}

void WindowCanvas::resizeEvent(QResizeEvent *resizeEvent) {
    screenBuffer->resize(resizeEvent->size());
}

void WindowCanvas::renderNow() {
    qDebug() << "renderNow called";

    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    screenBuffer->beginPaint(rect);

    QPaintDevice *device = screenBuffer->paintDevice();
    
    // Copy image to the screen
    QPainter screenPainter(device);
    screenPainter.drawImage(QPoint(0, 0), img);
    screenPainter.end();

    screenBuffer->endPaint();
    screenBuffer->flush(rect);    
}

bool WindowCanvas::event(QEvent *event) {
    qDebug() << "Event received: " << event->type();

    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    
    return QRasterWindow::event(event);
}
