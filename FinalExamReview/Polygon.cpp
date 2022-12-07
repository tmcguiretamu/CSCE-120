#include <iostream>
using std::cout, std::endl;

/*
Implement the member functions for the Polygon class, including the Rule of Three: a destructor, a copy constructor, and a copy assignment operator.

*/

struct Point {
  int x;
  int y;
};

class Polygon {

private:
  Point* vertices; // remember to think arrays for this
  int numVertices;

public:
  Polygon(); // constructor
  ~Polygon(); // destructor  
  Polygon(const Polygon& poly);  // copy constructor
  Polygon& operator=(const Polygon& poly);  // copy assignment operator

  // other member functions
  void addVertex(int x, int y);
  Point* getVertices() const;
  int getNumVertices() const;
  void print(); // outputs the list of vertices (x1, y1), (x2, y2), ... 
};

int main() {
  Polygon p1;
  p1.addVertex(1, 2);
  p1.addVertex(2, 5);
  p1.addVertex(3, 4);
  p1.addVertex(3, 3);
  cout << "Polygon p1:" << endl;
  p1.print();
  
  Polygon p2(p1);
  p2.addVertex(3, 2);
  cout << "Polygon p2:" << endl;
  p2.print();
  
  Polygon p3;
  p3 = p1;
  p3.addVertex(2, 2);
  cout << "Polygon p3:" << endl;
  p3.print();
  
}

Polygon::Polygon() // constructor
{
   numVertices = 0;
   vertices = nullptr;
}

Polygon::~Polygon() // destructor  
{
   delete [] vertices;
}

Polygon::Polygon(const Polygon& poly)  // copy constructor
{
   this->numVertices = poly.numVertices;
   this->vertices = new Point[numVertices];
   for(int i = 0; i < numVertices; ++i) {
      this->vertices[i].x = poly.vertices[i].x;
      this->vertices[i].y = poly.vertices[i].y;
   }
}

Polygon& Polygon::operator=(const Polygon& poly)  // copy assignment operator
{
   if (this == &poly) return *this;
   this->numVertices = poly.numVertices;
   delete [] this->vertices;
   this->vertices = new Point[numVertices];
   for(int i = 0; i < numVertices; ++i) {
      this->vertices[i].x = poly.vertices[i].x;
      this->vertices[i].y = poly.vertices[i].y;
   }
   return *this;   
}


// other member functions
void Polygon::addVertex(int x, int y) {
   Point *temp = nullptr;
   if (numVertices == 0) {   
      temp = new Point[1];
   }
   else {
      temp = new Point[numVertices+1];
      for (int i = 0; i < numVertices; ++i)
      {
         temp[i].x = vertices[i].x;
         temp[i].y = vertices[i].y;
      }
   }
   temp[numVertices].x = x;
   temp[numVertices].y = y;
   ++numVertices;
   delete [] vertices;
   vertices = temp;
}

Point* Polygon::getVertices() const {
   return vertices;
}

int Polygon::getNumVertices() const {
   return numVertices;
}

void Polygon::print() // outputs the list of vertices (x1, y1), (x2, y2), ...
{
   for (int i = 0; i < numVertices; ++i)
      cout << "(" << vertices[i].x << "," << vertices[i].y << ")" << endl;
   cout << endl;
}   
