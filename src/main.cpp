#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#include "Screen.hpp"
using namespace std;

map<string, string> buildMap(ifstream& map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
	{
		try
		{
			if (value.size() > 1)
			{
				//trans_map[key] = value.substr(1);
				trans_map.insert({key, value.substr(1)});
			}
			else
			{
				throw runtime_error(key);
			}
		}
		catch (runtime_error err)
		{
			cerr << "no rule for " << err.what() << endl;
			trans_map.erase(err.what());
			continue;
		}
	}

	return trans_map;
}

const string& transform(const string& s, const map<string, string>& m)
{
	auto iter = m.find(s);
	if (iter != m.cend())
	{
		return iter->second;
	}
	else
	{
		return s;
	}
}

void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word; bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	StrBlob b1;
	{
		StrBlob b2({"a" ,"an", "the"});
		b1 = b2;
		b2.push_back("about");
	}
	cout << b1.size() << endl;
	return 0;
}
