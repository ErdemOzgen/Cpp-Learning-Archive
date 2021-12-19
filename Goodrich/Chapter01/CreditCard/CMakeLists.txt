cmake_minimum_required(VERSION 3.22)
project(CreditCard)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CreditCard
        CredirCardTest.cpp
        CreditCard.cpp
        CreditCard.h)
