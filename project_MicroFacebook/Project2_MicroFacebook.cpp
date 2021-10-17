#include<iostream>
#include"Project2_MicroFacebook.h"
#include<string>

using namespace std;

/*FriendNode 생성자*/
FriendNode::FriendNode(char* n, FriendNode* nextPtr) {
	strcpy_s(name, n);
	next = nextPtr;
}

/*PersonNode 생성자*/
PersonNode::PersonNode(char* n, PersonNode* nextPtr, 
	FriendNode* head, FriendNode* cursor) {
	strcpy_s(name,n);
	next = nextPtr;
	head_friend = head;
	cursor_friend = cursor;
}

/*Person 생성자*/
Person::Person() {
	head_Person = NULL;
	cursor_Person = NULL;
}

/*Person 소멸자*/
Person::~Person() {
	head_Person = NULL;
	cursor_Person = NULL;
}

void Person::P(char* Pname) {
	/*microfacebook에 가입한 사람이 아무도 없는 경우*/
	if (head_Person==NULL) {                                            
		head_Person = new PersonNode(Pname, NULL, NULL, NULL);          
		cursor_Person = head_Person;
		cout << Pname << " sign in microfacebook!" << endl;
	}
	/*그 외의 경우 리스트의 마지막에 노드 추가*/
	else {       
		gotoEnd();
		PersonNode* location = new PersonNode(Pname, NULL,NULL,NULL);
		cursor_Person->next = location;
		cursor_Person = location;
		cout << Pname << " sign in microfacebook!" << endl;
	}
}

void Person::F(char* Fname1, char* Fname2) {
	/*가입한 사람이 있는 경우*/
	if (!isEmpty()) {                                                    
		cursor_Person = head_Person;
		/*Fname1을 찾았는지 확인하는 변수*/
		bool found1 = false;         
		/*Fname2를 찾았는지 확인하는 변수*/
		bool found2 = false;                                             
		while (cursor_Person != NULL) {
			/*PersonNode리스트를 돌며 Fname1을 찾았다면 found1=true*/
			if (!strcmp(cursor_Person->name, Fname1)) {                 
				found1 = true;
			}
			/*Fname2를 찾았다면 found2=true*/
			else if (!strcmp(cursor_Person->name, Fname2)) {           
				found2 = true;
			}
			cursor_Person = cursor_Person->next;
		}
		/*Fname1과 Fname2를 모두 찾았다면*/
		if (found1 && found2) {
			cursor_Person = head_Person;
			/*PersonNode리스트를 돌면서*/
			while (cursor_Person != NULL) {
				/*Fname1에 대해 addFriend 함수의 매개변수로 Fname2 전달*/
				/*즉 Fname2를 Fname1의 친구로 등록*/
				if (!strcmp(cursor_Person->name, Fname1)) {
					cursor_Person->addFriend(Fname2);
					break;
				}
				else {
					cursor_Person = cursor_Person->next;
				}
			}
			cursor_Person = head_Person;
			/*위와 마찬가지로 Fname1을 Fname2의 친구로 등록*/
			while (cursor_Person != NULL) {
				if (!strcmp(cursor_Person->name, Fname2)) {
					cursor_Person->addFriend(Fname1);
					break;
				}
				else {
					cursor_Person = cursor_Person->next;
				}
			}
			cout << endl;
			cout << Fname1 << " and " << Fname2 << " are now friend" << endl;
		}
		/*Fname1이나 Fname2가 PersonNode리스트에 없는 경우*/
		else {
			cout << "can't find " << Fname1 << " or " << Fname2 << endl;
		}
	}
}

/*FriendNode 리스트에 Fname을 추가하는 함수*/
void PersonNode::addFriend(char* Fname) {
	if (isEmpty()) {
		head_friend = new FriendNode(Fname, NULL);
		cursor_friend = head_friend;
	}
	else {
		gotoEnd();
		FriendNode* location = new FriendNode(Fname, NULL);
		cursor_friend->next = location;
	}
}

void Person::U(char* Uname1, char* Uname2) {
	if (!isEmpty()) {
		cursor_Person = head_Person;
		while (cursor_Person != NULL) {
			/*PersonNode 리스트에서 Uname1을 찾은 경우
			Uname1의 친구목록에서 Uname2 삭제*/
			if (!strcmp(cursor_Person->name, Uname1)) {
				cursor_Person->removeFriend(Uname2);
				break;
			}
			else {
				cursor_Person = cursor_Person->next;
			}
		}
		cursor_Person = head_Person;
		while (cursor_Person != NULL) {
			/*PersonNode 리스트에서 Uname2를 찾은 경우
			Uname2의 친구목록에서 Uname1 삭제*/
			if (!strcmp(cursor_Person->name, Uname2)) {
				cursor_Person->removeFriend(Uname1);
				break;
			}
			else {
				cursor_Person = cursor_Person->next;
			}
		}
		cout << Uname1 << " and " << Uname2 << "are no longer friend" << endl;
	}
}

/*친구를 삭제하는 함수*/
void PersonNode::removeFriend(char* Uname) {
	if (!isEmpty()) {
		cursor_friend = head_friend;
		FriendNode* delLoc, * before = cursor_friend;
		/*링크드 리스트에서 노드를 삭제하는 방법과 동일*/
		while (cursor_friend != NULL){
			if (!strcmp(cursor_friend->name, Uname)) {
				if (cursor_friend == head_friend) {
					head_friend = head_friend->next;
					cursor_friend = head_friend;
				}
				else {
					delLoc = cursor_friend;
					before->next = cursor_friend->next;
					cursor_friend = before;
					delete delLoc;
				}
			}
			else {
				before = cursor_friend;
				cursor_friend = cursor_friend->next;
			}
		}
	}
}

void Person::L(char* Lname) {
	if (!isEmpty()) {
		while (cursor_Person != NULL) {
			/*Lname을 찾아 친구목록 출력*/
			if (!strcmp(cursor_Person->name, Lname)) {
				cursor_Person->printFriend();
				break;
			}
			else {
				cursor_Person = cursor_Person->next;
			}
		}
	}
	else {
		cout << "Empty List" << endl;
	}
}

/*친구목록 출력 함수*/
void PersonNode::printFriend() {
	if (!isEmpty()) {
		cursor_friend = head_friend;
		while (cursor_friend != NULL) {
			cout << cursor_friend->name << " ";
			cursor_friend = cursor_friend->next;
		}
	}
}

bool Person::Q(char* Qname1, char* Qname2) {
	if (!isEmpty()) {
		/*Qname1의 친구로 Qname2가 등록되어 있음을 확인하는 변수 found*/
		bool found = false;
		cursor_Person = head_Person;
		while (cursor_Person != NULL) {
			/*Qname1이 PersonNode에 존재한다면 Qname1의 친구목록에서 Qname2 찾기*/
			if (!strcmp(cursor_Person->name, Qname1)) {
				/*친구목록에서 Qname2를 찾았다면 found는 true, 찾지 못했다면 found는 false*/
				found = cursor_Person->findingFriend(Qname2);
				break;
			}
			else {
				cursor_Person = cursor_Person->next;
			}
		}
		return found;
	}
	else {
		return false;
	}
}

/*친구를 찾는 함수*/
bool PersonNode::findingFriend(char* Qname) {
	bool found = false;
	if (!isEmpty()) {
		cursor_friend = head_friend;
		while (cursor_friend != NULL) {
			/*FriendNode 리스트에서 Qname을 찾았다면 found는 true*/
			if (!strcmp(cursor_friend->name, Qname)) {
				found = true;
				break;
			}
			else {
				cursor_friend = cursor_friend->next;
			}
		}
	}
	/*found 리턴*/
	return found;
}

void Person::gotoEnd() {
	if (!isEmpty()) {
		cursor_Person = head_Person;
		while (cursor_Person->next != NULL) {
			cursor_Person = cursor_Person->next;
		}
	}
}

void PersonNode::gotoEnd() {
	if (!isEmpty()) {
		cursor_friend = head_friend;
		while (cursor_friend->next != NULL) {
			cursor_friend = cursor_friend->next;
		}
	}
}

bool Person::isEmpty() {
	return(head_Person == NULL);
}

bool PersonNode::isEmpty() {
	return(head_friend == NULL);
}

void Person::showstructure() {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		PersonNode* location = head_Person;
		while(location!=NULL){
			cout << location->name << "   friends: ";
			location->printFriend();
			cout << endl;
			location = location->next;
		}
	}
}

void Person::checking_cursor() {
	if (!isEmpty()) {
		cout << "커서 이름: " << cursor_Person->name << endl;
		cout << "헤드 이름: " << head_Person->name << endl;
	}
}