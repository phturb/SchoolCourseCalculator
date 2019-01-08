#include "Semester.h"

Semester::Semester(string name) : name_(name){};

Semester::~Semester(){};

Course *Semester::getCourse(std::string courseName) const {
  return new Course();
};

std::string Semester::getName() const { return name_; };

void Semester::setName(std::string name) { name_ = name; };

void Semester::addCourse(Course *course) {
  string name = course->getName();
  auto it = courseList_.find(name);
  if (it != courseList_.end()) {
    cout << "Exam deja existant" << endl;
  } else {
    courseList_.insert(std::pair<string, Course *>(name, course));
  }
};

void Semester::removeCourse(Course *course) {
  string name = course->getName();
  auto it = courseList_.find(name);
  if (it != courseList_.end()) {
    courseList_.erase(it);
  } else {
    cout << "The exam doesn't exist" << endl;
  }
};

std::ostream &operator<<(std::ostream &os, const Semester &semester) {
  os << semester.getName() << std::endl;
  return os;
};
