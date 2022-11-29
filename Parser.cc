//
// Created by hanna on 11/29/2022.
//

#include "Parser.hpp"

std::vector<std::string> SplitString(const std::string &str, std::string delimiter) {
  size_t pos{0};
  size_t marker{0};
  auto result = std::vector<std::string>{};

  while ((marker = str.find(delimiter, pos)) != std::string::npos) {
    result.push_back(str.substr(pos, marker));
    pos += marker;
  }

  return result;
}
