#include <iostream>
#include <set>
#include <list>
using namespace std;

int main() {

	set<char> charSet;
	list<char> str({ 'a', 'a', 'b', 'b', 'b', 'c', 'd', 'e', 'e', 'f', 'g', 'h', 'h' });

	auto listItr = str.begin();

	while (listItr != str.end()) {

		auto setItr = charSet.insert(*listItr);

		if (setItr.second == false) {

			auto duplicate = listItr;
			++listItr;
			str.erase(duplicate);
		}
		else
			++listItr;
	}

	for (auto itr = str.begin(); itr != str.end(); ++itr)
		cout << *itr << " ";

	cout << "\n\n";
	cin.get();

	return 0;
}