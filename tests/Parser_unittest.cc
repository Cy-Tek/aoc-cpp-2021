//
// Created by hanna on 11/28/2022.
//

#include <gtest/gtest.h>

#include "../Parser.hpp"

using std::vector;
using std::string;

TEST(SplitString, HandlesNoMatches) {
  string test{"Hello world"};
  auto delimiter = ",";

  auto result = SplitString(test, delimiter);
  ASSERT_EQ(result, vector<string>{});
}

TEST(SplitString, HandlesOneCharDelimiter) {
  auto test = string{"Hello world"};
  auto result = SplitString(test, " ");
  auto expected = vector<string>{{"Hello"},
                                 {"world"}};

  ASSERT_EQ(result, expected);
}

TEST(SplitString, HandlesMultipleCharDelimiter) {
  auto test = string{"test\n\nfor\n\nmultiple\n\nnew\nlines"};
  auto result = SplitString(test, "\n\n");
  auto expected = vector<string>{{"test"},
                                 {"for"},
                                 {"multiple"},
                                 {"new\nlines"}};

  ASSERT_EQ(result, expected);
}