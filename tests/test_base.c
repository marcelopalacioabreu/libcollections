#include <stdlib.h>
#include <stdio.h>
#include <collections.h>
#include <string.h>

c_bool iterate(c_slist_node_t *l, void* data) {
	puts((const char*)l->data);
	return c_true;
}

int test_slist() {
	c_slist_node_t *l = NULL;
	l = c_slist_append(l, strdup("Hello"));
	l = c_slist_append(l, strdup("world"));
	l = c_slist_append(l, strdup("!"));

	c_slist_const_iterate(l, iterate, NULL);

	c_slist_destroy(l, free);
}

int main(int argc, char **argv) {
	return test_slist() ? EXIT_SUCCESS : EXIT_FAILURE;
}
