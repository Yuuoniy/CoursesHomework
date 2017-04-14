 #include "Relation.hpp"
#include "BooleanMatrix.hpp"

Relation::Relation(const BooleanMatrix& othermatrix,const Set & a, const Set & b):ProductSet(a, b) ,Matrix(othermatrix){
}
Relation::~Relation(){

}

