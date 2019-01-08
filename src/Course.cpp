#include "Course.h"

Course::Course(std::string name, unsigned int credit, double passingNote)
    : name_(name), credit_(credit), passingNote_(passingNote){};
Course::~Course(){};
// getter
string Course::getName() const { return name_; };

unsigned int Course::getCredit() const { return credit_; };

double Course::getPassingNote() const { return passingNote_; };

// setter
void Course::setName(const std::string name) { name_ = name; }

void Course::setCredit(const unsigned int credit) { credit_ = credit; }

void Course::setPassingNote(const double note) { passingNote_ = note; };

//Manupulator

double Course::calculateCourseNote()
{
  double note = 0;
  double weight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); ++it)
{
  Exam* exam = it->second;
  if(exam->getStatus()){
    note += (exam->getObtainedNote()/exam->getMaximumNote())*(exam->getWeighting());
    weight += exam->getWeighting();
  }
}
return note;
};
double Course::calculateMissingPercentage()
{
  double currentNote = calculateCourseNote();
  if (currentNote >= passingNote_){
    return 0;
  }
  else{
    return passingNote_ - currentNote;
  }
};
double Course::calculateCurrentNote()
{
  double note = 0;
  double weight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); ++it)
{
  Exam* exam = it->second;
  if(exam->getStatus()){
    note += (exam->getObtainedNote()/exam->getMaximumNote())*(exam->getWeighting());
    weight += exam->getWeighting();
  }
}
return note/weight*100;
};


std::ostream &operator<<(std::ostream &os, const Course &course) {
  os << course.getName() << std::endl;
  return os;
};
