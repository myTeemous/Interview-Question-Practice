#include <iostream>
#include <set>
#include <list>
using namespace std;

/*
Remove all duplicates from a Linked list
------------------------------------------
The solution below iterates through the list inserting each element into a hash set.
The set does not allow duplicates so if the insertion fails then that means that element 
has already appeared in the list and needs to be removed.
------------------------------------------
O(n) time
O(n) space
*/

int main() {

	set<char> charSet;  //hash set of chars, no duplicates allowed
	list<char> str({ 'a', 'a', 'b', 'b', 'b', 'c', 'd', 'e', 'e', 'f', 'g', 'h', 'h' });  //linked list of chars

	auto listItr = str.begin();  //iterator pointing to the beginning of str

	while (listItr != str.end()) {

		auto setItr = charSet.insert(*listItr);  //insert the current element into the set

		if (setItr.second == false) {  //if insertion fails delete the current node and increment the iterator

			auto duplicate = listItr;
			++listItr;
			str.erase(duplicate);
		}
		else  //insertion succeeded increment the iterator
			++listItr;
	}

	for (auto itr = str.begin(); itr != str.end(); ++itr)  //print the list
		cout << *itr << " ";

	cout << "\n\n";
	cin.get();

	return 0;
}