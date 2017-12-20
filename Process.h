// Rohan Panuganti
// 5/28/17
// Process.h
/*
  PURPOSE: The purpose of this file is to initialize all
  the methods of the Process class. 
*/

#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
  // constructor
  Process();

  // copy constructor
  Process(const Process &obj);

  // overloaded assignment operator
  Process& operator =(const Process &obj);

  // overloaded comparison operator
  bool operator <(const Process &obj);

  //overloaded comparison operator
  bool operator==(const Process &obj);

  // overloaded comparison operator
  bool operator<=(const Process &obj);

  // PRE: value taken in as parameter
  // POST: id set 
  void setID(int i);

  // PRE: value taken in as parameter
  // POST: priority set
  void setPr(int p);

  // PRE: value must be set
  // POST: id returned
  int getID();

  // PRE: value must be set
  // POST: priority returned
  int getPr();
  
private:
  int id;       // id of node
  int priority; // priority of node
};

#endif
