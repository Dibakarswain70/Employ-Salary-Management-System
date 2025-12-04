#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

void calculateGrossSalary(struct Employee *e) {
    e->grossSalary = e->basicSalary + e->hra + e->da;
}

void addEmployee() {
    struct Employee e;
    FILE *fp = fopen("employee.dat", "ab");
    if (!fp) {
        printf("\nError opening file!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Basic Salary: ");
    scanf("%f", &e.basicSalary);
    printf("Enter HRA: ");
    scanf("%f", &e.hra);
    printf("Enter DA: ");
    scanf("%f", &e.da);

    calculateGrossSalary(&e);

    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);

    printf("\nEmployee added successfully!\n");
}

void displayEmployees() {
    struct Employee e;
    FILE *fp = fopen("employee.dat", "rb");
    if (!fp) {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n------ Employee Salary Records ------\n");
    while (fread(&e, sizeof(e), 1, fp)) {
        printf("\nID: %d", e.id);
        printf("\nName: %s", e.name);
        printf("\nBasic Salary: %.2f", e.basicSalary);
        printf("\nHRA: %.2f", e.hra);
        printf("\nDA: %.2f", e.da);
        printf("\nGross Salary: %.2f", e.grossSalary);
        printf("\n-----------------------------------\n");
    }

    fclose(fp);
}

void searchEmployee() {
    int id, found = 0;
    struct Employee e;
    FILE *fp = fopen("employee.dat", "rb");
    if (!fp) {
        printf("\nNo records available!\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id == id) {
            found = 1;
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", e.id);
            printf("Name: %s\n", e.name);
            printf("Basic Salary: %.2f\n", e.basicSalary);
            printf("HRA: %.2f\n", e.hra);
            printf("DA: %.2f\n", e.da);
            printf("Gross Salary: %.2f\n", e.grossSalary);
            break;
        }
    }

    if (!found)
        printf("\nEmployee not found!\n");

    fclose(fp);
}

void deleteEmployee() {
    int id, found = 0;
    struct Employee e;

    FILE *fp = fopen("employee.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp) {
        printf("\nNo records to delete!\n");
        return;
    }

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id == id) {
            found = 1;
            continue; // skip writing the matched record
        }
        fwrite(&e, sizeof(e), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found)
        printf("\nEmployee deleted successfully!\n");
    else
        printf("\nEmployee ID not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n========== Employee Salary Management System ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
