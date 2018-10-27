#include <iostream>
#include "ForwardList.h"

int main()
{
	tForwardList<int> List;
	List.push_front(3);
	List.push_front(3);
	List.push_front(2);
	List.push_front(3);
	List.push_front(3);
	List.push_front(4);
	List.push_front(5);

	//List.pop_front();
	List.remove(3);

	std::cout << List.front() << std::endl;

	return 0;
}