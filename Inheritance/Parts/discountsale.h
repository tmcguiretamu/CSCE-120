//This is the interface for the class DiscountSale.
#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"


    class DiscountSale : public Sale
    {
    public:
        DiscountSale();
        DiscountSale(double thePrice, double theDiscount);
        //Discount is expressed as a percent of the price.
        virtual double bill() const;
    protected:
        double discount;
    };



//This is the implementation for the class DiscountSale.

    DiscountSale::DiscountSale() : Sale(), discount(0)
    {}

    DiscountSale::DiscountSale(double thePrice, double theDiscount)
              : Sale(thePrice), discount(theDiscount)
    {}

    double DiscountSale::bill() const
    {
        double fraction = discount/100;
        return (1 - fraction)*price;
    }


#endif //DISCOUNTSALE_H