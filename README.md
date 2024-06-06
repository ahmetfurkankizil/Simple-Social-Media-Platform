# Simple Social Media Platform

## Overview

This project implements a simple social media platform that allows users to sign up as either regular users or content creators. The platform supports various functionalities such as adding and removing users, following and unfollowing content creators, and managing content. All user and content data is managed using sorted linked lists.

## Implementation Details

### Data Structures

The platform uses sorted linked lists to manage:
- Regular users
- Content creators
- Contents

### Classes and Functions

#### SocialMediaPlatform Class

The main class of the project is `SocialMediaPlatform`, which provides the following functionalities:

- `SocialMediaPlatform()`: Constructor to initialize the platform.
- `~SocialMediaPlatform()`: Destructor to clean up the platform.
- `void addRegularUser(const int regularUserId, const std::string name)`: Adds a new regular user.
- `void removeRegularUser(const int regularUserId)`: Removes a regular user.
- `void addContentCreator(const int contentCreatorId, const std::string name)`: Adds a new content creator.
- `void removeContentCreator(const int contentCreatorId)`: Removes a content creator.
- `void addContent(const int contentCreatorId, const int contentId, const std::string title)`: Adds a new content.
- `void removeContent(const int contentCreatorId, const int contentId)`: Removes a content.
- `void followContentCreator(const int regularUserId, const int contentCreatorId)`: Allows a regular user to follow a content creator.
- `void unfollowContentCreator(const int regularUserId, const int contentCreatorId)`: Allows a regular user to unfollow a content creator.
- `void showFollowersOf(const int contentCreatorId) const`: Shows the list of followers of a content creator.
- `void showContentsOf(const int contentCreatorId) const`: Shows the list of contents of a content creator.
- `void showAllRegularUsers() const`: Shows the list of all regular users.
- `void showAllContentCreators() const`: Shows the list of all content creators.

### Example Usage

Here's an example of how to use the `SocialMediaPlatform` class:

```cpp
#include <iostream>
#include "SocialMediaPlatform.h"

int main() {
    SocialMediaPlatform SMP;

    // Show all regular users and content creators
    SMP.showAllRegularUsers();
    std::cout << std::endl;
    SMP.showAllContentCreators();
    std::cout << std::endl;

    // Add content creators
    SMP.addContentCreator(3, "Lonely Artist");
    SMP.addContentCreator(2, "Eater Man");
    SMP.addContentCreator(4, "Pet Lover");
    SMP.removeContentCreator(4);
    SMP.addContentCreator(4, "Musician Guy");
    SMP.addContentCreator(1, "Gamer");
    SMP.addContentCreator(6, "News");

    // Add contents
    SMP.addContent(3, 1, "How to perform art?");
    SMP.addContent(4, 2, "My favourite song");
    SMP.addContent(2, 2, "Best Recipe Ever");
    SMP.addContent(6, 5, "News of October");
    SMP.addContent(6, 6, "News of November");
    SMP.addContent(6, 8, "News of December");
    SMP.addContent(6, 13, "News of 2023");
    SMP.removeContent(6, 5);

    // Show all content creators
    SMP.showAllContentCreators();
    std::cout << std::endl;

    // Add regular users
    SMP.addRegularUser(1, "Alper");
    SMP.addRegularUser(5, "Ali");
    SMP.addRegularUser(4, "Merve");
    SMP.addRegularUser(2, "Ferit");
    SMP.addRegularUser(6, "Ayse");
    SMP.removeRegularUser(2);

    // Follow content creators
    SMP.followContentCreator(1, 6);
    SMP.followContentCreator(1, 2);
    SMP.followContentCreator(1, 1);
    SMP.followContentCreator(4, 4);
    SMP.followContentCreator(4, 3);
    SMP.followContentCreator(6, 4);
    SMP.followContentCreator(6, 6);
    SMP.followContentCreator(6, 3);
    SMP.followContentCreator(5, 3);
    SMP.followContentCreator(5, 1);

    // Unfollow content creators
    SMP.unfollowContentCreator(6, 4);
    std::cout << std::endl;

    // Remove users and content creators
    SMP.removeRegularUser(5);
    SMP.removeContentCreator(3);

    // Show all content creators and regular users
    SMP.showAllContentCreators();
    std::cout << std::endl;
    SMP.showAllRegularUsers();
    std::cout << std::endl;

    // Show followers and contents of a content creator
    SMP.showFollowersOf(6);
    std::cout << std::endl;
    SMP.showContentsOf(6);
    std::cout << std::endl;

    return 0;
}
```

### Example Output

```
Regular users in the social media platform:
None
Content creators in the social media platform:
None
Added content creator 3.
Added content creator 2.
Added content creator 4.
Removed content creator 4.
Added content creator 4.
Added content creator 1.
Added content creator 6.
Added content 1.
Added content 2.
Added content 5.
Added content 6.
Added content 8.
Added content 13.
Removed content 5.
Content creators in the social media platform:
1, 0 follower(s), 0 content(s)
2, 0 follower(s), 0 content(s)
3, 0 follower(s), 1 content(s)
4, 0 follower(s), 1 content(s)
6, 0 follower(s), 3 content(s)
Added regular user 1.
Added regular user 5.
Added regular user 4.
Added regular user 2.
Added regular user 6.
Removed regular user 2.
Regular user with ID 1 followed content creator with ID 6.
Regular user with ID 1 followed content creator with ID 2.
Regular user with ID 1 followed content creator with ID 1.
Regular user with ID 4 followed content creator with ID 4.
Regular user with ID 4 followed content creator with ID 3.
Regular user with ID 6 followed content creator with ID 4.
Regular user with ID 6 followed content creator with ID 6.
Regular user with ID 6 followed content creator with ID 3.
Regular user with ID 5 followed content creator with ID 3.
Regular user with ID 5 followed content creator with ID 1.
Regular user with ID 6 unfollowed content creator with ID 4.
Removed regular user 5.
Removed content creator 3.
Content creators in the social media platform:
1, 1 follower(s), 0 content(s)
2, 1 follower(s), 0 content(s)
4, 1 follower(s), 1 content(s)
6, 2 follower(s), 3 content(s)
Regular users in the social media platform:
1, Alper
4, Merve
6, Ayse
Regular users following content creator with ID 6:
1
6
Contents of content creator with ID 6:
6
8
13
```

## Contact

For any questions or issues, please contact the project maintainer at furkan.kizil@ug.bilkent.edu.tr
