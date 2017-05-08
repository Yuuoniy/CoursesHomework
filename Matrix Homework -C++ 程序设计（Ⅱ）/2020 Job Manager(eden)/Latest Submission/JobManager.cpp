#include "JobManager.h"
#include <cstring>
using namespace std;

JobManager* JobManager::instance = NULL;

JobManager* JobManager::getInstance() {
  if (instance == NULL) {
    instance = new JobManager();
  }
  return instance;
}
bool JobManager::deleteInstance() {
  if (instance != NULL) {
    delete instance;
    instance = NULL;
    return true;
  } else
    return false;
}

void JobManager::addJob(int priority) {
  Job* newJob = new Job(priority);
  if (jobFrontPointer == NULL) {
    jobFrontPointer = newJob;
    return;
  }
  Job* temp = jobFrontPointer;
  while (temp->getNext() != NULL) {
    temp = temp->getNext();
  }
  temp->setNext(newJob);
}

void JobManager::finishOneJob() {
  if (jobFrontPointer == NULL) return;
  Job* temp = jobFrontPointer;
  jobFrontPointer = jobFrontPointer->getNext();
  delete temp;
}
void JobManager::sortJob() {
  int count = getNumOfJob();
  if (jobFrontPointer == NULL || jobFrontPointer->getNext() == NULL) return;
  int temp = 0;
  Job* i = jobFrontPointer;
  Job* j = jobFrontPointer;
  for (; i->getNext(); i = i->getNext()) {
    for (j = jobFrontPointer; j->getNext(); j = j->getNext()) {
      if (j->getNext() == NULL) break;
      if (j->getPriority() < j->getNext()->getPriority()) {
        temp = j->getNext()->getPriority();
        j->getNext()->setPriority(j->getPriority());
        j->setPriority(temp);
        temp = j->getNext()->getId();
        j->getNext()->setId(j->getId());
        j->setId(temp);
      } else if (j->getPriority() == j->getNext()->getPriority()) {  //
        if (j->getId() > j->getNext()->getId()) {
          temp = j->getNext()->getId();
          j->getNext()->setId(j->getId());
          j->setId(temp);
        }
      }
    }
  }
}
void JobManager::printJob() {
  if (jobFrontPointer == NULL) {
    cout << "empty!" << endl;
    return;
  }
  Job* temp = jobFrontPointer;
  int flag = 1;
  while (temp != NULL) {
    if (flag) {
      flag = 0;
      cout << temp->toString();
    } else
      cout << "->" << temp->toString();
    temp = temp->getNext();
  }
  cout << endl;
}
int JobManager::getNumOfJob() {
  int count = 0;
  Job* temp = jobFrontPointer;
  while (temp != NULL) {
    temp = temp->getNext();
    count++;
  }
  return count;
}
void JobManager::clear() {
  if (jobFrontPointer == NULL) return;
  Job* p = jobFrontPointer;
  while (p != NULL) {
    Job* temp = p;
    p = p->getNext();
    delete temp;
  }
  jobFrontPointer = NULL;
}
JobManager::~JobManager() { clear(); }
JobManager::JobManager() { jobFrontPointer = NULL; }
