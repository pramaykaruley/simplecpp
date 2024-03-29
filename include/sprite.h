#ifndef _SPRITE_INCLUDED_
#define _SPRITE_INCLUDED_

#include <canvas.h>
#include <spriteInterface.h>
#include <iostream>
#include <commondefs.h>

namespace simplecpp{

class Sprite : public virtual SpriteInterface{
 protected:
  float z_index; // rank for painting
  static float max_z_index;  // ranks assigned so far
  Pose pose;
  bool visible;
  Color color;
  bool fill;
  void init(Composite* owner);
  bool penIsDown;
  double __angle__ = 0.0;
  double __scale__ = 1.0;
 public:
  Sprite( const Sprite& other );
  Sprite& operator=(const Sprite&);
  Sprite(Composite* owner = NULL);
  Sprite(double dx, double dy, Composite* owner = NULL);
  virtual ~Sprite();
  void reset(double dx, double dy, Composite* owner = NULL);

  virtual void forward(double distance);
  virtual void penDown(bool=true);
  virtual void penUp(bool=true);
  virtual void left(double Dangle){
    __angle__ -= Dangle;
    rotate(-Dangle*PI/180);
  }
  virtual void right(double Dangle){
    __angle__ += Dangle;
    rotate(Dangle*PI/180);
  }
  virtual double getX() const { return pose.X(); }
  virtual double getY() const { return pose.Y(); }
  virtual double getOrientation() const { 
    return pose.getOrientation(); 
  }
  virtual double getScale() const { return pose.getScale(); }

  virtual void paint(Pose *p=nullptr){};
  virtual void show();
  virtual void hide();
  virtual void rotate(double angle);
  virtual void face(Sprite &s);
  virtual void face(double x, double y, bool repaintP=true);
  virtual void setScale(double factor, bool repaintP=true);
  virtual void scale(double factor, bool repaintP=true);
  virtual void move(double xshift, double yshift, bool repaintP=true);
  virtual void moveTo(double x, double y, bool repaintP=true);
  virtual void print(std::string msg=""){std::cout << msg  << " Undefined.\n";}
  Sprite &setColor(Color c, bool repaintP=true);
  void setFill(bool v=true, bool repaintP=true);
  virtual void imprint(bool repaintP=true);
  virtual Position getOrigin() const {return pose.getOrigin();}
  virtual void setZIndex(float new_z_index);
  virtual float getZIndex() const;
  virtual Position getAtan2() const;
  virtual Sprite* clone(){return NULL;};
};
}

#endif
