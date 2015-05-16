#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

#include "Core.h"

using namespace std;

// this version almost work
// but need to define virtual destructer
int main()
{
    // store pointers, instead of objects
    vector<Core*> students;
    Core* record;

    // a input char to decide which kind of object to create
    char ch;
    string::size_type maxlen = 0;

    // read and store data
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;

        // record can decide use which read function
        record->read(cin);
        // dereference the pointer
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    // pass the version of `compare' that works on pointers
    sort(students.begin(), students.end(), compare_Core_ptrs);

    // write names and grade
    for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
        // students[i] is a pointer
        cout << students[i]->name() 
            << string(maxlen + 1 - students[i]->name().size(), ' ');

        try {
            double final_grade = students[i]->grade();

            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        } catch(domain_error& e) {
            cout << e.what() << endl;
        }

        // free the object allocated when reading
        delete students[i];
    }

    return 0;
    
}
