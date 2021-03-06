#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"
#include "GeneralFunction.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Semester : public GeneralFunction<Course> {
public:
  Semester(string name = "");
  ~Semester();

  double getTotalCredit();


  double calculateCote();

  string calculateLettreCote();

  friend ostream &operator<<(ostream &os, Semester &semester);

private:
  map<string, Course *> courseList_;
  string name_;
  double totalCredit_;
};

#endif
