#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

const int defMaxListSize = 10;   


class Telephone
{
private:
	char name[20];
	char phone_number[20];
	char birth[20];
	char monthOfbirth[20];

	friend class List;
};

class List
{
public:
	List(int maxNumber = defMaxListSize);

	
	~List();

	void cirmonth(char* m1, char* m2, char list[]);
	void read_file();
	void insert()    
		throw (logic_error);
	void remove()                                 
		throw (logic_error);
	void write_file();
	void select_Month(); 
	void show_Month();

	
	bool isEmpty() const;                   
	bool isFull() const;      

private:
	int maxSize,
		size;
	Telephone* dataItems; 
};