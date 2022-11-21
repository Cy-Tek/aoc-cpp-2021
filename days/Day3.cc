//
// Created by hanna on 11/19/2022.
//

#include <algorithm>
#include <iostream>
#include "Day3.hpp"
#include "../Parser.hpp"

Day3::Day3(std::string input) : Day(std::move(input), 3) {
  mNums = ParseLines<std::string>(mInput);
  std::sort(mNums.begin(), mNums.end());
}

std::string Day3::Part1() const {
  auto currentBit = 0;
  auto endIdx = mNums.size();
  auto ones = 0, zeros = 0;
  std::string gamma, epsilon;

  while (currentBit < mNums.at(0).size()) {
    for (int i = 0; i < endIdx; i++) {
      auto bit = mNums.at(i).at(currentBit);
      if (bit == '0') zeros++;
      else ones++;
    }

    if (ones > zeros) {
      gamma += '1';
      epsilon += '0';
    } else {
      gamma += '0';
      epsilon += '1';
    }

    zeros = 0;
    ones = 0;
    currentBit++;
  }

  auto gRate = std::stoi(gamma, nullptr, 2), eRate = std::stoi(epsilon, nullptr, 2);
  return std::to_string(gRate * eRate);
}

std::string Day3::Part2() const {
  auto currentBit = 0;
  auto startIdx = 0;
  auto endIdx = mNums.size();
  auto breakIdx = 0;
  auto ones = 0, zeros = 0;
  std::string oxygen, co2;

  while (currentBit < mNums.at(0).size() && startIdx != endIdx) {
    for (int i = startIdx; i < endIdx; i++) {
      auto bit = mNums.at(i).at(currentBit);
      if (bit == '0') {
        zeros++;
      } else {
        if (breakIdx == startIdx) {
          breakIdx = i;
        }
        ones++;
      }
    }

    if (ones >= zeros) {
      oxygen += '1';
      co2 += '0';
      startIdx = breakIdx;
    } else {
      oxygen += '0';
      co2 += '1';
      endIdx = breakIdx;
      breakIdx = startIdx;
    }

    std::sort(mNums.begin() + startIdx, mNums.begin() + endIdx);

    zeros = 0;
    ones = 0;
    currentBit++;
  }

  auto gRate = std::stoi(oxygen, nullptr, 2), eRate = std::stoi(co2, nullptr, 2);
  return std::to_string(gRate * eRate);
}
