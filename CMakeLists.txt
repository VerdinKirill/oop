cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 20)
project(battleships_war)
add_executable(battleships_war
    src/main.cpp
    src/Battleship.cpp
    src/Battleship.h
    src/BattleshipCell.cpp
    src/BattleshipCell.h
    src/Field.cpp
    src/Field.h
    src/FieldCell.cpp
    src/FieldCell.h
    src/ShipManager.cpp
    src/ShipManager.h)