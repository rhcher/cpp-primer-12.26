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

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}
