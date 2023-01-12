#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string LONG_ASTERISK =  "****************************************";
const string SHORT_ASTERISK = "************************";

struct itemType {
	int NDB_NO;
	string Long_Name;
	//string GDSN; //Useless
	long GTIN_UPC;
	string Manufacturer;
	//string Date_Modified; //Useless
	//string Date_Available; //Useless
	unordered_set<string> Ingredients;
};




//Required functions:

//Related Group 1
void readFile(ifstream& inFile, vector<itemType>& items);

bool openInputFile(ifstream& inFile);

bool getQuotedString(string& line, int &index, string& subString);

//Related Group 2
bool findIngredient(itemType item, string ingredient);

int searchForIngredient(vector<itemType> items, string ingredient, bool printEnable);

void printRecord(itemType& item);

//Related group 3
string makeStringUpper(string s);

void sort(vector<itemType>& list);


int main() {
	ifstream fin;
	if (!openInputFile(fin)) return -1;
	vector<itemType> items;
	readFile(fin, items);
	fin.close();
	sort(items);
	string line = "";
	while (true) {
		cout << "Enter ingredient: ";
		getline(cin, line);
		line = makeStringUpper(line);
		
		if (line == "Q") break;
		cout << "Searching for items containing " << line << endl;
		cout << LONG_ASTERISK << endl;
		
		int matches = searchForIngredient(items, line, false);
		cout << matches << " items found with the ingredient " << line << endl;
		cout << LONG_ASTERISK << endl;
		
		cout << "Would you like to see a list of items with " << line << " as an ingredient? (y/Y)";
		string show;
		getline(cin, show);
		show = makeStringUpper(show);
		if (show == "Y") searchForIngredient(items, line, true);
		
		cout << LONG_ASTERISK << endl;
		
		cout << "New search" << endl;
		
	}
	
	
	return 0;
}
