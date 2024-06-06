//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#ifndef HW3_SOCIALMEDIAPLATFORM_H
#define HW3_SOCIALMEDIAPLATFORM_H
#include <iostream>
#include <string>

#include "ContentCreator.h"

class SocialMediaPlatform {
    public:
        SocialMediaPlatform();
        ~SocialMediaPlatform();
        void addRegularUser( const int regularUserId, const string name );
        void removeRegularUser( const int regularUserId );
        void addContentCreator( const int contentCreatorId, const string name );
        void removeContentCreator( const int contentCreatorId );
        void addContent( const int contentCreatorId, const int contentId, const string title );
        void removeContent( const int contentCreatorId, const int contentId );
        void followContentCreator( const int regularUserId, const int contentCreatorId );
        void unfollowContentCreator( const int regularUserId, const int contentCreatorId);
        void showFollowersOf( const int contentCreatorId ) const;
        void showContentsOf( const int contentCreatorId ) const;
        void showAllRegularUsers( ) const;
        void showAllContentCreators( ) const;

        //Extra-Implemented Functions
        ContentCreator getContentCreatorById(int targetContentCreatorId) const;
        RegularUser getRegularUserById(int targetRegularUserId) const;
        void addContentToContentCreatorById(int targetContentCreatorId, Content& contentToBeAdded);
        void deleteContentFromContentCreatorById(int targetContentCreatorId, int contentIdToBeDeleted);
        void addFollowerToContentCreatorById(int targetContentCreatorId, RegularUser& followerToBeAdded);
        void deleteFollowerFromContentCreatorById(int targetContentCreatorId, int followerIdToBeDeleted);


    private:
        LinkedSortedList<RegularUser> regularUsers;
        LinkedSortedList<ContentCreator> contentCreators;
        LinkedSortedList<Content> allContents;
};

#endif //HW3_SOCIALMEDIAPLATFORM_H
