#include<iostream>
#include"Project2_MicroFacebook.h"

using namespace std;

void main() {
	Person person;
	char cmd;
	char name1[20], name2[20];

	while (1) {
		cout << endl;
		cout << "<Show people and friends>" << endl;
		person.showstructure();
		cout << endl;
		
		cout << "Command: ";
		cin >> cmd;
		cout << endl;
		if (cmd == 'X') {
			break;
		}
		else if (cmd == 'P'||cmd=='L') {
			cin >> name1;
			switch (cmd){
			case'P':
				person.P(name1);
				break;
			case'L':
				person.L(name1);
				break;
			default:
				break;
			}
		}
		else if(cmd=='F'||cmd=='U'||cmd=='Q') {
			cin >> name1 >> name2;
			switch (cmd){
			case'F':
				person.F(name1, name2);
				break;
			case'U':
				person.U(name1, name2);
				break;
			case'Q':
				if (person.Q(name1, name2)) {
					cout << "Yes" << endl;
				}
				else {
					cout << "No" << endl;
				}
			default:
				break;
			}
		}
	}
}