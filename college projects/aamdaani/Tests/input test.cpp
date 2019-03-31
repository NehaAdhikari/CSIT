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
char date[13],ttime[10];

void gotoxy(int x,int y); //To move the cursor to x column and y row of output screen
void rectangle(int x,int y,int l,int b);// To make a rectangle starting from (x,y) with length l and breadth b
void currency(char cur[], float n); // To convert a floating number n into currency format in Hindu Arabic Number system. Eg. on execution of the statement currency(cur,123456.789); the value of cur will be "1,23,456.78"
void date_output(char date[]); //To convert date in format mm/dd/yy to dd MMM, yyyy. Eg. 01/01/11 is changed to 01 Jan, 2011
void title(); 
void tran_main_exp(int);




int main()
{
 	int i,sw,type; //int type helps to determine the topic of transaction in the function tran_main_exp(type)
 	title();
		gotoxy(15,8); printf("1. Food & Beverage\n");
        gotoxy(15,10); printf("2. Bills & Utilities\n");
        gotoxy(15,12); printf("3. Shopping\n");
        gotoxy(15,14); printf("4. Transportation\n");
        gotoxy(15,16); printf("5. Friends & Family\n");
		gotoxy(45,8); printf("6. Entertainment\n");
        gotoxy(45,10); printf("7. Health & Fitness\n");
        gotoxy(45,12); printf("8. Gift & Donation\n");
        gotoxy(45,14); printf("9. Others\n");
        gotoxy(45,16); printf("10. Back to Main Menu\n");
        
        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,19); printf("Press a choice between the range [1-10]: ");
        
        scanf("%d",&sw);      
        switch(sw)
        {
        case 1:

            type=1;
			tran_main_exp(type); //it calls a function which records expense transaction


        break;
        
        case 2:


            type=2;
			tran_main_exp(type);


        break;
        
        case 3:

            type=3;
			tran_main_exp(type);

        break;


		case 4:
			
			type=4;
			tran_main_exp(type);
			
        break;

		case 5:
			
			type=5;
			tran_main_exp(type);
			
        break;        

		case 6:
			
			type=6;
			tran_main_exp(type);
			
        break;        

		case 7:
			
			type=7;
			tran_main_exp(type);
			
        break;        

		case 8:
			
			type=8;
			tran_main_exp(type);
			
        break;        

		case 9:
			
			type=9;
			tran_main_exp(type);
			
        break;        
        

        default://when entered characted is not between 1-10
        title();
        gotoxy(10,10); printf("Your input is out of range! Enter a choice between 1 to 10!");
        gotoxy(15,12); printf("Press any key to continue");
        getch();
	}
}



void tran_main_exp(int type)
{
	struct trans trans;
	char ch,curr[35];
	int i;
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
    _strdate(date);
    strcpy(trans._date,date);
    _strtime(ttime);
    strcpy(trans._ttime,ttime);
    gotoxy(5,12); printf("Expense Amount (in NRs.) : "); scanf("%f",&trans.amt);
    
	title();
    currency(curr,trans.amt);
    gotoxy(8,12); printf("%s is to be recorded under [%s] ",curr,trans.t_type);
	gotoxy(1,17); for(i=0;i<78;i++) printf("%c",196);
    gotoxy(8,20);printf("Are you sure you want to perform this tranasction? <Y/N>");
    ch=getch();
    if (ch=='Y'||ch=='y')
    {
	    fp=fopen("EXPENSE_T.DAT","a");
	       	fprintf(fp,"%s %s %s %.2f \n",trans.t_type,trans._date,trans._ttime,trans.amt);
	        fclose(fp);
	        title();
	        gotoxy(20,12);printf("Transaction recorded successfully!");
	        getch();
			main();
	        
		
	}
    else
    main();
    
}
    
//---------------------------------------//
    
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
    
    

void title()
{
    int i;

    system("cls");

    rectangle(0,0,80,23);
    gotoxy(37,2);
    printf("AAMDAANI");
    gotoxy(55,4); printf("Date : ");
    _strdate(date);
    date_output(date);
    printf("%s",date);
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


