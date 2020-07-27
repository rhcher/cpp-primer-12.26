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

void Foo(forward_list<int>& flst)
{
	auto curr = flst.begin();
	auto prev = flst.before_begin();
	while (curr != flst.end())
	{
		if (*curr % 2 == 0)
		{
			curr = flst.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else
		{
			curr = flst.erase_after(prev);
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
	Foo(flst);
	return 0;
}
