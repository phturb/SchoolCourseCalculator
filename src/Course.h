#ifndef CLASS_H
#define CLASS_H

#include "Exam.h"
#include "GeneralFunction.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Course : public GeneralFunction<Exam> {
public:
  Course(std::string name = "", unsigned int credit = 0,
         double passingNote = 50);
  ~Course();

  enum Cote { A, BPLUS, B, CPLUS, C, DPLUS, D, F };
  // getter
  unsigned int getCredit() const;
  double getPassingNote() const;
  // setter
  void setCredit(const unsigned int credit);
  void setPassingNote(const double note);

  void calculateLettreCote();
  double calculateCote();
  void calculateCourseNote();
  double calculateMissingPercentage();
  double calculateCurrentNote();

  friend std::ostream &operator<<(std::ostream &os, Course &course);

private:
  unsigned int credit_;
  double passingNote_;
  double note_;
  Cote cote_;
  string coteLetter_;
};

#endif
