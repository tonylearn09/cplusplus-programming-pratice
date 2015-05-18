#include <algorithm>
#include <list>
#include <string>
#include <iostream>

#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::max;

// compile with extract_fail_vec_1.cpp
list<Student_info> extract_fails(list<Student_info>& v);

int main()
{
    list<Student_info> vs;
    Student_info s;
    string::size_type maxlen = 0;

    while (read(cin, s)) {
        maxlen = max(maxlen, s.name.size());
        vs.push_back(s);
    }

    // list has to use its own member function for sort
    vs.sort(compare);

    list<Student_info> fails = extract_fails(vs);


    for (list<Student_info>::iterator iter = fails.begin();
            iter != fails.end(); ++iter)
        cout << iter->name << " " << grade(*iter) << endl;

    return 0;
}
