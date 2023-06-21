#pragma once

//p.1061

template <class Type>

class StackTp
{
private:
	enum {SIZE = 10};	
	int stacksize;
	Type* items;
	int top;
public:
	explicit StackTp(int ss = SIZE);
	StackTp(const StackTp& st);
	~StackTp() { delete[] items; }
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const Type& item);
	bool pop(Type& item);
	StackTp& operator=(const StackTp& st);
};

template<class Type>
inline StackTp<Type>::StackTp(int ss)
{
	items = new Type[stacksize];
}

template<class Type>
inline StackTp<Type>::StackTp(const StackTp& st)
{
	stacksize = st.stacksize;
	top = st.top;
	itemps = new Type[stacksize];
	for (int i = 0; i < top; i++)
	{
		items[i] = st.items[i];
	}
}

template<class Type>
inline bool StackTp<Type>::push(const Type& item)
{
	if (top < stacksize)
	{
		itemps[top++] = item;
		return true;
	}
	return false;
}

template<class Type>
inline bool StackTp<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	return false;
}

template<class Type>
inline StackTp<Type>& StackTp<Type>::operator=(const StackTp& st)
{
	if (this == &st) return *this;
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++) items[i] = st.items[i];
	
	return &this;
	// TODO: 여기에 return 문을 삽입합니다.
}
