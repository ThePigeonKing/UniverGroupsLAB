#include <iostream>

#include "funcs.h"
#include "classes/Table.h"

using namespace tpk4;

int main() {

  auto *shiftP = new PaidGroup("B20-505", 12, 31, 4, 128001, 120);
  PaidGroup pd("B20-505", 12, 31, 4, 128001, 120);
  auto *shiftD = new DayShift("B20-515", 12, 31, 4, tpk4::Engineer, 3200, 3);
  //std::cout << shiftP << "\n" <<  shiftD << std::endl;

  Table t_main;
  t_main.add_group(shiftP);
  t_main.add_group(shiftD);

  auto found1 = t_main.find_group("B20-505");

  std::cout << t_main << std::endl;

  t_main.delete_group(found1);

  std::cout << t_main << std::endl;

  std::cout << "---End of program!---" << std::endl;
  return 0;
}
