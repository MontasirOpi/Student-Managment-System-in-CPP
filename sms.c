#include <stdio.h>

// Constants
#define MAX_STUDENTS 20
#define MAX_STRING_LENGTH 100

// Student structure
typedef struct {
    char name[MAX_STRING_LENGTH];
    char roll[MAX_STRING_LENGTH];
    char semester[MAX_STRING_LENGTH];
    char technology[MAX_STRING_LENGTH];
    char phoneNumber[MAX_STRING_LENGTH];
} Student;

// Global variables
Student students[MAX_STUDENTS];
int totalStudents = 0;

// Function declarations
int isEqual(const char* str1, const char* str2);
void enter();
void show();
void searchrecord();
void update();
void deleterecord();

int main() {
    int value;
    while (1) {
        printf("Press 1 to enter data\n");
        printf("Press 2 to show data\n");
        printf("Press 3 to search data\n");
        printf("Press 4 to update data\n");
        printf("Press 5 to delete data\n");
        printf("Press 6 to exit\n");
        scanf("%d", &value);

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                searchrecord();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid keyword\n");
                break;
        }
    }

    return 0;
}

int isEqual(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void enter() {
    int choice;
    printf("How many students do you want to enter?\n");
    scanf("%d", &choice);

    if (totalStudents + choice <= MAX_STUDENTS) {
        for (int i = totalStudents; i < totalStudents + choice; i++) {
            printf("\nEnter data of student %d:\n\n", i + 1);
            printf("Enter name: ");
            scanf("%s", students[i].name);
            printf("Enter roll: ");
            scanf("%s", students[i].roll);
            printf("Enter semester: ");
            scanf("%s", students[i].semester);
            printf("Enter technology: ");
            scanf("%s", students[i].technology);
            printf("Enter phoneNumber: ");
            scanf("%s", students[i].phoneNumber);
        }
        totalStudents += choice;
    } else {
        printf("Maximum student capacity reached\n");
    }
}

void show() {
    for (int i = 0; i < totalStudents; i++) {
        printf("Data of student %d:\n\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll: %s\n", students[i].roll);
        printf("Semester: %s\n", students[i].semester);
        printf("Technology: %s\n", students[i].technology);
        printf("PhoneNumber: %s\n", students[i].phoneNumber);
    }
}

void searchrecord() {
    char rollno[MAX_STRING_LENGTH];
    printf("Enter the roll number of the student you want to search: ");
    scanf("%s", rollno);
    for (int i = 0; i < totalStudents; i++) {
        if (isEqual(rollno, students[i].roll)) {
            printf("Data of student %d:\n\n", i + 1);
            printf("Name: %s\n", students[i].name);
            printf("Roll: %s\n", students[i].roll);
            printf("Semester: %s\n", students[i].semester);
            printf("Technology: %s\n", students[i].technology);
            printf("PhoneNumber: %s\n", students[i].phoneNumber);
        }
    }
}

void update() {
    char rollno[MAX_STRING_LENGTH];
    printf("Enter the roll number of the student you want to update: ");
    scanf("%s", rollno);
    for (int i = 0; i < totalStudents; i++) {
        if (isEqual(rollno, students[i].roll)) {
            printf("Previous Data:\n\n");
            printf("Data of student %d:\n\n", i + 1);
            printf("Name: %s\n", students[i].name);
            printf("Roll: %s\n", students[i].roll);
            printf("Semester: %s\n", students[i].semester);
            printf("Technology: %s\n", students[i].technology);
            printf("PhoneNumber: %s\n", students[i].phoneNumber);

            printf("\nEnter new data:\n");
            printf("Enter Name: ");
            scanf("%s", students[i].name);
            printf("Enter roll: ");
            scanf("%s", students[i].roll);
            printf("Enter semester: ");
            scanf("%s", students[i].semester);
            printf("Enter technology: ");
            scanf("%s", students[i].technology);
            printf("Enter phoneNumber: ");
            scanf("%s", students[i].phoneNumber);
        }
    }
}

void deleterecord() {
    int a;
    printf("Press 1 to delete the full record\n");
    printf("Press 2 to delete a specific record\n");
    scanf("%d", &a);

    if (a == 1) {
        totalStudents = 0;
        printf("All records have been deleted\n");
    } else if (a == 2) {
        char rollno[MAX_STRING_LENGTH];
        printf("Enter the roll number you want to delete: ");
        scanf("%s", rollno);
        for (int i = 0; i < totalStudents; i++) {
            if (isEqual(rollno, students[i].roll)) {
                for (int j = i; j < totalStudents - 1; j++) {
                    strcpy(students[j].name, students[j + 1].name);
                    strcpy(students[j].roll, students[j + 1].roll);
                    strcpy(students[j].semester, students[j + 1].semester);
                    strcpy(students[j].technology, students[j + 1].technology);
                    strcpy(students[j].phoneNumber, students[j + 1].phoneNumber);
                }
                totalStudents--;
                printf("The required record has been deleted\n");
            }
        }
    }
}
