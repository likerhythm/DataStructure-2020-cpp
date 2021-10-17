#define _CRT_SECURE_NO_WARNINGS
#include "Project(1).h"
#include<fstream>
#include<string.h>
using namespace std;




List::List(int maxNumber)
	: maxSize(maxNumber),
	size(-1)
{
	dataItems = new Telephone[maxSize];         
}


List:: ~List(){                           
	delete dataItems;
}

void List::cirmonth(char* m1, char* m2, char list[]) {       //char 타입으로 저장된 생일을      
	int num = atoi(m1) * 10 + atoi(m2);                      //int타입으로 변환하여 태어난 월을 계산한 뒤
	                                                         //해당되는 월을 노드의 monthOfbirth 변수에 저장
	switch (num)            
	{                                                     
	case 1:
		strcpy(list, "January");
		break;
	case 2:
		strcpy(list, "February");
		break;
	case 3:
		strcpy(list, "March");
		break;
	case 4:
		strcpy(list, "April");
		break;
	case 5:
		strcpy(list, "May");
		break;
	case 6:
		strcpy(list, "June");
		break;
	case 7:
		strcpy(list, "July");
		break;
	case 8:
		strcpy(list, "August");
		break;
	case 9:
		strcpy(list, "September");
		break;
	case 10:
		strcpy(list, "October");
		break;
	case 11:
		strcpy(list, "November");
		break;
	case 12:
		strcpy(list, "December");
		break;
	default:
		strcpy(list, "NONE");
		break;
	}
}

void List::write_file() {                                  //전화번호부에 저장된 정보를 파일에 쓰는 함수_명령어 'W'
	char file_name[100];
	cout << "Enter the name of the file: ";
	cin >> file_name;

	ofstream writeFile;
	writeFile.open(strcat(file_name, ".txt"));

	if (writeFile.is_open()) {
		for (int i = 0; i <= size; i++)                   //이름, 전화번호, 생일순으로 작성
		{
			writeFile << dataItems[i].name << endl;
			writeFile << dataItems[i].phone_number << endl;
			writeFile << dataItems[i].birth << endl;
			writeFile << endl;
		}
		writeFile.close();
	}
}

void List::read_file() {                                   //저장된 파일을 읽어오는 함수_ 명령어 'R'
	
	char file_name[100];	
	cout << "Enter the name of the file: ";
	cin >> file_name;                                      //파일 이름 입력
	
	ifstream readFile;
	readFile.open(strcat(file_name, ".txt"));
	if (readFile.is_open()) {
		char blank[20];
		 do{
			size++;
			
			readFile.getline(dataItems[size].name, 20);		      //파일 한 줄씩 읽어와서
			readFile.getline(dataItems[size].phone_number, 20);	  //리스트의 노드에 추가
     		readFile.getline(dataItems[size].birth, 20);			    			                                                                          
			readFile.getline(blank, 20);
		 } while (!readFile.eof());

		 
		readFile.close();

		for (int i = 0; i <= size; i++)	{                 //파일을 읽어온 후 
			char m1[1], m2[1];                            //태어난 월을 계산(cirmonth 함수)
			m1[0] = dataItems[i].birth[0];
			m2[0] = dataItems[i].birth[1];
			cirmonth(m1, m2 , dataItems[i].monthOfbirth);
		}
	}
	show_Month();
}

void List::insert() throw (logic_error){                  //전화번호부에 노드를 추가하는 함수_명령어 '+'                     
	if (isFull()) {
		cout << "List is full" << endl;
	}
	else {
		size++;
		cout << "Name: ";
		cin.getline(dataItems[size].name,20);	

		cout << "Phone: ";
		cin.getline(dataItems[size].phone_number,20);

		cout << "Birthday: ";
		cin.getline(dataItems[size].birth,20);
	}
	char m1[1], m2[1];                                    //노드를 추가한 후
	m1[0] = dataItems[size].birth[0];                     //태어난 월을 계산(cirmonth 함수)
	m2[0] = dataItems[size].birth[1];
	cirmonth(m1, m2, dataItems[size].monthOfbirth);
	show_Month();
}


void List::remove() throw (logic_error){                  //노드를 지우는 함수_명령어 '-'
	bool found = false;
	if (isEmpty())
		cout << "List is empty" << endl;
	else{
		char delname[20];
		cout << "Name: ";
		cin.getline(delname, 20);                          //지울 노드의 이름을 입력
		for (int i = 0; i <= size; i++)
		{
			if (!strcmp(delname, dataItems[i].name))       //인덱스가 i에 해당하는 노드의 이름과
			{                                              //지우려는 노드의 이름이 같은 경우
				found = true;
				if (i == size)                                       //지우는 노드가 마지막 노드라면
					size--;                                          //size만 감소
				else {                                               //마지막 노드가 아니라면
					for (int j = i; j < size; j++) {                 //노드를 뒤에서 앞으로 하나씩 덮어쓰기
						dataItems[j] = dataItems[j + 1];
					}
					size--;
					break;
				}
			}
		}
		if(!found)
			cout << "This name is not in the list" << endl;    //리스트에 지울 노드의 이름과 같은 노드가 없다면
	}                                                      //오류 메시지 출력
	show_Month();
}

void List::select_Month() {                                //입력한 월이 생일인 사람의 수를 구하는 함수_명령어 'M'
	char selMonth[20];
	cout << "Enter the selected month: ";
	cin >> selMonth;                                              //확인하고싶은 월 입력
	int count = 0, countedNum[20], s = 0;                         //count: 해당 월이 생일인 사람의 수, countedNum: 해당 월이 생일인 사람의 인덱스를 저장하는 배열, s: countedNum의 사이즈
	for (int i = 0; i <= size; i++) {
		if (!strcmp(selMonth, dataItems[i].monthOfbirth)) {      //입력한 월과 인덱스 i에 해당하는 사람의 생일이 같다면
			count++;                                              //count를 하나 증가시키고
			countedNum[s] = i;                                    //countedNum 배열에 해당 사람의 인덱스 추가
			s++;                                                  //countedNum 사이즈 하나 증가
		}
	}
	cout << "Total number of birthdays in " << selMonth << ": " << count << endl << endl;
	for (int i = 0; i < s; i++){                                  //입력한 월과 생일이 같은 사람의 정보 출력
		cout << endl << dataItems[countedNum[i]].name << endl;    //countedNum 배열에 저장된 인덱스에 해당하는 사람의 정보 출력
		cout << dataItems[countedNum[i]].phone_number << endl;
		cout << dataItems[countedNum[i]].birth << endl << endl;;
	}
}

bool List::isEmpty() const{
	return(size == 0);                        
}


bool List::isFull() const{
	return(size == maxSize);                     
}

void List::show_Month() {                                                  //일부 명령어 실행 후 남은 사람들의 생일을 표시해주는 함수
	cout << "Total number of entries in the list: " << size + 1 << endl;
	cout << "Number of birthdays in" << endl;
	int arr[12] = { 0 };                                                   //arr: 인덱스를 1월~12월로 생각하고 각 달이 생일인 사람의 수를 저장하는 배열(0으로 초기화)
	for (int i = 0; i <= size; i++) {
		char m1[1], m2[1];
		m1[0] = dataItems[i].birth[0];
		m2[0] = dataItems[i].birth[1];
		int num = atoi(m1) * 10 + atoi(m2);                                //char 타입으로 저장된 생일을 int형태로 다시 계산하여
		arr[num]++;                                                        //arr 배열에 추가
	}
	for (int i = 0; i < 12; i++) {                                         //1월부터 12월까지 차례로 짚어가며
		if (arr[i] != 0) {                                                 //arr이 0이 아니라면
			switch (i)                                                     //해당 월이 생일인 사람의 수 출력
			{
			case 1:
				cout << "January: " << arr[i] << endl;
				break;
			case 2:
				cout << "February: " << arr[i] << endl;
				break;
			case 3:
				cout << "March: " << arr[i] << endl;
				break;
			case 4:
				cout << "April: " << arr[i] << endl;
				break;
			case 5:
				cout << "May: " << arr[i] << endl;
				break;
			case 6:
				cout << "June: " << arr[i] << endl;
				break;
			case 7:
				cout << "July: " << arr[i] << endl;
				break;
			case 8:
				cout << "August: " << arr[i] << endl;
				break;
			case 9:
				cout << "September: " << arr[i] << endl;
				break;
			case 10:
				cout << "October: " << arr[i] << endl;
				break;
			case 11:
				cout << "November: " << arr[i] << endl;
				break;
			case 12:
				cout << "December: " << arr[i] << endl;
				break;
			default:
				break;
			}
		}
	}
	cout << endl;
}