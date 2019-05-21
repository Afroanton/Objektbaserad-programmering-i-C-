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

double linked_list::back() const
	{
		return NULL;
	}

	else
	{
		return Tail->value;
	}
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
	
void linked_list::print_reverse() const
	while (pointer != nullptr)
	{
		cout << pointer->value << endl;
		pointer = pointer->prev;
	}