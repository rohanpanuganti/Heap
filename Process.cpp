// Rohan Panuganti
// Process.cpp
// 5/28/17

#include "Process.h"

// constructor
Process::Process(){
  id = 0;
  priority = 0;
}

// copt constructor
Process::Process(const Process &obj){
  id = obj.id;
  priority = obj.priority;
}

// overloaded =
Process& Process::operator =(const Process &obj){
  if(this != &obj){
    id = obj.id;
    priority = obj.priority;
  }
  return *this;
}

// overloaded < 
bool Process::operator <(const Process &obj){
  if(priority < obj.priority)
    return true;
  return false;
}

// overloaded == 
bool Process::operator==(const Process &obj){
  if(priority == obj.priority)
    return true;
  return false;
}

// overloaded <= 
bool Process::operator<=(const Process &obj){
  if(priority <= obj.priority)
    return true;
  return false;
}

// set the id
void Process::setID(int i){
  id = i;
}

// set priority
void Process::setPr(int p){
  priority = p;
}

// return id
int Process::getID(){
  return id;
}

// return priority
int Process::getPr(){
  return priority;
}
