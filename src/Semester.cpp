#include "Semester.h"

Semester::Semester(string name){setName(name);};

Semester::~Semester() { deleteItemList(); };

double Semester::calculateCote() {
  double totalCreditWeight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    totalCreditWeight +=
        (it->second)->calculateCote() * (it->second)->getCredit();
  }
  if (getTotalCredit() <= 0) {
    return 0;
  } else {
    return totalCreditWeight / getTotalCredit();
  }
};

double Semester::getTotalCredit() {
  totalCredit_ = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    totalCredit_ += (it->second)->getCredit();
  }
  return totalCredit_;
}

std::ostream &operator<<(std::ostream &os, Semester &semester) {
  os << "###############################\n"
     << "Semester Name : " << semester.getName() << std::endl;
  semester.showItems();
  os << "_______________________________\n"
     << "Cote Semestre : " << semester.calculateCote() << std::endl;
  return os;
};
