//
// Created by Polly on 31.05.2023.
//

#pragma once
#include <chrono>
#include <nlohmann/json.hpp>
//#include "DataArr.h"
//#include "Cycle.h"

namespace util {
    std::chrono::year_month_day getToday();
}

namespace std::chrono {
    inline void to_json(nlohmann::json &j, const std::chrono::year_month_day &ymd) {
        j = std::chrono::sys_days(ymd).time_since_epoch().count();
    }

    inline void from_json(const nlohmann::json &j, std::chrono::year_month_day &date) {
        date = std::chrono::sys_days(std::chrono::days(j));
    }
}
//    inline void from_json(const nlohmann::json& j, std::chrono::sys_days& date) {
//        date = std::chrono::sys_days(std::chrono::days(j));
//    }
//}

namespace std {
    template<typename T>
    inline void to_json(nlohmann::json& j, const std::optional<T>& value) {
        j = *value;
    }

    template<typename T>
    inline void from_json(const nlohmann::json& j, std::optional<T>& value) {
        value = std::optional<T>(j);
    }
}


//inline void to_json(json& j, const DateInfo& date) {
//    j = json{{"date", date.thisDate},
//             {"blood", date.blood},
//             {"painfulCycle", date.painfulCycle},
//             {"act", date.act},
//             {"painfulAct", date.painfulAct},
//             {"happy", date.happy}
//    };
//}
//
//inline void from_json(const json &j, DateInfo& date) {
//    j.at("date").get_to(date.thisDate);
//    j.at("blood").get_to(date.blood);
//    j.at("painfulCycle").get_to(date.painfulCycle);
//    j.at("act").get_to(date.act);
//    j.at("painfulAct").get_to(date.painfulAct);
//    j.at("happy").get_to(date.happy);
//}


//inline void to_json(json& j, const Cycle& cycle) {
//    j = json{{"date of beginning", cycle.dateOfBeginning},
//             {"date of ending", cycle.dateOfEnding},
//    };
//}
//
//inline void from_json(const json& j, Cycle& cycle) {
//    j.at("date of beginning").get_to(cycle.dateOfBeginning);
//    j.at("date of ending").get_to(cycle.dateOfEnding);
//}