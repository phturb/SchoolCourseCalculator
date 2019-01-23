

#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Course.h"
#include "Exam.h"
#include "GeneralFunction.h"
#include "Semester.h"
#include "Student.h"
#include <iostream>
#include <map>
#include <string>

class StudentManager {
public:
  StudentManager();
  ~StudentManager();
  void menu(string menuType);
  void addSemester(Student *student);
  void addCourse(Semester *semester);
  void passedExam(Exam *exam);
  void addExam(Course *course);
  void examChoice(Exam *exam);
  void courseChoice(Course *course);
  void semesterChoice(Semester *semester);
  bool choiceMaker(Student *student);

private:
};

#endif
