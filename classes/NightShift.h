#ifndef UNIVERGROUPSLAB_NIGHTSHIFT_H
#define UNIVERGROUPSLAB_NIGHTSHIFT_H

#include "structs.h"
#include "Group.h"

using namespace tpk4;

class NightShift : public Group {
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
    void writeToOstream(std::ostream& os) const override;
    //friend std::ostream& operator<<(std::ostream& os, const NightShift& group);
};

#endif //UNIVERGROUPSLAB_NIGHTSHIFT_H
