#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct student{
    char ID[15];
    char name[20];
    char add[20];
    char parname[20];
    int Class;
    long unsigned int phone_no;
};

struct student stu;

///This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
    // WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawRectangle(){
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

}

void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            printf(" ");
        }
    }
    return;
}

void window(){
    //drawRectangle();
   // gotoxy(28,2);
   // SetColor(35);
    printf("STUDENT RECORD SYSTEM");
   // gotoxy(20,3);
    printf("Tribhuvan University, Kathmandu, Nepal");
   // gotoxy(31,4);
    printf("Estd.: 2016 B.S.");
    //gotoxy(25,24);
   // SetColor(17);

}

void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}

void use_pass_field(){
    int x = 15, y = 16;
    int use;
    char pass[10];
    //SetColor(10);
    printf("The database is password protected.");
    printf(" Enter Valid username and password");
    //SetColor(17);
    printf("USERNAME:- ");
    printf("PASSWORD:- ");
    scanf("%d",use);
    get_password(pass);
}

void print_heading(const char st[]){
    //SetColorAndBackground(31,28);
    printf("SRS : %s",st);
    //SetColorAndBackground(17,15);
}

int conf_record(char id[]){
   // left for you
   //it checks whether the entered id for
   //new record is already in the database.
}

void add_student(){
    clearWindow();
    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        printf("ID: ");gets(stu.ID);
        //here you can confirms the ID
        printf("Name: ");gets(stu.name);
        printf("Address: ");gets(stu.add);
        printf("Parent's name: ");gets(stu.parname);
        printf("Class: ");scanf("%d",&stu.Class);
        printf("Phone Number: ");scanf("%ld",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
        printf("The record is sucessfully added");
    }
    //SetColor(28);
    fclose(fp);
    return;
}

void search_student(){
    clearWindow();
    print_heading("Search Record");
    //SetColor(45);
    char s_id[15];
    int isFound = 0;
    printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        printf("The record is Found");
        printf("ID: %s",stu.ID);
        printf("Name: %s",stu.name);
        printf("Address: %s",stu.add);
        printf("Parent's Name: %s",stu.parname);
        printf("Class: %d",stu.Class);
        printf("Phone No: %ld",stu.phone_no);
    }else{
        printf("Sory, No record found in the database");
    }
   // SetColor(28);
    fclose(fp);
    return;
}

void mod_student(){
    clearWindow();
    print_heading("Modify Record");
    //SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(stu.ID);
            printf("Name: ");gets(stu.name);
            printf("Address: ");gets(stu.add);
            printf("Parent's name: ");gets(stu.parname);
            printf("Class: ");scanf("%d",&stu.Class);
            printf("Phone Number: ");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    #include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct student{
    char ID[15];
    char name[20];
    char add[20];
    char parname[20];
    int Class;
    long unsigned int phone_no;
};

struct student stu;

///This will set the forground color for printing in a console window.
/*void SetColor(int ForgC)
{
    // WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}*/

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawRectangle(){
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

}

void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            printf(" ");
        }
    }
    return;
}

void window(){
    //drawRectangle();
   // gotoxy(28,2);
   // SetColor(35);
    printf("STUDENT RECORD SYSTEM");
   // gotoxy(20,3);
    printf("Tribhuvan University, Kathmandu, Nepal");
   // gotoxy(31,4);
    printf("Estd.: 2016 B.S.");
    //gotoxy(25,24);
   // SetColor(17);

}

void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}

void use_pass_field(){
    int x = 15, y = 16;
    int use;
    char pass[10];
    //SetColor(10);
    printf("The database is password protected.");
    printf(" Enter Valid username and password");
    //SetColor(17);
    printf("USERNAME:- ");
    printf("PASSWORD:- ");
    scanf("%d",use);
    get_password(pass);
}

void print_heading(const char st[]){
    //SetColorAndBackground(31,28);
    printf("SRS : %s",st);
    //SetColorAndBackground(17,15);
}

int conf_record(char id[]){
   // left for you
   //it checks whether the entered id for
   //new record is already in the database.
}

void add_student(){
    clearWindow();
    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        printf("ID: ");gets(stu.ID);
        //here you can confirms the ID
        printf("Name: ");gets(stu.name);
        printf("Address: ");gets(stu.add);
        printf("Parent's name: ");gets(stu.parname);
        printf("Class: ");scanf("%d",&stu.Class);
        printf("Phone Number: ");scanf("%ld",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
        printf("The record is sucessfully added");
    }
    //SetColor(28);
    fclose(fp);
    return;
}

void search_student(){
    clearWindow();
    print_heading("Search Record");
    //SetColor(45);
    char s_id[15];
    int isFound = 0;
    printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        printf("The record is Found");
        printf("ID: %s",stu.ID);
        printf("Name: %s",stu.name);
        printf("Address: %s",stu.add);
        printf("Parent's Name: %s",stu.parname);
        printf("Class: %d",stu.Class);
        printf("Phone No: %ld",stu.phone_no);
    }else{
        printf("Sory, No record found in the database");
    }
   // SetColor(28);
    fclose(fp);
    return;
}

void mod_student(){
    clearWindow();
    print_heading("Modify Record");
    //SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(stu.ID);
            printf("Name: ");gets(stu.name);
            printf("Address: ");gets(stu.add);
            printf("Parent's name: ");gets(stu.parname);
            printf("Class: ");scanf("%d",&stu.Class);
            printf("Phone Number: ");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("No Record Found");
    }
    fclose(fp);
    //SetColor(28);
    return;
}

void gen_marksheet(){
    //left for further enhancement
}

void delete_student(){
    clearWindow();
    print_heading("Delete Record");
    //SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    //gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("The record is sucessfully deleted");

    return;
}

void main_window(){
    int choice;

    int x = 2;
    while(1){
        printf("\n\t1. Add Student");
        printf("\n\t2. Search Student");
        printf("\n\t3. Modify Student Record");
        printf("\n\t4. Generate Marksheet");
        printf("\n\t5. Delete Student Record");
        printf("\n\t6. Change password");
        printf("\n\t7. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
                break;
            case 5:
                delete_student();
                break;
            case 6:
                break;
            case 7:
                exit(0);
                break;
            default:
                break;
        }

    }

}

int main(){

   // SetConsoleTitle("Programming-technique.blogspot.com - Student Record System");
    window();
    //use_pass_field();
    main_window();
    return 0;
}



}
    if(!isFound){
        printf("No Record Found");
    }
    fclose(fp);
    //SetColor(28);
    return;
}

void gen_marksheet(){
    //left for further enhancement
}

void delete_student(){
    clearWindow();
    print_heading("Delete Record");
    //SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("The record is sucessfully deleted");

    return;
}

void main_window(){
    int choice;

    int x = 2;
    while(1){
        printf("\n\t1. Add Student");
        printf("\n\t2. Search Student");
        printf("\n\t3. Modify Student Record");
        printf("\n\t4. Generate Marksheet");
        printf("\n\t5. Delete Student Record");
        printf("\n\t6. Change password");
        printf("\n\t7. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
                break;
            case 5:
                delete_student();
                break;
            case 6:
                break;
            case 7:
                exit(0);
                break;
            default:
                break;
        }

    }

}

int main(){

   // SetConsoleTitle("Programming-technique.blogspot.com - Student Record System");
    window();
    //use_pass_field();
    main_window();
    return 0;
}


