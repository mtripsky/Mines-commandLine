//
//  MinesGeneratorTests.cpp
//  MinesTests
//
//  Created by Matej Tripsky on 06/04/2019.
//  Copyright © 2019 Matej Tripsky. All rights reserved.
//

#include <stdio.h>
#include "catch.hpp"
#include "fakeit.hpp"
#include "MinesGenerator.h"


namespace board{
namespace tests{

SCENARIO( "testing MinesGenerator" ) {
    GIVEN( "1x1 board" ) {
        auto sut = MinesGenerator();
        
        WHEN( "no mine to be generated" ) {
            auto result = sut.generateMines(1, 0);
            
            THEN( "it should return empty vector" ) {
                REQUIRE( result.size() == 0);
            }
        }
        
        WHEN( "one mine to be generated" ) {
            auto result = sut.generateMines(1, 1);
            
            THEN( "it should return coordinate (0,0)" ) {
                REQUIRE( result.front().X == 0);
                REQUIRE( result.front().Y == 0);
            }
        }
    }
    
    GIVEN( "3x3 board" ) {
        auto sut = MinesGenerator();
        
        WHEN( "no mine to be generated" ) {
            auto result = sut.generateMines(3, 0);
            
            THEN( "it should return empty vector" ) {
                REQUIRE( result.size() == 0);
            }
        }
        
        WHEN( "one mine to be generated" ) {
            auto result = sut.generateMines(3, 1);
            
            THEN( "it should return one coordinate " ) {
                REQUIRE( result.size() == 1);
            }
        }
        
        WHEN( "three mines to be generated" ) {
            auto result = sut.generateMines(3, 3);
            
            THEN( "it should return three unique coordinates" ) {
                REQUIRE( result.size() == 3);
                auto coord1 = result[0];
                auto coord2 = result[1];
                auto coord3 = result[2];
                auto num_coord1 = std::count(result.begin(), result.end(), coord1);
                auto num_coord2 = std::count(result.begin(), result.end(), coord2);
                auto num_coord3 = std::count(result.begin(), result.end(), coord3);
                REQUIRE( num_coord1 == 1);
                REQUIRE( num_coord2 == 1);
                REQUIRE( num_coord3 == 1);
            }
        }
    }
}

}
}
