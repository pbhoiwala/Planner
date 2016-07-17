
#ifndef PAGES_H
#define	PAGES_H

#include <string>
#include <fstream>
#include <vector>

//#define notes "notes.txt"
#define notes "newNotes.txt"
#define deletednotes "Deletednotes.txt"
using namespace std;



class pages {
public:
	pages();             /// Constructor
	void displayDate();

	void notesMenu();
	void resetFiles();
	void loadDataFile();
	void loadDeletedNotes();


	~pages();
private:
	ifstream notesIn;
	ofstream notesOut;
	ifstream delIn;
	ofstream delOut;

	ifstream tempNotesIn;
	ofstream tempNotesOut;
	vector<string>myVec;
	vector<string>delVec;
};


/*
 - Show completed tasks
 - option to undo completed tasks 
 - option to undo deleted notes
 - line spacing before user's entry "CHOICE:"
*/






#endif	

