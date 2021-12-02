#ifndef UNIVERGROUPSLAB_CLASSES_H
#define UNIVERGROUPSLAB_CLASSES_H

#include <iostream>
#include <utility>
#include <vector>

#include "vector.h"

namespace tpk4 {

    enum Spec {
        Default,
        Engineer,
        Scientist,
        Programmer,

    };

    enum GroupID {
        Day,
        Night,
        Paid
    };

    enum Qualification {
        Def,
        B,
        M,
        A
    };

    class Group {
    protected:
        std::string ID_;
        std::size_t numberOfStudents_;
        std::size_t cafNumber_;
        std::size_t periodOfStudy_;

    public:
        Group() {
          ID_ = "";
          numberOfStudents_ = 0;
          cafNumber_ = 0;
          periodOfStudy_ = 0;
        }
        Group(std::string Line, int students, int caf, int period) {
          ID_ = std::move(Line);
          if (students >= 0){
            numberOfStudents_ = students;
          } else {
            students = 0;
          }
          if (caf >= 0){
            cafNumber_ = caf;
          } else {
            cafNumber_ = 0;
          }
          if (period >= 0) {
            periodOfStudy_ = period;
          } else {
            periodOfStudy_ = 0;
          }
        }

        [[nodiscard]] std::size_t getStudentsNum() const { return numberOfStudents_; }
        [[nodiscard]] std::size_t getCafNum() const { return cafNumber_; }
        [[nodiscard]] std::size_t getPeriod() const { return periodOfStudy_; }
        [[nodiscard]] std::string getID() const { return ID_; }
        void setStudentsNum(size_t number);
        void setCafNum(size_t number);
        void setTimePeriod(size_t number);
        void setID(const std::string& ID_name);

        // overloads

    };

    class DayShift : public Group{
    private:
        Spec specialization_;
        size_t grant_;
        size_t grantedStudents_;

    public:
        const GroupID identificator = Day;

        DayShift() : Group(){
          specialization_ = Default;
          grant_ = 0;
          grantedStudents_ = 0;
        }
        DayShift(std::string Line, int students, int caf, int period, Spec special, int gran, int GrStuds)
                : Group(std::move(Line), students, caf, period) {
          specialization_ = special;
          if (gran >= 0){
            grant_ = gran;
          } else {
            grant_ = 0;
          }
          if (GrStuds >= 0){
            grantedStudents_ = GrStuds;
          } else {
            grantedStudents_ = 0;
          }
        }


        Spec getSpec() { return specialization_; }
        [[nodiscard]] std::size_t getGrant() const { return grant_; }
        [[nodiscard]] std::size_t getAmountOfGranted() const { return grantedStudents_; }
        void setSpec(Spec new_one);
        void setGrant(std::size_t number);
        void setGrantedStudents(std::size_t number);

        // overloads
        friend std::ostream& operator<<(std::ostream& os, const DayShift& group);
    };

    class NightShift : public Group{
    private:
        bool isForeign;                   // типо контингент
        Qualification qual;

    public:
        const GroupID identificator = Night;

        NightShift() : Group() {
          isForeign = false;
          qual = Def;
        }

        [[nodiscard]] bool getIsForeign() const { return isForeign; }
        Qualification getQualification() { return qual; }
        void setIsForeign( bool stat ) { isForeign = stat; }
        void setQualification (Qualification q) { qual = q; }

    };

    class PaidGroup : public Group{
    private:
        std::size_t contract_;
        std::size_t payment_;

    public:
        const GroupID identificator = Paid;

        PaidGroup() : Group() {
          contract_ = 0;
          payment_ = 0;
        }

        [[nodiscard]] std::size_t getContract() const { return contract_; }
        [[nodiscard]] std::size_t getPayment() const { return payment_; }
        void setContract(int number);
    };

    // таблица из темплейтового вектора
    class Table {
    private:
      MyVec<Group*> table;

    public:
      // TO BE ADDED
    };

}


#endif //UNIVERGROUPSLAB_CLASSES_H
