#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

/*
	
	Programmer: William Wang

	Description: This program makes an 8 letter password for the user and prints it on a text file.

	Date: 25 September 2019

*/

bool checkcapitals(char password[8])
{

	if (password[0] > 64 && password[0] < 91 || password[1] > 64 && password[1] < 91 || password[2] > 64 && password[2] < 91 || password[3] > 64 && password[3] < 91 || password[4] > 64 && password[4] < 91 || password[5] > 64 && password[5] < 91 || password[6] > 64 && password[6] < 91 || password[7] > 64 && password[7] < 64)
	{
		return true;
	}


	else
	{
		return false;
	}
}

bool checknumbers(char password[8])
{


	if (password[0] > 47 && password[0] < 58 || password[1] > 47 && password[1] < 58 || password[2] > 47 && password[2] < 58 || password[3] > 47 && password[3] < 58 || password[4] > 47 && password[4] < 58 || password[5] > 47 && password[5] < 58 || password[6] > 47 && password[6] < 58 || password[7] > 47 && password[7] < 58)
	{
		return true;
	}


	else
	{
		return false;
	}
}

bool checksymbols(char password[8])
{

	if (password[0] > 31 && password[0] < 48 || password[1] > 31 && password[1] < 48 || password[2] > 31 && password[2] < 48 || password[3] > 31 && password[3] < 48 || password[4] > 31 && password[4] < 48 || password[5] > 31 && password[5] < 48 || password[6] > 31 && password[6] < 48 || password[7] > 31 && password[7] < 48)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool checkallconditions(char password[8]) 
{
	checkcapitals(password);
	checknumbers(password);
	checksymbols(password);

	if (checkcapitals(password) == true && checknumbers(password) == true && checksymbols(password) == true) 
	{
		return true;
	}

	else 
	{
		return false;
	}
}

bool checkconditions2(char password[8], char password2[8]) 
{
	if (password[0] == password2[0] && password[1] == password2[1] && password[2] == password2[2] && password[3] == password2[3] && password[4] == password2[4] && password[5] == password2[5] && password[6] == password2[6] && password[7] == password2[7])
	{
		return true;
	}

	else
	{
		return false;
	}
}

void requirements(string name)
{
	cout << setw(100) << setfill('=') << " " << endl;
	cout << "Hello " << name << endl;
	cout << "Your password must follow these requirements: " << endl;
	cout << "- 8 characters in length" << endl;
	cout << "- One capital letter" << endl;
	cout << "- 1 digit" << endl;
	cout << "- 1 special character" << endl;
	cout << setw(100) << setfill('=') << " " << endl;

	cout << "Enter your password now: " << endl;
}

void enterpassword(char password[8], int hide)
{
	for (int i = 0; i < 8; i++)
	{
		hide = _getwch();
		password[i] = hide;
		cout << password[i];
		Sleep(100);
		cout << "\b*";
	}

	checkallconditions(password);
}

void confirmpassword(char password2[8], char password[8], int hide2)
{
	for (int i = 0; i < 8; i++)
	{
		hide2 = _getwch();
		password2[i] = hide2;
		cout << password2[i];
		Sleep(100);
		cout << "\b*";
	}

	checkconditions2(password, password2);
}

int main()
{
	ofstream passfile;
	string name;
	char password[8];
	char password2[8];
	int hide = 0;
	int hide2 = 0;

	cout << "Programmer: William Wang " << endl;
	cout << "Date: 25 September 2019" << endl;
	cout << setw(100) << setfill('=') << " " << endl;
	cout << "enter your name: ";
	cin >> name;

	system("cls");

	requirements(name);

	enterpassword(password, hide);

	cout << endl;

	if (checkallconditions(password) == true)
	{
		cout << "your password is: " << endl;

		for (int i = 0; i < 8; i++)
		{
			cout << password[i];
		}

		cout << endl;

		cout << "now please confirm your password by typing it again" << endl;

		confirmpassword(password2, password, hide);

		if (checkconditions2(password, password2) == true)
		{
			cout << endl;
			cout << "your final password is: ";
			for (int i = 0; i < 8; i++)
			{
				cout << password[i];
			}

			cout << endl;

			cout << "printing to password.txt";
			
			passfile.open("password.txt");

			passfile << name << "'s password: ";

			for (int i = 0; i < 8; i++)
			{
				passfile << password[i];
			}

			passfile << endl;

			passfile << "this program brought to you by low budget ethan trinh";

			system("pause");

			exit(0);
		}

		else 
		{
			while (checkconditions2(password, password2) == false) 
			{
				cout << "your password was not confirmed, please try again" << endl;

				confirmpassword(password2, password, hide);
				
			}
		}

		if (checkconditions2(password, password2) == true)
		{
			cout << endl;
			cout << "your final password is: ";
			for (int i = 0; i < 8; i++)
			{
				cout << password[i];
			}

			cout << endl;

			cout << "printing to password.txt";

			passfile.open("password.txt");

			passfile << name << "'s password: ";

			for (int i = 0; i < 8; i++)
			{
				passfile << password[i];
			}

			passfile << endl;

			passfile << "this program brought to you by low budget ethan trinh";

			system("pause");

			exit(0);
		}

	}

	if(checkallconditions(password) == false)
	{
		while (checkallconditions(password) == false)
		{
			system("cls");
			requirements(name);
			cout << "your password did not follow the requirements, please try again" << endl;

			if (checkcapitals(password) == false)
			{
				cout << "you are missing a capital letter" << endl;
			}

			if (checknumbers(password) == false)
			{
				cout << "you are missing a digit" << endl;
			}

			if (checksymbols(password) == false)
			{
				cout << "you are missing a symbol" << endl;
			}

			enterpassword(password, hide);
		}

	}

	if (checkallconditions(password) == true)
	{
		cout << "your password is: " << endl;

		for (int i = 0; i < 8; i++)
		{
			cout << password[i];
		}

		cout << endl;

		cout << "now please confirm your password by typing it again" << endl;

		confirmpassword(password2, password, hide);

		if (checkconditions2(password, password2) == true)
		{
			cout << endl;
			cout << "your final password is: ";
			for (int i = 0; i < 8; i++)
			{
				cout << password[i];
			}

			cout << endl;

			cout << "printing to password.txt";

			passfile.open("password.txt");

			passfile << name << "'s password: ";

			for (int i = 0; i < 8; i++)
			{
				passfile << password[i];
			}

			passfile << endl;

			passfile << "this program brought to you by low budget ethan trinh";
		}

		else
		{
			while (checkconditions2(password, password2) == false)
			{
				cout << "your password was not confirmed, please try again" << endl;

				confirmpassword(password2, password, hide);

			}
		}

		if (checkconditions2(password, password2) == true)
		{
			cout << endl;
			cout << "your final password is: ";
			for (int i = 0; i < 8; i++)
			{
				cout << password[i];
			}

			cout << endl;

			cout << "printing to password.txt";

			passfile.open("password.txt");

			passfile << name << "'s password: ";

			for (int i = 0; i < 8; i++)
			{
				passfile << password[i];
			}

			passfile << endl;

			passfile << "this program brought to you by low budget ethan trinh";
		}

	}

	cout << endl;
	system("pause");
	
}