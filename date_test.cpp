
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
// TODO Finish the tests.

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


// TODO Delete commented previous tests later. Keep for now as reminder of test formatting.

// Tests that program can properly detect non-triangles
//TEST(TriangleTest, NotATriangle) {
//   EXPECT_EQ(NOT_TRIANGLE, triangleType(45.0, 45.0, 45.0));
//   EXPECT_EQ(NOT_TRIANGLE, triangleType(180.0, 30.0, 30.0));
//   EXPECT_EQ(NOT_TRIANGLE, triangleType(60.034, 60.1267, 60.3245));
//   EXPECT_EQ(NOT_TRIANGLE, triangleType(90.00005, 45.00006, 45.00002));
//}

// Tests that program can properly detect equilateral triangles
//TEST(TriangleTest, EquilateralTriangle) {
//   EXPECT_EQ(EQUILATERAL_TRIANGLE, triangleType(60.0, 60.0, 60.0));
//   EXPECT_EQ(EQUILATERAL_TRIANGLE, triangleType(60.00002, 60.00002, 60.00002));
//}

// Tests that program can properly detect right triangles
//TEST(TriangleTest, RightTriangle) {
//   EXPECT_EQ(RIGHT_TRIANGLE, triangleType(90.0, 45.0, 45.0));
//   EXPECT_EQ(RIGHT_TRIANGLE, triangleType(31.9, 58.1, 90.0));
//   EXPECT_EQ(RIGHT_TRIANGLE, triangleType(59.655, 90.00004657, 30.345));
//}

// Tests that program can properly detect isosceles triangles
//TEST(TriangleTest, IsoscelesTriangle) {
//   EXPECT_EQ(ISOSCELES_TRIANGLE, triangleType(45.5, 45.5, 89.0));
//   EXPECT_EQ(ISOSCELES_TRIANGLE, triangleType(80.0, 80.0, 20.0));
//   EXPECT_EQ(ISOSCELES_TRIANGLE, triangleType(80.0, 80.0, 20.0));
//   EXPECT_EQ(ISOSCELES_TRIANGLE, triangleType(50.00005465, 50.00003645, 80.0));
//}

// Tests that program can properly detect obtuse triangles
//TEST(TriangleTest, ObtuseTriangle) {
//   EXPECT_EQ(OBTUSE_TRIANGLE, triangleType(100.0, 34.7, 45.3));
//   EXPECT_EQ(OBTUSE_TRIANGLE, triangleType(120.0, 27.3, 32.7));
//   EXPECT_EQ(OBTUSE_TRIANGLE, triangleType(95.3450, 29.655, 55.00002849));
//   EXPECT_EQ(OBTUSE_TRIANGLE, triangleType(150.0000468, 26.355, 3.645));
//}

// Tests that program can properly detect acute triangles
//TEST(TriangleTest, AcuteTriangle) {
//   EXPECT_EQ(ACUTE_TRIANGLE, triangleType(50.0, 60.0, 70.0));
//   EXPECT_EQ(ACUTE_TRIANGLE, triangleType(49.6, 47.3, 83.1));
//   EXPECT_EQ(ACUTE_TRIANGLE, triangleType(56.675, 78.325, 45.00007843));
//}

// Tests that program can properly compare floats with a tolerance to the 10^-4 decimal
//TEST(TriangleTest, ComparingWithTolerance) {
   // Comparing two floats to see if they are equal
//   EXPECT_EQ(true, equalsWithTolerance(53.45673254632, 53.4567957478));
//   EXPECT_EQ(true, equalsWithTolerance(67.00006838498, 67.00003462354365));
//   EXPECT_EQ(false, equalsWithTolerance(60.00002, 60.0002));
//   EXPECT_EQ(false, equalsWithTolerance(45.2450, 45.2455));
   // Comparing a float with 90 to see if it is bigger than 90
//   EXPECT_EQ(true, greaterThanWithTolerance(90.2450));
//   EXPECT_EQ(false, greaterThanWithTolerance(90.000024657));
   // Comparing a float with 90 to see if it is smaller than 90
//   EXPECT_EQ(true, lessThanWithTolerance(89.99989999));
//   EXPECT_EQ(false, lessThanWithTolerance(90.00002));
//}

// Main method for running all tests
int main(int argc, char **argv) 
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
