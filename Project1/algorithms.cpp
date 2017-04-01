#include "stdafx.h"

struct Person
{
	string name;
	int age;

	friend ostream& operator<<(ostream& os, const Person& p)
	{
		return os << p.name << " is " << p.age << " years old.";
	}
};


int main()
{
	vector<Person> people{ {"John", 27}, {"Chris", 24}, {"Ann", 31} };

	auto print_all = [&]()
	{
		cout << people.size() << " persons:" << endl;
		//for_each(begin(people), end(people), [](const Person& p) {cout << p << endl; });
		for_each(people.begin(), people.end(), [](const Person& p) {cout << p << endl; });
	};

	print_all();

	auto oldest = *max_element(people.begin(), people.end(), [](const Person& p1, const Person& p2) {return p1.age < p2.age; });
	cout << oldest.name << " is the oldest" << endl;

	auto john = find_if(people.begin(), people.end(), [](const Person& p) {return p.name == string("John"); });
	if (john != people.end())
		cout << "Found " << john->name << " who is " << john->age << endl;

	auto youngerThan30 = count_if(people.begin(), people.end(), [](const Person& p) {return p.age < 30; });
	cout << "Found " << youngerThan30 << " people younger than 30" << endl;

	sort(people.begin(), people.end(), [](const Person& a, const Person& b) {return a.age < b.age; });
	cout << "People sorted by age:" << endl;
	print_all();

	Person jill{ "Jill",44 };
	replace_if(people.begin(), people.end(), [](const Person& p) {return p.name == "John"; },jill);
	print_all();

	system("pause");
	return 0;
}