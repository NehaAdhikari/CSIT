//Student Management System
//Submitted By: Kushal Kc
//				Mala Thapa Magar
//				Namkong Hang Kirat
//				Neha Adhikari
//===========================================================//



#include <stdio.h>//For standard I/O Operation
#include <stdlib.h>//To use functions like system(); system("dos command"); - this performs the dos command given. Eg. system("del abc.txt"); - This command deletes the file abc.txt from current location of project
#include <windows.h>//Used in making gotoxy(int, int) function
#include <conio.h>//For getch(); getche() type of functions
#include <time.h>//To get system date and time
#include <math.h>//To calculate mathematical problems, used esp. in interest calculation




void gotoxy(int x,int y); //To move the cursor to x column and y row of output screen
void _password(char buffer[]);// To input password from user so that asterik (*) is displayed for each character entered. Similar to gets(string); function
void rectangle(int x,int y,int l,int b);// To make a rectangle starting from (x,y) with length l and breadth b
void cls(int x1,int y1,int x2, int y2); // To clear only certain portion of screen starting from (x1,y1) to (x2,y2). Notice this function has been used in date entry. When date is not in dd/mm/yyyy format, the wrong value is cleared on the screen
void date_output(char date[]); //To convert date in format mm/dd/yy to dd MMM, yyyy. Eg. 01/01/11 is changed to 01 Jan, 2011
void currency(char cur[], float n); // To convert a floating number n into currency format in Hindu Arabic Number system. Eg. on execution of the statement currency(cur,123456.789); the value of cur will be "1,23,456.78"
void title();//Clears the screen and displays program title, Current User and Current date on top of Screen
void welcome();// Displays welcome screen that you see as soon as program is executed

void user();//Main program for user to manage transaction
void main_menu(); //Main meny of the program
void rec_inc(); //To record transaction regardina income
void rec_exp(); //TO recored transaction regarding expenditure
void display(); //TO display overall transaction
void disp_main(); //Main function to display transaction
void edit_user();// To edit user name and/or password of existing user
void tran_main_inc(int); //Main function to record income transaction
void tran_main_exp(int); //Main function to record expense transaction



char date[13],ttime[10];// This is global variables to store system date and system time

FILE *fp,*fp1,*fp2; // File pointers

struct user//Structure for storing User information
    {
        char name[30], password[30];

    };
    

struct trans//Structure for storing transaction information
    {
        char t_type[25],_date[15],_ttime[10];
        float amt;
    };


int main()
{
    char c;
    welcome(); //Welcome sreen at beginning
    do
    {
        system("cls"); //Clears the screen
        rectangle(8,9,70,13);
        gotoxy(10,11); printf("Press L to Log in or Esc to Exit\n\n\n\t\t\t\t\t");
        c=getche(); //Variable c stores the key pressed by user

        if (c=='L'||c=='l')
        {
            user();
            break;
        }
        if (c==27) exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key insted to A or S

    }while(1); //infinite loop incase any key other than Esc, A, or S is pressed.



    return 0;
}





void user()
{
    int i,ch;
//Log in Screen begins...

    char uname[30], pass[30],passwrd[30]={0},nam[30];
    int c=0,cnt=0;
    char ex,stime[9],etime[9];


    cnt=0;//This variable cnt counts the number of attempts of Log in
    do
    {
        system("cls");
        rectangle(10,8,70,15);
        gotoxy(7,5);printf("Only THREE attempts shall be allowed to enter username and password.");
        gotoxy(23,10); printf("Enter User name : "); scanf("%s",user.name);
        gotoxy(23,12); printf("Password        : ");
        char passwrd[30]={0};//To nullify the string passwrd
        _password(passwrd);
        strcpy(user.password,passwrd);
        cnt++;

        if (cnt==3)// when no of attempts exceeds 3
        {
            title();
            gotoxy(25,10); printf("Invalid User name or Password!\a");
            gotoxy(22,12);printf("Press ENTER to exit the program...");
            getch();
            exit(0);
        }



        c=0;//Counts the no. of user for which the name and password matches
        fp=fopen("USER.DAT","r");
        while(fscanf(fp,"%s %s %s\n",nam,pass)!=EOF)
        {
             strcpy(nam,strupr(nam));//Changing all strings nam and pass into uppercase
             strcpy(pass,strupr(pass));
             strcpy(user.name,strupr(user.name));
             strcpy(user.password,strupr(user.password));

             if((strcmp(user.name,nam)==0)&&(strcmp(user.password,pass)==0)) //if the combination matches value of c is increased and user id of req user is stored in user.id
             {
                 main_menu();
             }
         }

        fclose(fp);

        title();
        if (c==0)// when no records are found c=0
        {

            gotoxy(10,10); printf("Cannot find the given combination of USER NAME and PASSWORD!\a");
            getch();
        }
        else break; //terminates do... while loop if record found




    } while(1);//not exactly infinite as user is prompted only maximum three times.
}



void main_menu();
{
    do
    {
        title();

        gotoxy(15,8);printf("1. Record Income\n");
        gotoxy(15,10);printf("2. Record Expenditure\n");
        gotoxy(15,12);printf("3. Display Transaction\n");
        gotoxy(15,14);printf("4. Change Username/Password\n");
        gotoxy(15,16);printf("5. Exit\n");


        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,19);printf("Press a choice between the range [1-5] ");

        switch(getch()-48)
        {
        case 1:add_ac();break;
		case 2:deposit();break;        
        case 3:withdraw();break;
        case 4:fund_transfer();break;        
        case 5:
        title();
        gotoxy(15,10); printf("Are you sure you want to exit? <Y/N> : ");
        ex=getche();
        if (ex=='Y'||ex=='y')
        exit(0);


        break;

        default://when entered characted is not between 1-5
        title();
        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 5!");
        gotoxy(26,15); printf("Press any key to return to main menu...");
        getch();

    }

 }while(1);//infinite loop to return to main menu after execution of any function


//return 0;
 }





void edit_user()
{
    char nam[30], pass[30],ch, n_nam[30], n_pass[30]={0},passwrd[30]={0},n_pass1[30]={0};
    int c=0,err=0;
        title();

            gotoxy(25,8);printf("User Name  : ");
            scanf("%s",user.name);
            gotoxy(25,10);printf("Password  : ");
            _password(passwrd);
            strcpy(user.password,passwrd);

        fp=fopen("USER.DAT","r");
         while(fscanf(fp,"%s %s %s\n",user.uid,nam,pass)!=EOF)
         {
             strcpy(nam,strupr(nam));
             strcpy(pass,strupr(pass));
             strcpy(user.name,strupr(user.name));
             strcpy(user.password,strupr(user.password));
             if(strcmp(user.name,nam)==0&&strcmp(user.password,pass)==0) c++;
         }

        fclose(fp);
        title();
        if (c==0)
        {

            gotoxy(10,10); printf("Cannot find the given combination of USER NAME and PASSWORD!\a");
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
                    printf("NEW User Name        : ");
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
                        gotoxy(10,10);
                        printf("Password and confirm password does not match!\a");
                        getch();
                        err++;
                    }

                } while(err!=0);

                fp=fopen("USER.DAT","r");
                tfp=fopen("temp.dat","a");
                while(fscanf(fp,"%s %s %s\n",user.uid,nam,pass)!=EOF)
                {
                    strcpy(nam,strupr(nam));
                    strcpy(pass,strupr(pass));
                    if(strcmp(user.name,nam)!=0||strcmp(user.password,pass)!=0)
                        fprintf(tfp,"%s %s %s\n",user.uid,nam,pass);
                    else
                        fprintf(tfp,"%s %s %s\n",user.uid,n_nam,n_pass);
                }
                fclose(fp);
                fclose(tfp);
                system("del USER.DAT");
                system("ren temp.dat USER.DAT");

                title();
                gotoxy(25,10); printf("Record has been EDITED successfully!");
                getch();
            }


        }

}





//-------------------------------------------------------------------//

void welcome()
{
    int i;
    system("cls");
    rectangle(0,0,80,23);
    gotoxy(27,4); printf("AAMDAANI");
    gotoxy(25,5); for(i=0;i<27;i++) printf("%c",196);
    gotoxy(25,8); printf("Designed and Programmed by:");
    gotoxy(25,9);for(i=0;i<27;i++) printf("%c",196);
    gotoxy(33,11); printf("Namkong Hang Kirat");
    gotoxy(33,13); printf("Neha Adhikari");
    gotoxy(33,15); printf("Kusal Kc");
    gotoxy(33,17); printf("Mala Thapa Magar");
    gotoxy(24,20);

    printf("Press Any key to continue...");


    getch();

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




void cls(int x1,int y1,int x2, int y2)
{
    int i,j;
    for(i=y1;i<=y2;i++)
        for(j=x1;j<=x2;j++)
            {
                gotoxy(j,i); printf("%c",32);
            }

}


void _password(char buffer[])
	{


	     	char c;
         	int pos = 0;
           	do
            	{
           		 c = getch();
            		if( isprint(c) )
            		{
            			buffer[ pos++ ] = c;
            			printf("%c", '*');
            		}
            		else if( c == 8 && pos )
            		{
            			buffer[ pos-- ] = '\0';
            			printf("%s", "\b \b");
           		}
            	}while( c != 13 );
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


void title()
{
    int i;

    system("cls");

    rectangle(0,0,80,23);
    gotoxy(37,2);
    printf("Aamdaani");
    gotoxy(60,4); printf("Date : ");
    _strdate(date);
    date_output(date);
    printf("%s",date);
    _strdate(date);
    gotoxy(1,5);
      for(i=0;i<78;i++) printf("%c",196);

}


COORD coord = {0, 0};

void gotoxy (int x, int y)
        {
        coord.X = x;
        coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }

