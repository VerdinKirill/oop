#include "coordReader.h"

std::pair<int, int> CoordReader::readCoords()
{
    int x, y;
    std::cout << "Введите координаты: ";
    try
    {
        std::cin >> x >> y;
    }
    catch (std::exception &e)
    {
        // throw ReaderException("Были введены неверные координаты");
    }
    return {x, y};
}