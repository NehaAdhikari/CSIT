#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;


class People{
private:
    string landline, cell, name, email;
    bool valid;

public:
	void display(int contact, int location) {
        read (contact);
		cout<<"Name: -\b";
		cout<<name<<endl;
		cout<<"Land-line: -\b";
		cout<<landline<<endl;
		cout<<"Cellphone: -\b";
		cout<<cell<<endl;
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
        cout<<"NEW CONTACT";
        cout<<"Name: -";
        cout<<"Land-line: -";
        cout<<"Cell phone: -";
        cout<<"Email: -";
        cout<<"[1] Save";
        cout<<"[0] Cancel";

        valid=false;
        while (!valid) {
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
				while(!file.eof()) {
					getline (file, buffer);
					if(buffer.substr(0, 4)=="name") {
						if(name == buffer.substr (5, buffer.length() - 6)) {
                            for (unsigned int i = 0; i < name.length(); i++) {
								cout<<" ";
                            }
							cout<<"Already exists!";
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
        {
        	char temp[70];
			cin.getline(temp, 70);
			landline=(string)temp;
        }
        {
        	char temp[70];
			cin.getline(temp, 70);
			cell=(string)temp;
        }

        valid=false;
        while (!valid) {
			valid = false;
			{
				char temp[70];
				cin.getline(temp, 70);
				email=(string)temp;
			}

			int count = 0;
			for (int unsigned i = 0; i < email.length(); i++) {
				if(email.substr(i,1) == "@") {
					count++;
				}
			}

			if (count != 1 && email.length() != 0) {
                int temp = email.length();
                while (temp > 0) {
					cout<<" ";
					temp--;
                }
                cout<<"-";

				cout<<"!!!";
			}
			else {
				valid = true;
				cout<<" ";
			}
        }

        if (name.length() != 0) {
			bool loop = true;
			while (loop) {
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
		cout<<"DELETE CONTACT";
		cout<<"\n\nEnter the name of the contact to delete";
		cout<<"\nName: -\b";
		cin>>tempn;


	}

	void _search () {
		system("cls");
		string tempn;
		int location;
		cout<<"SEARCH CONTACT";
		cout<<"\n\nEnter the name of the contact to search";
		cout<<"\nName: -\b";
		cin>>tempn;

		system ("cls");
		cout<<"SEARCH RESULT";

        location = _find(tempn);
        if (location == -1) {
            cout<<"No match found!!";
        }
        else {
			display (location, 1);
        }

        cout<<"Press and key to go back...";
        getch ();
	}

	void edit () {
		system("cls");
		string tempn;
		int location;
		cout<<"MODIFY CONTACT";
		cout<<"\n\nEnter the name of the contact to edit";
		cout<<"\nName: -\b";
		cin>>tempn;

		system ("cls");
		cout<<"MODIFY CONTACT";
        location = _find(tempn);
        if (location == -1) {
            cout<<"No match found!";
        }
        else {
			int y = 3;

			cout<<"Leave the name field empty to delete this contact";

			cout<<"Name: -";
			cout<<"Land-line: -";
			cout<<"Cell phone: -";
			cout<<"Email: -";

			valid=false;
			while (!valid) {
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
					while(!file.eof()) {
						getline (file, buffer);
						if(buffer.substr(0, 4)=="name") {
							if(name == buffer.substr (5, buffer.length() - 6)) {
								for (unsigned int i = 0; i < name.length(); i++) {
									cout<<" ";
								
							}
								cout<<"Already exists!";
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
			{
				char temp[70];
				cin.getline(temp, 70);
				landline=(string)temp;
			}
			{
				char temp[70];
				cin.getline(temp, 70);
				cell=(string)temp;
			}

			valid=false;
			while (!valid) {
				valid = false;
				{
					char temp[70];
					cin.getline(temp, 70);
					email=(string)temp;
				}

				int count = 0;
				for (int unsigned i = 0; i < email.length(); i++) {
					if(email.substr(i,1) == "@") {
						count++;
					}
				}

				if (count != 1 && email.length() != 0) {
					int temp = email.length();
					while (temp > 0) {
						cout<<" ";
						temp--;
					}
					cout<<"-";
					cout<<"!!!";
				}
				else {
					valid = true;
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

    while (true) {
		system ("cls");
		system ("mode con:cols=80 lines=23");
		cout<<"MAIN MENU";
		cout<<"[1] Add new contact";
		cout<<"[2] List contacts";
		cout<<"[3] Search contact";
		cout<<"[4] Modify contact";
		cout<<"[0] Exit";
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
			cout<<"ALL CONTACTS";
			for(unsigned int i=1; i <= p.how_many();i++) {
				p.display(i,i);
			}

			cout<<"Press any key to go back"<<endl;
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
			cout<<"Enter a valid number!";
			getch ();
		}
    }
}
