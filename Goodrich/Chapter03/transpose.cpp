#include <iostream>
#include <vector>

using namespace std;

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void transpose(vector< vector<int> > *M, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			swap((*M)[i][j], (*M)[j][i]);
		}
	}
}

void printM(vector< vector<int> >M) {
	for (vector< vector<int> >::iterator i = M.begin(); i != M.end(); ++i) {
		for (vector<int>::iterator j = i->begin(); j != i->end(); ++j) {
			cout << *j << ' ';
		}
		cout << endl;
	}
}

int main() {
	vector<int> A = {1, 2, 3, 1};
	vector<int> B = {4, 5, 6, 2};
	vector<int> C = {7, 8, 9, 3};
	vector<int> D = {7, 6, 5, 4};
	vector< vector<int> >M;
	M.push_back(A);
	M.push_back(B);
	M.push_back(C);
	M.push_back(D);
	printM(M); cout << endl;
	transpose(&M, 4);
	printM(M);
}