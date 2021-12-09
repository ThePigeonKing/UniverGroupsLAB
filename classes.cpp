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
  } else {
    ID_ = ID_name;
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

void tpk4::DayShift::writeToOstream(std::ostream &os) const {
  os << "DayShift { " << "ID: \"" << ID_ << "\"\nCaf: " << cafNumber_ << "\t| Number of students: " <<
     numberOfStudents_ << "\nNumber of years to study: " << periodOfStudy_ << "\nSpec: " <<
     convert_spec(specialization_) << "\t| Grant: " << grant_ << "\nNumber of granted students: "
     << grantedStudents_ << " }\n";
}

void tpk4::NightShift::writeToOstream(std::ostream &os) const {
  os << "NightShift { ID: \"" << ID_ << "\"\nCaf: " << cafNumber_ << "\t| Number of students: " <<
     numberOfStudents_ << "\nNumber of years to study: " << periodOfStudy_
     << "\nForeign: ";
  if (isForeign_){
    os << "True ";
  } else {
    os << "False ";
  }
  os << "| Qualification: ";
  if (qual_ == B){
    os << "Bachelor degree ";
  } else if (qual_ == M){
    os << "Magistracy ";
  } else if (qual_ == A){
    os << "Postgraduate study ";
  } else {
    os << "N/A ";
  }
  os << " }\n";
}


void tpk4::PaidGroup::writeToOstream(std::ostream &os) const {
  os << "NightShift { ID: \"" << ID_ << "\"\nCaf: " << cafNumber_ << " | Number of students: " <<
     numberOfStudents_ << "\nNumber of years to study: " << periodOfStudy_
     << "\nContract: " << contract_ << "\nPayment: " << payment_
     << "K }\n";
}


