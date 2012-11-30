#include "tests.h"

#define WORD1 "Hello, "
#define WORD2 "world"
#define WORD3 "!"

TEST_GROUP(slist_interface) {
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

TEST(slist_interface, create_and_destroy) {
	c_slist_node_t *list = c_slist_create(strdup("Hello"));
	list = c_slist_append(list, strdup("world"));

	c_slist_destroy(list, free);
}

static c_bool count_chars(c_slist_node_t *n, void *data) {
	int *cc = (int *) data;

	*cc += strlen((char *) n->data);

	return c_true;
}

static c_bool concat_nodes(c_slist_node_t *n, void *data) {
	strcat((char *) data, (char *) n->data);

	return true;
}

TEST(slist_interface, iterate) {
	int cc = 1;
	c_slist_const_iterate(list, count_chars, &cc);

	char *res = (char *) malloc(cc);
	res[0] = 0;
	c_slist_const_iterate(list, concat_nodes, res);

	STRCMP_EQUAL(WORD1 WORD2 WORD3, res);

	free(res);
}

TEST(slist_interface, append_and_prepend) {
	c_slist_node_t *list = c_slist_create(C_INT_TO_PTR(1));
	list = c_slist_append(list, C_INT_TO_PTR(2));
	list = c_slist_prepend(list, C_INT_TO_PTR(0));

	c_slist_node_t *c = list;
	int i = 0;

	for(; c != NULL; i++, c = c->next) {
		CHECK_EQUAL_C_INT(i, C_PTR_TO_INT(c->data));
	}

	c_slist_destroy(list, NULL);
}
