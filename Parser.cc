//
// Created by hanna on 11/29/2022.
//

#include "Parser.hpp"

std::vector<std::string> SplitString(const std::string &str, std::string delimiter) {
  size_t pos{0};
  size_t marker{str.find(delimiter, 0)};
  if (marker == std::string::npos) {
    return {};
  }

  auto result = std::vector<std::string>{};
  while (marker != std::string::npos) {
    result.push_back(str.substr(pos, marker - pos));
    pos = marker + delimiter.size();
    marker = str.find(delimiter, pos);
  }

  // Handle fence post
  result.push_back(str.substr(pos, str.size() - pos));

  return result;
}
