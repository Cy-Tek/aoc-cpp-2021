//
// Created by hanna on 11/18/2022.
//

#ifndef AOC_CPP_2021_PARSER_HPP
#define AOC_CPP_2021_PARSER_HPP

#include <string>
#include <sstream>
#include <vector>
#include <functional>

std::vector<std::string> SplitString(const std::string &str, std::string delimiter);

template <typename T>
concept FromStr = std::constructible_from<std::string>;

template <FromStr T>
auto ParseLines(const std::string& str) {
  auto stream = std::stringstream{str};
  auto result = std::vector<T>{};
  auto line = std::string{};

  while (std::getline(stream, line, '\n')) {
    result.push_back(T{line});
  }

  return result;
}

template <FromStr T, size_t N>
auto ParseLines(const std::string& str) {
  auto stream = std::stringstream{str};
  auto objectStream = std::stringstream{};
  auto result = std::vector<T>{};
  auto line = std::string{};

  while (!stream.eof()) {
    for (auto i = 0; i < N; i++) {
      if (std::getline(stream, line, '\n')) {
        objectStream << line;

        if (i == N - 1) {
          result.push_back(T{objectStream});
          objectStream.clear();
        }
      } else {
        break;
      }
    }
  }

  return result;
}

template <typename O>
auto ParseLines(const std::string& input, std::function<O(const std::string&)> mapFn) {
  auto stream = std::stringstream{input};
  auto result = std::vector<O>{};
  auto line = std::string{};

  while (std::getline(stream, line, '\n')) {
    result.push_back(mapFn(line));
  }

  return result;
}

#endif // AOC_CPP_2021_PARSER_HPP
