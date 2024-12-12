cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 20)
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
    ShipManager.h

    skills/Bombardment.cpp
    skills/Bombardment.h
    skills/BombardmentFactory.cpp
    skills/BombardmentFactory.h
    skills/DoubleDamage.cpp
    skills/DoubleDamage.h
    skills/DoubleDamageFactory.cpp
    skills/DoubleDamageFactory.h
    skills/Scaner.cpp
    skills/Scaner.h
    skills/ScanerFactory.cpp
    skills/ScanerFactory.h 
    skills/Skill.h
    skills/SkillFactory.h
    skills/SkillManager.h
    skills/SkillManager.cpp
    skills/SkillPrinter.h
    skills/SkillPrinter.cpp
    skills/SkillVisitor.h

    InfoHolders/InfoHolder.h
    InfoHolders/SkillInfoHolder.h
    InfoHolders/SkillInfoHolder.cpp
    InfoHolders/SkillResultInfoHolder.h
    InfoHolders/SkillResultInfoHolder.cpp
    InfoHolders/commandHolder.h
    InfoHolders/commandHolder.cpp
    InfoHolders/coordHolder.h
    InfoHolders/coordHolder.cpp
    InfoHolders/coordReader.h
    InfoHolders/coordReader.cpp
    InfoHolders/commandReader.cpp
    InfoHolders/commandReader.h
    InfoHolders/directionReader.h
    InfoHolders/directionReader.cpp
    InfoHolders/directionHolder.cpp
    InfoHolders/directionHolder.h

    Exceptions/NoneAvailableSkillsException.h
    Exceptions/NoneAvailableSkillsException.cpp
    Exceptions/OutOfBondsException.h
    Exceptions/OutOfBondsException.cpp
    Exceptions/ShipNearAnotherException.h
    Exceptions/ShipNearAnotherException.cpp
    Exceptions/BotException.h
    Exceptions/BotException.cpp
    Exceptions/ReaderException.h
    Exceptions/ReaderException.cpp
    Exceptions/UnknownCommandException.h
    Exceptions/UnknownCommandException.cpp
    Exceptions/ModifiedJsonException.h
    Exceptions/ModifiedJsonException.cpp
    Exceptions/UnableOpenFileException.h
    Exceptions/UnableOpenFileException.cpp
    
    Players/Player.h
    Players/User.h
    Players/User.cpp
    Players/Bot.h
    Players/Bot.cpp
    
    Utils/Randomizer.cpp
    Utils/Randomizer.h

    Game/Game.h
    Game/GameState.cpp
    Game/GameState.h
    Game/PvEGame.cpp
    Game/PvEGame.h
    Game/GameSaver.h
    Game/GameSaver.cpp


    FileWork/FileWrapper.h
    FileWork/FileWrapper.cpp
    FileWork/Serialization.h
    FileWork/Serialization.cpp
    FileWork/Deserialization.cpp
    FileWork/Deserialization.cpp
    
    libraries/json.hpp
    )




