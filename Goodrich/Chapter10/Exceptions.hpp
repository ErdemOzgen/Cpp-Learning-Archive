#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <exception>
#include <string>

class NonexistentElement : public std::runtime_error {
public:
  NonexistentElement(const std::string err = "Element doesn't exist!")
	: runtime_error(err) {}
};

class BoundaryViolation : public std::runtime_error {
public:
  BoundaryViolation(const std::string err = "Out of bounds!")
	: runtime_error(err) {}
};


#endif
