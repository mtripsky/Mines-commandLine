//
//  MinesGenerator.h
//  Mines
//
//  Created by Matej Tripsky on 04/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef MinesGenerator_h
#define MinesGenerator_h

#include "../Helpers/Coordinate.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


namespace board {
    
class MinesGenerator{
public:
    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------
    MinesGenerator() {}
    
    // ------------------------------------------------------------------------
    // METHODS
    // ------------------------------------------------------------------------
    auto generateMines(int mSize, int count) const {
        auto result = std::vector<helpers::Coordinate<int>>();
        
        for(auto i=0; i< mSize; ++i){
            for(auto j=0; j< mSize; ++j) {
                result.emplace_back(helpers::Coordinate<int>(i,j));
            }
        }
        std::random_device rd;
        std::mt19937 g(rd());
        
        std::shuffle(result.begin(), result.end(), g);
        result.erase(result.begin() + count, result.end());
        
        return result;
    }
};

}

#endif /* MinesGenerator_h */
