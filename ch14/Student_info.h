#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>

#include "Core.h"
#include "Ptr.h"

class Student_info {
public:
    Student_info() { }
    Student_info(std::istream& is) {  read(is); }

    // no copy, assign, or destruct: they are in Handle

    std::istream& read(std::istream&);

    std::string name() const
    {
        if (cp)
            return cp->name();
        else
            throw std::runtime_error("uninitialized Student");
    }

    double grade() const
    {
        if (cp)
            return cp->grade();
        else
            throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& x, const Student_info& y)
    {
        return x.name() < y.name();
    }

private:
    Ptr<Core> cp;
};
#endif
