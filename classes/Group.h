#ifndef UNIVERGROUPSLAB_GROUP_H
#define UNIVERGROUPSLAB_GROUP_H

#include <iostream>
#include "structs.h"

using namespace tpk4;

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
    virtual void writeToOstream(std::ostream& os) const { };
    friend std::ostream& operator<<(std::ostream& os, const Group& group) {
      group.writeToOstream(os);

      return os;
    };
};


#endif //UNIVERGROUPSLAB_GROUP_H
