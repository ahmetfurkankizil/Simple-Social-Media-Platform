//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#include <string>
#include "ContentCreator.h"


ContentCreator::ContentCreator() : id(0), name("") {}

ContentCreator::ContentCreator(int id, const string& name) : id(id), name(name) {}

ContentCreator::~ContentCreator(){
    Node<RegularUser>* regularUserCurrent = followers.getHead();
    while (regularUserCurrent != nullptr) {
        Node<RegularUser>* regularUserTemp = regularUserCurrent;
        regularUserCurrent = regularUserCurrent->getNext();
        regularUserTemp = nullptr;
        delete regularUserTemp;
    }

    Node<Content>* contentCurrent = individualContents.getHead();
    while (contentCurrent != nullptr) {
        Node<Content>* contentTemp = contentCurrent;
        contentCurrent = contentCurrent->getNext();
        contentTemp = nullptr;
        delete contentTemp;
    }
}

int ContentCreator::getId() const {
    return id;
}

const string& ContentCreator::getName() const {
    return name;
}

void ContentCreator::setId(int id) {
    this->id = id;
}

void ContentCreator::setName(const string& name) {
    this->name = name;
}

LinkedSortedList<Content> ContentCreator::getContents() const {
    return individualContents;
}

LinkedSortedList<RegularUser> ContentCreator::getFollowers() const {
    return followers;
}

void ContentCreator::addIndividualContent(Content& newContent){
    individualContents.insertSorted(newContent);
}
void ContentCreator::removeIndividualContent(int contentId){
    individualContents.remove(contentId);
}

void ContentCreator::addIndividualFollower(RegularUser& newFollower){
    followers.insertSorted(newFollower);
}
void ContentCreator::removeIndividualFollower(int followerId){
    followers.remove(followerId);
}