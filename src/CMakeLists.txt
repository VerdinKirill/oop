# cmake_minimum_required(VERSION 3.10)
project(battleships_war)
add_executable(battleships_war
    main.cpp
    Battleship.cpp
    Battleship.h
    BattleshipCell.cpp
    BattleshipCell.h
    Field.cpp
    Field.h
    FieldCell.cpp
    FieldCell.h
    ShipManager.cpp
    ShipManager.h)