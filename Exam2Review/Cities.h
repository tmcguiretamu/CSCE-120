#ifndef _CITIES_H
#define _CITIES_H

#include <string>

class City
{
   private:
      unsigned ID;         // City ID  
      string name;         // City name
      string state;        // City state
      unsigned population; // Population of city   
   public:
      // Constructor
      City(unsigned ID, string name, string state, unsigned population);
      // accessors
      unsigned getId() const;   
      string getName() const;  
      string getState() const;  
      unsigned getPopulation() const;  
      // mutators
      void setId(unsigned newID); 
      void setName(string newName);  
      void setState(string newState);
      void setPopulation(unsigned newPop);     
}
#endif