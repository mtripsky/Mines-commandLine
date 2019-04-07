//
//  Field.h
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef Field_h
#define Field_h

namespace board{

struct Field{
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    Field()
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


#endif /* Field_h */
