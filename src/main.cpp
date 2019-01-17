#include "Course.h"
#include "Exam.h"
#include "GeneralFunction.h"
#include "Semester.h"
#include "Student.h"
#include <iostream>
#include <map>
#include <string>

void test1(Student * testStudent) {

  Semester *testSem = new Semester("TestSem");
  testStudent->addItem(testSem);
  Course *testCourse1 = new Course("testCourse1", 3, 50);
  Course *testCourse2 = new Course("testCourse2", 2, 50);
  testSem->addItem(testCourse1);
  testSem->addItem(testCourse2);
  Exam *testExam1 = new Exam("testExam1", 14, 20, 40);
  testExam1->setStatus(true);
  Exam *testExam2 = new Exam("testExam2", 14, 20, 60);
  testExam2->setStatus(true);
  Exam *testExam3 = new Exam("testExam3", 16, 20, 40);
  testExam3->setStatus(true);
  Exam *testExam4 = new Exam("testExam4", 11, 20, 60);
  testExam4->setStatus(true);
  testCourse1->addItem(testExam1);
  testCourse1->addItem(testExam2);
  testCourse2->addItem(testExam3);
  testCourse2->addItem(testExam4);
  Semester *testSem2 = new Semester("TestSem2");
  testStudent->addItem(testSem2);
  Course *testCourse3 = new Course("testCourse3", 3, 50);
  Course *testCourse4 = new Course("testCourse4", 3, 50);
  testSem2->addItem(testCourse3);
  testSem2->addItem(testCourse4);
  Exam *testExam5 = new Exam("testExam5", 11, 20, 40);
  testExam5->setStatus(true);
  Exam *testExam6 = new Exam("testExam6", 18, 20, 60);
  testExam6->setStatus(true);
  Exam *testExam7 = new Exam("testExam7", 13, 20, 40);
  testExam7->setStatus(true);
  Exam *testExam8 = new Exam("testExam8", 12, 20, 60);
  testExam8->setStatus(true);
  testCourse3->addItem(testExam5);
  testCourse3->addItem(testExam6);
  testCourse4->addItem(testExam7);
  testCourse4->addItem(testExam8);

  cout << *testStudent << endl;
};

int main() {
  Student *testStudent = new Student("testStudent");
  test1(testStudent);
  delete testStudent;
  return 0;
};
