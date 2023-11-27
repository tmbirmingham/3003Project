// Student.cpp
#include "Student.h"

double Student::getAverage() const {
    if (grades.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double grade : grades) {
        sum += grade;
    }

    return sum / grades.size();
}

double Student::calculateFinalGrade(double finalExamScore, double finalExamWeight) const {
    double average = getAverage();
    return (1.0 - finalExamWeight) * average + finalExamWeight * finalExamScore;
}
