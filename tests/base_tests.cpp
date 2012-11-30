#include "tests.h"

TEST_GROUP(base_tests) {

};

TEST(base_tests, sizeofs) {
	CHECK(sizeof(void*) >= sizeof(int));
}
