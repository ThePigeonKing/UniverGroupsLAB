#include "gtest/gtest.h"
#include "../classes/Table.h"

TEST(Base_class, basic_init){
  Group test;

  ASSERT_EQ(test.getUnique(), tpk4::Cringe);
  ASSERT_EQ(test.getCafNum(), 0);
  ASSERT_EQ(test.getPeriod(), 0);
  ASSERT_EQ(test.getID(), "");
  ASSERT_EQ(test.getStudentsNum(), 0);
}

TEST(Base_class, param_init){
  Group test("B20-505", 31, 12, 4);
  ASSERT_EQ(test.getUnique(), tpk4::Cringe);
  ASSERT_EQ(test.getCafNum(), 12);
  ASSERT_EQ(test.getPeriod(), 4);
  ASSERT_EQ(test.getID(), "B20-505");
  ASSERT_EQ(test.getStudentsNum(), 31);
}

TEST(Base_class, setters){
  Group test;

  test.setID("LINE");
  test.setCafNum(12);
  test.setStudentsNum(44);
  test.setTimePeriod(8);

  ASSERT_EQ(test.getUnique(), tpk4::Cringe);
  ASSERT_EQ(test.getCafNum(), 12);
  ASSERT_EQ(test.getPeriod(), 8);
  ASSERT_EQ(test.getID(), "LINE");
  ASSERT_EQ(test.getStudentsNum(), 44);
}

TEST(Dayshift_test, basic_init){
  DayShift test;


  ASSERT_EQ(test.getUnique(), tpk4::Day);
  ASSERT_EQ(test.getCafNum(), 0);
  ASSERT_EQ(test.getPeriod(), 0);
  ASSERT_EQ(test.getID(), "");
  ASSERT_EQ(test.getStudentsNum(), 0);
  ASSERT_EQ(test.getGrant(), 0);
  ASSERT_EQ(test.getAmountOfGranted(), 0);
}

TEST(Dayshift_test, param_init){
  DayShift test("B20-505", 12, 31, 4, tpk4::Engineer, 3200, 3);


  ASSERT_EQ(test.getUnique(), tpk4::Day);
  ASSERT_EQ(test.getCafNum(), 12);
  ASSERT_EQ(test.getPeriod(), 4);
  ASSERT_EQ(test.getID(), "B20-505");
  ASSERT_EQ(test.getStudentsNum(), 31);
  ASSERT_EQ(test.getGrant(), 3200);
  ASSERT_EQ(test.getAmountOfGranted(), 3);
  ASSERT_EQ(test.getSpec(), tpk4::Engineer);
}

TEST(NightShift_test, basic_init){
  NightShift test;


  ASSERT_EQ(test.getUnique(), tpk4::Night);
  ASSERT_EQ(test.getCafNum(), 0);
  ASSERT_EQ(test.getPeriod(), 0);
  ASSERT_EQ(test.getID(), "");
  ASSERT_EQ(test.getStudentsNum(), 0);
  ASSERT_EQ(test.getIsForeign(), 0);
  ASSERT_EQ(test.getQualification(), tpk4::Def);
}

TEST(NightShift_test, param_init){
  NightShift test("B20-505", 12, 31, 4, true, tpk4::B);


  ASSERT_EQ(test.getUnique(), tpk4::Night);
  ASSERT_EQ(test.getCafNum(), 12);
  ASSERT_EQ(test.getPeriod(), 4);
  ASSERT_EQ(test.getID(), "B20-505");
  ASSERT_EQ(test.getStudentsNum(), 31);
  ASSERT_EQ(test.getIsForeign(), true);
  ASSERT_EQ(test.getQualification(), tpk4::B);
}

TEST(PaidGroup_test, basic_init){
  PaidGroup test;


  ASSERT_EQ(test.getUnique(), tpk4::Paid);
  ASSERT_EQ(test.getCafNum(), 0);
  ASSERT_EQ(test.getPeriod(), 0);
  ASSERT_EQ(test.getID(), "");
  ASSERT_EQ(test.getStudentsNum(), 0);
  ASSERT_EQ(test.getContract(), 0);
  ASSERT_EQ(test.getPayment(), 0);
}

TEST(PaidGroup_test, param_init){
  PaidGroup test("B20-505", 12, 31, 4, 128001, 120);


  ASSERT_EQ(test.getUnique(), tpk4::Paid);
  ASSERT_EQ(test.getCafNum(), 12);
  ASSERT_EQ(test.getPeriod(), 4);
  ASSERT_EQ(test.getID(), "B20-505");
  ASSERT_EQ(test.getStudentsNum(), 31);
  ASSERT_EQ(test.getContract(), 12800100);
  ASSERT_EQ(test.getPayment(), 120);
}
