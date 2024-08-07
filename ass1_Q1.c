#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS 10
#define NUM_SUBJECTS 5

typedef struct {
    char name[50];
    char address[100];
    int marks[NUM_SUBJECTS];
} Student;

void findPassedFailedStudents(Student *students, int numStudents) {
    printf("Students who have failed in at least three subjects:\n");
    for (int i = 0; i < numStudents; i++) {
        int failCount = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            if (students[i].marks[j] < 40) {
                failCount++;
            }
        }
        if (failCount >= 3) {
            printf("%s\n", students[i].name);
        }
    }
}

void findMaxInSubject(Student *students, int numStudents, int subjectIndex, char *subjectName) {
    int maxMarks = -1;
    int maxIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks[subjectIndex] > maxMarks) {
            maxMarks = students[i].marks[subjectIndex];
            maxIndex = i;
        }
    }
    if (maxIndex != -1) {
        printf("Student with highest marks in %s:\n", subjectName);
        printf("Name: %s\n", students[maxIndex].name);
        printf("Address: %s\n", students[maxIndex].address);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("Marks in subject %d: %d\n", i + 1, students[maxIndex].marks[i]);
        }
    }
}

void findMinInSubject(Student *students, int numStudents, int subjectIndex, char *subjectName) {
    int minMarks = 101;
    int minIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks[subjectIndex] < minMarks) {
            minMarks = students[i].marks[subjectIndex];
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        printf("Student with lowest marks in %s:\n", subjectName);
        printf("Name: %s\n", students[minIndex].name);
        printf("Address: %s\n", students[minIndex].address);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("Marks in subject %d: %d\n", i + 1, students[minIndex].marks[i]);
        }
    }
}

void findStudentWithHighestAverage(Student *students, int numStudents) {
    float maxAverage = -1;
    int maxIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            total += students[i].marks[j];
        }
        float average = total / (float) NUM_SUBJECTS;
        if (average > maxAverage) {
            maxAverage = average;
            maxIndex = i;
        }
    }
    if (maxIndex != -1) {
        printf("Student with highest average marks:\n");
        printf("Name: %s\n", students[maxIndex].name);
        printf("Address: %s\n", students[maxIndex].address);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("Marks in subject %d: %d\n", i + 1, students[maxIndex].marks[i]);
        }
    }
}

void printStudentRecord(Student *students, int numStudents) {
    char name[50];
    printf("Enter the name of the student: ");
    scanf("%s", name);
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            int total = 0;
            printf("Student record:\n");
            printf("Name: %s\n", students[i].name);
            printf("Address: %s\n", students[i].address);
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                printf("Marks in subject %d: %d\n", j + 1, students[i].marks[j]);
                total += students[i].marks[j];
            }
            printf("Total marks: %d\n", total);
            return;
        }
    }
    printf("Student not found.\n");
}

int main() {
    Student students[NUM_STUDENTS] = {
        {"Alice", "123 A St", {90, 85, 78, 92, 88}},
        {"Bob", "456 B St", {45, 50, 55, 60, 65}},
        {"Charlie", "789 C St", {30, 35, 40, 25, 20}},
        {"David", "101 D St", {70, 75, 80, 85, 90}},
        {"Eve", "202 E St", {95, 98, 99, 100, 97}},
        {"Frank", "303 F St", {20, 15, 25, 30, 35}},
        {"Grace", "404 G St", {85, 80, 82, 88, 90}},
        {"Hank", "505 H St", {75, 70, 78, 80, 85}},
        {"Ivy", "606 I St", {95, 85, 75, 65, 55}},
        {"Jack", "707 J St", {60, 50, 45, 55, 65}}
    };

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Find the name of the students who have failed in minimum three subjects\n");
        printf("2. Show the record of the student who has got maximum marks in Mathematics\n");
        printf("3. Show the record of the student who has got minimum marks in Physics\n");
        printf("4. Show the record of the student whose average marks is maximum\n");
        printf("5. Print the record of the student with name and total\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findPassedFailedStudents(students, NUM_STUDENTS);
                break;
            case 2:
                findMaxInSubject(students, NUM_STUDENTS, 0, "Mathematics");
                break;
            case 3:
                findMinInSubject(students, NUM_STUDENTS, 1, "Physics");
                break;
            case 4:
                findStudentWithHighestAverage(students, NUM_STUDENTS);
                break;
            case 5:
                printStudentRecord(students, NUM_STUDENTS);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
