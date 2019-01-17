#include "Student.h"

Student::Student(std::string name) : creditAccumulated_(0){setName(name);};
Student::~Student() { deleteItemList(); };

// getter
double Student::getCreditAccumulated() {
  creditAccumulated_ = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    creditAccumulated_ += (it->second)->getTotalCredit();
  }
  return creditAccumulated_;
}
double Student::getCote() {
  double creditAccumulatedWeight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); it++) {
    creditAccumulatedWeight +=
        ((it->second)->getTotalCredit()) * ((it->second)->calculateCote());
  }
  return creditAccumulatedWeight / getCreditAccumulated();
}
// setter

std::ostream &operator<<(std::ostream &os, Student &student) {
  os << "\n*******************************" << endl;
  os << student.getName() << endl;
  student.showItems();
  os << "\n###############################" << endl;
  os << "Cote Moyenne : " << student.getCote() << endl;
  os << "*******************************" << endl;
  return os;
};
