

#include "dateManager.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    std::string command = "";
    DateManager * dateManager = new DateManager();
    while(command != "quit"){
        cout << "Enter command \n";
        cin >> command;
        if(command.substr(0, 2) == "-f"){
            cout << dateManager->calculateFutureDate();
        }
        // This is reserved for Lucas's method.
        // Lucas will need to make a class for
        // the methods for his function.
        //if(){
        //}
    }
}
