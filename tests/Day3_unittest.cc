//
// Created by hanna on 11/19/2022.
//

#include <gtest/gtest.h>
#include "../days/Day3.hpp"

TEST(Day3, Part1) {
  const std::string input = "00100\n"
                            "11110\n"
                            "10110\n"
                            "10111\n"
                            "10101\n"
                            "01111\n"
                            "00111\n"
                            "11100\n"
                            "10000\n"
                            "11001\n"
                            "00010\n"
                            "01010";

  Day3 day{input};
  ASSERT_EQ(day.Part1(), "198");
}

TEST(Day3, Part2) {
  const std::string input = "00100\n"
                            "11110\n"
                            "10110\n"
                            "10111\n"
                            "10101\n"
                            "01111\n"
                            "00111\n"
                            "11100\n"
                            "10000\n"
                            "11001\n"
                            "00010\n"
                            "01010";

  Day3 day{input};
  ASSERT_EQ(day.Part2(), "230");
}