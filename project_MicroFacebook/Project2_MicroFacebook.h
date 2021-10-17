#pragma once
#include<iostream>

/*친구의 정보를 저장하는 노드*/
class FriendNode {
public:
	FriendNode(char* n, FriendNode* nextPtr);
private:
	/*친구 이름*/
	char name[20];
	/*next 포인터*/
	FriendNode* next;

	friend class PersonNode;
};

/*microfacebook에 가입한 사람들의 노드
FriendNode 클래스를 다루는 함수 포함*/
class PersonNode {
public:
	PersonNode(char* n, PersonNode* nextPtr, 
		FriendNode* head, FriendNode* cursor);

	/*친구를 추가하는 함수*/
	void addFriend(char* Fname);

	/*친구를 지우는 함수*/
	void removeFriend(char* Uname);

	/*친구를 출력하는 함수*/
	void printFriend();

	/*친구를 찾는 함수*/
	bool findingFriend(char* Qname);

	/*커서를 다루는 함수*/
	void gotoEnd();
	bool isEmpty();
private:
	/*가입한 사람의 이름*/
	char name[20];
	/*가입한 사람들에 대한 next 포인터*/
	PersonNode* next;
	/*친구 리스트의 head포인터와 cursor 포인터*/
	FriendNode* head_friend, * cursor_friend;

	friend class Person;
};

/*PersonNode 클래스를 다루는 Person 클래스*/
class Person {
public:
	Person();
	~Person();

	/*microfacebook에 가입하는 함수*/
	void P(char* Pname);

	/*addFriend 함수로 이름을 전달해주는 함수*/
	void F(char* Fname1, char* Fname2);

	/*removeFriend 함수로 이름을 전달해주는 함수*/
	void U(char* Uname1, char* Uname2);

	/*친구를 출력할 사람을 찾는 함수*/
	void L(char* Lname);

	/*findingFriend 함수에 이름을 전달해주는 함수*/
	bool Q(char* Qname1, char* Qname2);

	void gotoEnd();
	/*microfacebook에 가입한 사람들과 그 사람들의 친구를 출력하는 함수*/
	void showstructure();
	bool isEmpty();
	
	/*테스트용 함수*/
	void checking_cursor();
private:
	/*가입한 사람들의 리스트에 대한 head포인터와 cursor 포인터*/
	PersonNode* head_Person, *cursor_Person;
};
