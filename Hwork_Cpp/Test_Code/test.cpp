#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;



int main(int argc, char const *argv[])
{
    list <int> arr ;

    arr.push_back(1);

    arr.push_back(3);

    arr.push_back(5);

    arr.push_back(2);

    arr.push_back(4);

    arr.push_back(6);

    arr.erase(arr.begin()+3)

    for (list<int>::iterator i = arr.begin() ; i != arr.end(); i++){
        printf("%d  ", *i);
    }

    return 0;
}
