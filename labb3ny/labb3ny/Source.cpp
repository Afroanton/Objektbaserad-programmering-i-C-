#include "linked_list.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
using namespace std;
void printlist(linked_list list)
{
	list.print();
}
linked_list merge(linked_list list1, linked_list list2)
{
	linked_list list4;
	while (!list1.is_empty() && !list2.is_empty())
	{
		if (list1.front() <= list2.front())
		{
			list4.push_back(list1.pop_front());

		}

		else
		{
			list4.push_back(list2.pop_front());

		}


	}
	while (!list1.is_empty())
	{
		list4.push_back(list1.pop_front());
	}
	while (!list2.is_empty())
	{
		list4.push_back(list2.pop_front());
	}
	return list4;
}
int main()
{
	srand(time(0));
	int menyval;
	int tal = 0;

	while (true)
	{

		cout << "[1]Kör" << endl;
		cin >> menyval;
		if (menyval == 1)
		{

			linked_list list1;
			linked_list list2;
			linked_list list3;
			linked_list list4;

			for (int counter = 0; counter < 100; counter++)
			{
				tal = tal + rand() % 20;
				list1.push_back(tal);
			}

			tal = 0;

			for (int counter = 0; counter < 100; counter++)
			{
				tal = tal + rand() % 20;
				list2.push_back(tal);
			}

			if (list1.at(50) < list2.at(50))
			{
				list2.remove(50);
				list3 = list1;
			}
			else if (list2.at(50) < list1.at(50))
			{
				list1.remove(50);

				list3 = list2;
			}
			else
			{
				cout << "Listorna har lika värde" << endl;
				list3 = list1;
			}
		
			for (int counter = 0; counter < 50; counter++)
			{
				
				list3.pop_back();
				list3.push_front(list3.pop_back());
			}
			cout << "Lista 3" << endl;			printlist(list3);			cout << endl << endl;			
			list4=merge(list1, list2);
			printlist(list4);
			cout << "Lista 4" << endl;
			list4.print();
			list4.ordning();
		}

	}

}

