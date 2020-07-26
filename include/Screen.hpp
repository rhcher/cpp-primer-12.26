#pragma once
#include <iostream>
#include <string>
#include <vector>

class Screen
{
	friend class Window_mgr;

public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c)
		: height(ht), width(wd), contents(ht * wd, c) {}
	Screen(pos ht, pos wd)
		: Screen(ht, wd, ' ') {}
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);
	Screen& set(char);
	Screen& set(pos, pos, char);

	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;

	void do_display(std::ostream& os) const
	{
		for (decltype(cursor) index = 0; index < height; ++index)
		{
			os << contents.substr(index * width, width);
			os << std::endl;
		}
	}
};

inline Screen& Screen::move(pos r, pos c)
{
	pos row = (r - 1) * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];
}

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen& Screen::set(pos r, pos col, char c)
{
	contents[r * width + col] = c;
	return *this;
}

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);

private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};
