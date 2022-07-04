#include <canvas.h>
#include <turtle.h>
#include <turtleSim.h>
#include <iostream>
#include <QThread>

namespace simplecpp{

  void turtleSim(const char* name, int w, int h){
     initCanvas(w,h);
    // _PsystemTurtle_= new Turtle;
  }

  void closeTurtleSim(){
    closeCanvas();
  }

  void resetTurtle(){
    theSystemTurtle().Sprite::reset(canvas_width()/2,canvas_height()/2);
  }

  void hide(bool state){
    if(state) theSystemTurtle().hide();
    else theSystemTurtle().show();
  }
  void penDown(bool state){theSystemTurtle().penDown(state);}
  void penUp(bool state){theSystemTurtle().penDown(!state);}
  void left(double dist){theSystemTurtle().left(dist);}
  void left(int dist){left(float(dist));}
  void right(double dist){theSystemTurtle().right(dist);}
  void right(int dist){right(float(dist));}
  void forward(double dist){theSystemTurtle().forward(dist);}
  void forward(int dist){forward(float(dist));}

  double sine(double x){return sin(PI*x/180);}
  double cosine(double x){return cos(PI*x/180);}
  double tangent(double x){return tan(PI*x/180);}
  double arcsine(double x){return asin(x)*180/PI;}
  double arccosine(double x){return acos(x)*180/PI;}
  double arctangent(double x){return atan(x)*180/PI;}
  double arctangent2(double y, double x){return atan2(y,x)*180/PI;}
  void wait(unsigned long mSec) {QThread::msleep(mSec);}
}
