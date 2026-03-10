#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 : list 직접 구현

template<typename T>
class Node
{
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{

	}

public:
	Node<T>*	_next;
	Node<T>*	_prev;
	T		_data;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	// 클래스 내부에서는 Class<T>에서 <T> 생략해도 템플릿으로 자동으로 인식함
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_node = _node->_next;
		return temp;
	}

	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& right)
	{
		return _node == right._node;
	}
	
	bool operator!=(const Iterator& right)
	{
		return !(*this == right);
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _header;
	}

	// [1] <-> [2] <-> [3] <-> [header] <->
	// [1] <-> [2] <-> [3] <-> [value] <-> [header] <->
	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	// [1] <-> [2] <-> [3] <-> [header] <->
	// [1] <-> [2] <-> [header] <->
	void pop_back()
	{
		RemoveNode(_header->_prev);
	}
	
	// [1] <-> [2] <-> [before(3)] <-> [header] <->
	// [1] <-> [2] <-> [node] <-> [before] <-> [header] <->
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* node = new Node<T>(value);

		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		before->_prev = node;
		node->_next = before;

		_size++;

		return node;
	}

	// [1] <-> [2] <-> [node(3)] <-> [4] <-> [header] <->
	// [1] <-> [2] <-> [4] <-> [header] <->
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		nextNode->_prev = prevNode;
		prevNode->_next = nextNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(_header->_next); }
	iterator end() { return iterator(_header); }

	iterator insert(iterator it, const T& value)
	{
		return iterator(AddNode(it._node, value));
	}

	iterator erase(iterator it)
	{
		return iterator(RemoveNode(it._node));
	}

public:
	Node<T>* _header;
	int _size;
};


int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();

	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}