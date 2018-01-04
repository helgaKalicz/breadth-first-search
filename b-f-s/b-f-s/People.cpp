#include "stdafx.h"
#include "People.h"



People::People()
{
	int idCounter = 0;
	makeListOfPeople();
	makeFriendForPeople();
}


People::~People()
{
}


void People::findFriendsInRange(std::string name, int distance)
{
	findFriends(name, distance);

	// Takes out the basic person's name from the set.
	for (std::string basicName : friends)
	{
		if (basicName == name)
		{
			friends.erase(basicName);
			break;
		}
	}

	// Prints out the list.
	std::cout << name << "'s friends in range " << distance << ":\n";
	for (std::string names : friends)
	{
		std::cout << "\t" << names << "\n";
	}

	// Clears the set to make this method reuseable.
	friends.clear();
}


void People::findFriends(std::string name, int distance)
{
	int range = 0;
	bool notInList = true;

	for (std::string personName : friends)
	{
		if (personName == name)
		{
			notInList = false;
			break;
		}
	}

	if (notInList)
	{
		friends.insert(name);
		if (range < distance)
		{
			for (Person person : vectorOfPeople)
			{
				if (person.getName() == name)
				{
					for (int i = 0; i < person.friendsSize(); ++i)
					{
						findFriends(person.listFriends()[i].getName(), distance - 1);
					}
					break;
				}
			}
		}
	}
}


void People::makeListOfPeople()
{
	std::string line;
	std::ifstream file;
	file.open("friends.txt");

	if (file.is_open())
	{
		std::vector<std::string> personData;
		std::string person;

		while (std::getline(file, line))
		{
			long lineLength = line.size();
			for (int i = 0; i < lineLength; ++i)
			{
				if (i == lineLength - 1)
				{
					person += line[i];
					personData.push_back(person);
					person.clear();
				}
				else if (line[i] == ',')
				{
					personData.push_back(person);
					person.clear();
					++i;
				}
				else
				{
					person += line[i];
				}
			}
			vectorOfFriends.push_back(personData);
			personData.clear();
		}
		file.close();

		for (std::vector<std::string> element : vectorOfFriends)
		{
			vectorOfPeople.emplace_back(Person(element[0], idCounter));
			++idCounter;
		}
	}
	else
	{
		std::cout << "Unable to open file";
	}
}


void People::makeFriendForPeople()
{
	long peopleSize = vectorOfFriends.size();
	for (int i = 0; i < peopleSize; ++i)
	{
		long friendsSize = vectorOfFriends[i].size();
		for (int j = 1; j < friendsSize; ++j)
		{
			for (Person person : vectorOfPeople)
			{
				if (person.getName() == vectorOfFriends[i][j])
				{
					vectorOfPeople[i].addFriend(&person);
					break;
				}
			}
		}
	}
}
