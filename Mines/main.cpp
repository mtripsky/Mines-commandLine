//
//  main.cpp
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#include <iostream>
#include "BoardInitializer.h"
#include "BoardState.h"
#include "BoardUpdater.h"
#include "MinesGenerator.h"
#include "BoardPrinter.h"
#include "AvalancheGenerator.h"
#include "PlayerInputReader.h"


int main(int argc, const char * argv[]) {
    
    const auto boardSize = 3;
    const auto mines = 2;
    
    auto minesGenerator = board::MinesGenerator();
    auto state = board::BoardState(boardSize);
    auto updater = board::boardUpdater(state);
    auto board = board::boardInitializer(state, minesGenerator, updater);
    
    board.initialize(mines);
    
    auto printer = board::boardPrinter(state);
    
    auto avalancheGen = game::avalancheGenerator(state);
    auto reader = game::playerInputReader(state, avalancheGen, printer);
    
    auto gameStatus = true;
    char command;
    char xCoord;
    int yCoord;
    
    std::cout<< "You are looking for : " << mines << std::endl;
    while(gameStatus){
        printer.print(false);
        std::cout<<"Input (p-for press, m-for mine, Q-for quit):\n";
        std::cout<<"Command: ";
        std::cin>>command;
        if(command == 'Q'){
            break;
        }
        std::cout<<"[x]: ";
        std::cin>>xCoord;
        std::cout<<"[y]: ";
        std::cin>>yCoord;
    
        gameStatus = reader.readInput(command, xCoord, yCoord);
        if(state.getMinesCounter() == mines){
            std::cout << "YOUR SOLUTION: " << std::endl;
            printer.print(false);
            std::cout << std::endl;
            std::cout << "SOLUTION: " << std::endl;
            printer.print();
            break;
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}
