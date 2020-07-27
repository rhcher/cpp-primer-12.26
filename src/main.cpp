#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void Foo(list<int>& lst)
{
	auto iter = lst.begin();
	while (iter != lst.end())
	{
		if ((*iter) % 2 == 0)
		{
			iter = lst.insert(iter, *iter);
			++iter;
			++iter;
		}
		else
		{
			iter = lst.erase(iter);
		}
	}
	for (auto item : lst)
	{
		cout << item << " ";
	}
	cout << endl;
}

void Function(forward_list<int>& flst)
{
	auto iter = flst.begin();
	auto prev = flst.before_begin();
	while (iter != flst.end())
	{
		if (*iter % 2 == 0)
		{
			iter = flst.insert_after(iter, *iter);
			prev = iter;
			++iter;
		}
		else
		{
			iter = flst.erase_after(prev);
		}
	}
	for (auto item : flst)
	{
		cout << item << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Foo(lst);
	Function(flst);
	return 0;
}
