/*
 * =============================================================================
 *
 *       Filename:  custmemory.hpp
 *
 *    Description:  Exercise 21.30 - Write Your Own Memory Handling Functions
 *
 *        Version:  1.0
 *        Created:  19/03/18 12:47:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =============================================================================
 */
#pragma once

/**
 * Copies n characters from s2 into the object pointed to by s1.
 * Returns a pointer to the resulting object.
 * Source and destination addresses cannot overlap.
 *
 * @param void*
 * @param const void*
 * @param size_t
 * @return void*
 */
void* memcpy(void* s1, const void* s2, size_t n) {
    // cast addresses to char* (allows pointer arithmetic)
    char* cs1 = (char*)s1;
    const char* cs2 = (char*)s2;

    for (unsigned int i = 0; i < n; ++i) { cs1[i] = cs2[i]; }

    return (void*)s1;
}  // end method memcpy

/**
 * Copies n characters from s2 into the object pointed to by s1.
 * The copy is performed as though the chars were first copied from s2 into a
 * temp array, then from the temp array into s1.
 * Returns a pointer to the resulting object.
 *
 * @param void*
 * @param const void*
 * @param size_t
 * @return void*
 */
void* memmove(void* s1, const void* s2, size_t n) {
    // cast addresses to char* (allows pointer arithmetic)
    char* cs1 = (char*)s1;
    const char* cs2 = (char*)s2;

    // temp array
    char* temp = new char[n];

    for (unsigned int i = 0; i < n; ++i) {
        temp[i] = cs2[i];
        cs1[i] = temp[i];
    }

    delete temp;

    return (void*)s1;
}  // end method memmove

/**
 * Compares the first n chars of the objects pointed to by s1 and s2.
 * Returns 0, less than 0, or greater than 0 if s1 is equal to, less than, or
 * greater than s2, respectively.
 *
 * @param void*
 * @param void*
 * @param size_t
 * @return int
 */
int memcmp(const void* s1, const void* s2, size_t n) {
    // cast addresses to char* (allows pointer arithmetic)
    char* cs1 = (char*)s1;
    const char* cs2 = (char*)s2;

    if (n != 0) {
        while (--n != 0) {
            if (*cs1++ != *cs2++) { return *--cs1 - *--cs2; }
        }
    }

    return 0;
}  // end method memcmp

/**
 * Locates the first occurance of c in the first n chars of s.
 * A pointer to c in s is returned if found. 0 otherwise.
 *
 * @param const void*
 * @param int
 * @param size_t
 * @return void*
 */
void* memchr(const void* s, int c, size_t n) {
    // cast address to char*
    const char* cs = (char*)s;

    if (n != 0) {
        while (--n != 0) {
            if (*cs++ == c) { return (void*)(--cs); } // decrement return value
        }
    }

    return nullptr;
}  // end method void* memchr

/**
 * Copies c into the first n chars of the object pointed to by s.
 * A pointer to result is returned.
 *
 * @param void*
 * @param int
 * @param size_t
 * @return void*
 */
void* memset(void* s, int c, size_t n) {
    // cast address to char*
    char* cs = (char*)s;

    if (n != 0) {
        while (--n != 0) {
            *cs++ = c;
        }

        return (void*)cs;
    }

    return nullptr;
}  // end method memset
