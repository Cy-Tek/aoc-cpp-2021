//
// Created by hanna on 11/19/2022.
//

#include <algorithm>
#include <iostream>
#include "Day3.hpp"
#include "../Parser.hpp"

Day3::Day3(std::string input) : Day(std::move(input), 3) {
  mNums = ParseLines<std::string>(mInput);
}

std::string Day3::Part1() const {
  auto currentBit = 0;
  auto endIdx = mNums.size();
  std::string gamma, epsilon;

  while (currentBit < mNums.at(0).size()) {
    auto ones = 0, zeros = 0;
    for (int i = 0; i < endIdx; i++) {
      if (mNums.at(i).at(currentBit) == '0') { zeros++; } else { ones++; }
    }

    if (ones > zeros) {
      gamma += '1';
      epsilon += '0';
    } else {
      gamma += '0';
      epsilon += '1';
    }

    currentBit++;
  }

  auto gRate = std::stoi(gamma, nullptr, 2), eRate = std::stoi(epsilon, nullptr, 2);
  return std::to_string(gRate * eRate);
}

std::string Day3::Part2() const {
  auto oxygen = FilterVec(mNums, Generator::Oxygen);
  auto co2 = FilterVec(mNums, Generator::CO2);
  return std::to_string(oxygen * co2);
}

int Day3::FilterVec(const std::vector<std::string> &list, Generator type) {
  auto currentBit = 0;
  auto result{list};

  while (currentBit < result.at(0).size() && result.size() > 1) {
    auto ones{0}, zeros{0};
    for (int i{0}; i < result.size(); i++) {
      if (result.at(i).at(currentBit) == '0') { zeros++; } else { ones++; }
    }

    char testBit = GetTestBit(type, ones, zeros);
    result.erase(std::remove_if(result.begin(), result.end(), [&](auto s) {
        return s[currentBit] == testBit;
    }), result.end());

    currentBit++;
  }

  return std::stoi(result[0], nullptr, 2);
}

constexpr char Day3::GetTestBit(Day3::Generator type, int ones, int zeros) {
  switch (type) {
    case Oxygen:
      return ones >= zeros ? '0' : '1';
    case CO2:
      return zeros <= ones ? '1' : '0';
  }
}
