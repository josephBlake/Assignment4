// File done by Alexander Blake and Lucas Larocco
#include "dateManager.h"
#include <gtest/gtest.h>

// Tests for stories 1 and 2 By Lucas Larocco
TEST(DateManagerTest, DateDifference)
{
  DateManager * dateManager = new DateManager("2020-03-19");
  //Valid dates

  //Same Year

  //Same Month
  EXPECT_EQ(5, dateManager->getDateDifference("2020-03-24"));
  //Next Month
  EXPECT_EQ(27, dateManager->getDateDifference("2020-04-15"));
  EXPECT_EQ(38, dateManager->getDateDifference("2020-04-26"));
  //More Than One Month
  EXPECT_EQ(209, dateManager->getDateDifference("2020-10-14"));
  EXPECT_EQ(221, dateManager->getDateDifference("2020-10-26"));

  //Year Difference

  //Same Month
  EXPECT_EQ(370, dateManager->getDateDifference("2021-03-24"));
  //Next Month
  EXPECT_EQ(392, dateManager->getDateDifference("2021-04-15"));
  EXPECT_EQ(403, dateManager->getDateDifference("2021-04-26"));
  //More Than One Month
  EXPECT_EQ(574, dateManager->getDateDifference("2021-10-14"));
  EXPECT_EQ(586, dateManager->getDateDifference("2021-10-26"));

  //More than One Year (4 years)

  //Same Month
  EXPECT_EQ(1466, dateManager->getDateDifference("2024-03-24"));
  //Next Month
  EXPECT_EQ(1488, dateManager->getDateDifference("2024-04-15"));
  EXPECT_EQ(1499, dateManager->getDateDifference("2024-04-26"));
  //More Than One Month
  EXPECT_EQ(1670, dateManager->getDateDifference("2024-10-14"));
  EXPECT_EQ(1682, dateManager->getDateDifference("2024-10-26"));

  //Out of order dates

  //Previous Year
  EXPECT_EQ(-1, dateManager->getDateDifference("2019-03-19"));
  
  //Previous Month
  EXPECT_EQ(-1, dateManager->getDateDifference("2020-02-19"));

  //Previous Day
  EXPECT_EQ(-1, dateManager->getDateDifference("2020-03-18"));

}


// Tests for stories 3 and 4 By Alexander Blake

// Tests that program can properly calculate future date based
// on amount of days and given initlal date.
TEST(DateManagerTest, FutureDate) 
{
   // Test Year Changes
   DateManager * dateManager = new DateManager("1999-08-09");
   EXPECT_EQ("New Date: 2000/8/9", dateManager->calculateFutureDate(365));
   dateManager = new DateManager("2000-08-09");
   EXPECT_EQ("New Date: 2001/8/9", dateManager->calculateFutureDate(366));
   // Test Month Changes
   dateManager = new DateManager("1999-08-09");
   EXPECT_EQ("New Date: 1999/11/17", dateManager->calculateFutureDate(100));
   dateManager = new DateManager("2008-01-31");
   EXPECT_EQ("New Date: 2008/3/1", dateManager->calculateFutureDate(30));
   // Test Day Changes
   dateManager = new DateManager("2014-05-15");
   EXPECT_EQ("New Date: 2014/5/25", dateManager->calculateFutureDate(10));
   dateManager = new DateManager("2012-02-01");
   EXPECT_EQ("New Date: 2012/2/29", dateManager->calculateFutureDate(28));
   // Test More Than One Change
   dateManager = new DateManager("1999-11-17");
   EXPECT_EQ("New Date: 2000/2/9", dateManager->calculateFutureDate(84));
   dateManager = new DateManager("2007-11-17");
   EXPECT_EQ("New Date: 2009/4/1", dateManager->calculateFutureDate(500));
}

// Tests that program can properly give the correct day of the week when given a date.
TEST(DateManagerTest, DayOfTheWeek) {
   DateManager * dateManager = new DateManager("2018-05-06");
   EXPECT_EQ("The Day Of The Week Sunday", dateManager->dayOfTheWeek());
   dateManager = new DateManager("2019-07-08");
   EXPECT_EQ("The Day Of The Week Monday", dateManager->dayOfTheWeek());
   dateManager = new DateManager("2018-12-11");
   EXPECT_EQ("The Day Of The Week Tuesday", dateManager->dayOfTheWeek());
   dateManager = new DateManager("2020-05-20");
   EXPECT_EQ("The Day Of The Week Wednesday", dateManager->dayOfTheWeek());
   dateManager = new DateManager("2020-01-30");
   EXPECT_EQ("The Day Of The Week Thursday", dateManager->dayOfTheWeek());
   dateManager = new DateManager("2020-10-30");
   EXPECT_EQ("The Day Of The Week Friday", dateManager->dayOfTheWeek());
   dateManager = new DateManager("2019-03-23");
   EXPECT_EQ("The Day Of The Week Saturday", dateManager->dayOfTheWeek());
}


// Main method for running all tests
int main(int argc, char **argv) 
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
