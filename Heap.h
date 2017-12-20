// Rohan Panuganti
// 5/28/17
// Heap.h
/*
  PURPOSE: The purpose of this file is to hold the
  Heap class methods. 
*/

#ifndef HEAP_H
#define HEAP_H

#include "Process.h"

class Heap {
public:
  // CONSTRUCTOR
  Heap(int cap);

  // DESTRUCTOR
  ~Heap();

  // PRE: constructor initialized
  // POST: bool is returned
  bool isEmpty() const;

  // PRE: two values are passed in
  // POST: the heap has a node added
  void insert(int i, int p);

  // PRE: the heap must be filled
  // POST: int returned
  int getMin() const;

  // PRE: heap muts have nodes
  // POST: new min node
  void deleteMin();

  // PRE: constructor initialized
  // POST: all values are printed
  void print() const;

  // PRE: nodes must be in the heap
  // POST: heap is ordered by priority 
  void heapSort();

  // PRE: position must exist
  // POST: value has new index
  void addValToPos(int pos, int p);

  // PRE: heap must have atleast one node
  // POST: min node is altered
  void replaceMin(int i, int p);

  // PRE: heap must have nodes
  // POST: one less node in the heap
  void deleteAtPos(int p);

  // PRE: constructor must be initialized
  // POST: no even priority numbers
  void flushEvenVal();
 
private:
  Process *theHeap; // array of processes      
  int size;         // number of nodes
  int capacity;     // size of array

  // PRE: constructor initialized
  // POST: index is recursively swapped down the heap
  void percolateUp(int pos);

  // PRE: constructor initialized
  // POST: index is recursively swapped up the heap 
  void percolateDown(int pos);

  // PRE: size must reach capacity
  // POST: capacity is doubled
  void resize();
};
#endif
