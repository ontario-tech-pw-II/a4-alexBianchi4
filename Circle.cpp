//updated by alexander bianchi [100754627]


#include <iostream>
#include <cmath>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
  this->x = x;
  this->y = y;
  this->r = r;
}

double Circle::area() const {
  return M_PI * (r*r);
}

double Circle::operator+(const Circle & c) const
{
   return area() + c.area();

}

Circle & Circle::operator++()
{
  r++;
  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  r++;
  return temp;

}

ostream & operator<<(ostream &out, const Circle &c)
{

  out << "Circle =(" << c.x << "," << c.y << "," << c.r << ")" << endl;
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
  cout << "\tx: ";
  in >> c.x;
  
  cout << "\ty: ";
  in >> c.y;
  
  cout << "\tr: ";
  in >> c.r;
 // Read a circle information form the in stream

  return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
   Circle a;
   Circle b(2,3,3.0);

   a.print();
   b.print();
  
   cout << "The area a + b is: " << a+b << endl;
   ++a;
   a.print();

   a++;
   a.print();

   cout << a;

   cin >> a;
   cout <<a;

  return 0;

}
