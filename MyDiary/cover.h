
#ifndef COVER_H
#define	COVER_H

#include <string>
#include <fstream>
#include <vector>

//#define worklist "worklist.txt"
#define worklist "newWorklist.txt"
using namespace std;



class cover {
public:
	cover();             /// Constructor
	void displayDate();

	void workMenu();
	void resetFiles();
	void convertDate(int monthI, string& monthS, int& date);
	void checkMonth(int mon);
	void loadWorkFile();
	void displayTodaysTasks();
	struct workToDo{
		string workName;
		string priority;
		int dueDate;
		int dueDateM;
		int dueDateD;
		string month;
		int priorityNum;
	};



	~cover();
private:
	ifstream todoIn;
	ofstream todoOut;
	vector<workToDo>mynewVec;
};

#endif	

