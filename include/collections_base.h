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

#include <stdint.h>

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
typedef void *c_slist_node_t;

/**
 * Possible actions for iterators
 */
enum c_iter_action_t {
	IT_NEXT, 		//!< Continue iteration
	IT_STOP,		//!< Stop iteration
	IT_REMOVE,		//!< Remove node and continue
	IT_REMOVE_STOP	//!< Remove node and stop iteration
};

/**
 * Pointer to integer
 */
#define C_PTR_TO_INT(v) ((int)(intptr_t)v)

/**
 * Integer to pointer
 */
#define C_INT_TO_PTR(v) ((void *)v)

#endif /* COLLECTIONS_BASE_H_ */
