#include "pages.h"
#include "cover.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <Windows.h>

using namespace std;

cover::cover()
{
	bool Inopen = todoIn.is_open();
	if (!Inopen) { todoIn.open(worklist, fstream::app); }
	bool Outopen = todoOut.is_open();
	if (!Outopen) { todoOut.open(worklist, fstream::app); }
	if (todoIn.fail()) {
		cerr << " Error: Unable to open File: " << worklist << endl;
	}
	if (todoOut.fail()){
		cerr << " Error: Unable to open File: " << worklist << endl;
	}

}


void cover::workMenu()
{
	string workChoice = "";
	workToDo mywork;
	cout << endl;
	while (true)
	{
		if (workChoice != "2")
		{
			system("cls");
			displayTodaysTasks();
			cout << endl << endl;
		}
		cout << endl << endl << endl;
		cout << " *** WORK TO DO *** " << endl << endl;

		cout << " [1] - Add New Task " << endl;
		cout << " [2] - Show Tasks " << endl;
		cout << " [3] - Edit a Task " << endl;
		cout << " [4] - Back to Menu " << endl;
		cout << "\n CHOICE: ";
		getline(cin, workChoice);

		while (workChoice != "1" && workChoice != "2" && workChoice != "3" && workChoice != "4")
		{
			cout << " Entry not recognized! Try Again " << endl;
			cout << " Your Choice: ";
			getline(cin, workChoice);
		}


		if (workChoice == "1")
		{
			system("cls");
			cout << endl << endl;
			cout << " Add stuff to do: " << endl << endl;
			cout << " Work to do: ";
			getline(cin, mywork.workName);

			if (!mywork.workName.empty()){

				cout << " Due  date (MMDD): ";
				cin >> mywork.dueDate;
				//cin >> mywork.dueDateM >> mywork.dueDateD;
				//getline(cin, mywork.dueDate);    
				convertDate(mywork.dueDate, mywork.month, mywork.dueDateD);

				cout << " Priority (1=Top <-> 5=Low)  : ";
				cin.ignore();
				getline(cin, mywork.priority);
				while (mywork.priority != "1" && mywork.priority != "2" &&mywork.priority != "3" &&mywork.priority != "4" &&mywork.priority != "5")
				{
					cout << " You can only set priority from 1 to 5 with 1 being the Top " << endl;
					cout << " Priority (1=Top <-> 5=Low)  : ";
					getline(cin, mywork.priority);
				}
				char a = mywork.priority[0];
				mywork.priorityNum = a - '0';
				mynewVec.push_back(mywork);


				todoOut << mywork.workName << "," << mywork.dueDate << "," << mywork.priorityNum << endl;
				//todoOut << mywork.workName << ", "/* << mywork.dueDate << ", "*/ << mywork.priorityNum << endl;
				//todoOut << mywork.workName << ", " << mywork.dueDateM << "-" << mywork.dueDateD << ", " << mywork.priorityNum << endl;
				resetFiles();
				cout << " Task Added to the list " << endl << endl << endl;
				Sleep(500);
			}
		}

		else if (workChoice == "2")
		{
			system("cls");
			if (mynewVec.size() == 0){ cout << " You do not have any tasks " << endl; 
			Sleep(500);
			break; }
			else{
				string viewChoice;
				cout << endl << endl << endl;
				cout << " How do you want to view your tasks " << endl;
				cout << " [1] - Priority " << endl;
				cout << " [2] - Due Date " << endl;
				cout << " [3] - Back to Menu " << endl;
				cout << "\n CHOICE: ";
				getline(cin, viewChoice);

				while (viewChoice != "1" && viewChoice != "2" && viewChoice != "3")
				{
					cout << " Entry not recognized! Try Again " << endl;
					cout << "\n CHOICE: ";
					getline(cin, viewChoice);
				}


				if (viewChoice == "1")
				{
					system("cls");
					cout << " Tasks To Do (by Priority): " << endl << endl;
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < mynewVec.size(); j++)
						{
							if (mynewVec[j].priorityNum == i + 1)
							{
								cout << " " << mynewVec[j].workName << " - " << mynewVec[j].month << " " << mynewVec[j].dueDateD << " - " << mynewVec[j].priorityNum << endl;
							}
						}
					}
				}
				else if (viewChoice == "2")
				{
					system("cls");
					cout << " Tasks To Do (by Deadline): " << endl << endl;

					for (int jan = 101; jan <= 131; jan++)
					{
						checkMonth(jan);
					}
					for (int feb = 201; feb <= 229; feb++)
					{
						checkMonth(feb);
					}
					for (int mar = 301; mar <= 331; mar++)
					{
						checkMonth(mar);
					}
					for (int apr = 401; apr <= 430; apr++)
					{
						checkMonth(apr);
					}
					for (int may = 501; may <= 531; may++)
					{
						checkMonth(may);
					}
					for (int jun = 601; jun <= 630; jun++)
					{
						checkMonth(jun);
					}
					for (int jul = 701; jul <= 731; jul++)
					{
						checkMonth(jul);
					}
					for (int aug = 801; aug <= 831; aug++)
					{
						checkMonth(aug);
					}
					for (int sep = 901; sep <= 930; sep++)
					{
						checkMonth(sep);
					}
					for (int oct = 1001; oct <= 1031; oct++)
					{
						checkMonth(oct);
					}
					for (int nov = 1101; nov <= 1130; nov++)
					{
						checkMonth(nov);
					}
					for (int dec = 1201; dec <= 1231; dec++)
					{
						checkMonth(dec);
					}

				}
				else if (viewChoice == "3"){}
			}
		}
		else if (workChoice == "3")
		{
			system("cls");
			if (mynewVec.size() == 0) { cout << " You do not have any tasks " << endl; 
			Sleep(500);
			break; }
			cout << " *** Edit a Task *** " << endl << endl;
			cout << " Pick a Task to Edit " << endl << endl;
			string taskEdit;
			int taskToEdit;
			for (int i = 0; i < mynewVec.size(); i++)
			{
				cout << " " << i + 1 << " - " << mynewVec[i].workName << " <-> " << mynewVec[i].month << mynewVec[i].dueDateD << " <-> " << " Pri: " << mynewVec[i].priorityNum << endl;
			}
			cout << " " << mynewVec.size()+1 << " - Back to Menu " << endl;
			cout << "\n CHOICE: ";
			getline(cin, taskEdit);
			taskToEdit = stoi(taskEdit);
			if (taskToEdit == mynewVec.size()+1) { break; }
			while (taskToEdit <= 0 || taskToEdit > mynewVec.size()+1)
			{
				cout << " Invalid Entry! Try Again " << endl;
				cout << "\n CHOICE: ";
				getline(cin, taskEdit);
				taskToEdit = stoi(taskEdit);
			}
			system("cls");
			cout << endl << endl;
			string editS;
			int edit;

			cout << " * " << mynewVec[taskToEdit - 1].workName << " <-> " << mynewVec[taskToEdit - 1].month << " " << mynewVec[taskToEdit - 1].dueDateD << " <-> " << " Pri: " << mynewVec[taskToEdit - 1].priorityNum << endl;
			cout << endl;
			cout << " [1] - Mark as Completed " << endl;
			cout << " [2] - Change the Task(name) " << endl;
			cout << " [3] - Change the Due Date " << endl;
			cout << " [4] - Change its Priority " << endl;
			cout << " [5] - Back to Menu " << endl;
			cout << "\n CHOICE: ";
			getline(cin, editS);
			while (editS != "1" && editS != "2" && editS != "3" && editS != "4" && editS != "5") {
				cout << " Invalid Entry! Try Again " << endl;
				cout << "\n CHOICE: ";
				getline(cin, editS);
			}
			edit = stoi(editS);
			
			if (edit == 1)
			{
				mynewVec.erase(mynewVec.begin() + (taskToEdit - 1));
				cout << " Good Job! Task marked as Completed " << endl << endl;
				Sleep(500);
			}
			else if (edit == 2)
			{
				cout << " Enter the new name of the Task:\n ";
				string newTask;
				getline(cin, newTask);
				mynewVec[taskToEdit - 1].workName = newTask;
				cout << " Task Name updated!" << endl << endl;
				Sleep(500);
			}
			else if (edit == 3)
			{
				string newDue;
				int newDue1;
				string newMon;
				int newDD;
				cout << " Enter the new deadline (MMDD):  ";
				getline(cin, newDue);
				newDue1 = stoi(newDue);
				convertDate(newDue1, newMon, newDD);
				mynewVec[taskToEdit - 1].dueDate = newDue1;
				mynewVec[taskToEdit - 1].dueDateD = newDD;
				mynewVec[taskToEdit - 1].month = newMon;
				cout << " Deadline updated " << endl << endl;
				Sleep(500);
			}
			else if (edit == 4)
			{
				string newPri;
				int newPri1;
				cout << " Enter the new priority for the taks: ";
				
				getline(cin, newPri);
				newPri1 = stoi(newPri);
				while (newPri1 <= 0 || newPri1 > 5){
					cout << " You can only set priority from 1 to 5 with 1 being the Top " << endl;
					cout << " Priority (1=Top <-> 5=Low)  : ";
					getline(cin, newPri);
					newPri1 = stoi(newPri);
				}
				mynewVec[taskToEdit - 1].priorityNum = newPri1;
				cout << " Task's priority updated" << endl << endl;
				Sleep(500);
			}
			else if (edit == 5) { break; }

			todoIn.close();
			todoOut.close();
			todoIn.open(worklist);
			todoOut.open(worklist);

			for (int k = 0; k < mynewVec.size(); k++)
			{
				todoOut << mynewVec[k].workName << "," << mynewVec[k].dueDate << "," << mynewVec[k].priorityNum << endl;
			}
			resetFiles();

		}
		else if (workChoice == "4")
		{
			break;
		}

	}
	return;
}


void cover::checkMonth(int mon)
{
	for (int i = 0; i < mynewVec.size(); i++)
	{
		if (mynewVec[i].dueDate == mon)
		{
			cout << " - " << mynewVec[i].workName << " -> " << mynewVec[i].month << " " << mynewVec[i].dueDateD << " -> "	<< mynewVec[i].priorityNum << endl;
		}
	}

}




void cover::convertDate(int monthI, string& monthS, int & date)
{
	date = monthI % 100;
	monthI = (monthI - date)/100;

	if (monthI == 1){ monthS = "JAN"; }
	else if (monthI == 2){ monthS = "FEB"; }
	else if(monthI == 3){ monthS = "MAR"; }
	else if (monthI == 4){ monthS = "APR"; }
	else if (monthI == 5){ monthS = "MAY"; }
	else if (monthI == 6){ monthS = "JUN"; }
	else if (monthI == 7){ monthS = "JUL"; }
	else if (monthI == 8){ monthS = "AUG"; }
	else if (monthI == 9){ monthS = "SEP"; }
	else if (monthI == 10){ monthS = "OCT"; }
	else if (monthI == 11){ monthS = "NOV"; }
	else if (monthI == 12){ monthS = "DEC"; }
	else { monthS = "???"; }

	//cout << " It is due on " << monthS << " " << date << endl;
}


void cover::resetFiles()
{
	todoIn.close();
	todoOut.close();
	todoIn.open(worklist, fstream::app);
	todoOut.open(worklist, fstream::app);
	if (todoIn.fail()) {
		cerr << " Error: Unable to open File: " << worklist << endl;
	}
	if (todoOut.fail()){
		cerr << " Error: Unable to open File: " << worklist << endl;
	}


}

void cover::loadWorkFile()
{
	resetFiles();
	string tempWork;
	string tempDueDate;
	string tempPriNum;
	workToDo loadWork;

	while (!todoIn.eof())
	{
		
		getline(todoIn, tempWork,',');
		if (tempWork == "\n" || tempWork.empty() || tempWork == "" || tempWork == " ") { 
			//cout << " empty";
			break;
		}
		else{
			getline(todoIn, tempDueDate, ',');
			getline(todoIn, tempPriNum, '\n');
			loadWork.workName = tempWork;
			loadWork.dueDate = stoi(tempDueDate);
			loadWork.priorityNum = stoi(tempPriNum);
			convertDate(loadWork.dueDate, loadWork.month, loadWork.dueDateD);
			mynewVec.push_back(loadWork);
			//cout << " work name is '" << loadWork.workName << "' & due month is '" << loadWork.month << "' & due date is '" << loadWork.dueDateD << "' & pri is '" << loadWork.priorityNum << "' " << endl;
			//cout << " " << loadWork.workName << " is due on " << loadWork.month << " " << loadWork.dueDateD << endl;
		}
	}



}


void cover::displayTodaysTasks()
{
	char date[9];
	string monthToday;
	string year;
	_strdate_s(date);
	//cout << date << endl;

	if (date[0] == '0' && date[1] == '1')
	{
		monthToday = "JAN";
	}

	else if (date[0] == '0' && date[1] == '2')
	{
		monthToday = "FEB";
	}
	else if (date[0] == '0' && date[1] == '3')
	{
		monthToday = "MAR";
	}
	else if (date[0] == '0' && date[1] == '4')
	{
		monthToday = "APR";
	}
	else if (date[0] == '0' && date[1] == '5')
	{
		monthToday = "MAY";
	}
	else if (date[0] == '0' && date[1] == '6')
	{
		monthToday = "JUN";
	}
	else if (date[0] == '0' && date[1] == '7')
	{
		monthToday = "JUL";
	}
	else if (date[0] == '0' && date[1] == '8')
	{
		monthToday = "AUG";
	}
	else if (date[0] == '0' && date[1] == '9')
	{
		monthToday = "SEP";
	}
	else if (date[0] == '1' && date[1] == '0')
	{
		monthToday = "OCT";
	}
	else if (date[0] == '1' && date[1] == '1')
	{
		monthToday = "NOV";
	}
	else if (date[0] == '1' && date[1] == '2')
	{
		monthToday = "DEC";
	}
	else
	{
		monthToday = "???";
	}
	cout << " \n Today is";
	cout << " " << monthToday << " " << date[3] << date[4] << ", 20" << date[6] << date[7] << endl;
	// display today's task

	int d11 = date[3] - '0';
	int d22 = date[4] - '0';
	bool disp1time = true;
	for (int l = 0; l < mynewVec.size(); l++)
	{
		if (mynewVec[l].month == monthToday)
		{
			int d1 = mynewVec[l].dueDateD / 10;
			int d2 = mynewVec[l].dueDateD % 10;
			if ((d1 == d11) && (d2 == d22))
			{
				if (disp1time) { cout << " Things to Do Today: " << endl << endl; }
				cout << " - " << mynewVec[l].workName << endl;
				disp1time = false;
			}

		}
	}
	if (disp1time) { cout << " You do not have anything due today " << endl << endl; }
	cout << endl << " ************************** " << endl;





}

cover::~cover()
{
	todoIn.close();
	todoOut.close();
}

