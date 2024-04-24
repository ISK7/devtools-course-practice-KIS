// Copyright 2024 Kiselev Igor

#ifndef MODULES_KISELEV_I_CONWAYS_GAME_OF_LIFE_APP_INCLUDE_CONWAYS_GAME_OF_LIFE_APP_H_
#define MODULES_KISELEV_I_CONWAYS_GAME_OF_LIFE_APP_INCLUDE_CONWAYS_GAME_OF_LIFE_APP_H_


#include "../include/conways_game_of_life.h"

class ConwaysGameOfLifeApplication {
 private:
    int numberOfGenerations;
    int dataErrorNumber;
    ConwaysGameOfLife game;
    const char* appName;
 public:
    ConwaysGameOfLifeApplication(int argc, const char** argv);
    std::string doWork();
    void nextGeneration();
    std::string getField();
    bool setNewField(int argc, const char** argv);
};

#endif //MODULES_KISELEV_I_CONWAYS_GAME_OF_LIFE_APP_INCLUDE_CONWAYS_GAME_OF_LIFE_APP_H_
