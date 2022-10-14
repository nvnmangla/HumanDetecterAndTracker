#include  <iostream>
#include<assert.h>

class Item{
Price p = new Price();
public:
  Item(int priceOfItem){
  p.setPrice(priceOfItem);
}
public:
  double calcSubTotal(int numItems){
  return numItems * p.getPrice();
}
public:
  double calcTotal(double subTotal, double tax){
  return subTotal + tax;
}
};


// Stub Class
class Price {        
  private:

    int testPrice; 

    Price(int priceOfItem) { 
      testPrice = priceOfItem;
    }
  public:
    
    
    void setPrice(int testPrice){
      Price::testPrice = testPrice;
    };
    
    int getPrice(){
      return Price::testPrice;
    };

  // testing 

  Item item;
  void testCalcSubTotal(){
      assert(testItem.calcSubTotal(2) == 2*Price::getPrice());
      assert(testItem.calcSubTotal(100) == 100*Price::getPrice());

}
    void testCalcTotal(){
      assert(testItem.calcTotal(50, 5) == 55);
      assert(testItem.calcTotal(10, 1) == 11);
    }

};
