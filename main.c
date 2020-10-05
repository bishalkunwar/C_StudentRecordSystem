#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void add();
void details();
void search();
void edit();
void option();
void to_delete();

struct student_records{
    char name[20];
    char faculty[20];
    char sem[20];
    char phone[20];
    char email[20];
    char f_number[20];
};

int main(){
    char ch='y';
    while(ch=='y'){
    option();
    printf("\n___________________________________________________________\n");
    printf("\n\nMore turn/ more execution?? (Y/N)");
    getch();
    scanf("%c",&ch);
    option();

    }
    printf("thank you!!!");

    return 0;
}

void option() {
    int choice;
    printf("welcome to student record system\n\n");
    printf("choose the following options\n\n1:Add Student\n2:Students Details\n3:update Student details\n4:Search student records\n 5:to do delete the file\n");
    printf("Enter your choice :\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            details();
            break;
        case 3:
            edit();
            break;
        case 4:
            search();
            break;
        case 5:
            to_delete();
            break;
        default:
            printf("invalid choice \n try again the valid choice");
            break;
    }

}

void add(){
    FILE *pj;
    char b[50];
    char path[] = "E:\\cbasic\\CProject\\CProject\\StudentData\\";
    struct student_records a;
    gets(a.name);
    printf("enter the details:\n");
    printf("name:");
    gets(a.name);
    strcpy(b, a.name);
    strcat(b,".txt");
    strcat(path,b);
    pj=fopen(path,"w");
    printf("faculty:");
    gets(a.faculty);
    printf("semester:");
    gets(a.sem);
    printf("phone:");
    gets(a.phone);
    printf("email:");
    gets(a.email);
    printf("father number:");
    gets(a.f_number);
    printf("your record has been added");
    fprintf(pj,"Name:%s\nFaculty:%s\nSemester:%s\nPhone:%s\nEmail:%s\nFather No.:%s",a.name,a.faculty,a.sem,a.phone,a.email,a.f_number);
    fclose(pj);

}

void details(){
    FILE *pj;
    char ch;
    char b[50];
    char c[50];
    char path[] = "E:\\cbasic\\CProject\\CProject\\StudentData\\";
    struct student_records a;
    printf("enter your name\n");
    printf("name:\t");
    gets(c);
    gets(c);
    strcpy(b, c);
    strcat(b, ".txt");
    strcat(path, b);
    pj = fopen(path, "r");
    if (pj == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of %s file are:\n", b);

    while ((ch = fgetc(pj)) != EOF)
        printf("%c", ch);
    fclose(pj);

}


void search(){
    FILE *pj;
    char ch;
    char b[50];
    char c[50];
    char path[] = "E:\\cbasic\\CProject\\CProject\\StudentData\\";
    struct student_records a;
    printf("enter your name\n");
    printf("name:\t");
    gets(c);
    gets(c);
    strcpy(b, c);
    strcat(b, ".txt");
    strcat(path, b);
    pj = fopen(path, "r");
    if (pj == NULL) {
        printf("Sorry!!\nData not found.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(pj)) != EOF)
        printf("%c", ch);
    fclose(pj);
}

void edit(){
    FILE *pj;
    char name[50];
    int status=0;
    char path[] = "E:\\cbasic\\CProject\\CProject\\StudentData\\";
    struct student_records a,d;
    printf("enter your name\n");
    printf("name:\t");
    gets(name);
    gets(name);
    strcat(name, ".txt");
    strcat(path,name);
    status=remove(path);
    if(status==0){
        printf("Press Enter to update details");
        add();
        printf("Successfully update");
    } else{
        printf("Error while updating file");
    }
    fclose(pj);
}

void to_delete()
{
    FILE *pj;
    char name[50];
    int status=0;
    char path[] = "E:\\cbasic\\CProject\\CProject\\StudentData\\";
    struct student_records a,d;
    printf("enter your name\n");
    printf("name:\t");
    gets(name);
    gets(name);
    strcat(name, ".txt");
    strcat(path,name);
    status=remove(path);
    if(status==0){
    printf("successfully removed");
    }
    else
    {
    printf("error on deleting");
    }
    fclose(pj);
}
