/*
 * collections_base.h
 *
 * This file describes base definitions for collections library
 *
 *  Created on: 28.11.2012
 *      Author: Anatoly Galiulin
 */

#ifndef COLLECTIONS_BASE_H_
#define COLLECTIONS_BASE_H_

// Base types
typedef int c_bool;
#define c_false (0)
#define c_true  (!c_false)

/**
 * Destructor for some data
 */
typedef void (*c_destructor_t)(void *data);

/**
 * Single linked list node
 */
typedef struct c_slist_node_t {

	struct c_slist_node_t *next;
	void *data;

} c_slist_node_t;

/**
 * Possible actions for iterators
 */
enum c_iter_action_t {
	IT_NEXT, 		//!< Continue iteration
	IT_STOP,		//!< Stop iteration
	IT_REMOVE,		//!< Remove node and continue
	IT_REMOVE_STOP	//!< Remove node and stop iteration
};

#endif /* COLLECTIONS_BASE_H_ */
