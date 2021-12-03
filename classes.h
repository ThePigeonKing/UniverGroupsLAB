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
        InfoSecurity

    };

    enum GroupID {
        Cringe,
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

        virtual GroupID getUnique() { return Cringe; }

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

    class DayShift : public Group {
    private:
        Spec specialization_;
        size_t grant_;
        size_t grantedStudents_;

    public:
        GroupID getUnique() override { return Day; }

        DayShift() : Group(){
          specialization_ = Default;
          grant_ = 0;
          grantedStudents_ = 0;
        }
        DayShift(std::string Line, int caf, int students, int period, Spec special, int gran, int GrStuds)
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
        bool isForeign_;                   // типо контингент
        Qualification qual_;

    public:
        GroupID getUnique() override { return Night; }

        NightShift() : Group() {
          isForeign_ = false;
          qual_ = Def;
        }

        NightShift(std::string Line, int caf, int students, int period, bool isFor, Qualification q) :
        Group(std::move(Line), students, caf, period) {
          isForeign_ = isFor;
          qual_ = q;
        }

        [[nodiscard]] bool getIsForeign() const { return isForeign_; }
        Qualification getQualification() { return qual_; }
        void setIsForeign( bool stat ) { isForeign_ = stat; }
        void setQualification (Qualification q) { qual_ = q; }

        // overloads
        friend std::ostream& operator<<(std::ostream& os, const NightShift& group);
    };

    class PaidGroup : public Group{
    private:
        std::size_t contract_;
        std::size_t payment_;

    public:
        GroupID getUnique() override { return Paid; }

        PaidGroup() : Group() {
          contract_ = 0;
          payment_ = 0;
        }

        PaidGroup(std::string Line, int caf, int students, int period, int contr, int payment) :
        Group(std::move(Line), students, caf, period) {
          // инициалирую только чтобы не ругалась IDE
          contract_ = 0;
          payment_ = 0;
          setContract(contr);
          setPayment(payment);
        }

        [[nodiscard]] std::size_t getContract() const { return contract_; }
        [[nodiscard]] std::size_t getPayment() const { return payment_; }
        void setContract(int number);
        void setPayment(int num) {
          if (num < 0){
            payment_ = 0;
            throw std::out_of_range("[!Err] University can't pay students!");
          }
          payment_ = num;
        }


        // overloads
        friend std::ostream& operator<<(std::ostream& os, const PaidGroup& group);
    };

    // таблица из темплейтового вектора
    class Table {
    private:
      int tSize;
      Vector::MyVec<Group*> table;

    public:
        Table() : tSize(0) {}

        ~Table() = default;

        [[nodiscard]] int getSize() const { return tSize; }
        void setSize(int val) {
          if (val < 0){
            tSize = 0;
            throw std::out_of_range("[!Err] Can't set negative size, reset to zero!");
          }
          tSize = val;
        }

        void add_group(Group *gr){
          table.push_back(gr);
          tSize++;
        }
        void delete_room(Group *gr){
          table.delete_elem(gr);
          tSize--;
        }

        // nullptr = not found
        Group *find_group(std::string someID){
          for (int i = 0; i < tSize; i++){
            if (table[i]->getID() == someID){
              return table[i];
            }
          }
          return nullptr;
        }

        friend std::ostream &operator<<(std::ostream &os, Table &tabl){
          os << "Number of all groups --> " << tabl.tSize << "\n------\n";
          GroupID comparator = Day;
          for (int iter = 0; iter < 3; iter++){
            if (iter == 1){
              comparator = Night;
              os << "\n-------------NightShifts-------------\n";
            } else if (iter == 2) {
              comparator = Paid;
              os << "\n-------------PaidGroups-------------\n";
            } else if (iter == 0) {
              comparator = Day;
              os << "\n-------------DayShifts-------------\n";
            }
            for (auto i : tabl.table) {
              if (i->getUnique() == comparator){
                os << i;
              }
            }
          }


          return os;
        }
      // TO BE ADDED
    };

}


#endif //UNIVERGROUPSLAB_CLASSES_H
