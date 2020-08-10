#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <initializer_list>
class StrBlobPtr;

class StrBlob
{
public:
	friend StrBlobPtr;
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const
	{
		return data->size();
	}
	bool empty() const
	{
		return data->empty();
	}
	void push_back(const std::string& s)
	{
		data->push_back(s);
	}
	void pop_back();
	std::string front();
	std::string back();

	virtual ~StrBlob() {}

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& mgs) const;
};

class StrBlobPtr
{
public:
	StrBlobPtr()
		: curr(0) {}
	StrBlobPtr(StrBlob& s,std::size_t sz = 0)
		: wptr(s.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
	virtual ~StrBlobPtr() {}

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
