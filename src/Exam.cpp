#include "Exam.h"

Exam::Exam(std::string name, double obtainedNote, double maximumNote,
           double weighting)
    : name_(name), obtainedNote_(obtainedNote), maximumNote_(maximumNote),
      weighting_(weighting), done_(false){};

Exam::~Exam(){};

std::string Exam::getName() const { return name_; };

double Exam::getObtainedNote() const { return obtainedNote_; };

double Exam::getMaximumNote() const { return maximumNote_; };

double Exam::getWeighting() const { return weighting_; };

bool Exam::getStatus() const { return done_; }

void Exam::setName(std::string name) { name_ = name; };
void Exam::setObtainedNote(double note) { obtainedNote_ = note; };
void Exam::setMaximumNote(double note) { maximumNote_ = note; };
void Exam::setWeighting(double weight) { weighting_ = weight; };

void Exam::setStatus(bool isdone) { done_ = isdone; }

std::ostream &operator<<(std::ostream &os, const Exam &exam) {
  os << "Exam Name : " << exam.getName() << std::endl;
  return os;
};
