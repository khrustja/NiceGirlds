#include <iostream>
#include "Set.h"

using namespace std;
int main() {

    Set<int> set1{ 1, 2, 3, 4 };
    Set<int> set2{ 3, 4, 5, 6 };

    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;

    for (int i = 1; i < 10; ++i) set1.add(i);
    cout << "Addition: " << set1 << endl;

    Set<int> unionSet = set1.union_with(set2);
    cout << "Union: " << unionSet << endl;

    Set<int> intersectionSet = set1.intersection_with(set2);
    cout << "Intersection: " << intersectionSet << endl;

    Set<int> differenceSet = set1.difference_with(set2);
    cout << "Difference: " << differenceSet << endl;

    set1.remove(3);
    cout << "Remove: " << set1 << endl;

    int elementToCheck = 3;
    if (set1.contains(elementToCheck)) {
        cout << "Set contains element " << elementToCheck << endl;
    }
    else {
        cout << "Set does not contain element " << elementToCheck << endl;
    }

    set2.clear();
    cout << "Set2: " << set2;

    return 0;
}