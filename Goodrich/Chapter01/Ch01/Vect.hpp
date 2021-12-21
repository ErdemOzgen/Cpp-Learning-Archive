
template <typename T>
class Vect {
public:
	Vect(int n);
	Vect();
	Vect(const Vect& a);
	~Vect();

	Vect<T>& operator=(const Vect<T>& a);
	void print();

private:
	T*	data;
	int 	size;
};

// Constructor of n:
template <typename T>
Vect<T>::Vect(int n) {
	this->size	= n;
	this->data	= new T[n];
}
// Empty constructor:
template <typename T>
Vect<T>::Vect() {
	this->size	= 10;
	this->data	= new T[10];
}
// Copy constructor:
template <typename T>
Vect<T>::Vect(const Vect& a) {
	this->size 	= a.size;
	this->data 	= new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->data[i] = a.data[i];
	}
}
// Destructor:
template <typename T>
Vect<T>::~Vect() {
	delete [] data;
}

// Assignmenet operator:
template <typename T>
Vect<T>& Vect<T>::operator=(const Vect<T>& a) {
	if (this != &a) {
		delete [] data;
		this->size = a.size;
		this->data = new T[this->size];
		for (int i = 0; i < size; i++) {
			this->data[i] = a.data[i];
		}
	}
	return *this;
}

template <typename T>
void Vect<T>::print() {
	for (int i = 0; i < this->size; i++) {
		cout << this->data[i] << ' ';
	}
	cout << endl;
}

