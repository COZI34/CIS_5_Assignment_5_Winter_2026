#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_STUDENTS 5

struct Student {
	int studentId;
	string studentName;
	float studentGrades;
};

void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
	Student students[MAX_STUDENTS];
	int count = 0;
	int choice;

	// ---------------- Add 5 students ----------------
	students[0] = { 1001, "Alice", 92.5 };
	students[1] = { 1002, "Bob", 85.0 };
	students[2] = { 1003, "Charlie", 78.5 };
	students[3] = { 1004, "Diana", 88.0 };
	students[4] = { 1005, "Ethan", 95.0 };

	count = 5;
	// ------------------------------------------------

	do {
		printMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			highestGrade(students, count);
			break;
		case 2:
			lowestGrade(students, count);
			break;
		case 3:
			averageGrade(students, count);
			break;
		case 4:
			printStudentId(students, count);
			break;
		case 5:
			printStudentName(students, count);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}

void printMenu() {
	cout << "\n=== Student Record System ===\n";
	cout << "1. Find student with the highest grade\n";
	cout << "2. Find the student with the lowest grade\n";
	cout << "3. Find the average grade in the class\n";
	cout << "4. Print all the student's ID\n";
	cout << "5. Print all the student's names\n";
	cout << "6. Exit\n";
}

void highestGrade(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float highest = students[0].studentGrades;
	int index = 0;

	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades > highest) {
			highest = students[i].studentGrades;
			index = i;
		}
	}

	cout << "Highest Grade: " << students[index].studentGrades
		<< " (" << students[index].studentName << ")\n";
}

void lowestGrade(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float lowest = students[0].studentGrades;
	int index = 0;

	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades < lowest) {
			lowest = students[i].studentGrades;
			index = i;
		}
	}

	cout << "Lowest Grade: " << students[index].studentGrades
		<< " (" << students[index].studentName << ")\n";
}

void averageGrade(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += students[i].studentGrades;
	}

	cout << fixed << setprecision(2);
	cout << "Average Grade: " << sum / count << endl;
}

void printStudentId(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student IDs:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentId << endl;
	}
}

void printStudentName(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student Names:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentName << endl;
	}
}
