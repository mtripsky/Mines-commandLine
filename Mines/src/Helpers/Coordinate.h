//
//  Coordinate.h
//  Mines
//
//  Created by Matej Tripsky on 05/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#ifndef Coordinate_h
#define Coordinate_h

namespace helpers {

template <typename T>
struct Coordinate {
    Coordinate(T x, T y) : X(x), Y(y)
    {}
    
    T X;
    T Y;
    
    bool operator==(const Coordinate<T> &other) {
        if(X == other.X && Y == other.Y) {
            return true;
        }
        
        return false;
    }
};
    
}

#endif /* Coordinate_h */
