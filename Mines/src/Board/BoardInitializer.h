//
//  Board.h
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include "Cell.h"
#include <vector>


namespace board {

template <typename BoardState, typename MinesGenerator, typename BoardUpdater>
class BoardInitializer{
public:
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    BoardInitializer(BoardState& state,
                     const MinesGenerator& generator,
                     const BoardUpdater& updater) :
                        m_state(state),
                        m_generator(generator),
                        m_updater(updater) {}
    
    // ------------------------------------------------------------------------
    // METHODS
    // ------------------------------------------------------------------------
    void initialize(int minesCount) const {
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
    // ------------------------------------------------------------------------
    // DATA
    // ------------------------------------------------------------------------
    BoardState& m_state;
    const MinesGenerator& m_generator;
    const BoardUpdater& m_updater;
};

template <typename BoardState, typename MinesGenerator, typename BoardUpdater>
BoardInitializer<BoardState, MinesGenerator,BoardUpdater> boardInitializer(
    BoardState& s,
    const MinesGenerator& g,
    const BoardUpdater& u) noexcept
{
    return BoardInitializer<BoardState, MinesGenerator, BoardUpdater>(s, g, u);
}
    
}

#endif /* Board_h */
