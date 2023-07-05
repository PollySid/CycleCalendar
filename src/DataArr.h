//
// Created by Polly on 19.04.2023.
//

#pragma once

#include <chrono>
#include <vector>
#include "Cycle.h"
#include "DateInfo.h"

class DataArr {
public:
//    void addCycle(Cycle& cycle);
//    void addData(DateInfo& date);
//    [[nodiscard]] const std::vector<Cycle>& getCycles() const;
//    [[nodiscard]] const std::vector<DateInfo>& getDates() const;
/**
 * @param date - you want to know the position of this date in a right cycle
 * @return serial number of this date in the right cycle from 0.
 * If it returns std::nullopt then this date doesn't belong to any cycle.
 */
    [[nodiscard]] std::optional<std::chrono::days> getPositionInCycle(const std::chrono::year_month_day& date) const;

    /**
 * @param date - you want to know the position of this date in a right cycle
 * @return serial number of this date in the right cycle from 0.
 * If it returns std::nullopt then this date doesn't belong to any cycle.
 */
    [[nodiscard]] std::optional<DateInfo> getDate(const std::chrono::year_month_day& date) const;
    ~DataArr() = default;
    DataArr(const DataArr&) = default;
    DataArr& operator=(const DataArr&) = delete;
    static DataArr& getInstance() {             // WOW! Is that a SINGLETON???
        if (!p_instance) {
            p_instance = new DataArr();
        }
        return *p_instance;
    }

private:
    DataArr();
    static inline DataArr* p_instance = nullptr;
    std::vector<Cycle> cyclesArr;
    std::vector<DateInfo> datesArr;
};
