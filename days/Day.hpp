//
// Created by Josh Hannaford on 11/14/22.
//

#ifndef AOC_CPP_2021_DAY_HPP
#define AOC_CPP_2021_DAY_HPP

#include <string>

class Day {
public:
    explicit Day(std::string input) : mInput(std::move(input)) {}
    virtual ~Day() = default;

    virtual std::string Part1() = 0;
    virtual std::string Part2() = 0;

protected:
    std::string mInput;
};

#endif //AOC_CPP_2021_DAY_HPP
