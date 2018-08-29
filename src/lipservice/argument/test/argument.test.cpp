#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying material numbers" ){
  argument::common::Matd mat;

  REQUIRE( mat.verify(1) );
  REQUIRE( not mat.verify(0) );
  REQUIRE( not mat.verify(10000) );

}
