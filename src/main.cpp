#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	map<string, size_t> word_count;
	map<string, vector<int>> svmap;
	pair<map<string, vector<int>>::iterator, bool> iter = svmap.insert({"hello", {1, 2, 3, 4, 5}});
	ifstream is("../include/Screen.hpp");
	string word;
	while (is >> word)
	{
		++word_count.insert({word, 0}).first->second;
	}
	for_each(word_count.begin(), word_count.end(), [](const pair<string, size_t>& p) { cout << "{" << p.first << ", " << p.second << "}" << endl; });
	return 0;
}
