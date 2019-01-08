#ifndef CLASS_H
#define CLASS_H

#include "Exam.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Course {
public:
  Course(std::string name = "", unsigned int credit = 0);
  ~Course();
  // getter
  std::string getName() const;
  Exam *getExam(const std::string examName);
  unsigned int getCredit() const;
  // setter
  void setName(const std::string name);
  void setCredit(const unsigned int credit);

  void addExam(Exam *exam);
  void removeExam(Exam *exam);

  double calculateCourseNote();
  double calculateMissingPercentage();
  double calculateCurrentNote();

  friend std::ostream &operator<<(std::ostream &os, const Course &course);

private:
  std::string name_;
  std::map<std::string, Exam *> examList_;
  unsigned int credit_;
};

#endif
