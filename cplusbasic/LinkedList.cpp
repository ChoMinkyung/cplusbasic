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

	cout << "\t" << st.no << "�� " << st.name << "�� �߰��Ǿ����ϴ�." << endl;

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
		cout << "\t" << no << "���� �����Ǿ����ϴ�." << endl;
	}
	else cout << "\t������ �׸��� �����ϴ�." << endl;

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
		cout << "\t��ȣ : " << temp->no << " �̸� : " << temp->name << endl;
		count++;
	}

	if (count == 0)
	{
		cout << "\t����Ʈ�� ����ֽ��ϴ�." << endl;
	}
	else cout << "\t�� �л� �� : " << count << endl;
}
