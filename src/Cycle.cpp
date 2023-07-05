//
// Created by Polly on 18.04.2023.
//

#include "Cycle.h"

using namespace std::chrono;

Cycle::Cycle() {
    const time_point now = current_zone()->to_local(system_clock::now());
    dateOfBeginning = static_cast<year_month_day>(floor<days>(now));     // current date
    dateOfEnding = std::nullopt;
}

days Cycle::getLengthOfCycle() {
    sys_days lastDay;
    if (!dateOfEnding) {
        const time_point now = current_zone()->to_local(system_clock::now());
        lastDay = static_cast<year_month_day>(floor<days>(now));
    } else {
        lastDay = *dateOfEnding;
    }
    return lastDay - sys_days(dateOfBeginning);
}

std::optional<std::chrono::days> Cycle::positionOfDateInCycle(const std::chrono::year_month_day& date) const {
    if (sys_days(dateOfBeginning) > sys_days(date)) {
        return std::nullopt;
    }
    if (dateOfEnding && *dateOfEnding < sys_days(date)) {
        return std::nullopt;
    }
    return sys_days(date) - sys_days(dateOfBeginning);
}

Cycle::~Cycle() = default;
