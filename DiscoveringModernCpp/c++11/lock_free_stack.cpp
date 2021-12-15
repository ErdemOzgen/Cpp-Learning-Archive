#include <iostream>
#include <atomic>

namespace dmc {

    // Implemented as list
    class lock_free_stack 
    {
	struct node { double data; node* next; };
      public:

	void push(double d) 
	{
	    node* new_node = new node;
	    new_node->data= d;
	    new_node->next= head.load();
	    // head= new_node;
	    while(! head.compare_exchange_weak(new_node->next, new_node));
#if 0
	    bool stored= false;
	    while(not stored) {
		if (head == new_node->next) {
		    head= new_node;
		    stored= true;
		} else {
		    new_node->next= head;
		    stored= false;
		}
	    }
#endif
	}
	std::atomic<node*> head;	
    };

}


int main (int argc, char* argv[]) 
{
    using namespace std;
    using namespace dmc;


    return 0;
}

