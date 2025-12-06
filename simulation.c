#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRE_FILE  "credentials.txt"

char currentUser[50];
char currentRole[20];

/* -------------------- LINKED LIST STRUCT -------------------- */

typedef struct Student {
    int roll;
    char name[50];
    float mark;
    struct Student *next;
} Student;

Student *head = NULL;

/* -------------------- LOGIN SYSTEM -------------------- */

int login() {
    char u[50], p[50], r[20];
    char inUser[50], inPass[50];

    printf("USERNAME: ");
    scanf("%s", inUser);
    printf("PASSWORD: ");
    scanf("%s", inPass);

    FILE *fp = fopen(CRE_FILE, "r");
    if (!fp) {
        printf("Credential file missing!\n");
        return 0;
    }

    while (fscanf(fp, "%s %s %s", u, p, r) == 3) {
        if (strcmp(inUser, u) == 0 && strcmp(inPass, p) == 0) {
            strcpy(currentUser, u);
            strcpy(currentRole, r);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

/* -------------------- LINKED LIST OPERATIONS -------------------- */

void addStudent() {
    Student *newNode = (Student *)malloc(sizeof(Student));

    printf("Roll: ");
    scanf("%d", &newNode->roll);
    printf("Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Mark: ");
    scanf("%f", &newNode->mark);

    newNode->next = head;
    head = newNode;

    printf("Student added!\n");
}

void displayStudents() {
    Student *temp = head;

    if (!temp) {
        printf("No records!\n");
        return;
    }

    printf("Roll\tName\tMark\n");
    printf("----\t----\t----\n");

    while (temp) {
        printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->mark);
        temp = temp->next;
    }
}

void searchStudent() {
    int find;
    printf("Enter roll to search: ");
    scanf("%d", &find);

    Student *temp = head;

    while (temp) {
        if (temp->roll == find) {
            printf("Found: %d %s %.2f\n", temp->roll, temp->name, temp->mark);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found!\n");
}

void deleteStudent() {
    int delRoll;
    printf("Enter roll to delete: ");
    scanf("%d", &delRoll);

    Student *temp = head, *prev = NULL;

    while (temp) {
        if (temp->roll == delRoll) {
            if (prev) prev->next = temp->next;
            else head = temp->next;

            free(temp);
            printf("Student deleted!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Roll not found!\n");
}

void updateStudent() {
    int updateRoll;
    printf("Enter roll to update: ");
    scanf("%d", &updateRoll);

    Student *temp = head;

    while (temp) {
        if (temp->roll == updateRoll) {
            printf("New Name: ");
            scanf(" %[^\n]", temp->name);
            printf("New Mark: ");
            scanf("%f", &temp->mark);

            printf("Student updated!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Roll not found!\n");
}

/* -------------------- MENUS -------------------- */

void adminMenu() {
    int c;
    while (1) {
        printf("\nADMIN MENU\n");
        printf("1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Logout\n");
        scanf("%d",&c);

        if      (c==1) addStudent();
        else if (c==2) displayStudents();
        else if (c==3) searchStudent();
        else if (c==4) updateStudent();
        else if (c==5) deleteStudent();
        else return;
    }
}

void staffMenu() {
    int c;
    while (1) {
        printf("\nSTAFF MENU\n");
        printf("1.Add\n2.Display\n3.Search\n4.Update\n5.Logout\n");
        scanf("%d",&c);

        if      (c==1) addStudent();
        else if (c==2) displayStudents();
        else if (c==3) searchStudent();
        else if (c==4) updateStudent();
        else return;
    }
}

void guestMenu() {
    int c;
    while (1) {
        printf("\nGUEST MENU\n");
        printf("1.Display\n2.Logout\n");
        scanf("%d",&c);

        if      (c==1) displayStudents();
        else return;
    }
}

void userMenu() {
    int c;
    while (1) {
        printf("\nUSER MENU\n");
        printf("1.Display\n2.Search\n3.Logout\n");
        scanf("%d",&c);

        if      (c==1) displayStudents();
        else if (c==2) searchStudent();
        else return;
    }
}

/* -------------------- MAIN -------------------- */

int main() {
    if (!login()) {
        printf("Invalid login!\n");
        return 0;
    }

    printf("Logged in as: %s\n", currentRole);

    if      (strcmp(currentRole,"admin")==0) adminMenu();
    else if (strcmp(currentRole,"staff")==0) staffMenu();
    else if (strcmp(currentRole,"user")==0) userMenu();
    else guestMenu();

    return 0;
}
