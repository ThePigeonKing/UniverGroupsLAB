#include "DayShift.h"
#include "structs.h"

using namespace tpk4;

void DayShift::setSpec(tpk4::Spec new_one) {
  if (specialization_ == new_one){
    throw std::invalid_argument("Value already set! Nothing changed");
  }
  specialization_ = new_one;
}

void DayShift::setGrant(std::size_t number) {
  if (number < 0){
    throw std::invalid_argument("Can't set negative grant!");
  }
  grant_ = number;
}

void DayShift::setGrantedStudents(std::size_t number) {
  if (number < 0){
    throw std::invalid_argument("Can't set negative grant!");
  }
  grantedStudents_ = number;
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

void DayShift::writeToOstream(std::ostream &os) const {
  os << "DayShift { " << "ID: \"" << ID_ << "\"\nCaf: " << cafNumber_ << "\t| Number of students: " <<
     numberOfStudents_ << "\nNumber of years to study: " << periodOfStudy_ << "\nSpec: " <<
     convert_spec(specialization_) << "\t| Grant: " << grant_ << "\nNumber of granted students: "
     << grantedStudents_ << " }\n";
}


