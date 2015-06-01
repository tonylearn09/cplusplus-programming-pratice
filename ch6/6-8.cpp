#include <vector>
#include <algorithm>
#include <iostream>

#include "6-8-classify.h"
#include "analysis.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main()
{
    // students who did all their homework
    vector<Student_info> did;

    Student_info student;

    // read the student records
    while (read(cin, student))
        did.push_back(student);
    
    // use did_all_hw to test the program
    vector<Student_info> didnt = classify(did, did_all_hw);

    // verify that the analyses will show us something
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // do the analysis
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in",
            optimistic_median_analysis, did, didnt);

    return 0;
}
