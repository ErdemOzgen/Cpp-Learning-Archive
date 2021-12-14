// 2.1 section - Classes

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

int main(){
	// Call default constructor
	shape shape1;
	cout<<shape1;
	
	// Call constructor with parameters
	shape shape2(1, 2, 3);
	cout<<shape2;
	
	// Call constructor with shape object parameter - copy constructor
	shape shape3(shape2);
	cout<<shape3;
	
	// Copy operator
	shape shape4 = shape2;
	cout<<shape4;
	
	return 0;
}	

