#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    deque<int> intDeque;
    vector<int> intVector;
    ostream_iterator<int> output(cout, " ");

    intDeque.push_back(1);
    intDeque.push_back(2);
    intDeque.push_back(3);
    intDeque.push_back(4);
    intDeque.push_back(5);

    cout << "Deque: \n";
    copy(intDeque.begin(), intDeque.end(), output);

    for(int i = 0; i < intDeque.size(); ++i)
    {
        intVector.push_back(intDeque[i]);
    }
    cout << "\nVector: \n";
    copy(intVector.begin(), intVector.end(), output);

    reverse(intVector.begin(), intVector.end());

    cout << "\nReversed vector: \n";
    copy(intVector.begin(), intVector.end(), output);

    return 0;
}
