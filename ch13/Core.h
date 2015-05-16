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

    // virtual function to check if object hold values for student record
    // or not
    // in exercise 13-3
    virtual bool valid() const { return !homework.empty(); }

    // virtual function to check if it did all the homework
    // in exercise 13-5
    virtual bool finish_check() const
    {
        return (std::find(homework.begin(), homework.end(), 0.0)
                == homework.end());
    }
    

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


    // virtual function to check if it do the thesis
    // inherit from finish_check
    // exercise 13-5
    bool finish_check() const { return thesis > 0.0; }

protected:
    // virtual clone function
    // put it in protected
    // the return type is not the same as base class
    Grad* clone() const { return new Grad(*this); }

private:
    double thesis;

};

class PassAndFail: public Core {
public:
    PassAndFail() { }

    // use Core's read function
    // because it didn't have thesis
    PassAndFail(std::istream& is) { Core::read(is); }

    double grade() const 
    {
        if (homework.size() > 0)
            return ::grade(midterm, final, homework);
        else 
            return (midterm + final) / 2;
    }

    // they don't need to do any homework
    bool valid() const { return true; }
    bool finish_check() const { return true; } 

    // don't need to write virtual destructer
    // it is inherited
private:
    PassAndFail* clone() const { return new PassAndFail(*this); }
};


class Audit: public Core {
public:
    Audit() { }
    // use its own read function
    Audit(std::istream& is) { read(is); }

    std::istream& read(std::istream&);
    double grade() const { return 0.0; }

    // assume they all did their homework
    // since they are audit, so we don't care
    bool valid() const { return true; }
    bool finish_check() const { return true; }
private:
    Audit* clone() const { return new Audit(*this); }
};

// not class memeber function
bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

// map numeric grade to a letter grade
// exercise 13-4.cpp
std::string map_to_letter(double);


#endif
