#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int count=0;				      //CodeWithC.com Student Record System
void main()
{
    int a,i,ch=1,rec;
    FILE *fp;
    struct student
    {
        char name[20],fname[20];
        int age,rollno;
    } s[100];
    //clrscr();
    do
    {
        printf("1.create record \n2.list record \n3.add another record \n4.exit\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            ch=1;
            fp=fopen("st3.txt","w+");
            if (fp==NULL)
            {
                printf("cannot open file\n");
                exit(1);
            }
            printf("enter name age and roll number of the student\n");
            for(i=0; ch==1; i++)
            {
                scanf("%s %d %d",&s[i].name,&s[i].age,&s[i].rollno);
                fprintf(fp,"%s \t%d\t %d\t",s[i].name,s[i].age,s[i].rollno);
                count=count+1;
//fwrite(&s,rec,1,fp);
                printf("press 1 to add another reocrd and 0 to exit\n");
                scanf("%d",&ch);
            }
            break;
        case 2:
            fp=fopen("st3.txt","r+");
            if (fp==NULL)
            {
                printf("cannot open file\n");
                exit(1);
            }
            printf("name \tage \t roll number \t\n\n");
            for(i=0; i<count; i++)
            {
                fscanf(fp,"%s %d %d",&s[i].name,&s[i].age,&s[i].rollno);
                printf("%s\t%d\t%d\t\n\n",s[i].name,s[i].age,s[i].rollno);
                fprintf(fp,"%s \t%d \t%d \t",s[i].name,s[i].age,s[i].rollno);
            }
            break;
        case 3:
            fp=fopen("st3.txt","a");
            if (fp==NULL)
            {
                printf("cannot open file\n");
                exit(1);
            }
            ch=1;
            for(i=count; ch==1; i++)
            {
                scanf("%s %d %d",&s[i].name,&s[i].age,&s[i].rollno);
                fprintf(fp,"%s\t%d\t %d\t",s[i].name,s[i].age,s[i].rollno);
                printf("press 1 to add another reocrd and 0 to exit\n");
                scanf("%d",&ch);
                count=count+1;
            }
            break;
        case 4:
            exit(1);
        }
    }
    while (a!=4);
    fclose (fp);
    getch();
}
