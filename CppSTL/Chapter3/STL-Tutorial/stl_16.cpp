// Iterator Adaptors
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main( )
{
	using namespace std;
	int i;

	vector<int> vec;
	for ( i = 1 ; i < 6 ; ++i )
	{
		vec.push_back ( i );
	}

	vector <int>::iterator vIter;
	cout << "The vector vec is: ( ";
	for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
		cout << *vIter << " ";
	cout << ")." << endl;

	vector <int>::reverse_iterator rvIter;
	cout << "The vector vec reversed is: ( ";
	for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
		cout << *rvIter << " ";
	cout << ")." << endl;

	vector <int>::iterator pos;
	pos = find ( vec.begin ( ), vec.end ( ), 4 );
	cout << "The iterator pos = " << *pos << "." << endl;

	vector <int>::reverse_iterator rpos ( pos );
	cout << "The reverse_iterator rpos = " << *rpos<< "." << endl;
}