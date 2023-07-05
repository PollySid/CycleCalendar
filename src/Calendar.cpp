//
// Created by Polly on 21.03.2023.
//

#include "Calendar.h"
#include <time.h>
#include <AUI/Util/UIBuildingHelpers.h>
#include <chrono>
#include "Util.h"
using namespace std::chrono;
using namespace declarative;


Calendar::Calendar() {

}

void Calendar::showMonth() {
    setLayout(_new<AGridLayout>(7, 6));

    setExtraStylesheet(_new<AStylesheet>(AStylesheet{
            {
                t<ALabel>(),
                TextAlign::CENTER,
            }
    }));
    _<ALabel> weekdays[7] = {Label ("Пн"),
                             Label ("Вт"),
                             Label ("Ср"),
                             Label ("Чт"),
                             Label ("Пт"),
                             Label ("Сб"),
                             Label ("Вс")};
    for (int i = 0; i < 7; ++i) {
        addView(weekdays[i]);
    }

    auto today = util::getToday();
    // and this date will be added to the previous cycle

    const year_month_day firstMonthsDay{today.year(), today.month(), day(1)};
    const auto weekDay1 = weekday(firstMonthsDay);            // first day of the month

    for (int i = 1; i < weekDay1.c_encoding(); ++i) {
        addView(SpacerExpanding());
    }

    auto lastMonthDay = static_cast<unsigned>
            ((year_month{today.year(), today.month()} / last).day());
    auto dNow = static_cast<unsigned>(today.day());
    for (int i = 0; i < lastMonthDay;) {
        if (++i == dNow) {
            addView(Label("{}"_format(i)) with_style {
                Border (5_dp, 0xdb4035_rgb),
                Padding (10_dp)
            });
        }
        else {
            addView(Label("{}"_format(i)));
        }
    }

}


