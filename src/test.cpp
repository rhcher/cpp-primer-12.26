#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(int argc, char* argv[])
{
	string s{"abcde"};
	auto num = 32;
	string tmp = to_string(num);
	tmp.append(". ");
	cout << tmp + s << endl;
	return 0;
}
