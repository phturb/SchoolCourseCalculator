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

  std::string getName() const;

  void setName(std::string name);

  friend ostream &operator<<(ostream &os, const Semester &semester);

private:
  map<string, Course *> courseList_;
  string name_;
};

#endif
