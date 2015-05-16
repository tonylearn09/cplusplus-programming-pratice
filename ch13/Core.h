#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "grade.h"

// Core defintion
class Core {
public:
    Core(): midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }

    std::string name() const { return n; }

    // virtual function for grade
    virtual double grade() const { return ::grade(midterm, final, homework); }
    // virtual function for read from istream
    virtual std::istream& read(std::istream&);

protected:
    // accessible by derived class
    double midterm, final;
    // name
    std::string n;

    std::vector<double> homework;

    // read the common part of Core and Grad
    std::istream& read_common(std::istream&);

};

// Grad definition
class Grad: public Core {
public:
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }
    
    // virtual function for grade
    double grade() const { return std::min(thesis, Core::grade()); }
    // virtual function for read
    std::istream& read(std::istream&);

private:
    double thesis;
};


// not class memeber function
bool compare(const Core&, const Core&);

#endif
