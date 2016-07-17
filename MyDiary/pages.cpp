#include "pages.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <Windows.h>
using namespace std;

pages::pages()
{
	bool inOpen = notesIn.is_open();
	if (!inOpen) { notesIn.open(notes, fstream::app); }
	
	bool outOpen = notesOut.is_open();
	if (!outOpen) { notesOut.open(notes, fstream::app); }
	
	bool delInOpen = delIn.is_open();
	if (!delIn) { delIn.open(deletednotes, fstream::app); }

	bool delOutOpen = delOut.is_open();
	if (!delOut) { delOut.open(deletednotes, fstream::app); }
	

	if (notesIn.fail()) {
		cerr << " Error: Unable to open File: " << notes << endl;
	}
	if (notesOut.fail()){
		cerr << " Error: Unable to open File: " << notes << endl;
	}
	if (delIn.fail()){
		cerr << " Error: Unable to open File: " << deletednotes << endl;
	}
	if (delOut.fail()){
		cerr << " Error: Unable to open File: " << deletednotes << endl;
	}


}



void pages::notesMenu()
{
	
	string notesChoice = "";	
	cout << endl << endl << endl;
	while (true){
		if (notesChoice != "2" && notesChoice != "4")
		{
			system("cls");
		}
		cout << endl << endl;
		cout << " *** NOTES *** " << endl << endl;

		cout << " [1] - Add Notes " << endl;
		cout << " [2] - Display Notes " << endl;
		cout << " [3] - Edit Notes " << endl;
		cout << " [4] - Deleted Notes " << endl;
		cout << " [5] - Back to Menu " << endl;
		cout << endl;
		cout << "\n CHOICE: ";
		getline(cin, notesChoice);

		//cout << " I got " << notesChoice << " as your option " << endl;
		/// If entry is invalid
		while (notesChoice != "1" && notesChoice != "2" && notesChoice != "3" && notesChoice != "4" &&  notesChoice != "5")
		{
			cout << " Entry not recognized! Try Again " << endl;
			cout << " Your Choice: ";
			getline(cin, notesChoice);
		}

		if (notesChoice == "1") // add notes
		{
			system("cls");
			cout << " Add Notes " << endl;
			string addNotes = "a";
			//cout << endl << " - ";
			//getline(cin, addNotes);
			//notesOut << addNotes;
			//myVec.push_back(addNotes);
			while (!addNotes.empty())
			{
				//cout << endl << " - ";
				cout << " - ";
				getline(cin, addNotes);
				if (addNotes.empty()) { break; }
				//notesOut << endl << addNotes;
				notesOut << addNotes << endl;
				myVec.push_back(addNotes);
			}
			//notesOut << endl;
			resetFiles();
			cout << " Your Notes have been added to the file!" << endl;
			Sleep(500);
		} // choice 1
		else if (notesChoice == "2")   /// Display Notes
		{
			system("cls");
			if (myVec.size() == 0){ cout << " You do not have any notes " << endl << endl; }
			else{
				cout << " \n Your Notes " << endl;
				string getNotes;
				/*while (!notesIn.eof())
				{
				getline(notesIn, getNotes);
				cout << endl << " - " << getNotes;
				} // while eof  */

				for (int i = 0; i < myVec.size(); i++)
				{
					cout << endl << " - " << myVec[i];
				}


				resetFiles();
			}
			cout << endl << endl;
		} // choice 2
		else if (notesChoice == "3")
		{
			system("cls");
			if (myVec.size() == 0) { cout << " You do not have any notes " << endl << endl;
			Sleep(500);
			break;
			}
			else{
				cout << " Your Notes " << endl << endl;
				string getNotes2;
				int counter = 0;
				/*while (!notesIn.eof())
				{
				getline(notesIn, getNotes2);
				cout << endl << " " << counter+1 << " - " << getNotes2;
				counter++;
				} // while eof  */
				for (int j = 0; j < myVec.size(); j++)
				{
					cout << endl << " " << j + 1 << " - " << myVec[j];
				}
				cout << endl << " " << myVec.size()+1 << " - Back to Menu " << endl;

				resetFiles();
				cout << endl << endl;
				string editStr;
				int edit;
				cout << " Which one would you like to edit? : ";
				getline(cin, editStr);
				edit = stoi(editStr);
				//cin >> edit;
				if (edit == myVec.size()+1){ break; }
				else{
					while (edit < 0 || edit>myVec.size())
					{
						cout << " Invalid Entry. Try Again!" << endl;
						cout << " Which one would you like to edit? ";
						cin >> edit;
					} // while invalid entry
					cout << " * " << myVec[edit - 1] << endl << endl;
					string editedNote;
					string iterateLn; // iterate through notes until the one to edit is found
					cout << " Enter the changed line (or just hit enter to delete the whole line)" << endl << " ";
					//cin.ignore();
					getline(cin, editedNote);

					if (editedNote.empty()) 
					{
						delOut << myVec[edit - 1] << endl;
						myVec.erase(myVec.begin() + (edit - 1)); 					
					}
					else {
						myVec[edit - 1] = editedNote;
					}

					notesIn.close();
					notesOut.close();
					notesIn.open(notes);
					notesOut.open(notes);
					
					for (int k = 0; k < myVec.size(); k++)
					{
						notesOut << myVec[k] << endl;
					}


					/*
					// copy needed notes to temp file and don't copy the one to delete
					for (int i = 1; i < edit; i++)
					{
					getline(notesIn, iterateLn);
					if (i != edit)
					{
					tempNotesOut << editedNote << endl;
					} // if
					else if (i == edit)
					{
					tempNotesOut << editedNote << endl;
					}

					} // for
					// copy temp file to original
					tempNotesIn.close();
					tempNotesOut.close();
					tempNotesIn.open(notes, fstream::app);
					tempNotesOut.open(notes, fstream::app);
					notesIn.close();
					notesOut.close();
					notesIn.open(notes); // clear files
					notesOut.open(notes);
					string copyNotes;

					while (!tempNotesIn.eof())
					{
					getline(tempNotesIn, copyNotes);
					notesOut << copyNotes;
					}*/
				} // don't go to menu
				resetFiles();
				cout << " Your Desired Changes have been saved " << endl << endl;
				Sleep(500);
			} // exit else statement for if myvec is not empty

		} // choice 3
		else if (notesChoice == "4")
		{
			system("cls");
			cout << endl << " Deleted Notes " << endl << endl;
			delVec.clear();
			loadDeletedNotes();
			for (int d = 0; d < delVec.size(); d++)
			{
				cout << " " << d + 1 << " - " << delVec[d] << endl;
			}





		}
		else if (notesChoice == "5")
		{
			break;
		}


	}

	return;
}

void pages::loadDataFile()
{
	resetFiles();
	string loadNotes;
	//cout << " in loadDataFile function" << endl;
	
	while (!notesIn.eof())
	{
		getline(notesIn, loadNotes);
		//cout << " getting " << loadNotes << " from file" << endl;
		if (!loadNotes.empty())
		{
			myVec.push_back(loadNotes);
		}
	}
}

void pages::loadDeletedNotes()
{
	resetFiles();
	string delLines;

	while (!delIn.eof())
	{
		getline(delIn, delLines);
		if (!delLines.empty())
		{
			delVec.push_back(delLines);
		}

	}




}






void pages::resetFiles()
{
	notesOut.close();
	notesIn.close();
	delIn.close();
	delOut.close();

	notesIn.open(notes, fstream::app);
	notesOut.open(notes, fstream::app);	
	delIn.open(deletednotes, fstream::app);
	delOut.open(deletednotes, fstream::app);

	if (notesIn.fail()) {
		cerr << " Error: Unable to open File: " << notes << endl;
	}
	if (notesOut.fail()){
		cerr << " Error: Unable to open File: " << notes << endl;
	}
	if (delIn.fail()){
		cerr << " Error: Unable to open File: " << deletednotes << endl;
	}
	if (delOut.fail()){
		cerr << " Error: Unable to open File: " << deletednotes << endl;
	}
}


pages::~pages()
{
	notesOut.close();
	notesIn.close();
	delIn.close();
	delOut.close();
}