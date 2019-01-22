#include "StudentManager.h"

StudentManager::StudentManager(){};

void StudentManager::menu(string menuType) {
  cout << "-----------------------" << endl;
  cout << "1 to add a " << menuType << endl;
  cout << "2 to look at a " << menuType << endl;
  cout << "3 to show a specific " << menuType << endl;
  cout << "4 to delete a " << menuType << endl;
  cout << "9 to exit" << endl;
  cout << "-----------------------" << endl;
}

void StudentManager::addSemester(Student *student) {
  string semesterName;
  cout << "Semester name : ";
  cin >> semesterName;
  student->addItem(new Semester(semesterName));
};

void StudentManager::addCourse(Semester *semester) {
  string courseName;
  string creditNumber;
  string passingNote;
  cout << "Course name : ";
  cin >> courseName;
  cout << "Credit number : ";
  cin >> creditNumber;
  cout << "PassingNote : ";
  cin >> passingNote;
  semester->addItem(new Course(courseName));
};
void StudentManager::passedExam(Exam *exam) {
  double maximumNote = 0;
  double obtainedNote = 0;
  exam->setStatus(true);
  cout << "On how much was the exam : ";
  cin >> maximumNote;
  exam->setMaximumNote(maximumNote);
  cout << "What note did you get: ";
  cin >> obtainedNote;
  exam->setObtainedNote(obtainedNote);
}
void StudentManager::addExam(Course *course) {
  string examName;
  double examWeight = 0;
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

void StudentManager::examChoice(Exam *exam) {
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

void StudentManager::courseChoice(Course *course) {
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

void StudentManager::semesterChoice(Semester *semester) {
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

bool StudentManager::choiceMaker(Student *student) {
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
