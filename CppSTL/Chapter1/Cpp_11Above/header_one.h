#ifndef HEADER_ONE_H
#define HEADER_ONE_H

#include <iostream>
#include <thread>

class ThreadingClass {
public:
    // Calculate the sum S(0...n) recursively
    int rec_sum(int num) {
        if(num<0)
            return -1;
        if(num==0 || num==1)
            return num;
        return num + rec_sum(num-1);        
    }
    // Simple recursive factorial function
    int rec_fact(int num) {
        if(num<0)
            return -1;
        if(num==0 || num==1)
            return 1;
        return num*rec_fact(num-1);
    }
    // Simple void factorial function to call the recursive factorial function !
    void fact(int num) {
        std::cout << "From Thread ID : "<< std::this_thread::get_id() << "\n";
        std::cout << num << "! = " << rec_fact(num) << std::endl;
    }
};

#endif /* HEADER_ONE */