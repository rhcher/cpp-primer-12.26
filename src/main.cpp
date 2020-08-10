#include <algorithm>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
#include <memory>
using namespace std;
using ivec = shared_ptr<vector<int>>;

auto Foo() -> ivec
{
	return make_shared<vector<int>>();
}

auto scanf() -> ivec
{
	int i;
	auto in = Foo();
	while (cin >> i)
	{
		(*in).push_back(i);
	}
	return in;
}

void print()
{
	auto out = scanf();
	for_each((*out).cbegin(), (*out).cend(), [](const int& i) { cout << i << " "; });
	cout << endl;
}

void process(shared_ptr<int> ptr)
{

}

int main(int argc, char* argv[])
{
	shared_ptr<int> sp(new int(4));
	weak_ptr<int> wp(sp);
	cout <<  wp.use_count() <<endl;
	return 0;
}
