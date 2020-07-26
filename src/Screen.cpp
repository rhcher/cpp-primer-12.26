#include "Screen.hpp"
using namespace std;

void Window_mgr::clear(ScreenIndex index)
{
	Screen& s = screens[index];
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& item)
{
	screens.push_back(item);
	return screens.size() - 1;
}
