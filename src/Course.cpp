#include "Course.h"

Course::Course(std::string name, unsigned int credit, double passingNote)
    : name_(name), credit_(credit), passingNote_(passingNote), note_(0),
      coteLetter_("F") {
  cote_ = F;
};
Course::~Course() { deleteItemList(); };
// getter
string Course::getName() const { return name_; };

unsigned int Course::getCredit() const { return credit_; };

double Course::getPassingNote() const { return passingNote_; };

// setter
void Course::setName(const std::string name) { name_ = name; }

void Course::setCredit(const unsigned int credit) { credit_ = credit; }

void Course::setPassingNote(const double note) { passingNote_ = note; };

// Manupulator

void Course::calculateCourseNote() {
  double note = 0;
  double weight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); ++it) {
    Exam *exam = it->second;
    if (exam->getStatus()) {
      note += (exam->getObtainedNote() / exam->getMaximumNote()) *
              (exam->getWeighting());
      weight += exam->getWeighting();
    }
  }
  note_ = note;
};
double Course::calculateMissingPercentage() {
  calculateCourseNote();
  if (note_ >= passingNote_) {
    return 0;
  } else {
    return passingNote_ - note_;
  }
};
double Course::calculateCurrentNote() {
  double note = 0;
  double weight = 0;
  for (auto it = itemList_.begin(); it != itemList_.end(); ++it) {
    Exam *exam = it->second;
    if (exam->getStatus()) {
      note += (exam->getObtainedNote() / exam->getMaximumNote()) *
              (exam->getWeighting());
      weight += exam->getWeighting();
    }
  }
  calculateLettreCote();
  return note / weight * 100;
};

void Course::calculateLettreCote() {
  calculateCourseNote();
  if (note_ >= 80) {
    cote_ = A;
    coteLetter_ = "A";
  } else if (note_ >= 75) {
    cote_ = BPLUS;
    coteLetter_ = "B+";
  } else if (note_ >= 70) {
    cote_ = B;
    coteLetter_ = "B";
  } else if (note_ >= 65) {
    cote_ = CPLUS;
    coteLetter_ = "C+";
  } else if (note_ >= 60) {
    cote_ = C;
    coteLetter_ = "C";
  } else if (note_ >= 55) {
    cote_ = DPLUS;
    coteLetter_ = "D+";
  } else if (note_ >= 50) {
    cote_ = D;
    coteLetter_ = "D";
  } else {
    cote_ = F;
    coteLetter_ = "F";
  }
};

double Course::calculateCote() {
  switch (cote_) {
  case A:
    return 4;
  case BPLUS:
    return 3.5;
  case B:
    return 3;
  case CPLUS:
    return 2.5;
  case C:
    return 2;
  case DPLUS:
    return 1.5;
  case D:
    return 1;
  case F:
    return 0;
  default:
    return 0;
  }
};

std::ostream &operator<<(std::ostream &os, Course &course) {
  os << "-------------------------------\n";
  os << "Course Name : " << course.getName() << std::endl;
  os << "-------------------------------\n";
  course.showItems();
  double weight = 0;
  double note = 0;
  for (auto it = course.itemList_.begin(); it != course.itemList_.end(); ++it) {
    auto *exam = it->second;
    if (exam->getStatus()) {
      note += (exam->getObtainedNote() / exam->getMaximumNote()) *
              (exam->getWeighting());
      weight += exam->getWeighting();
    }
  }
  course.calculateCurrentNote();

  cout << "Course Info" << endl;
  cout << "Current Mark : " << course.note_ << "/" << weight << endl;
  cout << "Missing percentage : " << course.calculateMissingPercentage() << "%"
       << endl;
  cout << "Cote : " << course.calculateCote() << " -- " << course.coteLetter_
       << endl;
  return os;
};
