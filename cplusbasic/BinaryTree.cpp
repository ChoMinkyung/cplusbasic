#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	// 초기화
	root->data = nullptr;
	root->left = root->right = nullptr;
}

BinaryTree::~BinaryTree()
{
	// 모두 삭제
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
		// 현재 노드가 비어있으면 삽입
		if (current_node->data == nullptr)
		{
			current_node->data = new_data->data;
			current_node->left = nullptr;
			current_node->right = nullptr;
			break;
		}
		else
		{
			// 비어있지 않으면 이동
			if (current_node->data->no < new_data->data->no)
			{
				// 새로 입력할 데이터가 현재 노드 번호보다 크면 오른쪽 자식으로 이동
				current_node = current_node->right;
			}
			else if (current_node->data->no > new_data->data->no)
			{
				// 새로 입력할 데이터가 현재 노드 번호보다 작으면 왼쪽 자식으로 이동
				current_node = current_node->left;
			}
			else
			{
				// 같으면 입력 불가
				cout << "\t>> 해당 번호를 가진 학생이 이미 있습니다." << endl;
				break;
			}
		}
	}
}

void BinaryTree::Remove(int no)
{
	Node* parent_node = root;
	Node* current_node = root;

	// 삭제할 노드 찾기
	while (1)
	{
		if (current_node->data == nullptr)
		{
			cout << "\t>> 해당 번호를 가진 학생이 없습니다." << endl;
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

	// 삭제하기
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
		// 자식이 둘 다 있으므로 왼쪽에서 가장 큰 것이랑 바꾼다
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
	cout <<"\t" << node->data->no << "번 " << node->data->name
		<< endl;
	Print(node->right);
}

Node* BinaryTree::GetRoot()
{
	return root;
}
