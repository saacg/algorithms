
#include <iostream>
#include <cstdlib>

template<class T>
numCell<T>::numCell()
{
    storedValue = 0;
}

template<class T>
numCell<T>::numCell(T initialValue)
{
    storedValue = initialValue;
}

template<class T>
T numCell<T>::read()
{
    return storedValue;
}

template<class T>
void numCell<T>::write(T value)
{
   storedValue = value;
}

template<class T>
numCell& numCell<T>::swap(numCell& otherCell)
{
    T tmp = this->read();
    write(otherCell.read());
    otherCell.write(tmp);
    return *this;
}

template<class T>
numCell& numCell<T>::operator=(numCell& otherCell)
{
    write(otherCell.read());
    return *this;
}

template<class T>
numCell& numCell<T>::operator+(numCell& otherCell)
{
    
    numCell *result = new numCell();
    result->write(this->read() + otherCell.read());
    return *result;
}
