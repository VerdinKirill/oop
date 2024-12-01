#include "coordReader.h"


std::pair<int, int> CoordReader::readCoords () {
    int x, y;
    std::cout << "Введите координаты: ";
    std::cin >> x >> y;
    return {x, y};
}