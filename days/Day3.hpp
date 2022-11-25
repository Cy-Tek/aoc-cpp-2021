//
// Created by hanna on 11/19/2022.
//

#ifndef AOC_CPP_2021_DAY3_HPP
#define AOC_CPP_2021_DAY3_HPP


#include <vector>
#include <functional>
#include "Day.hpp"

class Day3: public Day {
public:
    explicit Day3(std::string input);

    [[nodiscard]]
    std::string Part1() const override;

    [[nodiscard]]
    std::string Part2() const override;

private:
    enum Generator {
        Oxygen,
        CO2
    };

    static int FilterVec(const std::vector<std::string> &list, Generator type);
    static constexpr char GetTestBit(Generator type, int ones, int zeros);

    std::vector<std::string> mNums;
};

#endif //AOC_CPP_2021_DAY3_HPP