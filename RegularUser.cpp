//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#include "RegularUser.h"
#include <string>

using namespace std;

RegularUser::RegularUser() : id(0), name("") {}

RegularUser::RegularUser(int id, const string& name) : id(id), name(name) {}

int RegularUser::getId() const {
    return id;
}

const string& RegularUser::getName() const {
    return name;
}
