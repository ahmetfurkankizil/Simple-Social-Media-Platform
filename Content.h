//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#ifndef HW3_CONTENT_H
#define HW3_CONTENT_H
#include <iostream>
#include <string>
using namespace std;

#include "RegularUser.h"

class Content {
public:
    Content();
    Content(int id, const string& name);
    int getId() const;
    const string& getName() const;
    void setId(int id);
    void setName(const string& name);

private:
    int id;
    string name;
};


#endif //HW3_CONTENT_H
