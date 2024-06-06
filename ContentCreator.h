//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#ifndef HW3_CONTENTCREATOR_H
#define HW3_CONTENTCREATOR_H


#include <iostream>
#include <string>

#include "Content.h"

class ContentCreator {
public:
    ContentCreator();
    ContentCreator(int id, const string& name);
    ~ContentCreator();
    int getId() const;
    const string& getName() const;
    void setId(int id);
    void setName(const string& name);
    bool exists(int targetContentId) const;
    void addIndividualContent(Content& newContent);
    void removeIndividualContent(int contentId);
    void addIndividualFollower(RegularUser& newFollower);
    void removeIndividualFollower(int followerId);
    LinkedSortedList<Content> getContents() const;
    LinkedSortedList<RegularUser> getFollowers() const;

private:
    int id;
    string name;
    LinkedSortedList<Content> individualContents;
    LinkedSortedList<RegularUser> followers;
};


#endif //HW3_CONTENTCREATOR_H
