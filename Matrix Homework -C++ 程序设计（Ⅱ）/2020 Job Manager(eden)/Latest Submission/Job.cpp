#include "Job.h"
#include <sstream>
#include <iostream>
using namespace std;
int Job::number = 0;
    
Job::Job(int priority){
    this->priority = priority;
    nextJob = NULL;
    this->id = number++;
}

void Job::setId(int id){
    this->id = id;
}
int Job::getId() const{
    return id;
}
void Job::setPriority(int priority){
    this->priority = priority;
}
int Job::getPriority() const{
    return priority;
}
void Job::setNext(Job *job){
    this->nextJob = job;
}
Job* Job::getNext() const{
    return nextJob;
}
string Job::toString(){
    ostringstream ss;
    ss << "["<<id<<":"<<priority<<"]";
    return ss.str();
}



