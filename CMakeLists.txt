cmake_minimum_required(VERSION 3.26)
project(HW3_Ahmet_Furkan_KIZIL_22203112)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW3_Ahmet_Furkan_KIZIL_22203112
        Content.cpp
        Content.h
        ContentCreator.cpp
        ContentCreator.h
        LinkedSortedList.cpp
        LinkedSortedList.h
        RegularUser.cpp
        RegularUser.h
        SocialMediaPlatform.cpp
        SocialMediaPlatform.h
        Main.cpp)
