#include <stdio.h>
#include "sai.h"



const char* test_profile_get_value(
    _In_ sai_switch_profile_id_t profile_id,
    _In_ const char* variable)
{
    return 0;
}


int test_profile_get_next_value(
    _In_ sai_switch_profile_id_t profile_id,
    _Out_ const char** variable,
    _Out_ const char** value)
{
    return -1;
}


const service_method_table_t test_services = {
    test_profile_get_value,
    test_profile_get_next_value
};


void print_port_list(sai_lag_api_t *lag_api, sai_object_id_t lag_oid){
	sai_attribute_t		output[2];
	sai_object_id_t		port_list[16];

	
    	output[0].id = SAI_LAG_ATTR_PORT_LIST;
    	output[0].value.objlist.list = port_list;
	lag_api->get_lag_attribute(lag_oid, 1, output);
	if (output[0].value.objlist.count == 0)
		printf("LAG port list is empty\n");
	printf("GET LAG 0x%lX PORT LIST. PORTS[ ", lag_oid);
	for (int i = 0; i < output[0].value.objlist.count; i++){
		printf("0x%lX, ", output[0].value.objlist.list[i]);
	}
	printf("]\n");
}

int main()
{
    sai_status_t              status;
    sai_object_id_t           port_list[64];
    sai_lag_api_t 	     *lag_api;
    sai_object_id_t           lag_oid;
    sai_object_id_t           lag_oid2;
    sai_object_id_t           member_oid;
    sai_object_id_t           member_oid2;
    sai_object_id_t           member_oid3;
    sai_object_id_t           member_oid4;
    sai_switch_api_t         *switch_api;
    sai_attribute_t           switch_attrs[2];
    sai_attribute_t           lag_attrs[2];
    sai_attribute_t		output[2];
    sai_switch_notification_t notifications;

    status = sai_api_initialize(0, &test_services);

    status = sai_api_query(SAI_API_SWITCH, (void**)&switch_api);
    status = switch_api->initialize_switch(0, "HW_ID", 0, &notifications);
    switch_attrs[0].id = SAI_SWITCH_ATTR_PORT_LIST;
    switch_attrs[0].value.objlist.list = port_list;
    switch_attrs[0].value.objlist.count = 64;
    status = switch_api->get_switch_attribute(1, switch_attrs);
    status = sai_api_query(SAI_API_LAG, (void**)&lag_api);
    if (status != SAI_STATUS_SUCCESS) {
    	printf("Failed to query LAG API, status=%d\n", status);
    	return 1;
    }


    //create lag 1
    status = lag_api->create_lag(&lag_oid, 0, NULL);
    if (status != SAI_STATUS_SUCCESS) {
         printf("Failed to create a LAG, status=%d\n", status);
         return 1;
    }

    lag_attrs[0].id = SAI_LAG_MEMBER_ATTR_PORT_ID;
    lag_attrs[0].value.oid = port_list[0];
    lag_attrs[1].id = SAI_LAG_MEMBER_ATTR_LAG_ID;
    lag_attrs[1].value.oid = lag_oid;

    //create lag members 1 and 2
    status = lag_api->create_lag_member(&member_oid, 2, lag_attrs);
    lag_attrs[0].value.oid = port_list[1];
    status = lag_api->create_lag_member(&member_oid2, 2, lag_attrs);

    //create lag 2
    status = lag_api->create_lag(&lag_oid2, 0, NULL);


    //create lag member 3 and 4
    lag_attrs[0].value.oid = port_list[2];
    lag_attrs[1].value.oid = lag_oid2;
    status = lag_api->create_lag_member(&member_oid3, 2, lag_attrs);
    lag_attrs[0].value.oid = port_list[3];
    status = lag_api->create_lag_member(&member_oid4, 2, lag_attrs);

    //get port list from lag 1
    print_port_list(lag_api, lag_oid);
    //get port list from lag 2
    print_port_list(lag_api, lag_oid2);
    
    //get lag id from lag member 1
    output[0].id = SAI_LAG_MEMBER_ATTR_LAG_ID;
    status = lag_api->get_lag_member_attribute(member_oid, 1, output);

    printf("GET LAG MEMBER 1. LAG ID = 0x%lX\n", output[0].value.oid);

    //get port id from lag member 3
    output[0].id = SAI_LAG_MEMBER_ATTR_PORT_ID;
    status = lag_api->get_lag_member_attribute(member_oid3, 1, output);

    printf("GET LAG MEMBER 3. PORT ID = 0x%lX\n", output[0].value.oid);

    status = lag_api->remove_lag_member(member_oid2);

    //get port list from lag 1
    print_port_list(lag_api, lag_oid);


    status = lag_api->remove_lag_member(member_oid3);
    //get port list from lag 2
    print_port_list(lag_api, lag_oid2);
    status = lag_api->remove_lag_member(member_oid);
    status = lag_api->remove_lag_member(member_oid4);
    status = lag_api->remove_lag(lag_oid2);
    status = lag_api->remove_lag(lag_oid);





    switch_api->shutdown_switch(0);
    status = sai_api_uninitialize();

    return 0;
}
