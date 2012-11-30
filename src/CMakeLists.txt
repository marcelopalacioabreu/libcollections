set(COLL_SRC	slist.c)

add_library(collections ${COLL_SRC})

if(${COLL_RUN_TESTS})
	target_link_libraries(collections CppUTest)
endif(${COLL_RUN_TESTS})
