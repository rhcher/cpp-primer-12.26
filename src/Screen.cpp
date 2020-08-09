#include "Screen.hpp"
using namespace std;

StrBlob::StrBlob()
	: data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il)
	: data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const std::string& mgs) const
{
	if (i >= data->size())
	{
		throw out_of_range(mgs);
	}
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
