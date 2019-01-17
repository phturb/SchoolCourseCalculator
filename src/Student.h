#ifndef STUDENT_H
#define STUDENT_H

#include "GeneralFunction.h"
#include "Semester.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Student : public GeneralFunction<Semester> {
public:
  Student(std::string name = "");
  ~Student();

  // getter

  double getCote();
  double getCreditAccumulated();

  friend std::ostream &operator<<(std::ostream &os, Student &student);

private:
  std::string name_;
  double creditAccumulated_;
};

#endif
