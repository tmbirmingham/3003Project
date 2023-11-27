// Gradebook.cpp
#include "Gradebook.h"
#include <iostream>
#include <iomanip>

Gradebook::~Gradebook() {
    for (Student* student : students) {
        delete student;
    }
}

void Gradebook::addStudent(const std::string& name) {
    Student* newStudent = new Student;
    newStudent->name = name;
    students.push_back(newStudent);
}

void Gradebook::removeStudent() {
    if (students.empty()) {
        std::cout << "No students to remove.\n";
        return;
    }

    std::cout << "Choose a student to remove:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i]->name << "\n";
    }

    int studentChoice;
    std::cout << "Enter the number corresponding to the student: ";
    std::cin >> studentChoice;

    if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
        delete students[studentChoice - 1];
        students.erase(students.begin() + studentChoice - 1);
        std::cout << "Student removed.\n";
    } else {
        std::cout << "Invalid student choice.\n";
    }

    std::cin.ignore();  // Ignore any newline character
}

void Gradebook::inputGrades() {
    if (students.empty()) {
        std::cout << "No students to input grades for.\n";
        return;
    }

    std::cout << "Choose a student to input grades for:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i]->name << "\n";
    }

    int studentChoice;
    std::cout << "Enter the number corresponding to the student: ";
    std::cin >> studentChoice;

    if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
        Student* selectedStudent = students[studentChoice - 1];

        std::cout << "Enter grades for " << selectedStudent->name << " (Enter -1 to finish):\n";
        double grade;
        do {
            std::cin >> grade;

            if (grade != -1) {
                selectedStudent->grades.push_back(grade);
            }

        } while (grade != -1);
    } else {
        std::cout << "Invalid student choice.\n";
    }

    std::cin.ignore();  // Ignore any newline character
}

void Gradebook::displayGrades() const {
    if (students.empty()) {
        std::cout << "No students to display grades for.\n";
        return;
    }

    if (students.size() == 1) {
        // If there is only one student, display their grades directly
        const Student* student = students[0];
        std::cout << "Grades for " << student->name << ": ";
        for (double grade : student->grades) {
            std::cout << grade << " ";
        }
        std::cout << "\n";
        std::cout << "Average: " << std::fixed << std::setprecision(2) << student->getAverage() << "\n\n";
        return;
    }

    std::cout << "Choose a student to display grades for:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i]->name << "\n";
    }

    int studentChoice;
    std::cout << "Enter the number corresponding to the student: ";
    std::cin >> studentChoice;

    if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
        const Student* selectedStudent = students[studentChoice - 1];

        std::cout << "Grades for " << selectedStudent->name << ": ";
        for (double grade : selectedStudent->grades) {
            std::cout << grade << " ";
        }
        std::cout << "\n";
        std::cout << "Average: " << std::fixed << std::setprecision(2) << selectedStudent->getAverage() << "\n\n";
    } else {
        std::cout << "Invalid student choice.\n";
    }

    std::cin.ignore();  // Ignore any newline character
}

void Gradebook::calculateFinalGrade() const {
    if (students.empty()) {
        std::cout << "No students to calculate final grades for.\n";
        return;
    }

    std::cout << "Choose a student to calculate the final grade for:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i]->name << "\n";
    }

    int studentChoice;
    std::cout << "Enter the number corresponding to the student: ";
    std::cin >> studentChoice;

    if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
        const Student* selectedStudent = students[studentChoice - 1];

        double finalExamScore;
        std::cout << "Enter the final exam score for " << selectedStudent->name << ": ";
        std::cin >> finalExamScore;

        double finalExamWeight;
        std::cout << "Enter the weight of the final exam for " << selectedStudent->name << " (as a decimal, e.g., 0.4): ";
        std::cin >> finalExamWeight;

        std::cout << "Final grade for " << selectedStudent->name << ": "
                  << std::fixed << std::setprecision(2) << selectedStudent->calculateFinalGrade(finalExamScore, finalExamWeight) << "\n\n";
    } else {
        std::cout << "Invalid student choice.\n";
    }

    std::cin.ignore();  // Ignore any newline character
}
