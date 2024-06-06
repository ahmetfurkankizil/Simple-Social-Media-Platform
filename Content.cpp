//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#include <string>
#include "Content.h"
using namespace std;


Content::Content() : id(0), name("") {}

Content::Content(int id, const string& name) : id(id), name(name) {}

int Content::getId() const {
    return id;
}

const string& Content::getName() const {
    return name;
}

void Content::setId(int id) {
    this->id = id;
}

void Content::setName(const string& name) {
    this->name = name;
}
