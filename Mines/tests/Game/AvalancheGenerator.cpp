//
//  AvalancheGenerator.cpp
//  MinesTests
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#include <stdio.h>
#include "catch.hpp"
#include "fakeit.hpp"
#include "BoardState.h"
#include "AvalancheGenerator.h"


namespace game{
namespace tests{
        
SCENARIO( "testing AvalancheGenerator generate" ) {
    GIVEN( "2x2 board with 1 field with non zero neighboringMinesCounter" ) {
        auto state = board::BoardState(4);
        state.setField(0,1).neighboringMinesCounter = 1;
        state.setField(1,0).neighboringMinesCounter = 1;
        state.setField(1,1).neighboringMinesCounter = 1;
        auto sut = AvalancheGenerator<board::BoardState>(state);
        
        WHEN( "when starting at (0,0)" ) {
            sut.generate(helpers::Coordinate<int>(0,0));
            
            THEN( "it should reveal all fields except (1,1)" ) {
                REQUIRE( state.getField(0,0).isRevealed);
                REQUIRE( state.getField(0,1).isRevealed);
                REQUIRE( state.getField(1,0).isRevealed);
                REQUIRE_FALSE( state.getField(1,1).isRevealed);
            }
        }
        
        WHEN( "when starting at (1,1)" ) {
            sut.generate(helpers::Coordinate<int>(1,1));
            
            THEN( "it should reveal all fields except (0,0)" ) {
                REQUIRE_FALSE( state.getField(0,0).isRevealed);
                REQUIRE( state.getField(0,1).isRevealed);
                REQUIRE( state.getField(1,0).isRevealed);
                REQUIRE( state.getField(1,1).isRevealed);
            }
        }
    }
    
    GIVEN( "3x3 board with 3 fields with non zero neighboringMinesCounter" ) {
        auto state = board::BoardState(3);
        state.setField(0,1).neighboringMinesCounter = 1;
        state.setField(1,1).neighboringMinesCounter = 1;
        state.setField(2,2).neighboringMinesCounter = 1;
        auto sut = AvalancheGenerator<board::BoardState>(state);

        WHEN( "when starting at (0,0)" ) {
            sut.generate(helpers::Coordinate<int>(0,0));

            THEN( "it should reveal (0,0),(0,1),(1,0),(1,1),(2,0),(2,1),(2,2) and rest should not" ) {
                REQUIRE( state.getField(0,0).isRevealed);
                REQUIRE( state.getField(0,1).isRevealed);
                REQUIRE( state.getField(1,0).isRevealed);
                REQUIRE( state.getField(1,1).isRevealed);
                REQUIRE( state.getField(2,0).isRevealed);
                REQUIRE( state.getField(2,1).isRevealed);
                REQUIRE( state.getField(2,2).isRevealed);
                REQUIRE_FALSE( state.getField(0,2).isRevealed);
                REQUIRE_FALSE( state.getField(1,2).isRevealed);
            }
        }

        WHEN( "when starting at (0,2)" ) {
            sut.generate(helpers::Coordinate<int>(0,2));

            THEN( "it should reveal (0,1),(0,2),(1,1),(1,2),(2,2) and rest should not" ) {
                REQUIRE_FALSE( state.getField(0,0).isRevealed);
                REQUIRE( state.getField(0,1).isRevealed);
                REQUIRE_FALSE( state.getField(1,0).isRevealed);
                REQUIRE( state.getField(1,1).isRevealed);
                REQUIRE_FALSE( state.getField(2,0).isRevealed);
                REQUIRE_FALSE( state.getField(2,1).isRevealed);
                REQUIRE( state.getField(2,2).isRevealed);
                REQUIRE( state.getField(0,2).isRevealed);
                REQUIRE( state.getField(1,2).isRevealed);
            }
        }
    }
}

}
}

