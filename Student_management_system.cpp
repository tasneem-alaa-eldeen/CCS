#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    vector<string> courses;

public:
    Student(string studentName) {
        name = studentName;
    }

    string getName() const {
        return name;
    }

    void addCourse(const string& course) {
        courses.push_back(course);
        cout << "Course \"" << course << "\" added to " << name << ".\n";
    }

    void deleteCourse(const string& course) {
        auto it = find(courses.begin(), courses.end(), course);
        if (it != courses.end()) {
            courses.erase(it);
            cout << "Course \"" << course << "\" removed from " << name << ".\n";
        } else {
            cout << "Course not found for student " << name << ".\n";
        }
    }

    void display() const {
        cout << "Student: " << name << "\n";
        cout << "  Courses: ";
        if (courses.empty()) {
            cout << "None";
        } else {
            for (size_t i = 0; i < courses.size(); i++) {
                cout << courses[i] << (i + 1 < courses.size() ? ", " : "");
            }
        }
        cout << "\n";
    }
};

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Add Course to Student\n";
        cout << "4. Delete Course from Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            students.push_back(Student(name));
            cout << "Student \"" << name << "\" added.\n";
        } else if (choice == 2) {
            string name;
            cout << "Enter student name to delete: ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->getName() == name) {
                    students.erase(it);
                    cout << "Student \"" << name << "\" deleted.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found.\n";
        } else if (choice == 3) {
            string name, course;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (auto& s : students) {
                if (s.getName() == name) {
                    cout << "Enter course name: ";
                    getline(cin, course);
                    s.addCourse(course);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found.\n";
        } else if (choice == 4) {
            string name, course;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (auto& s : students) {
                if (s.getName() == name) {
                    cout << "Enter course name to delete: ";
                    getline(cin, course);
                    s.deleteCourse(course);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found.\n";
        } else if (choice == 5) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                for (const auto& s : students) {
                    s.display();
                }
            }
        } else if (choice == 6) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}