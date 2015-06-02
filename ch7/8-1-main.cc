#include <vector>
#include <iostream>

#include "8-1-analysis.h"
#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> did, didnt;

    Student_info student;
    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in",
            optimistic_median, did, didnt);

    return 0;
}
