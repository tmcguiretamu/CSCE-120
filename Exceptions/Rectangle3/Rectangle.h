// Specification file for the Rectangle class
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
   private:
      double width;     // The rectangle's width
      double length;    // The rectangle's length
   public:
      // Exception classes
      class NegativeLength
         { };            // Empty class declaration
      class NegativeWidth
         { };            // Empty class declaration
		 
      // Default constructor
      Rectangle()
         { width = 0.0; length = 0.0; }
      
      // Mutator functions, defined in Rectangle.cpp
      void setWidth(double);
      void setLength(double);
      
      // Accessor functions
      double getWidth() const
         { return width; }

      double getLength() const
         { return length; }

      double getArea() const
         { return width * length; }
};
#endif