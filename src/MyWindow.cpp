//
// Created by Polly on 15.03.2023.
//
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/Util/ALayoutInflater.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AGroupBox.h>
#include <AUI/View/AButton.h>
#include "MyWindow.h"
#include "Calendar.h"
#include "Util.h"
#include <fmt/chrono.h>
#include "DataArr.h"

using namespace declarative;

MyWindow::MyWindow() : AWindow("Calendar", 400_dp, 600_dp) {
    auto myC = std::make_shared<Calendar>();
    myC->showMonth();
    auto tempToday = util::getToday();

    Label actualDate = std::format("{} {}, {}", tempToday.day(), tempToday.month(), tempToday.year());

    DataArr& myArr = DataArr::getInstance();
    Label posOfDayInCycle = [&]() -> AString {
        auto myOpt = myArr.getPositionInCycle(util::getToday());
        if (myOpt) {
            return "{}-й день цикла"_format(myOpt->count() + 1);
        } else {
            return "Пока циклов нет";
        }
    }();


    //tempMood
    std::string tempBlood;
    bool tempPainfulCycle = false;
    unsigned tempAct = 0;
    unsigned tempPainfulAct = 0;
    unsigned tempHappy = 0;
    if (auto thisDate = myArr.getDate(tempToday)) {
//        tempMood = "настроение: ещё не настроено";
        tempBlood.append(thisDate->getStringBlood());   // find a date in myArr and read its mark in "blood"
        tempPainfulCycle = thisDate->isPainfulCycle();
        tempAct = thisDate->isAct();
        tempPainfulAct = thisDate->isPainfulAct();
        tempHappy = thisDate->isHappy();
//    } else {    // here will be actions is this day has no marks
//
    }
    //Label mood = "настроение: {}"_format(/*???*/);
    Label blood = "кровь: {}"_format(tempBlood);
    Label painfulCycle = "болезненные месячные: {}"_format(tempPainfulCycle);
    Label act = "любовь: {}"_format(tempAct);
    Label painfulAct = "боль: {}"_format(tempPainfulAct);
    Label happy = "оргазм: {}"_format(tempHappy);

    setContents(Vertical {
        Horizontal {
                actualDate,
                posOfDayInCycle
        },
        myC,

        Vertical{   // show all labels of the day
//                mood,
                Horizontal{
                        blood,
                        Button{" изменить... "}.clicked(this, [this, &myArr, tempToday] {
                            auto menu2 = AWindow::current()->createOverlappingSurface(
                                    additionButton->getPositionInWindow(), {150_dp, 100_dp});
                            ALayoutInflater::inflate(menu2, Vertical{
                                    Label("обилие крови: "),
                                    Label(myArr.getDate(tempToday) ? myArr.getDate(tempToday)->getStringBlood() : "no"),
                                    Horizontal{
                                            Button{" + "}.clicked(this, [&myArr, tempToday] {
                                                myArr.getDate(tempToday)->setBlood(DateInfo::Bloods(int(myArr.getDate(tempToday)->getBlood()) + 1));
                                            }),
                                            Button{" - "},
                                    }
                            });
                        })
                },
                painfulCycle,
                act,
                painfulAct,
                happy
        }

    });

}
