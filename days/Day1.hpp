//
// Created by hanna on 11/18/2022.
//

#ifndef AOC_CPP_2021_DAY1_HPP
#define AOC_CPP_2021_DAY1_HPP

#include <climits>
#include <vector>
#include "Day.hpp"

class Day1 : public Day {
public:
    explicit Day1(std::string input);

    [[nodiscard]]
    std::string Part1() const override;

    [[nodiscard]]
    std::string Part2() const override;

private:
    std::vector<int> mItems;
};

#endif //AOC_CPP_2021_DAY1_HPP
