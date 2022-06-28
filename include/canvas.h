#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

#include <memory>
#include <QGuiApplication>
#include <simplecppmainwindow.h>

class Canvas {
    public:
    virtual std::string toString();
    virtual void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth) = 0;
};

class TraceCanvas : public Canvas {
    public:
    TraceCanvas() = default;
    std::string toString();
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);
};

class QtCanvas : public Canvas {
    std::unique_ptr<QGuiApplication> app;
    std::unique_ptr<SimpleCppMainWindow> win;
    
    public:
    QtCanvas();
    std::string toString();
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);
};

class canvasFactory {
    public:
    static std::unique_ptr<Canvas> makeCanvas(std::string canvasType);    
};
#endif
