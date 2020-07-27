#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	vector<int> ivec;
	cout << "ivec: size: " << ivec.size() << endl;
	cout << "      capacity: " << ivec.capacity() << endl;
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
	{
	ivec.push_back(ix);
	}
	cout << "ivec: size: " << ivec.size() << endl;
	cout << "      capacity: " << ivec.capacity() << endl;
	cout << "ivec : " << endl;
	for (auto item : ivec)
	{
		cout << item << " ";
	}
	return 0;
}
