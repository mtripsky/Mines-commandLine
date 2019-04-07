//
//  Board.h
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include "Field.h"
#include <vector>


namespace board {

template <typename BoardState, typename MinesGenerator, typename BoardUpdater>
class Board{
public:
    Board(BoardState& state,
          const MinesGenerator& generator,
          const BoardUpdater& updater) :
        m_state(state),
        m_generator(generator),
        m_updater(updater)
    {}
    
    void InitializeBoard(int minesCount){
        auto side = m_state.getBoardSize();
        if(side * side < minesCount){
            std::cout << "Too many mines for the board" << std::endl;
            return;
        }
        
        auto minesCoordinates = m_generator.generateMines(side, minesCount);
        
        for( auto mineCoordinate : minesCoordinates)
        {
            m_updater.update(mineCoordinate);
        }
    }
    
private:
    BoardState& m_state;
    const MinesGenerator& m_generator;
    const BoardUpdater& m_updater;
};

template <typename BoardState, typename MinesGenerator, typename BoardUpdater>
Board<BoardState, MinesGenerator,BoardUpdater> board(
    BoardState& state,
    const MinesGenerator& generator,
    const BoardUpdater& updater) noexcept
{
    return Board<BoardState, MinesGenerator, BoardUpdater>(state, generator, updater);
}
    
    
}

#endif /* Board_h */
