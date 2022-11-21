//
// Created by hanna on 11/19/2022.
//

#ifndef AOC_CPP_2021_DAY3_HPP
#define AOC_CPP_2021_DAY3_HPP


#include <vector>
#include "Day.hpp"

class Day3: public Day {
public:
    explicit Day3(std::string input);

    [[nodiscard]]
    std::string Part1() const override;

    [[nodiscard]]
    std::string Part2() const override;

private:
    kj;
    std::vector<std::string> mNums;
};

#endif //AOC_CPP_2021_DAY3_HPP
