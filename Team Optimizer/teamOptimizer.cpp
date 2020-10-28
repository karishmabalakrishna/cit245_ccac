#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <istream>
#include <algorithm>
#include "candidates.cpp"

using namespace std;


vector<string> candidateNames(3);
map<string, candidates> finalCandidates; 

//screening questions for candidate and saving the eligible candidates name into list and their information in the map
void candidateScreening(){

  string name;
  string projectRole;
  int experience;
  cout<< "Please enter name: " <<'\n';
 // cin >> name;
  cin.ignore();
  getline(cin, name);
  cout << "Select one area of interest: android, web, server" << '\n';
  cin>> projectRole;

  //convert the user entered role into lowercase
  transform(projectRole.begin(), projectRole.end(), projectRole.begin(), ::tolower); 

  cout<<"How much experience do you have in your area: " <<'\n';
  cin >> experience;

  if(projectRole == "android" || projectRole == "web" || projectRole == "server"){

        if(experience > 3)
        {
          cout <<"Congrats you are selected!" << '\n';
          //save the user name in list
          candidateNames.push_back(name);

          //save the candidates information in map
          finalCandidates.insert({name,candidates(name,projectRole,experience)});
        }

        else{
          cout <<'\n' <<"Sorry you are not selected! More than 3years of experience is required." <<'\n';
        }

     }

//if wrong role is entered the program will exit
     else{
       cout << "Wrong selection! Thank You!" <<'\n';
       exit(0);
     }
}

//modifying the role of candidate
void modifyRoleOfCandidate()
{
        string nameOfCandidate;
        string modifiedRole;

        cout << "Enter the name of candidate whose role you want to modify(case-sensitive)" << '\n';
       // cin >> nameOfCandidate;
        cin.ignore();
        getline(cin, nameOfCandidate);
        cout << '\n' << "Enter the modified role of candidate:" << '\n';
        cin >> modifiedRole;

        finalCandidates.at(nameOfCandidate).setInterest(modifiedRole);

        cout << '\n' << "The final list is: " << '\n';
        for (const auto& pair: finalCandidates) {
		  cout << "{" << pair.first << ": " << pair.second.getInterest()<<"}\n";

      }
}


//entry point of program
int main() {


  int choice ;
  string wantToContinue = "Yes";

//while loop to prompt user to select a choice. The while loop reset the question once the user is done and continues to run till user want to continue
 while(wantToContinue == "Yes" || wantToContinue == "yes"){
      
      cout << '\n' << "Welcome to Android Email Designing Project. Please type option to continue(1 ? 2 ? 3)" << '\n';
      cout << "1. Enter candidate Information"<<'\n';
      cout<<"2. Show the final candidates list with designation" << '\n';
      cout << "3. Modify the role of candidate" << '\n' << '\n';
      cin >> choice;

//First choice prompt user to answer the series of questions

      if(choice == 1){
        candidateScreening();

      }

//Second choice shows the list of users along with their role in key value pair in map.
 else if(choice == 2){

//if map is empty
      if(finalCandidates.empty()){
        cout << "No candidates has been finalized yet" <<'\n';
        break;
      }
      
//if map is not empty
      cout<<"Following candidates has been selected for above mentioned roles" <<'\n';

//for loop to iterate over the map
      for (const auto& pair: finalCandidates) {
		  cout << "{" << pair.first << ": " << pair.second.getInterest()<<"}\n";
	  }

    
}

//Third choice to modify the role of candidate
  else{
        modifyRoleOfCandidate();
  }

  //prompt user if they want to continue the program
      cout <<'\n' <<"Do you want to go back to Options?(Yes ? No)" <<'\n';
      cin >> wantToContinue;
}

}

