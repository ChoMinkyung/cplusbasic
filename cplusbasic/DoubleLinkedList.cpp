#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
	head.next = &tail;
	head.prev = nullptr;
	tail.next = nullptr;
	tail.prev = &head;
}

DoubleLinkedList::~DoubleLinkedList()
{
	Clear();
}

void DoubleLinkedList::Insert(const Student& st)
{
	Student* newStudent = new Student();

	newStudent->no = st.no;
	newStudent->name = st.name;

	newStudent->prev = tail.prev;
	newStudent->next = &tail;
	tail.prev->next = newStudent;
	tail.prev = newStudent;

	cout << "\t" << st.no << "번 " << st.name << "가 추가되었습니다." << endl;

}

void DoubleLinkedList::Remove(int no)
{
	Student* temp = head.next;
	bool exist = false;
	while (temp->next != nullptr)
	{
		if (temp->no == no)
		{
			exist = true;
			break;
		}
		temp = temp->next;
	}

	if (exist)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		cout << "\t" << no << "번이 삭제되었습니다." << endl;
	}
	else cout << "\t삭제할 항목이 없습니다." << endl;
}

void DoubleLinkedList::Clear()
{
	head.next = &tail;
	tail.prev = &head;
}

void DoubleLinkedList::Print()
{
	Student* temp = head.next;
	int count = 0;

	while (temp->next != nullptr)
	{
		cout << "\t번호 : ";
		cout.width(5);
		cout.fill(' ');
		cout << temp->no;
		cout << " 이름 : " << temp->name << endl;

		count++;
		temp = temp->next;
	}

	if (count == 0)
	{
		cout << "\t리스트가 비어있습니다." << endl;
	}
	else cout << "\t총 학생 수 : " << count << endl;
}

void DoubleLinkedList::ReversePrint()
{
	Student* temp = tail.prev;
	int count = 0;

	while (temp->prev != nullptr)
	{
		cout << "\t번호 : ";
		cout.width(5);
		cout.fill(' ');
		cout << temp->no;
		cout << " 이름 : " << temp->name << endl;

		count++;
		temp = temp->prev;
	}

	if (count == 0)
	{
		cout << "\t리스트가 비어있습니다." << endl;
	}
	else cout << "\t총 학생 수 : " << count << endl;
}
