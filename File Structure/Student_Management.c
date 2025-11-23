#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char name[50];
    int roll_no;
    char course[50];
    float grade;
} Student;

void add_record(void) {
    Student s;
    char fname[50], lname[50];
    printf("Enter Student ID: ");
    scanf("%d", &s.id);   
    printf("Enter Student First Name: ");
    scanf("%s", fname);
    printf("Enter Student Last Name: ");
    scanf("%s", lname);
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    printf("Enter Course: ");
    scanf("%s", s.course);
    printf("Enter Grade: ");
    scanf("%f", &s.grade);
    FILE *file = fopen("students.text", "a");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%d %s %s %d %s %.2f\n", s.id, fname, lname, s.roll_no, s.course, s.grade);
    fclose(file);
    printf("Record added successfully!\n");
}

void display_records(void) {
    Student s;
    FILE *file = fopen("students.text", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Student Records:\n");
    printf("ID\tName\t\tRoll No\tCourse\tGrade\n");
    char fname[50], lname[50];

    while(fscanf(file, "%d %49s %49s %d %49s %f", &s.id, fname, lname, &s.roll_no, s.course, &s.grade) == 6) {
        snprintf(s.name, sizeof(s.name), "%s %s", fname, lname);
        printf("%d\t%s\t%d\t%s\t%.2f\n", s.id, s.name, s.roll_no, s.course, s.grade);
    }
    fclose(file);
}

void search_record(void) {
    FILE *file = fopen("students.text", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    Student s;
    char fname[50], lname[50];
    int found = 0;  
    while(fscanf(file, "%d %49s %49s %d %49s %f", &s.id, fname, lname, &s.roll_no, s.course, &s.grade) == 6) {
        if(s.id == id) {
            snprintf(s.name, sizeof(s.name), "%s %s", fname, lname);
            printf("Record Found:\n");
            printf("ID: %d\nName: %s\nRoll No: %d\nCourse: %s\nGrade: %.2f\n", s.id, s.name, s.roll_no, s.course, s.grade);
            found = 1;
            break;
        }
    }
}

void delete_record(void) {
    FILE *file = fopen("students.text", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    FILE *temp = fopen("temp.text", "w");
    if(temp == NULL) {
        fclose(file);
        printf("Error opening temporary file!\n");
        return;
    }
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    Student s;
    char fname[50], lname[50];
    int found = 0;
    while(fscanf(file, "%d %49s %49s %d %49s %f", &s.id, fname, lname, &s.roll_no, s.course, &s.grade) == 6) {
        if(s.id == id) {
            found = 1;
            continue;
        }
        fprintf(temp, "%d %s %s %d %s %.2f\n", s.id, fname, lname, s.roll_no, s.course, s.grade);
    }
    fclose(file);
    fclose(temp);
    if(found) {
        remove("students.text");
        rename("temp.text", "students.text");
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.text");
        printf("Record not found!\n");
    }
}

void update_record(void) {
    FILE *file = fopen("students.text", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    FILE *temp = fopen("temp.text", "w");
    if(temp == NULL) {
        fclose(file);
        printf("Error opening temporary file!\n");
        return;
    }
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    Student s;
    char fname[50], lname[50];
    int updated = 0;
    while(fscanf(file, "%d %49s %49s %d %49s %f", &s.id, fname, lname, &s.roll_no, s.course, &s.grade) == 6) {
        if(s.id == id && !updated) {
            printf("Enter new details:\n");
            printf("Enter Student First Name: ");
            scanf("%s", fname);
            printf("Enter Student Last Name: ");
            scanf("%s", lname);
            printf("Enter Roll Number: ");
            scanf("%d", &s.roll_no);
            printf("Enter Course: ");
            scanf("%s", s.course);
            printf("Enter Grade: ");
            scanf("%f", &s.grade);
            fprintf(temp, "%d %s %s %d %s %.2f\n", s.id, fname, lname, s.roll_no, s.course, s.grade);
            printf("Record updated successfully!\n");
            updated = 1;
        } else {
            fprintf(temp, "%d %s %s %d %s %.2f\n", s.id, fname, lname, s.roll_no, s.course, s.grade);
        }
    }
    fclose(file);
    fclose(temp);
    if(updated) {
        remove("students.text");
        rename("temp.text", "students.text");
    } else {
        remove("temp.text");
        printf("Record not found!\n");
    }
}
int main() {
    int choice;
    while(1) {
        printf("\nStudent Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Update Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                update_record();
                break;
            case 6: 
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}