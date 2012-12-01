/*
 * collections_int.h
 *
 *  Created on: 30.11.2012
 *      Author: Anatoly Galiulin
 */

#ifndef COLLECTIONS_INT_H_
#define COLLECTIONS_INT_H_

#ifdef CPPUTEST_ENABLED
#include <CppUTest/MemoryLeakDetectorMallocMacros.h>
#endif

#include <collections.h>

typedef struct c_slist_node {

	struct c_slist_node *next;
	void *data;

} c_slist_node;

#define C_SLIST(v) ((c_slist_node*)v)

#endif /* COLLECTIONS_INT_H_ */
