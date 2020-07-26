#include <forward_list>
#include <iostream>
#include <vector>
using namespace std;

void find_to_delete(forward_list<string>& flst, const string& s1, const string& s2)
{
	[[maybe_unused]] auto prev = flst.cbefore_begin();
	auto curr = flst.begin();

	while (curr != flst.end())
	{
		if ((*curr) == s1)
		{
			flst.insert_after(curr, s2);
			break;
		}
		else
		{
			++curr;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		cout << "helloworld";
	}
}
