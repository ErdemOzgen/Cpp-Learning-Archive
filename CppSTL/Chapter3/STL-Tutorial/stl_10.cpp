// 4.2.3 section - Bidirectional Iterators

#include <vector>
#include <list>
#include <iostream>

using namespace std;

template <class BidirectionalIterator, class Compare>

void bubble_sort (BidirectionalIterator first, BidirectionalIterator last, Compare comp){  
	BidirectionalIterator left_el = first, right_el = first;  
	right_el++;  
	
	while (first != last)  {    
		while (right_el != last) {      
			if (comp(*right_el, *left_el)) 
				iter_swap (left_el, right_el);      
			right_el++;      left_el++;    
		}    
		last--;    
		left_el = first, right_el = first;    
		right_el++;  
	}
}

int main ()
{
	list<int> l1 (1, 1);
	
	l1.push_back (2);  // list l: 1 2
	
	list<int>::iterator first = l1.begin();
	list<int>::iterator last  = l1.end();
	
	while (last != first) {  
		--last;  
		cout << *last << " ";
	}
	
	list<int> l2 (1, 1); // fill list
	
	l2.push_back (2);  // list l: 1 2
	
	bubble_sort (l2.begin(), l2.end(), less<int>() );   // sort ascendingly
	
	first = l2.begin();
	last  = l2.end();
	
	while (first != last) {  
		cout << *first++ << " ";
	}
	
	bubble_sort (l2.begin(), l2.end(), greater<int>() );// sort descendingly
	
	first = l2.begin();
	last  = l2.end();
	
	while (first != last) {  
		cout << *first++ << " ";
	}
}