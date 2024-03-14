#include <iostream>

using namespace std;

struct Elem
{
	Elem *link1,
		 *link2;
	int info;
};

int main()
{
	Elem *p;

	p = new Elem;										// 1
	p->info = 1;										// 2
	p->link1 = NULL;									// 3
	p->link2 = new Elem;								// 4
	p->link2->info = 2;									// 5
	p->link2->link1 = p->link1;							// 6
	p->link2->link2 = new Elem;							// 7
	p->link2->link2->info = 4;							// 8
	p->link2->link2->link1 = p;							// 9
	p->link2->link2->link2 = new Elem;					// 10
	p->link2->link2->link2->info = 3;					// 11
	p->link2->link2->link2->link1 = p;					// 12
	p->link2->link2->link2->link2 = p->link2->link1;	// 13

	delete p->link2->link2->link2;						// 14
	delete p->link2->link2;								// 15
	delete p->link2;									// 16
	delete p;											// 17

	return 0;
}