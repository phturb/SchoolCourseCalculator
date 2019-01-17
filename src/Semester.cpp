#include "Semester.h"

Semester::Semester(string name) : name_(name){};

Semester::~Semester(){};

std::string Semester::getName() const { return name_; };

void Semester::setName(std::string name) { name_ = name; };

double Semester::calculateCote() {
  double totalCredit = 0;
  double totalCreditWeight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    totalCredit += (it->second)->getCredit();
    totalCreditWeight +=
        (it->second)->calculateCote() * (it->second)->getCredit();
  }
  if (totalCredit <= 0) {
    return 0;
  } else {
    return totalCreditWeight/totalCredit;
  }
};

std::ostream &operator<<(std::ostream &os, Semester &semester) {
  os << "###############################\n"
     << "Semester Name : " << semester.getName() << std::endl;
  auto semItemList = semester.getItemList();
  for (auto it = semItemList.begin(); it != semItemList.end(); it++) {
    os << *(it->second);
  }
  os << "________________________________\n" << "Cote Semestre : " << semester.calculateCote();
  return os;
};
