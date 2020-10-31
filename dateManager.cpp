#include "dateManager.h"
#include <iostream>
#include <regex>

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
string DateManager::dayOfTheWeek(){
  int year = std::stoi(date.substr(0, 4));
  int month = std::stoi(date.substr(5, 2));
  int day = std::stoi(date.substr(8, 2));

  std::tm theTime = {0, 0, 0, day, month, year};
  std::time_t dayFilter = std::mktime(&theTime);
  std::tm * filteredTime = std::localtime(&dayFilter);

  int theDay = ((filteredTime->tm_wday) + 3) % 7;

  std::string dayName = "";
  if(theDay == 0){
    dayName = "Sunday";
  } else if(theDay == 1){
    dayName = "Monday";
  } else if(theDay == 2){
    dayName = "Tuesday";
  } else if(theDay == 3){
    dayName = "Wednesday";
  } else if(theDay == 4){
    dayName = "Thursday";
  } else if(theDay == 5){
    dayName = "Friday";
  } else if(theDay == 6){
    dayName = "Saturday";
  }
  
  return "The Day Of The Week " + dayName;
}

//Gets the amount of days between two dates
int DateManager::getDateDifference(string secondDate)
{
  int days = 0;

  int firstYear = std::stoi(date.substr(0, 4));
  int firstMonth = std::stoi(date.substr(5, 2));
  int firstDay = std::stoi(date.substr(8, 2));

  int secondYear = std::stoi(secondDate.substr(0, 4));
  int secondMonth = std::stoi(secondDate.substr(5, 2));
  int secondDay = std::stoi(secondDate.substr(8, 2));


  int yearsPast = secondYear - firstYear;
  //If the second year is before the first, the second date is older.
  if (yearsPast < 0)
  {
    return -1;
  } 
  else if (yearsPast == 0 && (secondMonth - firstMonth) < 0) //If the years are the same but the second month is before the first, the second date is older.
  {
    return -1;
  }
  else if (yearsPast == 0 && (secondMonth - firstMonth) == 0 && (secondDay - firstDay) < 0) //If the year and month is the same but the second day is before the first day, the second date is older.
  {
    return -1;
  }

  //For each full year that is passed add 365 days.
  days += yearsPast == 0 ? 0 : (yearsPast - 1) * 365;

  int currentMonth = firstMonth;
  //For the remaining year we are either in the final year or the year before it.
  int currentYear = yearsPast == 0 ? secondYear : secondYear - 1;

  //If we are in the same year and the same month to start off we just add the days between the first and second day and we are done
  if (firstMonth == secondMonth && currentYear == secondYear)
  {
    days += secondDay - firstDay;
  }
  else
  {
    //Loop through the remaining months adding the days past in each month
    while (currentMonth != secondMonth || currentYear != secondYear)
    {
      //We do not go through the full first month so we subtract however many days have already passed.
      if (currentMonth == firstMonth)
      {
        days += checkMonth(currentMonth, currentYear) - firstDay;
      }
      else //Add the number of days in the month if we went through the whole month
      {
        days += checkMonth(currentMonth, currentYear);      
      }
      //Increment the current month and if we go to a new year increment current year and set the month to 1.
      if (currentMonth == 12)
      {
        currentMonth = 1;
        currentYear++;
      }
      else
      {
        currentMonth++;
      }
    }
    //Add the reamining days in the final month.
    days += secondDay; 
  }

  return days;
}

DateManager::~DateManager()
{

}
