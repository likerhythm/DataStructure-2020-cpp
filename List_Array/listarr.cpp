#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)


	: maxSize(maxNumber),
	size(0),
	cursor(-1)
{
	dataItems = new DataType[maxSize];                     //배열 동적할당
}

//--------------------------------------------------------------------

List:: ~List()

{
	delete dataItems;

}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)
throw (logic_error)

{
	if (!isFull()) {                         //리스트가 가득차지 않았을 경우
		dataItems[size] = newDataItem;       //newDataItem 추가
		size++;                              //size 증가
		cursor = size - 1;                   //cursor 이동 
	}
	else {                                   //리스트가 가득 차있는 경우
		cout << "List is Full" << endl;
	}
}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	if (!isEmpty()) {          //리스트가 비어있지 않은 경우
		if (size==1) {         //리스트에 data가 하나만 있는 경우
			size--;            //size 감소
			cursor = -1;       //cursor 초기화
		}
		else if (cursor == size - 1) {   //cursor가 마지막 리스트 원소를 가리키는 경우
			size--;                      //사이즈만 감소
		}
		else {                                             //cursor가 리스트 중간에 있는 경우
			dataItems[cursor] = dataItems[size - 1];       //리스트의 마지막 원소로 대체
			size--;                                        //사이즈 감소
		}
	}
	else {                                 //리스트가 비어있는 경우
		cout << "List is Empty" << endl;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	if (!isEmpty()) {                         //리스트가 비어있지 않은 경우
		dataItems[cursor] = newDataItem;      //newDataItem으로 대체
	}
	else {                                    //리스트가 비어있는 경우
		cout << "List is empty" << endl;
	}

}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	size = 0;                      //size를 0으로, cursor를 -1로 초기화
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	return(size == 0);                          //리스트의 size가 0이면 true, 아니면 false 반환
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	return(size == maxSize);                      //리스트의 size가 max이면 true, 아니면 false 반환

}

//--------------------------------------------------------------------

bool List::gotoBeginning() throw (logic_error)
// Moves the cursor to the beginning of the list.
{
	if (!isEmpty()) {             //리스트가 비어있지 않은 경우
		cursor = 0;               //cursor를 0으로 변경
		return true;
	}
	else {                        //리스트가 비어있는 경우
		return false;
	}

}

//--------------------------------------------------------------------

bool List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	if (!isEmpty()) {                    //리스트가 비어있지 않은 경우
		cursor = size - 1;               //cursor를 마지막 원소로 이동
		return true;
	}
	else {                               //리스트가 비어있는 경우
		return false;
	}
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	if (!isEmpty()) {                 
		if (cursor != size - 1) {       //리스트가 비어있으면서 cursor가 마지막 원소를 가리키지 않는 경우
			cursor++;                   //cursor 증가시키고 true 반환
			return true;
		}
		else {                          //리스트가 비어있으면서 cursor가 마지막 원소를 가리키는 경우
			return false;               //false 반환
		}
	}
	else {                       //리스트가 비어있는 경우 false 반환
		return false;
	}

}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	if (!isEmpty()) {
		if (cursor != 0) {           //리스트가 비어있지 않으면서 cursor가 첫번째 원소를 가리키지 않는 경우
			cursor--;                //cursor를 감소시키고 true 반환
			return true;
		}
		else {                       //리스트가 비어있지 않으면서 cursor가 첫번째 원소를 가리키는 경우
			return false;            //false 반환
		}
	}
	else {                   //리스트가 비어있는 경우 false 반환
		return false;
	}

}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)
// Returns the item marked by the cursor.

{
	if (!isEmpty()) {                     //리스트가 비어있지 않은 경우 
		return dataItems[cursor];         //cursor가 가리키는 원소 반환
	}
	else {                                //리스트가 비어있는 경우
		cout << "List is empty" << endl;
	}

}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	if (isEmpty()) {                             //리스트가 비어있는 경우
		cout << "Empty list" << endl;            
	}
	else {                                       //리스트가 비어있지 않은 경우
		cout << "cursor: " << cursor << endl;
		cout << "size: " << size << endl;
		cout << "[1] [2] [3] [4] [5] [6] [7] [8]" << endl;
		cout << " ";
		for (int i = 0; i < size; i++) {          //원소를 차례로 출력
			cout << dataItems[i] << "   ";
		}
	}

}

//--------------------------------------------------------------------

//in-lab
void List::countBases(List& dnaSequence, int& aCount, int& cCount, int& tCount, int& gCount) {
	aCount = 0;                             //a,c,t,g count를 0으로 초기화
	cCount = 0;
	tCount = 0;
	gCount = 0;
	
	if (!isEmpty()) {                       //리스트가 비어있지 않은 경우
		for (int i = 0; i < size; i++)                     //dnaSequence 리스트의 dataItem의 원소들 차례로 분석하여 각각의 count 증가
			if (dnaSequence.dataItems[i] == 'A')
				aCount++;
			else if (dnaSequence.dataItems[i] == 'C')
				cCount++;
			else if (dnaSequence.dataItems[i] == 'T')
				tCount++;
			else
				gCount++;
	}
}