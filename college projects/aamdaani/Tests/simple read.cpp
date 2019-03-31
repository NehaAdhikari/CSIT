#include <stdio.h>//For standard I/O Operation
#include <stdlib.h>//To use functions like system(); system("dos command"); - this performs the dos command given. Eg. system("cls"); - This command clears the screen
#include <windows.h>//Used in making gotoxy(int, int) function
#include <conio.h>//For getch(); getche() type of functions
#include <time.h>//To get system date and time
#include <ctype.h> //For isprint() type of functions.
#include <math.h>//To calculate mathematical problems, used esp. in interest calculation



struct trans//Structure for storing transaction information
    {
        char t_type[25],_date[15],_ttime[10];
        float amt;
        int c;
    };

struct user//Structure for storing User information
    {
        char name[30], password[30];

    };
    
FILE *fp,*tfp,*fp1;
char date[13],ttime[10];
int inputc=1,outputc=1;

void gotoxy(int x,int y); //To move the cursor to x column and y row of output screen
void _password(char buffer[]);// To input password from user so that asterik (*) is displayed for each character entered. Similar to gets(string); function
void rectangle(int x,int y,int l,int b);// To make a rectangle starting from (x,y) with length l and breadth b
void currency(char cur[], float n); // To convert a floating number n into currency format in Hindu Arabic Number system. Eg. on execution of the statement currency(cur,123456.789); the value of cur will be "1,23,456.78"
void date_output(char date[]); //To convert date in format mm/dd/yy to dd MMM, yyyy. Eg. 01/01/11 is changed to 01 Jan, 2011
void welcome();// Displays welcome screen that you see as soon as program is executed
void title(); //Clears the screen and displays program title and Current date on top of Screen


void user();//Window to login to enter main menu of the program
void main_menu(); //Main menu of the program
void rec_inc(); //To record transaction regardina income
void rec_exp(); //TO recored transaction regarding expenditure
void display(); //TO display overall transaction
void edit(); //To edit username and password
void tran_edit(); //To edit transaction
void tran_delete(); //To delete transaction
void disp_main(int); //Main function to display transaction
void tran_main_inc(int); //Main function to record income transaction
void tran_main_exp(int); //Main function to record expense transaction


int main()
{
    char c;
    welcome(); //Welcome sreen at beginning
    do
    {
        system("cls"); //Clears the screen
        rectangle(8,9,70,13);
        gotoxy(23,11); printf("Press L to Log in or Esc to Exit");
        c=getche(); //Variable c stores the key pressed by user

        if (c=='L'||c=='l')
        {
            user();
            break;
        }
        if (c==27) exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key insted to A or S

    }while(1); //infinite loop incase any key other than Esc or L is pressed.
    return 0;
}




void user()
{
    int i,ch;
	//Log in Screen begins...

    char pass[30],nam[30];
    int cnt,c;
    struct user user;

    cnt=0;//This variable cnt counts the number of attempts of Log in
    do
    {
        system("cls");
        rectangle(10,8,70,15);
        gotoxy(7,5);printf("Only THREE attempts will be allowed to enter Username and Password.");
        gotoxy(23,10); printf("Enter Username  : "); gets(user.name);
        gotoxy(23,12); printf("Password        : ");
        _password(user.password);
        
        if (cnt==2)// when no of attempts exceeds 3 (0, 1 & 2)
        {
            title();
            gotoxy(15,10); printf("You have entered wrong username and/or password three times.\n");
            gotoxy(24,12);printf("Press ENTER to exit the program.");
            getch();
            exit(0);
        }

        fp=fopen("USER.DAT","r");
        while(fscanf(fp,"%s %s\n",nam,pass)!=EOF)
        {
            if((strcmp(user.name,nam)==0)&&(strcmp(user.password,pass)==0))
            {
            	c = 1;
            }
        }
		cnt++; //if the combination doesn't match error text is shown and cnt is increased
		
		fclose(fp);
        title();
        
        if(c==1)
        {main_menu();} //main menu of the program is prompted        
        
        else
        {
        	title();
            gotoxy(25,10); printf("Invalid Username and/or Password!\a");
            gotoxy(28,12);printf("Press ENTER to try again.");
            getch();
		}
    } while(1);//not exactly infinite as user is prompted only maximum three times.
    
}




void main_menu()
{
	int i;
	char ex;
	system("cls");
	do
    {
        title(); //Displays title and date at the top
		gotoxy(10,7); printf("1. Record Income");
        gotoxy(10,9); printf("2. Record Expenditure");
        gotoxy(10,11); printf("3. Display Transaction");
        gotoxy(10,13); printf("4. Edit Transaction");
        gotoxy(10,15); printf("5. Delete Transactions");
		gotoxy(45,7); printf("6. Change Username/Password");
		gotoxy(45,9); printf("7. Exit");

        gotoxy(1,17); for(i=0;i<78;i++) printf("_"); //prints long line of "_" to separate menu and choice input
        gotoxy(23,20); printf("Press a choice between the range [1-7] ");

        switch(getch()-48) //getch gets the int value of "charater" 1 to 5, to convert it to respective integer we subtract it by 48
        {
	        case 1:rec_inc();
			break;
	        
	        case 2:rec_exp();
			break;
	        
	        case 3:display();
			break;
	        
	        case 4:tran_edit();
	        break;
	        
	        case 5:tran_delete();
	        break;
	        
	        case 6:edit();
	        break;
	        
	        case 7:
			{
		        title();
		        gotoxy(15,14); printf("Are you sure you want to exit? <Y/N> : ");
		        ex=getche();
		        if (ex=='Y'||ex=='y')
		        exit(0);
				else
				main_menu();
		        break;
			}
		    default://when entered characted is not between 1-7
		    {
		        title();
		        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 7!");
		        gotoxy(26,15); printf("Press any key to continue");
		        getch();
		        main_menu();
			}
	    }
	}while(1);//infinite loop to return to main menu after execution of any function
//return 0;
 }
 
 
 
 void rec_inc()
 {
 	int i, type; //int type helps to determine the topic of transaction in the function tran_main_inc(type)
 	title();
		gotoxy(15,7); printf("1. Interest Money\n");
        gotoxy(15,9); printf("2. Award\n");
        gotoxy(15,11); printf("3. Salary\n");
        gotoxy(15,13); printf("4. Gifts\n");
        gotoxy(15,15); printf("5. Selling\n");
		gotoxy(45,7); printf("6. Others\n");
        gotoxy(45,9); printf("7. Back to Main Menu\n");

        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,20); printf("Press a choice between the range [1-7] ");
        
        switch(getch()-48)
        {
        case 1:type=1;tran_main_inc(type); //it calls function whic records income transaction
        break;
        
        case 2:type=2;tran_main_inc(type);
        break;
        
        case 3:type=3;tran_main_inc(type);
        break;

		case 4:type=4;tran_main_inc(type);
        break;

		case 5:type=5;tran_main_inc(type);
        break;        

		case 6:type=6;tran_main_inc(type);
        break;        
        
        case 7:main_menu();
        break;

        default://when entered characted is not between 1-7
        title();
        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 7!");
        gotoxy(26,15); printf("Press any key to continue");
        getch();
        rec_inc();
 	}
 }


void rec_exp()
{
 	int i,sw,type; //int type helps to determine the topic of transaction in the function tran_main_exp(type)
 	title();
		gotoxy(15,7); printf("1. Food & Beverage\n");
        gotoxy(15,9); printf("2. Bills & Utilities\n");
        gotoxy(15,11); printf("3. Shopping\n");
        gotoxy(15,13); printf("4. Transportation\n");
        gotoxy(15,15); printf("5. Friends & Family\n");
		gotoxy(45,7); printf("6. Entertainment\n");
        gotoxy(45,9); printf("7. Health & Fitness\n");
        gotoxy(45,11); printf("8. Gift & Donation\n");
        gotoxy(45,13); printf("9. Others\n");
        gotoxy(45,15); printf("10. Back to Main Menu\n");
        
        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,20); printf("Enter a choice between the range [1-10]: ");
        scanf("%d",&sw);                
        switch(sw)
        {
        case 1:type=1;tran_main_exp(type); //it calls a function which records expense transaction of type 1 ie.Food & Beverage
        break;
        
        case 2:type=2;tran_main_exp(type); //it calls a function which records expense transaction of type 2 ie.Bills & Utilities....etc
        break;
        
        case 3:type=3;tran_main_exp(type);
        break;

		case 4:type=4;tran_main_exp(type);
        break;

		case 5:type=5;tran_main_exp(type);
        break;        

		case 6:type=6;tran_main_exp(type);
        break;        

		case 7:type=7;tran_main_exp(type);
        break;        

		case 8:type=8;tran_main_exp(type);
        break;        

		case 9:type=9;tran_main_exp(type);
        break;        
        
        case 10:main_menu();
        break;

        default://when entered characted is not between 1-10
	    {title();
	    gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 10!");
	    gotoxy(26,15); printf("Press any key to continue");
	    getch();
	    rec_exp();}
	}
}



void display()
{
 	int i, type;
 	title();
		gotoxy(15,8);printf("1. Income\n");
        gotoxy(15,10);printf("2. Expense\n");
        gotoxy(15,12);printf("3. Overall\n");
        gotoxy(15,14);printf("4. Back to Main Menu\n");

        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,20);printf("Press a choice between the range [1-4] ");
        
        switch(getch()-48)
        {
	        case 1:type=1;disp_main(type); //it calls main display function which displays total incomes
	        break;
	        
	        case 2:type=2;disp_main(type); //it calls main display function which displays total expenses
	        break;
	        
	        case 3:type=3;disp_main(type); //it calls main display function which displays overall transactions
	        break;        
	        
	        case 4:main_menu();
	        break;
	
	        default://when entered characted is not between 1-8
	        {title();
	        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 4!");
	        gotoxy(26,15); printf("Press any key to continue");
	        getch();
	        display();}
	    }
 }


void edit()
{
    char nam[30], pass[30],ch, n_nam[30], n_pass[30]={0},passwrd[30]={0},n_pass1[30]={0};
    struct user user;
    int c=0,err=0;
        title();

            gotoxy(25,8);printf("User Name  : ");
            scanf("%s",user.name);
            gotoxy(25,10);printf("Password  : ");
            _password(passwrd);
            strcpy(user.password,passwrd);

        fp=fopen("USER.DAT","r");
         while(fscanf(fp,"%s %s\n",nam,pass)!=EOF)
         {
             if(strcmp(user.name,nam)==0&&strcmp(user.password,pass)==0) c++;
         }

        fclose(fp);
        title();
        if (c==0)
        {

            gotoxy(22,10); printf("Wrong Username and/or Password\a");
            getch();
        }
        else
        {
           gotoxy(8,10); printf("Are you sure you want to CHANGE user name and/or password? <Y/N> : ");
            ch=getche();
            if(ch=='Y'||ch=='y')
            {
                do
                {
                	title();
                    err=0;
                    gotoxy(25,8);
                    printf("NEW Username        : ");
                    scanf("%s",n_nam);
                    gotoxy(25,10);
                    printf("NEW Password         : ");
                    _password(n_pass);
                    gotoxy(25,12);
                    printf("Confirm NEW Password : ");
                    _password(n_pass1);

                    if (strcmp(n_pass,n_pass1)!=0)
                    {
                        title();
                        gotoxy(17,13);
                        printf("Password and confirm password does not match!\a");
                        getch();
                        err++;
                    }

                } while(err!=0);

                tfp=fopen("TEMP.DAT","a");
                fprintf(tfp,"%s %s\n",n_nam,n_pass);
                fclose(tfp);
                fclose(fp);
                remove("USER.DAT");
                rename("TEMP.DAT","USER.DAT");
                title();
                gotoxy(21,13); printf("Record has been EDITED successfully!");
                getch();
            }


        }

}



//----------------------------------------------//



void tran_main_inc(int type)
{
	struct trans trans;
	char ch,curr[35];
	int i;
	
	fp=fopen("INCOME_T.DAT","r");
	while(fread(&trans,sizeof(trans),1,fp)==1)
	{
	    if(inputc<=trans.c)
	    inputc++;
	}
	fclose(fp);
	trans.c=inputc;
	
	switch(type)
	{
        case 1: strcpy(trans.t_type,"Interest Money"); break;
        case 2: strcpy(trans.t_type,"Award"); break;
        case 3: strcpy(trans.t_type,"Salary"); break;
        case 4: strcpy(trans.t_type,"Gifts"); break;
        case 5: strcpy(trans.t_type,"Selling"); break;
        case 6: strcpy(trans.t_type,"Others"); break;
    }
    title();
    gotoxy(10,9);printf("Choose transaction occurance date:");
    gotoxy(10,11);printf("1. Today");
    gotoxy(10,13);printf("2. Input Date by self");
    gotoxy(1,17); for(i=0;i<78;i++) printf("_");
    gotoxy(23,20);printf("Press a choice between 1 and 2 ");
    switch(getch()-48)
    {
    	case 1:
    	{
    		title();
		    _strdate(date);
		    strcpy(trans._date,date);
		    _strtime(ttime);
		    strcpy(trans._ttime,ttime);
		    gotoxy(16,14);printf("Income Amount (in NRs.) : "); scanf("%f",&trans.amt);
		    
			title();
		    currency(curr,trans.amt);
		    gotoxy(12,12); printf("%s is to be recorded under [%s] ",curr,trans.t_type);
			gotoxy(1,17); for(i=0;i<78;i++) printf("%c",196);
		    gotoxy(11,20);printf("Are you sure you want to record this tranasction? <Y/N>");
		    ch=getche();
		    if (ch=='Y'||ch=='y')
		    {
			    fp=fopen("INCOME_T.DAT","a");
			    fwrite(&trans,sizeof(trans),1,fp);
			    fclose(fp);
			    title();
			    gotoxy(20,12);printf("Transaction recorded successfully!");
			    getch();
			    rec_inc();
			}
			else
			rec_inc();
			break;
		}
		case 2:
		{
			title();
			gotoxy(10,12);printf("Input Date in the format mm/dd/yy:");
			gotoxy(10,13);printf("(Example:02/22/15)");
			gotoxy(10,16);printf("Income Amount (in NRs.) : ");
			gotoxy(45,12);scanf("%s",&trans._date);
			gotoxy(36,16);scanf("%f",&trans.amt);
		    _strtime(ttime);
		    strcpy(trans._ttime,ttime);
			title();
		    currency(curr,trans.amt);
		    gotoxy(12,12); printf("%s is to be recorded under [%s] ",curr,trans.t_type);
			gotoxy(1,17); for(i=0;i<78;i++) printf("%c",196);
		    gotoxy(11,20);printf("Are you sure you want to record this tranasction? <Y/N>");
		    ch=getche();
		    if (ch=='Y'||ch=='y')
		    {
			    fp=fopen("INCOME_T.DAT","a");
			    fwrite(&trans,sizeof(trans),1,fp);
			    fclose(fp);
			    title();
			    gotoxy(20,12);printf("Transaction recorded successfully!");
			    getch();
			    rec_inc();
			}
			else
			rec_inc();
			break;
		}
			
	    default://when entered characted is not 1 or 2
	    {title();
	    gotoxy(27,12); printf("Your input is out of range!");
	    gotoxy(26,15); printf("Press any key to continue");
	    getch();
	    tran_main_inc(type);}
	}
}


void tran_main_exp(int type)
{
	struct trans trans;
	char ch,curr[35];
	int i;
	
	
	fp=fopen("EXPENSE_T.DAT","r");
	while(fread(&trans,sizeof(trans),1,fp)==1)
	{
	    if(outputc<=trans.c)
	    outputc++;
	}
	fclose(fp);
	trans.c=outputc;
	
	switch(type)
	{
        case 1: strcpy(trans.t_type,"Food & Beverage"); break;
        case 2: strcpy(trans.t_type,"Bills & Utilities"); break;
        case 3: strcpy(trans.t_type,"Shopping"); break;
        case 4: strcpy(trans.t_type,"Transportation"); break;
        case 5: strcpy(trans.t_type,"Friends & Family"); break;
        case 6: strcpy(trans.t_type,"Entertainment"); break;
        case 7: strcpy(trans.t_type,"Health & Fitness"); break;
        case 8: strcpy(trans.t_type,"Gift & Donation"); break;
        case 9: strcpy(trans.t_type,"Others"); break;
    }
    title();
    gotoxy(10,9);printf("Choose transaction occurance date:");
    gotoxy(10,11);printf("1. Today");
    gotoxy(10,13);printf("2. Input Date by self");
    gotoxy(1,17); for(i=0;i<78;i++) printf("_");
    gotoxy(23,20);printf("Press a choice between 1 and 2 ");
    switch(getch()-48)
    {
    	case 1:
    	{
    		title();
		    _strdate(date);
		    strcpy(trans._date,date);
		    _strtime(ttime);
		    strcpy(trans._ttime,ttime);
		    gotoxy(16,14);printf("Expense Amount (in NRs.) : "); scanf("%f",&trans.amt);
		    
			title();
		    currency(curr,trans.amt);
		    gotoxy(12,12); printf("%s is to be recorded under [%s] ",curr,trans.t_type);
			gotoxy(1,17); for(i=0;i<78;i++) printf("%c",196);
		    gotoxy(11,20);printf("Are you sure you want to record this tranasction? <Y/N>");
		    ch=getche();
		    if (ch=='Y'||ch=='y')
		    {
			    fp=fopen("EXPENSE_T.DAT","a");
			    fwrite(&trans,sizeof(trans),1,fp);
			    fclose(fp);
			    title();
			    gotoxy(20,12);printf("Transaction recorded successfully!");
			    getch();
			    rec_exp();
			}
			else
			rec_exp();
		}
		
		case 2:
		{
			title();
			gotoxy(10,12);printf("Input Date in the format mm/dd/yy:");
			gotoxy(10,13);printf("(Example:02/22/15)");
			gotoxy(10,16);printf("Expense Amount (in NRs.) : ");
			gotoxy(45,12);scanf("%s",&trans._date);
			gotoxy(36,16);scanf("%f",&trans.amt);
		    _strtime(ttime);
		    strcpy(trans._ttime,ttime);
			title();
		    currency(curr,trans.amt);
		    gotoxy(12,12); printf("%s is to be recorded under [%s] ",curr,trans.t_type);
			gotoxy(1,17); for(i=0;i<78;i++) printf("%c",196);
		    gotoxy(11,20);printf("Are you sure you want to record this tranasction? <Y/N>");
		    ch=getche();
		    if (ch=='Y'||ch=='y')
		    {
			    fp=fopen("EXPENSE_T.DAT","a");
			    fwrite(&trans,sizeof(trans),1,fp);
			    fclose(fp);
			    title();
			    gotoxy(20,12);printf("Transaction recorded successfully!");
			    getch();
			    rec_exp();
			}
			else
			rec_exp();
		}
		
		default://when entered characted is not 1 or 2
	    {title();
	    gotoxy(27,12); printf("Your input is out of range!");
	    gotoxy(26,15); printf("Press any key to continue");
	    getch();
	    tran_main_exp(type);
		}
	}
}



void disp_main(int type)
{
	struct trans trans;
	char ch,curr[35];
    int c,i,j=1;
    float totalam=0,totalam1=0;
    float in1=0,in2=0,in3=0,in4=0,in5=0,in6=0;
    float ou1=0,ou2=0,ou3=0,ou4=0,ou5=0,ou6=0,ou7=0,ou8=0,ou9=0;
	switch(type)
	{
        case 1: 
        {
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("INCOME_T.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	totalam=totalam+trans.amt;
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Press Backspace to go Back.");
	        gotoxy(45,22);puts("Total Income:  ");
			currency(curr,totalam);
	        gotoxy(60,22);printf("%s",curr);
	    	c=getch();
	    	if(c==8)
	    	display();
	    	else
	    	disp_main(type);
			break;    	
    	}
        
        case 2: 
        {
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("EXPENSE_T.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	totalam=totalam+trans.amt;
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Press Backspace to go Back.");
	        gotoxy(45,22);puts("Total Expense:  ");
			currency(curr,totalam);
	        gotoxy(61,22);printf("%s",curr);
	    	c=getch();
	    	if(c==8)
	    	display();
	    	else
	    	disp_main(type);
	    	break;
	   }
	    case 3: {
	        title();
	        gotoxy(18,7);printf("INCOME");
	        gotoxy(58,7);printf("EXPENSE");
	        fp=fopen("INCOME_T.DAT","r");
			while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	if(strcmp("Interest Money",trans.t_type)==0) in1=in1+trans.amt;
	        	else if(strcmp("Award",trans.t_type)==0) in2=in2+trans.amt;
	        	else if(strcmp("Salary",trans.t_type)==0) in3=in3+trans.amt;
	        	else if(strcmp("Gifts",trans.t_type)==0) in4=in4+trans.amt;
	        	else if(strcmp("Selling",trans.t_type)==0) in5=in5+trans.amt;
	        	else if(strcmp("Others",trans.t_type)==0) in6=in6+trans.amt;
	        }
	        gotoxy(3,9); printf("1. Interest Money\n");
	        currency(curr,in1);
	        gotoxy(21,9);printf(": %s",curr);
	        gotoxy(3,10); printf("2. Award\n");
	        currency(curr,in2);
	        gotoxy(21,10);printf(": %s",curr);
	        gotoxy(3,11); printf("3. Salary\n");
	        currency(curr,in3);
	        gotoxy(21,11);printf(": %s",curr);
	        gotoxy(3,12); printf("4. Gifts\n");
	        currency(curr,in4);
	        gotoxy(21,12);printf(": %s",curr);
	        gotoxy(3,13); printf("5. Selling\n");
	        currency(curr,in5);
	        gotoxy(21,13);printf(": %s",curr);
			gotoxy(3,14); printf("6. Others\n");
			currency(curr,in6);
			gotoxy(21,14);printf(": %s",curr);
			
			totalam=in1+in2+in3+in4+in5+in6;
			currency(curr,totalam);
			gotoxy(6,19); printf("Total Inflow: \n");
			gotoxy(20,19); printf("%s",curr);
			
	        
			fp=fopen("EXPENSE_T.DAT","r");
			while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	if(strcmp("Food & Beverage",trans.t_type)==0) ou1=ou1+trans.amt;
	        	else if(strcmp("Bills & Utilities",trans.t_type)==0) ou2=ou2+trans.amt;
	        	else if(strcmp("Shopping",trans.t_type)==0) ou3=ou3+trans.amt;
	        	else if(strcmp("Transportation",trans.t_type)==0) ou4=ou4+trans.amt;
	        	else if(strcmp("Friends & Family",trans.t_type)==0) ou5=ou5+trans.amt;
	        	else if(strcmp("Entertainment",trans.t_type)==0) ou6=ou6+trans.amt;
	        	else if(strcmp("Health & Fitness",trans.t_type)==0) ou7=ou7+trans.amt;
	        	else if(strcmp("Gift & Donation",trans.t_type)==0) ou8=ou8+trans.amt;
	        	else if(strcmp("Others",trans.t_type)==0) ou9=ou9+trans.amt;
	        }
	        fclose(fp);
	        gotoxy(40,9); printf("1. Food & Beverage");
	        currency(curr,ou1);
	        gotoxy(61,9);printf(": %s",curr);
        	gotoxy(40,10); printf("2. Bills & Utilities");
        	currency(curr,ou2);
        	gotoxy(61,10);printf(": %s",curr);
        	gotoxy(40,11); printf("3. Shopping");
        	currency(curr,ou3);
        	gotoxy(61,11);printf(": %s",curr);
        	gotoxy(40,12); printf("4. Transportation");
        	currency(curr,ou4);
        	gotoxy(61,12);printf(": %s",curr);
        	gotoxy(40,13); printf("5. Friends & Family");
        	currency(curr,ou5);
        	gotoxy(61,13);printf(": %s",curr);
			gotoxy(40,14); printf("6. Entertainment");
			currency(curr,ou6);
			gotoxy(61,14);printf(": %s",curr);
        	gotoxy(40,15); printf("7. Health & Fitness");
        	currency(curr,ou7);
        	gotoxy(61,15);printf(": %s",curr);
        	gotoxy(40,16); printf("8. Gift & Donation");
        	currency(curr,ou8);
        	gotoxy(61,16);printf(": %s",curr);
        	gotoxy(40,17); printf("9. Others");
        	currency(curr,ou9);
        	gotoxy(61,17);printf(": %s",curr);
        	
        	totalam1=ou1+ou2+ou3+ou4+ou5+ou6+ou7+ou8+ou9;
			currency(curr,totalam1);
			gotoxy(45,19); printf("Total Outflow: \n");
			gotoxy(60,19); printf("%s",curr);
        	
        	
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(27,22);printf("Press Backspace to go Back.");
	    	c=getch();
	    	if(c==8)
	    	display();
	    	else
	    	disp_main(type);
	    	break;
        	
        
    	}
    }
          
    
}



void tran_delete()
{
 	struct trans trans;
	char ch,curr[35];
    int c,i,j=1,k=0;
 	
	 	title();
		gotoxy(15,10);printf("1. Delete Income Transaction\n");
        gotoxy(15,12);printf("2. Delete Expense Transaction\n");
        gotoxy(15,14);printf("3. Back to Main Menu\n");

        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
        
        switch(getch()-48)
        {
	        case 1:
			title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("INCOME_T.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Enter transaction no. to delete or press other key to go back: ");
	    	scanf("%d",&c);
	    	fp=fopen("INCOME_T.DAT","r");
	    	tfp=fopen("TEMP.DAT","w");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
			{
		        if(c==trans.c)
		        {title();
			    gotoxy(20,12);printf("Transaction has been sucessfully deleted!");
		        k=1;
			    getch();
		        }
		       else{
		       		fwrite(&trans,sizeof(trans),1,tfp);
		            }
		    }
		    fclose(fp);
		    fclose(tfp);
            remove("INCOME_T.DAT");
            rename("TEMP.DAT","INCOME_T.DAT");
		    
	    	fp=fopen("INCOME_T.DAT","r");
	    	tfp=fopen("TEMP.DAT","w");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
	    	{
	    		if(trans.c<c)
	    		{
	    			fwrite(&trans,sizeof(trans),1,tfp);
				}
	    		else if(c<trans.c)
	    		{
	    			trans.c--;
	    			fwrite(&trans,sizeof(trans),1,tfp);
				}
			}
			fclose(fp);
		    fclose(tfp);
            remove("INCOME_T.DAT");
            rename("TEMP.DAT","INCOME_T.DAT");
	    	if(!k)
	    	tran_delete();
			break;
			
			case 2:
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("EXPENSE_T","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Enter transaction no. to delete or press other key to go back: ");
	    	scanf("%d",&c);
	    	fp=fopen("EXPENSE_T","r");
	    	tfp=fopen("TEMP.DAT","w");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
			{
		        if(c==trans.c)
		        {title();
			    gotoxy(20,12);printf("Transaction has been sucessfully deleted!");
		        k=1;
			    getch();
		        }
		       else{
		       		fwrite(&trans,sizeof(trans),1,tfp);
		            }
		    }
		    fclose(fp);
		    fclose(tfp);
            remove("EXPENSE_T.DAT");
            rename("TEMP.DAT","EXPENSE_T");
		    
	    	fp=fopen("EXPENSE_T","r");
	    	tfp=fopen("TEMP.DAT","w");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
	    	{
	    		if(trans.c<c)
	    		{
	    			fwrite(&trans,sizeof(trans),1,tfp);
				}
	    		else if(c<trans.c)
	    		{
	    			trans.c--;
	    			fwrite(&trans,sizeof(trans),1,tfp);
				}
			}
			fclose(fp);
		    fclose(tfp);
            remove("EXPENSE_T.DAT");
            rename("TEMP.DAT","INCOME_T.DAT");
	    	if(!k)
	    	tran_delete();	        
	        break;
	        
	        
	        case 3:main_menu();
	        break;
	
	        default://when entered characted is not between 1-3
	        {title();
	        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 3!");
	        gotoxy(26,15); printf("Press any key to continue");
	        getch();
	        tran_delete();}
	    }
 }


void tran_edit()
{
	struct trans trans;
	char ch,curr[35];
    int c,i,j=1,k=0;
 	
	 	title();
		gotoxy(15,10);printf("1. Edit Income Transaction\n");
        gotoxy(15,12);printf("2. Edit Expense Transaction\n");
        gotoxy(15,14);printf("3. Back to Main Menu\n");

        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
        
        switch(getch()-48)
        {
	        case 1:
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("INCOME_T.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Enter transaction no. to edit or press other key to go back: ");
	    	scanf("%d",&c);
	    	fp=fopen("INCOME_T.DAT","r+");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
			{
		        if(c==trans.c)
		        {	title();
			        gotoxy(15,10);printf("1. Edit Transaction Type\n");
			        gotoxy(15,12);printf("2. Edit Date\n");
			        gotoxy(15,14);printf("3. Back Amount\n");
			
			        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
			        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
			        
			        switch(getch()-48)
			        {
			        	case 1:
			        		title();
							gotoxy(15,7); printf("1. Interest Money\n");
					        gotoxy(15,9); printf("2. Award\n");
					        gotoxy(15,11); printf("3. Salary\n");
					        gotoxy(15,13); printf("4. Gifts\n");
					        gotoxy(15,15); printf("5. Selling\n");
							gotoxy(45,7); printf("6. Others\n");
					
					        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
					        gotoxy(23,20); printf("Press a choice between the range [1-6] ");
					        
					        switch(getch()-48)
					        {
								case 1: strcpy(trans.t_type,"Interest Money"); break;
						        case 2: strcpy(trans.t_type,"Award"); break;
						        case 3: strcpy(trans.t_type,"Salary"); break;
						        case 4: strcpy(trans.t_type,"Gifts"); break;
						        case 5: strcpy(trans.t_type,"Selling"); break;
						        case 6: strcpy(trans.t_type,"Others"); break;
							}
							fseek(fp,-sizeof(trans),SEEK_CUR);
            				fwrite(&trans,sizeof(trans),1,fp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 2:
							title();
							gotoxy(10,12);printf("Input Date in the format mm/dd/yy:");
							gotoxy(10,13);printf("(Example:02/22/15)");
							gotoxy(45,12);scanf("%s",&trans._date);
							fseek(fp,-sizeof(trans),SEEK_CUR);
            				fwrite(&trans,sizeof(trans),1,fp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 3:
							title();
							gotoxy(10,13);printf("Input Amount (in NRs.):");
							gotoxy(35,13);scanf("%s",&trans.amt);
							fseek(fp,-sizeof(trans), SEEK_CUR);
            				fwrite(&trans,sizeof(trans),1,fp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
			        }
			        tran_edit();
			    }
			}
	    	tran_edit();
			break;
			
			case 2:
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("EXPENSE.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Enter transaction no. to edit or press other key to go back: ");
	    	scanf("%d",&c);
	    	fp=fopen("EXPENSE_T.DAT","r+");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
			{
		        if(c==trans.c)
		        {	title();
			        gotoxy(15,10);printf("1. Edit Transaction Type\n");
			        gotoxy(15,12);printf("2. Edit Date\n");
			        gotoxy(15,14);printf("3. Back Amount\n");
			
			        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
			        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
			        
			        switch(getch()-48)
			        {
			        	case 1:
			        		title();
							gotoxy(15,7); printf("1. Food & Beverage\n");
					        gotoxy(15,9); printf("2. Bills & Utilities\n");
					        gotoxy(15,11); printf("3. Shopping\n");
					        gotoxy(15,13); printf("4. Transportation\n");
					        gotoxy(15,15); printf("5. Friends & Family\n");
							gotoxy(45,7); printf("6. Entertainment\n");
					        gotoxy(45,9); printf("7. Health & Fitness\n");
					        gotoxy(45,11); printf("8. Gift & Donation\n");
					        gotoxy(45,13); printf("9. Others\n");
					        
					        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
					        gotoxy(23,20);printf("Press a choice between the range [1-9] ");
					        
					        switch(getch()-48)
					        {
						        case 1: strcpy(trans.t_type,"Food & Beverage"); break;
						        case 2: strcpy(trans.t_type,"Bills & Utilities"); break;
						        case 3: strcpy(trans.t_type,"Shopping"); break;
						        case 4: strcpy(trans.t_type,"Transportation"); break;
						        case 5: strcpy(trans.t_type,"Friends & Family"); break;
						        case 6: strcpy(trans.t_type,"Entertainment"); break;
						        case 7: strcpy(trans.t_type,"Health & Fitness"); break;
						        case 8: strcpy(trans.t_type,"Gift & Donation"); break;
						        case 9: strcpy(trans.t_type,"Others"); break;
							}
							fseek(fp,-sizeof(trans), SEEK_CUR);
            				fwrite(&trans,sizeof(trans),1,fp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 2:
							title();
							gotoxy(10,12);printf("Input Date in the format mm/dd/yy:");
							gotoxy(10,13);printf("(Example:02/22/15)");
							gotoxy(45,12);scanf("%s",&trans._date);
							fseek(fp,-sizeof(trans), SEEK_CUR);
            				fwrite(&trans,sizeof(trans),1,fp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 3:
							title();
							gotoxy(10,13);printf("Input Amount (in NRs.):");
							gotoxy(35,13);scanf("%s",&trans.amt);
							fseek(fp,-sizeof(trans), SEEK_CUR);
            				fwrite(&trans,sizeof(trans),1,fp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						tran_edit();
			        }
			    }
			}
	    	tran_edit();      
	        break;
	        
	        
	        case 3:main_menu();
	        break;
	
	        default://when entered characted is not between 1-3
	        {title();
	        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 3!");
	        gotoxy(26,15); printf("Press any key to continue");
	        getch();
	        tran_delete();}
	    }
}
//--------------------------------------------------------//


void welcome()
{
    int i;
    system("cls");
    rectangle(0,0,80,23);
    rectangle(27,2,52,4);
    gotoxy(36,3); printf("AAMDAANI");
    gotoxy(32,6);for(i=0;i<15;i++) printf("%c",196);
    gotoxy(35,7); printf("Project By:");
    gotoxy(32,8);for(i=0;i<15;i++) printf("%c",196);
    gotoxy(36,10); printf("Kusal Kc");
    gotoxy(32,12); printf("Mala Thapa Magar");
    gotoxy(31,14); printf("Namkong Hang Kirat");
    gotoxy(34,16); printf("Neha Adhikari");
    gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	gotoxy(28,22);
    printf("Press Any key to continue.");
    getch();

}


void title()
{
    int i;

    system("cls");

    rectangle(0,0,80,23);
    gotoxy(37,2);
    printf("AAMDAANI");
    gotoxy(59,4); printf("Date : ");
    _strdate(date); //_strdate stores system date in variable date in format mm/dd/yy
    date_output(date); //converts mm/dd/yy to to dd MMM, yyyy.
    printf("%s",date);
    gotoxy(1,5);
      for(i=0;i<78;i++) printf("%c",196);

}


void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}


void _password(char buffer[])
{
   	char c;
   	int pos = 0;
   	do
   	{
		c = getch();
  		if(isprint(c))
   		{
   			buffer[ pos++ ] = c;
   			printf("%c", '*');
   		}
   		else if(c == 8 && pos)
   		{
   			buffer[ pos-- ] = '\0';
   			printf("%s", "\b \b");
   		}
  	}while( c!= 13 );
}


void date_output(char date[]) //mm/dd/yy ---> dd MMM, yyyy
{
    struct
    {
        int dd;
        char mm[4];
        int yyyy;
    }_date;

    char temp[15];
    int mm,c,i;
    _date.dd=(date[3]-48)*10+(date[4]-48);

    mm=(date[0]-48)*10+(date[1]-48);
    _date.yyyy=2000+(date[6]-48)*10+(date[7]-48);
switch(mm)
    {
        case 1: strcpy(_date.mm,"Jan"); break;
        case 2: strcpy(_date.mm,"Feb"); break;
        case 3: strcpy(_date.mm,"Mar"); break;
        case 4: strcpy(_date.mm,"Apr"); break;
        case 5: strcpy(_date.mm,"May"); break;
        case 6: strcpy(_date.mm,"Jun"); break;
        case 7: strcpy(_date.mm,"Jul"); break;
        case 8: strcpy(_date.mm,"Aug"); break;
        case 9: strcpy(_date.mm,"Sep"); break;
        case 10: strcpy(_date.mm,"Oct"); break;
        case 11: strcpy(_date.mm,"Nov"); break;
        case 12: strcpy(_date.mm,"Dec"); break;
    }

    temp[0]=(int)(_date.dd/10)+48;
    temp[1]=(int)(_date.dd%10)+48;
    temp[2]=32;
    temp[3]='\0';
    strcat(temp,_date.mm);
    temp[6]=',';
    c=0;
    temp[7]=32;
    for(i=3;i>=0;i--)
    {
        temp[8+c]=(int)(_date.yyyy/pow(10,i))+48;
        c++;
        _date.yyyy%=(int)pow(10,i);
    }
    temp[12]='\0';
    strcpy(date,temp);
    }


void currency(char cur[], float n)
{

    int num,i,x,c;
    char temp[30];
    num=(int)n;
    int a[6];
    a[5]=num%1000;
    num=num/1000;

    for(i=4;i>=0;i--)
    {
        a[i]=num%100;
        num=num/100;
    }



    for(i=0;i<6;i++)
        if (a[i]!=0) break;

        x=i;
        c=0;
        for(i=x;i<6;i++)
        {
            if(i==5)
            {
                if (a[i]>=100||i!=x) cur[c++]=(a[i]/100)+48;
                if (a[i]%100>=10||i!=x) cur[c++]=(a[i]%100)/10+48;
                if (a[i]%100<10&&i==x) cur[c++]=48;
                cur[c++]=(a[i]%100)%10+48;
            }
            else
            {
                if (a[i]>=10||i!=x) cur[c++]=(a[i]/10)+48;
                cur[c++]=(a[i]%10)+48;
                cur[c++]=',';
            }

        }

        cur[c++]='.';
        num=(n-(int)n)*100;
        cur[c++]=num/10+48;
        cur[c++]=num%10+48;
        cur[c]='\0';
        if (n==0) strcpy(cur,"0.00");
        strcpy(temp,"Rs. ");
        strcat(temp,cur);
        strcpy(cur,temp);
}



COORD coord = {0, 0};

void gotoxy (int x, int y)
        {
        coord.X = x;
        coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }

