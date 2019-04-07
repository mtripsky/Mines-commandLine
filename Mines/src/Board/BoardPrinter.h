//
//  BoardSolutionPrinter.h
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef BoardSolutionPrinter_h
#define BoardSolutionPrinter_h

#include <iomanip>
#include <iostream>


namespace board{
    
template <typename BoardState>
class BoardPrinter{
public:
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    BoardPrinter(BoardState& state) : m_state(state)
    {}
    
    // ------------------------------------------------------------------------
    // METHODS
    // ------------------------------------------------------------------------
    void print(bool flag = true) const
    {
        printHeader();
        for(auto i=0; i< m_state.getBoardSize(); ++i)
        {
            std::cout << m_alphabet[i] << std::setw(1) << '|';
            printLine(m_state.getFieldsLine(i), flag);
        }
    }
    
private:
    // ------------------------------------------------------------------------
    // AUXILARY METHODS
    // ------------------------------------------------------------------------
    void printHeader() const
    {
        std::cout << std::setw(4);
        for (auto i=0; i < m_state.getBoardSize(); ++i) {
            std::cout << i << ' ';
        }
        std::cout<< '\n';
        std::cout << std::setw(4);
        for (auto i=0; i < 2*m_state.getBoardSize(); ++i) {
            std::cout << '-';
        }
        std::cout<< '\n';
    }
    
    void printLine(const std::vector<Field> fields, const bool solution) const
    {
        std::cout << std::setw(2);
        for (auto field : fields) {
            if(solution) {
                if(field.isMine){
                    std::cout << 'm' << ' ';
                }
                else{
                    std::cout << field.neighboringMinesCounter << ' ';
                }
            }
            else {
                if(field.isRevealed)
                {
                    std::cout << field.symbol << ' ';
                }
                else {
                    std::cout << 'o' << ' ';
                }
            }
        }
        std::cout<< '\n';
    }
    
    // ------------------------------------------------------------------------
    // DATA
    // ------------------------------------------------------------------------
    const std::string m_alphabet = "abcdefghijklmnopqrstuvwxyz";
    BoardState& m_state;
};

template <typename BoardState>
BoardPrinter<BoardState> boardPrinter(BoardState& s)
{
    return BoardPrinter<BoardState>(s);
}

}

#endif /* BoardSolutionPrinter_h */
