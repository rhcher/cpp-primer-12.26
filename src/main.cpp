#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Foo(string& s, const string& asc, const string& desc)
{
	string::difference_type diff = 0;
	string::size_type ascpos = 0;
	string::size_type descpos = 0;
	vector<string> result{};

	while ((ascpos = s.find_first_of(asc, ascpos)) != string::npos && (descpos = s.find_first_of(desc, descpos)) != string::npos)
	{
		if (ascpos < descpos)
		{
			result.push_back(s.substr(ascpos+1, descpos-1));
		}
		else
		{
			result.push_back(s.substr(descpos+1, ascpos-1));
		}
		++ascpos;
		++descpos;
	}

	for (auto i = result.cbegin(); i != result.cend(); ++i)
	{
		size_t max = (*i).size();
		for (auto iter = i + 1; iter != result.cend();)
		{
			if (max < (*iter).size())
			{
				result.insert(result.cbegin(), *iter);
				iter = result.erase(iter);
			}
			++iter;
		}
	}

	cout << "the result is : " <<result.at(0)<<endl;
}

int main(int argc, char* argv[])
{
	string ascender{"bdfhklt"};
	string descender{"gjpqy"};
	string s{};
	cout << "Please input a string : " << endl;
	cin >> s;
	Foo(s, ascender, descender);
}
