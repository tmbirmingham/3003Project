// Gradebook.h
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>
#include "Student.h"

class Gradebook {
public:
    std::vector<Student*> students;

    ~Gradebook();

    void addStudent(const std::string& name);
    void removeStudent();
    void inputGrades();
    void displayGrades() const;
    void calculateFinalGrade() const;
};

#endif // GRADEBOOK_H
