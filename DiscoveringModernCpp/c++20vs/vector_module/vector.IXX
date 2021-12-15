export module vector

class vector 
{
  public:
    vector(int size) : my_size(size), data(new double[size]) {}

    vector() : my_size(0) {}

    vector(const vector& that) 
      : my_size(that.my_size), data(new double[my_size])
    {
    	for (int i=0; i<my_size; ++i) 
	    data[i] = that.data[i];
    }

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
    int                         my_size;
    std::unique_ptr<double[]>   data;
};

std::ostream& operator<<(std::ostream& os, const vector& v)
{
  os << '[';
  for (int i= 0; i < v.size(); ++i) os << v[i] << ',';
  os << ']';
  return os;
}
