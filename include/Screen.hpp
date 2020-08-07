#pragma once
#include <iostream>
#include <sstream>
#include <string>

class Sales_data
{
public:
    Sales_data() = default;
    unsigned int isbn() const
    {
        return this->isbn_;
    }
    virtual ~Sales_data () {}

private:
    unsigned int isbn_;
    std::string name_;
    std::string author_;
};
