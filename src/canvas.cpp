#include <simplecppmainwindow.h>
#include <QApplication>
#include <sprite.h>
#include <canvas.h>

namespace simplecpp {
std::unique_ptr<QApplication> appObj;
std::unique_ptr<SimpleCppMainWindow> winObj;

void initCanvas(const char *title, const int width, const int height){

    // Construct command-line arguments for the application
    auto argc {1};
    auto cmd {"simplecpp"};
    const char *argv[2];
    argv[0] = cmd;
    argv[1] = nullptr;

    // Initialize the application
    appObj = std::make_unique<QApplication>(argc, reinterpret_cast<char**>(&argv));

    // Create and open application window
    winObj = std::make_unique<SimpleCppMainWindow> (title, width, height);
    winObj->show();

}

void closeCanvas(){
    // Close application window
    winObj->close();
    winObj.reset(nullptr);

    // Close application
    appObj->exit();
    appObj.reset(nullptr);

}

void repaint() {
    // TODO
}

int canvas_width(){
   return winObj->width();
 }

 int canvas_height(){
   return winObj->height();
 }

void drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth){
    winObj->drawLine(start, end, lineColor, lineWidth);
}

void drawPolygon(XPoint *points, int nPoints, Color fillColor,
                 bool fill, unsigned int lineWidth,
                 int lineStyle, int capStyle, int joinStyle, int fillRule,
                 int function){ // TODO: Unsed argument?

}

void beginFrame(){
//    globalRepaintFlag = false;
}

void endFrame(){
//  	globalRepaintFlag = true;
//    repaint();
}

void addSprite(Sprite *t){
    // TODO
/*
 *     if(t){
       spriteSet.insert(t);
    }
    */
}


void removeSprite(Sprite *t){
    // TODO
    /*
    if(t){
      for( iter = spriteSet.begin(); iter != spriteSet.end(); iter ++){
    if((*iter) == t){spriteSet.erase(iter); break;}
      }
    }
    repaint();
    */
}

void c_imprint(Sprite* s){
    //bindFBO();
    s->paint();
    //unbindFBO();
}

}
