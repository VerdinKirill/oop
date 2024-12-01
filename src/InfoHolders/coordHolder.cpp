#include "coordHolder.h"


void CoordHolder::read () {
    coords = coordReader.readCoords ();
}


std::pair<int, int> CoordHolder::getCoords () {
    return coords;
}