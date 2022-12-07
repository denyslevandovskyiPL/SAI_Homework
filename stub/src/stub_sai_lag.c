#include "sai.h"
#include "stub_sai.h"
#include "assert.h"
#define MAX_NUMBER_OF_LAG_MEMBERS 16
#define MAX_NUMBER_OF_LAGS 5

typedef struct _lag_member_db_entry_t {
    bool            is_used;
    sai_object_id_t port_oid;
    sai_object_id_t lag_oid;
} lag_member_db_entry_t;

typedef struct _lag_db_entry_t {
    bool            is_used;
    sai_object_id_t members_ids[MAX_NUMBER_OF_LAG_MEMBERS];
} lag_db_entry_t;

struct lag_db_t {
    lag_db_entry_t        lags[MAX_NUMBER_OF_LAGS];
    lag_member_db_entry_t members[MAX_NUMBER_OF_LAG_MEMBERS];
} lag_db;


sai_status_t get_lag_member_attribute(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg)
{
    uint32_t     db_index;
    sai_status_t status;

    assert((SAI_LAG_MEMBER_ATTR_LAG_ID == (int64_t)arg)||(SAI_LAG_MEMBER_ATTR_PORT_ID == (int64_t)arg));

    status = stub_object_to_type(key->object_id, SAI_OBJECT_TYPE_LAG_MEMBER, &db_index);

    if (status != SAI_STATUS_SUCCESS) {
        printf("Cannot get LAG DB index.\n");
        return status;

    }
    switch ((int64_t)arg) {
    case SAI_LAG_MEMBER_ATTR_LAG_ID:
        value->oid = lag_db.members[db_index].lag_oid;
        break;
    case SAI_LAG_MEMBER_ATTR_PORT_ID:
	value->oid = lag_db.members[db_index].port_oid;
	break;
    default:
        printf("Got unexpected attribute ID\n");
        return SAI_STATUS_FAILURE;
    }
    return SAI_STATUS_SUCCESS;
}

sai_status_t get_lag_attribute(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg)
{
    uint32_t     db_index;
    sai_status_t status;

    assert((SAI_LAG_ATTR_PORT_LIST == (int64_t)arg));

    status = stub_object_to_type(key->object_id, SAI_OBJECT_TYPE_LAG, &db_index);

    if (status != SAI_STATUS_SUCCESS) {
        printf("Cannot get LAG DB index.\n");
        return status;

    }
   
    int j = 0;
    value->objlist.count = 0;
    uint32_t member_id;
    
    switch ((int64_t)arg) {
    case SAI_LAG_ATTR_PORT_LIST:
	for (int i = 0; i < MAX_NUMBER_OF_LAG_MEMBERS; i++){
		status = stub_object_to_type(lag_db.lags[db_index].members_ids[i], SAI_OBJECT_TYPE_LAG_MEMBER, &member_id);
		if (status != SAI_STATUS_SUCCESS){
			continue;
		}
		if (lag_db.members[member_id].is_used)
		{
			value->objlist.list[j] = lag_db.members[i].port_oid;
			j++;
			value->objlist.count++;
		}
	}	
        break;
    default:
        printf("Got unexpected attribute ID\n");
        return SAI_STATUS_FAILURE;
    }
    return SAI_STATUS_SUCCESS;
}


static const sai_attribute_entry_t lag_attribs[] = {

    { SAI_LAG_ATTR_PORT_LIST, true, false, false, true,

      "List of ports in LAG", SAI_ATTR_VAL_TYPE_OBJLIST },

    { END_FUNCTIONALITY_ATTRIBS_ID, false, false, false, false,

      "", SAI_ATTR_VAL_TYPE_UNDETERMINED }

};

static const sai_vendor_attribute_entry_t lag_vendor_attribs[] = {

    { SAI_LAG_ATTR_PORT_LIST,

      { true, false, false, true },

      { true, false, false, true },

      get_lag_attribute, (void*) SAI_LAG_ATTR_PORT_LIST,

      NULL, NULL },
};

static const sai_vendor_attribute_entry_t lag_member_vendor_attribs[] = {

    { SAI_LAG_MEMBER_ATTR_LAG_ID,

      { true, false, false, true },

      { true, false, false, true },

      get_lag_member_attribute, (void*) SAI_LAG_MEMBER_ATTR_LAG_ID,

      NULL, NULL },

    { SAI_LAG_MEMBER_ATTR_PORT_ID,

      { true, false, false, true },

      { true, false, false, true },

      get_lag_member_attribute, (void*) SAI_LAG_MEMBER_ATTR_PORT_ID,

      NULL, NULL }

};

static const sai_attribute_entry_t lag_member_attribs[] = {

    { SAI_LAG_MEMBER_ATTR_LAG_ID, true, true, false, true,

      "LAG ID", SAI_ATTR_VAL_TYPE_OID },

    { SAI_LAG_MEMBER_ATTR_PORT_ID, true, true, false, true,

      "PORT ID", SAI_ATTR_VAL_TYPE_OID },

    { END_FUNCTIONALITY_ATTRIBS_ID, false, false, false, false,

      "", SAI_ATTR_VAL_TYPE_UNDETERMINED }

};

sai_status_t stub_create_lag(
    _Out_ sai_object_id_t* lag_id,
    _In_ uint32_t attr_count,
    _In_ sai_attribute_t *attr_list)
{
	sai_status_t status;

	uint32_t ii = 0;
	
	for (; ii < MAX_NUMBER_OF_LAGS; ii++) {
		if (!lag_db.lags[ii].is_used) {
			break;
		}
	}

	if (ii == MAX_NUMBER_OF_LAGS) {
		printf("Cannot create LAG: limit is reached\n");
		return SAI_STATUS_FAILURE;
	}

	uint32_t lag_db_id = ii;
	lag_db.lags[lag_db_id].is_used = true;	
	status = stub_create_object(SAI_OBJECT_TYPE_LAG, lag_db_id, lag_id);
	if (status != SAI_STATUS_SUCCESS) {
	    printf("Cannot create a LAG OID\n");
	    return status;
	}
	printf("CREATE LAG: 0x%lX\n", *lag_id);
	return SAI_STATUS_SUCCESS;
}

sai_status_t stub_remove_lag(
    _In_ sai_object_id_t  lag_id)
{
	uint32_t     lag_member_id;
	uint32_t     lag_db_id;
	sai_status_t status;

	status = stub_object_to_type(lag_id, SAI_OBJECT_TYPE_LAG, &lag_db_id);
	if (status != SAI_STATUS_SUCCESS) {
		printf("Cannot get LAG DB ID.\n");
		return status;
	}
	for (int i = 0; i < MAX_NUMBER_OF_LAG_MEMBERS; i++){
		status = stub_object_to_type(lag_db.lags[lag_db_id].members_ids[i], SAI_OBJECT_TYPE_LAG_MEMBER, &lag_member_id);
		if (status != SAI_STATUS_SUCCESS){
			continue;
		}
		if (lag_db.members[lag_member_id].is_used){
			printf("Cannot delete LAG: lag members list is not empty\n");
			return SAI_STATUS_FAILURE;
		}
	}

	lag_db.lags[lag_db_id].is_used = false;
	memset(lag_db.lags[lag_db_id].members_ids, 0, sizeof(lag_db.lags[lag_db_id].members_ids));
	printf("REMOVE LAG: 0x%lX\n", lag_id);
	return SAI_STATUS_SUCCESS;
}


sai_status_t stub_set_lag_attribute(
    _In_ sai_object_id_t  lag_id,
    _In_ const sai_attribute_t *attr)
{
    printf("SET LAG ATTRIBUTE: 0x%lX\n", lag_id);
    return SAI_STATUS_SUCCESS;
}



sai_status_t stub_get_lag_attribute(
    _In_ sai_object_id_t lag_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list)
{
	const sai_object_key_t key = { .object_id = lag_id };
	return sai_get_attributes(&key, NULL, lag_attribs, lag_vendor_attribs, attr_count, attr_list);
}

sai_status_t stub_create_lag_member(
    _Out_ sai_object_id_t* lag_member_id,
    _In_ uint32_t attr_count,
    _In_ sai_attribute_t *attr_list)
{
	sai_status_t status;
        uint32_t ii = 0;
	
	status = check_attribs_metadata(attr_count, attr_list, lag_member_attribs, lag_member_vendor_attribs, SAI_OPERATION_CREATE);
	if (status != SAI_STATUS_SUCCESS) {
    		printf("Failed attributes check\n");
    		return status;
	}
        for (; ii < MAX_NUMBER_OF_LAG_MEMBERS; ii++) {
                if (!lag_db.members[ii].is_used) {
                        break;
                }
        }
	
        if (ii == MAX_NUMBER_OF_LAGS) {
                printf("Cannot create LAG member: limit is reached\n");
                return SAI_STATUS_FAILURE;
        }

	uint32_t lag_mem_db_id = ii;
        status = stub_create_object(SAI_OBJECT_TYPE_LAG_MEMBER, lag_mem_db_id, lag_member_id);
        if (status != SAI_STATUS_SUCCESS) {
            printf("Cannot create a LAG MEMBER OID\n");
            return status;
        }

	uint32_t db_index;
	status = stub_object_to_type(attr_list[1].value.oid, SAI_OBJECT_TYPE_LAG, &db_index);
	lag_db.lags[db_index].members_ids[lag_mem_db_id] = *lag_member_id;
        lag_db.members[lag_mem_db_id].is_used = true;
        lag_db.members[lag_mem_db_id].port_oid = attr_list[0].value.oid;
        lag_db.members[lag_mem_db_id].lag_oid = attr_list[1].value.oid;
	
        printf("CREATE LAG MEMBER: 0x%lX (PORT = %lX, LAG = %lX)\n",
			*lag_member_id,
			lag_db.members[lag_mem_db_id].port_oid,
			lag_db.members[lag_mem_db_id].lag_oid);
        return SAI_STATUS_SUCCESS;
}

sai_status_t stub_remove_lag_member(
    _In_ sai_object_id_t  lag_member_id)
{
	sai_status_t status;
	uint32_t lag_member_db_id;

	status = stub_object_to_type(lag_member_id, SAI_OBJECT_TYPE_LAG_MEMBER, &lag_member_db_id);
	if (status != SAI_STATUS_SUCCESS) {
    		printf("Cannot get LAG DB ID.\n");
    		return status;
	}
	lag_db.members[lag_member_db_id].is_used = false;
	printf("REMOVE LAG MEMBER: 0x%lX\n", lag_member_id);
	return SAI_STATUS_SUCCESS;
}

sai_status_t stub_set_lag_member_attribute(
    _In_ sai_object_id_t  lag_member_id,
    _In_ const sai_attribute_t *attr)
{
    printf("SET LAG MEMBER ATTRIBUTE: 0x%lX\n", lag_member_id);
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_get_lag_member_attribute(
    _In_ sai_object_id_t lag_member_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list)
{
	const sai_object_key_t key = { .object_id = lag_member_id };
	return sai_get_attributes(&key, NULL, lag_member_attribs, lag_member_vendor_attribs, attr_count, attr_list);
}

const sai_lag_api_t lag_api = {
    stub_create_lag,
    stub_remove_lag,
    stub_set_lag_attribute,
    stub_get_lag_attribute,
    stub_create_lag_member,
    stub_remove_lag_member,
    stub_set_lag_member_attribute,
    stub_get_lag_member_attribute
};
