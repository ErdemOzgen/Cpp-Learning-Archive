/*
 * =============================================================================
 *
 *       Filename:  custchar.hpp
 *
 *    Description:  Exercise 21.27 - Write Your Own Character Handling Functions.
 *
 *        Version:  1.0
 *        Created:  16/03/18 11:36:56
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
 * Check if given char is digit [0-9].
 * @param int
 * @return int
 */
int isdigit(int c) {
    return ((c >= 48 && c <= 57) ? 1 : 0);
}  // end method isdigit

/**
 * Checks whether given char is letter [a-z][A-Z];
 * @param int
 * @return int
 */
int isalpha(int c) {
    return (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ? 1 : 0);
}  // end method isalpha

/**
 * Checks whether given char is digit [0-9] or letter [a-z][A-Z]
 * @param int
 * @return int
 */
int isalnum(int c) {
    return ((isdigit(c) || isalpha(c)) ? 1 : 0);
}  // end method isalnum

/**
 * Checks whether given char is hexadecimal digit [0-9][a-f][A-F]
 * @param int
 * @return int
 */
int isxdigit(int c) {
    return ((isdigit(c) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102)) ? 1 : 0);
}  // end method isxdigit

/**
 * Checks whether the given char is lowercase letter [a-z]
 * @param int
 * @return int
 */
int islower(int c) {
    return ((c >= 97 && c <= 122) ? 1 : 0);
}  // end method islower

/**
 * Checks whether given char is uppercase letter [A-Z]
 * @param int
 * @return int
 */
int isupper(int c) {
    return ((c >= 65 && c <= 90) ? 1 : 0);
}  // end method isupper

/**
 * Returns given char as lowercase letter if is uppercase.
 * @param int
 * @return int
 */
int tolower(int c) {
    return ((isupper(c)) ? (c + 32) : c);
}  // end method tolower

/**
 * Returns given char as uppercase letter if is lowercase.
 * @param int
 * @return int
 */
int toupper(int c) {
    return ((islower(c)) ? (c - 32) : c);
}  // end method toupper

/**
 * Checks if given char is a white-space character - newline('\n'), space(' '),
 * form feed('\f'), carriage return('\r'), horizontal tab('\t') or vertical tab('\v')
 * @param int
 * @return int
 */
int isspace(int c) {
    return (((c >= 9 && c <= 13) || (c == 32)) ? 1 : 0);
}  // end method isspace

/**
 * Checks if given char is a control character - newline('\n'), form feed('\f'),
 * carriage return('\r'), horizontal tab('\t'), vertical tab('\v'), alert('\a'),
 * or backspace('\b')
 * @param int
 * @return int
 */
int iscntrl(int c) {
    return ((c >= 7 && c <= 13) ? 1 : 0);
}  // end method iscntrl

/**
 * Checks if given char is a printing characters other than a space, a digit,
 * or a letter.
 * @param int
 * @return int
 */
int ispunct(int c) {
    return (((c >= 33 && c <= 47) ||
             (c >= 58 && c <= 64) ||
             (c >= 91 && c <= 96) ||
             (c >= 123 && c <= 126)) ? 1 : 0);
}  // end method ispunct

/**
 * Checks if given char is a printing char including space(' ').
 * @param int
 * @return int
 */
int isprint(int c) {
    return ((isalnum(c) || ispunct(c) || isspace(c)) ? 1 : 0);
}  // end method isprint

/**
 * Checks if given char is a printing character other than space.
 * @param int
 * @return int
 */
int isgraph(int c) {
    return ((isalnum(c) || ispunct(c)) ? 1 : 0);
}  // end method isgraph
