#include <iostream>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include "days/Day.hpp"
#include "days/Day1.hpp"
#include "days/Day2.hpp"
#include "days/Day3.hpp"

auto LoadInputsFromDirectory(const std::string &dir) {
  using std::filesystem::recursive_directory_iterator;
  auto map = std::unordered_map<std::string, std::string>{};
  for (const auto &file: recursive_directory_iterator(dir)) {
    auto filePath = file.path().string();
    auto fileName = file.path().filename().stem().string();
    auto fileStream = std::ifstream{filePath};
    auto fileContents = std::string{
        std::istreambuf_iterator<char>{fileStream},
        std::istreambuf_iterator<char>{}
    };

    map.insert({fileName, fileContents});
  }

  return map;
}

auto CreateDays() {
  auto inputs = LoadInputsFromDirectory("./inputs");
  auto days = std::vector<std::shared_ptr<Day>>{
      {std::make_shared<Day1>(inputs["day1"])},
      {std::make_shared<Day2>(inputs["day2"])},
      {std::make_shared<Day3>(inputs["day3"])},
  };

  return days;
}

int main() {
  auto days = CreateDays();
  for (int i = 1; auto &day: days) {
    std::cout << *day;

    if (i++ < days.size()) {
      std::cout << std::endl;
    }
  }

  return 0;
}
