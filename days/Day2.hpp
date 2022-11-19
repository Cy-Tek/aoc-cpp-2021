//
// Created by hanna on 11/19/2022.
//

#ifndef AOC_CPP_2021_DAY2_HPP
#define AOC_CPP_2021_DAY2_HPP


#include <vector>
#include "Day.hpp"
#include "../Parser.hpp"

class Day2: public Day {
public:
    explicit Day2(std::string input);

    [[nodiscard]]
    std::string Part1() const override;

    [[nodiscard]]
    std::string Part2() const override;

private:
    enum Direction {
        Forward,
        Up,
        Down
    };

    struct Instruction {
        Direction direction;
        int distance;

        explicit Instruction(const std::string& str);
    };

    static Direction WordToDirection(const std::string &word);

    std::vector<Instruction> mInstructions;
};


#endif //AOC_CPP_2021_DAY2_HPP
