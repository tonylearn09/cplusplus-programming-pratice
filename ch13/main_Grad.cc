#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string>
#include <iomanip>

#include "Core.h"

using namespace std;

int main()
{
    vector<Grad> students;
    Grad record;
    string::size_type maxlen = 0;

    // read and store the data
    // read from Grad, not Core
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    // write names and grade
    for (vector<Grad>::size_type i = 0; i != students.size(); ++i) {
        cout << setw(maxlen + 1) << students[i].name();

        try {
            // Grad::grade
            double final_grade = students[i].grade();

            streamsize prec = cout.precision();
            cout << setprecision(3) << " " << final_grade
                << setprecision(prec) << endl;
        } catch (domain_error& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}

