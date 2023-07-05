//
// Created by Polly on 19.04.2023.
//

#pragma once

#include <chrono>
#include <nlohmann/json.hpp>
#include "Util.h"
using json = nlohmann::json;

class DateInfo {
    friend inline void to_json(json& j, const DateInfo& date);
    friend inline void from_json(const json& j, DateInfo& date);

public:
    enum class Moods {
        BAD = 0,
        MIDDLE = 1,
        GOOD = 2
    };
    enum class Bloods {
        NO = 0,
        SO = 1,
        MIDDLE = 2,
        MUCH = 3
    };
    DateInfo();

    explicit DateInfo(std::chrono::year_month_day date);

    [[nodiscard]] const std::chrono::year_month_day &getThisDate() const;

//    void setThisDate(const std::chrono::year_month_day &thisDate);

    [[nodiscard]] Bloods getBlood() const;

    [[nodiscard]] std::string getStringBlood() const;

    void setBlood(Bloods blood);

    [[nodiscard]] bool isPainfulCycle() const;

    void setPainfulCycle(bool painfulCycle);

    [[nodiscard]] unsigned isAct() const;

    void setAct(unsigned act);

    [[nodiscard]] unsigned isPainfulAct() const;

    void setPainfulAct(unsigned painfulAct);

    [[nodiscard]] unsigned isHappy() const;

    void setHappy(unsigned happy);

    ~DateInfo();

private:
    std::chrono::year_month_day thisDate;
    Moods mood = Moods::MIDDLE;
    Bloods blood;
    bool painfulCycle;
    unsigned act;
    unsigned painfulAct;
    unsigned happy;
};

//namespace std::chrono {
//    inline void to_json(json& j, const std::chrono::year_month_day& ymd) {
//        j = std::chrono::sys_days(ymd).time_since_epoch().count();
//    }
//
//    inline void from_json(const json& j, std::chrono::year_month_day& date) {
//        date = std::chrono::sys_days(std::chrono::days(j));
//    }
//}


inline void to_json(json& j, const DateInfo& date) {
    j = json{{"date", date.thisDate},
             {"blood", date.blood},
             {"painfulCycle", date.painfulCycle},
             {"act", date.act},
             {"painfulAct", date.painfulAct},
             {"happy", date.happy}
    };
}

inline void from_json(const json &j, DateInfo& date) {
    j.at("date").get_to(date.thisDate);
    j.at("blood").get_to(date.blood);
    j.at("painfulCycle").get_to(date.painfulCycle);
    j.at("act").get_to(date.act);
    j.at("painfulAct").get_to(date.painfulAct);
    j.at("happy").get_to(date.happy);
}

