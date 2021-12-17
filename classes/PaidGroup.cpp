#include "PaidGroup.h"

#include "math.h"

using namespace tpk4;

// 8-digit number, else will be filled with zeros
void PaidGroup::setContract(int number) {
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

void PaidGroup::writeToOstream(std::ostream &os) const {
  os << "PaidShift { ID: \"" << ID_ << "\"\nCaf: " << cafNumber_ << " | Number of students: " <<
     numberOfStudents_ << "\nNumber of years to study: " << periodOfStudy_
     << "\nContract: " << contract_ << "\nPayment: " << payment_
     << "K }\n";
}
