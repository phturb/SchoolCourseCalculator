#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Semester {
public:
        Semester(string name = "");
        ~Semester();

        Course* getCourse(std::string courseName) const;
        std::string getName() const;

        void setName(std::string name);

        void addCourse(Course* course);
        void removeCourse(Course* course);
        friend ostream& operator<<(ostream& os, const Semester &semester);
private:
        map<string, Course*> courseList_;
        string name_;
};


#endif
