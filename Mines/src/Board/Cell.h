//
//  Cell.h
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef Cell_h
#define Cell_h

namespace board{

struct Cell{
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    Cell()
    {
        isRevealed = false;
        neighboringMinesCounter = 0;
        isMine = false;
        symbol = 'o';
    }
    
    // ------------------------------------------------------------------------
    // DATA
    // ------------------------------------------------------------------------
    bool isRevealed;
    int neighboringMinesCounter;
    bool isMine;
    char symbol;
};

}


#endif /* Cell_h */
