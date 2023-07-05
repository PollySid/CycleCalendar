//
// Created by Polly on 19.04.2023.
//

#include <fstream>
//#include <AUI/Logging/ALogger.h>
#include "DataArr.h"

using namespace std::chrono;

DataArr::DataArr() {
    std::ifstream f("MyData.json");
    if (f.is_open()) {
        json j = json::parse(f);

        cyclesArr = j["cycles"].get<std::vector<Cycle>>();
        datesArr = j["dates"].get<std::vector<DateInfo>>();
    }

    Cycle myCycle;        // - this was for test
    myCycle.dateOfBeginning = year_month_day(year(2023), month(6), day(26));
    cyclesArr.push_back(myCycle);

    DateInfo myDate(year_month_day(year(2023), month(7), day(5)));        // - this was also for test
    myDate.setHappy(2);
    myDate.setBlood(DateInfo::Bloods::SO);
    datesArr.push_back(myDate);
}

//void DataArr::addCycle(Cycle& cycle) {
//    cyclesArr.push_back(cycle);
//    std::ofstream f("MyData.json");
//    json j = {"cycles", cycle};
//    f << j << std::endl;
//}
//
//void DataArr::addData(DateInfo& date) {
//    datesArr.push_back(date);
//    std::ofstream f("MyData.json");
//    json j = {"dates", date};
//    f << j << std::endl;
//}
//
//const std::vector<Cycle>& DataArr::getCycles() const {
//    return cyclesArr;
//}
//
//const std::vector<DateInfo>& DataArr::getDates() const {
//    return datesArr;
//}

std::optional<days> DataArr::getPositionInCycle(const year_month_day &date) const {
    for (const auto& cycle : cyclesArr) {
        if (auto res = cycle.positionOfDateInCycle(date)) {
            return res;
        }
    }
    return std::nullopt;
}

std::optional<DateInfo> DataArr::getDate(const year_month_day &date) const {
    for (const auto& day : datesArr) {
        if (day.getThisDate() == date) {
            return day;
        }
    }
    return std::nullopt;
}




//const time_point now = current_zone()->to_local(system_clock::now());
//const year_month_day today{floor<days>(now)};   // current date
//// and this date will be added to the previous cycle
//
//auto myDate = DateInfo();
//myDate.setBlood(DateInfo::Bloods::MIDDLE);
//json j;
//to_json(j, myDate);
//
//std::ofstream outfile ("MyData.json");
//outfile << j << std::endl;
//outfile.close();


//failik "MyData.json"