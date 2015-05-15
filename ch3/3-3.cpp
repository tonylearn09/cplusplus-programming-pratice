#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    typedef vector<string>::size_type vec_sz;

    vector<string> words;
    vector<int> appear_times;

    cout << "Enter words: ";
    string s;

    while (cin >> s) {
        bool repeat = false;

        for (vec_sz i = 0; i < words.size(); ++i) {
            if (s == words[i]) {
                ++appear_times[i];
                repeat = true;
            }
        }

        if (!repeat) {
            // first time to appear
            words.push_back(s);
            appear_times.push_back(1);
        }
    }

    for (vec_sz i = 0; i < words.size(); ++i)
        cout << words[i] << " appears " << appear_times[i] << " times."
            << endl;

    return 0;

}
