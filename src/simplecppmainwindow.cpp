#include <simplecppmainwindow.h>
#include <QDebug>

SimpleCppMainWindow::SimpleCppMainWindow(QString title, int width, int height, QWindow *parent)
    : QRasterWindow(parent)
{
    setTitle(title);
    setWidth(width);
    setHeight(height);

    screenBuffer = std::make_unique<QBackingStore> (this);
    offScreenBuffer = std::make_unique<QImage> (width, height, QImage::Format_RGB32);
    
    offScreenBuffer->fill(QColor(243,243,244));    // Fill background colour
}

SimpleCppMainWindow::~SimpleCppMainWindow()
{

}

void SimpleCppMainWindow::exposeEvent(QExposeEvent *)
{
    renderNow();
}

void SimpleCppMainWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    screenBuffer->resize(resizeEvent->size());
}


void SimpleCppMainWindow::renderNow()
{
    qDebug() << "renderNow called";

    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    screenBuffer->beginPaint(rect);

    QPaintDevice *device = screenBuffer->paintDevice();
    
    // Copy image to the screen
    QPainter screenPainter(device);
    screenPainter.drawImage(QPoint(0, 0), *offScreenBuffer);
    screenPainter.end();

    screenBuffer->endPaint();
    screenBuffer->flush(rect);    
}

bool SimpleCppMainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void SimpleCppMainWindow::drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth)
{
    qDebug() << "Drawing line";

    QPen pen;
    pen.setColor(lineColor);
    pen.setWidth(lineWidth);

    // Write to offscreen buffer
    QPainter painter(offScreenBuffer.get());
    painter.setPen(pen);
    painter.drawLine(start, end);        
    painter.end();

    update();   // Redraw everything

    QGuiApplication::processEvents();
}
