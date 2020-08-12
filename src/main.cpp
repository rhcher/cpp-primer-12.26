#include "Screen.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	ifstream in("data/text");
	if (!in.is_open())
	{
		cerr << "open fail! " << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq(in);
	cout << "Please input the string that you want to query : ";
	string input;
	cin >> input;
	tq.wordQuery(input);
	return 0;
}
