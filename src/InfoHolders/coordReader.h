#ifndef COORDREADER_H
#define COORDREADER_H

#include <iostream>
#include <exception>
#include "../Exceptions/ReaderException.h"




class CoordReader {

public:
    std::pair<int, int> readCoords ();

};

#endif