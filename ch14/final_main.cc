#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    char ch;
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // compare must be rewritten to work on const Handle<Core>&
    sort(students.begin(), students.end(), Student_info::compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
            << string(maxlen + 1 - students[i].name().size(), ' ');

        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error& e) {
            cout << e.what() << endl;
        }
        // no `delete' statement
        // delete automatically when get out of main
    }

    return 0;

}
