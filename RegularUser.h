//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#ifndef HW3_REGULARUSER_H
#define HW3_REGULARUSER_H
#include <iostream>
#include <string>

#include "LinkedSortedList.h"
#include "LinkedSortedList.cpp"

using namespace std;


class RegularUser {
public:
    RegularUser();
    RegularUser(int id, const string& name);
    int getId() const;
    const string& getName() const;

private:
    int id;
    string name;
};


#endif //HW3_REGULARUSER_H
