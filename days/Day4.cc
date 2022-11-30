//
// Created by hanna on 11/27/2022.
//

#include <ranges>
#include "Day4.hpp"
#include "../Parser.hpp"


Day4::Day4(string input) : Day(std::move(input), 4) {
  auto outputs = SplitString(mInput, "\n\n");
  auto callListStr = vector<string>{SplitString(outputs[0], ",")};

  std::transform(callListStr.begin(), callListStr.end(), std::back_inserter(mCalls), [](const string &s) {
      return std::stoi(s);
  });

  outputs.erase(outputs.begin());
  std::transform(outputs.begin(), outputs.end(), std::back_inserter(mBoards), [](const string &s) { return Board{s}; })
}

string Day4::Part1() const {
  return {};
}

string Day4::Part2() const {
  return {};
}

Day4::Board::Board(const string &input) {

}

void Day4::Board::Call(int number) {

}

std::optional<size_t> Day4::Board::CheckWinner() const {
  return {};
}
