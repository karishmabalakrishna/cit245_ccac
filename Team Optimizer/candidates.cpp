#include <iostream>
#include <string>

using namespace std;


class candidates{
  
 private:
  string candName;
   string candInterest;
  int candExperience;

  public:
   candidates(string name, string interest, int experience){
     candName = name;
     candInterest = interest;
     candExperience = experience;
   }

   void setName(string n){
     candName = n;
   }

   string getName(){
     return candName;
   }

  void setInterest(string i){
     candInterest = i;
   }

   string getInterest() const{
     return candInterest;
   }

   void setExperience(int e){
     candExperience = e;
   }

   int getExperience(){
     return candExperience;
   }

};
