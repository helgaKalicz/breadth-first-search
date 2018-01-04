#pragma once

#include "Person.h"
#include <fstream>
#include <set>


class People
{
public:
	People();
	~People();

	void findFriendsInRange(std::string name, int distance);

private:
	void makeListOfPeople();
	void makeFriendForPeople();
	void findFriends(std::string name, int distance);

	int idCounter;
	std::vector<std::string> friendsOfFriends;
	std::vector<Person> vectorOfPeople;
	std::vector<std::vector<std::string>> vectorOfFriends;
	std::set<std::string> friends;
};
