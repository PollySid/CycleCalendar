//
// Created by Polly on 18.04.2023.
//

#pragma once

#include <chrono>
#include <optional>
#include <nlohmann/json.hpp>
#include "Util.h"
using json = nlohmann::json;

class Cycle {
    friend inline void to_json(json& j, const Cycle& cycle);
    friend inline void from_json(const json& j, Cycle& cycle);
public:
    Cycle();

    /**
     * @return length of this cycle.
     * From "dateOfBeginning" to "dateOfEnding".
     * If the field "dateOfEnding" contains 0 then returns count of days from "dayOfBeginning" to current date
     * (takes it from the system)
     */
    std::chrono::days getLengthOfCycle();

    /**
     * @return serial number of this date in the cycle from 0.
     * If it returns nullopt then this cycle doesn't contain this date.
     */
    [[nodiscard]] std::optional<std::chrono::days> positionOfDateInCycle(const std::chrono::year_month_day& date) const;

    ~Cycle();

//private:
    /**
     * @brief this cycle's beginning date
     */
    std::chrono::year_month_day dateOfBeginning;

    /**
     * @brief this cycle's ending date
     * @details
     * if it contains 0 then this is the current cycle
     */
    std::optional<std::chrono::year_month_day> dateOfEnding;
};


inline void to_json(json& j, const Cycle& cycle) {
    if (cycle.dateOfEnding != std::nullopt) {
        j = json{{"date of beginning", std::chrono::sys_days(cycle.dateOfBeginning)},
                 {"date of ending", std::chrono::sys_days(*cycle.dateOfEnding)}
        };
    } else {
        j = json{{"date of beginning", std::chrono::sys_days(cycle.dateOfBeginning)},
                 {"date of ending", 0}
        };
    }
}

inline void from_json(const json& j, Cycle& cycle) {
    j.at("date of beginning").get_to(cycle.dateOfBeginning);
    if (j.at("date of ending") != 0) {
        j.at("date of ending").get_to(cycle.dateOfEnding);
    } else {
        cycle.dateOfEnding = std::nullopt;
    }
}


