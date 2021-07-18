#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

#include <simplecppmainwindow.h>
#include <QApplication>



namespace simplecpp{

    typedef QPoint XPoint ;
    typedef QColor Color;

#define COLOR(c) (Color(x))
    class Sprite;

    extern std::unique_ptr<QApplication> appObj;
    extern std::unique_ptr<SimpleCppMainWindow> winObj;

    // Canvas management functions
    void initCanvas(const char window_title[]="Simplecpp Canvas", const int w=500, const int h=500);
    void closeCanvas();
    void repaint();
    int canvas_width();
    int canvas_height();
    void beginFrame();
    void endFrame();

    // Canvas drawing functions
    void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);
    void drawPolygon(XPoint *points, int nPoints, Color fillColor,
                     bool fill = true, unsigned int lineWidth = 2,
                     int lineStyle = 1, int capStyle = 1, int joinStyle = 1, int fillRule = 1,
                     int function = 1); // TODO: Unsed argument?

    // Sprite management functions
    void addSprite(Sprite *t);
    void removeSprite(Sprite *t);
    void c_imprint(Sprite* s);

}

#endif
