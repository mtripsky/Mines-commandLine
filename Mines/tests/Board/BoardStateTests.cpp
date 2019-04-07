//
//  BoardStateTests.cpp
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#include <stdio.h>
#include "catch.hpp"
#include "fakeit.hpp"
#include "BoardState.h"
#include "Coordinate.h"
#include "Field.h"


namespace board{
    namespace tests{
        
        SCENARIO( "testing board state" ) {
            GIVEN( "board size 2" ) {
                
                WHEN( "state is initialized" ) {
                    auto sut = BoardState(2);
                    
                    THEN( "then all neighbor counters should be zero" ) {
                        REQUIRE( sut.getField(helpers::Coordinate<int>(0,0)).neighboringMinesCounter == 0 );
                        REQUIRE( sut.getField(helpers::Coordinate<int>(0,1)).neighboringMinesCounter == 0 );
                        REQUIRE( sut.getField(helpers::Coordinate<int>(1,0)).neighboringMinesCounter == 0 );
                        REQUIRE( sut.getField(helpers::Coordinate<int>(1,1)).neighboringMinesCounter == 0 );
                    }
                }
                
                WHEN( "state is initialized and we change Field(1,1).isBomb = true" ) {
                    auto sut = BoardState(2);
                    
                    sut.setField(helpers::Coordinate<int>(1,1)).isMine = true;
                    
                    THEN( "then all Field should have isBomb false except Field(1,1)" ) {
                        REQUIRE_FALSE( sut.getField(helpers::Coordinate<int>(0,0)).isMine);
                        REQUIRE_FALSE( sut.getField(helpers::Coordinate<int>(0,1)).isMine);
                        REQUIRE_FALSE( sut.getField(helpers::Coordinate<int>(1,0)).isMine);
                        REQUIRE( sut.getField(helpers::Coordinate<int>(1,1)).isMine);
                    }
                }
            }
        }
        
    }
}

