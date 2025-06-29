#include <stdio.h>
#include <string.h>
#define mx 100

struct Student{
    char name[51];
    int roll;
    double cgpa;
};

struct Student list[mx];
int cnt = 0;

int rollCheck(int roll) {
    for(int i = 0; i < cnt; i++) {
        if(list[i].roll == roll) return 0;
    }
    return 1;
}

void add() {
    if(cnt == mx) {
        printf("The Student List is Full\n");
        return;
    }

    struct Student temp;
    printf("Enter a Name of Student Without Space: ");
    scanf("%s", temp.name);
    printf("Enter Roll of the Student: ");
    scanf("%d", &temp.roll);

    if(!rollCheck(temp.roll)) {
        printf("Roll number already exists!\n");
        return;
    }

    printf("Enter CGPA of the Student: ");
    scanf("%lf", &temp.cgpa);

    int pos = cnt;
    for(int i = 0; i < cnt; i++) {
        if(strcmp(temp.name, list[i].name) < 0) {
            pos = i;
            break;
        }
    }

    for(int i = cnt; i > pos; i--) {
        list[i] = list[i-1];
    }
    list[pos] = temp;
    cnt++;
    printf("Student Added Successfully\n");
}

void del() {
    int roll, found = 0;
    printf("Enter the Roll of Student to remove: ");
    scanf("%d", &roll);

    for(int i = 0; i < cnt; i++) {
        if(list[i].roll == roll) {
            list[i] = list[cnt-1];
            cnt--;
            printf("Student Data Deleted Successfully\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("No Student Found with that Roll\n");
    }
}

void allStu() {
    if(cnt == 0) {
        printf("The Student List is Empty\n");
        return;
    }

    for(int i = 0; i < cnt; i++) {
        printf("%d. %s | Roll: %d | CGPA: %.2lf\n", i+1, list[i].name, list[i].roll, list[i].cgpa);
    }
}

void countStudents() {
    printf("Total Number of Students: %d\n", cnt);
}


void update() {
    int roll, found = 0;
    printf("Enter roll to update: ");
    scanf("%d", &roll);

    for(int i = 0; i < cnt; i++) {
        if(list[i].roll == roll) {
            int ch;
            printf("1. Update Name\n2. Update Roll\n3. Update CGPA\nEnter choice: ");
            scanf("%d", &ch);

            if(ch == 1){
                printf("Enter new name: ");
                scanf("%s", list[i].name);
            } 
            else if(ch == 2){
                int newRoll;
                printf("Enter New Roll: ");
                scanf("%d", &newRoll);
                if(!rollCheck(newRoll)) {
                    printf("Roll Number Already Exists!\n");
                    return;
                }
                list[i].roll = newRoll;
            } 
            else if(ch == 3){
                printf("Enter New CGPA: ");
                scanf("%lf", &list[i].cgpa);
            } 
            else{
                printf("Invalid Choice!\n");
                return;
            }

            printf("Student Updated Successfully\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("No Student Found With That Roll\n");
    }
}


void findRoll() {
    int roll;
    printf("Enter Roll to Search: ");
    scanf("%d", &roll);

    for(int i = 0; i < cnt; i++) {
        if(list[i].roll == roll) {
            printf("Result: %s | Roll: %d | CGPA: %.2lf\n", list[i].name, list[i].roll, list[i].cgpa);
            return;
        }
    }
    printf("No Student Found With That Roll\n");
}

void findName() {
    char s[51];
    printf("Enter a Name to Search: ");
    scanf("%s", s);

    for(int i = 0; i < cnt; i++) {
        if(strcmp(list[i].name, s) == 0) {
            printf("Result: %s | Roll: %d | CGPA: %.2lf\n", list[i].name, list[i].roll, list[i].cgpa);
            return;
        }
    }
    printf("No Student Found With That Name\n");
}

int main() {
    printf("\t\t\tStudent Management System (100 Students)\n");
    printf("Prepared by: Mir Yeasir Abrar\n");
    printf("Batch: 98(1st Shift) -- Roll: 35\n\n");

    int n;
    while(1) {
        printf("\n1: Add Student\n2: Delete Student\n3: Find by Name\n4: Find by Roll\n5: Show All Students\n6: Update Student\n7: Count Students\n8: Exit\n\nEnter a choice: ");
        scanf("%d", &n);

        if(n == 1) add();
        else if(n == 2) del();
        else if(n == 3) findName();
        else if(n == 4) findRoll();
        else if(n == 5) allStu();
        else if(n == 6) update();
        else if(n == 7) countStudents();
        else if(n == 8) break;
        else printf("Enter a Number Between 1-8\n");
    }
    return 0;
}