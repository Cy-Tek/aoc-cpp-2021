//
// Created by hanna on 11/18/2022.
//

#ifndef AOC_CPP_2021_PARSER_HPP
#define AOC_CPP_2021_PARSER_HPP

#include <string>
#include <sstream>
#include <vector>
#include <functional>

template <typename T>
concept FromStr = std::constructible_from<std::string>;

template <FromStr T>
auto ParseLines(const std::string& str) {
  auto stream = std::stringstream{str};
  auto result = std::vector<T>{};
  auto line = std::string{};

  while (std::getline(stream, line, '\n')) {
    result.push_back({line});
  }

  return result;
}

template <typename O>
auto ParseLinesMap(const std::string& input, std::function<O(const std::string&)> mapFn) {
  auto stream = std::stringstream{input};
  auto result = std::vector<O>{};
  auto line = std::string{};

  while (std::getline(stream, line, '\n')) {
    result.push_back(mapFn(line));
  }

  return result;
}

#endif // AOC_CPP_2021_PARSER_HPP
