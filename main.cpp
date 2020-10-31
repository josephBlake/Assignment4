// File done by Alexander Blake and Lucas Larocco

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

//Method By Lucas Larocco and Alexander Blake
int main(int argc, char *argv[]) {
  string command;
  cout << "(--help for Command Menu)" << endl;
  while(command != "quit")
  {
    // Gets initial command.
    cout << "Enter command" << endl;;
    cin >> command;

    // Checks what command, so long as it's valid, was called.
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
      // Gets a date
      string date;
      cout << "Enter date (format must be in yyyy-mm-dd)" << endl;
      cin >> date;

      // Sees what date-required command is actually being called
      if (isValidDate(date))
      {
        DateManager * dateManager = new DateManager(date);

        // The days after a date command
        if(command == "-f")
        {
          string inDays;
          cout << "Enter Number of Days" << endl;
          cin >> inDays;

          int days = getIntegerFromString(inDays);
          if (days > 0)
          {
            string futureDate = dateManager->calculateFutureDate(days);
            cout << futureDate << endl;
          }
          else
          {
            cout << "Invalid Number of Days" << endl;
          }
        } // The day of the week command
        else if(command == "-w")
        {
          string weekDay = dateManager->dayOfTheWeek();
          cout << weekDay << endl;
        } // The difference in dates command
        else if(command == "-d")
        {
          string secondDate;
          cout << "Enter Second Date" << endl;
          cin >> secondDate;
          if (isValidDate(secondDate))
          {
            int differenceInDays = dateManager->getDateDifference(secondDate);
            if (differenceInDays == -1)
            {
              cout << "The Second Date is Before the First Date" << endl;
            }
            else
            {
              cout << differenceInDays << " days" << endl; 
            }
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

//Method By Lucas Larocco
//Check if a command is included in the list of possible commands.
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

//Method By Lucas Larocco
//Checks if a date matches the regex used for each date.
bool isValidDate(string date)
{
  return regex_match(date, std::regex("[0-9][0-9][0-9][0-9]-[0-1][0-9]-[0-3][0-9]"));
}

//Method By Lucas Larocco
//Turns a string into an integer and makes sure it is a valid integer. A value of -1 is returned if the integer is not valid.
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

//Method By Lucas Larocco
//Print the menu with all the commands with their descriptions.
void printHelpMenu()
{
  cout << "\nCommand Menu \n" << endl;
  cout << "(Important Note: Type the command first and the program will then ask you for a date)\n" << endl;
  cout << "-f - Shows a new date after a specified number of days have been added to the original date - ex. (Input: -f 2020-03-19 5 Output: 2020-03-24)\n" << endl;
  cout << "-w - Shows the day of the week for the specific date - ex. (Input: -w 2020-10-30 Output: Friday)\n" << endl;
  cout << "-d - Shows the difference in days between the two dates - ex. (Input: -d 2020-03-19 2020-03-24 Output: 5 days)\n" << endl;
  cout << "quit - Exits program\n" << endl;
}






