#include <iostream>
#include "Heap.h"
#include "PrintJob.h"

using namespace std;

Heap::Heap(){
    numItems = 0;
}

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
void Heap::enqueue ( PrintJob* job){
    if (numItems == 10)
    {
        return;
    }
    int priority = job->getPriority();
    if (numItems == 0)
    {
        arr[0] = job;
    }
    else if (priority < arr[numItems-1]->getPriority())
    {
        arr[numItems] = job;
    }
    else
    {
        int count = 0;
        for (int i = 0; i < numItems; ++i)
        {
            if (priority < arr[i]->getPriority())
            {
                ++count;
            }
        }
        for (int i = numItems; i > count; --i)
        {
            arr[i] = arr[i-1];
        }
        arr[count] = job;   
    }
    

    ++numItems;
}

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
void Heap::dequeue ( ){
    delete arr[0];
    for (int i = 0; i < numItems - 1; ++i)
    {
        arr[i] = arr[i+1];
    }
    --numItems;
}

  /*Returns the node with highest priority.*/
PrintJob* Heap::highest ( ){
    return arr[0];
}

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
void Heap::print ( ){
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() 
        << ", Number of Pages: " << arr[0]->getPages() << endl;
}
