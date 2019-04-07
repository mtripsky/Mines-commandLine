//
//  PlayerInputReader.h
//  Mines
//
//  Created by Matej Tripsky on 07/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef PlayerInputReader_h
#define PlayerInputReader_h

#include <iostream>
#include <string>
#include <algorithm>
#include "Coordinate.h"


namespace game {

template <typename BoardState, typename AvalancheGenerator, typename Printer>
class PlayerInputReader{
public:
    PlayerInputReader(BoardState& state, const AvalancheGenerator& generator, const Printer& printer) :
        m_state(state),
        m_generator(generator),
        m_printer(printer)
    {}
    
    bool readInput(const char command, const char xCoordIn, const int yCoord) const {
        const auto xCoord = findIndexInAlphabet(xCoordIn);
        
        switch (command) {
            case 'p':
                return handlePress(xCoord, yCoord);
            case 'm':
                m_state.setMinesCounter() += 1;
                m_state.setField(xCoord, yCoord).symbol = 'm';
                m_state.setField(xCoord, yCoord).isRevealed = true;
                break;
            default:
                break;
        }
        
        return true;
    }
    
private:
    bool handlePress(const int x, const int y) const {
        if(m_state.getField(x,y).isMine){
            std::cout << "<<<<<<<< GAME OVER >>>>>>>>>" << std::endl;
            m_printer.print(false);  // print current state
            m_printer.print();  // print solution
            return false;
        }
        
        m_generator.generate(helpers::Coordinate<int>(x,y));
        
        return true;
    }
    
    auto findIndexInAlphabet(const char target) const
    {
        auto idx = m_alphabet.find(target);
        
        if (idx != std::string::npos) {
            return idx;
        } else {
            throw std::invalid_argument( "received incorrect coordinate" );
        }
    }
    
    
    BoardState& m_state;
    const AvalancheGenerator& m_generator;
    const Printer& m_printer;
    const std::string m_alphabet = "abcdefghijklmnopqrstuvwxyz";
};


template <typename BoardState, typename AvalancheGenerator, typename Printer>
PlayerInputReader<BoardState, AvalancheGenerator, Printer> playerInputReader(
        BoardState& b,
        const AvalancheGenerator& a,
        const Printer& p)
    {
        return PlayerInputReader<BoardState, AvalancheGenerator, Printer>(b, a, p);
    }
    
}

#endif /* PlayerInputReader_h */
