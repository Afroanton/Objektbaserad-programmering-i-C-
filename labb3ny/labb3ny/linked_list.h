#pragma once
#include <iostream>
#include <string>
using namespace std;

class linked_list
{
public:
	linked_list();
	linked_list(const linked_list& src);
	~linked_list();
	linked_list merge(linked_list list1, linked_list list2);
	linked_list & operator =(const linked_list & rhs);
	// adds elements to the back .
	//linked_list & operator +=(const linked_list & rhs);

	void insert(double value, size_t pos);
	void push_back(double value);
	size_t size() const;
	double front() const;
	double back() const;
	double at(size_t pos) const;
	double pop_front();
	double pop_back();
	void remove(size_t pos);
	bool is_empty() const;
	void print();
	void print_reverse() const;


private:
	struct node_t {
		node_t(double value, node_t * next = 0, node_t * prev = 0);
		double value;
		node_t *next;
		node_t *prev;
	};
	node_t *Head;
	node_t *Tail;
};
