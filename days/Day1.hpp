//
// Created by hanna on 11/18/2022.
//

#ifndef AOC_CPP_2021_DAY1_HPP
#define AOC_CPP_2021_DAY1_HPP

#include <climits>
#include <vector>
#include "Day.hpp"
#include "../Parser.hpp"

class Day1 : public Day {
public:
    explicit Day1(std::string input) : Day(std::move(input)) {
      mItems = ParseLinesMap<int>(mInput, [](auto s) { return std::stoi(s); });
    }

    std::string Part1() override {
      auto prev = mItems.at(0);
      auto count = 0;
      for (auto i = 1; i < mItems.size(); i++) {
        if (mItems[i] > prev) count++;
        prev = mItems[i];
      }

      return std::to_string(count);
    }

    std::string Part2() override {
      auto prev = INT_MAX;
      auto count = 0;

      for (auto i{0}; i < mItems.size() - 2; i++) {
        auto sum = mItems[i] + mItems[i + 1] + mItems[i + 2];
        if (sum > prev) count++;
        prev = sum;
      }

      return std::to_string(count);
    }

private:
    std::vector<int> mItems;
};

#endif //AOC_CPP_2021_DAY1_HPP
