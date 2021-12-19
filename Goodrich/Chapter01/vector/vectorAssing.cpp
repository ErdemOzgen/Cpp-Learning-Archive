Vect& Vect::operator=(const Vect& a) {	// assignment operator from a
    if (this != &a) {				// avoid self-assignment
      delete [] data;				// delete old array
      size = a.size;				// set new size
      data = new int[size];			// allocate new array
      for (int i=0; i < size; i++) {		// copy the vector contents
        data[i] = a.data[i];
      }
    }
    return *this;
  }