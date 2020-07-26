/*
 * @Author: skynine
 * @Date: 2020-07-24 21:05:37
 * @LastEditors: skynine
 * @LastEditTime: 2020-07-24 21:06:27
 * @Description: file content
 */
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main()
{
	forward_list<int> flst{1, 2, 3, 4, 5, 6, 7};
	auto prev = flst.cbefore_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
	}
}
