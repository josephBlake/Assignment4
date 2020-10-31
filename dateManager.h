// File By Alexander Blake and Lucas Larocco
#include <string>
#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

using namespace std;

class DateManager {
public:
  // This is the constructor which will store a date for method usage.
  DateManager(string date);

  // The purpose of this method is to check what the end day of a month is based a date's current month.
  int checkMonth(int month, int year);

  // This method is the main function for the -f command in the program. This method returns what date it will be after a certain amount of days after a given date.
  string calculateFutureDate(int daysPast);

  // This method is the main function for the -w command in the program. This method returns what day of the week a given date is in.
  string dayOfTheWeek();

  int getDateDifference(string secondDate);

  ~DateManager();

private:
  string date;    
};

#endif
