//
//  BoardUpdaterTests.cpp
//  MinesTests
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#include <stdio.h>
#include "catch.hpp"
#include "fakeit.hpp"
#include "BoardUpdater.h"
#include "BoardState.h"

namespace board{
namespace tests{

SCENARIO( "testing BoardUpdater" ) {
    GIVEN( "2x2 board" ) {
        auto state = BoardState(2);
        auto sut = BoardUpdater<BoardState>(state);

        WHEN( "one bomb on Coordinate(0,1)" ) {
            const auto coordinate01 = helpers::Coordinate<int>(0,1);
            sut.update(coordinate01);
            
            THEN( "then it should update isBomb on (0,1) and counter on neighbors" ) {
                REQUIRE_FALSE( state.getField(helpers::Coordinate<int>(0,0)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,1)).isMine);
                REQUIRE_FALSE( state.getField(helpers::Coordinate<int>(1,0)).isMine);
                REQUIRE_FALSE( state.getField(helpers::Coordinate<int>(1,1)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,0)).neighboringMinesCounter == 1);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,1)).neighboringMinesCounter == 0);
                REQUIRE( state.getField(helpers::Coordinate<int>(1,0)).neighboringMinesCounter == 1);
                REQUIRE( state.getField(helpers::Coordinate<int>(1,1)).neighboringMinesCounter == 1);
            }
        }
        
        WHEN( "one bomb on Coordinate(0,1) and second on Coordinate(1,1)" ) {
            const auto coordinate01 = helpers::Coordinate<int>(0,1);
            sut.update(coordinate01);
            const auto coordinate11 = helpers::Coordinate<int>(1,1);
            sut.update(coordinate11);
            
            THEN( "then it should update isBomb on (0,1) and (1,1) and counter on neighbors" ) {
                REQUIRE_FALSE( state.getField(helpers::Coordinate<int>(0,0)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,1)).isMine);
                REQUIRE_FALSE( state.getField(helpers::Coordinate<int>(1,0)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(1,1)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,0)).neighboringMinesCounter == 2);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,1)).neighboringMinesCounter == 1);
                REQUIRE( state.getField(helpers::Coordinate<int>(1,0)).neighboringMinesCounter == 2);
                REQUIRE( state.getField(helpers::Coordinate<int>(1,1)).neighboringMinesCounter == 1);
            }
        }
    }
    
    GIVEN( "1x1 board" ) {
        auto state = BoardState(1);
        auto sut = BoardUpdater<BoardState>(state);

        WHEN( "bomb on coordinate(0,1) which is not on the board" ) {
            const auto coordinate01 = helpers::Coordinate<int>(0,1);
            sut.update(coordinate01);
            
            THEN( "then it should not update anything" ) {
                REQUIRE_FALSE( state.getField(helpers::Coordinate<int>(0,0)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,0)).neighboringMinesCounter == 0);
            }
        }
        
        WHEN( "bomb on Coordinate(0,0)" ) {
            const auto coordinate00 = helpers::Coordinate<int>(0,0);
            sut.update(coordinate00);
            
            THEN( "then it should update isBomb on (0,0)" ) {
                REQUIRE( state.getField(helpers::Coordinate<int>(0,0)).isMine);
                REQUIRE( state.getField(helpers::Coordinate<int>(0,0)).neighboringMinesCounter == 0);
            }
        }
    }
}

}
}
