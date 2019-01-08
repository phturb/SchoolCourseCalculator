#include "Course.h"
#include "Exam.h"
#include "GeneralFunction.h"
#include "Semester.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  Semester testSem("TestSem");
  cout << testSem << endl;
  Course *testCourse = new Course("testCourse", 3, 50);
  cout << *testCourse << endl;
  Exam *testExam1 = new Exam("testExam1", 14, 20, 40);
  Exam *testExam2 = new Exam("testExam2", 14, 20, 60);
  testExam1->setStatus(true);
  cout << *testExam1 << endl;
  cout << *testExam2 << endl;
  testCourse->addItem(testExam1);
  testCourse->addItem(testExam2);
  cout << *(testCourse->getItem("testExam2")) << endl;
  testSem.addItem(testCourse);
  cout << (testSem.getItem("testCourse"))->calculateCurrentNote() << endl;
  cout << (testSem.getItem("testCourse"))->calculateCourseNote() << endl;
  cout << (testSem.getItem("testCourse"))->calculateMissingPercentage() << endl;

  return 0;
}
