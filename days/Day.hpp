//
// Created by Josh Hannaford on 11/14/22.
//

#ifndef AOC_CPP_2021_DAY_HPP
#define AOC_CPP_2021_DAY_HPP

#include <string>
#include <ostream>
#include <iomanip>

class Day {
public:
    explicit Day(std::string input, int number) : mInput(std::move(input)), mDayNumber{number} {}
    virtual ~Day() = default;

    [[nodiscard]]
    virtual std::string Part1() const = 0;

    [[nodiscard]]
    virtual std::string Part2() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Day &day) {
      auto part1 = day.Part1();
      auto part2 = day.Part2();
      auto maxLength = std::max(part1.length(), part2.length()) + 8; // 8 is for the "Part #; " text

      os << "Day " << day.mDayNumber << std::endl;
      os << std::setfill('-') << std::setw(maxLength) << '-' << std::endl;
      os << "Part 1: " << day.Part1() << std::endl;
      os << "Part 2: " << day.Part2() << std::endl;

      return os;
    }

protected:
    std::string mInput;

private:
    int mDayNumber;
};

#endif //AOC_CPP_2021_DAY_HPP
