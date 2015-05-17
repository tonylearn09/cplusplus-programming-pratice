#include <algorithm>

#include "Core.h"
#include "grade.h"

using std::istream;
using std::string;
using std::vector;
using std::min;

std::istream& read_hw(std::istream& in, std::vector<double>& hw);


string Core::name() const { return n; } 

double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const
{
    return min(thesis, Core::grade());
}

bool compare(const Core& x, const Core& y)
{
    return x.name() < y.name();
}

bool compare_Core_ptrs(const Core* x, const Core* y)
{
    return compare(*x, *y);
}
