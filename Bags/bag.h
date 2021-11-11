// FILE: bag.h
//
// Instead of using a template, we can easily rewrite a class if we use a typedef.
// We will still have to recompile
//
// TYPEDEFS and MEMBER CONSTANTS for the Bag class:
//   typedef _____ value_type
//     Bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   static const int DEFAULT_CAPACITY = _____
//     Bag::DEFAULT_CAPACITY is the initial capacity of a bag that is created
//     by the default constructor.
//
// CONSTRUCTOR for the Bag class:
//   Bag(int initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the Bag class:
//   void reserve(int new_capacity)
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//   int erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void operator +=(const Bag& addend) 
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the Bag class:
//   int size( ) const 
//     Postcondition: Return value is the total number of items in the bag.
//
//   int count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bag
//
// NONMEMBER FUNCTIONS for the Bag class:
//   Bag operator +(const Bag& b1, const Bag& b2)
//   Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the Bag class:
//   Assignments and the copy constructor may be used with bag objects.


#ifndef BAG_H
#define BAG_H

class Bag
{
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        static const int DEFAULT_CAPACITY = 30;        
        // CONSTRUCTORS and DESTRUCTOR
        Bag(int initial_capacity = DEFAULT_CAPACITY);
        Bag(const Bag& source);
        ~Bag( );
        // MODIFICATION MEMBER FUNCTIONS
        void reserve(int new_capacity);
        bool erase_one(const value_type& target);
        int erase(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const Bag& addend);
        void operator =(const Bag& source);
        // CONSTANT MEMBER FUNCTIONS
        int size( ) const { return used; }
        int count(const value_type& target) const;
    private:
        value_type *data;     // Pointer to partially filled dynamic array
        int used;       // How much of array is being used
        int capacity;   // Current capacity of the bag
};

// NONMEMBER FUNCTIONS for the Bag class
Bag operator +(const Bag& b1, const Bag& b2);


#endif
