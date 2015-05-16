#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "grade.h"

// Core defintion
class Core {
    // it can access the clone function
    friend class Student_info;
public:
    Core(): midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }

    std::string name() const { return n; }

    // virtual function for grade
    virtual double grade() const { return ::grade(midterm, final, homework); }
    // virtual function for read from istream
    virtual std::istream& read(std::istream&);

    // virtual destructer
    virtual ~Core() { }

protected:
    // accessible by derived class
    double midterm, final;
    // name
    std::string n;

    std::vector<double> homework;

    // read the common part of Core and Grad
    std::istream& read_common(std::istream&);

    // virtual clone function
    // we don't put it in public
    virtual Core* clone() const { return new Core(*this); }

};

// Grad definition
class Grad: public Core {
    // no need friend class Student_info
    // since Student_info never refer to Grad directory
    // it use virtual Core::clone instead
public:
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }
    
    // virtual function for grade
    double grade() const { return std::min(thesis, Core::grade()); }
    // virtual function for read
    std::istream& read(std::istream&);

    // no need to declare virtual destructer
    // since it was inherited

protected:
    // virtual clone function
    // put it in protected
    // the return type is not the same as base class
    Grad* clone() const { return new Grad(*this); }

private:
    double thesis;

};


// not class memeber function
bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

#endif
