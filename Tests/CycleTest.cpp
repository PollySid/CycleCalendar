//
// Created by Polly on 10.05.2023.
//

#include "gtest/gtest.h"
#include "Cycle.h"
using namespace std::chrono;

TEST(Cycle, positionOfDateInCycle) {
    Cycle c1 = Cycle();
    c1.dateOfBeginning = year_month_day(year(2000), month(1), day(1));
    c1.dateOfEnding = year_month_day(year(2000), month(1), day(30));
    EXPECT_EQ(c1.positionOfDateInCycle(year_month_day(year(2000), month(1), day(10))), days(9));
    EXPECT_EQ(c1.positionOfDateInCycle(year_month_day(year(2000), month(1), day(30))), days(29));
    EXPECT_EQ(c1.positionOfDateInCycle(year_month_day(year(2000), month(5), day(30))), std::nullopt);

}

TEST(Cycle, positionOfDateInCycle2) {
    Cycle c2 = Cycle();
    c2.dateOfBeginning = year_month_day(year(2000), month(1), day(31));
    c2.dateOfEnding = year_month_day(year(2000), month(2), day(29));
    EXPECT_EQ(c2.positionOfDateInCycle(year_month_day(year(2000), month(1), day(31))), days(0));
}