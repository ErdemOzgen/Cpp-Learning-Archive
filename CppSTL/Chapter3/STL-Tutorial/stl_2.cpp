// 2.3 section - Templates

#include <iostream>
#include <ostream>
#include<string>

using namespace std;

class shape {
	private:
		int x_pos;
		int y_pos;
		int color;
	public:
		// Default constructor
		shape () : x_pos(0), y_pos(0), color(1) {}
		// Constructor with 3 parameters - one with default value (c)
		shape (int x, int y, int c = 1) : x_pos(x), y_pos(y), color(c) {}
		// Copy constructor
		shape (const shape& s) : x_pos(s.x_pos), y_pos(s.y_pos), color(s.color) {}
		// Destructor
		~shape () {}
		// Operator overloading
		shape& operator= (const shape& s) {
			x_pos = s.x_pos, y_pos = s.y_pos, color = s.color; return *this; 
		}
		// Getter x_pos
		int get_x_pos () { 
			return x_pos; 
		}
		// Getter y_pos
		int get_y_pos () { 
			return y_pos; 
		}
		// Getter color
		int get_color () { 
			return color; 
		}
		// Setter x_pos
		void set_x_pos (int x) { 
			x_pos = x; 
		}
		// Setter y_pos
		void set_y_pos (int y) { 
			y_pos = y; 
		}
		// Setter color
		void set_color (int c) { 
			color = c; 
		}
		// Virtual = function can be overwritten in a derived class 
		virtual void DrawShape () {}
		// Overload operator<< (friend means that we have access to private members of class)
		friend ostream& operator<< (ostream& os, const shape& s);
};

ostream& operator<< (ostream& os, const shape& s) {
	os << "shape: (" << s.x_pos << "," << s.y_pos << "," << s.color << ") \n";
	return os;
}

// Swap integers
void swap_elements(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

// Swap Templates or Parametrized types
template <class T> void swap_elements (T& a, T& b) {   
	T temp = a;   
	a = b;   
	b = temp;
}

// Function template examples
template <class T>T& min (T& a, T&b) { 
	return a < b ? a : b; 
}
template <class T>void print_to_cout (char* msg, T& obj) {   
	cout << msg << ": " << obj << endl;
}

int main(){	
	// Swap integers
	int a = 5, b = 6;
	cout<<"Before: a="<<a<<" b="<<b<<"\n";
	swap_elements(a, b);
	cout<<"After: a="<<a<<" b="<<b<<"\n";
	
	// Swap Templates or Parametrized types 
	shape shape1(1, 2, 3);
	shape shape2(4, 5, 6);
	cout<<"Before: shape1="<<shape1<<" shape2="<<shape2<<"\n";
	swap_elements(shape1, shape2);
	cout<<"After: shape1="<<shape1<<" shape2="<<shape2<<"\n";
	
	// Function template examples - we need < to be implemented
	// shape minimum = min(shape1, shape2);
	// cout<<"Min: "<<minimum<<"\n";
	int minimum = min(a, b);
	cout<<"Min: "<<minimum<<"\n";
	
	char *msg = "Shape object to print";
	print_to_cout(msg, shape1);
	return 0;
}	

