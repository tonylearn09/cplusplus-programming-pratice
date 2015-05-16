#include "Core.h"

using namespace std;

std::istream& read_hw(std::istream&, std::vector<double>&);

istream& Core::read_common(istream& in)
{
    // read and store student's name and exam grade
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

bool compare(const Core& x, const Core& y)
{
    return x.name() < y.name();
}


