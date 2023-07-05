//
// Created by Polly on 31.05.2023.
//

#include "Util.h"
using namespace std::chrono;

std::chrono::year_month_day util::getToday() {
    const time_point now = current_zone()->to_local(system_clock::now());
    const year_month_day today{floor<days>(now)};
    return today;
}


