#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

#include <simplecppmainwindow.h>
#include <QApplication>

namespace simplecpp{
extern std::unique_ptr<QApplication> appObj;
extern std::unique_ptr<SimpleCppMainWindow> winObj;

typedef QPoint XPoint ;
typedef QColor Color;

void initCanvas(const char window_title[]="Simplecpp Canvas", const int w=500, const int h=500);
void closeCanvas();
void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth);
}

#endif
