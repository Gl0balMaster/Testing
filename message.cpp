#include <iostream>
#include <vector>

template <size_t N, size_t M, typename T = int64_t>
class Matrix {
public:
  Matrix(T num) {
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        matrix[i].push_back(num);
      }
    }
  }

  Matrix() {
    T temp = 0;
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      matrix[i].resize(width);
      for (size_t j = 0; j < width; j++)
      {
        matrix[i][j] = temp;
      }
      
    }
  }

  Matrix(std::vector<std::vector<T>> vector) {
    matrix.resize(vector.size());
    for (size_t i = 0; i < vector.size(); i++) {
      matrix[i].resize(vector[i].size());
      for (size_t j = 0; j < vector[i].size(); j++) {
        matrix[i][j] = vector[i][j];
      }
    }
  }
  template <size_t V, size_t B>
  Matrix<N,M,T>(Matrix<V, B, T> other) {
    height = V;
    width = B;
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
        matrix[i].resize(width);
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] = other(i,j);
      }
    }
  }

  T& operator()(size_t stroka, size_t stolb) { return matrix[stroka][stolb]; }

  T operator()(size_t stroka, size_t stolb) const {
    return matrix[stroka][stolb];
  }

  Matrix Transposed() {
    size_t copy = width;
    std::vector<std::vector<T>> result;
    result.resize(width);
    for (size_t i = 0; i < width; i++) {
      for (size_t j = 0; j < height; j++) {
        result[i].push_back(matrix[j][i]);
      }
    }
    matrix.clear();
    matrix.resize(width);
    for (size_t i = 0; i < width; i++) {
      matrix[i].resize(height);
      matrix[i] = result[i];
    }
    width = height;
    height = copy;
    return *this;
  }

  Matrix& operator*(T num) {
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] *= num;
      }
    }
    return *this;
  }

  template <size_t V, size_t B, typename U>
  Matrix operator=(Matrix<V,B, U> other) {
    width = other.width;
    height = other.height;
    matrix.resize(other.height);
    for (size_t i = 0; i < height; i++) {
      matrix[i].resize(width);
      for (size_t j = 0; j < other.width; j++) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
    return *this;
  }

template <size_t V, size_t B>
Matrix<N,B,T> operator*(Matrix<V,B, T> mat2) {
  Matrix<N, B, T> result;
  int counter = 0;
  for (size_t k = 0; k < height; k++) {
    for (size_t i = 0; i < B; i++)
    {
      for (size_t j = 0; j < V; j++)
      {
        result(k,i) += (matrix[k][j] * mat2(j,k));
      }
    }
  }
  return result;
}

void print(){
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      std::cout<<(i,j)<<" ";
    }
    std::cout << std::endl;
  }
  
}
private:
  size_t height = N;
  size_t width = M;
  std::vector<std::vector<T>> matrix;

template <size_t V, size_t B>
friend Matrix operator*(Matrix<V,B, T> mat2);
};

template <size_t A, typename T>
class Matrix<A, A, T> {
public:
  Matrix(T num) {
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        matrix[i].push_back(num);
      }
    }
  }
void print(){
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      std::cout<<matrix[i][j]<<" ";
    }
    std::cout << std::endl;
  }
  
}
  Matrix() {
    T temp = 0;
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      matrix[i].resize(width);
      for (size_t j = 0; j < width; j++)
      {
        matrix[i][j] = temp;
      }
      
    }
  }

  Matrix(std::vector<std::vector<T>> vector) {
    matrix.resize(vector.size());
    for (size_t i = 0; i < vector.size(); i++) {
      matrix[i].resize(vector[i].size());
      for (size_t j = 0; j < vector[i].size(); j++) {
        matrix[i][j] = vector[i][j];
      }
    }
  }

  template <size_t V, size_t B, typename U>
  Matrix(Matrix<V,B,U>& other) {
    height = other.height;
    width = other.width;
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      matrix[i].resize(width);
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
  }

  T& operator()(size_t stroka, size_t stolb) { return matrix[stroka][stolb]; }

  T operator()(size_t stroka, size_t stolb) const {
    return matrix[stroka][stolb];
  }


  Matrix Transposed() {
    size_t copy = width;
    std::vector<std::vector<T>> result;
    result.resize(width);
    for (size_t i = 0; i < width; i++) {
      for (size_t j = 0; j < height; j++) {
        result[i].push_back(matrix[j][i]);
      }
    }
    matrix.clear();
    matrix.resize(width);
    for (size_t i = 0; i < width; i++) {
      matrix[i].resize(height);
      matrix[i] = result[i];
    }
    width = height;
    height = copy;
    return *this;
  }

  template <size_t V, size_t B, typename U>
  Matrix operator=(Matrix<V,B, U> other) {
    width = B;
    height = V;
    matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      matrix[i].resize(width);
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] = other(i,j);
      }
    }
    return *this;
  }


  Matrix& operator+=(const Matrix& other) {
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] += other.matrix[i][j];
      }
    }
    return *this;
  }

  Matrix operator+(const Matrix& other) {
    Matrix<other.height, other.width, T> result = other;
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        result.matrix[i][j] += matrix[i][j];
      }
    }
    return result;
  }
  Matrix& operator*(T num) {
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] *= num;
      }
    }
    return *this;
  }

  Matrix operator*(const Matrix& other) {
    Matrix result;
    T sum = 0;
    result.height = height;
    result.width = width;
    result.matrix.resize(height);
    for (size_t i = 0; i < height; i++) {
      result.matrix[i].resize(height);
    }
    int counter = 0;
    for (size_t k = 0; result.matrix[width - 1][width - 1] == 0; k++) {
      for (size_t i = 0; i < height; i++) {
        T temp = matrix[k][i] * other.matrix[i][k];
        sum += temp;
      }
      result.matrix[counter][k] = sum;
      if (k == height - 1) {
        counter++;
        k = -1;
      }
      sum = 0;
    }
    return result;
  }

  Matrix& operator-=(const Matrix& other) {
    if (width != other.width || height != other.width) {
      exit(1);
    }
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        matrix[i][j] -= other.matrix[i][j];
      }
    }
    return *this;
  }

  Matrix operator-(const Matrix& other) {
    Matrix result = *this;
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        result.matrix[i][j] -= other.matrix[i][j];
      }
    }
    return result;
  }

  Matrix& operator=(const Matrix& other) {
    width = other.width;
    height = other.height;
    matrix.resize(other.height);
    for (size_t i = 0; i < height; i++) {
      matrix[i].resize(width);
      for (size_t j = 0; j < other.width; j++) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
    return *this;
  }

  T Trace() {
    T sum = 0;
    for (size_t i = 0; i < height; i++) {
      sum += matrix[i][i];
    }
    return sum;
  }

  

private:
  size_t height = A;
  size_t width = A;
  std::vector<std::vector<T>> matrix;
};

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  Matrix<4,3> matrix(a);
  Matrix<3,3> matrix3(b);
  Matrix<3,3> as;
 // matrix3.Trace();
  as = matrix * matrix3;
as.print();
}