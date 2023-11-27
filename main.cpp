// main.cpp
#include "Gradebook.h"
#include "Student.h"
#include <iostream>

int main() {
    Gradebook gradebook;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Input Grades\n";
        std::cout << "3. Display Grades\n";
        std::cout << "4. Calculate Final Grade\n";
        std::cout << "5. Remove Student\n";
        std::cout << "0. Exit\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string studentName;
                std::cout << "Enter the name of the student: ";
                std::cin.ignore();  // Ignore any leftover newline character
                std::getline(std::cin, studentName);
                gradebook.addStudent(studentName);
                break;
            }
            case 2:
                gradebook.inputGrades();
                break;
            case 3:
                gradebook.displayGrades();
                break;
            case 4:
                gradebook.calculateFinalGrade();
                break;
            case 5:
                gradebook.removeStudent();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
