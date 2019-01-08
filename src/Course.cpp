#include "Course.h"

Course::Course(std::string name, unsigned int credit)
    : name_(name), credit_(credit){};
Course::~Course(){};
// getter
std::string Course::getName() const { return name_; };
Exam* Course::getExam(string examName) {
  auto it = examList_.find(examName);
  if (it != examList_.end()) {
    return it->second;
  }
    return new Exam;
};
unsigned int Course::getCredit() const { return credit_; };
// setter
void Course::setName(const std::string name) { name_ = name; }
void Course::setCredit(const unsigned int credit) { credit_ = credit; }

void Course::addExam(Exam *exam) {
  auto it = examList_.find(exam->getName());
  if (it != examList_.end()) {
    cout << "Exam deja existant" << endl;
  } else {
    examList_.insert(std::pair<string, Exam *>(exam->getName(), exam));
  }
};

void Course::removeExam(Exam *exam) {
  string name = exam->getName();
  auto it = examList_.find(name);
  if (it != examList_.end()) {
    examList_.erase(it);
  } else {
    cout << "The exam doesn't exist" << endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Course &course) {
  os << course.getName() << std::endl;
  return os;
};
