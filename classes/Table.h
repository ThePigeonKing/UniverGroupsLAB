#ifndef UNIVERGROUPSLAB_TABLE_H
#define UNIVERGROUPSLAB_TABLE_H

#include <iostream>
#include <utility>
#include <vector>

#include "vector.h"
#include "structs.h"
#include "Group.h"
#include "NightShift.h"
#include "DayShift.h"
#include "PaidGroup.h"

using namespace tpk4;


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
        void delete_group(Group *gr){
          table.delete_elem(gr);
          tSize--;
        }

        // nullptr = not found
        Group *find_group(const std::string& someID){
          for (int i = 0; i < tSize; i++){
            if (table[i]->getID() == someID){
              return table[i];
            }
          }
          return nullptr;
        }

        friend std::ostream &operator<<(std::ostream &os, Table &tabl){
          os << "Total amount of groups --> " << tabl.tSize;
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
                os << *i;
              }
            }
          }
          return os;
        }
    };


#endif //UNIVERGROUPSLAB_TABLE_H
