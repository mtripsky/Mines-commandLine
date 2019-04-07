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
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    BoardState(int boardSize)
    {
        m_fields = std::vector<std::vector<Field>>();
        m_fields.resize(boardSize, std::vector<Field>(boardSize,Field()));
        m_minesCounter = 0;
    }
    
    // ------------------------------------------------------------------------
    // ACCESSORS
    // ------------------------------------------------------------------------
    const Field getField(const helpers::Coordinate<int> coordinate) const {
        return m_fields[coordinate.X][coordinate.Y];
    }
    
    const Field getField(const int x, const int y) const {
        return m_fields[x][y];
    }
    
    const std::vector<Field> getFieldsLine(const int index) const {
        return m_fields[index];
    }
    
    const int getBoardSize() const {
        return m_fields.size();
    }
    
    const int getMinesCounter() const {
        return m_minesCounter;
    }
    
    // ------------------------------------------------------------
    // MUTATORS
    // ------------------------------------------------------------
    Field& setField(const helpers::Coordinate<int> coordinate) {
        return m_fields[coordinate.X][coordinate.Y];
    }
    
    Field& setField(const int x, const int y) {
        return m_fields[x][y];
    }
    
    int& setMinesCounter() {
        return m_minesCounter;
    }
    
private:
    // ------------------------------------------------------------------------
    // DATA
    // ------------------------------------------------------------------------
    std::vector<std::vector<Field>> m_fields;
    int m_minesCounter;
};
    
}
#endif /* BoardState_h */
