#include "linked_list.h"
void linked_list::ordning()
{
	node_t *ptr = Head;
	while (ptr->next != nullptr)
	{
		if (ptr->value <= ptr->next->value)
		{
			
		}
		else
		{
			cout << "inte ordning" << endl;
			
		}
		ptr = ptr->next;
	}

}
linked_list::linked_list()
{
	Head = nullptr;
	Tail = nullptr;
}

linked_list::linked_list(const linked_list& src)
{
	Head = nullptr;
	Tail = nullptr;
	node_t *temp;
	temp = src.Head;
	while (temp != nullptr)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

linked_list::~linked_list()
{
	while (Head != nullptr)
	{
		node_t *ptr = Head;
		Head = Head->next;
		delete ptr;
	}
}

linked_list::node_t::node_t(double value, node_t * next, node_t * prev)
{
	this->value = value;
	this->next = next;
	this->prev = prev;
}

linked_list& linked_list::operator =(const linked_list & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (rhs.size() < 0)
	{
		cout << "the list is empty" << endl;
	}
	else
	{
		node_t *temp;
		temp = rhs.Head;
		
		while (temp != nullptr)
		{
			push_back(temp->value);
			temp = temp->next;
		}
	}
	return *this;

}

//linked_list& linked_list::operator +=(const linked_list & rhs)
//{



//}

void linked_list::insert(double value, size_t pos)
{
	if (Tail == nullptr || Head == nullptr)
	{
		Head = new node_t(value, nullptr, nullptr);
		Tail = Head;
		Head->value = value;
		Head->next = nullptr;
		Head->prev = nullptr;
		cout << "First node" << endl;
	}
	else if (pos == 1)
	{
		node_t *ptr = new node_t(value, nullptr, nullptr);
		ptr->next = Head;
		ptr->prev = nullptr;
		ptr->value = value;
		Head->prev = ptr;
		Head = ptr;
	}
	else if (pos == size() + 1)
	{
		cout << "test " << endl;
		node_t *ptr = new node_t(value, nullptr, nullptr);
		ptr->value = value;
		Tail->next = ptr;
		ptr->prev = Tail;
		ptr->next = nullptr;
		Tail = ptr;

	}
	else
	{
		node_t *ptr = new node_t(value, nullptr, nullptr);
		ptr->value = value;
		node_t *counter = Head;
		int count = 1;
		while (count != pos - 1)
		{
			counter = counter->next;
			count++;
		}
		ptr->next = counter->next;
		ptr->prev = counter;
		counter->next->prev = ptr;
		counter->next = ptr;
	}
}

void linked_list::push_front(double value)
{
	if (Head == nullptr || Tail == nullptr)
	{
		Head = new node_t(value, Head, nullptr);
		Head->value = value;
		Head->next = nullptr;
		Head->prev = nullptr;
		Tail = Head;

		cout << "First node" << endl;
	}
	else
	{
		node_t *ptr = new node_t(value, Head, nullptr);
		ptr->value = value;
		ptr->next = Head;
		ptr->prev = nullptr;
		Head->prev = ptr;
		Head = ptr;
	}

}

void linked_list::push_back(double value)
{
	node_t *ptr = new node_t(value, Head, nullptr);
	if (Tail == nullptr || Head == nullptr)
	{
		Head = new node_t(value, Head, nullptr);
		Head->value = value;
		Head->next = nullptr;
		Head->prev = nullptr;
		Tail = Head;

		cout << "First node" << endl;
	}
	else
	{
		Tail->next = ptr;
		ptr->value = value;
		ptr->next = nullptr;
		ptr->prev = Tail;
		Tail = ptr;
	}

}

size_t linked_list::size() const
{
	size_t counter = 0;
	node_t *ptr2;
	ptr2 = Head;

	while (ptr2 != nullptr)
	{
		counter++;
		ptr2 = ptr2->next;

	}
	return counter;
}
void linked_list::print()
{
	node_t *pointer = Head;
	while (pointer != nullptr)
	{
		cout << pointer->value << endl;
		pointer = pointer->next;
	}
}
double linked_list::front() const
{
	if (Head == nullptr)
	{
		return NULL;
	}

	else
	{
		return Head->value;
	}
}

double linked_list::back() const{	if (Tail == nullptr)
	{
		return NULL;
	}

	else
	{
		return Tail->value;
	}}double linked_list::pop_front(){	double sendback;	node_t *remove = Head;	if (Head == nullptr)	{				return NULL;	}	else if (Head->next == nullptr)	{				sendback = front();		Head = nullptr;		delete remove;		return sendback;	}	else	{				sendback = front();		Head = Head->next;		delete remove;		return sendback;	}	}double linked_list::pop_back(){		double sendback;	node_t *remove = Tail;
	if (Tail == nullptr)
	{
		return NULL;
	}
	else if (Tail->prev==nullptr)
	{
		sendback = back();
		Tail = nullptr;
		delete remove;
		return sendback;
	}
	else
	{
		sendback = back();
		Tail = Tail->prev;
		Tail->next = nullptr;
		delete remove;
		return sendback;
	}
	}void linked_list::remove(size_t pos){	node_t *remove = Head;	size_t counter = 1;	while (counter != pos)	{		remove = remove->next;		counter++;	}	if (remove->next == nullptr && remove->prev == nullptr)	{		cout << "test4" << endl;		remove = Head;		delete remove;	}	else if (remove->prev == nullptr)	{		cout << "test1" << endl;		remove = Head;		Head = Head->next;		delete remove;	}	else if (remove->next == nullptr)	{		cout << "test2" << endl;		remove = Tail;		Tail = Tail->prev;		Tail->next = nullptr;		delete remove;	}	else	{		cout << "test3" << endl;		remove->next->prev = remove->prev;		remove->prev->next = remove->next;		delete remove;	}}
void linked_list::print_reverse() const{	node_t *pointer = Tail;
	while (pointer != nullptr)
	{
		cout << pointer->value << endl;
		pointer = pointer->prev;
	}}double linked_list::at(size_t pos) const{	node_t *pointer = Head;	size_t counter = 1;	if (pos <= size())	{		while (counter != pos)		{			pointer = pointer->next;			counter++;		}	}	else	{		return NULL;	}}bool linked_list::is_empty() const{	if (Tail == nullptr || Head == nullptr)	{		return true;	}	else	{		return false;	}}