#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef priority_queue<int, vector<int>, std::greater<int> > Tower;

void drawTabs (int a) {
	for (int i = 0; i < a; i++) {
		cout << ' ';
	}
}

void drawPeg(Tower *a, int level, int elemNum) {
	int size = a->size();
	int tabs;
	if (a->empty() || (size + level < elemNum)) { // If the tower is too small
		// cout << '-';
		tabs = elemNum + 1;
	} else {
		for (int i = 0; i <= a->top(); i++) {	// Show the peg
			cout << '*';
		}
		tabs = elemNum - a->top() + 1;
		a->pop();
	}
	drawTabs(tabs);
}

void drawTowers(Tower A, Tower B, Tower C, int elemNum) {
	// system("clear");
	// Vectors are sorted, and only the smallest could be pop'd
	for (int i = 0; i < elemNum; i++) {
		drawPeg(&A, i, elemNum);
		drawPeg(&B, i, elemNum);
		drawPeg(&C, i, elemNum);
		cout << endl;
	}
}

void moveTower(int elemNum, Tower *Source, Tower *Destination, Tower *Spare) {
	// elemNum is the largest in the Source
	if (elemNum == 0) {
		Destination->push(Source->top());
		Source->pop();
	} else {
		moveTower(elemNum - 1, Source, Spare, Destination);
		Destination->push(Source->top());
		Source->pop();
		moveTower(elemNum - 1, Spare, Destination, Source);
	}
	
}

int main() {
	int elemNum;
	cout << "What is the size of the tower: ";
	cin >> elemNum;
	Tower A, B, C;
	for (int i = 0; i < elemNum; i++) {
		A.push(i);
	}
	drawTowers(A, B, C, elemNum);
	moveTower(elemNum-1, &A, &B, &C);
	drawTowers(A, B, C, elemNum);

}