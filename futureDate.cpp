

#include <string>
#include "futureDate.h"
#include <iostream>
using namespace std;

int checkMonth(int month, int year){
    int endDay = 0;

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        endDay = 31;
    }

    if(month == 4 || month == 6 || month == 9 || month == 11){
        endDay = 30;
    }

    if(month == 2){
        if(year % 4 == 0){
            endDay = 29;
        }else{
            endDay = 28;
        }
    }

    return endDay;
}

std::string calculatedFutureDate(std::string command){
    cout << command;
    string date = command.substr(3, 10);
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    int daysPast = std::stoi(command.substr(11, 10));

    while(daysPast / 365 >= 1 || daysPast / 366 >= 1){
        if(year % 4 == 0){
            year = year + 1;
            daysPast = daysPast - 366;
        }else{
            year = year + 1;
            daysPast = daysPast - 365;
        }
    }
    
    while((day + daysPast) > checkMonth(month, year)){
        int daysToNextMonth = (checkMonth(month, year) - day) + 1;
        day = 1;
        if(month == 12){
            month = 1;
            year = year + 1;
        }else{
            month = month + 1;
        }
        daysPast = daysPast - daysToNextMonth;
    }

    day = day + daysPast;
    return "New Date: ";
}
