#include <iostream>
#include <vector>
#include <string>

using namespace std;

float getGradePoints(string grade) {
    if (grade == "A+") return 10;
    else if (grade == "A") return 9;
    else if (grade == "B+") return 8;
    else if (grade == "B") return 7;
    else if (grade == "C+") return 6;
    else if (grade == "C") return 5;
    else if (grade == "D+") return 4;
    else if (grade == "D") return 3;
    else if (grade == "E+") return 2;
    else if (grade == "E") return 1;
    else if (grade == "F") return 0;
    else return 0;
}

float calculateSGPA(vector<string> grades, vector<int> credits, int &totalGradePoints, int &totalCredits) {
    totalGradePoints = 0;
    totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalGradePoints += getGradePoints(grades[i]) * credits[i];
        totalCredits += credits[i];
    }

    return (totalGradePoints) / totalCredits; 
}

int main() {
    int semesters;
    cout << "Enter the number of semesters: ";
    cin >> semesters;

    int totalCreditsAll = 0;
    int totalGradePointsAll = 0;

    for (int sem = 1; sem <= semesters; ++sem) {
        cout << "\nSemester " << sem << endl;
        int courses;
        cout << "Enter the number of courses: ";
        cin >> courses;

        vector<string> grades(courses);
        vector<int> credits(courses);

        for (int course = 0; course < courses; ++course) {
            cout << "Enter grade for course " << course + 1 << ": ";
            cin >> grades[course];
            cout << "Enter credit for course " << course + 1 << ": ";
            cin >> credits[course];
        }

        int totalGradePoints, totalCredits;
        float sgpa = calculateSGPA(grades, credits, totalGradePoints, totalCredits);
        cout << "SGPA for Semester " << sem << ": " << sgpa << endl;

        totalCreditsAll += totalCredits;
        totalGradePointsAll += totalGradePoints;
    }

    float cgpa = (totalGradePointsAll) / totalCreditsAll;
    cout << "\nCumulative Grade Point Average (CGPA): " << cgpa << endl;

    return 0;
}
