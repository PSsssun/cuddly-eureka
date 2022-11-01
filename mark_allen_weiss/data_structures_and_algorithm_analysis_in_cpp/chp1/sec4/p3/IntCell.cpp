#include "IntCell.h"

/**
  * Construct the IntCell with initialValue
  * the default value is ommited here (specified in the interface only).
  */
IntCell::IntCell( int initialValue ) : storedValue{ initialValue }
{
}

/**
  * Return the stored value.
  */
int IntCell::read() const
{
    return storedValue;
}

/**
  * Store x.
  */
void IntCell::write( int x )
{
    storedValue = x;
}



