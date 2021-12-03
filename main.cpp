#include <iostream>

#include "funcs.h"
#include "classes.h"

using namespace tpk4;

int main() {

  PaidGroup shiftP("B20-505", 12, 31, 4, 128001, 120);
  DayShift shiftD("B20-505", 12, 31, 4, tpk4::Engineer, 3200, 3);
  //std::cout << shiftP << "\n" <<  shiftD << std::endl;

  Table t_main;
  // TODO t_main.add_group(shiftP);


  std::cout << "---End of program!---" << std::endl;
  return 0;
}
