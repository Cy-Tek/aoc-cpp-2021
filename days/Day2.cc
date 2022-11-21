//
// Created by hanna on 11/19/2022.
//

#include <sstream>
#include <stdexcept>
#include <iostream>
#include "Day2.hpp"
#include "../Parser.hpp"

Day2::Day2(std::string input): Day(std::move(input), 2) {
  mInstructions = ParseLines<Instruction>(mInput);
}

std::string Day2::Part1() const {
  auto distance = 0, depth = 0;

  for (const auto &instruction: mInstructions) {
    switch (instruction.direction) {
      case Forward:
        distance += instruction.distance;
        break;
      case Up:
        depth -= instruction.distance;
        break;
      case Down:
        depth += instruction.distance;
        break;
    }
  }

  return std::to_string(distance * depth);
}

std::string Day2::Part2() const {
  auto distance = 0, depth = 0, aim = 0;

  for (const auto &instruction: mInstructions) {
    switch (instruction.direction) {
      case Forward:
        distance += instruction.distance;
        depth += aim * instruction.distance;
        break;
      case Up:
        aim -= instruction.distance;
        break;
      case Down:
        aim += instruction.distance;
        break;
    }
  }

  return std::to_string(distance * depth);
}

Day2::Direction Day2::WordToDirection(const std::string &word) {
  if (word == "forward") return Day2::Forward;
  else if (word == "up") return Day2::Up;
  else if (word == "down") return Day2::Down;

  throw std::invalid_argument("Word must be either 'forward', 'down' or 'up'");
}


Day2::Instruction::Instruction(const std::string &str) {
  auto stream = std::istringstream{str};
  std::string dir, dist;
  
  stream >> dir;
  stream >> dist;
  
  try {
    this->direction = WordToDirection(dir);
    this->distance = std::stoi(dist);
  } catch (std::invalid_argument &exception) {
    std::cerr << "Failed to create Instruction from: " << str << std::endl;
    std::cerr << exception.what() << std::endl;
  }
}
