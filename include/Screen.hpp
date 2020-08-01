#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Date
{
public:
	Date() = default;
	Date(std::string date)
	{
		// 1/1/1990
        std::string tmp= date.substr(date.find_first_of(number));
        day = std::stoi(tmp);
        tmp = tmp.substr(tmp.find_first_not_of(number));
        tmp = tmp.substr(tmp.find_first_of(number));
        month = std::stoi(tmp);
        tmp = tmp.substr(tmp.find_first_not_of(number));
        tmp = tmp.substr(tmp.find_first_of(number));
        year = std::stoi(tmp);
	}
	void date_show()
	{
		std::cout << "year: " << year << std::endl;
		std::cout << "month: " << month << std::endl;
		std::cout << "day: " << day << std::endl;
	}
	virtual ~Date() {}

private:
	unsigned year;
	unsigned month;
	unsigned day;
    static const std::string number;
};

const std::string Date::number {"0123456789"};
