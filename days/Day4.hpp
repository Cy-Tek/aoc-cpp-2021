//
// Created by hanna on 11/27/2022.
//

#ifndef AOC_CPP_2021_DAY4_HPP
#define AOC_CPP_2021_DAY4_HPP


#include <vector>
#include <unordered_map>
#include <optional>
#include "Day.hpp"

using std::string;
using std::vector;
using std::unordered_map;

class Day4: public Day {
public:
    explicit Day4(string input);

    [[nodiscard]]
    string Part1() const override;

    [[nodiscard]]
    string Part2() const override;

private:
    class Board {
    public:
      explicit Board(const string &input);

      void Call(int number);

      [[nodiscard]]
      std::optional<size_t> CheckWinner() const;

    private:
        size_t mScore;
        unordered_map<int, bool> mCalled;
    };

    vector<int> mCalls;
    vector<Board> mBoards;
};


#endif //AOC_CPP_2021_DAY4_HPP
