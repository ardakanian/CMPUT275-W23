/*
  Operator overloading, example #1

  Course: CMPUT 275
  Zac Friggstad, 2021
*/

#include <iostream>

using namespace std;

// Models an incredibly simple 2-dimensional point with integer coordinates
// We can add points (like vector addition, it adds component-wise)
struct Point2D {
  int x, y;

  // component-wise addition, returns the new point
  Point2D operator+(Point2D rhs) {
    Point2D c;
    c.x = x + rhs.x; // same as this->x + rhs.x
    c.y = y + rhs.y;
    return c;
  }
};

// Extract from an input stream. NOTE: cin is of type istream
istream& operator>>(istream& in_stream, Point2D& point) {
  in_stream >> point.x >> point.y;
  return in_stream;
  // can also do the following one-liner
  // return in_stream >> point.x >> point.y;
  // because the extractions into the integers will ALSO return a reference
  // to in_stream
};

// Insert into an output stream. NOTE: cout is of type ostream
ostream& operator<<(ostream& out_stream, Point2D point) {
  out_stream << '(' << point.x << ',' << point.y << ')';
  return out_stream;
}

int main() {
  Point2D a, b;
  cout << "Enter a point (with a space between the x and y values): ";
  cin >> a;
  cout << "Enter another point: ";
  cin >> b;

  cout << a << " + " << b << " = " << a+b << endl << endl;

  cout << "Can also do this: " << a.operator+(b)
       << ", but that defeats the purpose :)" << endl << endl;

  // Challenge question: how/why does the following work?
  (operator<<(operator<<(cout, a), b)) << endl;

  return 0;
}
