

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "pages.h"
#include "cover.h"
#include <ctype.h>
#include <Windows.h>

/*
- OPTION TO GO BACK TO MENU (ACCIDENTLY CHOSEN AN OPTION)

*/

bool securityCheck();
using namespace std;



int main(int argc, char** argv) {
	
	bool pass = securityCheck();
	if (pass){

		string menuChoice;
		pages dialer;
		dialer.loadDataFile();
		cover dialer2;
		dialer2.loadWorkFile();

		cout << endl;

		do{
			system("cls");
			cout << endl << endl << endl;
			cout << " *** MENU *** " << endl << endl;
			cout << " [1] - Notes " << endl;
			cout << " [2] - To Do List " << endl;
			cout << " [3] - Exit " << endl;
			cout << " \n CHOICE: ";
			getline(cin, menuChoice);

			while (menuChoice != "1" && menuChoice != "2" && menuChoice != "3")
			{
				cout << " Entery not recognized. Try Again. " << endl;
				cout << "\n CHOICE: ";
				getline(cin, menuChoice);
			}



			if (menuChoice == "1")
			{
				dialer.notesMenu();

			}
			else if (menuChoice == "2")
			{
				dialer2.workMenu();
			}

		} while (menuChoice != "3");

		cout << endl << endl << endl;
		system("pause");
	}
	return 0;
}


bool securityCheck()
{
	bool pass = false;
	string code = "sagan";
	string hint = "universe";
	string checkCode;
	int loopCtr =0;
	while (loopCtr<3)
	{
		cout << endl << endl;
		cout << " Enter the Security Code:   ";
		getline(cin, checkCode);
		if (checkCode == code)
		{
			cout << " Access Granted " << endl;
			pass = true;
			Sleep(1000);
			break;
		}
		else if (checkCode == "hint")
		{
			cout << " Hint: " << hint << endl;			
		}
		else
		{
			cout << " Access Denied " << endl;
			loopCtr++;
			Sleep(1000);
		}
	}

	if (pass) { return true; }
	else { return false; }

}