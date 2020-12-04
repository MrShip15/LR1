// Copyright 2020 MrShip15 mr.shi15@gmail.ru
#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <any>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using nlohmann::json;

class Student {
 public:
  explicit Student(const json& js);
  const std::string& get_name() const;
  const std::any& get_group() const;
  const std::any& get_avg() const;
  const std::any& get_debt() const;
  void print_name(std::ostream& out) const;
  void print_group(std::ostream& out) const;
  void print_avg(std::ostream& out) const;
  void print_debt(std::ostream& out) const;

 private:
  std::string Name;
  std::any Group;
  std::any Avg;
  std::any Debt;
};

#endif  // INCLUDE_STUDENT_HPP_
