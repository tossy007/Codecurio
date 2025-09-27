#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student *students = NULL;  // dynamic array of students
int count = 0;                     // number of students

// Insert Student
void insertStudent(struct Student **student, int *count, int id, char *name, float marks) {
    *student = realloc(*student, (*count + 1) * sizeof(struct Student));
    if (*student == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    (*student)[*count].id = id;
    strcpy((*student)[*count].name, name);
    (*student)[*count].marks = marks;

    (*count)++;
}

// Display Student Info List
void displaystudent(struct Student *student, int count) {
    printf("\n----- Student Records -----\n");

    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("ID: %d | NAME: %s | MARKS: %.2f\n",
               student[i].id, student[i].name, student[i].marks);
    }
}

// Delete Student by ID
void deleteStudent(struct Student *student, int *count, int id) {
    int found = -1;

    for (int i = 0; i < *count; i++) {
        if (student[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < *count - 1; i++) {
            student[i] = student[i + 1];
        }
        (*count)--;
        printf("Deleted ID: %d\n", id);
    } else {
        printf("Student not found!!!\n");
    }
}

int main() {
    float marks;
    char name[50];
    int choices;
    int id;

    do {
        printf("\n**** MINI DATABASE ****\n");
        printf("1. Register Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choices);

        switch (choices) {
            case 1:
                printf("\nEnter Your ID: ");
                scanf("%d", &id);

                printf("Enter Your Name:\n ");
                scanf(" %s", name);

                printf("Enter Your Marks: \n");
                scanf("%f", &marks);

                insertStudent(&students, &count, id, name, marks);
                break;

            case 2:
                displaystudent(students, count);
                break;

            case 3:
                printf("\nEnter ID to Delete: ");
                scanf("%d", &id);
                deleteStudent(students, &count, id);
                break;

            case 4:
                printf("\nExited Successfully !!!\n");
                getchar();
                break;

            default:
                printf("Enter Valid Option\n");
        }

    } while (choices != 4);

    free(students);
}
