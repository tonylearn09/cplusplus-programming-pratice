#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;
using std::max;

// compile with extract_fail_vec_1.cpp
// or extract_fail_vec_2.cpp
// or extract_fail_iter.cpp
vector<Student_info> extract_fails(vector<Student_info>& v);

int main()
{
    vector<Student_info> vs;
    Student_info s;
    string::size_type maxlen = 0;

    while (read(cin, s)) {
        maxlen = max(maxlen, s.name.size());
        vs.push_back(s);
    }

    sort(vs.begin(), vs.end(), compare);

    vector<Student_info> fails = extract_fails(vs);

    for (int i = 0; i < fails.size(); ++i)
        cout << fails[i].name << " " << grade(fails[i]) << endl;

    return 0;
}
