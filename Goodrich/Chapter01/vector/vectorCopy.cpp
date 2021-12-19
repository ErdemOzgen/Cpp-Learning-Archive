Vect::Vect(const Vect& a) {			// copy constructor from a
    size = a.size;				// copy sizes
    data = new int[size];			// allocate new array
    for (int i = 0; i < size; i++) {		// copy the vector contents
      data[i] = a.data[i];
    }
  }