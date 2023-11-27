// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
public:
    std::string name;
    std::vector<double> grades;

    double getAverage() const;
    double calculateFinalGrade(double finalExamScore, double finalExamWeight) const;
};

#endif // STUDENT_H
