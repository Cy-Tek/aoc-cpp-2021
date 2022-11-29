//
// Created by hanna on 11/28/2022.
//

#include <gtest/gtest.h>

#include "../Parser.hpp"

TEST(SplitsStrings, HandlesNoMatches) {
  std::string test{"Hello world"};
  auto delimiter = ",";

  auto result = SplitString(test, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{});
}