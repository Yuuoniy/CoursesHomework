 
#include <iostream>
#include <sstream>
#include <cmath>
#ifndef VE_H
#define	VE_H

using namespace std;
struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
};

class Vehicle {
 public:
    explicit Vehicle(double _speed);
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const;
    virtual ~Vehicle();
 private:
    double speed;
};

class BicycleStrategy:public Vehicle
{
public:
	BicycleStrategy(double speed);
	void doTravel(const City& src, const City& dest);
	~BicycleStrategy();
	
};

class TrainStrategy:public Vehicle
{
public:
	TrainStrategy(double speed);
	void doTravel(const City& src, const City& dest) ;
	~TrainStrategy();
	
};
class AirplaneStrategy:public Vehicle
{
public:
	AirplaneStrategy(double speed);
	void doTravel(const City& src, const City& dest) ;
	~AirplaneStrategy();
	
};




 Vehicle::Vehicle(double _speed):speed(_speed) {}
 void Vehicle::doTravel(const City& src, const City& dest){

 }
 double Vehicle::getSpeed() const {
        return speed;
    }
 Vehicle::~Vehicle() {}



BicycleStrategy::BicycleStrategy(double speed):Vehicle(speed){
}

void BicycleStrategy::doTravel(const City& src, const City& dest) {
		double time = 0;
		double dis = fabs(src.x-dest.x)+fabs(src.y-dest.y);
		time = dis/getSpeed();
		cout << "It takes "<< time <<" hours to Travel from " << src.name << " to " << dest.name << " by Bicycle."<<endl;
}
BicycleStrategy::~BicycleStrategy(){
}
	

TrainStrategy::TrainStrategy(double speed):Vehicle(speed){}
void TrainStrategy:: doTravel(const City& src, const City& dest) {
		double time = 0;
		double dis = sqrt((src.x-dest.x)*(src.x-dest.x)+((src.y-dest.y)*(src.y-dest.y)));
		time = dis/getSpeed();
		cout << "It takes "<< time <<" hours to Travel from " << src.name << " to " << dest.name << " by Train."<<endl;
}

TrainStrategy::~TrainStrategy(){
}
	

AirplaneStrategy::AirplaneStrategy(double speed):Vehicle(speed){}
void AirplaneStrategy::doTravel(const City& src, const City& dest) {
		double time = 0;
		double dis =fabs(src.x-dest.x)>fabs(src.y-dest.y)?fabs(src.x-dest.x):fabs(src.y-dest.y);
		time = dis/getSpeed();
		cout << "It takes "<< time <<" hours to Travel from " << src.name << " to " << dest.name << " by Airplane."<<endl;

	}
AirplaneStrategy::~AirplaneStrategy(){

}



#endif