#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string expr{"1*(2+3)"};
	stack<char> c_stack;
	auto seen = 0;
	auto rep = '#';
	for (auto item : expr)
	{
		c_stack.push(item);
		if (c_stack.top() == '(')
		{
			++seen;
		}
		if (seen && item == ')')
		{
			while (c_stack.top() != '(')
			{
				c_stack.pop();
			}
			c_stack.pop();
			c_stack.push(rep);
			--seen;
		}
	}

	string output{};
	for (; !c_stack.empty(); c_stack.pop())
	{
		output.insert(output.begin(), c_stack.top());
	}
	cout << output << endl;
	return EXIT_SUCCESS;
}
