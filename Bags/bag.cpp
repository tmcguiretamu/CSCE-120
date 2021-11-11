// FILE: bag.cpp
// CLASS implemented: bag (see bag.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. The actual items of the bag are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable data;
//   3. The size of the dynamic array is in the member variable capacity.

#include <cassert>       // Provides assert function
#include "bag.h"
using namespace std;

    Bag::Bag(int initial_capacity)
    {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }

    Bag::Bag(const Bag& source)
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        for (int i = 0; i < used; i++) 
           data[i] = source.data[i];
    }

    Bag::~Bag( )
    {
         delete [ ] data;
    }

    void Bag::reserve(int new_capacity)
    {
        value_type *larger_array;

        if (new_capacity == capacity)
            return; // The allocated memory is already the right size.

        if (new_capacity < used)
            new_capacity = used; // Can’t allocate less than we are using.

        larger_array = new value_type[new_capacity];
        for (int i = 0; i < used; i++) 
           larger_array[i] = data[i];
        delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
    }
    
    int Bag::erase(const value_type& target)
    {
      int index = 0;
      int many_removed = 0;

      while (index < used)
      {
         if (data[index] == target)
         {
            --used;
            data[index] = data[used];
            ++many_removed;
         }
         else
            ++index;
      }

         return many_removed;
    }

    bool Bag::erase_one(const value_type& target)
    {
      int index; // The location of target in the data array    
      // First, set index to the location of target in the data array,  
      // which could be as small as 0 or as large as used-1.
      // If target is not in the array, then index will be set equal to used.
      index = 0;
      while ((index < used) && (data[index] != target))
         ++index;

      if (index == used) // target isn't in the Bag, so no work to do
         return false;

      // When execution reaches here, target is in the Bag at data[index].
      // So, reduce used by 1 and copy the last item onto data[index].
      --used;
      data[index] = data[used];
      return true;
    }

    void Bag::insert(const value_type& entry)
    {   
        if (used == capacity)
            reserve(used+1);
        data[used] = entry;
        ++used;
    }
    
    void Bag::operator +=(const Bag& addend)
    // Library facilities used: algorithm
    {
        if (used + addend.used > capacity)
            reserve(used + addend.used);
        for (int i = 0; i < capacity; i++) 
            data[i+used] = addend.data[i];       
        used += addend.used;
    }

    void Bag::operator =(const Bag& source)
    {
      value_type *new_data;

      // Check for possible self-assignment:
      if (this == &source)
            return;

      // If needed, allocate an array with a different size:
      if (capacity != source.capacity)
      { 
         new_data = new value_type[source.capacity];
         delete [ ] data;
         data = new_data;
         capacity = source.capacity;
      }

      // Copy the data from the source array:
      used = source.used;
      for (int i = 0; i < used; i++) 
         data[i] = source.data[i];
    }

    int Bag::count(const value_type& target) const
    {
      int answer;
      int i;

      answer = 0;
      for (i = 0; i < used; ++i)
         if (target == data[i])
      ++answer;
      return answer;
    }

    Bag operator +(const Bag& b1, const Bag& b2)
    {
      Bag answer(b1.size( ) + b2.size( ));

      answer += b1; 
      answer += b2;
      return answer;
    }

