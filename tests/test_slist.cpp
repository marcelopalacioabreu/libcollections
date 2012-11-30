#include "tests.h"

#define WORD1 "Hello, "
#define WORD2 "world"
#define WORD3 "!"

TEST_GROUP(list) {

	c_slist_node_t *list;

	void setup() {
		list = NULL;
		list = c_slist_append(list, strdup(WORD1));
		list = c_slist_append(list, strdup(WORD2));
		list = c_slist_append(list, strdup(WORD3));
	}

	void teardown() {
		c_slist_destroy(list, free);
	}
};

TEST(list, create_and_destroy) {
	c_slist_node_t* l = c_slist_create(strdup("Hello"));
	l = c_slist_append(l, strdup("world!"));
	c_slist_destroy(l, free);
}

c_bool count_chars(c_slist_node_t *n, void *data) {
	int *cc = (int *) data;

	*cc += strlen((char *) n->data);

	return c_true;
}

c_bool concat_nodes(c_slist_node_t *n, void *data) {
	strcat((char *) data, (char *) n->data);

	return true;
}

TEST(list, iterate) {
	int cc = 1;
	c_slist_const_iterate(list, count_chars, &cc);

	char *res = (char *) malloc(cc);
	res[0] = 0;
	c_slist_const_iterate(list, concat_nodes, res);

	STRCMP_EQUAL(WORD1 WORD2 WORD3, res);

	free(res);
}
