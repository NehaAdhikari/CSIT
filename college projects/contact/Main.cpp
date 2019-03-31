#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

class Draw {
public:
    void box (int x, int y, int h, int w) {
        gotoxy (x, y);        //top
        cout<<(char)(-38);
        for(int i = 1; i <= (w - 2); i++) {
            cout<<(char)(-60);
        }
        cout<<(char)(-65);
        gotoxy(x, y + h - 1);        //bot
        cout<<(char)(-64);
        for(int i = 1; i <= (w - 2); i++) {
            cout<<(char)(-60);
        }
        cout<<(char)(-39);
        gotoxy(x, y+1);     //left vertical
        for(int i = 0; i < h - 2; i++) {
            gotoxy(x, (y + 1 + i));
            cout<<(char)(-77)<<endl;
        }
        gotoxy(x + w - 1, y + 1);     //right vertical
        for(int i = 0; i < h - 2; i++) {
			gotoxy(x + w - 1, (y + 1 + i));
            cout<<(char)(-77)<<endl;
        }
    }

    void divide_horizontal (int x, int y, int w) {
        gotoxy(x, y);
        cout<<(char)(-61);
        for (int  i = 0; i < w-2; i++) {
            cout<<(char)(-60);
        }
        cout<<(char)(-76);
    }

    void gotoxy(int x, int y) {
        COORD coordinate;
        coordinate.X = x;
        coordinate.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
    }
}draw;

class People{
private:
    string landline, cell, name, email;
    bool valid;

public:
	void display(int contact, int location) {
        read (contact);
        draw.box(2, (location * 6) - 4, 6, 75);
		draw.gotoxy(4, (location * 6) - 3);
		cout<<"Name: -\b";
		cout<<name<<endl;
		draw.gotoxy(4, (location * 6) - 2);
		cout<<"Land-line: -\b";
		cout<<landline<<endl;
		draw.gotoxy(4, (location * 6) - 1);
		cout<<"Cellphone: -\b";
		cout<<cell<<endl;
		draw.gotoxy(4, (location * 6));
		cout<<"E-Mail: -\b";
		cout<<email<<endl;
	}

	int _find(string querry){
		ifstream file;
		string buffer;
		int location;
		bool match = false;

		file.open("data.txt");
		if (!file.is_open()) {
			draw.gotoxy(2,1);
			cout<<"Error accessing data file.\n";
			getch();
			exit(-1);
		}

		location = 0;
		while(!file.eof() && !match) {
			getline (file, buffer);
			if (buffer.substr (0, 5) == "BEGIN") {
				location++;
				while (buffer.substr (0, 3) != "END") {
					getline(file, buffer);
					if (buffer.substr (0, 4) == "name" && querry == buffer.substr (5, buffer.length() - 6)) {
						match = true;
						break;
					}
				}
			}
		}

		if (!match) {
			return -1;
		}
		else {
			return location;
		}

		file.close();
	}

    void add () {
    	system ("cls");

    	int y = 5;

    	draw.box(2, y, 12, 76);
    	draw.divide_horizontal(2, y+2, 76);
    	draw.divide_horizontal(2, y+9, 76);

        draw.gotoxy (34, y+1);
        cout<<"NEW CONTACT";
        draw.gotoxy (4, y+4);
        cout<<"Name: -";
        draw.gotoxy (4, y+5);
        cout<<"Land-line: -";
        draw.gotoxy (4, y+6);
        cout<<"Cell phone: -";
        draw.gotoxy (4, y+7);
        cout<<"Email: -";
        draw.gotoxy (16, y+10);
        cout<<"[1] Save";
        draw.gotoxy (50, y+10);
        cout<<"[0] Cancel";

        valid=false;
        while (!valid) {
			draw.gotoxy(10, y+4);
			valid = false;
			{
				char temp[70];
				ifstream file;
				string buffer;

				file.open("data.txt");
				if (!file.is_open()) {
					cout<<"Error accessing data file.\n";
					getch();
					exit(-1);
				}
				cin.getline(temp, 70);
				name=(string)temp;
				cin.sync();
				while(!file.eof()) {
					getline (file, buffer);
					if(buffer.substr(0, 4)=="name") {
						if(name == buffer.substr (5, buffer.length() - 6)) {
							draw.gotoxy (10, y+4);
                            for (unsigned int i = 0; i < name.length(); i++) {
								cout<<" ";
                            }
                            draw.gotoxy(62, y+4);
							cout<<"Already exists!";
                            draw.gotoxy (10, y+4);
                            cout<<"-";
                            valid = false;
							break;
						}
						else {
							valid = true;
						}
					}
				}
				file.close();
			}
        }

        draw.gotoxy(15, y+5);
        {
        	char temp[70];
			cin.getline(temp, 70);
			landline=(string)temp;
			cin.sync();
        }
        draw.gotoxy(16, y+6);
        {
        	char temp[70];
			cin.getline(temp, 70);
			cell=(string)temp;
			cin.sync();
        }

        valid=false;
        while (!valid) {
			draw.gotoxy(11, y+7);
			valid = false;
			{
				char temp[70];
				cin.getline(temp, 70);
				email=(string)temp;
				cin.sync();
			}

			int count = 0;
			for (int unsigned i = 0; i < email.length(); i++) {
				if(email.substr(i,1) == "@") {
					count++;
				}
			}

			if (count != 1 && email.length() != 0) {
				draw.gotoxy(11, y+7);
                int temp = email.length();
                while (temp > 0) {
					cout<<" ";
					temp--;
                }
                draw.gotoxy(11, y+7);
                cout<<"-";

				draw.gotoxy(73, y+7);
				cout<<"!!!";
			}
			else {
				valid = true;
				draw.gotoxy(75, y+7);
				cout<<" ";
			}
        }

        if (name.length() != 0) {
			bool loop = true;
			while (loop) {
				draw.gotoxy (51, y+10);
				{
					char ch;
					ch = getch();

					switch (ch) {
					case '1':
						write("data.txt");
						loop = false;
						break;
					case '0':
						loop = false;
						break;
					}
				}
			}
        }
    }

    unsigned int how_many () {
		unsigned int total = 0;
		string dump;
		ifstream file;

		file.open ("data.txt");
        if (!file.is_open()) {
			cout<<"Error accessing data file.\n";
			getch ();
			exit (-1);
        }

        while (!file.eof()) {
			getline(file, dump);
			total++;
        }

		file.close();
        return total / 6;
    }

    void read (unsigned int contact) {
		ifstream file;
		string buffer;

		file.open("data.txt");
		if (!file.is_open()) {
			cout<<"Error accessing data file.\n";
			getch();
			exit(-1);
		}

		if(!file.eof()) {
			for (int i = (contact * 6) - 6; i > 0; i--) {
				getline (file, buffer);
			}
			getline (file, buffer);

			if (buffer.substr (0, 5) == "BEGIN") {
				while (buffer.substr (0, 3) != "END") {
					getline(file, buffer);

					if (buffer.substr (0, 4) == "name") {
						name = buffer.substr (5, buffer.length() - 6);
					}
					else if (buffer.substr (0, 4) == "land") {
						landline = buffer.substr (5, buffer.length() - 6);
					}
					else if (buffer.substr (0, 4) == "cell") {
						cell = buffer.substr (5, buffer.length() - 6);
					}
					else if (buffer.substr (0, 4) == "mail") {
						email = buffer.substr (5, buffer.length() - 6);
					}
				}
			}
		}
		file.close();
	}

	void write (char *filename) {
		ofstream file;

		file.open (filename, ios::app);
		if (!file.is_open ()) {
			cout<<"Error accessing data file.\n";
			getch();
			exit (-1);
		}

		file<<"BEGIN"<<endl;
		file<<"name:"<<name<<";"<<endl;
		file<<"land:"<<landline<<";"<<endl;
		file<<"cell:"<<cell<<";"<<endl;
		file<<"mail:"<<email<<";"<<endl;
		file<<"END"<<endl;
		file.close();
	}

	void _delete () {
		system ("cls");
		string tempn;
		ifstream file;
		string buffer;

		file.open("data.txt");
		if (!file.is_open()) {
			cout<<"Error accessing data file.\n";
			getch();
			exit(-1);
		}

		draw.gotoxy (33, 1);
		cout<<"DELETE CONTACT";
		cout<<"\n\nEnter the name of the contact to delete";
		cout<<"\nName: -\b";
		cin>>tempn;


	}

	void _search () {
		system("cls");
		string tempn;
		int location;

		draw.gotoxy (33, 1);
		cout<<"SEARCH CONTACT";
		cout<<"\n\nEnter the name of the contact to search";
		cout<<"\nName: -\b";
		cin>>tempn;
		cin.sync();

		system ("cls");
		draw.gotoxy (33, 1);
		cout<<"SEARCH RESULT";

        location = _find(tempn);
        if (location == -1) {
            draw.gotoxy(32, 3);
            cout<<"No match found!!";
            draw.gotoxy(27, 4);
        }
        else {
			display (location, 1);
			draw.gotoxy(27, 8);
        }

        cout<<"Press and key to go back...";
        getch ();
	}

	void edit () {
		system("cls");
		string tempn;
		int location;

		draw.gotoxy (32, 1);
		cout<<"MODIFY CONTACT";
		cout<<"\n\nEnter the name of the contact to edit";
		cout<<"\nName: -\b";
		cin>>tempn;
		cin.sync();

		system ("cls");
		draw.gotoxy (32, 1);
		cout<<"MODIFY CONTACT";
        location = _find(tempn);
        if (location == -1) {
            draw.gotoxy(32, 3);
            cout<<"No match found!";
            draw.gotoxy(27, 4);
        }
        else {
			int y = 3;

			draw.gotoxy (22, 2);
			cout<<"Leave the name field empty to delete this contact";

			draw.box(2, y, 6, 76);
			draw.gotoxy (4, y+1);
			cout<<"Name: -";
			draw.gotoxy (4, y+2);
			cout<<"Land-line: -";
			draw.gotoxy (4, y+3);
			cout<<"Cell phone: -";
			draw.gotoxy (4, y+4);
			cout<<"Email: -";

			valid=false;
			while (!valid) {
				draw.gotoxy(10, y+1);
				valid = false;
				{
					char temp[70];
					ifstream file;
					string buffer;

					file.open("data.txt");
					if (!file.is_open()) {
						cout<<"Error accessing data file.\n";
						getch();
						exit(-1);
					}
					cin.getline(temp, 70);
					name=(string)temp;
					cin.sync();
					while(!file.eof()) {
						getline (file, buffer);
						if(buffer.substr(0, 4)=="name") {
							if(name == buffer.substr (5, buffer.length() - 6)) {
								draw.gotoxy (10, y+1);
								for (unsigned int i = 0; i < name.length(); i++) {
									cout<<" ";
								}
								draw.gotoxy(62, y+1);
								cout<<"Already exists!";
								draw.gotoxy (10, y+1);
								cout<<"-";
								valid = false;
								break;
							}
							else {
								valid = true;
							}
						}
					}
					file.close();
				}
			}

			draw.gotoxy(15, y+2);
			{
				char temp[70];
				cin.getline(temp, 70);
				landline=(string)temp;
				cin.sync();
			}
			draw.gotoxy(16, y+3);
			{
				char temp[70];
				cin.getline(temp, 70);
				cell=(string)temp;
				cin.sync();
			}

			valid=false;
			while (!valid) {
				draw.gotoxy(11, y+4);
				valid = false;
				{
					char temp[70];
					cin.getline(temp, 70);
					email=(string)temp;
					cin.sync();
				}

				int count = 0;
				for (int unsigned i = 0; i < email.length(); i++) {
					if(email.substr(i,1) == "@") {
						count++;
					}
				}

				if (count != 1 && email.length() != 0) {
					draw.gotoxy(11, y+4);
					int temp = email.length();
					while (temp > 0) {
						cout<<" ";
						temp--;
					}
					draw.gotoxy(11, y+4);
					cout<<"-";

					draw.gotoxy(73, y+4);
					cout<<"!!!";
				}
				else {
					valid = true;
					draw.gotoxy(75, y+4);
					cout<<" ";
				}
			}

			{
				fstream tempfile;
				tempfile.open ("temp.txt", ios::in|ios::out);
				tempfile.close();
			}
			if (name.length() != 0) {
				write ("temp.txt");
			}
			for (unsigned int i = 1; i <= how_many(); i++) {
				if (i == location) {
					continue;
				}
				else {
					read (i);
					write ("temp.txt");
				}
			}
			system ("del /f /q data.txt");
			system ("ren temp.txt data.txt");

        }

		draw.gotoxy(23, 9);
        cout<<"Press and key to go back...";
        getch ();
	}
}p;

/*
###p.add###
read data from user and store it temporarily
###########

###p.write###
permanently write the info into file named "data.txt"
#############

###p.read(int n)###
read nth contact from file and store it temporarily
######################

###p.how_many()###
gives the number of contacts stored in the file
##################

use these functions to create a p.search(string name) to search name inside the data.txt file and show it
*/

int main () {
    int ch;
	system ("COLOR f0");
	system ("title Contact Management System");

    while (true) {
		system ("cls");
		system ("mode con:cols=80 lines=23");

		draw.box (25, 5, 11, 29);
		draw.gotoxy (35, 6);
		cout<<"MAIN MENU";
		draw.divide_horizontal(25, 7, 29);
		draw.gotoxy(30, 8);
		cout<<"[1] Add new contact";
			 draw.gotoxy (30, 9);
		cout<<"[2] List contacts";
			 draw.gotoxy (30, 10);
		cout<<"[3] Search contact";
			 draw.gotoxy (30, 11);
		cout<<"[4] Modify contact";
			 draw.gotoxy (30, 12);
		cout<<"[0] Exit";
		draw.divide_horizontal (25, 13, 29);
		draw.gotoxy (30, 14);
		cout<<"Enter your choice: ";
		ch = getch();

		switch (ch) {
		case '1':
			p.add();
			break;
		case '2':
			system("cls");
			if ((7*p.how_many())+5 > 30) {
				char script[100];
				sprintf (script, "mode con:cols=80 lines=%d", (6*p.how_many())+5);
				system (script);
			}
			draw.gotoxy(33,1);
			cout<<"ALL CONTACTS";
			for(unsigned int i=1; i <= p.how_many();i++) {
				p.display(i,i);
			}

			draw.gotoxy (25, (6*p.how_many())+3);
			cout<<"Press any key to go back"<<endl;
			draw.gotoxy (0, 0);
			getch();
			break;
		case '3':
			p._search();
			break;
		case '4':
			p.edit ();
			break;
		case '0':
			cout<<endl<<endl;
			exit (0);
			break;
		default:
			draw.gotoxy (29, 14);
			cout<<"Enter a valid number!";
			getch ();
		}
    }
}
