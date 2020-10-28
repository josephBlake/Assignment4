#include <string>
#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

using namespace std;

class DateManager {
public:
  DateManager();

  int checkMonth(int month, int year);

  string calculateFutureDate();

  ~DateManager();    
};

#endif
