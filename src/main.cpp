#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void Old_to_New(string& s, const string& oldVal, const string& newVal)
{
	cout << "Old string is : " << s << endl;
	for (auto iter = s.cbegin(); iter != s.cend() - oldVal.size() + 1; ++iter)
	{
		if (*iter == *oldVal.begin())
		{
			auto olditer = oldVal.begin();
			for (auto itertmp = iter; olditer != oldVal.end(); ++itertmp, ++olditer)
			{
				if (*itertmp != *olditer)
					break;
			}
			if (olditer == oldVal.end())
			{
				string::size_type pos = iter - s.cbegin();
				s.erase(iter, iter + oldVal.size());
				s.insert(pos, newVal);
				iter = s.cbegin() + pos + newVal.size();
			}
		}
	}
	cout << "new string is : " << s << endl;
}

int main(int argc, char* argv[])
{
	string s{"qthwepthoriurtythrasdfglkthrujhzxcvb"};
	Old_to_New(s, "tho", "though");
	Old_to_New(s, "thru", "through");
}
