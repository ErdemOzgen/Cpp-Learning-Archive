#ifndef RUNTIME_EXCEPTIONS_HPP
#define RUNTIME_EXCEPTIONS_HPP

#include <string>

/****************************************************************
 * Exceptions
 ****************************************************************/
class RuntimeException {
private:
  std::string errorMsg;
public:
  RuntimeException(const std::string& err) { errorMsg = err; }
  std::string getMessage() const { return errorMsg; }
};

class IndexOutOfBounds : public RuntimeException {
public:
  IndexOutOfBounds(const std::string& err = "Index out of bounds!")
    : RuntimeException(err) {}
};

class StackEmpty : public RuntimeException {
public:
  StackEmpty(const std::string& err = "Stack is empty!")
    : RuntimeException(err) {}
};

class StackFull : public RuntimeException {
public:
  StackFull(const std::string& err = "Stack is full!")
    : RuntimeException(err) {}
};

class QueueEmpty : public RuntimeException {
public:
  QueueEmpty(const std::string& err = "Queue is empty!")
    : RuntimeException(err) {}
};

class QueueFull : public RuntimeException {
public:
  QueueFull(const std::string& err = "Queue is full!")
    : RuntimeException(err) {}
};

class DequeEmpty : public RuntimeException {
public:
  DequeEmpty(const std::string& err = "Deque is empty!")
    : RuntimeException(err) {}
};

class DequeFull : public RuntimeException {
public:
  DequeFull(const std::string& err = "Deque is full!")
    : RuntimeException(err) {}
};

#endif
