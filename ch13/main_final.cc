#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // record will decide which object to construct now
    while (record.read(cin)) {
        // record have member function name now
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // alphabetisz the student records
    sort(students.begin(), students.end(), Student_info::compare);

    // write the name and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) { 
        cout << students[i].name()
            << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
        
    }

    return 0;
}
