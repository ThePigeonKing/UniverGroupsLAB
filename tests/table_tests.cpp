#include "gtest/gtest.h"
#include "../classes/Table.h"
#include "../classes/DayShift.h"
#include "../classes/NightShift.h"
#include "../classes/PaidGroup.h"
#include "../classes/Group.h"
#include "../classes/vector.h"


TEST(Table_class, basic_init){
  Table sample;

  ASSERT_EQ(sample.getSize(), 0);
}

TEST(Table_class, setters){
  Table sample;
  sample.setSize(5);

  ASSERT_EQ(sample.getSize(), 5);
}

TEST(Table_class, add_group){
  Table sample;
  auto *shiftP = new PaidGroup("B20-505", 12, 31, 4, 128001, 120);
  sample.add_group(shiftP);
  auto found = sample.find_group("B20-505");

  ASSERT_EQ(found->getID(), "B20-505");
  ASSERT_EQ(found->getStudentsNum(), 31);
  ASSERT_EQ(found->getUnique(), tpk4::Paid);
}

TEST(Table_class, addOfDifferentGroups){
  Table sample;
  auto *shiftP = new PaidGroup("B20-505", 21, 13, 44, 128001, 120);
  auto *shiftD = new DayShift("B20-515", 12, 31, 4, tpk4::Engineer,
                                    3200, 3);
  sample.add_group(shiftP);
  sample.add_group(shiftD);

  auto found1 = sample.find_group("B20-515");
  auto found2 = sample.find_group("B20-505");

  ASSERT_EQ(found1->getStudentsNum(), 31);
  ASSERT_EQ(found2->getStudentsNum(), 13);

  ASSERT_EQ(found1->getPeriod(), 4);
  ASSERT_EQ(found2->getPeriod(), 44);

  auto day = dynamic_cast<DayShift*>(found1);

  ASSERT_EQ(day->getGrant(), 3200);
}

TEST(Table_class, delete_element){
  Table sample;
  auto *shiftP = new PaidGroup("B20-505", 21, 13, 44, 128001, 120);
  auto *shiftD = new DayShift("B20-515", 12, 31, 4, tpk4::Engineer,
                                    3200, 3);

  sample.add_group(shiftP);
  sample.add_group(shiftD);

  sample.delete_group(shiftD);

  auto found1 = sample.find_group("B20-515");

  ASSERT_EQ(found1, nullptr);
}

