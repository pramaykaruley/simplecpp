#ifndef SIMPLECPPMAINWINDOW_H
#define SIMPLECPPMAINWINDOW_H

#include <QtGui>

typedef QPoint XPoint ;
typedef QColor Color;

class SimpleCppMainWindow : public QRasterWindow
{
    Q_OBJECT

public:
    SimpleCppMainWindow(QString title="Simplecpp Window", int width=800, int height=600, QWindow *parent = nullptr);
    ~SimpleCppMainWindow();

    // Drawing primitives
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);

public slots:
    void renderNow();

private:
     std::unique_ptr<QBackingStore> screenBuffer;
     std::unique_ptr<QImage> offScreenBuffer;     

protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

};
#endif // SIMPLECPPMAINWINDOW_H
