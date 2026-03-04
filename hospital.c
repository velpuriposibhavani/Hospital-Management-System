#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

void addPatient() {
    FILE *fp = fopen("patients.txt", "a");
    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    scanf("%s", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    scanf("%s", p.disease);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("Patient record added successfully!\n");
}

void displayPatients() {
    FILE *fp = fopen("patients.txt", "r");
    struct Patient p;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Patient Records ---\n");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d", p.id);
        printf("\nName: %s", p.name);
        printf("\nAge: %d", p.age);
        printf("\nDisease: %s\n", p.disease);
    }

    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen("patients.txt", "r");
    struct Patient p;
    int id, found = 0;

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\nPatient Found\n");
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Disease: %s\n", p.disease);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---");
        printf("\n1. Add Patient");
        printf("\n2. Display Patients");
        printf("\n3. Search Patient");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addPatient();
            break;

        case 2:
            displayPatients();
            break;

        case 3:
            searchPatient();
            break;

        case 4:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}