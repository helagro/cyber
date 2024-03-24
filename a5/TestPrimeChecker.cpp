#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this once per test-runner!

#include "catch.hpp"
#include "PrimeChecker.hpp"

TEST_CASE("Test PrimeChecker Normal") {
    PrimeChecker pc;

    REQUIRE(!pc.isPrime(0));
    REQUIRE(!pc.isPrime(1));
    REQUIRE(pc.isPrime(5));
    REQUIRE(pc.isPrime(7));
}
