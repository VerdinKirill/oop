#include "coordHolder.h"


void CoordHolder::read () {
    coords = coordReader.readCoords();
    if (coords.first < 0 || coords.second < 0)
    {
        throw ReaderException(std::string("Вы ввели некоректные координаты"));
    }
}


std::pair<int, int> CoordHolder::getCoords () {
    return coords;
}