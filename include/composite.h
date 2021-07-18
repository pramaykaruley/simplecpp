#ifndef _COMPOSITE_INCLUDED_
#define _COMPOSITE_INCLUDED_
#include <sprite.h>

namespace simplecpp{
class Composite : public Sprite{
  std::vector<Sprite*> parts;
 public:
  Composite(double x, double y, Composite* owner);
  void addPart(Sprite* p);
  void paint(Pose *p);
};
}
#endif

