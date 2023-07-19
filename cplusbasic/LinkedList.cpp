#include "LinkedList.h"

LinkedList::LinkedList()
{
	head.next = tail;
	tail = nullptr;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Insert(const Student& st)
{
	Student* temp = &head;
	Student* newStudent = new Student();

	newStudent->no = st.no;
	newStudent->name = st.name;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	temp->next = newStudent;
	newStudent->next = tail;

	cout << "\t" << st.no << "번 " << st.name << "가 추가되었습니다." << endl;

}

void LinkedList::Remove(int no)
{
	Student* temp = &head;
	bool exist = false;
	while (temp->next != nullptr)
	{
		if (temp->next->no == no)
		{
			exist = true;
			break;
		}
		temp = temp->next;
	}

	if (exist)
	{
		Student* temp_2 = temp->next->next;
		temp->next = temp_2;
		cout << "\t" << no << "번이 삭제되었습니다." << endl;
	}
	else cout << "\t삭제할 항목이 없습니다." << endl;

}

void LinkedList::Clear()
{
	head.next = tail;
	tail = nullptr;
}

void LinkedList::Print()
{
	Student* temp = &head;
	int count = 0;

	while (temp->next != nullptr)
	{
		temp = temp->next;
		cout << "\t번호 : " << temp->no << " 이름 : " << temp->name << endl;
		count++;
	}

	if (count == 0)
	{
		cout << "\t리스트가 비어있습니다." << endl;
	}
	else cout << "\t총 학생 수 : " << count << endl;
}
