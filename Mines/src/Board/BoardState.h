//
//  BoardState.h
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef BoardState_h
#define BoardState_h

#include "Field.h"
#include "Coordinate.h"


namespace board {

class BoardState{
public:
    BoardState(int boardSize)
    {
        m_fields = std::vector<std::vector<Field>>();
        m_fields.resize(boardSize, std::vector<Field>(boardSize,Field()));
        m_minesCounter = 0;
    }
    
    // ------------------------------------------------------------
    // ACCESSORS
    // ------------------------------------------------------------
    const Field getField(helpers::Coordinate<int> coordinate) const {
        return m_fields[coordinate.X][coordinate.Y];
    }
    
    const Field getField(int x, int y) const {
        return m_fields[x][y];
    }
    
    const std::vector<Field> getFieldsLine(int index) const {
        return m_fields[index];
    }
    
    const size_t getBoardSize() const {
        return m_fields.size();
    }
    
    const int getMinesCounter() const {
        return m_minesCounter;
    }
    
    // ------------------------------------------------------------
    // MUTATORS
    // ------------------------------------------------------------
    Field& setField(helpers::Coordinate<int> coordinate) {
        return m_fields[coordinate.X][coordinate.Y];
    }
    
    Field& setField(int x, int y) {
        return m_fields[x][y];
    }
    
    int& setMinesCounter() {
        return m_minesCounter;
    }
    
private:
    std::vector<std::vector<Field>> m_fields;
    int m_minesCounter;
};
    
}
#endif /* BoardState_h */
