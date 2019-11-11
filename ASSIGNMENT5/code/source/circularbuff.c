/*
 * circularbuff.c
 *
 *  Created on: Nov 9, 2019
 *      Author: SURAJ THITE
 */

#include "circularbuff.h"
/*******************************************************************************************************
 * Function Name: cbuff_init(cbuff* ptr,uint16_t length)
 * Description : This function initializes the circular buffer
 * @input: pointer to a structure , length of circular buffer to be initialized
 * @Return : status codes
 *******************************************************************************************************/

int8_t cbuff_init(cbuff* ptr,uint16_t length)
{
	if(ptr->cbuffptr == NULL || length < 0)
	{
		return FAIL;
	}
	else
	{
		ptr->cbuffptr =(int8_t *)malloc(sizeof(int8_t)*length)
		ptr->head = ptr->buffer;
		ptr->tail = ptr->buffer;
		ptr->size = length;
		ptr->count = 0;
		return Allocate_Free;
	}
}



/*******************************************************************************************************
 * Function Name:cbuff_is_full(cbuff* ptr)
 * Description : This function checks whether the circular buffer is full or not.
 * @input: pointer to a structure
 * @Return :status codes
 *******************************************************************************************************/

uint8_t cbuff_add(cbuff* ptr,uint8_t data)
{
	if(ptr ==NULL)
		return FAIL;
	else if(ptr->count ==ptr->size)
		return Over_Fill;
	else if(ptr->head == ptr->cbuffptr + ptr->size -1)
	{
		*ptr->head =add;
		ptr->head = ptr->cbuffptr;
		ptr->count++;
		return Wrap_Add;
	}
	else
	{
		*ptr ->head =add;
		ptr->head ++;
		ptr->count++;
		return Added;
	}
}


/*******************************************************************************************************
 * Function Name:cbuff_remove(cbuff* ptr,uint8_t* store)
 * Description : This function removes an element from the circular buffer and stores it in the pointer store passed as argument
 * @input: pointer to a structure , pointer to a location where data is to be stored.
 * @Return :status codes
 *******************************************************************************************************/

uint8_t cbuff_remove(cbuff* ptr,uint8_t* store)
{
	if(ptr==NULL)
		return FAIL;
	else if(cbuff_is_empty(ptr)== Buffer_Empty)
	{
		return Over_empty;
	}
	else if(ptr->tail ==ptr->cbuffptr + ptr->size -1)
	{
		store = *ptr->tail;
		ptr->tail = ptr->cbuffptr;
		ptr->count--;
		return Wrap_Remove;
	}
	else
	{
		store = *ptr->tail;
		ptr->tail++;
		ptr->count--;
		return Removed;
	}
}


/*******************************************************************************************************
 * Function Name:cbuff_is_full(cbuff* ptr)
 * Description : This function checks whether the circular buffer is full or not.
 * @input: pointer to a structure
 * @Return :status codes
 *******************************************************************************************************/
uint8_t cbuff_is_full(cbuff* ptr)
{
	if(ptr==NULL)
	{	return FAIL;	}
	else if (ptr->count == ptr->size)
	{	return Buffer_Full;	}
	else
	{	return Buffer_Not_Full;	}
}

/*******************************************************************************************************
 * Function Name: cbuff_is_empty(cbuff* ptr)
 * Description : This function checks whether the buffer is empty or not
 * @input: pointer to a structure
 * @Return :status codes
 *******************************************************************************************************/

uint8_t cbuff_is_empty(cbuff* ptr)
{
	if(ptr==NULL)
		return FAIL;
	else if(ptr->count ==0)
	{
		return Buffer_Empty;
	}
	else
	{
		return Buffer_Not_Empty;
	}
}

/*******************************************************************************************************
 * Function Name: cbuff_destroy(cbuff* ptr)
 * Description : This function frees the memory allocated for circular buffer
 * @input: pointer to a structure
 * @Return : status codes
 *******************************************************************************************************/

uint8_t cbuff_destroy(cbuff* ptr)
{
	if(ptr ==NULL)
	{
		return FAIL;
	}
	else
	{
		free(ptr->cbuffptr);
		return Success;
	}
}

/*******************************************************************************************************
 * Function Name: cbuff_verify_init(cbuff* ptr)
 * Description : This function verifies whether pointer to cbuffer is initialized or not
 * @input: pointer to a structure
 * @Return : status codes
 *******************************************************************************************************/

uint8_t cbuff_verify_init(cbuff* ptr)
{

}


