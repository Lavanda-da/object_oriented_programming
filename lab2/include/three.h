#pragma once

#include <string>
#include <iostream>

class Three
{ 
public:
    Three();
    Three(const size_t & n, unsigned char t = '0');
    Three(const std::initializer_list< unsigned char> &t);
    Three(const std::string &t);
    Three(const Three& other);
    Three(Three&& other) noexcept;      

    int size() const;
    void convertToString(std::string & s);    

    bool equals(const Three& other) const;
    bool more(const Three &other) const;
    bool less(const Three &other) const;
    Three sum(const Three& other);
    void add(const Three& other);
    Three subtraction(const Three& other);
    void remove(const Three& other);
    std::ostream& print(std::ostream& os);

    virtual ~Three() noexcept;

private:
    void addZeros(int n);
    void removeZeros();

private:
    size_t _size;
    unsigned char *_array;
};
