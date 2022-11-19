//
// Created by hanna on 11/18/2022.
//

#include <gtest/gtest.h>

#include "../days/Day1.hpp"

TEST(Day1, Part1) {
  const std::string input = "199\n"
                            "200\n"
                            "208\n"
                            "210\n"
                            "200\n"
                            "207\n"
                            "240\n"
                            "269\n"
                            "260\n"
                            "263";

  Day1 day{input};
  ASSERT_EQ(day.Part1(), "7");
}

TEST(Day1, Part2) {
  const std::string input = "199\n"
                            "200\n"
                            "208\n"
                            "210\n"
                            "200\n"
                            "207\n"
                            "240\n"
                            "269\n"
                            "260\n"
                            "263";

  Day1 day{input};
  ASSERT_EQ(day.Part2(), "5");
}