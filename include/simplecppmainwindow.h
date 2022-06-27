#ifndef SIMPLECPPMAINWINDOW_H
#define SIMPLECPPMAINWINDOW_H

#include <QtGui>

typedef QPoint XPoint ;
typedef QColor Color;

enum struct CmdType {
    Line, Rect
};

struct LineCmd
{
    XPoint start, end;
    Color foreColor, backColor;
    unsigned width;
};

struct RectCmd
{
    XPoint start, end;
    Color foreColor, backColor;
    unsigned width;
};

struct DrawingCommand {
    CmdType type;    
};


class SimpleCppMainWindow : public QRasterWindow
{
    Q_OBJECT

public:
    SimpleCppMainWindow(QString title="Simplecpp Window", int width=800, int height=600, QWindow *parent = nullptr);
    ~SimpleCppMainWindow();
    virtual void render(QPainter *painter);

    // Drawing primitives
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);

public slots:
    void renderNow();

private:
     std::unique_ptr<QBackingStore> screenBuffer;
     std::vector<DrawingCommand> pendingCmd;     // Commands queued for rendering. Commands are cleared after rendering.

protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

};
#endif // SIMPLECPPMAINWINDOW_H
