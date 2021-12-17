#include "NightShift.h"

using namespace tpk4;

void NightShift::writeToOstream(std::ostream &os) const {
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
