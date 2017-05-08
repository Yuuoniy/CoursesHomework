#include "Matrix.h"
Matrix::Matrix(string str, int _height, int _width, int** _param) {
  name = str;
  width = _width;
  height = _height;
  param = new int*[height];
  for (int i = 0; i < height; i++) {
    param[i] = new int[width];
    for (int j = 0; j < width; j++) {
      param[i][j] = _param[i][j];
    }
  }
}
Matrix::Matrix(const Matrix& other) {
  name = other.name;
  width = other.width;
  height = other.height;
  int** param = new int*[height];
  for (int i = 0; i < height; i++) {
    param[i] = new int[width];
    for (int j = 0; j < width; j++) {
      param[i][j] = other.param[i][j];
    }
  }
}
Matrix::~Matrix() {
  for (int i = 0; i < height; i++) {
    delete[] param[i];
  }
  delete[] param;
}

// overload operator
bool Matrix::operator==(const Matrix& other) {
  if (other.width != width || other.height != height) return false;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (other.param[i][j] != param[i][j]) return false;
    }
  }
  return true;
}

bool Matrix::operator!=(const Matrix& other) {
  return *this == other ? false : true;
  return false;
}
void Matrix::operator+=(const Matrix& other) {
  if (other.width != width || other.height != height) {
    std::cout << "invalid addition." << std::endl;
    return;
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      param[i][j] += other.param[i][j];
    }
  }
}
void Matrix::operator-=(const Matrix& other) {
  if (other.width != width || other.height != height) {
    std::cout << "invalid substraction." << std::endl;
    return;
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      param[i][j] -= other.param[i][j];
    }
  }
}
Matrix Matrix::operator*(const Matrix& other) {
  Matrix result;

  if (width != other.height) {
    std::cout << "invalid multiplication." << std::endl;
    return result;
  }
  result.name = "newMat";
  result.height = this->height;
  result.width = other.width;
  result.param = new int*[result.height];
  for (int i = 0; i < result.height; i++) {
    result.param[i] = new int[result.width];
    for (int j = 0; j < result.width; j++) result.param[i][j] = 0;
  }

  for (int i = 0; i < result.height; i++) {
    for (int j = 0; j < result.width; j++) {
      for (int k = 0; k < this->width; k++) {
        (result.param)[i][j] += param[i][k] * (other.param)[k][j];
      }
    }
  }

  return result;
}
