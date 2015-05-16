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

    /*
    while (isspace(ch))
        is >> ch;
    cout << ch << endl;
    */
    
    // use Core or Grade constuct funtion to read the input and construct
    if (ch == 'U')
        cp = new Core(is);
    else if (ch == 'G')
        cp = new Grad(is);
    else if (ch == 'P')
        cp = new PassAndFail(is);
    else if (ch == 'A')
        cp = new Audit(is);
    else
        throw runtime_error("no this kind of options for the object.");

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
