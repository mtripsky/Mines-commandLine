//
//  BoardState.h
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef BoardState_h
#define BoardState_h

#include "Cell.h"
#include "../Helpers/Coordinate.h"


namespace board {

class BoardState{
public:
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    BoardState(int boardSize)
    {
        m_Cells = std::vector<std::vector<Cell>>();
        m_Cells.resize(boardSize, std::vector<Cell>(boardSize,Cell()));
        m_minesCounter = 0;
    }
    
    // ------------------------------------------------------------------------
    // ACCESSORS
    // ------------------------------------------------------------------------
    const Cell getCell(const helpers::Coordinate<int> coordinate) const {
        return m_Cells[coordinate.X][coordinate.Y];
    }
    
    const Cell getCell(const int x, const int y) const {
        return m_Cells[x][y];
    }
    
    const std::vector<Cell> getCellsLine(const int index) const {
        return m_Cells[index];
    }
    
    const int getBoardSize() const {
        return m_Cells.size();
    }
    
    const int getMinesCounter() const {
        return m_minesCounter;
    }
    
    // ------------------------------------------------------------
    // MUTATORS
    // ------------------------------------------------------------
    Cell& setCell(const helpers::Coordinate<int> coordinate) {
        return m_Cells[coordinate.X][coordinate.Y];
    }
    
    Cell& setCell(const int x, const int y) {
        return m_Cells[x][y];
    }
    
    int& setMinesCounter() {
        return m_minesCounter;
    }
    
private:
    // ------------------------------------------------------------------------
    // DATA
    // ------------------------------------------------------------------------
    std::vector<std::vector<Cell>> m_Cells;
    int m_minesCounter;
};
    
}
#endif /* BoardState_h */
