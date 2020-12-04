// Copyright 2020 MrShip15 mr.shi15@gmail.ru
#ifndef INCLUDE_PARSER_HPP_
#define INCLUDE_PARSER_HPP_

#include <string>
#include <vector>

#include "student.hpp"
using nlohmann::json;

class Parser {
 public:
  explicit Parser(const std::string& jsonPath);
  void print_columns(std::ostream& out) const;
  void print_lines(std::ostream& out) const;
  friend std::ostream& operator<<(std::ostream& out, const Parser& pars);

 private:
  std::vector<Student> students;
  std::vector<size_t> column_width{0, 9, 7, 15};
};

#endif  // INCLUDE_PARSER_HPP_
