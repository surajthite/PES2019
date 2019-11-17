/*
 * circularbuff.h
 *
 *  Created on: Nov 9, 2019
 *      Author: SURAJ THITE
 */

#ifndef CIRCULARBUFF_H_
#define CIRCULARBUFF_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "main.h"
typedef struct
{
	uint8_t *cbuffptr;
    uint8_t *newcbuffptr;
    uint8_t *head;
    uint8_t *tail;
    uint16_t size;
    uint8_t count;
}cbuff;


typedef enum
{
    cbuff_init_success,
    cbuff_init_fail,
    cbuff_empty,
    cbuff_not_empty,
    cbuff_full,
    cbuff_not_full,
    null_ptr,
    buffer_NA,
    cbuff_success
}cbuff_status;

cbuff_status cbuff_init(cbuff *ptr, uint16_t length);
cbuff_status cbuff_add(cbuff *ptr, uint8_t val);
cbuff_status cbuff_delete(cbuff *ptr, uint8_t *val);
cbuff_status cbuff_isempty(cbuff *ptr);
cbuff_status cbuff_check_full(cbuff *ptr);
cbuff_status cbuff_resize(cbuff *ptr,uint8_t length);
void cbuff_print(cbuff* ptr);

#endif /* CIRCULARBUFF_H_ */
