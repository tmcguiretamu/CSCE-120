//This is the implementation for the class Sale.
//The interface for the class Sale is in
//the header file sale.h.
#include "sale.h"

    Sale::Sale() 
    { price = 0.0;}

    Sale::Sale(double thePrice) 
    { price = thePrice; }

    double Sale::bill() const 
    { return price; }

    double Sale::savings(const Sale& other) const
    { return ( bill() - other.bill() ); }

    bool operator < (const Sale& first, const Sale& second)
    { return (first.bill() < second.bill()); }

