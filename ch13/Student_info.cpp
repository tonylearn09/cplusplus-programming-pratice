#include <iostream>
#include <stdexcept>
#include <cctype>

#include "Core.h"
#include "Student_info.h"

using namespace std;

istream& Student_info::read(istream& is)
{
    // delete previous object, if any
    // won't bother to delete unexisting object
    delete cp;

    char ch;
    is >> ch;

    // use Core or Grade constuct funtion to read the input and construct
    if (ch == 'U')
        cp = new Core(is);
    else if (ch == 'G')
        cp = new Grad(is);
    else if (ch == 'P')
        cp = new PassAndFail(is);
    else if (ch == 'A')
        cp = new Audit(is);
    else {
        // need to create a pointer, or otherwise when we call the destructer
        // it will have cored dump
        // since there is no pointer 
        // besides, every line in linux end with '\n'
        // and the last line in the file end with '\n''EOF'
        // so it will call this else when it read the 'EOF'
        // since it is not 'U' or 'G' ...
        cp = 0;
        /* throw runtime_error("read invalid student type"); */
    }
    return is;
}

// copy constructer
Student_info::Student_info(const Student_info& s): cp(0)
{
    if (s.cp)
        cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
    // check for self assignment
    if (&s != this) {
        delete cp;
        if (s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }

    return *this;
}
