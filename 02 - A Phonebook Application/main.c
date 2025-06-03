#include <stdio.h>
#include <string.h>
#define mx 100

struct PhoneBook{
    char name[51];
    char phone[11];
};

struct PhoneBook list[mx]; 
int cnt = 0;

void add(){
    printf("Enter a name without space\n");
    if(cnt == mx){
        printf("Maximum Number of contact fulfilled\n");
        return;
    }
    struct PhoneBook temp;
    printf("Name: ");
    scanf("%s", temp.name);
    printf("Phone: ");
    scanf("%s", temp.phone);

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
    printf("New Contact Added Successfully \n");
}

void del(){
    char c[51];
    int found = 0;
    printf("Enter the Name to remove: ");
    scanf("%s", c);

    for(int i = 0; i < cnt; i++){
        if(strcmp(list[i].name, c) == 0){
            list[i] = list[cnt - 1];
            cnt--;
            printf("Contact Deleted Successfully\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("No contact found with that name\n");
    }
}

void findNum(){
    char s[21];
    printf("Enter number to search: ");
    scanf("%s", s);
    for(int i = 0; i < cnt; i++){
        if(strcmp(list[i].phone, s) == 0){
            printf("Result: %s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("No contact found with that number\n");
}

void findName(){
    char s[51];
    printf("Enter a name to search: ");
    scanf("%s", s);
    for(int i = 0; i < cnt; i++){
        if(strcmp(list[i].name, s) == 0){
            printf("Result: %s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("No contact found with that name\n");
}


void allCntk(){
    if(cnt == 0){
        printf("The contact list is empty\n");
        return;
    }
    for(int i = 0; i < cnt; i++){
        printf("%d. %s : %s\n", i+1, list[i].name, list[i].phone);
    }
}

int main(){

    printf("\t\t\tPhone Book Appliction (100 Contacts)\n");
    printf("Prepared by: Mir Yeasir Abrar\n");
    printf("Batch: 98(1st Shift) -- Roll: 35\n\n");

    int n;
    for(;;){
        printf("\n1: Add a New Contact \n2: Delete a Contact \n3: Find Contact by Name \n4: Find Contact by Number \n5: Show the Full List of Contact \n6:Exit \n\nEnter a choice: ");
        scanf("%d", &n);

        if(n == 1){
            add();
        }
        else if(n == 2){
            del();
        }
        else if(n == 3){
            findName();
        }
        else if(n == 4){
            findNum();
        }
        else if(n == 5){
            allCntk();
        }
        else if(n == 6){
            break;
        }
        else{
            printf("Enter a number between 1-6\n");
        }
    }
    return 0;
}
