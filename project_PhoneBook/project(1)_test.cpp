#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<fstream>
#include"Project(1).h"

using namespace std;

int main() {
	List testList(10);
	char cmd;

	do {
		cout << "Commands:" << endl;
		cout << "	R: read from a file" << endl;
		cout << "	+: add a new entry" << endl;
		cout << "	-: remove an entry" << endl;
		cout << "	W:write to a file" << endl;
		cout << "	M:select a month" << endl;
		cout << "	Q: quit the program" << endl;
		cout << endl;

		cin >> cmd;
		cin.ignore();

		switch (cmd)
		{
		case 'R':
			testList.read_file();
			break;
		case '+':
			cout << "Add an entry: " << endl;
			testList.insert();
			break;
		case'-':
			cout << "Remove an entry:" << endl;
			testList.remove();
			break;
		case 'W':
			testList.write_file();
			break;
		case 'M':
			testList.select_Month();
		case'Q':
			break;


		default:
			break;
			cout << endl;
		}
	} while (cmd != 'Q');

	return 0;
}