//
// Created by hanna on 11/28/2022.
//

#include "Day1.hpp"

Day1::Day1(std::string input) : Day(std::move(input), 1) {
  mItems = ParseLines<int>(mInput, [](auto s) { return std::stoi(s); });
}

std::string Day1::Part1() const {
  auto prev = mItems.at(0);
  auto count = 0;
  for (auto i = 1; i < mItems.size(); i++) {
    if (mItems[i] > prev) count++;
    prev = mItems[i];
  }

  return std::to_string(count);
}

std::string Day1::Part2() const {
  auto prev = INT_MAX;
  auto count = 0;

  for (auto i{0}; i < mItems.size() - 2; i++) {
    auto sum = mItems[i] + mItems[i + 1] + mItems[i + 2];
    if (sum > prev) count++;
    prev = sum;
  }

  return std::to_string(count);
}
