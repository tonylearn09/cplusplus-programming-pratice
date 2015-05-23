#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string ascenders = "bdfhklt";
const string descenders = "gjpqy";

bool has_special_char(const string& word, const string& chars)
{
	for (string::const_iterator iter = word.begin(); 
		iter != word.end(); ++iter)
		for (string::const_iterator it = chars.begin(); 
			it != chars.end(); ++it)
			if (*iter == *it)
				return true;

	return false;
}

int main()
{
	vector<string> has_asc_or_dsc;
	string longest_word_without_special_char;
	string s;

	while (cin >> s)
		if (has_special_char(s, ascenders) || has_special_char(s, descenders))
			has_asc_or_dsc.push_back(s);
		else if (s.size() > longest_word_without_special_char.size())
			longest_word_without_special_char = s;

	cout << "\nHas ascenders or descenders: " << endl;

	for (vector<string>::const_iterator it = has_asc_or_dsc.begin();
		it != has_asc_or_dsc.end(); ++it)
		cout << *it << endl;

	cout << "Longest word without ascenders or descenders: " 
       << longest_word_without_special_char << endl;

  	return 0;
}