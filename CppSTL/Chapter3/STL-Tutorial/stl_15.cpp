// Iterator Adaptors
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
	using namespace std;
	int i;

	vector<int> vec;
	for ( i = 1 ; i < 6 ; ++i )
	{
		vec.push_back ( 3 * i );
	}

	vector <int>::iterator vIter;

	cout << "The vector vec is: ( ";
	for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
		cout << *vIter << " ";
	cout << ")." << endl;

	vector <int>::reverse_iterator rvIter;
	cout << "The vector vec reversed is: ( ";
	for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
		cout << *rvIter << " ";
	cout << ")." << endl;

	// Initializing reverse_iterators to the first element
	vector <int>::reverse_iterator rVPOS1 = vec.rend ( ) - 1;

	cout << "The iterator rVPOS1 initially points to the last "<< "element\n in the reversed sequence: "<< *rVPOS1 << "." << endl;

	vector <int>::reverse_iterator rVPOS2 =rVPOS1 - 2; 
	cout << "After the -2 offset, the iterator rVPOS2 points\n"<< " to the 2nd element from the last in the reversed sequence: "<< *rVPOS2 << "." << endl;
}