#include "BooleanMatrix.hpp"
using namespace std;
BooleanMatrix::BooleanMatrix(const BooleanMatrix &other):Matrix(other){

}
BooleanMatrix::BooleanMatrix(int r, int c):Matrix(r,c){

}

bool BooleanMatrix::replace(matrix_element_type e, int r, int c){
	if(e!=0&&e!=1)
		return false;
	else{
		Matrix::replace(e,r,c);
	}
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix &other) {
  BooleanMatrix temp(row, columns);
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= columns; j++)
    //  temp.matirx[ELEMENT_POS(i, j)] = this->getElement(i,j) & other.getElement(i,j);
  		temp.replace(this->getElement(i,j) & other.getElement(i,j),i,j);
  }
  return temp;
}
BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix &other) {
  BooleanMatrix temp(row, columns);
  for (int i = 1; i <=row; i++) {
    for (int j = 1; j <=columns; j++)
    //  temp.matirx[ELEMENT_POS(i, j)] = ((*this).getElement(i,j)||other.getElement(i,j))?1:0;
    temp.replace(this->getElement(i,j) | other.getElement(i,j),i,j);

  }
  return temp;
}
BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix &other) const {
  if (this->columns != other.row) return *this;
  BooleanMatrix result(row, other.columns);
  for (int i = 1; i <= this->row; i++) {
    for (int j = 1; j <= other.columns; j++) {
      for (int k = 1; k <= this->columns; k++) {
        if((this->getElement(i, k)) * other.getElement(k,j)){
          result.replace(1, i, j);
          break;
        }
      }
    }
  }

  return result;
}
