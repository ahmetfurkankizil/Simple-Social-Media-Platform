//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#include <iostream>
#include <string>
#include "SocialMediaPlatform.h"


SocialMediaPlatform::SocialMediaPlatform(){}
SocialMediaPlatform::~SocialMediaPlatform(){
    Node<ContentCreator>* creatorCurrent = contentCreators.getHead();
    while (creatorCurrent != nullptr) {
        Node<ContentCreator>* contentCurrentTemp = creatorCurrent;
        creatorCurrent = creatorCurrent->getNext();
        contentCurrentTemp = nullptr;
        delete contentCurrentTemp;
    }

    Node<RegularUser>* regularUserCurrent = regularUsers.getHead();
    while (regularUserCurrent != nullptr) {
        Node<RegularUser>* regularUserTemp = regularUserCurrent;
        regularUserCurrent = regularUserCurrent->getNext();
        regularUserTemp = nullptr;
        delete regularUserTemp;
    }

    Node<Content>* contentCurrent = allContents.getHead();
    while (contentCurrent != nullptr) {
        Node<Content>* contentTemp = contentCurrent;
        contentCurrent = contentCurrent->getNext();
        contentTemp = nullptr;
        delete contentTemp;
    }
}

void SocialMediaPlatform::addRegularUser( const int regularUserId, const string name ){
    if(regularUsers.isEmpty()) {
        RegularUser newUser(regularUserId, name);
        regularUsers.insertSorted(newUser);
        std::cout << "Added regular user " << regularUserId << "."  << std::endl;
    } else {
        if (regularUsers.exists(regularUserId)) {
            std::cout << "Cannot add regular user. There is already a regular user with ID " << regularUserId << "." << std::endl;
        } else {
            RegularUser newUser(regularUserId, name);
            regularUsers.insertSorted(newUser);
            std::cout << "Added regular user " << regularUserId << "."  << std::endl;
        }
    }
}

void SocialMediaPlatform::removeRegularUser( const int regularUserId ){
    if(regularUsers.isEmpty()) {
        std::cout << "Cannot remove regular user. There is no regular user with ID " << regularUserId << "." << std::endl;
    } else {
        if (!regularUsers.exists(regularUserId)) {
            std::cout << "Cannot remove regular user. There is no regular user with ID " << regularUserId << "." << std::endl;
        } else {
            Node<ContentCreator>* current = contentCreators.getHead();
            for (int i = 0; i < contentCreators.getLength(); ++i) {
                if (current->getItem().getFollowers().exists(regularUserId)) {
                    current->getItem().removeIndividualFollower(regularUserId); // Return a pointer to the found ContentCreator
                }
                current = current->getNext();
            }
            regularUsers.remove(regularUserId);
            std::cout << "Removed regular user " << regularUserId << "."  << std::endl;
        }
    }
}

void SocialMediaPlatform::addContentCreator( const int contentCreatorId, const string name ){
    if(contentCreators.isEmpty()) {
        ContentCreator newContentCreator(contentCreatorId, name);
        contentCreators.insertSorted(newContentCreator);
        std::cout << "Added content creator " << contentCreatorId << "."  << std::endl;
    } else {
        if (contentCreators.exists(contentCreatorId)) {
            std::cout << "Cannot add content creator. There is already a content creator with ID " << contentCreatorId << "." << std::endl;
        } else {
            ContentCreator newContentCreator(contentCreatorId, name);
            contentCreators.insertSorted(newContentCreator);
            std::cout << "Added content creator " << contentCreatorId << "."  << std::endl;
        }
    }
}

void SocialMediaPlatform::removeContentCreator( const int contentCreatorId ){
    if(contentCreators.isEmpty()) {
        std::cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId << "." << std::endl;
    } else {
        if (!contentCreators.exists(contentCreatorId)) {
            std::cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId << "." << std::endl;
        } else {
            contentCreators.remove(contentCreatorId);
            std::cout << "Removed content creator " << contentCreatorId << "."  << std::endl;
        }
    }
}

void SocialMediaPlatform::addContent( const int contentCreatorId, const int contentId, const string title ){
    if (allContents.exists(contentId)) {
        std::cout << "Cannot add content. There is already a content with ID " << contentId << "." << std::endl;
    } else {
        if (!contentCreators.exists(contentCreatorId)) {
            std::cout << "Cannot add content. There is no content creator with ID " << contentCreatorId << "." << std::endl;
        } else {
            Content newContent(contentId, title);
            addContentToContentCreatorById(contentCreatorId, newContent);
            allContents.insertSorted(newContent);
            std::cout << "Added content " << contentId << "." << std::endl;
        }
    }
}


void SocialMediaPlatform::removeContent( const int contentCreatorId, const int contentId ){
    if(!contentCreators.exists(contentCreatorId)) {
        std::cout << "Cannot remove content. There is no content creator with ID " << contentCreatorId << "." << std::endl;
    } else {
        if(!getContentCreatorById(contentCreatorId).getContents().exists(contentId)) {
            std::cout << "Cannot remove content. There is no content with ID " << contentId << " shared by content creator with ID " << contentCreatorId << "." << std::endl;
        } else {
            deleteContentFromContentCreatorById(contentCreatorId, contentId);
            allContents.remove(contentId);
            std::cout << "Removed content " << contentId << "." << std::endl;
        }
    }
}

void SocialMediaPlatform::followContentCreator( const int regularUserId, const int contentCreatorId ){
    if(!regularUsers.exists(regularUserId) || !contentCreators.exists(contentCreatorId)) {
        std::cout << "Cannot follow. Regular user and/or content creator ID does not exist." << std::endl;
    } else {
        if(getContentCreatorById(contentCreatorId).getFollowers().exists(regularUserId)) {
            std::cout << "Cannot follow. The user is already following the content creator." << std::endl;
        } else {
            RegularUser newFollower(getRegularUserById(regularUserId).getId(), getRegularUserById(regularUserId).getName());
            addFollowerToContentCreatorById(contentCreatorId, newFollower);
            std::cout << "Regular user with ID " << regularUserId << " followed content creator with ID " << contentCreatorId << "." << std::endl;
        }
    }
}

void SocialMediaPlatform::unfollowContentCreator( const int regularUserId, const int contentCreatorId){
    if(!regularUsers.exists(regularUserId) || !contentCreators.exists(contentCreatorId)) {
        std::cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << std::endl;
    } else {
        if(!getContentCreatorById(contentCreatorId).getFollowers().exists(regularUserId)) {
            std::cout << "Cannot unfollow. The user is not following the content creator." << std::endl;
        } else {
            deleteFollowerFromContentCreatorById(contentCreatorId, regularUserId);
            std::cout << "Regular user with ID " << regularUserId << " unfollowed content creator with ID " << contentCreatorId << "." << std::endl;
        }
    }
}

void SocialMediaPlatform::showFollowersOf( const int contentCreatorId ) const{
    if(!contentCreators.exists(contentCreatorId)) {
        std::cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << std::endl;
    } else {
        std::cout << "Regular users following content creator with ID " << contentCreatorId << ":" << std::endl;
        ContentCreator creator = getContentCreatorById(contentCreatorId);
        LinkedSortedList<RegularUser> followersList = creator.getFollowers();
        // If there are no followers
        if (followersList.isEmpty()) {
            std::cout << "None" << std::endl;
        } else {
            Node<RegularUser>* current = followersList.getHead();
            while (current != nullptr) {
                RegularUser tempRegularUser = current->getItem();
                std::cout << tempRegularUser.getId() << std::endl;
                current = current->getNext();
            }
        }
    }
}

void SocialMediaPlatform::showContentsOf( const int contentCreatorId ) const{
    if(!contentCreators.exists(contentCreatorId)) {
        std::cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << std::endl;
    } else {
        std::cout << "Contents of content creator with ID " << contentCreatorId << ":" << std::endl;
        ContentCreator creator = getContentCreatorById(contentCreatorId);
        LinkedSortedList<Content> contentsList = creator.getContents();
        // If there are no contents
        if (contentsList.isEmpty()) {
            std::cout << "None" << std::endl;
        } else {
            Node<Content>* current = contentsList.getHead();
            while (current != nullptr) {
                Content tempContent = current->getItem();
                std::cout << tempContent.getId() << std::endl;
                current = current->getNext();
            }
        }
    }
}

void SocialMediaPlatform::showAllRegularUsers( ) const{
    std::cout << "Regular users in the social media platform:" << std::endl;

    if (regularUsers.isEmpty()) {
        std::cout << "None" << std::endl;
    } else {
        Node<RegularUser>* current = regularUsers.getHead();
        while (current != nullptr) {
            RegularUser tempUser = current->getItem();
            std::cout << tempUser.getId() << ", " << tempUser.getName() << std::endl;
            current = current->getNext();
        }
    }
}

void SocialMediaPlatform::showAllContentCreators( ) const{
    std::cout << "Content creators in the social media platform:" << std::endl;

    if (contentCreators.isEmpty()) {
        std::cout << "None" << std::endl;
    } else {
        Node<ContentCreator>* current = contentCreators.getHead();
        while (current != nullptr) {
            ContentCreator tempCreator = current->getItem();
            std::cout << tempCreator.getId() << ", " << tempCreator.getName() << ", "
                      << tempCreator.getFollowers().getLength() << " follower(s), "
                      << tempCreator.getContents().getLength() << " content(s)" << std::endl;
            current = current->getNext();
        }
    }
}

//Extra-Implemented Functions
ContentCreator SocialMediaPlatform::getContentCreatorById(int targetContentCreatorId) const {
    Node<ContentCreator>* current = contentCreators.getHead();

    while (current != nullptr) {
        if (current->getItem().getId() == targetContentCreatorId) {
            return current->getItem(); // Return a pointer to the found ContentCreator
        }
        current = current->getNext();
    }

    //This is to shut the compiler down
    return ContentCreator();
}

RegularUser SocialMediaPlatform::getRegularUserById(int targetRegularUserId) const {
    Node<RegularUser>* current = regularUsers.getHead();

    while (current != nullptr) {
        if (current->getItem().getId() == targetRegularUserId) {
            return current->getItem(); // Return a pointer to the found ContentCreator
        }
        current = current->getNext();
    }

    //This is to shut the compiler down
    return RegularUser();
}

void SocialMediaPlatform::addContentToContentCreatorById(int targetContentCreatorId, Content& contentToBeAdded) {
    Node<ContentCreator>* current = contentCreators.getHead();

    while (current != nullptr) {
        if (current->getItem().getId() == targetContentCreatorId) {
            current->getItem().addIndividualContent(contentToBeAdded); // Return a pointer to the found ContentCreator
        }
        current = current->getNext();
    }
}

void SocialMediaPlatform::deleteContentFromContentCreatorById(int targetContentCreatorId, int contentIdToBeDeleted) {
    Node<ContentCreator>* current = contentCreators.getHead();

    while (current != nullptr) {
        if (current->getItem().getId() == targetContentCreatorId) {
            current->getItem().removeIndividualContent(contentIdToBeDeleted); // Return a pointer to the found ContentCreator
        }
        current = current->getNext();
    }
}

void SocialMediaPlatform::addFollowerToContentCreatorById(int targetContentCreatorId, RegularUser& followerToBeAdded) {
    Node<ContentCreator>* current = contentCreators.getHead();

    while (current != nullptr) {
        if (current->getItem().getId() == targetContentCreatorId) {
            current->getItem().addIndividualFollower(followerToBeAdded); // Return a pointer to the found ContentCreator
        }
        current = current->getNext();
    }
}

void SocialMediaPlatform::deleteFollowerFromContentCreatorById(int targetContentCreatorId, int followerIdToBeDeleted) {
    Node<ContentCreator>* current = contentCreators.getHead();

    while (current != nullptr) {
        if (current->getItem().getId() == targetContentCreatorId) {
            current->getItem().removeIndividualFollower(followerIdToBeDeleted); // Return a pointer to the found ContentCreator
        }
        current = current->getNext();
    }
}
