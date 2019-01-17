#include "Course.h"
#include "Exam.h"
#include "GeneralFunction.h"
#include "Semester.h"
#include "Student.h"
#include <iostream>
#include <map>
#include <string>

string semesterName = "";
string courseName = "";
string examName = "";
double maximumNote = 0;
double obtainedNote = 0;
double examWeight = 0;
unsigned int creditNumber = 0;
double passingNote = 0;
int choice = 0;
string isPassed = "No";
void test1(Student *testStudent) {

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
};

void menu(string menuType) {
  cout << "-----------------------" << endl;
  cout << "1 to add a " << menuType << endl;
  cout << "2 to look at a " << menuType << endl;
  cout << "3 to show a specific " << menuType << endl;
  cout << "4 to delete a " << menuType << endl;
  cout << "9 to exit" << endl;
  cout << "-----------------------" << endl;
}

void addSemester(Student *student) {
  cout << "Semester name : ";
  cin >> semesterName;
  student->addItem(new Semester(semesterName));
};

void addCourse(Semester *semester) {
  cout << "Course name : ";
  cin >> courseName;
  cout << "Credit number : ";
  cin >> creditNumber;
  cout << "PassingNote : ";
  cin >> passingNote;
  semester->addItem(new Course(courseName));
};
void passedExam(Exam *exam) {
  exam->setStatus(true);
  cout << "On how much was the exam : ";
  cin >> maximumNote;
  exam->setMaximumNote(maximumNote);
  cout << "What note did you get: ";
  cin >> obtainedNote;
  exam->setObtainedNote(obtainedNote);
}
void addExam(Course *course) {
  cout << "Exam name : ";
  cin >> examName;
  Exam *exam = new Exam(examName);
  cout << "How much worth is the exam : ";
  cin >> examWeight;
  exam->setWeighting(examWeight);
  cout << "Was the exam passed (Yes or No): ";
  cin >> isPassed;
  if (isPassed == "Yes") {
    exam->setStatus(true);
    passedExam(exam);
  } else {
    exam->setStatus(false);
  }
  course->addItem(exam);
};

void examChoice(Exam *exam) {
  choice = 0;
  cout << exam->getName() << "Exam CHOICE MAKER" << endl;
  cin >> choice;
  switch (choice) {
  case 1:
    passedExam(exam);
    break;
  default:
    break;
  };
};

void courseChoice(Course *course) {
  choice = 0;
  cout << course->getName() << " CHOICE MAKER" << endl;
  menu("Exam");
  cin >> choice;
  switch (choice) {
  case 1:
    addExam(course);
    break;
  case 2:
    cout << "Enter course name" << endl;
    cin >> examName;
    examChoice(course->getItem(examName));
    break;
  case 3:
    cout << "Enter course name" << endl;
    for (auto it = course->getItemList().begin();
         it != course->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> examName;
    cout << *(course->getItem(examName));
    break;
  case 4:
    cout << "Enter course name" << endl;
    for (auto it = course->getItemList().begin();
         it != course->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> examName;
    course->removeItem(examName);
    break;
  default:
    break;
  };
};

void semesterChoice(Semester *semester) {
  choice = 0;
  cout << semester->getName() << " CHOICE MAKER" << endl;
  menu("Course");
  cin >> choice;
  switch (choice) {
  case 1:
    addCourse(semester);
    break;
  case 2:
    cout << "Enter course name" << endl;
    for (auto it = semester->getItemList().begin();
         it != semester->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> courseName;
    courseChoice(semester->getItem(courseName));
    break;
  case 3:
    cout << "Enter course name" << endl;
    for (auto it = semester->getItemList().begin();
         it != semester->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> courseName;
    cout << *(semester->getItem(courseName));
    break;
  case 4:
    cout << "Enter course name" << endl;
    for (auto it = semester->getItemList().begin();
         it != semester->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> courseName;
    semester->removeItem(courseName);
    break;
  default:
    break;
  };
};

bool choiceMaker(Student *student) {
  choice = 0;
  cout << student->getName() << " CHOICE MAKER" << endl;
  menu("Semester");
  cin >> choice;
  switch (choice) {
  case 1:
    addSemester(student);
    break;
  case 2:
    cout << "Enter semester name" << endl;
    for (auto it = student->getItemList().begin();
         it != student->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> semesterName;
    semesterChoice(student->getItem(semesterName));
    break;
  case 3:
    cout << "Enter semester name" << endl;
    for (auto it = student->getItemList().begin();
         it != student->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> semesterName;
    cout << *(student->getItem(semesterName));
    break;
  case 4:
    cout << "Enter semester name" << endl;
    for (auto it = student->getItemList().begin();
         it != student->getItemList().end(); it++) {
      cout << (it->second)->getName() << endl;
    }
    cin >> semesterName;
    student->removeItem(semesterName);
    break;
  case 5:
    cout << *student;
    break;
  case 6:
    test1(student);
    break;
  default:
    return false;
  }
  return true;
};

int main() {
  bool running = true;
  Student *testStudent = new Student("testStudent");
  while (running) {
    running = choiceMaker(testStudent);
  }
  delete testStudent;
  return 0;
};
