#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_3.h"



inline_response_200_3_t *inline_response_200_3_create(
    list_t *connections
    ) {
	inline_response_200_3_t *inline_response_200_3_local_var = malloc(sizeof(inline_response_200_3_t));
    if (!inline_response_200_3_local_var) {
        return NULL;
    }
	inline_response_200_3_local_var->connections = connections;

	return inline_response_200_3_local_var;
}


void inline_response_200_3_free(inline_response_200_3_t *inline_response_200_3) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200_3->connections) {
		network_connection_schema_free(listEntry->data);
	}
	list_free(inline_response_200_3->connections);
	free(inline_response_200_3);
}

cJSON *inline_response_200_3_convertToJSON(inline_response_200_3_t *inline_response_200_3) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_3->connections
    if(inline_response_200_3->connections) { 
    cJSON *connections = cJSON_AddArrayToObject(item, "connections");
    if(connections == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *connectionsListEntry;
    if (inline_response_200_3->connections) {
    list_ForEach(connectionsListEntry, inline_response_200_3->connections) {
    cJSON *itemLocal = network_connection_schema_convertToJSON(connectionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(connections, itemLocal);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_3_t *inline_response_200_3_parseFromJSON(cJSON *inline_response_200_3JSON){

    inline_response_200_3_t *inline_response_200_3_local_var = NULL;

    // inline_response_200_3->connections
    cJSON *connections = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "connections");
    list_t *connectionsList;
    if (connections) { 
    cJSON *connections_local_nonprimitive;
    if(!cJSON_IsArray(connections)){
        goto end; //nonprimitive container
    }

    connectionsList = list_create();

    cJSON_ArrayForEach(connections_local_nonprimitive,connections )
    {
        if(!cJSON_IsObject(connections_local_nonprimitive)){
            goto end;
        }
        network_connection_schema_t *connectionsItem = network_connection_schema_parseFromJSON(connections_local_nonprimitive);

        list_addElement(connectionsList, connectionsItem);
    }
    }


    inline_response_200_3_local_var = inline_response_200_3_create (
        connections ? connectionsList : NULL
        );

    return inline_response_200_3_local_var;
end:
    return NULL;

}
