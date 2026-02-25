#include <stdio.h>
#include <string.h>

/*
---------------------------------------------------------
Project Title : Student Record Management System
Developed By  : Vaidangi Gadhiya
Technology    : C Programming
Concepts Used : Structure, Functions, Arrays, Loops,
                Conditional Statements, Switch Case
Description   : This program manages student records
                including adding, displaying and searching
                student details.
---------------------------------------------------------
*/

struct Student {
    int rollNo;
    char name[50];
    float marks1, marks2, marks3;
    float total, percentage;
};

struct Student students[100];
int count = 0;


void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Marks of 3 Subjects: ");
    scanf("%f %f %f",
          &students[count].marks1,
          &students[count].marks2,
          &students[count].marks3);

    students[count].total =
        students[count].marks1 +
        students[count].marks2 +
        students[count].marks3;

    students[count].percentage =
        students[count].total / 3;

    count++;

    printf("\nStudent Record Added Successfully!\n");
}


void displayStudents() {
    if (count == 0) {
        printf("\nNo Records Found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n-----------------------------");
        printf("\nRoll No   : %d", students[i].rollNo);
        printf("\nName      : %s", students[i].name);
        printf("\nTotal     : %.2f", students[i].total);
        printf("\nPercentage: %.2f%%", students[i].percentage);
        printf("\n-----------------------------\n");
    }
}


void searchStudent() {
    int roll, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found!");
            printf("\nName       : %s", students[i].name);
            printf("\nPercentage : %.2f%%\n",
                   students[i].percentage);
            found = 1;
        }
    }

    if (!found) {
        printf("\nStudent Not Found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n====== Student Management System ======");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 4);

    return 0;
}
