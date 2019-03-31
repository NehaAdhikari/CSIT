#include <stdio.h>//For standard I/O Operation
#include <stdlib.h>//To use functions like system(); system("dos command"); - this performs the dos command given. Eg. system("del abc.txt"); - This command deletes the file abc.txt from current location of project
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
    
FILE *fp,*fp1,*fp2;
char date[13],ttime[10];

int main()
{
	struct trans trans,temp;
	fp=fopen("EXPENSE_T.DAT","r");
	while(fscanf(fp,"%s %s %s %2f \n",trans.t_type,trans._date,trans._ttime,trans.amt)!=EOF)
	{
		printf("%s\t",trans.t_type);
		printf("%s\t",trans._date);
		printf("%s\n",trans._ttime);
		printf("%.2f\n",trans.amt);
	}
	getch();
}
