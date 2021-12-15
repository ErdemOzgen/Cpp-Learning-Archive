#include <cassert>
#include <iostream>

class vector 
{
  public:
    vector(int size) : my_size(size), data(new double[size]) {}

    vector() : my_size(0), data(0) {}

    ~vector() { delete[] data; }

    // What the compiler would generate:
    // A new vector pointing to the same data!
    // vector(const vector& that)
    //   : my_size(that.my_size), data(that.data) {}

    // We have to write the copy constructor and actually copy
    vector(const vector& that) 
      : my_size(that.my_size), data(new double[my_size])
    {
    	for (int i=0; i<my_size; ++i)
	    data[i] = that.data[i]; 
    }

    // What the compiler would generate:
    // The target vector now points to the same data as that
    // Memory of *this not released
    // void operator=(const vector& that)
    // {
    // 	my_size= that.my_size;
    // 	data= that.data;
    // }
    
    void operator=(const vector& that) 
    {
    	assert(that.my_size == my_size);
    	for (int i=0; i<my_size; ++i) 
    	    data[i] = that.data[i];
    }

    int size() const { return my_size; }
    int size() { return my_size; }

    double& operator[](int i) const {
	assert(i>=0 && i<my_size);
	return data[i];
    }

    double& operator[](int i) {
	assert(i>=0 && i<my_size);
	return data[i];

    }

    vector operator+(const vector& that) const {
	assert(that.my_size == my_size);
	vector sum(my_size);
	for (int i= 0; i < my_size; ++i)
	    sum[i] = (*this)[i] + that[i]; 
	return sum;
    }

  private:
    int     my_size;
    double* data;
};

std::ostream& operator<<(std::ostream& os, const vector& v)
{
  os << '[';
  if (v.size() > 0)
      os << v[0];
  for (int i= 1; i < v.size(); ++i) 
      os << ", " << v[i];
  return os << ']';
}

double dot(const vector& v, const vector& w) 
{
    double s= 0.0;
    for (int i= 0; i < v.size(); i++)
	s+= v[i] * w[i];
    return s;
}

int main()
{
    vector v1(4);
    v1[0] = v1[1] = 1.0; v1[2] = 2.0; v1[3] = -3.0;
    std::cout << v1 << std::endl;

    vector w(v1.size());
    w= v1;

    const vector v2(v1);
    std::cout << "v2[3] is " << v2[3] << '\n';

    v1[3]= 3.14;
    std::cout << "v2[3] is " << v2[3] << '\n';

    std::cout << "w is " << w << '\n';
    v1[1]= 9.;
    std::cout << "w is " << w << '\n';

    vector sum(w + v1);

    return 0;
}
