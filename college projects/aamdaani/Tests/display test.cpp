#include <stdio.h>//For standard I/O Operation
#include <stdlib.h>//To use functions like system(); system("dos command"); - this performs the dos command given. Eg. system("del abc.txt"); - This command deletes the file abc.txt from current location of project
#include <windows.h>//Used in making gotoxy(int, int) function
#include <conio.h>//For getch(); getche() type of functions
#include <time.h>//To get system date and time
#include <math.h>//To calculate mathematical problems, used esp. in interest calculation



struct trans//Structure for storing transaction information
    {
        char t_type[25],_date[15],_ttime[10];
        float amt;
    };

FILE *fp,*fp1,*fp2;
char date[13];

void gotoxy(int x,int y); //To move the cursor to x column and y row of output screen
void rectangle(int x,int y,int l,int b);// To make a rectangle starting from (x,y) with length l and breadth b
void currency(char cur[], float n); // To convert a floating number n into currency format in Hindu Arabic Number system. Eg. on execution of the statement currency(cur,123456.789); the value of cur will be "1,23,456.78"
void title(); 
void tran_main_exp(int);
void disp_main(int);




int main()
{
 	int i, type;
 	title();
		gotoxy(15,8);printf("1. Total Income\n");
        gotoxy(15,10);printf("2. Total Output\n");
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
        

        default://when entered characted is not between 1-8
        title();
        gotoxy(10,10); printf("Your input is out of range! Enter a choice between 1 to 4!");
        gotoxy(15,12); printf("Press any key to continue");
        getch();
    	}
 }



void disp_main(int type)
{
	struct trans trans;
	char ch,curr[35];
    int c,i,j,l,n,x,pg=1;
    int nr;
	switch(type)
	{
        case 1: 
        
        title();

        gotoxy(2,6);puts("SN");
        gotoxy(6,6);puts("     Details");
        gotoxy(35,6); puts("Date");
        gotoxy(50,6); puts("Time");
        gotoxy(60,6);puts("   Amount (NRs.)");
        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
        gotoxy(1,21); for(i=1;i<79;i++) printf("%c",196);
        if(n>l) {n=0; pg=1;}
        i=n;

        gotoxy(2,22); printf("Page : %d out of %d",pg,(int)l/10+1);
        
        
        
        case 2: 
        
        title();

        gotoxy(2,6);puts("SN");
        gotoxy(6,6);puts("     Details");
        gotoxy(35,6); puts("Date");
        gotoxy(50,6); puts("Time");
        gotoxy(60,6);puts("   Amount (NRs.)");
        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
        gotoxy(1,21); for(i=1;i<79;i++) printf("%c",196);
        if(n>l) {n=0; pg=1;}
        i=n;

        gotoxy(2,22); printf("Page : %d out of %d",pg,(int)l/10+1);
        
        
        
        
        
        
        case 3: 
        
        title();

        gotoxy(2,6);puts("SN");
        gotoxy(6,6);puts("     Details");
        gotoxy(35,6); puts("Date");
        gotoxy(50,6); puts("Time");
        gotoxy(60,6);puts("   Amount (NRs.)");
        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
        gotoxy(1,21); for(i=1;i<79;i++) printf("%c",196);
        if(n>l) {n=0; pg=1;}
        i=n;

        gotoxy(2,22); printf("Page : %d out of %d",pg,(int)l/10+1);
        
        
    }
          
    
}
    
    
    //
    
    
    
    
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
    printf("AAMDAANI");
    gotoxy(60,4); printf("Date : ");
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


