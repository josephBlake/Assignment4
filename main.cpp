

#include "dateManager.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  std::string command = "";
  while(command != "quit")
  {
    cout << "Enter command" << endl;;
    cin >> command;

    if(command == "quit"){
      break;
    }

    string date = "";
    cout << "Enter date (format must be in yyyy/mm/dd)" << endl;
    cin >> date;

    DateManager * dateManager = new DateManager(date);

    if(command.substr(0, 2) == "-f")
    {
      int days;
      cout << "Enter Number of Days" << endl;
      cin >> days;

      string futureDate = dateManager->calculateFutureDate(days);
      cout << futureDate;
    }
        // This is reserved for Lucas's method.
        // Lucas will need to make a class for
        // the methods for his function.
        //if(){
        //}
  }
}


