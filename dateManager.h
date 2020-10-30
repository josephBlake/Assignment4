#include <string>
#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

using namespace std;

class DateManager {
public:
  DateManager(string date);

  int checkMonth(int month, int year);

  string calculateFutureDate(int daysPast);

  string dayOfTheWeek();

  int getDateDifference(string secondDate);

  ~DateManager();

private:
  string date;    
};

#endif
