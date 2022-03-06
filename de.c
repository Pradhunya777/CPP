#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct student
{
    char na[30];
    char cl[10];
    int rl;
    char date[12];
}s;

FILE *fp;
long sz = sizeof(s);

int main()
{
    int ch;

    while(1)
    {
        system("cls");
        printf("\n\t <<--------------School Students Handling--------------->>");
        printf("\n\t 1.Take Admission");
        printf("\n\t 2.Student Information");
        printf("\n\t 3.Search");
        printf("\n\t 4.Modify");
        printf("\n\t 5.Delete");
        printf("\n\t 6.Sort");
        printf("\n\t 7.Exit");

        printf("\n\t Enter Your Choise = ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 7:
            exit(0);

        case 1:
            input();
            break;
        case 2:
            display();
            break;
        }
        printf("\n\t Press any key to continue...");
        getch();
    }

    return 0;
}

void input()
{

    char mydate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(mydate, "%02d/%02d/%d",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900);
    //printf("%s", myDate);
    strcpy(s.date,mydate);

    fp=fopen("C:\\Users\\LENOVO\\Desktop\\c\\stud2.txt","ab");//Append in binary mode
    printf("\n\t Enter student name = ");
    fflush(stdin); //Input buffer ko  khali krta hai;
    gets(s.na);
    printf("\n\t Enter class = ");
    fflush(stdin);
    gets(s.cl);
    printf("\n\t Enter Rollno = ");
    scanf("%d",&s.rl);
    fwrite(&s, sz, 1, fp);
    printf("\n\t Record Saved Successfully...");
    fclose(fp);
}

void display(){
    system("cls");
    printf("\n\t <<----Student Information is---->>");
    printf("\n\n %-30s %-20s %-10s %s\n", "name", "class", "roll", "date");
    fp=fopen("C:\\Users\\LENOVO\\Desktop\\c\\stud2.txt","rb");//read in binary mode
    while(fread(&s, sz, 1, fp) == 1)
    {
         printf("%-30s %-20s %-10s %s\n", s.na, s.cl, s.rl, s.date);
    }
    fclose(fp);
}
