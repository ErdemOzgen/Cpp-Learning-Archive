 class Vector {				// a 3-element vector
  public: // ... public members omitted
  private:
    double coord[3];				// storage for coordinates
    friend class Matrix;			// give Matrix access to coord
  };

  class Matrix { 				// a 3x3 matrix
  public:
    Vector multiply(const Vector& v);		// multiply by vector v
    // ... other public members omitted
  private:
    double a[3][3];				// matrix entries
  };

  Vector Matrix::multiply(const Vector& v) {	// multiply by vector v
    Vector w;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        w.coord[i] += a[i][j] * v.coord[j];	// access to coord allowed
    return w;
  }