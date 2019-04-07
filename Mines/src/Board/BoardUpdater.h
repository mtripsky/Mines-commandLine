//
//  BoardUpdater.h
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef BoardUpdater_h
#define BoardUpdater_h

#include "../Helpers/Coordinate.h"
#include "Field.h"
#include <vector>
#include <tuple>


namespace board {

template <typename State>
class BoardUpdater{
public:
    
    BoardUpdater(State& state) :
        m_state(state)
    {}
    
    void update(helpers::Coordinate<int> coord) const {
        if(isCoordinateOnBoard(coord.Y, coord.X))
        {
            for (auto i = -1; i <= 1 ; ++i) {
                for (auto j= -1; j <= 1; ++j) {
                    if(isCoordinateOnBoard(coord.X + i, coord.Y + j))
                    {
                        if(i == 0 && j == 0) {
                            m_state.setField(
                                helpers::Coordinate<int>(coord.X + i, coord.Y + j)).isMine = true;
                            m_state.setField(
                                helpers::Coordinate<int>(coord.X + i, coord.Y + j)).symbol = 'm';
                        }
                        else {
                            m_state.setField(
                                helpers::Coordinate<int>(coord.X + i, coord.Y + j)).neighboringMinesCounter += 1;
                        }
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
    
    State& m_state;
};
   
}

#endif /* BoardUpdater_h */
