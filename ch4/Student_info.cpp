#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    // read and store student's name and midterm, final
    is >> s.name >> s.midterm >> s.final;
    // read and store homewrok
    read_hw(is, s.homework);
    return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    // if fail at the begining, then will leave in to be error state
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the error state, so input will work for the next one
        in.clear();
    }

    return in;
}
