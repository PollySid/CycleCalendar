//
// Created by Polly on 19.04.2023.
//

#include "DateInfo.h"
using namespace std::chrono;

DateInfo::DateInfo() : blood(Bloods::NO), painfulCycle(false), act(0), painfulAct(0), happy(0)
{
    const time_point now = current_zone()->to_local(system_clock::now());
    thisDate = static_cast<year_month_day>(floor<days>(now));
}

DateInfo::DateInfo(year_month_day date) : blood(Bloods::NO), painfulCycle(false), act(0), painfulAct(0), happy(0)
{
    thisDate = date;
}


const std::chrono::year_month_day &DateInfo::getThisDate() const {
    return thisDate;
}

//void DateInfo::setThisDate(const std::chrono::year_month_day &thisDate) {
//    DateInfo::thisDate = thisDate;
//}

DateInfo::Bloods DateInfo::getBlood() const {
    return blood;
}

std::string DateInfo::getStringBlood() const {
    switch(this->getBlood()) {
        case(DateInfo::Bloods::NO):
            return "нет";
        case(DateInfo::Bloods::SO):
            return "немного";
        case(DateInfo::Bloods::MIDDLE):
            return "средне";
        case(DateInfo::Bloods::MUCH):
            return "очень много";
    }
}

void DateInfo::setBlood(DateInfo::Bloods blood) {
    DateInfo::blood = blood;
}

bool DateInfo::isPainfulCycle() const {
    return painfulCycle;
}

void DateInfo::setPainfulCycle(bool painfulCycle) {
    DateInfo::painfulCycle = painfulCycle;
}

unsigned DateInfo::isAct() const {
    return act;
}

void DateInfo::setAct(unsigned act) {
    DateInfo::act = act;
}

unsigned DateInfo::isPainfulAct() const {
    return painfulAct;
}

void DateInfo::setPainfulAct(unsigned painfulAct) {
    DateInfo::painfulAct = painfulAct;
}

unsigned DateInfo::isHappy() const {
    return happy;
}

void DateInfo::setHappy(unsigned happy) {
    DateInfo::happy = happy;
}

DateInfo::~DateInfo() = default;
