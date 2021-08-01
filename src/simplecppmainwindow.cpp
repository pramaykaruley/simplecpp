#include <simplecppmainwindow.h>
#include <QDebug>

SimpleCppMainWindow::SimpleCppMainWindow(QString title, int width, int height, QWindow *parent)
    : QRasterWindow(parent)
{
    setTitle(title);
    setWidth(width);
    setHeight(height);

    screenBuffer = std::make_unique<QBackingStore> (this);
    pendingCmd.reserve(10000);
}

SimpleCppMainWindow::~SimpleCppMainWindow()
{

}

void SimpleCppMainWindow::exposeEvent(QExposeEvent *)
{
    if (isExposed())
        renderNow();
}

void SimpleCppMainWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    screenBuffer->resize(resizeEvent->size());
}


void SimpleCppMainWindow::renderNow()
{
    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    screenBuffer->beginPaint(rect);

    QPaintDevice *device = screenBuffer->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), QColor(243,243,244));
    render(&painter);
    painter.end();

    screenBuffer->endPaint();
    screenBuffer->flush(rect);
}

void SimpleCppMainWindow::render(QPainter *painter)
{
    for (auto &currCmd : pendingCmd)
    {
        QPen pen;

        switch(currCmd.type){
        case CmdType::Line:
            pen.setColor(currCmd.lineCmd.foreColor);
            pen.setWidth(currCmd.lineCmd.width);
            painter->setPen(pen);
            painter->drawLine(currCmd.lineCmd.start, currCmd.lineCmd.end);
            break;
        case CmdType::Rect:
            break;
        }
    }

    //qDebug() << "Render called";
    pendingCmd.clear();
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
    DrawingCommand newDrawingCmd {
        CmdType::Line,      // For line
        {
            {start, end, lineColor, lineWidth}  // LineCmd initialization
        }
    };
    pendingCmd.push_back(newDrawingCmd);
}
