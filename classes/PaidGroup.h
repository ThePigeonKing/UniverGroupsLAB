#ifndef UNIVERGROUPSLAB_PAIDGROUP_H
#define UNIVERGROUPSLAB_PAIDGROUP_H

#include "iostream"
#include "structs.h"
#include "Group.h"

using namespace tpk4;

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
    void writeToOstream(std::ostream& os) const override;

};

#endif //UNIVERGROUPSLAB_PAIDGROUP_H
