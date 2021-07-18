#include <commondefs.h>
#include <iostream>

namespace simplecpp{

    Position::Position(){
      x = y = 0.0;
    }

    Position::Position(double x1, double y1){
      x = x1;
      y = y1;
    }

    Position Position::operator+(Position p){
      return Position(x+p.x, y+p.y);
    }

    double Position::getX(){
      return x;
    }

    double Position::getY(){
      return y;
    }

    double Position::GetXDistance(){
      return x;
    }

    double Position::GetYDistance(){
      return y;
    }

    void Position::print(char *msg){
        std::cout << msg <<": "<< x <<", "<< y<<std::endl;
    }

// class Pose
      Pose::Pose(){
        a11=a22=1;
        a21=a12=a13=a23=0;
      }

      Pose::Pose(double dx,double dy){
        a11=a22=1;
        a21=a12=0;
        a13=dx; a23=dy;
      }

      Pose::Pose(double theta){
        a11=a22=cos(theta);
        a21=sin(theta);
        a12=-a21;
        a13=a23=0;
      }

      Pose::Pose(double scale, bool s){
        a11=a22=scale;
        a21=a12=a13=a23=0;
      }

      Pose::Pose(const Pose &p, const Pose &q){
        a11 = p.a11*q.a11+p.a12*q.a21;
        a12 = p.a11*q.a12+p.a12*q.a22;
        a13 = p.a11*q.a13+p.a12*q.a23+p.a13;
        a21 = p.a21*q.a11+p.a22*q.a21;
        a22 = p.a21*q.a12+p.a22*q.a22;
        a23 = p.a21*q.a13+p.a22*q.a23+p.a23;
      }

      XPoint Pose::prod(Position p) const{
        auto x = a11*p.x+a12*p.y+a13 + 0.5;  // round, not truncate.
        auto y = a21*p.x+a22*p.y+a23 + 0.5;
        return XPoint(x, y);
      }


      Position Pose::prodPosition(Position p) {
        return Position(a11*p.x+a12*p.y+a13, a21*p.x+a22*p.y+a23);
      }

      void Pose::compute_res_vertex(XPoint* xpt, std::vector<Position> vertex, int count) const{
        for(int i=0; i<count; i++)
          xpt[i] = prod(vertex[i]);
      }

      void Pose::compute_res_vertex(XPoint* xpt, Position *vertex, int count) const{
        for(int i=0; i<count; i++)
          xpt[i] = prod(vertex[i]);
      }

      Position Pose::unitX() const{
        double s = getScale();
        return Position(a11/s,a21/s);}

      Position Pose::getOrigin() const{
        return Position(a13,a23);
      }

      Position Pose::getAtan2() const{
        return Position(a11,a21);
      }

      double Pose::getOrientation() const{
        return atan2(a21,a11);
      }

      double Pose::X() const{ return a13; }
      double Pose::Y() const{ return a23; }

      double Pose::getScale() const {return sqrt(pow(a11,2)+pow(a12,2));}

      void Pose::setScale(double s){
        double olds = getScale();
        double r = s/olds;
        a11 *= r;
        a12 *= r;
        //a13 *= r;
        a21 *= r;
        a22 *= r;
        //a23 *= r;
      }

      void Pose::print() const{
        std::cout << a11 << ", " << a12 << ", " << a13 <<"  "
                  << a21 << ", " << a22 << ", " << a23 << std::endl;
      }

}
