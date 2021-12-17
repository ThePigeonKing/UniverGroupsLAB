#ifndef UNIVERGROUPSLAB_DAYSHIFT_H
#define UNIVERGROUPSLAB_DAYSHIFT_H

#include "Table.h"
#include "Group.h"

class DayShift : public Group {
private:        Spec specialization_;
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
    // instead of overloading <<
    void writeToOstream(std::ostream& os) const override;
    //friend std::ostream& operator<<(std::ostream& os, const DayShift& group);
};

#endif //UNIVERGROUPSLAB_DAYSHIFT_H
