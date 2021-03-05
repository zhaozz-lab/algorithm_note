#include <iostream>
#include<chrono>
#include<vector>
#include<string>
using namespace std;
class Ball
{
public:
	// Factory Method
	static Ball* make_Ball(int choice);
	virtual void play() = 0;
};

class basketball : public Ball
{
public:
	void play()
	{
		cout << "play basketball \n";
	}
};
class football : public Ball
{
public:
	void play()
	{
		cout << "play football \n";
	}
};
class tableball : public Ball
{
public:
	void play()
	{
		cout << "play tableball \n";
	}
};

Ball* Ball::make_Ball(int choice)
{
	if (choice == 1)
		return new basketball;
	else if (choice == 2)
		return new football;
	else
		return new tableball;
}

int main()
{
	vector<Ball*> roles;
	int choice;
	while (true)
	{
		cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Ball::make_Ball(choice));
	}
	for (int i = 0; i < roles.size(); i++)
		roles[i]->make_Ball(i);
	for (int i = 0; i < roles.size(); i++)
		delete roles[i];
}

