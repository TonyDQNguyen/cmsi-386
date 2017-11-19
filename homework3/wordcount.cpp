#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template <typename T1, typename T2>

struct organize {
	typedef pair<T1, T2> type;
	bool operator ()(type const& a, type const& b) const {
		return a.second > b.second;
	}
};

int main () {
	map<string, int> word_count;
	map<string, int>::iterator it;

	string file_line;
	string file_to_string;
	string file_name;

	cout <<  "Please enter the file you want to input into the word counter: \n";
	cin >> file_name;
	cout << "\n";

	ifstream in;
	in.open(file_name);

	if (!in.is_open()) {
		cout << "ERROR: File does not exist or is corrupted.";
		return -1;
	}

	while (!in.eof()) {
		getline(in, file_line);

		for (int i = 0; i < file_line.length(); i++) {
			if (!isalpha(file_line[i])){
				file_line.erase(i,1);
				file_line.insert(i, " ");
	    	}
		}
		file_to_string += file_line;
	}

	transform(file_to_string.begin(), file_to_string.end(), file_to_string.begin(), tolower);



	istringstream iss(file_to_string);

	while (iss) {
		string word;
		iss >> word;

		if (word.compare("") != 0) {
			it = word_count.find(word);
			if (it == word_count.end())
				word_count[word] = 1;

			else {
				int current = word_count.at(word);
				word_count.at(word) = current + 1;
			}
		}
	}

	vector<pair<string, int>> mapcopy(word_count.begin(), word_count.end());
	sort(mapcopy.begin(), mapcopy.end(), organize<string, int>());

	for (int x = 0; x != mapcopy.size(); x++)
	    cout << mapcopy.at(x).first << " " << mapcopy.at(x).second << "\n";

	in.close();
	return 0;
}
