/*
 * slist.c
 *
 * Single linked list
 *
 *  Created on: 28.11.2012
 *      Author: Anatoly Galiulin
 */

#include <collections_slist.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Initialize node values
 */
#define _coll_slist_init_node(n, next_, data_) { n->next = next_; n->data = data_; }

c_slist_node_t* c_slist_create(void *data) {
	c_slist_node_t *n = (c_slist_node_t*) malloc(
			sizeof(c_slist_node_t));

	_coll_slist_init_node(n, NULL, data);

	return n;
}

void c_slist_destroy(c_slist_node_t* l, c_destructor_t d) {
	while(l != NULL)
		l = c_slist_remove_first(l, d);
}

c_slist_node_t* c_slist_append(c_slist_node_t *l, void *data) {
	if (l == NULL)
		return c_slist_create(data);

	c_slist_node_t *c = l;

	while (c->next != NULL )
		c = c->next;

	c->next = c_slist_create(data);

	return l;
}

c_slist_node_t* c_slist_prepend(c_slist_node_t *l, void *data) {

	c_slist_node_t *n = c_slist_create(data);
	n->next = l;

	return n;
}

c_slist_node_t* c_slist_remove_first(c_slist_node_t *l, c_destructor_t d) {
	assert(l != NULL);

	if(d != NULL && l->data != NULL)
		d(l->data);

	c_slist_node_t *n = l->next;
	free(l);

	return n;
}

c_slist_node_t* c_slist_remove_last(c_slist_node_t *l, c_destructor_t d) {
	assert(l != NULL);

	c_slist_node_t *c = l, *p = NULL;

	while(c->next != NULL) {
		p = c;
		c = c->next;
	}

	if(d != NULL && c->data != NULL)
		d(c->data);
	free(c);
	if(p == NULL)
		return NULL;

	p->next = NULL;
	return l;
}

c_bool c_slist_const_iterate(c_slist_node_t *l, c_slist_citerator_t it, void *it_data) {
	while(l != NULL) {
		if(it(l, it_data) != c_true)
			return c_false;
		l = l->next;
	}

	return c_true;
}
