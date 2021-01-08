// Copyright 2020 MrShip15 mr.shi15@gmail.ru
#include "student.hpp"

using nlohmann::json;

const int shift_two = 2;
const int shift_three = 2;

Student::Student(const json& js) {
  if (js.empty()) {
    throw std::invalid_argument("json empty!");
  }
  if (js.at("name").is_string()) {
    Name = js.at("name").get<std::string>();
  } else {
    throw std::invalid_argument("name is not correct");
  }
  if (js.at("group").is_string()) {
    Group = js.at("group").get<std::string>();
  } else if (js.at("group").is_number_unsigned()) {
    Group = js.at("group").get<size_t>();
  } else {
    throw std::invalid_argument("group is not correct");
  }
  if (js.at("avg").is_null()) {
    Avg = nullptr;
  } else if (js.at("avg").is_string()) {
    Avg = js.at("avg").get<std::string>();
  } else if (js.at("avg").is_number_float()) {
    Avg = js.at("avg").get<double>();
  } else if (js.at("avg").is_number_unsigned()) {
    Avg = js.at("avg").get<size_t>();
  } else {
    throw std::invalid_argument("avg is not correct");
  }
  if (js.at("debt").is_null()) {
    Debt = nullptr;
  } else if (js.at("debt").is_string()) {
    Debt = js.at("debt").get<std::string>();
  } else if (js.at("debt").is_array()) {
    Debt = js.at("debt").get<std::vector<std::string>>();
  } else {
    throw std::invalid_argument("debt is not correct");
  }
}
const std::string& Student::get_name() const { return Name; }
const std::any& Student::get_group() const { return Group; }
const std::any& Student::get_avg() const { return Avg; }
const std::any& Student::get_debt() const { return Debt; }
void Student::print_name(std::ostream& out, size_t column_width) const {
    out << std::setfill(' ') << std::setw(column_width)
        << "| " + Name;
}
void Student::print_group(std::ostream& out, size_t column_width) const {
    if (Group.type() == typeid(std::string)) {
        out << std::setw(column_width)
            << "| " + std::any_cast<std::string>(Group);
    } else {
        out << "| " << std::setw(column_width - shift_two)
            << std::any_cast<size_t>(Group);
    }
}
void Student::print_avg(std::ostream& out, size_t column_width) const {
    if (Avg.type() == typeid(std::nullptr_t)) {
        out << "| " << std::setw(column_width - shift_two) << "null";
    } else if (Avg.type() == typeid(std::string)) {
        out << std::setw(column_width)
            << "| " + std::any_cast<std::string>(Avg);
    } else if (Avg.type() == typeid(std::size_t)) {
        out << "| " << std::setw(column_width - shift_two)
            << std::any_cast<size_t>(Avg);
    } else {
        out << "| " << std::setw(column_width - shift_two)
            << std::any_cast<double>(Avg);
    }
}
void Student::print_debt(std::ostream& out, size_t column_width) const {
    if (Debt.type() == typeid(std::nullptr_t)) {
        out << "| " << std::setw(column_width - shift_two) << "null";
    } else if (Debt.type() == typeid(std::string)) {
        out << std::setw(column_width)
            << "| " + std::any_cast<std::string>(Debt);
    } else {
        out << "| "
            << std::any_cast<std::vector<std::string>>(Debt)
                .size()
                                                    << std::setw(column_width - shift_two) << " items";
    }
}