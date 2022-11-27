#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
   list<string> list1, list2, list3;
   list1.push_back("eden@yahoo.com");
   list1.push_back("dva@yahoo.com");
   list1.push_back("tri@yahoo.com");

   list2.push_back("dva@yahoo.com");
   list2.push_back("cetiri@yahoo.com");
   list2.push_back("pet@yahoo.com");

   list3.push_back("eden@yahoo.com");
   list3.push_back("pet@yahoo.com");
   list3.push_back("sest@yahoo.com");

   list1.splice(list1.end(), list2);
   list1.splice(list1.end(), list3);

   // mora da se sortira za da se otstranat duplikati
   list1.sort();
   list1.unique();

   ostream_iterator<string> output(cout, " ");
   copy(list1.begin(), list1.end(), output);

    return 0;
}
