
/************object model class*********************/
/*******************************************************/
#include <iostream>
#include <string>

using namespace std;


class racquet{

  private:

  string brand;
  double diameter;
  double weight;

  public:

  racquet(string b, double dia, double w){
     brand = b;
     diameter = dia;
     weight = w;
   }

   void setBrand(string b){
     brand = b;
   }

   string getBrand(){
     return brand;
   }

  void setDiameter(double d){
     diameter = d;
   }

   double getDiameter() const{
     return diameter;
   }

   void setWeight(int w){
     weight = w;
   }

   double getWeight(){
     return weight;
   }
};
