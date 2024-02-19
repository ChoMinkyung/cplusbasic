#include "Hash.h"

Hash::Hash()
{
	// ChainHash에 대한 동적 할당 수행
	hash_table = new ChainHash;

	// first_hash에 대한 동적 할당 및 초기화 수행
	hash_table->size = 13;
	hash_table->first_hash = new Node * [hash_table->size];

	for (int i = 0; i < hash_table->size; i++)
	{
		hash_table->first_hash[i] = nullptr;
	}
}

Hash::Hash(int size)
{
	hash_table->size = size;
	hash_table->first_hash = new Node * [hash_table->size];

	for (int i = 0; i < hash_table->size; i++)
	{
		hash_table->first_hash[i] = nullptr;
	}
}

Hash::~Hash()
{
}

void Hash::Insert(const Student& st)
{
	if (Find(st.no) > -1)
	{
		cout << "\t해당 번호가 이미 존재합니다." << endl;
		return;
	}

	Node* new_data = new Node();
	new_data->data = new Student();

	new_data->data->no = st.no;
	new_data->data->name = st.name;


	int hash_value = new_data->data->no % hash_table->size;
	if (hash_table->first_hash[hash_value] == NULL)
	{
		hash_table->first_hash[hash_value] = new_data;
	}
	else if (hash_table->first_hash[hash_value]->next == NULL)
	{
		hash_table->first_hash[hash_value]->next = new_data;
	}
	else
	{
		new_data->next = hash_table->first_hash[hash_value]->next;
		hash_table->first_hash[hash_value]->next = new_data;
	}
}

void Hash::Remove(int no)
{
	int depth = Find(no);
	if (depth > -1)
	{
		cout << "\t데이터를 삭제합니다." << endl;
	}
	else
	{
		cout << "\t삭제할 데이터가 없습니다." << endl;
		return;
	}

	int hash_value = no % hash_table->size;

	Node* current = hash_table->first_hash[hash_value];

	if (depth == 0)
	{
		if (current->next != NULL)
		{
			current->data = current->next->data;
			if (current->next->next == NULL)
				current->next = NULL;
			else current->next = current->next->next;
		}
		else
		{
			//delete current;
			current->data = NULL;
		}
	}
	else
	{
		for (int i = 0; i < depth - 1; i++)
		{
			current = current->next;
		}

		if (current->next == NULL)
		{
			delete current;
			current = NULL;
		}
		else
		{
			if (current->next->next == NULL)
			{
				//delete current->next;
				current->next = NULL;
			}
			else
			{
				current->next->data = current->next->next->data;
				//delete current->next->next;
				current->next->next = NULL;
			}
		}

	}

}

void Hash::Clear()
{
	Node* current;
	for (int i = 0; i < hash_table->size; i++)
	{
		current = hash_table->first_hash[i];
		while (current!=nullptr)
		{
			if (current->data == NULL) break;
			Remove(current->data->no);
			
		}
		current=NULL;

	}
}

void Hash::Print()
{
	Node* current;
	for (int i = 0; i < hash_table->size; i++)
	{
		cout.width(2);
		cout.fill('0');
		cout << i;

		current = hash_table->first_hash[i];

		while (current != NULL)
		{
			if (current->data == NULL)break;
			cout << "-> " << current->data->no << "(" <<
				current->data->name << ")";
			current = current->next;
		}
		cout << endl;
	}
}

int Hash::Find(int no)
{
	int depth = 0;
	int hash_value = no % hash_table->size;
	Node* current = hash_table->first_hash[hash_value];
	bool find = false;

	while (current != NULL)
	{
		if (current->data->no == no)
		{
			find = true;
			cout << "\t" << no << "(" << current->data->name << ")" << endl;
			break;
		}
		current = current->next;
		depth++;
	}

	if (find) return depth;
	else return -100;
}
