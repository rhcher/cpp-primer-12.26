#include "Screen.hpp"
using namespace std;

TextQuery::TextQuery(ifstream& in)
{
	string line;
	auto num = 1;
	while (getline(in, line))
	{
		auto linetmp = line;
		string numtmp = to_string(num);
		numtmp.append(") ");  // 匹配输出格式
		lines.push_back(numtmp + line);
		++num;

		istringstream is(linetmp);	// 此处读入的是原始文本
		string word;
		while (is >> word)
		{
			wordProcess(word);	// 处理单词
			auto tmp = rules[word];
			++wordCount[word];
			if (tmp.size() == 0)
			{
				tmp.push_back(numtmp + line);
			}
			if (find(tmp.begin(), tmp.end(), numtmp + line) == tmp.end())
			{
				tmp.push_back(numtmp + line);
			}
			rules[word] = tmp;
		}
	}
}

// 打印单词及其对应的句子
void TextQuery::print() const
{
	auto f = [&](const pair<string, vector<string>>& p) {
		cout << "<" << p.first << ">"
			 << " occurs " << wordCount.at(p.first) << " times" << endl;
		auto s = [](const string& s) { cout << "    (line " << s << endl; };
		for_each(p.second.begin(), p.second.end(), s);
	};

	for_each(rules.begin(), rules.end(), f);
}

// 打印读取的文本
void TextQuery::printText() const
{
	for_each(lines.begin(), lines.end(), [](const string& s) { cout << s << endl; });
}

// 查询单词出现的次数并输出全部所在行
void TextQuery::wordQuery(const std::string& word) const
{
	if (rules.find(word) == rules.end())
	{
		cerr << "no this word!" << endl;
		return;
	}
	auto check = [&]() { return wordCount.at(word) > 1; };  // 判断是单数还是复数
	cout << word << " occurs " << wordCount.at(word) << (check() ? " times" : " time") << endl;
	auto f = [](const string& s) {
		cout << "    (line " << s << endl;
	};
	for_each(rules.at(word).begin(), rules.at(word).end(), f);
}
