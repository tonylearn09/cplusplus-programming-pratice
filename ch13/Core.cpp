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

istream& Audit::read(istream& in)
{
    // only need name, since they are audit
    in >> n;
    return in;
}


bool compare(const Core& x, const Core& y)
{
    return x.name() < y.name();
}

bool compare_Core_ptrs(const Core* x, const Core* y)
{
    return compare(*x, *y);
}

string map_to_letter(double grades)
{
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    static const char* const letter_grade[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    // or static const size_t grade_number = sizeof(numbers) / sizeof(*numbers);
    static const size_t grade_number = sizeof(numbers) / sizeof(numbers[0]);

    // the highest number is in the front
    for (size_t i = 0; i < grade_number; ++i) {
        if (grades >= numbers[i])
            return letter_grade[i];
    }
    return "\?\?\?";
}
