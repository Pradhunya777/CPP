#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdbool.h" //use for boolean data types
#define size 2
/*
*** Structures ***
*/

//login struct
typedef struct {
	char user_name[30];
	char password[30];
}LOG_IN;

//structure for atm system
struct {
	int atm_id;
	float atm_total_cash;
	LOG_IN login;
}atm;

//structure for users
struct user {
	int user_id;
	char name[10];
	char bank_name[10];
	float user_total_cash ;
	int pin;
	LOG_IN login;
}users[size];

/*
*** Functions ***
*/

//initialize ATM details
void initATM(){
	atm.atm_id = 4533;
	atm.atm_total_cash = 50000;
	strcpy(atm.login.user_name, "shewalepradhunya@gmail.com");
	strcpy(atm.login.password,  "pd@777");
}

//display all about ATM
void displayATM(){
	printf("\n\t\t ****** About ATM ****** ");
	printf("\n\t---------------------------------------");
	printf("\n\t ATM  ID           : %d   ", atm.atm_id);
	printf("\n\t Total Cash in ATM : %.2f ", atm.atm_total_cash);
	printf("\n\t User Name         : %s   ", atm.login.user_name);
	printf("\n\t Pass Word         : %s   ", atm.login.password);
}

//check validation for ATM system login
bool isValidLogin(char user_name[], char password[]){
	return( !strcmp(atm.login.user_name, user_name) && !strcmp(atm.login.password, password) );
}

// get users info
void getUsers(){
	int i;
	printf("\n\t********User ATM Service**************");
	for(i=0; i< size; i++){
		printf("\n\t Enter User Id        :\t");
		scanf("%d", &users[i].user_id);
		printf("\n\t Enter Name           :\t");
		scanf("%s", &users[i].name);
		printf("\n\t Enter User Bank Name :\t");
		scanf("%s", &users[i].bank_name);
		printf("\n\t Enter Deposit Cash   :\t");
		scanf("%f", &users[i].user_total_cash);
		printf("\n\t Enter 4 Digit Pin    :\t");
		scanf("%d", &users[i].pin);
		printf("\n\t Enter User-Name      :\t");
		scanf("%s", &users[i].login.user_name);
		printf("\n\t Enter Pass-Word      :\t");
		scanf("%s", &users[i].login.password);
	}
}
//display all users
void displayUsers(){
    printf("\n\t********Visited User**************");
    for(int i=0; i< size; i++){
		printf("\n\t User Id     : %d",users[i].user_id);
		printf("\n\t Name        : %s",users[i].name);
		printf("\n\t Bank Name   : %s",users[i].bank_name);
		printf("\n\t Total Cash  : %.2f",users[i].user_total_cash);
		printf("\n\t Pin         : %d",users[i].pin);
		printf("\n\t User-Name   : %s",users[i].login.user_name);
		printf("\n\t User-Name   : %s",users[i].login.password);
	}
}
/*
****	Atm oprations
*/
//check balance
void checkBalance(int pin){
    for(int i=0; i< size; i++){
        if(users[i].pin == pin){
           printf("\n\t Total Cash  : %.2f",users[i].user_total_cash);
           break;
        }
    }
}

//Withdraw Cash
void withdrawCash(int pin){
	int temp;
	printf("\n\t Enter Amount To Withdraw :\t");
	scanf("%d", &temp);

    if(temp <=  atm.atm_total_cash){
        for(int i=0; i< size; i++){
            if(users[i].pin == pin){
                if(temp <= users[i].user_total_cash){
                    users[i].user_total_cash -= temp;
                    atm.atm_total_cash -= temp;
                    printf("\n\t Collect Your Cash ...");
                    printf("\n\t Remaining Total Cash  : %.2f",users[i].user_total_cash);
                    break;
                }else
                    printf("\n\t You Have No Enough Balance.... Plase Check it.");
            }
        }
    }else
        printf("\n\t No Cash in ATM...");
}
//Deposit Cash
void depositCash(int pin){
	int temp;
	printf("\n\t Enter Amount To Deposit :\t");
	scanf("%d", &temp);

	for(int i=0; i< size; i++){
    	if(users[i].pin == pin){
    		 users[i].user_total_cash += temp;
    	}
    }

}
//enter pin
int inputPin(){
    int pin;
    printf("\n\t Enter 4 Digit Pin :\t");
    scanf("%d", &pin);
    return(pin);
}

/*
*** Main methos ***
*/
int main(){
	char user_name[30], password[30];
	int ch, action;
	//set up ATM
	initATM();
	getUsers();

	do{
		printf("\n\t********Welcome to ATM Service**************");
		printf("\n\t 1 : System Login only. ");
		printf("\n\t 2 : Use ATM ");
        printf("\n\t*********************************************");

		printf("\n\t Enter Choice :\t");
		scanf("%d", &ch);

		switch(ch){
		    //admin pannel
			case 1 :


				printf("\n\t Enter User-Name :\t");
				scanf("%s", &user_name);
				printf("\n\t Enter Pass-Word :\t");
				scanf("%s", &password);

				if(isValidLogin(user_name, password)){
					displayATM();

				}else
					printf("\n\t Invalide users....");
			break;
			//user pannel
			case 2 :
			    do{
                	printf("\n\t********User ATM Service**************");
                    printf("\n\t 1 : Check Balance");
                    printf("\n\t 2 : Withdraw Cash");
                    printf("\n\t 3 : Deposit Cash");
                    printf("\n\t 4 : Quit");
                    printf("\n\t*********************************************");
                    printf("\n\t Enter your choice :\t");
                    scanf("%d", &action);

                    switch(action){
                    	case 1 :
                    	    checkBalance(inputPin());
                    	break;
                    	case 2 :
                    		withdrawCash(inputPin());
                    	break;
                    	case 3 :
                    		depositCash(inputPin());
                    		displayUsers();
                    	break;
                    	case 4 :
                    		printf("\n\n\t Thank You Using ATM !!!");
                    		exit(1);
                    	break;
                    	default : printf("\n\t Invalide choice....");
                    }

				}while(action != 4);
			break;
			default : printf("\nt Invalide Choice... ");

		}
	}while(ch != 2);
	return 0;
}
