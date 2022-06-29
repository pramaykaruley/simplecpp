#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

#include <memory>
#include <algorithm>

#include <QtGui>
#include <QDebug>

typedef QPoint XPoint ;
typedef QColor Color;

class Canvas : public QRasterWindow{
    public:
    virtual ~Canvas() = default;
    virtual std::string toString();
    virtual void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth) = 0;
    
    static std::unique_ptr<Canvas> createCanvas(std::string fileName = std::string()); 
};

class TraceCanvas : public Canvas {
    public:
    TraceCanvas() = default;
    std::string toString();
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);
};

class ImageCanvas : public Canvas {    
    QString fileName;

    protected:
    QImage img;

    public:    
    ImageCanvas(const QString imageFileName, const unsigned width, const unsigned height);
    virtual ~ImageCanvas();
    std::string toString();
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);
};

class WindowCanvas : public ImageCanvas{
    Q_OBJECT

    public:
    WindowCanvas(const unsigned width, const unsigned height);
    std::string toString();
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);

    public slots:    
    void renderNow();

    protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

    private:
    QScopedPointer<QBackingStore> screenBuffer;
};
#endif
