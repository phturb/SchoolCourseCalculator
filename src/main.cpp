#include "Course.h"
#include "Exam.h"
#include "GeneralFunction.h"
#include "Semester.h"
#include <iostream>
#include <map>
#include <string>

int main()
{
    Semester testSem("TestSem");
    Course *testCourse1 = new Course("testCourse1", 3, 50);
    Exam *testExam1 = new Exam("testExam1", 14, 20, 40);
    Exam *testExam2 = new Exam("testExam2", 14, 20, 60);
    testExam1->setStatus(true);
    testExam2->setStatus(true);
    testCourse1->addItem(testExam1);
    testCourse1->addItem(testExam2);
    testSem.addItem(testCourse1);
    Course *testCourse2 = new Course("testCourse2", 2, 50);
    Exam *testExam3 = new Exam("testExam3", 16, 20, 40);
    Exam *testExam4 = new Exam("testExam4", 11, 20, 60);
    testExam3->setStatus(true);
    testExam4->setStatus(true);
    testCourse2->addItem(testExam3);
    testCourse2->addItem(testExam4);
    testSem.addItem(testCourse2);
    cout << testSem << endl;

    return 0;
}
