

#include "dateManager.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;

bool isValidCommand(string command);
bool isValidDate(string date);
int getIntegerFromString(string days);
void printHelpMenu();

string possibleCommands[] = {"-f", "-w", "-d"};

int main(int argc, char *argv[]) {
  string command;
  cout << "(--help for Command Menu)" << endl;
  while(command != "quit")
  {
    cout << "Enter command" << endl;;
    cin >> command;

    if(command == "quit")
    {
      break;
    }
    else if(command == "--help")
    {
      printHelpMenu();
    }
    else if(isValidCommand(command))
    {
      string date;
      cout << "Enter date (format must be in yyyy/mm/dd)" << endl;
      cin >> date;

      if (isValidDate(date))
      {
        DateManager * dateManager = new DateManager(date);

        if(command == "-f")
        {
          string inDays;
          cout << "Enter Number of Days" << endl;
          cin >> inDays;

          int days = getIntegerFromString(inDays);
          if (days != -1)
          {
            string futureDate = dateManager->calculateFutureDate(days);
            cout << futureDate << endl;
          }
          else
          {
            cout << "Invalid Number of Days" << endl;
          }
        }
        else if(command == "-w")
        {
          string weekDay = dateManager->dayOfTheWeek();
          cout << weekDay << endl;
        }
        else if(command == "-d")
        {
          string secondDate;
          cout << "Enter Second Date" << endl;
          cin >> secondDate;
          if (isValidDate(secondDate))
          {
            int differenceInDays = dateManager->getDateDifference(secondDate);
	    cout << differenceInDays << " days" << endl;
          }
          else
          {
            cout << "Invalid Date" << endl;
          }
        }
      }
      else
      {
        cout << "Invalid Date" << endl;
      }
    }
    else
    {
      cout << "Invalid Command" << endl;
    }
  }
}

bool isValidCommand(string command)
{
  for (string cmd: possibleCommands)
  {
    if (command == cmd)
    {
      return true;
    }
  }
  return false;
}

bool isValidDate(string date)
{
  return regex_match(date, std::regex("[0-9][0-9][0-9][0-9]-[0-1][0-9]-[0-3][0-9]"));
}

int getIntegerFromString(string days)
{
  istringstream s(days);
  int value;
  if (!(s >> value))
  {
    return -1;
  }
  char c;
  if (s >> c)
  {
    return -1;
  }

  return value;
}

void printHelpMenu()
{
  cout << "\nCommand Menu \n" << endl;
  cout << "-f - Shows a new date after a specified number of days have been added to the original date - ex. (Input: -f 2020-03-19 5 Output: 2020-03-24)\n" << endl;
  cout << "-w - Shows the day of the week for the specific date - ex. (Input: -w 2020-10-30 Output: Friday)\n" << endl;
  cout << "-d - Shows the difference in days between the two dates - ex. (Input: -d 2020-03-19 2020-03-24 Output: 5 days)\n" << endl;
}






