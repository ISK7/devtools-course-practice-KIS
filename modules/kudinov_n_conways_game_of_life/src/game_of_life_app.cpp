// Copyright 2024 Kiselev Igor

#include "../include/game_of_life_app.h"

#include <exception>

ConwaysGameOfLifeApplication::ConwaysGameOfLifeApplication(int argc, const char** argv) : game(1, 1) {
    dataErrorNumber = 0;
    appName = argv[0];
    numberOfGenerations = 0;
    if (argc == 1) {
        dataErrorNumber = -1;
        return;
    }
    if (argc < 4 || argc % 2 == 1) {
        dataErrorNumber = 1;
        return;
    }
    try {
        char* end;
        const char* numberString = argv[3];
        numberOfGenerations = _strtoi64(numberString, &end, 0);
        if (numberOfGenerations < 0 || end[0]) dataErrorNumber = 2;
    }
    catch (...) {
        dataErrorNumber = 2;
    }
    setNewField(argc, argv);
}

std::string ConwaysGameOfLifeApplication::doWork() {
    switch (dataErrorNumber)
    {
    case -1:
        return "This is application for Conway's game of life.\n" + 
            std::string("Pleace, enter height and width of field, number of ") +
            "generations and living points";
        break;
    case 1:
        return "Error: Incorrect count of arguments!";
        break;
    case 2:
        return "Error: Incorrect number of generations!";
        break;
    case 3:
        return "Error: Incorrect height or width!";
        break;
    case 4:
        return "Error: Some of points are incorret!";
        break;
    }
    for (int i = 0; i < numberOfGenerations; i++) {
        nextGeneration();
    }
    return appName + ' ' + getField();
}

void ConwaysGameOfLifeApplication::nextGeneration() {
    game.simulateNextGeneration();
}

std::string ConwaysGameOfLifeApplication::getField() {
    return game.toString();
}

bool ConwaysGameOfLifeApplication::setNewField(int argc, const char** argv) {
    int height = 0;
    int width = 0;
    dataErrorNumber = 0;
    try {
        char* endH;
        char* endW;
        const char* numberHeight = argv[1];
        const char* numberWidth = argv[2];
        height = _strtoi64(numberHeight, &endH, 0);
        width = _strtoi64(numberWidth, &endW, 0);
        if (numberOfGenerations < 0 || endH[0] || endW[0]) dataErrorNumber = 2;
    }
    catch (...) {
        dataErrorNumber = 1;
        return false;
    }
    ConwaysGameOfLife newGame = ConwaysGameOfLife(1,1);
    if (dataErrorNumber == 0) {
        try {
            newGame = ConwaysGameOfLife(height, width);
        }
        catch (...) {
            dataErrorNumber = 3;
            return false;
        }
        if (dataErrorNumber == 0) {
            try {
                for (int i = 4; i < argc - 1; i += 2) {
                    char* endX;
                    char* endY;
                    int x = _strtoi64(argv[i], &endX, 0);
                    int y = _strtoi64(argv[i + 1], &endY, 0);
                    game.setCellState(x, y, true);
                }
            }
            catch (...) {
                dataErrorNumber = 4;
                return false;
            }
        }
    }
    game = ConwaysGameOfLife(newGame);
    return true;
}
