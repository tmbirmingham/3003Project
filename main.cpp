#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    vector<double> grades;

    double getAverage() const {
        if (grades.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }

        return sum / grades.size();
    }

    double calculateFinalGrade(double finalExamScore) const {
        // Weight of final will always be 40% of total grade
        // Hope to add feature that will allow user to enter the weight of the grade distribution
        double average = getAverage();
        return 0.6 * average + 0.4 * finalExamScore;
    }
};

class Gradebook {
public:
    vector<Student*> students;

    ~Gradebook() {
        for (Student* student : students) {
            delete student;
        }
    } // Gradebook deconstructor to free up unused space

    // Function to add student push_back function used to add the student to the end of the vector
    void addStudent(const string& name) {
        Student* newStudent = new Student;
        newStudent->name = name;
        students.push_back(newStudent);
    }

    // This will be displayed if the user attempts to view grades without any students stored in the system
    void removeStudent() {
        if (students.empty()) {
            cout << "No students to remove.\n";
            return;
        }

        // Using size_t to make sure the memory is properly taken care of
        cout << "Choose a student to remove:\n";
        for (size_t i = 0; i < students.size(); ++i) {
            cout << i + 1 << ". " << students[i]->name << "\n";
        }

        int studentChoice;
        cout << "Enter the number corresponding to the student: ";
        cin >> studentChoice;

        // Logic for deleting the selected student from the vector
        if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
            delete students[studentChoice - 1];
            students.erase(students.begin() + studentChoice - 1);
            cout << "Student removed.\n";
        } else {
            cout << "Invalid student choice.\n";
        }
    }

    // Function to allow the user to enter the grades for a student that they select
    void inputGrades() {
        if (students.empty()) {
            cout << "No students to input grades for.\n";
            return;
        }

        cout << "Choose a student to input grades for:\n";
        for (size_t i = 0; i < students.size(); ++i) {
            cout << i + 1 << ". " << students[i]->name << "\n";
        }

        int studentChoice;
        cout << "Enter the number corresponding to the student: ";
        cin >> studentChoice;

        // Logic to determine what student was selected
        if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
            Student* selectedStudent = students[studentChoice - 1];

            cout << "Enter grades for " << selectedStudent->name << " (Enter -1 to finish):\n";
            double grade;
            do {
                cin >> grade;

                // -1 is a good sentinel value because grades cannot be a negative value
                if (grade != -1) {
                    selectedStudent->grades.push_back(grade);
                }

            } while (grade != -1);
        } else {
            cout << "Invalid student choice.\n";
        }
    }

    // Function to display the grades for a given student
    void displayGrades() const {
        if (students.empty()) {
            cout << "No students to display grades for.\n";
            return;
        }

        cout << "Choose a student to display grades for:\n";
        for (size_t i = 0; i < students.size(); ++i) {
            cout << i + 1 << ". " << students[i]->name << "\n";
        }

        int studentChoice;
        cout << "Enter the number corresponding to the student: ";
        cin >> studentChoice;

        if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
            const Student* selectedStudent = students[studentChoice - 1];

            cout << "Grades for " << selectedStudent->name << ": ";
            for (double grade : selectedStudent->grades) {
                cout << grade << " ";
            }
            cout << "\n";
            cout << "Average: " << fixed << setprecision(2) << selectedStudent->getAverage() << "\n\n";
        } else {
            cout << "Invalid student choice.\n";
        }
    }

    // Function to display the final grade to the user
    void calculateFinalGrade() const {
        if (students.empty()) {
            cout << "No students to calculate final grades for.\n";
            return;
        }

        cout << "Choose a student to calculate the final grade for:\n";
        for (size_t i = 0; i < students.size(); ++i) {
            cout << i + 1 << ". " << students[i]->name << "\n";
        }

        int studentChoice;
        cout << "Enter the number corresponding to the student: ";
        cin >> studentChoice;

        if (studentChoice >= 1 && studentChoice <= static_cast<int>(students.size())) {
            const Student* selectedStudent = students[studentChoice - 1];

            double finalExamScore;
            cout << "Enter the final exam score for " << selectedStudent->name << ": ";
            cin >> finalExamScore;

            cout << "Final grade for " << selectedStudent->name << ": "
                 << fixed << setprecision(2) << selectedStudent->calculateFinalGrade(finalExamScore) << "\n\n";
        } else {
            cout << "Invalid student choice.\n";
        }
    }
};

int main() {
    Gradebook gradebook;
    int choice;

    /* Do while loop to act as a menu for the user
    if the user enters the sentinel value of 0, the program will end*/
    do {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Input Grades\n";
        cout << "3. Display Grades\n";
        cout << "4. Calculate Final Grade\n";
        cout << "5. Remove Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string studentName;
                cout << "Enter the name of the student: ";
                cin >> studentName;
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
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
