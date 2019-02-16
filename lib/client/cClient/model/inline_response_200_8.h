/*
 * inline_response_200_8.h
 *
 * 
 */

#ifndef _inline_response_200_8_H_
#define _inline_response_200_8_H_

#include <string.h>
#include "cJSON.h"
#include "inline_response_200_8_data.h"
#include "object.h"




typedef struct inline_response_200_8_t {
        inline_response_200_8_data_t *data; //nonprimitive
        object_t *error; //nonprimitive

} inline_response_200_8_t;

inline_response_200_8_t *inline_response_200_8_create(
        inline_response_200_8_data_t *data,
        object_t *error
);

void inline_response_200_8_free(inline_response_200_8_t *inline_response_200_8);

inline_response_200_8_t *inline_response_200_8_parseFromJSON(char *jsonString);

cJSON *inline_response_200_8_convertToJSON(inline_response_200_8_t *inline_response_200_8);

#endif /* _inline_response_200_8_H_ */

