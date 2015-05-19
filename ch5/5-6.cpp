#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;
using std::max;

vector<Student_info> extrace_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;

    vector<Student_info>::size_type i = 0;

    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.insert(students.begin(), students[i]);
            // change index to point to the current element
            // since there is one more element in the front
            ++i;
        } 
        ++i;
    }

    // the remain size of pass students
    students.resize(students.size() - fail.size());

    return fail;
}

int main()
{
    vector<Student_info> vs;
    Student_info s;
    string::size_type maxlen = 0;
    while (read(cin, s)) {
        maxlen = max(maxlen, s.name.size());
        vs.push_back(s);
    }

    // sort(vs.begin(), vs.end(), compare);

    // test the time
    clock_t start = clock();
    vector<Student_info> fails = extrace_fails(vs);
    clock_t elapsed = clock() - start;

    cout << "Elapsed: " << elapsed << endl;

    return 0;
}
