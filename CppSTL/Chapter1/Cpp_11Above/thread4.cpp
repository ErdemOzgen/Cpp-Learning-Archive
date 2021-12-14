#include <iostream>
#include <vector>
#include <thread>

#include "header_one.h"

using namespace std;

void helper(int num)
{
  ThreadingClass diman;
  cout << num << "! = " << diman.rec_fact(num) << endl;
}

void detacher(int num)
{
  cout << "\nStarting detacher function ...\n";

  thread dimanThread(helper, num);

  /*  Uncomment and watch how threads are mixed
  if(num%2==0)
    dimanThread.detach();
  else
    if(dimanThread.joinable())
      dimanThread.join();
  */

  // For now lets detach every one & also wait 0.2 seconds for every operation in order to be completed
  dimanThread.detach();
  this_thread::sleep_for(std::chrono::milliseconds(100));

  cout << "Exiting function detacher ...\n";
}

int main()
{
  for(auto i=1; i<11; i++)
    detacher(i);

  return 0;
}
