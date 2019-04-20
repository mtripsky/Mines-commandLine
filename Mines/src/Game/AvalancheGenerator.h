//
//  AvalancheGenerator.h
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef AvalancheGenerator_h
#define AvalancheGenerator_h

#include "../Helpers/Coordinate.h"


namespace game{

template <typename BoardState>
class AvalancheGenerator {
public:
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    AvalancheGenerator(BoardState& state) : m_state(state)
    {
        m_x = std::vector<int>{-1,0,1,0};
        m_y = std::vector<int>{0,-1,0,1};
    }
    
    // ------------------------------------------------------------------------
    // METHODS
    // ------------------------------------------------------------------------
    void generate(helpers::Coordinate<int> coord) const {
        const auto mineCounter = m_state.getCell(coord).neighboringMinesCounter;
        m_state.setCell(coord).isRevealed = true;
        m_state.setCell(coord).symbol = '0' + mineCounter;
        
        if(mineCounter == 0){
            for (auto i = 0; i< m_x.size(); ++i) {
                if(isCoordinateOnBoard(coord.X + m_x[i], coord.Y + m_y[i])){
                    if(!m_state.getCell(coord.X + m_x[i], coord.Y + m_y[i]).isRevealed
                       && m_state.getCell(coord.X + m_x[i], coord.Y + m_y[i]).neighboringMinesCounter == 0)
                    {
                        generate(helpers::Coordinate<int>(coord.X + m_x[i], coord.Y + m_y[i]));
                    }
                    else
                    {
                        m_state.setCell(coord.X + m_x[i], coord.Y + m_y[i]).isRevealed = true;
                        m_state.setCell(coord.X + m_x[i], coord.Y + m_y[i]).symbol =
                        '0' + m_state.getCell(coord.X + m_x[i], coord.Y + m_y[i]).neighboringMinesCounter;
                    }
                }
            }
        }
    }
    
private:
    // ------------------------------------------------------------------------
    // AUXILARY METHODS
    // ------------------------------------------------------------------------
    bool isCoordinateOnBoard(int i, int j) const
    {
        if(i < 0 || j < 0 || i >= m_state.getBoardSize() || j>= m_state.getBoardSize())
        {
            return false;
        }
        
        return true;
    }
    
    // ------------------------------------------------------------------------
    // DATA
    // ------------------------------------------------------------------------
    BoardState& m_state;
    std::vector<int> m_x;
    std::vector<int> m_y;
};

template <typename BoardState>
AvalancheGenerator<BoardState> avalancheGenerator(BoardState& s)
{
    return AvalancheGenerator<BoardState>(s);
}
    
}


#endif /* AvalancheGenerator_h */
