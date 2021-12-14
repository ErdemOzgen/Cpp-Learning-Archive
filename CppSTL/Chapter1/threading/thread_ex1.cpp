#include <iostream>
#include <vector>
#include <thread>
#include <pthread.h>

#define MAX 20

template<class T>
void echo(const std::vector<T> vecOfAnything) {
    char threadName[MAX];
    auto threadID = std::this_thread::get_id();
    // Fetch the thread name
    pthread_getname_np(pthread_self(), &threadName[0], sizeof(threadName));
    // Print it out
    std::cout << "\nThe function runs on thread : " << threadName << std::endl;
    std::cout << "Thread ID: " << threadID << std::endl;
    for(const auto& anything: vecOfAnything)
        std::cout << anything << " ";
    std::cout << std::endl;
}

int main()
{
  // Main thread name & ID
  char mainThreadName[MAX];
  // Set threadName from thread_ex1to --> main thread
  pthread_setname_np(pthread_self(), "main thread");
  pthread_getname_np(pthread_self(), &mainThreadName[0], sizeof(mainThreadName));
  std::cout << "Main function thread : " << mainThreadName << std::endl;
  std::cout << "Main function   ID   : " << std::this_thread::get_id() << std::endl;

  // Declare and Use a vector for the two threads to join them together in the end
  std::vector<std::thread> vecOfThreads(2);

  std::vector<std::string> names{"Giovanni", "Rivaldo", "Karembue", "Ze Elias", "Zetterberg"};
  vecOfThreads.push_back(std::thread(echo<std::string>, names));

  std::vector<int> ints{1 ,2 ,3 ,4 , 5};
  vecOfThreads.push_back(std::thread(echo<int>, ints));

  for(auto& thread : vecOfThreads)
    if(thread.joinable())
      thread.join();

  return 0;
}

/*  Compile in terminal >> g++ thread_ex1.cpp -lpthread -o thread_ex1 

SAMPLE OUTPUT

Main function thread : main thread
Main function   ID   : 140316032526144

The function runs on thread : main thread
Thread ID: 140316014352128
Giovanni Rivaldo Karembue Ze Elias Zetterberg

The function runs on thread : main thread
Thread ID: 140316005959424
1 2 3 4 5

*/
