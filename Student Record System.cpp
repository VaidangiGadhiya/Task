#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int count = 0;

void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;
    char cont = 'y';

    printf("===== Student Record System =====\n");

    while(cont == 'y' || cont == 'Y') {
        printf("\n--- Menu ---\n");
        printf("1. Add Student\n2. Display All Students\n3. Search Student by Roll\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: 
                printf("Exiting Student Record System. Goodbye!\n");
                return 0;
            default: printf("Invalid choice! Please select 1-4.\n");
        }

        if(choice != 4) {
            printf("\nDo you want to continue? (y/n): ");
            scanf(" %c", &cont);
        }
    }

    return 0;
}

void addStudent() {
    if(count >= MAX) {
        printf("Student list full! Cannot add more.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student Added Successfully!\n");
}

void displayStudents() {
    if(count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("\nRoll: %d\nName: %s\nMarks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void searchStudent() {
    if(count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    int rollNo, found = 0;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &rollNo);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == rollNo) {
            printf("\nStudent Found:\nRoll: %d\nName: %s\nMarks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("No student found with Roll Number %d.\n", rollNo);
    }

}
