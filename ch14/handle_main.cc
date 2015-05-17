#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "Handle.h"
#include "Core.h"

using namespace std;

bool compare_Core_handles(const Handle<Core>& lhs, const Handle<Core>& rhs)
{
    return compare(*lhs, *rhs);
}

int main()
{
    vector< Handle<Core> > students;
    Handle<Core> record;
    char ch;
    string::size_type maxlen = 0;

    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;

        // Handle<T>::->, then virtual call to read
        record->read(cin);
        // Handle<T>::->
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    // compare must be rewritten to work on const Handle<Core>&
    sort(students.begin(), students.end(), compare_Core_handles);

    for (vector< Handle<Core> >::size_type i = 0; i != students.size(); ++i) {
        cout << students[i]->name()
            << string(maxlen + 1 - students[i]->name().size(), ' ');

        try {
            double final_grade = students[i]->grade();
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
