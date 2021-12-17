#include "Group.h"
#include "NightShift.h"
#include "DayShift.h"
#include "PaidGroup.h"


void Group::setStudentsNum(size_t number) {
  if (number <= 0){
    number = 0;
    throw std::out_of_range("Can't set negative number of students!");
  }
  numberOfStudents_ = number;
}

void Group::setCafNum(size_t number) {
  if (number <= 0){
    cafNumber_ = 0;
    throw std::out_of_range("Can't set negative number of cathedra!");
  }
  cafNumber_ = number;
}

void Group::setTimePeriod(size_t number) {
  if (number < 0){
    periodOfStudy_ = 0;
    throw std::out_of_range("Can't set negative number of cathedra!");
  }
  periodOfStudy_ = number;
}

void Group::setID(const std::string& ID_name) {
  if (ID_name.length() < 1){
    ID_ = "";
    throw std::invalid_argument("Can't set empty ID!");
  } else {
    ID_ = ID_name;
  }
}