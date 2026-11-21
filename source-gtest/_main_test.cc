#include <gtest/gtest.h>
#/*---*/
#

/**
 *
 set(CMAKE_CXX_STANDARD 20)
 ###
 # find_package()
 # > brew install googlet
 # > sudo dnf install gtest-devel gmock-devel
 # > sudo apt install libgtest-dev libgmock-dev
 ###
 find_package("GTest" QUIET CONFIG COMPONENTS "GTest" "GMock")
 link_libraries(
 	"ONLYTEST" "GTest::gtest"
 )
 *
 */

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
