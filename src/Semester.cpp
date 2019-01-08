#include "Semester.h"

Semester::Semester(string name) : name_(name){};

Semester::~Semester(){};

std::string Semester::getName() const { return name_; };

void Semester::setName(std::string name) { name_ = name; };

std::ostream &operator<<(std::ostream &os, const Semester &semester) {
  os << semester.getName() << std::endl;
  return os;
};
