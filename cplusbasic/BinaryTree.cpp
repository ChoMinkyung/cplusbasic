#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	// �ʱ�ȭ
	root->data = nullptr;
	root->left = root->right = nullptr;
}

BinaryTree::~BinaryTree()
{
	// ��� ����
}

void BinaryTree::Insert(const Student& st)
{
	Node* current_node = root;

	Node* new_data = new Node();
	new_data->data = (Student*)&st;

	/*new_data->data->no = st.no;
	new_data->data->name = st.name;*/

	while (1)
	{
		// ���� ��尡 ��������� ����
		if (current_node->data == nullptr)
		{
			current_node->data = new_data->data;
			current_node->left = nullptr;
			current_node->right = nullptr;
			break;
		}
		else
		{
			// ������� ������ �̵�
			if (current_node->data->no < new_data->data->no)
			{
				// ���� �Է��� �����Ͱ� ���� ��� ��ȣ���� ũ�� ������ �ڽ����� �̵�
				current_node = current_node->right;
			}
			else if (current_node->data->no > new_data->data->no)
			{
				// ���� �Է��� �����Ͱ� ���� ��� ��ȣ���� ������ ���� �ڽ����� �̵�
				current_node = current_node->left;
			}
			else
			{
				// ������ �Է� �Ұ�
				cout << "\t>> �ش� ��ȣ�� ���� �л��� �̹� �ֽ��ϴ�." << endl;
				break;
			}
		}
	}
}

void BinaryTree::Remove(int no)
{
	Node* parent_node = root;
	Node* current_node = root;

	// ������ ��� ã��
	while (1)
	{
		if (current_node->data == nullptr)
		{
			cout << "\t>> �ش� ��ȣ�� ���� �л��� �����ϴ�." << endl;
			return;
		}

		if (current_node->data->no == no)
		{
			break;
		}
		else if (current_node->data->no < no)
		{
			parent_node = current_node;
			current_node = current_node->right;
		}
		else if (current_node->data->no > no)
		{
			parent_node = current_node;
			current_node = current_node->left;
		}

	}

	// �����ϱ�
	if (current_node->left == nullptr && current_node->right == nullptr)
	{
		if (parent_node->data->no < current_node->data->no)
		{
			parent_node->right = nullptr;
		}
		else
		{
			parent_node->left = nullptr;
			
		}
	}
	else if (current_node->left == nullptr)
	{
		if(parent_node->data->no < current_node->data->no)
			parent_node->right = current_node->right;
		else 
			parent_node->left = current_node->right;
	}
	else if (current_node->right == nullptr)
	{
		if (parent_node->data->no < current_node->data->no)
			parent_node->right = current_node->left;
		else
			parent_node->left = current_node->left;
	}
	else
	{
		Node* temp = current_node;
		// �ڽ��� �� �� �����Ƿ� ���ʿ��� ���� ū ���̶� �ٲ۴�
		while (temp->left==nullptr)
		{
			temp = temp->left;
		}
		current_node->data = temp->data;
		current_node = temp;
	}
	
	delete current_node;
}

void BinaryTree::Clear()
{
}

void BinaryTree::Print(Node * node)
{
	if (node == nullptr) return;

	Print(node->left);
	cout <<"\t" << node->data->no << "�� " << node->data->name
		<< endl;
	Print(node->right);
}

Node* BinaryTree::GetRoot()
{
	return root;
}
