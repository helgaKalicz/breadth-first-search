#include "stdafx.h"
#include <iostream>
#include "People.h"


int main()
{
	People homework;
	homework.findFriendsInRange("Arden Lucian", 1);
	std::cout << "\n\n\n";
	homework.findFriendsInRange("Arden Lucian", 3);
	std::cout << "\n\n\n";
	homework.findFriendsInRange("Tanya Rajah", 1);
	std::cout << "\n\n\n";

	int c;
	std::cin >> c;
	return 0;
};
