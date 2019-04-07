//
//  AvalancheGenerator.h
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef AvalancheGenerator_h
#define AvalancheGenerator_h

#include "Coordinate.h"


namespace game{

template <typename BoardState>
class AvalancheGenerator {
public:
    AvalancheGenerator(BoardState& state) : m_state(state)
    {
        m_x = std::vector<int>{-1,0,1,0};
        m_y = std::vector<int>{0,-1,0,1};
    }
    
    void generate(helpers::Coordinate<int> coord) const {
        const auto mineCounter = m_state.getField(coord).neighboringMinesCounter;
        m_state.setField(coord).isRevealed = true;
        m_state.setField(coord).symbol = '0' + mineCounter;
        
        if(mineCounter == 0){
            for (auto i = 0; i< m_x.size(); ++i) {
                if(isCoordinateOnBoard(coord.X + m_x[i], coord.Y + m_y[i])){
                    if(!m_state.getField(coord.X + m_x[i], coord.Y + m_y[i]).isRevealed
                       && m_state.getField(coord.X + m_x[i], coord.Y + m_y[i]).neighboringMinesCounter == 0)
                    {
                        generate(helpers::Coordinate<int>(coord.X + m_x[i], coord.Y + m_y[i]));
                    }
                    else
                    {
                        m_state.setField(coord.X + m_x[i], coord.Y + m_y[i]).isRevealed = true;
                        m_state.setField(coord.X + m_x[i], coord.Y + m_y[i]).symbol =
                        '0' + m_state.getField(coord.X + m_x[i], coord.Y + m_y[i]).neighboringMinesCounter;
                    }
                }
            }
        }
    }
    
private:
    bool isCoordinateOnBoard(int i, int j) const
    {
        if(i < 0 || j < 0 || i >= m_state.getBoardSize() || j>= m_state.getBoardSize())
        {
            return false;
        }
        
        return true;
    }
    
    BoardState& m_state;
    std::vector<int> m_x;
    std::vector<int> m_y;
};

}


#endif /* AvalancheGenerator_h */
