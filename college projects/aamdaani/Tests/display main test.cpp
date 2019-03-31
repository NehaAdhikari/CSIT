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
    };

struct user//Structure for storing User information
    {
        char name[30], password[30];

    };
    
FILE *fp,*tfp;
char date[13],ttime[10];

void gotoxy(int x,int y); //To move the cursor to x column and y row of output screen
void _password(char buffer[]);// To input password from user so that asterik (*) is displayed for each character entered. Similar to gets(string); function
void rectangle(int x,int y,int l,int b);// To make a rectangle starting from (x,y) with length l and breadth b
void currency(char cur[], float n); // To convert a floating number n into currency format in Hindu Arabic Number system. Eg. on execution of the statement currency(cur,123456.789); the value of cur will be "1,23,456.78"
void date_output(char date[]); //To convert date in format mm/dd/yy to dd MMM, yyyy. Eg. 01/01/11 is changed to 01 Jan, 2011
void welcome();// Displays welcome screen that you see as soon as program is executed
void title(); //Clears the screen and displays program title and Current date on top of Screen

void disp_main(int);

int main()
{
 	int i, type;
 	title();
		gotoxy(15,9);printf("1. Income\n");
        gotoxy(15,11);printf("2. Expense\n");
        gotoxy(15,13);printf("3. Overall\n");
        gotoxy(15,15);printf("4. Back to Main Menu\n");

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
        

        default://when entered characted is not between 1-8
        title();
        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 4!");
        gotoxy(26,15); printf("Press any key to continue");
        getch();
        main();
	    }
 }
 
 void disp_main(int type)
{
	struct trans trans,read;
	char ch,curr[35];
    int c,i,j,l,n,x,pg=1;
    int nr;
	switch(type)
	{
        case 1: 
        {
	        title();
	        gotoxy(2,6);puts("SN");
	        gotoxy(10,6);puts("Transaction Type");
	        gotoxy(45,6); puts("Date");
	        gotoxy(63,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        gotoxy(1,21); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("INCOME_T","r");
	        while(fscanf(fp,"%s %s %s %f\n",read.t_type,read._date,read._ttime,read.amt)!=EOF)
	        {
	        	for(i=1;i<20;i++)
	        	{
	        		gotoxy(2,8+i);printf("%s",read.t_type);
	        		gotoxy(2,8+i);printf("%s",read._date);
	        		gotoxy(2,8+i);printf("%s",read._ttime);
	        		gotoxy(2,8+i);printf("%.2f",read.amt);
				}
			}
			scanf("%d",&j);
	    }
        
        case 2: 
        {
	        title();
	
	        gotoxy(2,6);puts("SN");
	        gotoxy(8,6);puts("Details");
	        gotoxy(30,6); puts("Date");
	        gotoxy(60,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        gotoxy(1,21); for(i=1;i<79;i++) printf("%c",196);
	        if(n>l) {n=0; pg=1;}
	        i=n;
	
	        gotoxy(2,22); printf("Page : %d out of %d",pg,(int)l/10+1);
	        
	    }
        
        
        
        
        case 3: 
        {
	        title();
	
	        gotoxy(2,6);puts("SN");
	        gotoxy(8,6);puts("Details");
	        gotoxy(30,6); puts("Date");
	        gotoxy(60,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        gotoxy(1,21); for(i=1;i<79;i++) printf("%c",196);
	        if(n>l) {n=0; pg=1;}
	        i=n;
	
	        gotoxy(2,22); printf("Page : %d out of %d",pg,(int)l/10+1);
	    }
        
    }
          
    
}




//--------------------------------------------------------//

void welcome()
{
    int i;
    system("cls");
    rectangle(0,0,80,23);
    gotoxy(37,3); printf("AAMDAANI");
    gotoxy(25,5); for(i=0;i<30;i++) printf("%c",196);
    gotoxy(35,7); printf("Project By:");
    gotoxy(25,9);for(i=0;i<30;i++) printf("%c",196);
    gotoxy(33,11); printf("Namkong Hang Kirat");
    gotoxy(33,13); printf("Neha Adhikari");
    gotoxy(33,15); printf("Kusal Kc");
    gotoxy(33,17); printf("Mala Thapa Magar");
    gotoxy(29,20);
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
    gotoxy(55,4); printf("Date : ");
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

