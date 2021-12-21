#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////
// P_3_1
typedef vector<int>		OneD;
typedef vector<OneD>	TwoD;
typedef vector<TwoD>	ThreeD;

OneD add1D (OneD A, OneD B) {
  assert(A.size() == B.size());
  OneD C;
  for (int i = 0; i < A.size(); i++) {
    C.push_back(A[i]+B[i]);
  }
  return C;
}

TwoD add2D (TwoD A, TwoD B) {
  assert(A.size() == B.size());
  TwoD C;
  OneD temp;
  for (int i = 0; i < A.size(); i++) {
    C.push_back(add1D(A[i], B[i]));
  }
  return C;
}

ThreeD add3D(ThreeD A, ThreeD B) {
  assert(A.size() == B.size());
  ThreeD C;
  for (int i = 0; i < A.size(); i++) {
    C.push_back(add2D(A[i], B[i]));
  }
  return C;
}

void print3D (ThreeD A, size_t x, size_t y, size_t z) {
  for (int i = 0; i < z; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < x; k++) {
	cout << A[i][j][k] << '\t';
      }
      cout << endl;
    }
    cout << endl;
  }
}

void P_3_1() {
  // Create 3D:
  OneD temp1D;
  TwoD temp2D;
  ThreeD A, B;
  for (int i = 0; i < 3; i++) {
    temp2D.clear();
    for (int j = 0; j < 3; j++) {
      temp1D.clear();
      for (int k = 0; k< 3; k++) {
	temp1D.push_back(i*9+j*3+k);
      }
      temp2D.push_back(temp1D);
    }
    A.push_back(temp2D);
  }
  for (int i = 0; i < 3; i++) {
    temp2D.clear();
    for (int j = 0; j < 3; j++) {
      temp1D.clear();
      for (int k = 0; k< 3; k++) {
	temp1D.push_back((i*9+j*3+k)*2);
      }
      temp2D.push_back(temp1D);
    }
    B.push_back(temp2D);
  }
  //////
  cout << "=== A ===\n";
  print3D(A,3,3,3);
  cout << "=== B ===\n";
  print3D(B,3,3,3);
  cout << "=== A + B ===\n";
  print3D(add3D(A,B), 3,3,3);
}

//////////////////////////////////////////////////////////
// P-3.2
class Matrix {
public:
  Matrix(size_t m = 0, size_t n = 0);
  void addRow(vector<int> V);
  void addRow(int A[]);
public:
  friend ostream& operator<<(ostream&, const Matrix);
  friend Matrix operator+(Matrix lhs, const Matrix& rhs);
  friend Matrix operator*(Matrix lhs, const Matrix& rhs);
private:
  size_t rows;
  size_t cols;
  vector< vector<int> > M;
};

Matrix::Matrix(size_t m, size_t n) {
  this->rows = m;
  this->cols = n;
  this->M = vector< vector<int> >(m, vector<int>(n));
}
void Matrix::addRow(vector<int> V) {
  if (rows > 0) {
    assert(V.size() == cols);
  } else {
    cols = V.size();
  }
  M.push_back(V);
  rows++;
}
void Matrix::addRow(int A[]) {
  if (rows > 0) {
    assert(sizeof(*A)/sizeof(A[0]) == cols);
  } else {
    cols = sizeof(*A)/sizeof(A[0]);
  }
  M.push_back(vector<int>(*A));
  rows++;
}
Matrix operator+(Matrix lhs, const Matrix& rhs) {
  assert (lhs.rows == rhs.rows && lhs.cols == rhs.cols);
  for (int i = 0; i < lhs.rows; i++) {
    for (int j = 0; j < lhs.cols; j++) {
      lhs.M[i][j] += rhs.M[i][j];
    }
  }
  return lhs;
}

Matrix operator*(Matrix lhs, const Matrix& rhs) {
  assert (lhs.rows == rhs.rows && lhs.cols == rhs.cols);
  for (int i = 0; i < lhs.rows; i++) {
    for (int j = 0; j < lhs.cols; j++) {
      lhs.M[i][j] *= rhs.M[i][j];
    }
  }
  return lhs;
}


ostream& operator<<(ostream& os, const Matrix M) {
  for (size_t i = 0; i < M.rows; i++) {
    for (size_t j = 0; j < M.cols; j++) {
      os << M.M[i][j] << '\t';
    }
    os << endl;
  }
  return os;
}

void P_3_2() {
  Matrix M0, M1;
  vector<int> V = {1, 2, 3};
  M0.addRow(V);
  M0.addRow({4,5,6});

  M1.addRow({1,1,2});
  M1.addRow({10,10,11});

  cout << "=== A ===\n" << M0 << endl;
  cout << "=== B ===\n" << M1 << endl;
  cout << "=== A+B ===\n" << M0+M1 << endl;
  cout << "=== A*B ===\n" << M0*M1 << endl;
}

//////////////////////////////////////////////////////////
// P-3.6
void addToSet(set<char> *A, string str) {
  for (int i = 0; i < str.length(); i++) {
    A->insert(str[i]);
  }
}

struct prob {
  prob(string x, string y, string z) : x(x), y(y), z(z) {
    A.clear();
    addToSet(&A, x);
    addToSet(&A, y);
    addToSet(&A, z);
  }
  prob() {
    x = "";
    y = "";
    z = "";
    A.clear();
  }
  // x+y = z
  string x;
  string y;
  string z;
  set<char> A;
};


size_t findPos(char c, const set<char> A) {
  size_t i = 0;
  for (set<char>::iterator it = A.begin(); it != A.end(); ++it) {
    if (*it == c) return i+1;
    else i++;
  }
  cout << "No char in A\n";
  return A.size();
}

int toNum(string str, set<char> A, vector<int> S) {
  int temp = 0;
  size_t it;
  for (int i = str.length()-1; i >= 0; i--) {
    it = findPos(str[i], A);
    //cout << str[i] << ' ' << S[it] << ' ' << it << endl;
    temp += S[it]*pow(10, str.length() - i - 1);
  }
  //cout << temp << endl;
  return temp;
}

bool problem(prob xyz, const vector<int> S) {
  if (toNum(xyz.x, xyz.A, S) + toNum(xyz.y, xyz.A, S) == toNum(xyz.z, xyz.A, S)) return true;
  else return false;
}

template <typename T>
void print (T ar) {	// Use with vector/set/queue
  for (typename T::iterator it = ar.begin(); it != ar.end(); ++it) {
    cout << *it << ' ';
  }
  cout << endl;
}

bool PuzzleSolve (prob xyz, int k, vector<int> *S, set<int> Uc) {
  for (set<int>::iterator it = Uc.begin(); it != Uc.end(); ++it) {
    set<int> U = Uc;	// local copy of the set -> otherwise erases
    int e = *it;
    S->push_back(e);
    U.erase(*it);
    // print<set<int> >(U);
    if (k == 0) {
      // cout << "Checking: ";
      // print<vector<int> >(*S);
      // Test if S solves the problem:
      if(problem(xyz, *S)) {
	cout << "\nSolution found:\n";
	// cout << '(' << toNum(xyz.x, xyz.A, *S) + toNum(xyz.y, xyz.A, *S) << ')' << endl;
	cout << "Set:\t"; print<vector<int> >(*S);
	cout << "Chars:\t"; cout << "  "; print<set<char> >(xyz.A);
	cout << "Solution:\n";
	cout << xyz.x << '+' << xyz.y << '=' << xyz.z << endl;
	cout 	<< toNum(xyz.x, xyz.A, *S) 
		<< '+' << toNum(xyz.y, xyz.A, *S) 
		<< '=' << toNum(xyz.z, xyz.A, *S)
		<< '(' << toNum(xyz.x, xyz.A, *S) + toNum(xyz.y, xyz.A, *S) << ')' << endl;
	return true;
      }
    } else {
      // This is odd but I don't want to return if the solution is NOT found
      if (PuzzleSolve(xyz, k-1, S, U)) return true;
    }
    // U.insert(e);
    // if (S->empty()) cout << "WOW" << endl;
    S->pop_back();
  }
  return false;
}

void P_3_6() {
  set<int> U = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  vector<int> S;
  prob xyz = {"pot", "pan", "bib"};
  PuzzleSolve(xyz, xyz.A.size(), &S, U);

  S.clear();
  xyz = {"dog", "cat", "pig"};
  PuzzleSolve(xyz, xyz.A.size(), &S, U);

  S.clear();
  xyz = {"boy", "girl", "baby"};
  PuzzleSolve(xyz, xyz.A.size(), &S, U);
}







/////////////////////////////////////////////////////////
int main() {
  srand(time(NULL));
  cout << "\n*****************P-3.1*****************\n";
  P_3_1();
  cout << "\n*****************P-3.2*****************\n";
  P_3_2();
  cout << "\n*****************P-3.6*****************\n";
  P_3_6();

}

