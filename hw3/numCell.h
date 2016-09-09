#ifndef numCELL
#define numCELL

#include <stdio.h>

/* A class for storing and manipulating integers */
class numCell
{
private:
    int storedValue;
    
public:
    numCell();                                // constructor 
    numCell(int initialValue);                // constructor
    int read();                               // return the content of the cell
    void write(int value);                    // write value to cell
    numCell& swap (numCell& otherCell);       // swap the contents of this cell with another
    numCell& operator=(numCell& otherCell);   // copy constructor
    numCell& operator+(numCell& otherCell);   // return the sum of this and otherCell
};

#endif /* numCell_hpp */
