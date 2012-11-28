/*
 * collections_slist.h
 *
 * Single linked list
 *
 *  Created on: 28.11.2012
 *      Author: Anatoly Galiulin
 */

#ifndef COLLECTIONS_SLIST_H_
#define COLLECTIONS_SLIST_H_

#include <stddef.h>

#include "collections_base.h"

/**
 * Create single linked list
 * @param data	First node's value
 * @return	Pointer to the head of the list
 */
extern c_slist_node_t* c_slist_create(void *data);

/**
 * Destroy single linked list
 * @param l
 * @param d
 */
extern void c_slist_destroy(c_slist_node_t* l, c_destructor_t d);

/**
 * Add data to the end of the list
 * @param l
 * @param data
 * @return Possible new head of the list
 */
extern c_slist_node_t* c_slist_append(c_slist_node_t *l, void *data);

/**
 * Add data to the head of the list
 * @param l
 * @param data
 * @return Possible new head of the list
 */
extern c_slist_node_t* c_slist_prepend(c_slist_node_t *l, void *data);

/**
 * Delete head of the list
 * @param l
 * @param d
 * @return Possible new head of the list
 */
extern c_slist_node_t* c_slist_remove_first(c_slist_node_t *l, c_destructor_t d);

/**
 * Delete last element of the list
 * @param l
 * @param d
 * @return Possible new head of the list
 */
extern c_slist_node_t* c_slist_remove_last(c_slist_node_t *l, c_destructor_t d);

/**
 * @brief Constant iterator function for single list
 *
 * Constant iterator can't be used for removing elements from list
 *
 * @param l	Current node
 * @param it_data	Data passed to iteration cycle
 * @return c_true for continue, or c_false for stop
 */
typedef c_bool (*c_slist_citerator_t)(c_slist_node_t *l, void *it_data);

/**
 * Iterate over single linked list
 * @param l	list
 * @param it	iterator function
 * @param it_data	data to pass to iterator function
 * @return c_true if iterator processed all elements of the list
 */
extern c_bool c_slist_const_iterate(c_slist_node_t *l, c_slist_citerator_t it, void *it_data);

#endif /* COLLECTIONS_SLIST_H_ */
