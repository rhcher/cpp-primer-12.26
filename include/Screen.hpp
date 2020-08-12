#pragma once
#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class TextQuery
{
public:
	TextQuery() = default;
	TextQuery(std::ifstream& in);

	void print() const;
	void printText() const;
	void wordQuery(const std::string& s) const;

	virtual ~TextQuery() {}

private:
	//去除单词中的标点符号,并将所有单词出换为小写
	void wordProcess(std::string& s);
	const std::string punctuation = {"!@#$%^&*()-_=+,<.>/?|\"\'"};	//标点符号
	std::vector<std::string> lines;									// 读入的文本
	std::map<std::string, std::vector<std::string>> rules;			// 存储单词及其对应的句子
	std::map<std::string, int> wordCount;							// 存储单词以及其出现的次数
};

inline void TextQuery::wordProcess(std::string& s)
{
	auto beg = s.find_first_not_of(punctuation);
	auto end = s.find_first_of(punctuation, beg);
	s = s.substr(beg, end - beg);
	for (auto& item : s)
	{
		item = tolower(item);
	}
}
