#include <iostream>
#include "CLinkedList.hpp"

int main() {
  CLinkedList <std::string> playList;
  std::cout << playList << std::endl;
  playList.add("Staying Alive");
  std::cout << playList << std::endl;
  playList.add("Le Freak");
  std::cout << playList << std::endl;
  playList.add("Jive Talking");
  std::cout << playList << std::endl;
  playList.advance();
  std::cout << playList << std::endl;
  playList.remove();
  std::cout << playList << std::endl;
  playList.advance();
  playList.remove();
  std::cout << playList << std::endl;
}
