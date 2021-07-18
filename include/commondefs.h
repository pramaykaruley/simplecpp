#ifndef _COMMONDEFS_INCLUDED_
#define _COMMONDEFS_INCLUDED_

#include <cmath>
#include <qpoint.h>
#include <vector>

#define PI M_PI
typedef QPoint XPoint;

namespace simplecpp {

    struct Position{
      double x, y;
      Position();
      Position(double x1, double y1);
      Position operator+(Position p);
      double getX();
      double getY();
      double GetXDistance();
      double GetYDistance();
      void print(char *msg = nullptr);
    };

    class Pose{
      double a11,a12,a13,a21,a22,a23;
     public:
      Pose();
      Pose(double dx,double dy);
      Pose(double theta);
      Pose(double scale, bool s);
      Pose(const Pose &p, const Pose &q);
      XPoint prod(Position p) const;
      Position prodPosition(Position p);
      void compute_res_vertex(XPoint* xpt, std::vector<Position> vertex, int count) const;
      void compute_res_vertex(XPoint* xpt, Position *vertex, int count) const;
      Position unitX() const;
      Position getOrigin() const;
      Position getAtan2() const;
      double getOrientation() const;
      double X() const;
      double Y() const;
      double getScale() const;
      void setScale(double s);
      void print() const;
    };

}

#endif
