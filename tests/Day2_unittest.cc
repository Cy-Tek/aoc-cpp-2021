//
// Created by hanna on 11/19/2022.
//

#include <gtest/gtest.h>
#include "../days/Day2.hpp"

TEST(Day2, Part1) {
  const std::string input = "forward 5\n"
                            "down 5\n"
                            "forward 8\n"
                            "up 3\n"
                            "down 8\n"
                            "forward 2";

  Day2 day{input};
  ASSERT_EQ(day.Part1(), "150");
}

TEST(Day2, Part2) {
  const std::string input = "forward 5\n"
                            "down 5\n"
                            "forward 8\n"
                            "up 3\n"
                            "down 8\n"
                            "forward 2";

  Day2 day{input};
  ASSERT_EQ(day.Part2(), "900");
}