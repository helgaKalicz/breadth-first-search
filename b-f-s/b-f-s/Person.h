#include <iostream>
#include <vector>
#include <string>


class Person
{
public:
	explicit Person(std::string name, int id);
	~Person();

	std::string getName();
	int getID();
	void addFriend(Person *person);
	std::vector<Person> listFriends();
	int friendsSize();

private:
	std::string name;
	int id;
	std::vector<Person> friends;
};
