#include "Course.h"
#include "Exam.h"
#include "Semester.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main() {
  Semester testSem("TestSem");
  cout<<testSem<<endl;
  Course* testCourse = new Course("testCourse",3);
  cout<<*testCourse<<endl;
  Exam* testExam1 = new Exam("testExam1",14,20,40);
  Exam* testExam2 = new Exam("testExam2",14,20,60);
  cout<<*testExam1<<endl;
  cout<<*testExam2<<endl;
  testCourse->addExam(testExam1);
  cout<<*(testCourse->getExam("testExam3"))<<endl;
  testCourse->addExam(testExam2);
  testSem.addCourse(testCourse);

  return 0;
}
