#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool has_uppercase(const string& words)
{
    for (string::const_iterator i = words.begin(); i != words.end(); ++i)  
        if (isupper(*i))
            return true;

    return false;
}

void print_string_vector(const vector<string>& v)
{
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << endl;
}

int main()
{
    string s;
    vector<string> lower_case_string;
    vector<string> upper_case_string;

    while (cin >> s)
        if (has_uppercase(s))
            upper_case_string.push_back(s);
        else
            lower_case_string.push_back(s);

    cout << "\nNo uppercase letters:" << endl;
    print_string_vector(lower_case_string);

    cout << "Has uppercase letters:" << endl;
    print_string_vector(upper_case_string);

}
