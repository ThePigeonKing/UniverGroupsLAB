#include <cmath>

#include "classes.h"

void tpk4::Group::setStudentsNum(size_t number) {
  if (number <= 0){
    number = 0;
    throw std::out_of_range("Can't set negative number of students!");
  }
  numberOfStudents_ = number;
}

void tpk4::Group::setCafNum(size_t number) {
  if (number <= 0){
    cafNumber_ = 0;
    throw std::out_of_range("Can't set negative number of cathedra!");
  }
  cafNumber_ = number;
}

void tpk4::Group::setTimePeriod(size_t number) {
  if (number < 0){
    periodOfStudy_ = 0;
    throw std::out_of_range("Can't set negative number of cathedra!");
  }
  periodOfStudy_ = number;
}

void tpk4::Group::setID(const std::string& ID_name) {
  if (ID_name.length() < 1){
    ID_ = "";
    throw std::invalid_argument("Can't set empty ID!");
  }
}

void tpk4::DayShift::setSpec(tpk4::Spec new_one) {
  if (specialization_ == new_one){
    throw std::invalid_argument("Value already set! Nothing changed");
  }
  specialization_ = new_one;
}

void tpk4::DayShift::setGrant(std::size_t number) {
  if (number < 0){
    throw std::invalid_argument("Can't set negative grant!");
  }
  grant_ = number;
}

void tpk4::DayShift::setGrantedStudents(std::size_t number) {
  if (number < 0){
    throw std::invalid_argument("Can't set negative grant!");
  }
  grantedStudents_ = number;
}


// 8-digit number, else will be filled with zeros
void tpk4::PaidGroup::setContract(int number) {
  if ((number <= 0) || (number >= 100000000)){
    contract_ = 0;
    throw std::out_of_range("Contract number out of bound!");
  }

  int divided = number, decades = 0;
  while (divided > 0){
    decades++;
    divided /= 10;
  }

  divided = number * pow(10, 8 - decades);

  contract_ = divided;
}

std::string convert_spec(tpk4::Spec spec){
  switch (spec) {
    case tpk4::Default: return "Default";
    case tpk4::Engineer: return "Engineer";
    case tpk4::Scientist: return "Scientist";
    case tpk4::Programmer: return "Programmer";
    case tpk4::InfoSecurity: return "InformationalSecurity";
    default:
      return "N/A";
  }
}

std::ostream &tpk4::operator<<(std::ostream &os, const tpk4::DayShift &group) {
  os << "DayShift { " << "ID: \"" << group.ID_ << "\"\nCaf: " << group.cafNumber_ << "\t| Number of students: " <<
     group.numberOfStudents_ << "\nNumber of years to study: " << group.periodOfStudy_ << "\nSpec: " <<
     convert_spec(group.specialization_) << "\t| Grant: " << group.grant_ << "\nNumber of granted students: "
     << group.grantedStudents_ << " }\n";
  return os;
}

std::ostream &tpk4::operator<<(std::ostream &os, const tpk4::NightShift &group) {
  os << "NightShift { ID: \"" << group.ID_ << "\"\nCaf: " << group.cafNumber_ << "\t| Number of students: " <<
  group.numberOfStudents_ << "\nNumber of years to study: " << group.periodOfStudy_
  << "\nForeign: ";
  if (group.isForeign_){
    os << "True ";
  } else {
    os << "False ";
  }
  os << "| Qualification: ";
  if (group.qual_ == B){
    os << "Bachelor degree ";
  } else if (group.qual_ == M){
    os << "Magistracy ";
  } else if (group.qual_ == A){
    os << "Postgraduate study ";
  } else {
    os << "N/A ";
  }
  os << " }\n";

  return os;
}

std::ostream &tpk4::operator<<(std::ostream &os, const PaidGroup &group) {
  os << "NightShift { ID: \"" << group.ID_ << "\"\nCaf: " << group.cafNumber_ << " | Number of students: " <<
     group.numberOfStudents_ << "\nNumber of years to study: " << group.periodOfStudy_
     << "\nContract: " << group.contract_ << "\nPayment: " << group.payment_
     << "K }\n";
  return os;
}


