#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>

using namespace std;

class Exam {
public:
  Exam(std::string name = "", double obtainedNote = 0, double maximumNote = 0,
       double weighting = 0);
  ~Exam();
  std::string getName() const;
  double getObtainedNote() const;
  double getMaximumNote() const;
  double getWeighting() const;
  bool getStatus() const;

  void setName(std::string name);
  void setObtainedNote(double note);
  void setMaximumNote(double note);
  void setWeighting(double weight);
  void setStatus(bool isdone);

  friend std::ostream &operator<<(std::ostream &os, const Exam &exam);

private:
  std::string name_;
  double obtainedNote_;
  double maximumNote_;
  double weighting_;
  bool done_;
};

#endif
