#include "dateManager.h"
#include <iostream>

using namespace std;

// This is the constructor which will store a date for method usage.
DateManager::DateManager(string date)
{
  this->date = date;
}

// The purpose of this method is to check what the end day of a month is based a date's current month.
int DateManager::checkMonth(int month, int year)
{
  int endDay = 0;

  // Each number represents their corresponding month of the year. So this means 1 is January, 5 is May, 12 is December, and so on.
  if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
  {
    endDay = 31;
  }

  if(month == 4 || month == 6 || month == 9 || month == 11)
  {
    endDay = 30;
  }

  // Feburary is a special case thanks to leap years.
  if(month == 2)
  {
    if(year % 4 == 0)
    {
      endDay = 29;
    }
    else
    {
      endDay = 28;
    }
  }

  return endDay;
}

// This method is the main function for the -f command in the program. This method returns what date it will be after a certain amount of days after a given date.
string DateManager::calculateFutureDate(int daysPast)
{
  int year = std::stoi(date.substr(0, 4));
  int month = std::stoi(date.substr(5, 2));
  int day = std::stoi(date.substr(8, 2));

  // This loop checks how many, if any, years have passed in order to shrink the amount of days past.
  while(daysPast / 365 >= 1 || daysPast / 366 >= 1)
  {
    if(year % 4 == 0)
    {
      year = year + 1;
      daysPast = daysPast - 366;
    }
    else
    {
      year = year + 1;
      daysPast = daysPast - 365;
    }
  }

  // This loop checks how many, if any, months have passed in order to shrink the amount of days past.
  while((day + daysPast) > checkMonth(month, year))
  {
    int daysToNextMonth = (checkMonth(month, year) - day) + 1;
    day = 1;
    if(month == 12)
    {
      month = 1;
      year = year + 1;
    }
    else
    {
      month = month + 1;
    }
    daysPast = daysPast - daysToNextMonth;
  }

  // After checking that the amount of days past will no longer bring the date to a new month, the rest is simply added to the day part of the date.
  day = day + daysPast;

  std::string newYear = std::to_string(year);
  std::string newMonth = std::to_string(month);
  std::string newDay = std::to_string(day);
  return "New Date: " + newYear + "/" + newMonth + "/" + newDay;
}

// This method is the main function for the -w command in the program. This method returns what day of the week a given date is in.
// TODO Finish this method
string DateManager::dayOfTheWeek(){
  return "";
}

DateManager::~DateManager()
{

}
