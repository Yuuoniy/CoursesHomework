 #ifndef Relation_hpp
#define Relation_hpp 
#include "ProductSet.hpp"
#include "BooleanMatrix.hpp"
using namespace std;
class Relation:ProductSet
{
public:
	Relation(BooleanMatrix const & ,Set const& a,Set const&b);
	~Relation();
protected:
	BooleanMatrix Matrix;

};
#endif