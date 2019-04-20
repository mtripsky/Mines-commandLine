//
//  BoardStateTests.cpp
//  Mines
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#include <stdio.h>
#include "../libs/catch.hpp"
#include "../libs/fakeit.hpp"
#include "../../src/Board/BoardState.h"
#include "../../src/Helpers/Coordinate.h"
#include "../../src/Board/Cell.h"


namespace board{
    namespace tests{

        SCENARIO( "testing board state" ) {
            GIVEN( "board size 2" ) {

                WHEN( "state is initialized" ) {
                    auto sut = BoardState(2);

                    THEN( "then all neighbor counters should be zero" ) {
                        REQUIRE( sut.getCell(helpers::Coordinate<int>(0,0)).neighboringMinesCounter == 1 );
                        REQUIRE( sut.getCell(helpers::Coordinate<int>(0,1)).neighboringMinesCounter == 0 );
                        REQUIRE( sut.getCell(helpers::Coordinate<int>(1,0)).neighboringMinesCounter == 0 );
                        REQUIRE( sut.getCell(helpers::Coordinate<int>(1,1)).neighboringMinesCounter == 0 );
                    }
                }

                WHEN( "state is initialized and we change Cell(1,1).isBomb = true" ) {
                    auto sut = BoardState(2);

                    sut.setCell(helpers::Coordinate<int>(1,1)).isMine = true;

                    THEN( "then all Cell should have isBomb false except Cell(1,1)" ) {
                        REQUIRE_FALSE( sut.getCell(helpers::Coordinate<int>(0,0)).isMine);
                        REQUIRE_FALSE( sut.getCell(helpers::Coordinate<int>(0,1)).isMine);
                        REQUIRE_FALSE( sut.getCell(helpers::Coordinate<int>(1,0)).isMine);
                        REQUIRE( sut.getCell(helpers::Coordinate<int>(1,1)).isMine);
                    }
                }
            }
        }

    }
}
