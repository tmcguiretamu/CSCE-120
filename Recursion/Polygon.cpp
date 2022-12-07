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
  
  Polygon p2(p);
  p2.addVertex(3, 2);

  Polygon p3;
  p3 = p1;
  p3.addVertex(2, 2);
}

Polygon::Polygon() // constructor
{
}
Polygon::~Polygon() // destructor  
{
}
Polygon::Polygon(const Polygon& poly)  // copy constructor
{
}
Polygon& Polygon::operator=(const Polygon& poly)  // copy assignment operator
{
}


// other member functions
void Polygon::addVertex(int x, int y) {}
Point* Polygon::getVertices() const {}
int Polygon::getNumVertices() const {}
void Polygon::print(); // outputs the list of vertices (x1, y1), (x2, y2), ...
{
}   
