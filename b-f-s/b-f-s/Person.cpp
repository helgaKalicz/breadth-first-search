#include "stdafx.h"
#include "Person.h"


Person::Person(std::string name, int id)
{
	this->name = name;
	this->id = id;
}


Person::~Person()
{
}


std::string Person::getName()
{
	return this->name;
}


int Person::getID()
{
	return this->id;
}


void Person::addFriend(Person *person)
{
	friends.push_back(*person);
}


std::vector<Person> Person::listFriends()
{
	return this->friends;
}


int Person::friendsSize()
{
	return friends.size();
}
