

// Project for student management system

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int i = 0;

// Structure to store the student
struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid;
} st[55];

// Function to add the student
void add_student()
{

    printf("\n\t Add the Students Details\n");
    printf("\n\t-------------------------\n");
    printf("\n\t Enter the first name of student\n");
    scanf("%s", st[i].fname);
    printf("\n\tEnter the last name of student\n");
    scanf("%s", st[i].lname);
    printf("\n\tEnter the Roll Number\n");
    scanf("%d", &st[i].roll);
    printf("\n\tEnter the CGPA you obtained\n");
    scanf("%f", &st[i].cgpa);
    printf("Enter the course ID \n");
    scanf("%d", &st[i].cid);

    i = i + 1;
}

// Function to find the student
// by the roll number
void find_rl()
{
    int x;
    printf("\n\tEnter the Roll Number of the student\n");
    scanf("%d", &x);
    for (int j = 1; j <= i; j++) {
        if (x == st[i].roll) {
            printf("\n\t The Students Details are\n");
            printf("\n\t The First name is %s\n",
            st[i].fname);
            printf("\n\t The Last name is %s\n",
            st[i].lname);
            printf("\n\t The CGPA is %f\n",
            st[i].cgpa);
            printf("\n\tThe course ID are %d\n",
            st[i].cid);
        }

        break;
    }
}

// Function to find the student
// by the first name
void find_fn()
{
    char a[50];
    printf("\n\t Enter the First Name of the student\n");
    scanf("%s", a);
    int c = 0;

    for (int j = 1; j <= i; j++) {
        if (!strcmp(st[j].fname, a)) {

            printf(
                "\t The Students Details are\n");
            printf(
                "\t The First name is %s\n",
                st[i].fname);
            printf(
                "\t The Last name is %s\n",
                st[i].lname);
            printf(
                "\tThe Roll Number is %d\n ",
                st[i].roll);
            printf(
                "\t The CGPA is %f\n",
                st[i].cgpa);
            printf(
                "\t Enter the course ID of \n");

                printf(
                    "\t The course ID are %d\n",
                    st[i].cid);

            c = 1;
        }
        else
            printf(
                "\n\t The First Name not Found\n");
    }
}




// Function to print the total
// number of students
void tot_s()
{
    printf("\t The total number of"
           " Student is %d\n",
           i);
    printf("\t you can have a "
           "max of 50 students\n");
    printf("\t you can have %d "
           "more students\n",
           50 - i);
}

// Function to delete a student
// by the roll number
void del_s()
{
    int a;
    printf("\n\t Enter the Roll Number"
           " which you want "
           "to delete\n");
    scanf("%d", &a);
    for (int j = 1; j <= i; j++) {
        if (a == st[j].roll) {
            for (int k = j; k < 49; k++)
                st[k] = st[k + 1];
            i--;
        }
    }
    printf("\n\t The Roll Number"
           " is removed Successfully\n");
}

// Function to update a students data
void up_s()
{
 int x;
    printf("\n\t Enter the roll number to update the entry : ");

    scanf("%d", &x);
    for (int j = 0; j <= i; j++) {
        if (x == st[i].roll) {
            printf("\t 1. first name\n"
                   "\t 2. last name\n"
                   "\t 3. roll no.\n"
                   "\t 4. CGPA\n"
                   "\t 5. course\n");
            int z;
            printf("\n\t Enter the number which field you want to update = ");
            scanf("%d", &z);
            switch (z) {
            case 1:
                printf("\t Enter the new "
                       "first name : \n");
                scanf("%s", st[i].fname);
                break;
            case 2:
                printf("\t Enter the new "
                       "last name : \n");
                scanf("%s", st[i].lname);
                break;
            case 3:
                printf("\t Enter the new "
                       "roll numnber : \n");
                scanf("%d", &st[i].roll);
                break;
            case 4:
                printf("\t Enter the new CGPA : \n");
                scanf("%f", &st[i].cgpa);
                break;
            case 5:
                printf("Enter the new course \n");
                scanf(
                    "%d", &st[i].cid);
                break;
            }
            printf("UPDATED SUCCESSFULLY.\n");
        }
    }
}

// Driver code
void main()

{
    int choice, count;
    while (i = 1) {
            printf("********Welcome to Student Management Services**************\n");
        printf("\n\t **********TASKS*********\n");
        printf("\t 1. Add the Student Details\n");
        printf("\t 2. Find the Student "
               "Details by Roll Number\n");
        printf("\t 3. Find the Student "
               "Details by First Name\n");
        printf("\t 4. Student "
               "Details by Course Id\n");
        printf("\t 5. Find the Total number"
               " of Students\n");
        printf("\t 6. Delete the Students Details"
               " by Roll Number\n");
        printf("\t 7. Update the Students Details"
               " by Roll Number\n");
        printf("\t 8. To Exit\n");
        printf("\t\n Enter your choice to "
               "find the task\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_student();
            break;
        case 2:
            find_rl();
            break;
        case 3:
            find_fn();
            break;
        case 4:
           // find_c();
            break;
        case 5:
            tot_s();
            break;
        case 6:
            del_s();
            break;
        case 7:
            up_s();
            break;
        case 8:
            exit(0);
            break;
        }
    }
}
