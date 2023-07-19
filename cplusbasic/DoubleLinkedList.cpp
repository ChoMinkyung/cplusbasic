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

	cout << "\t" << st.no << "�� " << st.name << "�� �߰��Ǿ����ϴ�." << endl;

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

		cout << "\t" << no << "���� �����Ǿ����ϴ�." << endl;
	}
	else cout << "\t������ �׸��� �����ϴ�." << endl;
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
		cout << "\t��ȣ : ";
		cout.width(5);
		cout.fill(' ');
		cout << temp->no;
		cout << " �̸� : " << temp->name << endl;

		count++;
		temp = temp->next;
	}

	if (count == 0)
	{
		cout << "\t����Ʈ�� ����ֽ��ϴ�." << endl;
	}
	else cout << "\t�� �л� �� : " << count << endl;
}

void DoubleLinkedList::ReversePrint()
{
	Student* temp = tail.prev;
	int count = 0;

	while (temp->prev != nullptr)
	{
		cout << "\t��ȣ : ";
		cout.width(5);
		cout.fill(' ');
		cout << temp->no;
		cout << " �̸� : " << temp->name << endl;

		count++;
		temp = temp->prev;
	}

	if (count == 0)
	{
		cout << "\t����Ʈ�� ����ֽ��ϴ�." << endl;
	}
	else cout << "\t�� �л� �� : " << count << endl;
}
