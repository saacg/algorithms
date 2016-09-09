#include "numCell.h"


numCell::numCell()
{
    storedValue = 0;
}

numCell::numCell(int initialValue)
{
    storedValue = initialValue;
}

int numCell::read()
{
    return storedValue;
}

void numCell::write(int value)
{
    storedValue = value;
}

numCell& numCell::swap(numCell& otherCell)
{
    int tmp = this->read();
    write(otherCell.read());
    otherCell.write(tmp);
    return *this;
}

numCell& numCell::operator=(numCell& otherCell)
{
    write(otherCell.read());
    return *this;
}

numCell& numCell::operator+(numCell& otherCell)
{
    
    numCell *result = new numCell();
    result->write(this->read() + otherCell.read());
    return *result;
}
