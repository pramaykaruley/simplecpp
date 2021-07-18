#include <composite.h>

namespace simplecpp {

  Composite::Composite(double x, double y, Composite* owner)
    : Sprite(x,y,owner){
  }

  void Composite::addPart(Sprite* p){
    parts.push_back(p);
  }

  void Composite::paint(Pose *p){
    if(visible){
      for(size_t i=0; i<parts.size(); i++){
    if(p){
      Pose r = Pose(*p, pose);
      parts[i]->paint(&r);
    }
    else {
      parts[i]->paint(&pose);
    }
      }
    }
  }

}
