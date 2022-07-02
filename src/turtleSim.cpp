#include <canvas.h>
#include <turtle.h>
#include <turtleSim.h>
#include <iostream>

static simplecpp::Turtle theSystemTurtle;

void check(const char*){
  // if(!_PsystemTurtle_){
  //   std::cout << "You need to call turtleSim before calling "<<msg<<".\n";
  //   exit(1);
  // }
}

namespace simplecpp{

  void turtleSim(const char* name, int w, int h){
     initCanvas(w,h);
    // _PsystemTurtle_= new Turtle;
  }

  void closeTurtleSim(){
    closeCanvas();
  }

  void resetTurtle(){
    theSystemTurtle.Sprite::reset(canvas_width()/2,canvas_height()/2);
  }

  void hide(bool state){
    if(state) theSystemTurtle.hide(); 
    else theSystemTurtle.show();
  }
  void penDown(bool state){check("penDown"); theSystemTurtle.penDown(state);}
  void penUp(bool state){check("penUp"); theSystemTurtle.penDown(!state);}
  void left(double dist){check("left"); theSystemTurtle.left(dist);}
  void left(int dist){check("left"); left(float(dist));}
  void right(double dist){check("right"); theSystemTurtle.right(dist);}
  void right(int dist){check("right"); right(float(dist));}
  void forward(double dist){check("forward"); theSystemTurtle.forward(dist);}
  void forward(int dist){check("forward"); forward(float(dist));}

  double sine(double x){return sin(PI*x/180);}
  double cosine(double x){return cos(PI*x/180);}
  double tangent(double x){return tan(PI*x/180);}
  double arcsine(double x){return asin(x)*180/PI;}
  double arccosine(double x){return acos(x)*180/PI;}
  double arctangent(double x){return atan(x)*180/PI;}
  double arctangent2(double y, double x){return atan2(y,x)*180/PI;}


}
