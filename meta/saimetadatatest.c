#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saimetadata.h"
#define PP(x) printf("%p\n", (x));
#define TEST_ASSERT_TRUE(x,msg) if (!(x)){ fprintf(stderr, "ASSERT TRUE FAILED(%d): %s: %s\n", __LINE__, #x, msg); exit(1);}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wenum-conversion"
void non_object_id_test(void)
{
    sai_object_key_t ok;
    volatile void *p;
    p = &ok.key.fdb_entry;
    printf("fdb_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.fdb_entry, "member fdb_entry don't start at union begin! Standard C fail");
    p = &ok.key.inseg_entry;
    printf("inseg_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.inseg_entry, "member inseg_entry don't start at union begin! Standard C fail");
    p = &ok.key.ipmc_entry;
    printf("ipmc_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.ipmc_entry, "member ipmc_entry don't start at union begin! Standard C fail");
    p = &ok.key.l2mc_entry;
    printf("l2mc_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.l2mc_entry, "member l2mc_entry don't start at union begin! Standard C fail");
    p = &ok.key.mcast_fdb_entry;
    printf("mcast_fdb_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.mcast_fdb_entry, "member mcast_fdb_entry don't start at union begin! Standard C fail");
    p = &ok.key.my_sid_entry;
    printf("my_sid_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.my_sid_entry, "member my_sid_entry don't start at union begin! Standard C fail");
    p = &ok.key.nat_entry;
    printf("nat_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.nat_entry, "member nat_entry don't start at union begin! Standard C fail");
    p = &ok.key.neighbor_entry;
    printf("neighbor_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.neighbor_entry, "member neighbor_entry don't start at union begin! Standard C fail");
    p = &ok.key.route_entry;
    printf("route_entry: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.route_entry, "member route_entry don't start at union begin! Standard C fail");
    p = &ok.key.object_id;
    printf("object_id: "); PP(p);
    TEST_ASSERT_TRUE(&ok.key == (void*)&ok.key.object_id, "member object_id don't start at union begin! Standard C fail");
}
void switch_id_position_test(void)
{
    sai_fdb_entry_t fdb_entry = { 0 };
    TEST_ASSERT_TRUE(&fdb_entry == (void*)&fdb_entry.switch_id, "fdb_entry.switch_id is not at the struct beginning");
    sai_inseg_entry_t inseg_entry = { 0 };
    TEST_ASSERT_TRUE(&inseg_entry == (void*)&inseg_entry.switch_id, "inseg_entry.switch_id is not at the struct beginning");
    sai_ipmc_entry_t ipmc_entry = { 0 };
    TEST_ASSERT_TRUE(&ipmc_entry == (void*)&ipmc_entry.switch_id, "ipmc_entry.switch_id is not at the struct beginning");
    sai_l2mc_entry_t l2mc_entry = { 0 };
    TEST_ASSERT_TRUE(&l2mc_entry == (void*)&l2mc_entry.switch_id, "l2mc_entry.switch_id is not at the struct beginning");
    sai_mcast_fdb_entry_t mcast_fdb_entry = { 0 };
    TEST_ASSERT_TRUE(&mcast_fdb_entry == (void*)&mcast_fdb_entry.switch_id, "mcast_fdb_entry.switch_id is not at the struct beginning");
    sai_my_sid_entry_t my_sid_entry = { 0 };
    TEST_ASSERT_TRUE(&my_sid_entry == (void*)&my_sid_entry.switch_id, "my_sid_entry.switch_id is not at the struct beginning");
    sai_nat_entry_t nat_entry = { 0 };
    TEST_ASSERT_TRUE(&nat_entry == (void*)&nat_entry.switch_id, "nat_entry.switch_id is not at the struct beginning");
    sai_neighbor_entry_t neighbor_entry = { 0 };
    TEST_ASSERT_TRUE(&neighbor_entry == (void*)&neighbor_entry.switch_id, "neighbor_entry.switch_id is not at the struct beginning");
    sai_route_entry_t route_entry = { 0 };
    TEST_ASSERT_TRUE(&route_entry == (void*)&route_entry.switch_id, "route_entry.switch_id is not at the struct beginning");
}
void custom_range_test(void)
{
    TEST_ASSERT_TRUE(SAI_PORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for PORT");
    TEST_ASSERT_TRUE(SAI_PORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for PORT");
    TEST_ASSERT_TRUE(SAI_LAG_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for LAG");
    TEST_ASSERT_TRUE(SAI_LAG_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for LAG");
    TEST_ASSERT_TRUE(SAI_VIRTUAL_ROUTER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for VIRTUAL_ROUTER");
    TEST_ASSERT_TRUE(SAI_VIRTUAL_ROUTER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for VIRTUAL_ROUTER");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NEXT_HOP");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NEXT_HOP");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NEXT_HOP_GROUP");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NEXT_HOP_GROUP");
    TEST_ASSERT_TRUE(SAI_ROUTER_INTERFACE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ROUTER_INTERFACE");
    TEST_ASSERT_TRUE(SAI_ROUTER_INTERFACE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ROUTER_INTERFACE");
    TEST_ASSERT_TRUE(SAI_ACL_TABLE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ACL_TABLE");
    TEST_ASSERT_TRUE(SAI_ACL_TABLE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ACL_TABLE");
    TEST_ASSERT_TRUE(SAI_ACL_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ACL_ENTRY");
    TEST_ASSERT_TRUE(SAI_ACL_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ACL_ENTRY");
    TEST_ASSERT_TRUE(SAI_ACL_COUNTER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ACL_COUNTER");
    TEST_ASSERT_TRUE(SAI_ACL_COUNTER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ACL_COUNTER");
    TEST_ASSERT_TRUE(SAI_ACL_RANGE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ACL_RANGE");
    TEST_ASSERT_TRUE(SAI_ACL_RANGE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ACL_RANGE");
    TEST_ASSERT_TRUE(SAI_ACL_TABLE_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ACL_TABLE_GROUP");
    TEST_ASSERT_TRUE(SAI_ACL_TABLE_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ACL_TABLE_GROUP");
    TEST_ASSERT_TRUE(SAI_ACL_TABLE_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ACL_TABLE_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_ACL_TABLE_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ACL_TABLE_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_HOSTIF_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HOSTIF");
    TEST_ASSERT_TRUE(SAI_HOSTIF_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HOSTIF");
    TEST_ASSERT_TRUE(SAI_MIRROR_SESSION_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MIRROR_SESSION");
    TEST_ASSERT_TRUE(SAI_MIRROR_SESSION_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MIRROR_SESSION");
    TEST_ASSERT_TRUE(SAI_SAMPLEPACKET_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SAMPLEPACKET");
    TEST_ASSERT_TRUE(SAI_SAMPLEPACKET_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SAMPLEPACKET");
    TEST_ASSERT_TRUE(SAI_STP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for STP");
    TEST_ASSERT_TRUE(SAI_STP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for STP");
    TEST_ASSERT_TRUE(SAI_HOSTIF_TRAP_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HOSTIF_TRAP_GROUP");
    TEST_ASSERT_TRUE(SAI_HOSTIF_TRAP_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HOSTIF_TRAP_GROUP");
    TEST_ASSERT_TRUE(SAI_POLICER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for POLICER");
    TEST_ASSERT_TRUE(SAI_POLICER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for POLICER");
    TEST_ASSERT_TRUE(SAI_WRED_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for WRED");
    TEST_ASSERT_TRUE(SAI_WRED_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for WRED");
    TEST_ASSERT_TRUE(SAI_QOS_MAP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for QOS_MAP");
    TEST_ASSERT_TRUE(SAI_QOS_MAP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for QOS_MAP");
    TEST_ASSERT_TRUE(SAI_QUEUE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for QUEUE");
    TEST_ASSERT_TRUE(SAI_QUEUE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for QUEUE");
    TEST_ASSERT_TRUE(SAI_SCHEDULER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SCHEDULER");
    TEST_ASSERT_TRUE(SAI_SCHEDULER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SCHEDULER");
    TEST_ASSERT_TRUE(SAI_SCHEDULER_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SCHEDULER_GROUP");
    TEST_ASSERT_TRUE(SAI_SCHEDULER_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SCHEDULER_GROUP");
    TEST_ASSERT_TRUE(SAI_BUFFER_POOL_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for BUFFER_POOL");
    TEST_ASSERT_TRUE(SAI_BUFFER_POOL_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for BUFFER_POOL");
    TEST_ASSERT_TRUE(SAI_BUFFER_PROFILE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for BUFFER_PROFILE");
    TEST_ASSERT_TRUE(SAI_BUFFER_PROFILE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for BUFFER_PROFILE");
    TEST_ASSERT_TRUE(SAI_INGRESS_PRIORITY_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for INGRESS_PRIORITY_GROUP");
    TEST_ASSERT_TRUE(SAI_INGRESS_PRIORITY_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for INGRESS_PRIORITY_GROUP");
    TEST_ASSERT_TRUE(SAI_LAG_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for LAG_MEMBER");
    TEST_ASSERT_TRUE(SAI_LAG_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for LAG_MEMBER");
    TEST_ASSERT_TRUE(SAI_HASH_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HASH");
    TEST_ASSERT_TRUE(SAI_HASH_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HASH");
    TEST_ASSERT_TRUE(SAI_UDF_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for UDF");
    TEST_ASSERT_TRUE(SAI_UDF_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for UDF");
    TEST_ASSERT_TRUE(SAI_UDF_MATCH_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for UDF_MATCH");
    TEST_ASSERT_TRUE(SAI_UDF_MATCH_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for UDF_MATCH");
    TEST_ASSERT_TRUE(SAI_UDF_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for UDF_GROUP");
    TEST_ASSERT_TRUE(SAI_UDF_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for UDF_GROUP");
    TEST_ASSERT_TRUE(SAI_FDB_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for FDB_ENTRY");
    TEST_ASSERT_TRUE(SAI_FDB_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for FDB_ENTRY");
    TEST_ASSERT_TRUE(SAI_SWITCH_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SWITCH");
    TEST_ASSERT_TRUE(SAI_SWITCH_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SWITCH");
    TEST_ASSERT_TRUE(SAI_HOSTIF_TRAP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HOSTIF_TRAP");
    TEST_ASSERT_TRUE(SAI_HOSTIF_TRAP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HOSTIF_TRAP");
    TEST_ASSERT_TRUE(SAI_HOSTIF_TABLE_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HOSTIF_TABLE_ENTRY");
    TEST_ASSERT_TRUE(SAI_HOSTIF_TABLE_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HOSTIF_TABLE_ENTRY");
    TEST_ASSERT_TRUE(SAI_NEIGHBOR_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NEIGHBOR_ENTRY");
    TEST_ASSERT_TRUE(SAI_NEIGHBOR_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NEIGHBOR_ENTRY");
    TEST_ASSERT_TRUE(SAI_ROUTE_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ROUTE_ENTRY");
    TEST_ASSERT_TRUE(SAI_ROUTE_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ROUTE_ENTRY");
    TEST_ASSERT_TRUE(SAI_VLAN_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for VLAN");
    TEST_ASSERT_TRUE(SAI_VLAN_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for VLAN");
    TEST_ASSERT_TRUE(SAI_VLAN_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for VLAN_MEMBER");
    TEST_ASSERT_TRUE(SAI_VLAN_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for VLAN_MEMBER");
    TEST_ASSERT_TRUE(SAI_HOSTIF_PACKET_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HOSTIF_PACKET");
    TEST_ASSERT_TRUE(SAI_HOSTIF_PACKET_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HOSTIF_PACKET");
    TEST_ASSERT_TRUE(SAI_TUNNEL_MAP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TUNNEL_MAP");
    TEST_ASSERT_TRUE(SAI_TUNNEL_MAP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TUNNEL_MAP");
    TEST_ASSERT_TRUE(SAI_TUNNEL_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TUNNEL");
    TEST_ASSERT_TRUE(SAI_TUNNEL_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TUNNEL");
    TEST_ASSERT_TRUE(SAI_TUNNEL_TERM_TABLE_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TUNNEL_TERM_TABLE_ENTRY");
    TEST_ASSERT_TRUE(SAI_TUNNEL_TERM_TABLE_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TUNNEL_TERM_TABLE_ENTRY");
    TEST_ASSERT_TRUE(SAI_FDB_FLUSH_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for FDB_FLUSH");
    TEST_ASSERT_TRUE(SAI_FDB_FLUSH_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for FDB_FLUSH");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NEXT_HOP_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NEXT_HOP_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_STP_PORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for STP_PORT");
    TEST_ASSERT_TRUE(SAI_STP_PORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for STP_PORT");
    TEST_ASSERT_TRUE(SAI_RPF_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for RPF_GROUP");
    TEST_ASSERT_TRUE(SAI_RPF_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for RPF_GROUP");
    TEST_ASSERT_TRUE(SAI_RPF_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for RPF_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_RPF_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for RPF_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_L2MC_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for L2MC_GROUP");
    TEST_ASSERT_TRUE(SAI_L2MC_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for L2MC_GROUP");
    TEST_ASSERT_TRUE(SAI_L2MC_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for L2MC_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_L2MC_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for L2MC_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_IPMC_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for IPMC_GROUP");
    TEST_ASSERT_TRUE(SAI_IPMC_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for IPMC_GROUP");
    TEST_ASSERT_TRUE(SAI_IPMC_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for IPMC_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_IPMC_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for IPMC_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_L2MC_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for L2MC_ENTRY");
    TEST_ASSERT_TRUE(SAI_L2MC_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for L2MC_ENTRY");
    TEST_ASSERT_TRUE(SAI_IPMC_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for IPMC_ENTRY");
    TEST_ASSERT_TRUE(SAI_IPMC_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for IPMC_ENTRY");
    TEST_ASSERT_TRUE(SAI_MCAST_FDB_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MCAST_FDB_ENTRY");
    TEST_ASSERT_TRUE(SAI_MCAST_FDB_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MCAST_FDB_ENTRY");
    TEST_ASSERT_TRUE(SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for HOSTIF_USER_DEFINED_TRAP");
    TEST_ASSERT_TRUE(SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for HOSTIF_USER_DEFINED_TRAP");
    TEST_ASSERT_TRUE(SAI_BRIDGE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for BRIDGE");
    TEST_ASSERT_TRUE(SAI_BRIDGE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for BRIDGE");
    TEST_ASSERT_TRUE(SAI_BRIDGE_PORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for BRIDGE_PORT");
    TEST_ASSERT_TRUE(SAI_BRIDGE_PORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for BRIDGE_PORT");
    TEST_ASSERT_TRUE(SAI_TUNNEL_MAP_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TUNNEL_MAP_ENTRY");
    TEST_ASSERT_TRUE(SAI_TUNNEL_MAP_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TUNNEL_MAP_ENTRY");
    TEST_ASSERT_TRUE(SAI_TAM_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM");
    TEST_ASSERT_TRUE(SAI_TAM_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM");
    TEST_ASSERT_TRUE(SAI_SRV6_SIDLIST_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SRV6_SIDLIST");
    TEST_ASSERT_TRUE(SAI_SRV6_SIDLIST_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SRV6_SIDLIST");
    TEST_ASSERT_TRUE(SAI_PORT_POOL_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for PORT_POOL");
    TEST_ASSERT_TRUE(SAI_PORT_POOL_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for PORT_POOL");
    TEST_ASSERT_TRUE(SAI_INSEG_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for INSEG_ENTRY");
    TEST_ASSERT_TRUE(SAI_INSEG_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for INSEG_ENTRY");
    TEST_ASSERT_TRUE(SAI_DTEL_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for DTEL");
    TEST_ASSERT_TRUE(SAI_DTEL_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for DTEL");
    TEST_ASSERT_TRUE(SAI_DTEL_QUEUE_REPORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for DTEL_QUEUE_REPORT");
    TEST_ASSERT_TRUE(SAI_DTEL_QUEUE_REPORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for DTEL_QUEUE_REPORT");
    TEST_ASSERT_TRUE(SAI_DTEL_INT_SESSION_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for DTEL_INT_SESSION");
    TEST_ASSERT_TRUE(SAI_DTEL_INT_SESSION_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for DTEL_INT_SESSION");
    TEST_ASSERT_TRUE(SAI_DTEL_REPORT_SESSION_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for DTEL_REPORT_SESSION");
    TEST_ASSERT_TRUE(SAI_DTEL_REPORT_SESSION_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for DTEL_REPORT_SESSION");
    TEST_ASSERT_TRUE(SAI_DTEL_EVENT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for DTEL_EVENT");
    TEST_ASSERT_TRUE(SAI_DTEL_EVENT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for DTEL_EVENT");
    TEST_ASSERT_TRUE(SAI_BFD_SESSION_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for BFD_SESSION");
    TEST_ASSERT_TRUE(SAI_BFD_SESSION_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for BFD_SESSION");
    TEST_ASSERT_TRUE(SAI_ISOLATION_GROUP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ISOLATION_GROUP");
    TEST_ASSERT_TRUE(SAI_ISOLATION_GROUP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ISOLATION_GROUP");
    TEST_ASSERT_TRUE(SAI_ISOLATION_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for ISOLATION_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_ISOLATION_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for ISOLATION_GROUP_MEMBER");
    TEST_ASSERT_TRUE(SAI_TAM_MATH_FUNC_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_MATH_FUNC");
    TEST_ASSERT_TRUE(SAI_TAM_MATH_FUNC_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_MATH_FUNC");
    TEST_ASSERT_TRUE(SAI_TAM_REPORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_REPORT");
    TEST_ASSERT_TRUE(SAI_TAM_REPORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_REPORT");
    TEST_ASSERT_TRUE(SAI_TAM_EVENT_THRESHOLD_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_EVENT_THRESHOLD");
    TEST_ASSERT_TRUE(SAI_TAM_EVENT_THRESHOLD_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_EVENT_THRESHOLD");
    TEST_ASSERT_TRUE(SAI_TAM_TEL_TYPE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_TEL_TYPE");
    TEST_ASSERT_TRUE(SAI_TAM_TEL_TYPE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_TEL_TYPE");
    TEST_ASSERT_TRUE(SAI_TAM_TRANSPORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_TRANSPORT");
    TEST_ASSERT_TRUE(SAI_TAM_TRANSPORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_TRANSPORT");
    TEST_ASSERT_TRUE(SAI_TAM_TELEMETRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_TELEMETRY");
    TEST_ASSERT_TRUE(SAI_TAM_TELEMETRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_TELEMETRY");
    TEST_ASSERT_TRUE(SAI_TAM_COLLECTOR_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_COLLECTOR");
    TEST_ASSERT_TRUE(SAI_TAM_COLLECTOR_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_COLLECTOR");
    TEST_ASSERT_TRUE(SAI_TAM_EVENT_ACTION_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_EVENT_ACTION");
    TEST_ASSERT_TRUE(SAI_TAM_EVENT_ACTION_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_EVENT_ACTION");
    TEST_ASSERT_TRUE(SAI_TAM_EVENT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_EVENT");
    TEST_ASSERT_TRUE(SAI_TAM_EVENT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_EVENT");
    TEST_ASSERT_TRUE(SAI_NAT_ZONE_COUNTER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NAT_ZONE_COUNTER");
    TEST_ASSERT_TRUE(SAI_NAT_ZONE_COUNTER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NAT_ZONE_COUNTER");
    TEST_ASSERT_TRUE(SAI_NAT_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NAT_ENTRY");
    TEST_ASSERT_TRUE(SAI_NAT_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NAT_ENTRY");
    TEST_ASSERT_TRUE(SAI_TAM_INT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TAM_INT");
    TEST_ASSERT_TRUE(SAI_TAM_INT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TAM_INT");
    TEST_ASSERT_TRUE(SAI_COUNTER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for COUNTER");
    TEST_ASSERT_TRUE(SAI_COUNTER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for COUNTER");
    TEST_ASSERT_TRUE(SAI_DEBUG_COUNTER_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for DEBUG_COUNTER");
    TEST_ASSERT_TRUE(SAI_DEBUG_COUNTER_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for DEBUG_COUNTER");
    TEST_ASSERT_TRUE(SAI_PORT_CONNECTOR_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for PORT_CONNECTOR");
    TEST_ASSERT_TRUE(SAI_PORT_CONNECTOR_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for PORT_CONNECTOR");
    TEST_ASSERT_TRUE(SAI_PORT_SERDES_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for PORT_SERDES");
    TEST_ASSERT_TRUE(SAI_PORT_SERDES_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for PORT_SERDES");
    TEST_ASSERT_TRUE(SAI_MACSEC_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MACSEC");
    TEST_ASSERT_TRUE(SAI_MACSEC_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MACSEC");
    TEST_ASSERT_TRUE(SAI_MACSEC_PORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MACSEC_PORT");
    TEST_ASSERT_TRUE(SAI_MACSEC_PORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MACSEC_PORT");
    TEST_ASSERT_TRUE(SAI_MACSEC_FLOW_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MACSEC_FLOW");
    TEST_ASSERT_TRUE(SAI_MACSEC_FLOW_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MACSEC_FLOW");
    TEST_ASSERT_TRUE(SAI_MACSEC_SC_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MACSEC_SC");
    TEST_ASSERT_TRUE(SAI_MACSEC_SC_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MACSEC_SC");
    TEST_ASSERT_TRUE(SAI_MACSEC_SA_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MACSEC_SA");
    TEST_ASSERT_TRUE(SAI_MACSEC_SA_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MACSEC_SA");
    TEST_ASSERT_TRUE(SAI_SYSTEM_PORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SYSTEM_PORT");
    TEST_ASSERT_TRUE(SAI_SYSTEM_PORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SYSTEM_PORT");
    TEST_ASSERT_TRUE(SAI_FINE_GRAINED_HASH_FIELD_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for FINE_GRAINED_HASH_FIELD");
    TEST_ASSERT_TRUE(SAI_FINE_GRAINED_HASH_FIELD_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for FINE_GRAINED_HASH_FIELD");
    TEST_ASSERT_TRUE(SAI_SWITCH_TUNNEL_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for SWITCH_TUNNEL");
    TEST_ASSERT_TRUE(SAI_SWITCH_TUNNEL_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for SWITCH_TUNNEL");
    TEST_ASSERT_TRUE(SAI_MY_SID_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MY_SID_ENTRY");
    TEST_ASSERT_TRUE(SAI_MY_SID_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MY_SID_ENTRY");
    TEST_ASSERT_TRUE(SAI_MY_MAC_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for MY_MAC");
    TEST_ASSERT_TRUE(SAI_MY_MAC_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for MY_MAC");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_GROUP_MAP_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for NEXT_HOP_GROUP_MAP");
    TEST_ASSERT_TRUE(SAI_NEXT_HOP_GROUP_MAP_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for NEXT_HOP_GROUP_MAP");
    TEST_ASSERT_TRUE(SAI_IPSEC_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for IPSEC");
    TEST_ASSERT_TRUE(SAI_IPSEC_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for IPSEC");
    TEST_ASSERT_TRUE(SAI_IPSEC_PORT_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for IPSEC_PORT");
    TEST_ASSERT_TRUE(SAI_IPSEC_PORT_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for IPSEC_PORT");
    TEST_ASSERT_TRUE(SAI_IPSEC_SA_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for IPSEC_SA");
    TEST_ASSERT_TRUE(SAI_IPSEC_SA_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for IPSEC_SA");
    TEST_ASSERT_TRUE(SAI_GENERIC_PROGRAMMABLE_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for GENERIC_PROGRAMMABLE");
    TEST_ASSERT_TRUE(SAI_GENERIC_PROGRAMMABLE_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for GENERIC_PROGRAMMABLE");
    TEST_ASSERT_TRUE(SAI_TABLE_BITMAP_CLASSIFICATION_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TABLE_BITMAP_CLASSIFICATION_ENTRY");
    TEST_ASSERT_TRUE(SAI_TABLE_BITMAP_CLASSIFICATION_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TABLE_BITMAP_CLASSIFICATION_ENTRY");
    TEST_ASSERT_TRUE(SAI_TABLE_BITMAP_ROUTER_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TABLE_BITMAP_ROUTER_ENTRY");
    TEST_ASSERT_TRUE(SAI_TABLE_BITMAP_ROUTER_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TABLE_BITMAP_ROUTER_ENTRY");
    TEST_ASSERT_TRUE(SAI_TABLE_META_TUNNEL_ENTRY_ATTR_CUSTOM_RANGE_START == 0x10000000, "invalid custom range start for TABLE_META_TUNNEL_ENTRY");
    TEST_ASSERT_TRUE(SAI_TABLE_META_TUNNEL_ENTRY_ATTR_CUSTOM_RANGE_END > 0x10000000, "invalid custom range end for TABLE_META_TUNNEL_ENTRY");
}
void check_pointer_names_test(void)
{
    sai_bfd_session_state_change_notification_fn var_sai_bfd_session_state_change_notification_fn = NULL;
    PP(var_sai_bfd_session_state_change_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_BFD_SESSION_STATE_CHANGE_NOTIFY);
    sai_fdb_event_notification_fn var_sai_fdb_event_notification_fn = NULL;
    PP(var_sai_fdb_event_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_FDB_EVENT_NOTIFY);
    sai_ipsec_sa_status_change_notification_fn var_sai_ipsec_sa_status_change_notification_fn = NULL;
    PP(var_sai_ipsec_sa_status_change_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_IPSEC_SA_STATUS_CHANGE_NOTIFY);
    sai_nat_event_notification_fn var_sai_nat_event_notification_fn = NULL;
    PP(var_sai_nat_event_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_NAT_EVENT_NOTIFY);
    sai_packet_event_notification_fn var_sai_packet_event_notification_fn = NULL;
    PP(var_sai_packet_event_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_PACKET_EVENT_NOTIFY);
    sai_port_state_change_notification_fn var_sai_port_state_change_notification_fn = NULL;
    PP(var_sai_port_state_change_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_PORT_STATE_CHANGE_NOTIFY);
    sai_queue_pfc_deadlock_notification_fn var_sai_queue_pfc_deadlock_notification_fn = NULL;
    PP(var_sai_queue_pfc_deadlock_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_QUEUE_PFC_DEADLOCK_NOTIFY);
    sai_switch_shutdown_request_notification_fn var_sai_switch_shutdown_request_notification_fn = NULL;
    PP(var_sai_switch_shutdown_request_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_SWITCH_SHUTDOWN_REQUEST_NOTIFY);
    sai_switch_state_change_notification_fn var_sai_switch_state_change_notification_fn = NULL;
    PP(var_sai_switch_state_change_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_SWITCH_STATE_CHANGE_NOTIFY);
    sai_tam_event_notification_fn var_sai_tam_event_notification_fn = NULL;
    PP(var_sai_tam_event_notification_fn);
    printf("%d\n", SAI_SWITCH_ATTR_TAM_EVENT_NOTIFY);
}
void enum_size_check_test(void)
{
    TEST_ASSERT_TRUE((sizeof(sai_acl_action_type_t) == sizeof(int32_t)), "invalid enum sai_acl_action_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_bind_point_type_t) == sizeof(int32_t)), "invalid enum sai_acl_bind_point_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_counter_attr_t) == sizeof(int32_t)), "invalid enum sai_acl_counter_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_dtel_flow_op_t) == sizeof(int32_t)), "invalid enum sai_acl_dtel_flow_op_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_acl_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_ip_frag_t) == sizeof(int32_t)), "invalid enum sai_acl_ip_frag_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_ip_type_t) == sizeof(int32_t)), "invalid enum sai_acl_ip_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_range_attr_t) == sizeof(int32_t)), "invalid enum sai_acl_range_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_range_type_t) == sizeof(int32_t)), "invalid enum sai_acl_range_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_stage_t) == sizeof(int32_t)), "invalid enum sai_acl_stage_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_table_attr_t) == sizeof(int32_t)), "invalid enum sai_acl_table_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_table_group_attr_t) == sizeof(int32_t)), "invalid enum sai_acl_table_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_table_group_member_attr_t) == sizeof(int32_t)), "invalid enum sai_acl_table_group_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_acl_table_group_type_t) == sizeof(int32_t)), "invalid enum sai_acl_table_group_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_api_extensions_t) == sizeof(int32_t)), "invalid enum sai_api_extensions_t size");
    TEST_ASSERT_TRUE((sizeof(sai_api_t) == sizeof(int32_t)), "invalid enum sai_api_t size");
    TEST_ASSERT_TRUE((sizeof(sai_attr_condition_type_t) == sizeof(int32_t)), "invalid enum sai_attr_condition_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_attr_flags_t) == sizeof(int32_t)), "invalid enum sai_attr_flags_t size");
    TEST_ASSERT_TRUE((sizeof(sai_attr_value_type_t) == sizeof(int32_t)), "invalid enum sai_attr_value_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bfd_encapsulation_type_t) == sizeof(int32_t)), "invalid enum sai_bfd_encapsulation_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bfd_session_attr_t) == sizeof(int32_t)), "invalid enum sai_bfd_session_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bfd_session_offload_type_t) == sizeof(int32_t)), "invalid enum sai_bfd_session_offload_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bfd_session_stat_t) == sizeof(int32_t)), "invalid enum sai_bfd_session_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bfd_session_state_t) == sizeof(int32_t)), "invalid enum sai_bfd_session_state_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bfd_session_type_t) == sizeof(int32_t)), "invalid enum sai_bfd_session_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_attr_t) == sizeof(int32_t)), "invalid enum sai_bridge_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_flood_control_type_t) == sizeof(int32_t)), "invalid enum sai_bridge_flood_control_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_port_attr_t) == sizeof(int32_t)), "invalid enum sai_bridge_port_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_port_fdb_learning_mode_t) == sizeof(int32_t)), "invalid enum sai_bridge_port_fdb_learning_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_port_stat_t) == sizeof(int32_t)), "invalid enum sai_bridge_port_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_port_tagging_mode_t) == sizeof(int32_t)), "invalid enum sai_bridge_port_tagging_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_port_type_t) == sizeof(int32_t)), "invalid enum sai_bridge_port_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_stat_t) == sizeof(int32_t)), "invalid enum sai_bridge_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bridge_type_t) == sizeof(int32_t)), "invalid enum sai_bridge_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_buffer_pool_attr_t) == sizeof(int32_t)), "invalid enum sai_buffer_pool_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_buffer_pool_stat_t) == sizeof(int32_t)), "invalid enum sai_buffer_pool_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_buffer_pool_threshold_mode_t) == sizeof(int32_t)), "invalid enum sai_buffer_pool_threshold_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_buffer_pool_type_t) == sizeof(int32_t)), "invalid enum sai_buffer_pool_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_buffer_profile_attr_t) == sizeof(int32_t)), "invalid enum sai_buffer_profile_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_buffer_profile_threshold_mode_t) == sizeof(int32_t)), "invalid enum sai_buffer_profile_threshold_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_bulk_op_error_mode_t) == sizeof(int32_t)), "invalid enum sai_bulk_op_error_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_common_api_t) == sizeof(int32_t)), "invalid enum sai_common_api_t size");
    TEST_ASSERT_TRUE((sizeof(sai_condition_operator_t) == sizeof(int32_t)), "invalid enum sai_condition_operator_t size");
    TEST_ASSERT_TRUE((sizeof(sai_counter_attr_t) == sizeof(int32_t)), "invalid enum sai_counter_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_counter_stat_t) == sizeof(int32_t)), "invalid enum sai_counter_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_counter_type_t) == sizeof(int32_t)), "invalid enum sai_counter_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_debug_counter_attr_t) == sizeof(int32_t)), "invalid enum sai_debug_counter_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_debug_counter_bind_method_t) == sizeof(int32_t)), "invalid enum sai_debug_counter_bind_method_t size");
    TEST_ASSERT_TRUE((sizeof(sai_debug_counter_type_t) == sizeof(int32_t)), "invalid enum sai_debug_counter_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_default_value_type_t) == sizeof(int32_t)), "invalid enum sai_default_value_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_dtel_attr_t) == sizeof(int32_t)), "invalid enum sai_dtel_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_dtel_event_attr_t) == sizeof(int32_t)), "invalid enum sai_dtel_event_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_dtel_event_type_t) == sizeof(int32_t)), "invalid enum sai_dtel_event_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_dtel_int_session_attr_t) == sizeof(int32_t)), "invalid enum sai_dtel_int_session_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_dtel_queue_report_attr_t) == sizeof(int32_t)), "invalid enum sai_dtel_queue_report_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_dtel_report_session_attr_t) == sizeof(int32_t)), "invalid enum sai_dtel_report_session_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ecn_mark_mode_t) == sizeof(int32_t)), "invalid enum sai_ecn_mark_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_enum_flags_type_t) == sizeof(int32_t)), "invalid enum sai_enum_flags_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_erspan_encapsulation_type_t) == sizeof(int32_t)), "invalid enum sai_erspan_encapsulation_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_fdb_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_fdb_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_fdb_entry_type_t) == sizeof(int32_t)), "invalid enum sai_fdb_entry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_fdb_event_t) == sizeof(int32_t)), "invalid enum sai_fdb_event_t size");
    TEST_ASSERT_TRUE((sizeof(sai_fdb_flush_attr_t) == sizeof(int32_t)), "invalid enum sai_fdb_flush_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_fdb_flush_entry_type_t) == sizeof(int32_t)), "invalid enum sai_fdb_flush_entry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_fine_grained_hash_field_attr_t) == sizeof(int32_t)), "invalid enum sai_fine_grained_hash_field_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_generic_programmable_attr_t) == sizeof(int32_t)), "invalid enum sai_generic_programmable_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_global_api_type_t) == sizeof(int32_t)), "invalid enum sai_global_api_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hash_algorithm_t) == sizeof(int32_t)), "invalid enum sai_hash_algorithm_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hash_attr_t) == sizeof(int32_t)), "invalid enum sai_hash_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_attr_t) == sizeof(int32_t)), "invalid enum sai_hostif_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_packet_attr_t) == sizeof(int32_t)), "invalid enum sai_hostif_packet_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_table_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_hostif_table_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_table_entry_channel_type_t) == sizeof(int32_t)), "invalid enum sai_hostif_table_entry_channel_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_table_entry_type_t) == sizeof(int32_t)), "invalid enum sai_hostif_table_entry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_trap_attr_t) == sizeof(int32_t)), "invalid enum sai_hostif_trap_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_trap_group_attr_t) == sizeof(int32_t)), "invalid enum sai_hostif_trap_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_trap_type_t) == sizeof(int32_t)), "invalid enum sai_hostif_trap_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_tx_type_t) == sizeof(int32_t)), "invalid enum sai_hostif_tx_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_type_t) == sizeof(int32_t)), "invalid enum sai_hostif_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_user_defined_trap_attr_t) == sizeof(int32_t)), "invalid enum sai_hostif_user_defined_trap_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_user_defined_trap_type_t) == sizeof(int32_t)), "invalid enum sai_hostif_user_defined_trap_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_hostif_vlan_tag_t) == sizeof(int32_t)), "invalid enum sai_hostif_vlan_tag_t size");
    TEST_ASSERT_TRUE((sizeof(sai_in_drop_reason_t) == sizeof(int32_t)), "invalid enum sai_in_drop_reason_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ingress_priority_group_attr_t) == sizeof(int32_t)), "invalid enum sai_ingress_priority_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ingress_priority_group_stat_t) == sizeof(int32_t)), "invalid enum sai_ingress_priority_group_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_inseg_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_inseg_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_inseg_entry_pop_qos_mode_t) == sizeof(int32_t)), "invalid enum sai_inseg_entry_pop_qos_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_inseg_entry_pop_ttl_mode_t) == sizeof(int32_t)), "invalid enum sai_inseg_entry_pop_ttl_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_inseg_entry_psc_type_t) == sizeof(int32_t)), "invalid enum sai_inseg_entry_psc_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ip_addr_family_t) == sizeof(int32_t)), "invalid enum sai_ip_addr_family_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipmc_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_ipmc_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipmc_entry_type_t) == sizeof(int32_t)), "invalid enum sai_ipmc_entry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipmc_group_attr_t) == sizeof(int32_t)), "invalid enum sai_ipmc_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipmc_group_member_attr_t) == sizeof(int32_t)), "invalid enum sai_ipmc_group_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_attr_t) == sizeof(int32_t)), "invalid enum sai_ipsec_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_cipher_t) == sizeof(int32_t)), "invalid enum sai_ipsec_cipher_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_direction_t) == sizeof(int32_t)), "invalid enum sai_ipsec_direction_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_port_attr_t) == sizeof(int32_t)), "invalid enum sai_ipsec_port_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_port_stat_t) == sizeof(int32_t)), "invalid enum sai_ipsec_port_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_sa_attr_t) == sizeof(int32_t)), "invalid enum sai_ipsec_sa_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_sa_octet_count_status_t) == sizeof(int32_t)), "invalid enum sai_ipsec_sa_octet_count_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_ipsec_sa_stat_t) == sizeof(int32_t)), "invalid enum sai_ipsec_sa_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_isolation_group_attr_t) == sizeof(int32_t)), "invalid enum sai_isolation_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_isolation_group_member_attr_t) == sizeof(int32_t)), "invalid enum sai_isolation_group_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_isolation_group_type_t) == sizeof(int32_t)), "invalid enum sai_isolation_group_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_l2mc_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_l2mc_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_l2mc_entry_type_t) == sizeof(int32_t)), "invalid enum sai_l2mc_entry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_l2mc_group_attr_t) == sizeof(int32_t)), "invalid enum sai_l2mc_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_l2mc_group_member_attr_t) == sizeof(int32_t)), "invalid enum sai_l2mc_group_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_lag_attr_t) == sizeof(int32_t)), "invalid enum sai_lag_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_lag_member_attr_t) == sizeof(int32_t)), "invalid enum sai_lag_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_log_level_t) == sizeof(int32_t)), "invalid enum sai_log_level_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_attr_t) == sizeof(int32_t)), "invalid enum sai_macsec_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_cipher_suite_t) == sizeof(int32_t)), "invalid enum sai_macsec_cipher_suite_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_direction_t) == sizeof(int32_t)), "invalid enum sai_macsec_direction_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_flow_attr_t) == sizeof(int32_t)), "invalid enum sai_macsec_flow_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_flow_stat_t) == sizeof(int32_t)), "invalid enum sai_macsec_flow_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_max_secure_associations_per_sc_t) == sizeof(int32_t)), "invalid enum sai_macsec_max_secure_associations_per_sc_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_port_attr_t) == sizeof(int32_t)), "invalid enum sai_macsec_port_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_port_stat_t) == sizeof(int32_t)), "invalid enum sai_macsec_port_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_sa_attr_t) == sizeof(int32_t)), "invalid enum sai_macsec_sa_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_sa_stat_t) == sizeof(int32_t)), "invalid enum sai_macsec_sa_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_sc_attr_t) == sizeof(int32_t)), "invalid enum sai_macsec_sc_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_macsec_sc_stat_t) == sizeof(int32_t)), "invalid enum sai_macsec_sc_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_mcast_fdb_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_mcast_fdb_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_meter_type_t) == sizeof(int32_t)), "invalid enum sai_meter_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_mirror_session_attr_t) == sizeof(int32_t)), "invalid enum sai_mirror_session_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_mirror_session_congestion_mode_t) == sizeof(int32_t)), "invalid enum sai_mirror_session_congestion_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_mirror_session_type_t) == sizeof(int32_t)), "invalid enum sai_mirror_session_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_my_mac_attr_t) == sizeof(int32_t)), "invalid enum sai_my_mac_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_my_sid_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_my_sid_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_my_sid_entry_endpoint_behavior_flavor_t) == sizeof(int32_t)), "invalid enum sai_my_sid_entry_endpoint_behavior_flavor_t size");
    TEST_ASSERT_TRUE((sizeof(sai_my_sid_entry_endpoint_behavior_t) == sizeof(int32_t)), "invalid enum sai_my_sid_entry_endpoint_behavior_t size");
    TEST_ASSERT_TRUE((sizeof(sai_nat_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_nat_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_nat_event_t) == sizeof(int32_t)), "invalid enum sai_nat_event_t size");
    TEST_ASSERT_TRUE((sizeof(sai_nat_type_t) == sizeof(int32_t)), "invalid enum sai_nat_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_nat_zone_counter_attr_t) == sizeof(int32_t)), "invalid enum sai_nat_zone_counter_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_native_hash_field_t) == sizeof(int32_t)), "invalid enum sai_native_hash_field_t size");
    TEST_ASSERT_TRUE((sizeof(sai_neighbor_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_neighbor_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_attr_t) == sizeof(int32_t)), "invalid enum sai_next_hop_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_attr_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_map_attr_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_map_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_map_type_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_map_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_member_attr_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_member_configured_role_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_member_configured_role_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_member_observed_role_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_member_observed_role_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_group_type_t) == sizeof(int32_t)), "invalid enum sai_next_hop_group_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_next_hop_type_t) == sizeof(int32_t)), "invalid enum sai_next_hop_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_object_stage_t) == sizeof(int32_t)), "invalid enum sai_object_stage_t size");
    TEST_ASSERT_TRUE((sizeof(sai_object_type_extensions_t) == sizeof(int32_t)), "invalid enum sai_object_type_extensions_t size");
    TEST_ASSERT_TRUE((sizeof(sai_object_type_t) == sizeof(int32_t)), "invalid enum sai_object_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_out_drop_reason_t) == sizeof(int32_t)), "invalid enum sai_out_drop_reason_t size");
    TEST_ASSERT_TRUE((sizeof(sai_outseg_exp_mode_t) == sizeof(int32_t)), "invalid enum sai_outseg_exp_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_outseg_ttl_mode_t) == sizeof(int32_t)), "invalid enum sai_outseg_ttl_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_outseg_type_t) == sizeof(int32_t)), "invalid enum sai_outseg_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_packet_action_t) == sizeof(int32_t)), "invalid enum sai_packet_action_t size");
    TEST_ASSERT_TRUE((sizeof(sai_packet_color_t) == sizeof(int32_t)), "invalid enum sai_packet_color_t size");
    TEST_ASSERT_TRUE((sizeof(sai_packet_vlan_t) == sizeof(int32_t)), "invalid enum sai_packet_vlan_t size");
    TEST_ASSERT_TRUE((sizeof(sai_policer_attr_t) == sizeof(int32_t)), "invalid enum sai_policer_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_policer_color_source_t) == sizeof(int32_t)), "invalid enum sai_policer_color_source_t size");
    TEST_ASSERT_TRUE((sizeof(sai_policer_mode_t) == sizeof(int32_t)), "invalid enum sai_policer_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_policer_stat_t) == sizeof(int32_t)), "invalid enum sai_policer_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_attr_t) == sizeof(int32_t)), "invalid enum sai_port_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_auto_neg_config_mode_t) == sizeof(int32_t)), "invalid enum sai_port_auto_neg_config_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_breakout_mode_type_t) == sizeof(int32_t)), "invalid enum sai_port_breakout_mode_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_connector_attr_t) == sizeof(int32_t)), "invalid enum sai_port_connector_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_connector_failover_mode_t) == sizeof(int32_t)), "invalid enum sai_port_connector_failover_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_dual_media_t) == sizeof(int32_t)), "invalid enum sai_port_dual_media_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_err_status_t) == sizeof(int32_t)), "invalid enum sai_port_err_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_fec_mode_extended_t) == sizeof(int32_t)), "invalid enum sai_port_fec_mode_extended_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_fec_mode_t) == sizeof(int32_t)), "invalid enum sai_port_fec_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_flow_control_mode_t) == sizeof(int32_t)), "invalid enum sai_port_flow_control_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_interface_type_t) == sizeof(int32_t)), "invalid enum sai_port_interface_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_internal_loopback_mode_t) == sizeof(int32_t)), "invalid enum sai_port_internal_loopback_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_link_training_failure_status_t) == sizeof(int32_t)), "invalid enum sai_port_link_training_failure_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_link_training_rx_status_t) == sizeof(int32_t)), "invalid enum sai_port_link_training_rx_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_loopback_mode_t) == sizeof(int32_t)), "invalid enum sai_port_loopback_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_mdix_mode_config_t) == sizeof(int32_t)), "invalid enum sai_port_mdix_mode_config_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_mdix_mode_status_t) == sizeof(int32_t)), "invalid enum sai_port_mdix_mode_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_media_type_t) == sizeof(int32_t)), "invalid enum sai_port_media_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_module_type_t) == sizeof(int32_t)), "invalid enum sai_port_module_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_oper_status_t) == sizeof(int32_t)), "invalid enum sai_port_oper_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_pool_attr_t) == sizeof(int32_t)), "invalid enum sai_port_pool_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_pool_stat_t) == sizeof(int32_t)), "invalid enum sai_port_pool_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_prbs_config_t) == sizeof(int32_t)), "invalid enum sai_port_prbs_config_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_prbs_rx_status_t) == sizeof(int32_t)), "invalid enum sai_port_prbs_rx_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_priority_flow_control_mode_t) == sizeof(int32_t)), "invalid enum sai_port_priority_flow_control_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_ptp_mode_t) == sizeof(int32_t)), "invalid enum sai_port_ptp_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_serdes_attr_t) == sizeof(int32_t)), "invalid enum sai_port_serdes_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_stat_t) == sizeof(int32_t)), "invalid enum sai_port_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_port_type_t) == sizeof(int32_t)), "invalid enum sai_port_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_qos_map_attr_t) == sizeof(int32_t)), "invalid enum sai_qos_map_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_qos_map_type_t) == sizeof(int32_t)), "invalid enum sai_qos_map_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_queue_attr_t) == sizeof(int32_t)), "invalid enum sai_queue_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_queue_pfc_continuous_deadlock_state_t) == sizeof(int32_t)), "invalid enum sai_queue_pfc_continuous_deadlock_state_t size");
    TEST_ASSERT_TRUE((sizeof(sai_queue_pfc_deadlock_event_type_t) == sizeof(int32_t)), "invalid enum sai_queue_pfc_deadlock_event_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_queue_stat_t) == sizeof(int32_t)), "invalid enum sai_queue_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_queue_type_t) == sizeof(int32_t)), "invalid enum sai_queue_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_route_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_route_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_router_interface_attr_t) == sizeof(int32_t)), "invalid enum sai_router_interface_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_router_interface_stat_t) == sizeof(int32_t)), "invalid enum sai_router_interface_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_router_interface_type_t) == sizeof(int32_t)), "invalid enum sai_router_interface_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_rpf_group_attr_t) == sizeof(int32_t)), "invalid enum sai_rpf_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_rpf_group_member_attr_t) == sizeof(int32_t)), "invalid enum sai_rpf_group_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_samplepacket_attr_t) == sizeof(int32_t)), "invalid enum sai_samplepacket_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_samplepacket_mode_t) == sizeof(int32_t)), "invalid enum sai_samplepacket_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_samplepacket_type_t) == sizeof(int32_t)), "invalid enum sai_samplepacket_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_scheduler_attr_t) == sizeof(int32_t)), "invalid enum sai_scheduler_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_scheduler_group_attr_t) == sizeof(int32_t)), "invalid enum sai_scheduler_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_scheduling_type_t) == sizeof(int32_t)), "invalid enum sai_scheduling_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_srv6_sidlist_attr_t) == sizeof(int32_t)), "invalid enum sai_srv6_sidlist_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_srv6_sidlist_type_t) == sizeof(int32_t)), "invalid enum sai_srv6_sidlist_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_stats_mode_t) == sizeof(int32_t)), "invalid enum sai_stats_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_status_t) == sizeof(int32_t)), "invalid enum sai_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_stp_attr_t) == sizeof(int32_t)), "invalid enum sai_stp_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_stp_port_attr_t) == sizeof(int32_t)), "invalid enum sai_stp_port_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_stp_port_state_t) == sizeof(int32_t)), "invalid enum sai_stp_port_state_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_attr_extensions_t) == sizeof(int32_t)), "invalid enum sai_switch_attr_extensions_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_attr_t) == sizeof(int32_t)), "invalid enum sai_switch_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_failover_config_mode_t) == sizeof(int32_t)), "invalid enum sai_switch_failover_config_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_firmware_load_method_t) == sizeof(int32_t)), "invalid enum sai_switch_firmware_load_method_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_firmware_load_type_t) == sizeof(int32_t)), "invalid enum sai_switch_firmware_load_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_hardware_access_bus_t) == sizeof(int32_t)), "invalid enum sai_switch_hardware_access_bus_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_mcast_snooping_capability_t) == sizeof(int32_t)), "invalid enum sai_switch_mcast_snooping_capability_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_notification_type_t) == sizeof(int32_t)), "invalid enum sai_switch_notification_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_oper_status_t) == sizeof(int32_t)), "invalid enum sai_switch_oper_status_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_pointer_type_t) == sizeof(int32_t)), "invalid enum sai_switch_pointer_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_restart_type_t) == sizeof(int32_t)), "invalid enum sai_switch_restart_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_stat_t) == sizeof(int32_t)), "invalid enum sai_switch_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_switching_mode_t) == sizeof(int32_t)), "invalid enum sai_switch_switching_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_tunnel_attr_t) == sizeof(int32_t)), "invalid enum sai_switch_tunnel_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_switch_type_t) == sizeof(int32_t)), "invalid enum sai_switch_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_system_port_attr_t) == sizeof(int32_t)), "invalid enum sai_system_port_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_system_port_type_t) == sizeof(int32_t)), "invalid enum sai_system_port_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_bitmap_classification_entry_action_t) == sizeof(int32_t)), "invalid enum sai_table_bitmap_classification_entry_action_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_bitmap_classification_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_table_bitmap_classification_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_bitmap_classification_entry_stat_t) == sizeof(int32_t)), "invalid enum sai_table_bitmap_classification_entry_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_bitmap_router_entry_action_t) == sizeof(int32_t)), "invalid enum sai_table_bitmap_router_entry_action_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_bitmap_router_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_table_bitmap_router_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_bitmap_router_entry_stat_t) == sizeof(int32_t)), "invalid enum sai_table_bitmap_router_entry_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_meta_tunnel_entry_action_t) == sizeof(int32_t)), "invalid enum sai_table_meta_tunnel_entry_action_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_meta_tunnel_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_table_meta_tunnel_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_table_meta_tunnel_entry_stat_t) == sizeof(int32_t)), "invalid enum sai_table_meta_tunnel_entry_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_bind_point_type_t) == sizeof(int32_t)), "invalid enum sai_tam_bind_point_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_collector_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_collector_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_event_action_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_event_action_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_event_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_event_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_event_threshold_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_event_threshold_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_event_threshold_unit_t) == sizeof(int32_t)), "invalid enum sai_tam_event_threshold_unit_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_event_type_t) == sizeof(int32_t)), "invalid enum sai_tam_event_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_int_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_int_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_int_presence_type_t) == sizeof(int32_t)), "invalid enum sai_tam_int_presence_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_int_type_t) == sizeof(int32_t)), "invalid enum sai_tam_int_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_math_func_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_math_func_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_report_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_report_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_report_mode_t) == sizeof(int32_t)), "invalid enum sai_tam_report_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_report_type_t) == sizeof(int32_t)), "invalid enum sai_tam_report_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_reporting_unit_t) == sizeof(int32_t)), "invalid enum sai_tam_reporting_unit_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_tel_math_func_type_t) == sizeof(int32_t)), "invalid enum sai_tam_tel_math_func_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_tel_type_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_tel_type_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_telemetry_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_telemetry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_telemetry_type_t) == sizeof(int32_t)), "invalid enum sai_tam_telemetry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_transport_attr_t) == sizeof(int32_t)), "invalid enum sai_tam_transport_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_transport_auth_type_t) == sizeof(int32_t)), "invalid enum sai_tam_transport_auth_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tam_transport_type_t) == sizeof(int32_t)), "invalid enum sai_tam_transport_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tlv_type_t) == sizeof(int32_t)), "invalid enum sai_tlv_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_attr_t) == sizeof(int32_t)), "invalid enum sai_tunnel_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_decap_ecn_mode_t) == sizeof(int32_t)), "invalid enum sai_tunnel_decap_ecn_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_dscp_mode_t) == sizeof(int32_t)), "invalid enum sai_tunnel_dscp_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_encap_ecn_mode_t) == sizeof(int32_t)), "invalid enum sai_tunnel_encap_ecn_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_map_attr_t) == sizeof(int32_t)), "invalid enum sai_tunnel_map_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_map_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_tunnel_map_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_map_type_t) == sizeof(int32_t)), "invalid enum sai_tunnel_map_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_peer_mode_t) == sizeof(int32_t)), "invalid enum sai_tunnel_peer_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_stat_t) == sizeof(int32_t)), "invalid enum sai_tunnel_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_term_table_entry_attr_t) == sizeof(int32_t)), "invalid enum sai_tunnel_term_table_entry_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_term_table_entry_type_t) == sizeof(int32_t)), "invalid enum sai_tunnel_term_table_entry_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_ttl_mode_t) == sizeof(int32_t)), "invalid enum sai_tunnel_ttl_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_type_t) == sizeof(int32_t)), "invalid enum sai_tunnel_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_tunnel_vxlan_udp_sport_mode_t) == sizeof(int32_t)), "invalid enum sai_tunnel_vxlan_udp_sport_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_udf_attr_t) == sizeof(int32_t)), "invalid enum sai_udf_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_udf_base_t) == sizeof(int32_t)), "invalid enum sai_udf_base_t size");
    TEST_ASSERT_TRUE((sizeof(sai_udf_group_attr_t) == sizeof(int32_t)), "invalid enum sai_udf_group_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_udf_group_type_t) == sizeof(int32_t)), "invalid enum sai_udf_group_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_udf_match_attr_t) == sizeof(int32_t)), "invalid enum sai_udf_match_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_virtual_router_attr_t) == sizeof(int32_t)), "invalid enum sai_virtual_router_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_vlan_attr_t) == sizeof(int32_t)), "invalid enum sai_vlan_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_vlan_flood_control_type_t) == sizeof(int32_t)), "invalid enum sai_vlan_flood_control_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_vlan_mcast_lookup_key_type_t) == sizeof(int32_t)), "invalid enum sai_vlan_mcast_lookup_key_type_t size");
    TEST_ASSERT_TRUE((sizeof(sai_vlan_member_attr_t) == sizeof(int32_t)), "invalid enum sai_vlan_member_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_vlan_stat_t) == sizeof(int32_t)), "invalid enum sai_vlan_stat_t size");
    TEST_ASSERT_TRUE((sizeof(sai_vlan_tagging_mode_t) == sizeof(int32_t)), "invalid enum sai_vlan_tagging_mode_t size");
    TEST_ASSERT_TRUE((sizeof(sai_wred_attr_t) == sizeof(int32_t)), "invalid enum sai_wred_attr_t size");
    TEST_ASSERT_TRUE((sizeof(sai_status_t) == sizeof(int32_t)), "invalid sai_status_t size");
}
void list_count_test(void)
{
    size_t size_ref = sizeof(sai_object_list_t);
    sai_acl_resource_list_t acl_resource_list;
    TEST_ASSERT_TRUE(sizeof(sai_acl_resource_list_t) == size_ref, "type sai_acl_resource_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(acl_resource_list.count) == sizeof(uint32_t), "sai_acl_resource_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(acl_resource_list.list) == sizeof(void*), "sai_acl_resource_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&acl_resource_list == (void*)&acl_resource_list.count, "sai_acl_resource_list_t.count should be first member in sai_acl_resource_list_t");
    sai_ip_address_list_t ip_address_list;
    TEST_ASSERT_TRUE(sizeof(sai_ip_address_list_t) == size_ref, "type sai_ip_address_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(ip_address_list.count) == sizeof(uint32_t), "sai_ip_address_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(ip_address_list.list) == sizeof(void*), "sai_ip_address_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&ip_address_list == (void*)&ip_address_list.count, "sai_ip_address_list_t.count should be first member in sai_ip_address_list_t");
    sai_ip_prefix_list_t ip_prefix_list;
    TEST_ASSERT_TRUE(sizeof(sai_ip_prefix_list_t) == size_ref, "type sai_ip_prefix_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(ip_prefix_list.count) == sizeof(uint32_t), "sai_ip_prefix_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(ip_prefix_list.list) == sizeof(void*), "sai_ip_prefix_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&ip_prefix_list == (void*)&ip_prefix_list.count, "sai_ip_prefix_list_t.count should be first member in sai_ip_prefix_list_t");
    sai_map_list_t map_list;
    TEST_ASSERT_TRUE(sizeof(sai_map_list_t) == size_ref, "type sai_map_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(map_list.count) == sizeof(uint32_t), "sai_map_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(map_list.list) == sizeof(void*), "sai_map_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&map_list == (void*)&map_list.count, "sai_map_list_t.count should be first member in sai_map_list_t");
    sai_object_list_t object_list;
    TEST_ASSERT_TRUE(sizeof(sai_object_list_t) == size_ref, "type sai_object_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(object_list.count) == sizeof(uint32_t), "sai_object_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(object_list.list) == sizeof(void*), "sai_object_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&object_list == (void*)&object_list.count, "sai_object_list_t.count should be first member in sai_object_list_t");
    sai_port_err_status_list_t port_err_status_list;
    TEST_ASSERT_TRUE(sizeof(sai_port_err_status_list_t) == size_ref, "type sai_port_err_status_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(port_err_status_list.count) == sizeof(uint32_t), "sai_port_err_status_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(port_err_status_list.list) == sizeof(void*), "sai_port_err_status_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&port_err_status_list == (void*)&port_err_status_list.count, "sai_port_err_status_list_t.count should be first member in sai_port_err_status_list_t");
    sai_port_eye_values_list_t port_eye_values_list;
    TEST_ASSERT_TRUE(sizeof(sai_port_eye_values_list_t) == size_ref, "type sai_port_eye_values_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(port_eye_values_list.count) == sizeof(uint32_t), "sai_port_eye_values_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(port_eye_values_list.list) == sizeof(void*), "sai_port_eye_values_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&port_eye_values_list == (void*)&port_eye_values_list.count, "sai_port_eye_values_list_t.count should be first member in sai_port_eye_values_list_t");
    sai_port_lane_latch_status_list_t port_lane_latch_status_list;
    TEST_ASSERT_TRUE(sizeof(sai_port_lane_latch_status_list_t) == size_ref, "type sai_port_lane_latch_status_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(port_lane_latch_status_list.count) == sizeof(uint32_t), "sai_port_lane_latch_status_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(port_lane_latch_status_list.list) == sizeof(void*), "sai_port_lane_latch_status_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&port_lane_latch_status_list == (void*)&port_lane_latch_status_list.count, "sai_port_lane_latch_status_list_t.count should be first member in sai_port_lane_latch_status_list_t");
    sai_qos_map_list_t qos_map_list;
    TEST_ASSERT_TRUE(sizeof(sai_qos_map_list_t) == size_ref, "type sai_qos_map_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(qos_map_list.count) == sizeof(uint32_t), "sai_qos_map_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(qos_map_list.list) == sizeof(void*), "sai_qos_map_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&qos_map_list == (void*)&qos_map_list.count, "sai_qos_map_list_t.count should be first member in sai_qos_map_list_t");
    sai_s16_list_t s16_list;
    TEST_ASSERT_TRUE(sizeof(sai_s16_list_t) == size_ref, "type sai_s16_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(s16_list.count) == sizeof(uint32_t), "sai_s16_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(s16_list.list) == sizeof(void*), "sai_s16_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&s16_list == (void*)&s16_list.count, "sai_s16_list_t.count should be first member in sai_s16_list_t");
    sai_s32_list_t s32_list;
    TEST_ASSERT_TRUE(sizeof(sai_s32_list_t) == size_ref, "type sai_s32_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(s32_list.count) == sizeof(uint32_t), "sai_s32_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(s32_list.list) == sizeof(void*), "sai_s32_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&s32_list == (void*)&s32_list.count, "sai_s32_list_t.count should be first member in sai_s32_list_t");
    sai_s8_list_t s8_list;
    TEST_ASSERT_TRUE(sizeof(sai_s8_list_t) == size_ref, "type sai_s8_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(s8_list.count) == sizeof(uint32_t), "sai_s8_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(s8_list.list) == sizeof(void*), "sai_s8_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&s8_list == (void*)&s8_list.count, "sai_s8_list_t.count should be first member in sai_s8_list_t");
    sai_segment_list_t segment_list;
    TEST_ASSERT_TRUE(sizeof(sai_segment_list_t) == size_ref, "type sai_segment_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(segment_list.count) == sizeof(uint32_t), "sai_segment_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(segment_list.list) == sizeof(void*), "sai_segment_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&segment_list == (void*)&segment_list.count, "sai_segment_list_t.count should be first member in sai_segment_list_t");
    sai_system_port_config_list_t system_port_config_list;
    TEST_ASSERT_TRUE(sizeof(sai_system_port_config_list_t) == size_ref, "type sai_system_port_config_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(system_port_config_list.count) == sizeof(uint32_t), "sai_system_port_config_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(system_port_config_list.list) == sizeof(void*), "sai_system_port_config_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&system_port_config_list == (void*)&system_port_config_list.count, "sai_system_port_config_list_t.count should be first member in sai_system_port_config_list_t");
    sai_tlv_list_t tlv_list;
    TEST_ASSERT_TRUE(sizeof(sai_tlv_list_t) == size_ref, "type sai_tlv_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(tlv_list.count) == sizeof(uint32_t), "sai_tlv_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(tlv_list.list) == sizeof(void*), "sai_tlv_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&tlv_list == (void*)&tlv_list.count, "sai_tlv_list_t.count should be first member in sai_tlv_list_t");
    sai_u16_list_t u16_list;
    TEST_ASSERT_TRUE(sizeof(sai_u16_list_t) == size_ref, "type sai_u16_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(u16_list.count) == sizeof(uint32_t), "sai_u16_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(u16_list.list) == sizeof(void*), "sai_u16_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&u16_list == (void*)&u16_list.count, "sai_u16_list_t.count should be first member in sai_u16_list_t");
    sai_u16_range_list_t u16_range_list;
    TEST_ASSERT_TRUE(sizeof(sai_u16_range_list_t) == size_ref, "type sai_u16_range_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(u16_range_list.count) == sizeof(uint32_t), "sai_u16_range_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(u16_range_list.list) == sizeof(void*), "sai_u16_range_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&u16_range_list == (void*)&u16_range_list.count, "sai_u16_range_list_t.count should be first member in sai_u16_range_list_t");
    sai_u32_list_t u32_list;
    TEST_ASSERT_TRUE(sizeof(sai_u32_list_t) == size_ref, "type sai_u32_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(u32_list.count) == sizeof(uint32_t), "sai_u32_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(u32_list.list) == sizeof(void*), "sai_u32_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&u32_list == (void*)&u32_list.count, "sai_u32_list_t.count should be first member in sai_u32_list_t");
    sai_u8_list_t u8_list;
    TEST_ASSERT_TRUE(sizeof(sai_u8_list_t) == size_ref, "type sai_u8_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(u8_list.count) == sizeof(uint32_t), "sai_u8_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(u8_list.list) == sizeof(void*), "sai_u8_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&u8_list == (void*)&u8_list.count, "sai_u8_list_t.count should be first member in sai_u8_list_t");
    sai_vlan_list_t vlan_list;
    TEST_ASSERT_TRUE(sizeof(sai_vlan_list_t) == size_ref, "type sai_vlan_list_t has different sizeof than sai_object_type_t");
    TEST_ASSERT_TRUE(sizeof(vlan_list.count) == sizeof(uint32_t), "sai_vlan_list_t.count should be uint32_t");
    TEST_ASSERT_TRUE(sizeof(vlan_list.list) == sizeof(void*), "sai_vlan_list_t.list should be pointer");
    TEST_ASSERT_TRUE(&vlan_list == (void*)&vlan_list.count, "sai_vlan_list_t.count should be first member in sai_vlan_list_t");
}
void api_name_test(void)
{
    sai_object_type_t checked[SAI_OBJECT_TYPE_EXTENSIONS_MAX];
    memset(checked, 0, SAI_OBJECT_TYPE_EXTENSIONS_MAX * sizeof(sai_object_type_t));
    void *dummy = NULL;
    {
        sai_port_api_t port_api = { 0 };
        sai_generic_create_fn create = port_api.create_port;
        sai_generic_remove_fn remove = port_api.remove_port;
        sai_generic_set_fn set = port_api.set_port_attribute;
        sai_generic_get_fn get = port_api.get_port_attribute;
        sai_create_port_fn cr = NULL;
        sai_remove_port_fn re = NULL;
        sai_set_port_attribute_fn se = NULL;
        sai_get_port_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_PORT] = SAI_OBJECT_TYPE_PORT;
    }
    {
        sai_lag_api_t lag_api = { 0 };
        sai_generic_create_fn create = lag_api.create_lag;
        sai_generic_remove_fn remove = lag_api.remove_lag;
        sai_generic_set_fn set = lag_api.set_lag_attribute;
        sai_generic_get_fn get = lag_api.get_lag_attribute;
        sai_create_lag_fn cr = NULL;
        sai_remove_lag_fn re = NULL;
        sai_set_lag_attribute_fn se = NULL;
        sai_get_lag_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_LAG] = SAI_OBJECT_TYPE_LAG;
    }
    {
        sai_virtual_router_api_t virtual_router_api = { 0 };
        sai_generic_create_fn create = virtual_router_api.create_virtual_router;
        sai_generic_remove_fn remove = virtual_router_api.remove_virtual_router;
        sai_generic_set_fn set = virtual_router_api.set_virtual_router_attribute;
        sai_generic_get_fn get = virtual_router_api.get_virtual_router_attribute;
        sai_create_virtual_router_fn cr = NULL;
        sai_remove_virtual_router_fn re = NULL;
        sai_set_virtual_router_attribute_fn se = NULL;
        sai_get_virtual_router_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_VIRTUAL_ROUTER] = SAI_OBJECT_TYPE_VIRTUAL_ROUTER;
    }
    {
        sai_next_hop_api_t next_hop_api = { 0 };
        sai_generic_create_fn create = next_hop_api.create_next_hop;
        sai_generic_remove_fn remove = next_hop_api.remove_next_hop;
        sai_generic_set_fn set = next_hop_api.set_next_hop_attribute;
        sai_generic_get_fn get = next_hop_api.get_next_hop_attribute;
        sai_create_next_hop_fn cr = NULL;
        sai_remove_next_hop_fn re = NULL;
        sai_set_next_hop_attribute_fn se = NULL;
        sai_get_next_hop_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NEXT_HOP] = SAI_OBJECT_TYPE_NEXT_HOP;
    }
    {
        sai_next_hop_group_api_t next_hop_group_api = { 0 };
        sai_generic_create_fn create = next_hop_group_api.create_next_hop_group;
        sai_generic_remove_fn remove = next_hop_group_api.remove_next_hop_group;
        sai_generic_set_fn set = next_hop_group_api.set_next_hop_group_attribute;
        sai_generic_get_fn get = next_hop_group_api.get_next_hop_group_attribute;
        sai_create_next_hop_group_fn cr = NULL;
        sai_remove_next_hop_group_fn re = NULL;
        sai_set_next_hop_group_attribute_fn se = NULL;
        sai_get_next_hop_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NEXT_HOP_GROUP] = SAI_OBJECT_TYPE_NEXT_HOP_GROUP;
    }
    {
        sai_router_interface_api_t router_interface_api = { 0 };
        sai_generic_create_fn create = router_interface_api.create_router_interface;
        sai_generic_remove_fn remove = router_interface_api.remove_router_interface;
        sai_generic_set_fn set = router_interface_api.set_router_interface_attribute;
        sai_generic_get_fn get = router_interface_api.get_router_interface_attribute;
        sai_create_router_interface_fn cr = NULL;
        sai_remove_router_interface_fn re = NULL;
        sai_set_router_interface_attribute_fn se = NULL;
        sai_get_router_interface_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ROUTER_INTERFACE] = SAI_OBJECT_TYPE_ROUTER_INTERFACE;
    }
    {
        sai_acl_api_t acl_api = { 0 };
        sai_generic_create_fn create = acl_api.create_acl_table;
        sai_generic_remove_fn remove = acl_api.remove_acl_table;
        sai_generic_set_fn set = acl_api.set_acl_table_attribute;
        sai_generic_get_fn get = acl_api.get_acl_table_attribute;
        sai_create_acl_table_fn cr = NULL;
        sai_remove_acl_table_fn re = NULL;
        sai_set_acl_table_attribute_fn se = NULL;
        sai_get_acl_table_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ACL_TABLE] = SAI_OBJECT_TYPE_ACL_TABLE;
    }
    {
        sai_acl_api_t acl_api = { 0 };
        sai_generic_create_fn create = acl_api.create_acl_entry;
        sai_generic_remove_fn remove = acl_api.remove_acl_entry;
        sai_generic_set_fn set = acl_api.set_acl_entry_attribute;
        sai_generic_get_fn get = acl_api.get_acl_entry_attribute;
        sai_create_acl_entry_fn cr = NULL;
        sai_remove_acl_entry_fn re = NULL;
        sai_set_acl_entry_attribute_fn se = NULL;
        sai_get_acl_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ACL_ENTRY] = SAI_OBJECT_TYPE_ACL_ENTRY;
    }
    {
        sai_acl_api_t acl_api = { 0 };
        sai_generic_create_fn create = acl_api.create_acl_counter;
        sai_generic_remove_fn remove = acl_api.remove_acl_counter;
        sai_generic_set_fn set = acl_api.set_acl_counter_attribute;
        sai_generic_get_fn get = acl_api.get_acl_counter_attribute;
        sai_create_acl_counter_fn cr = NULL;
        sai_remove_acl_counter_fn re = NULL;
        sai_set_acl_counter_attribute_fn se = NULL;
        sai_get_acl_counter_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ACL_COUNTER] = SAI_OBJECT_TYPE_ACL_COUNTER;
    }
    {
        sai_acl_api_t acl_api = { 0 };
        sai_generic_create_fn create = acl_api.create_acl_range;
        sai_generic_remove_fn remove = acl_api.remove_acl_range;
        sai_generic_set_fn set = acl_api.set_acl_range_attribute;
        sai_generic_get_fn get = acl_api.get_acl_range_attribute;
        sai_create_acl_range_fn cr = NULL;
        sai_remove_acl_range_fn re = NULL;
        sai_set_acl_range_attribute_fn se = NULL;
        sai_get_acl_range_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ACL_RANGE] = SAI_OBJECT_TYPE_ACL_RANGE;
    }
    {
        sai_acl_api_t acl_api = { 0 };
        sai_generic_create_fn create = acl_api.create_acl_table_group;
        sai_generic_remove_fn remove = acl_api.remove_acl_table_group;
        sai_generic_set_fn set = acl_api.set_acl_table_group_attribute;
        sai_generic_get_fn get = acl_api.get_acl_table_group_attribute;
        sai_create_acl_table_group_fn cr = NULL;
        sai_remove_acl_table_group_fn re = NULL;
        sai_set_acl_table_group_attribute_fn se = NULL;
        sai_get_acl_table_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ACL_TABLE_GROUP] = SAI_OBJECT_TYPE_ACL_TABLE_GROUP;
    }
    {
        sai_acl_api_t acl_api = { 0 };
        sai_generic_create_fn create = acl_api.create_acl_table_group_member;
        sai_generic_remove_fn remove = acl_api.remove_acl_table_group_member;
        sai_generic_set_fn set = acl_api.set_acl_table_group_member_attribute;
        sai_generic_get_fn get = acl_api.get_acl_table_group_member_attribute;
        sai_create_acl_table_group_member_fn cr = NULL;
        sai_remove_acl_table_group_member_fn re = NULL;
        sai_set_acl_table_group_member_attribute_fn se = NULL;
        sai_get_acl_table_group_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ACL_TABLE_GROUP_MEMBER] = SAI_OBJECT_TYPE_ACL_TABLE_GROUP_MEMBER;
    }
    {
        sai_hostif_api_t hostif_api = { 0 };
        sai_generic_create_fn create = hostif_api.create_hostif;
        sai_generic_remove_fn remove = hostif_api.remove_hostif;
        sai_generic_set_fn set = hostif_api.set_hostif_attribute;
        sai_generic_get_fn get = hostif_api.get_hostif_attribute;
        sai_create_hostif_fn cr = NULL;
        sai_remove_hostif_fn re = NULL;
        sai_set_hostif_attribute_fn se = NULL;
        sai_get_hostif_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_HOSTIF] = SAI_OBJECT_TYPE_HOSTIF;
    }
    {
        sai_mirror_api_t mirror_api = { 0 };
        sai_generic_create_fn create = mirror_api.create_mirror_session;
        sai_generic_remove_fn remove = mirror_api.remove_mirror_session;
        sai_generic_set_fn set = mirror_api.set_mirror_session_attribute;
        sai_generic_get_fn get = mirror_api.get_mirror_session_attribute;
        sai_create_mirror_session_fn cr = NULL;
        sai_remove_mirror_session_fn re = NULL;
        sai_set_mirror_session_attribute_fn se = NULL;
        sai_get_mirror_session_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MIRROR_SESSION] = SAI_OBJECT_TYPE_MIRROR_SESSION;
    }
    {
        sai_samplepacket_api_t samplepacket_api = { 0 };
        sai_generic_create_fn create = samplepacket_api.create_samplepacket;
        sai_generic_remove_fn remove = samplepacket_api.remove_samplepacket;
        sai_generic_set_fn set = samplepacket_api.set_samplepacket_attribute;
        sai_generic_get_fn get = samplepacket_api.get_samplepacket_attribute;
        sai_create_samplepacket_fn cr = NULL;
        sai_remove_samplepacket_fn re = NULL;
        sai_set_samplepacket_attribute_fn se = NULL;
        sai_get_samplepacket_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SAMPLEPACKET] = SAI_OBJECT_TYPE_SAMPLEPACKET;
    }
    {
        sai_stp_api_t stp_api = { 0 };
        sai_generic_create_fn create = stp_api.create_stp;
        sai_generic_remove_fn remove = stp_api.remove_stp;
        sai_generic_set_fn set = stp_api.set_stp_attribute;
        sai_generic_get_fn get = stp_api.get_stp_attribute;
        sai_create_stp_fn cr = NULL;
        sai_remove_stp_fn re = NULL;
        sai_set_stp_attribute_fn se = NULL;
        sai_get_stp_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_STP] = SAI_OBJECT_TYPE_STP;
    }
    {
        sai_hostif_api_t hostif_api = { 0 };
        sai_generic_create_fn create = hostif_api.create_hostif_trap_group;
        sai_generic_remove_fn remove = hostif_api.remove_hostif_trap_group;
        sai_generic_set_fn set = hostif_api.set_hostif_trap_group_attribute;
        sai_generic_get_fn get = hostif_api.get_hostif_trap_group_attribute;
        sai_create_hostif_trap_group_fn cr = NULL;
        sai_remove_hostif_trap_group_fn re = NULL;
        sai_set_hostif_trap_group_attribute_fn se = NULL;
        sai_get_hostif_trap_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_HOSTIF_TRAP_GROUP] = SAI_OBJECT_TYPE_HOSTIF_TRAP_GROUP;
    }
    {
        sai_policer_api_t policer_api = { 0 };
        sai_generic_create_fn create = policer_api.create_policer;
        sai_generic_remove_fn remove = policer_api.remove_policer;
        sai_generic_set_fn set = policer_api.set_policer_attribute;
        sai_generic_get_fn get = policer_api.get_policer_attribute;
        sai_create_policer_fn cr = NULL;
        sai_remove_policer_fn re = NULL;
        sai_set_policer_attribute_fn se = NULL;
        sai_get_policer_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_POLICER] = SAI_OBJECT_TYPE_POLICER;
    }
    {
        sai_wred_api_t wred_api = { 0 };
        sai_generic_create_fn create = wred_api.create_wred;
        sai_generic_remove_fn remove = wred_api.remove_wred;
        sai_generic_set_fn set = wred_api.set_wred_attribute;
        sai_generic_get_fn get = wred_api.get_wred_attribute;
        sai_create_wred_fn cr = NULL;
        sai_remove_wred_fn re = NULL;
        sai_set_wred_attribute_fn se = NULL;
        sai_get_wred_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_WRED] = SAI_OBJECT_TYPE_WRED;
    }
    {
        sai_qos_map_api_t qos_map_api = { 0 };
        sai_generic_create_fn create = qos_map_api.create_qos_map;
        sai_generic_remove_fn remove = qos_map_api.remove_qos_map;
        sai_generic_set_fn set = qos_map_api.set_qos_map_attribute;
        sai_generic_get_fn get = qos_map_api.get_qos_map_attribute;
        sai_create_qos_map_fn cr = NULL;
        sai_remove_qos_map_fn re = NULL;
        sai_set_qos_map_attribute_fn se = NULL;
        sai_get_qos_map_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_QOS_MAP] = SAI_OBJECT_TYPE_QOS_MAP;
    }
    {
        sai_queue_api_t queue_api = { 0 };
        sai_generic_create_fn create = queue_api.create_queue;
        sai_generic_remove_fn remove = queue_api.remove_queue;
        sai_generic_set_fn set = queue_api.set_queue_attribute;
        sai_generic_get_fn get = queue_api.get_queue_attribute;
        sai_create_queue_fn cr = NULL;
        sai_remove_queue_fn re = NULL;
        sai_set_queue_attribute_fn se = NULL;
        sai_get_queue_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_QUEUE] = SAI_OBJECT_TYPE_QUEUE;
    }
    {
        sai_scheduler_api_t scheduler_api = { 0 };
        sai_generic_create_fn create = scheduler_api.create_scheduler;
        sai_generic_remove_fn remove = scheduler_api.remove_scheduler;
        sai_generic_set_fn set = scheduler_api.set_scheduler_attribute;
        sai_generic_get_fn get = scheduler_api.get_scheduler_attribute;
        sai_create_scheduler_fn cr = NULL;
        sai_remove_scheduler_fn re = NULL;
        sai_set_scheduler_attribute_fn se = NULL;
        sai_get_scheduler_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SCHEDULER] = SAI_OBJECT_TYPE_SCHEDULER;
    }
    {
        sai_scheduler_group_api_t scheduler_group_api = { 0 };
        sai_generic_create_fn create = scheduler_group_api.create_scheduler_group;
        sai_generic_remove_fn remove = scheduler_group_api.remove_scheduler_group;
        sai_generic_set_fn set = scheduler_group_api.set_scheduler_group_attribute;
        sai_generic_get_fn get = scheduler_group_api.get_scheduler_group_attribute;
        sai_create_scheduler_group_fn cr = NULL;
        sai_remove_scheduler_group_fn re = NULL;
        sai_set_scheduler_group_attribute_fn se = NULL;
        sai_get_scheduler_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SCHEDULER_GROUP] = SAI_OBJECT_TYPE_SCHEDULER_GROUP;
    }
    {
        sai_buffer_api_t buffer_api = { 0 };
        sai_generic_create_fn create = buffer_api.create_buffer_pool;
        sai_generic_remove_fn remove = buffer_api.remove_buffer_pool;
        sai_generic_set_fn set = buffer_api.set_buffer_pool_attribute;
        sai_generic_get_fn get = buffer_api.get_buffer_pool_attribute;
        sai_create_buffer_pool_fn cr = NULL;
        sai_remove_buffer_pool_fn re = NULL;
        sai_set_buffer_pool_attribute_fn se = NULL;
        sai_get_buffer_pool_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_BUFFER_POOL] = SAI_OBJECT_TYPE_BUFFER_POOL;
    }
    {
        sai_buffer_api_t buffer_api = { 0 };
        sai_generic_create_fn create = buffer_api.create_buffer_profile;
        sai_generic_remove_fn remove = buffer_api.remove_buffer_profile;
        sai_generic_set_fn set = buffer_api.set_buffer_profile_attribute;
        sai_generic_get_fn get = buffer_api.get_buffer_profile_attribute;
        sai_create_buffer_profile_fn cr = NULL;
        sai_remove_buffer_profile_fn re = NULL;
        sai_set_buffer_profile_attribute_fn se = NULL;
        sai_get_buffer_profile_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_BUFFER_PROFILE] = SAI_OBJECT_TYPE_BUFFER_PROFILE;
    }
    {
        sai_buffer_api_t buffer_api = { 0 };
        sai_generic_create_fn create = buffer_api.create_ingress_priority_group;
        sai_generic_remove_fn remove = buffer_api.remove_ingress_priority_group;
        sai_generic_set_fn set = buffer_api.set_ingress_priority_group_attribute;
        sai_generic_get_fn get = buffer_api.get_ingress_priority_group_attribute;
        sai_create_ingress_priority_group_fn cr = NULL;
        sai_remove_ingress_priority_group_fn re = NULL;
        sai_set_ingress_priority_group_attribute_fn se = NULL;
        sai_get_ingress_priority_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP] = SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP;
    }
    {
        sai_lag_api_t lag_api = { 0 };
        sai_generic_create_fn create = lag_api.create_lag_member;
        sai_generic_remove_fn remove = lag_api.remove_lag_member;
        sai_generic_set_fn set = lag_api.set_lag_member_attribute;
        sai_generic_get_fn get = lag_api.get_lag_member_attribute;
        sai_create_lag_member_fn cr = NULL;
        sai_remove_lag_member_fn re = NULL;
        sai_set_lag_member_attribute_fn se = NULL;
        sai_get_lag_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_LAG_MEMBER] = SAI_OBJECT_TYPE_LAG_MEMBER;
    }
    {
        sai_hash_api_t hash_api = { 0 };
        sai_generic_create_fn create = hash_api.create_hash;
        sai_generic_remove_fn remove = hash_api.remove_hash;
        sai_generic_set_fn set = hash_api.set_hash_attribute;
        sai_generic_get_fn get = hash_api.get_hash_attribute;
        sai_create_hash_fn cr = NULL;
        sai_remove_hash_fn re = NULL;
        sai_set_hash_attribute_fn se = NULL;
        sai_get_hash_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_HASH] = SAI_OBJECT_TYPE_HASH;
    }
    {
        sai_udf_api_t udf_api = { 0 };
        sai_generic_create_fn create = udf_api.create_udf;
        sai_generic_remove_fn remove = udf_api.remove_udf;
        sai_generic_set_fn set = udf_api.set_udf_attribute;
        sai_generic_get_fn get = udf_api.get_udf_attribute;
        sai_create_udf_fn cr = NULL;
        sai_remove_udf_fn re = NULL;
        sai_set_udf_attribute_fn se = NULL;
        sai_get_udf_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_UDF] = SAI_OBJECT_TYPE_UDF;
    }
    {
        sai_udf_api_t udf_api = { 0 };
        sai_generic_create_fn create = udf_api.create_udf_match;
        sai_generic_remove_fn remove = udf_api.remove_udf_match;
        sai_generic_set_fn set = udf_api.set_udf_match_attribute;
        sai_generic_get_fn get = udf_api.get_udf_match_attribute;
        sai_create_udf_match_fn cr = NULL;
        sai_remove_udf_match_fn re = NULL;
        sai_set_udf_match_attribute_fn se = NULL;
        sai_get_udf_match_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_UDF_MATCH] = SAI_OBJECT_TYPE_UDF_MATCH;
    }
    {
        sai_udf_api_t udf_api = { 0 };
        sai_generic_create_fn create = udf_api.create_udf_group;
        sai_generic_remove_fn remove = udf_api.remove_udf_group;
        sai_generic_set_fn set = udf_api.set_udf_group_attribute;
        sai_generic_get_fn get = udf_api.get_udf_group_attribute;
        sai_create_udf_group_fn cr = NULL;
        sai_remove_udf_group_fn re = NULL;
        sai_set_udf_group_attribute_fn se = NULL;
        sai_get_udf_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_UDF_GROUP] = SAI_OBJECT_TYPE_UDF_GROUP;
    }
    {
        sai_fdb_api_t fdb_api = { 0 };
        typedef sai_status_t (*fdb_entry_create_fn)(\
                _In_ const sai_fdb_entry_t *fdb_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*fdb_entry_remove_fn)(\
                _In_ const sai_fdb_entry_t *fdb_entry);
        typedef sai_status_t (*fdb_entry_set_fn)(\
                _In_ const sai_fdb_entry_t *fdb_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*fdb_entry_get_fn)(\
                _In_ const sai_fdb_entry_t *fdb_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        fdb_entry_create_fn create = fdb_api.create_fdb_entry;
        fdb_entry_remove_fn remove = fdb_api.remove_fdb_entry;
        fdb_entry_set_fn set = fdb_api.set_fdb_entry_attribute;
        fdb_entry_get_fn get = fdb_api.get_fdb_entry_attribute;
        sai_create_fdb_entry_fn cr = NULL;
        sai_remove_fdb_entry_fn re = NULL;
        sai_set_fdb_entry_attribute_fn se = NULL;
        sai_get_fdb_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_FDB_ENTRY] = SAI_OBJECT_TYPE_FDB_ENTRY;
    }
    {
        sai_switch_api_t switch_api = { 0 };
        sai_create_switch_fn create = switch_api.create_switch;
        sai_generic_remove_fn remove = switch_api.remove_switch;
        sai_generic_set_fn set = switch_api.set_switch_attribute;
        sai_generic_get_fn get = switch_api.get_switch_attribute;
        sai_create_switch_fn cr = NULL;
        sai_remove_switch_fn re = NULL;
        sai_set_switch_attribute_fn se = NULL;
        sai_get_switch_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SWITCH] = SAI_OBJECT_TYPE_SWITCH;
    }
    {
        sai_hostif_api_t hostif_api = { 0 };
        sai_generic_create_fn create = hostif_api.create_hostif_trap;
        sai_generic_remove_fn remove = hostif_api.remove_hostif_trap;
        sai_generic_set_fn set = hostif_api.set_hostif_trap_attribute;
        sai_generic_get_fn get = hostif_api.get_hostif_trap_attribute;
        sai_create_hostif_trap_fn cr = NULL;
        sai_remove_hostif_trap_fn re = NULL;
        sai_set_hostif_trap_attribute_fn se = NULL;
        sai_get_hostif_trap_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_HOSTIF_TRAP] = SAI_OBJECT_TYPE_HOSTIF_TRAP;
    }
    {
        sai_hostif_api_t hostif_api = { 0 };
        sai_generic_create_fn create = hostif_api.create_hostif_table_entry;
        sai_generic_remove_fn remove = hostif_api.remove_hostif_table_entry;
        sai_generic_set_fn set = hostif_api.set_hostif_table_entry_attribute;
        sai_generic_get_fn get = hostif_api.get_hostif_table_entry_attribute;
        sai_create_hostif_table_entry_fn cr = NULL;
        sai_remove_hostif_table_entry_fn re = NULL;
        sai_set_hostif_table_entry_attribute_fn se = NULL;
        sai_get_hostif_table_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_HOSTIF_TABLE_ENTRY] = SAI_OBJECT_TYPE_HOSTIF_TABLE_ENTRY;
    }
    {
        sai_neighbor_api_t neighbor_api = { 0 };
        typedef sai_status_t (*neighbor_entry_create_fn)(\
                _In_ const sai_neighbor_entry_t *neighbor_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*neighbor_entry_remove_fn)(\
                _In_ const sai_neighbor_entry_t *neighbor_entry);
        typedef sai_status_t (*neighbor_entry_set_fn)(\
                _In_ const sai_neighbor_entry_t *neighbor_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*neighbor_entry_get_fn)(\
                _In_ const sai_neighbor_entry_t *neighbor_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        neighbor_entry_create_fn create = neighbor_api.create_neighbor_entry;
        neighbor_entry_remove_fn remove = neighbor_api.remove_neighbor_entry;
        neighbor_entry_set_fn set = neighbor_api.set_neighbor_entry_attribute;
        neighbor_entry_get_fn get = neighbor_api.get_neighbor_entry_attribute;
        sai_create_neighbor_entry_fn cr = NULL;
        sai_remove_neighbor_entry_fn re = NULL;
        sai_set_neighbor_entry_attribute_fn se = NULL;
        sai_get_neighbor_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NEIGHBOR_ENTRY] = SAI_OBJECT_TYPE_NEIGHBOR_ENTRY;
    }
    {
        sai_route_api_t route_api = { 0 };
        typedef sai_status_t (*route_entry_create_fn)(\
                _In_ const sai_route_entry_t *route_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*route_entry_remove_fn)(\
                _In_ const sai_route_entry_t *route_entry);
        typedef sai_status_t (*route_entry_set_fn)(\
                _In_ const sai_route_entry_t *route_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*route_entry_get_fn)(\
                _In_ const sai_route_entry_t *route_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        route_entry_create_fn create = route_api.create_route_entry;
        route_entry_remove_fn remove = route_api.remove_route_entry;
        route_entry_set_fn set = route_api.set_route_entry_attribute;
        route_entry_get_fn get = route_api.get_route_entry_attribute;
        sai_create_route_entry_fn cr = NULL;
        sai_remove_route_entry_fn re = NULL;
        sai_set_route_entry_attribute_fn se = NULL;
        sai_get_route_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ROUTE_ENTRY] = SAI_OBJECT_TYPE_ROUTE_ENTRY;
    }
    {
        sai_vlan_api_t vlan_api = { 0 };
        sai_generic_create_fn create = vlan_api.create_vlan;
        sai_generic_remove_fn remove = vlan_api.remove_vlan;
        sai_generic_set_fn set = vlan_api.set_vlan_attribute;
        sai_generic_get_fn get = vlan_api.get_vlan_attribute;
        sai_create_vlan_fn cr = NULL;
        sai_remove_vlan_fn re = NULL;
        sai_set_vlan_attribute_fn se = NULL;
        sai_get_vlan_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_VLAN] = SAI_OBJECT_TYPE_VLAN;
    }
    {
        sai_vlan_api_t vlan_api = { 0 };
        sai_generic_create_fn create = vlan_api.create_vlan_member;
        sai_generic_remove_fn remove = vlan_api.remove_vlan_member;
        sai_generic_set_fn set = vlan_api.set_vlan_member_attribute;
        sai_generic_get_fn get = vlan_api.get_vlan_member_attribute;
        sai_create_vlan_member_fn cr = NULL;
        sai_remove_vlan_member_fn re = NULL;
        sai_set_vlan_member_attribute_fn se = NULL;
        sai_get_vlan_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_VLAN_MEMBER] = SAI_OBJECT_TYPE_VLAN_MEMBER;
    }
    checked[(int)SAI_OBJECT_TYPE_HOSTIF_PACKET] = SAI_OBJECT_TYPE_HOSTIF_PACKET;
    {
        sai_tunnel_api_t tunnel_api = { 0 };
        sai_generic_create_fn create = tunnel_api.create_tunnel_map;
        sai_generic_remove_fn remove = tunnel_api.remove_tunnel_map;
        sai_generic_set_fn set = tunnel_api.set_tunnel_map_attribute;
        sai_generic_get_fn get = tunnel_api.get_tunnel_map_attribute;
        sai_create_tunnel_map_fn cr = NULL;
        sai_remove_tunnel_map_fn re = NULL;
        sai_set_tunnel_map_attribute_fn se = NULL;
        sai_get_tunnel_map_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TUNNEL_MAP] = SAI_OBJECT_TYPE_TUNNEL_MAP;
    }
    {
        sai_tunnel_api_t tunnel_api = { 0 };
        sai_generic_create_fn create = tunnel_api.create_tunnel;
        sai_generic_remove_fn remove = tunnel_api.remove_tunnel;
        sai_generic_set_fn set = tunnel_api.set_tunnel_attribute;
        sai_generic_get_fn get = tunnel_api.get_tunnel_attribute;
        sai_create_tunnel_fn cr = NULL;
        sai_remove_tunnel_fn re = NULL;
        sai_set_tunnel_attribute_fn se = NULL;
        sai_get_tunnel_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TUNNEL] = SAI_OBJECT_TYPE_TUNNEL;
    }
    {
        sai_tunnel_api_t tunnel_api = { 0 };
        sai_generic_create_fn create = tunnel_api.create_tunnel_term_table_entry;
        sai_generic_remove_fn remove = tunnel_api.remove_tunnel_term_table_entry;
        sai_generic_set_fn set = tunnel_api.set_tunnel_term_table_entry_attribute;
        sai_generic_get_fn get = tunnel_api.get_tunnel_term_table_entry_attribute;
        sai_create_tunnel_term_table_entry_fn cr = NULL;
        sai_remove_tunnel_term_table_entry_fn re = NULL;
        sai_set_tunnel_term_table_entry_attribute_fn se = NULL;
        sai_get_tunnel_term_table_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TUNNEL_TERM_TABLE_ENTRY] = SAI_OBJECT_TYPE_TUNNEL_TERM_TABLE_ENTRY;
    }
    checked[(int)SAI_OBJECT_TYPE_FDB_FLUSH] = SAI_OBJECT_TYPE_FDB_FLUSH;
    {
        sai_next_hop_group_api_t next_hop_group_api = { 0 };
        sai_generic_create_fn create = next_hop_group_api.create_next_hop_group_member;
        sai_generic_remove_fn remove = next_hop_group_api.remove_next_hop_group_member;
        sai_generic_set_fn set = next_hop_group_api.set_next_hop_group_member_attribute;
        sai_generic_get_fn get = next_hop_group_api.get_next_hop_group_member_attribute;
        sai_create_next_hop_group_member_fn cr = NULL;
        sai_remove_next_hop_group_member_fn re = NULL;
        sai_set_next_hop_group_member_attribute_fn se = NULL;
        sai_get_next_hop_group_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NEXT_HOP_GROUP_MEMBER] = SAI_OBJECT_TYPE_NEXT_HOP_GROUP_MEMBER;
    }
    {
        sai_stp_api_t stp_api = { 0 };
        sai_generic_create_fn create = stp_api.create_stp_port;
        sai_generic_remove_fn remove = stp_api.remove_stp_port;
        sai_generic_set_fn set = stp_api.set_stp_port_attribute;
        sai_generic_get_fn get = stp_api.get_stp_port_attribute;
        sai_create_stp_port_fn cr = NULL;
        sai_remove_stp_port_fn re = NULL;
        sai_set_stp_port_attribute_fn se = NULL;
        sai_get_stp_port_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_STP_PORT] = SAI_OBJECT_TYPE_STP_PORT;
    }
    {
        sai_rpf_group_api_t rpf_group_api = { 0 };
        sai_generic_create_fn create = rpf_group_api.create_rpf_group;
        sai_generic_remove_fn remove = rpf_group_api.remove_rpf_group;
        sai_generic_set_fn set = rpf_group_api.set_rpf_group_attribute;
        sai_generic_get_fn get = rpf_group_api.get_rpf_group_attribute;
        sai_create_rpf_group_fn cr = NULL;
        sai_remove_rpf_group_fn re = NULL;
        sai_set_rpf_group_attribute_fn se = NULL;
        sai_get_rpf_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_RPF_GROUP] = SAI_OBJECT_TYPE_RPF_GROUP;
    }
    {
        sai_rpf_group_api_t rpf_group_api = { 0 };
        sai_generic_create_fn create = rpf_group_api.create_rpf_group_member;
        sai_generic_remove_fn remove = rpf_group_api.remove_rpf_group_member;
        sai_generic_set_fn set = rpf_group_api.set_rpf_group_member_attribute;
        sai_generic_get_fn get = rpf_group_api.get_rpf_group_member_attribute;
        sai_create_rpf_group_member_fn cr = NULL;
        sai_remove_rpf_group_member_fn re = NULL;
        sai_set_rpf_group_member_attribute_fn se = NULL;
        sai_get_rpf_group_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_RPF_GROUP_MEMBER] = SAI_OBJECT_TYPE_RPF_GROUP_MEMBER;
    }
    {
        sai_l2mc_group_api_t l2mc_group_api = { 0 };
        sai_generic_create_fn create = l2mc_group_api.create_l2mc_group;
        sai_generic_remove_fn remove = l2mc_group_api.remove_l2mc_group;
        sai_generic_set_fn set = l2mc_group_api.set_l2mc_group_attribute;
        sai_generic_get_fn get = l2mc_group_api.get_l2mc_group_attribute;
        sai_create_l2mc_group_fn cr = NULL;
        sai_remove_l2mc_group_fn re = NULL;
        sai_set_l2mc_group_attribute_fn se = NULL;
        sai_get_l2mc_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_L2MC_GROUP] = SAI_OBJECT_TYPE_L2MC_GROUP;
    }
    {
        sai_l2mc_group_api_t l2mc_group_api = { 0 };
        sai_generic_create_fn create = l2mc_group_api.create_l2mc_group_member;
        sai_generic_remove_fn remove = l2mc_group_api.remove_l2mc_group_member;
        sai_generic_set_fn set = l2mc_group_api.set_l2mc_group_member_attribute;
        sai_generic_get_fn get = l2mc_group_api.get_l2mc_group_member_attribute;
        sai_create_l2mc_group_member_fn cr = NULL;
        sai_remove_l2mc_group_member_fn re = NULL;
        sai_set_l2mc_group_member_attribute_fn se = NULL;
        sai_get_l2mc_group_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_L2MC_GROUP_MEMBER] = SAI_OBJECT_TYPE_L2MC_GROUP_MEMBER;
    }
    {
        sai_ipmc_group_api_t ipmc_group_api = { 0 };
        sai_generic_create_fn create = ipmc_group_api.create_ipmc_group;
        sai_generic_remove_fn remove = ipmc_group_api.remove_ipmc_group;
        sai_generic_set_fn set = ipmc_group_api.set_ipmc_group_attribute;
        sai_generic_get_fn get = ipmc_group_api.get_ipmc_group_attribute;
        sai_create_ipmc_group_fn cr = NULL;
        sai_remove_ipmc_group_fn re = NULL;
        sai_set_ipmc_group_attribute_fn se = NULL;
        sai_get_ipmc_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_IPMC_GROUP] = SAI_OBJECT_TYPE_IPMC_GROUP;
    }
    {
        sai_ipmc_group_api_t ipmc_group_api = { 0 };
        sai_generic_create_fn create = ipmc_group_api.create_ipmc_group_member;
        sai_generic_remove_fn remove = ipmc_group_api.remove_ipmc_group_member;
        sai_generic_set_fn set = ipmc_group_api.set_ipmc_group_member_attribute;
        sai_generic_get_fn get = ipmc_group_api.get_ipmc_group_member_attribute;
        sai_create_ipmc_group_member_fn cr = NULL;
        sai_remove_ipmc_group_member_fn re = NULL;
        sai_set_ipmc_group_member_attribute_fn se = NULL;
        sai_get_ipmc_group_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_IPMC_GROUP_MEMBER] = SAI_OBJECT_TYPE_IPMC_GROUP_MEMBER;
    }
    {
        sai_l2mc_api_t l2mc_api = { 0 };
        typedef sai_status_t (*l2mc_entry_create_fn)(\
                _In_ const sai_l2mc_entry_t *l2mc_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*l2mc_entry_remove_fn)(\
                _In_ const sai_l2mc_entry_t *l2mc_entry);
        typedef sai_status_t (*l2mc_entry_set_fn)(\
                _In_ const sai_l2mc_entry_t *l2mc_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*l2mc_entry_get_fn)(\
                _In_ const sai_l2mc_entry_t *l2mc_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        l2mc_entry_create_fn create = l2mc_api.create_l2mc_entry;
        l2mc_entry_remove_fn remove = l2mc_api.remove_l2mc_entry;
        l2mc_entry_set_fn set = l2mc_api.set_l2mc_entry_attribute;
        l2mc_entry_get_fn get = l2mc_api.get_l2mc_entry_attribute;
        sai_create_l2mc_entry_fn cr = NULL;
        sai_remove_l2mc_entry_fn re = NULL;
        sai_set_l2mc_entry_attribute_fn se = NULL;
        sai_get_l2mc_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_L2MC_ENTRY] = SAI_OBJECT_TYPE_L2MC_ENTRY;
    }
    {
        sai_ipmc_api_t ipmc_api = { 0 };
        typedef sai_status_t (*ipmc_entry_create_fn)(\
                _In_ const sai_ipmc_entry_t *ipmc_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*ipmc_entry_remove_fn)(\
                _In_ const sai_ipmc_entry_t *ipmc_entry);
        typedef sai_status_t (*ipmc_entry_set_fn)(\
                _In_ const sai_ipmc_entry_t *ipmc_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*ipmc_entry_get_fn)(\
                _In_ const sai_ipmc_entry_t *ipmc_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        ipmc_entry_create_fn create = ipmc_api.create_ipmc_entry;
        ipmc_entry_remove_fn remove = ipmc_api.remove_ipmc_entry;
        ipmc_entry_set_fn set = ipmc_api.set_ipmc_entry_attribute;
        ipmc_entry_get_fn get = ipmc_api.get_ipmc_entry_attribute;
        sai_create_ipmc_entry_fn cr = NULL;
        sai_remove_ipmc_entry_fn re = NULL;
        sai_set_ipmc_entry_attribute_fn se = NULL;
        sai_get_ipmc_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_IPMC_ENTRY] = SAI_OBJECT_TYPE_IPMC_ENTRY;
    }
    {
        sai_mcast_fdb_api_t mcast_fdb_api = { 0 };
        typedef sai_status_t (*mcast_fdb_entry_create_fn)(\
                _In_ const sai_mcast_fdb_entry_t *mcast_fdb_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*mcast_fdb_entry_remove_fn)(\
                _In_ const sai_mcast_fdb_entry_t *mcast_fdb_entry);
        typedef sai_status_t (*mcast_fdb_entry_set_fn)(\
                _In_ const sai_mcast_fdb_entry_t *mcast_fdb_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*mcast_fdb_entry_get_fn)(\
                _In_ const sai_mcast_fdb_entry_t *mcast_fdb_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        mcast_fdb_entry_create_fn create = mcast_fdb_api.create_mcast_fdb_entry;
        mcast_fdb_entry_remove_fn remove = mcast_fdb_api.remove_mcast_fdb_entry;
        mcast_fdb_entry_set_fn set = mcast_fdb_api.set_mcast_fdb_entry_attribute;
        mcast_fdb_entry_get_fn get = mcast_fdb_api.get_mcast_fdb_entry_attribute;
        sai_create_mcast_fdb_entry_fn cr = NULL;
        sai_remove_mcast_fdb_entry_fn re = NULL;
        sai_set_mcast_fdb_entry_attribute_fn se = NULL;
        sai_get_mcast_fdb_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MCAST_FDB_ENTRY] = SAI_OBJECT_TYPE_MCAST_FDB_ENTRY;
    }
    {
        sai_hostif_api_t hostif_api = { 0 };
        sai_generic_create_fn create = hostif_api.create_hostif_user_defined_trap;
        sai_generic_remove_fn remove = hostif_api.remove_hostif_user_defined_trap;
        sai_generic_set_fn set = hostif_api.set_hostif_user_defined_trap_attribute;
        sai_generic_get_fn get = hostif_api.get_hostif_user_defined_trap_attribute;
        sai_create_hostif_user_defined_trap_fn cr = NULL;
        sai_remove_hostif_user_defined_trap_fn re = NULL;
        sai_set_hostif_user_defined_trap_attribute_fn se = NULL;
        sai_get_hostif_user_defined_trap_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_HOSTIF_USER_DEFINED_TRAP] = SAI_OBJECT_TYPE_HOSTIF_USER_DEFINED_TRAP;
    }
    {
        sai_bridge_api_t bridge_api = { 0 };
        sai_generic_create_fn create = bridge_api.create_bridge;
        sai_generic_remove_fn remove = bridge_api.remove_bridge;
        sai_generic_set_fn set = bridge_api.set_bridge_attribute;
        sai_generic_get_fn get = bridge_api.get_bridge_attribute;
        sai_create_bridge_fn cr = NULL;
        sai_remove_bridge_fn re = NULL;
        sai_set_bridge_attribute_fn se = NULL;
        sai_get_bridge_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_BRIDGE] = SAI_OBJECT_TYPE_BRIDGE;
    }
    {
        sai_bridge_api_t bridge_api = { 0 };
        sai_generic_create_fn create = bridge_api.create_bridge_port;
        sai_generic_remove_fn remove = bridge_api.remove_bridge_port;
        sai_generic_set_fn set = bridge_api.set_bridge_port_attribute;
        sai_generic_get_fn get = bridge_api.get_bridge_port_attribute;
        sai_create_bridge_port_fn cr = NULL;
        sai_remove_bridge_port_fn re = NULL;
        sai_set_bridge_port_attribute_fn se = NULL;
        sai_get_bridge_port_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_BRIDGE_PORT] = SAI_OBJECT_TYPE_BRIDGE_PORT;
    }
    {
        sai_tunnel_api_t tunnel_api = { 0 };
        sai_generic_create_fn create = tunnel_api.create_tunnel_map_entry;
        sai_generic_remove_fn remove = tunnel_api.remove_tunnel_map_entry;
        sai_generic_set_fn set = tunnel_api.set_tunnel_map_entry_attribute;
        sai_generic_get_fn get = tunnel_api.get_tunnel_map_entry_attribute;
        sai_create_tunnel_map_entry_fn cr = NULL;
        sai_remove_tunnel_map_entry_fn re = NULL;
        sai_set_tunnel_map_entry_attribute_fn se = NULL;
        sai_get_tunnel_map_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TUNNEL_MAP_ENTRY] = SAI_OBJECT_TYPE_TUNNEL_MAP_ENTRY;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam;
        sai_generic_remove_fn remove = tam_api.remove_tam;
        sai_generic_set_fn set = tam_api.set_tam_attribute;
        sai_generic_get_fn get = tam_api.get_tam_attribute;
        sai_create_tam_fn cr = NULL;
        sai_remove_tam_fn re = NULL;
        sai_set_tam_attribute_fn se = NULL;
        sai_get_tam_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM] = SAI_OBJECT_TYPE_TAM;
    }
    {
        sai_srv6_api_t srv6_api = { 0 };
        sai_generic_create_fn create = srv6_api.create_srv6_sidlist;
        sai_generic_remove_fn remove = srv6_api.remove_srv6_sidlist;
        sai_generic_set_fn set = srv6_api.set_srv6_sidlist_attribute;
        sai_generic_get_fn get = srv6_api.get_srv6_sidlist_attribute;
        sai_create_srv6_sidlist_fn cr = NULL;
        sai_remove_srv6_sidlist_fn re = NULL;
        sai_set_srv6_sidlist_attribute_fn se = NULL;
        sai_get_srv6_sidlist_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SRV6_SIDLIST] = SAI_OBJECT_TYPE_SRV6_SIDLIST;
    }
    {
        sai_port_api_t port_api = { 0 };
        sai_generic_create_fn create = port_api.create_port_pool;
        sai_generic_remove_fn remove = port_api.remove_port_pool;
        sai_generic_set_fn set = port_api.set_port_pool_attribute;
        sai_generic_get_fn get = port_api.get_port_pool_attribute;
        sai_create_port_pool_fn cr = NULL;
        sai_remove_port_pool_fn re = NULL;
        sai_set_port_pool_attribute_fn se = NULL;
        sai_get_port_pool_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_PORT_POOL] = SAI_OBJECT_TYPE_PORT_POOL;
    }
    {
        sai_mpls_api_t mpls_api = { 0 };
        typedef sai_status_t (*inseg_entry_create_fn)(\
                _In_ const sai_inseg_entry_t *inseg_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*inseg_entry_remove_fn)(\
                _In_ const sai_inseg_entry_t *inseg_entry);
        typedef sai_status_t (*inseg_entry_set_fn)(\
                _In_ const sai_inseg_entry_t *inseg_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*inseg_entry_get_fn)(\
                _In_ const sai_inseg_entry_t *inseg_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        inseg_entry_create_fn create = mpls_api.create_inseg_entry;
        inseg_entry_remove_fn remove = mpls_api.remove_inseg_entry;
        inseg_entry_set_fn set = mpls_api.set_inseg_entry_attribute;
        inseg_entry_get_fn get = mpls_api.get_inseg_entry_attribute;
        sai_create_inseg_entry_fn cr = NULL;
        sai_remove_inseg_entry_fn re = NULL;
        sai_set_inseg_entry_attribute_fn se = NULL;
        sai_get_inseg_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_INSEG_ENTRY] = SAI_OBJECT_TYPE_INSEG_ENTRY;
    }
    {
        sai_dtel_api_t dtel_api = { 0 };
        sai_generic_create_fn create = dtel_api.create_dtel;
        sai_generic_remove_fn remove = dtel_api.remove_dtel;
        sai_generic_set_fn set = dtel_api.set_dtel_attribute;
        sai_generic_get_fn get = dtel_api.get_dtel_attribute;
        sai_create_dtel_fn cr = NULL;
        sai_remove_dtel_fn re = NULL;
        sai_set_dtel_attribute_fn se = NULL;
        sai_get_dtel_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_DTEL] = SAI_OBJECT_TYPE_DTEL;
    }
    {
        sai_dtel_api_t dtel_api = { 0 };
        sai_generic_create_fn create = dtel_api.create_dtel_queue_report;
        sai_generic_remove_fn remove = dtel_api.remove_dtel_queue_report;
        sai_generic_set_fn set = dtel_api.set_dtel_queue_report_attribute;
        sai_generic_get_fn get = dtel_api.get_dtel_queue_report_attribute;
        sai_create_dtel_queue_report_fn cr = NULL;
        sai_remove_dtel_queue_report_fn re = NULL;
        sai_set_dtel_queue_report_attribute_fn se = NULL;
        sai_get_dtel_queue_report_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_DTEL_QUEUE_REPORT] = SAI_OBJECT_TYPE_DTEL_QUEUE_REPORT;
    }
    {
        sai_dtel_api_t dtel_api = { 0 };
        sai_generic_create_fn create = dtel_api.create_dtel_int_session;
        sai_generic_remove_fn remove = dtel_api.remove_dtel_int_session;
        sai_generic_set_fn set = dtel_api.set_dtel_int_session_attribute;
        sai_generic_get_fn get = dtel_api.get_dtel_int_session_attribute;
        sai_create_dtel_int_session_fn cr = NULL;
        sai_remove_dtel_int_session_fn re = NULL;
        sai_set_dtel_int_session_attribute_fn se = NULL;
        sai_get_dtel_int_session_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_DTEL_INT_SESSION] = SAI_OBJECT_TYPE_DTEL_INT_SESSION;
    }
    {
        sai_dtel_api_t dtel_api = { 0 };
        sai_generic_create_fn create = dtel_api.create_dtel_report_session;
        sai_generic_remove_fn remove = dtel_api.remove_dtel_report_session;
        sai_generic_set_fn set = dtel_api.set_dtel_report_session_attribute;
        sai_generic_get_fn get = dtel_api.get_dtel_report_session_attribute;
        sai_create_dtel_report_session_fn cr = NULL;
        sai_remove_dtel_report_session_fn re = NULL;
        sai_set_dtel_report_session_attribute_fn se = NULL;
        sai_get_dtel_report_session_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_DTEL_REPORT_SESSION] = SAI_OBJECT_TYPE_DTEL_REPORT_SESSION;
    }
    {
        sai_dtel_api_t dtel_api = { 0 };
        sai_generic_create_fn create = dtel_api.create_dtel_event;
        sai_generic_remove_fn remove = dtel_api.remove_dtel_event;
        sai_generic_set_fn set = dtel_api.set_dtel_event_attribute;
        sai_generic_get_fn get = dtel_api.get_dtel_event_attribute;
        sai_create_dtel_event_fn cr = NULL;
        sai_remove_dtel_event_fn re = NULL;
        sai_set_dtel_event_attribute_fn se = NULL;
        sai_get_dtel_event_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_DTEL_EVENT] = SAI_OBJECT_TYPE_DTEL_EVENT;
    }
    {
        sai_bfd_api_t bfd_api = { 0 };
        sai_generic_create_fn create = bfd_api.create_bfd_session;
        sai_generic_remove_fn remove = bfd_api.remove_bfd_session;
        sai_generic_set_fn set = bfd_api.set_bfd_session_attribute;
        sai_generic_get_fn get = bfd_api.get_bfd_session_attribute;
        sai_create_bfd_session_fn cr = NULL;
        sai_remove_bfd_session_fn re = NULL;
        sai_set_bfd_session_attribute_fn se = NULL;
        sai_get_bfd_session_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_BFD_SESSION] = SAI_OBJECT_TYPE_BFD_SESSION;
    }
    {
        sai_isolation_group_api_t isolation_group_api = { 0 };
        sai_generic_create_fn create = isolation_group_api.create_isolation_group;
        sai_generic_remove_fn remove = isolation_group_api.remove_isolation_group;
        sai_generic_set_fn set = isolation_group_api.set_isolation_group_attribute;
        sai_generic_get_fn get = isolation_group_api.get_isolation_group_attribute;
        sai_create_isolation_group_fn cr = NULL;
        sai_remove_isolation_group_fn re = NULL;
        sai_set_isolation_group_attribute_fn se = NULL;
        sai_get_isolation_group_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ISOLATION_GROUP] = SAI_OBJECT_TYPE_ISOLATION_GROUP;
    }
    {
        sai_isolation_group_api_t isolation_group_api = { 0 };
        sai_generic_create_fn create = isolation_group_api.create_isolation_group_member;
        sai_generic_remove_fn remove = isolation_group_api.remove_isolation_group_member;
        sai_generic_set_fn set = isolation_group_api.set_isolation_group_member_attribute;
        sai_generic_get_fn get = isolation_group_api.get_isolation_group_member_attribute;
        sai_create_isolation_group_member_fn cr = NULL;
        sai_remove_isolation_group_member_fn re = NULL;
        sai_set_isolation_group_member_attribute_fn se = NULL;
        sai_get_isolation_group_member_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_ISOLATION_GROUP_MEMBER] = SAI_OBJECT_TYPE_ISOLATION_GROUP_MEMBER;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_math_func;
        sai_generic_remove_fn remove = tam_api.remove_tam_math_func;
        sai_generic_set_fn set = tam_api.set_tam_math_func_attribute;
        sai_generic_get_fn get = tam_api.get_tam_math_func_attribute;
        sai_create_tam_math_func_fn cr = NULL;
        sai_remove_tam_math_func_fn re = NULL;
        sai_set_tam_math_func_attribute_fn se = NULL;
        sai_get_tam_math_func_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_MATH_FUNC] = SAI_OBJECT_TYPE_TAM_MATH_FUNC;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_report;
        sai_generic_remove_fn remove = tam_api.remove_tam_report;
        sai_generic_set_fn set = tam_api.set_tam_report_attribute;
        sai_generic_get_fn get = tam_api.get_tam_report_attribute;
        sai_create_tam_report_fn cr = NULL;
        sai_remove_tam_report_fn re = NULL;
        sai_set_tam_report_attribute_fn se = NULL;
        sai_get_tam_report_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_REPORT] = SAI_OBJECT_TYPE_TAM_REPORT;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_event_threshold;
        sai_generic_remove_fn remove = tam_api.remove_tam_event_threshold;
        sai_generic_set_fn set = tam_api.set_tam_event_threshold_attribute;
        sai_generic_get_fn get = tam_api.get_tam_event_threshold_attribute;
        sai_create_tam_event_threshold_fn cr = NULL;
        sai_remove_tam_event_threshold_fn re = NULL;
        sai_set_tam_event_threshold_attribute_fn se = NULL;
        sai_get_tam_event_threshold_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_EVENT_THRESHOLD] = SAI_OBJECT_TYPE_TAM_EVENT_THRESHOLD;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_tel_type;
        sai_generic_remove_fn remove = tam_api.remove_tam_tel_type;
        sai_generic_set_fn set = tam_api.set_tam_tel_type_attribute;
        sai_generic_get_fn get = tam_api.get_tam_tel_type_attribute;
        sai_create_tam_tel_type_fn cr = NULL;
        sai_remove_tam_tel_type_fn re = NULL;
        sai_set_tam_tel_type_attribute_fn se = NULL;
        sai_get_tam_tel_type_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_TEL_TYPE] = SAI_OBJECT_TYPE_TAM_TEL_TYPE;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_transport;
        sai_generic_remove_fn remove = tam_api.remove_tam_transport;
        sai_generic_set_fn set = tam_api.set_tam_transport_attribute;
        sai_generic_get_fn get = tam_api.get_tam_transport_attribute;
        sai_create_tam_transport_fn cr = NULL;
        sai_remove_tam_transport_fn re = NULL;
        sai_set_tam_transport_attribute_fn se = NULL;
        sai_get_tam_transport_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_TRANSPORT] = SAI_OBJECT_TYPE_TAM_TRANSPORT;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_telemetry;
        sai_generic_remove_fn remove = tam_api.remove_tam_telemetry;
        sai_generic_set_fn set = tam_api.set_tam_telemetry_attribute;
        sai_generic_get_fn get = tam_api.get_tam_telemetry_attribute;
        sai_create_tam_telemetry_fn cr = NULL;
        sai_remove_tam_telemetry_fn re = NULL;
        sai_set_tam_telemetry_attribute_fn se = NULL;
        sai_get_tam_telemetry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_TELEMETRY] = SAI_OBJECT_TYPE_TAM_TELEMETRY;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_collector;
        sai_generic_remove_fn remove = tam_api.remove_tam_collector;
        sai_generic_set_fn set = tam_api.set_tam_collector_attribute;
        sai_generic_get_fn get = tam_api.get_tam_collector_attribute;
        sai_create_tam_collector_fn cr = NULL;
        sai_remove_tam_collector_fn re = NULL;
        sai_set_tam_collector_attribute_fn se = NULL;
        sai_get_tam_collector_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_COLLECTOR] = SAI_OBJECT_TYPE_TAM_COLLECTOR;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_event_action;
        sai_generic_remove_fn remove = tam_api.remove_tam_event_action;
        sai_generic_set_fn set = tam_api.set_tam_event_action_attribute;
        sai_generic_get_fn get = tam_api.get_tam_event_action_attribute;
        sai_create_tam_event_action_fn cr = NULL;
        sai_remove_tam_event_action_fn re = NULL;
        sai_set_tam_event_action_attribute_fn se = NULL;
        sai_get_tam_event_action_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_EVENT_ACTION] = SAI_OBJECT_TYPE_TAM_EVENT_ACTION;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_event;
        sai_generic_remove_fn remove = tam_api.remove_tam_event;
        sai_generic_set_fn set = tam_api.set_tam_event_attribute;
        sai_generic_get_fn get = tam_api.get_tam_event_attribute;
        sai_create_tam_event_fn cr = NULL;
        sai_remove_tam_event_fn re = NULL;
        sai_set_tam_event_attribute_fn se = NULL;
        sai_get_tam_event_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_EVENT] = SAI_OBJECT_TYPE_TAM_EVENT;
    }
    {
        sai_nat_api_t nat_api = { 0 };
        sai_generic_create_fn create = nat_api.create_nat_zone_counter;
        sai_generic_remove_fn remove = nat_api.remove_nat_zone_counter;
        sai_generic_set_fn set = nat_api.set_nat_zone_counter_attribute;
        sai_generic_get_fn get = nat_api.get_nat_zone_counter_attribute;
        sai_create_nat_zone_counter_fn cr = NULL;
        sai_remove_nat_zone_counter_fn re = NULL;
        sai_set_nat_zone_counter_attribute_fn se = NULL;
        sai_get_nat_zone_counter_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NAT_ZONE_COUNTER] = SAI_OBJECT_TYPE_NAT_ZONE_COUNTER;
    }
    {
        sai_nat_api_t nat_api = { 0 };
        typedef sai_status_t (*nat_entry_create_fn)(\
                _In_ const sai_nat_entry_t *nat_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*nat_entry_remove_fn)(\
                _In_ const sai_nat_entry_t *nat_entry);
        typedef sai_status_t (*nat_entry_set_fn)(\
                _In_ const sai_nat_entry_t *nat_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*nat_entry_get_fn)(\
                _In_ const sai_nat_entry_t *nat_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        nat_entry_create_fn create = nat_api.create_nat_entry;
        nat_entry_remove_fn remove = nat_api.remove_nat_entry;
        nat_entry_set_fn set = nat_api.set_nat_entry_attribute;
        nat_entry_get_fn get = nat_api.get_nat_entry_attribute;
        sai_create_nat_entry_fn cr = NULL;
        sai_remove_nat_entry_fn re = NULL;
        sai_set_nat_entry_attribute_fn se = NULL;
        sai_get_nat_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NAT_ENTRY] = SAI_OBJECT_TYPE_NAT_ENTRY;
    }
    {
        sai_tam_api_t tam_api = { 0 };
        sai_generic_create_fn create = tam_api.create_tam_int;
        sai_generic_remove_fn remove = tam_api.remove_tam_int;
        sai_generic_set_fn set = tam_api.set_tam_int_attribute;
        sai_generic_get_fn get = tam_api.get_tam_int_attribute;
        sai_create_tam_int_fn cr = NULL;
        sai_remove_tam_int_fn re = NULL;
        sai_set_tam_int_attribute_fn se = NULL;
        sai_get_tam_int_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TAM_INT] = SAI_OBJECT_TYPE_TAM_INT;
    }
    {
        sai_counter_api_t counter_api = { 0 };
        sai_generic_create_fn create = counter_api.create_counter;
        sai_generic_remove_fn remove = counter_api.remove_counter;
        sai_generic_set_fn set = counter_api.set_counter_attribute;
        sai_generic_get_fn get = counter_api.get_counter_attribute;
        sai_create_counter_fn cr = NULL;
        sai_remove_counter_fn re = NULL;
        sai_set_counter_attribute_fn se = NULL;
        sai_get_counter_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_COUNTER] = SAI_OBJECT_TYPE_COUNTER;
    }
    {
        sai_debug_counter_api_t debug_counter_api = { 0 };
        sai_generic_create_fn create = debug_counter_api.create_debug_counter;
        sai_generic_remove_fn remove = debug_counter_api.remove_debug_counter;
        sai_generic_set_fn set = debug_counter_api.set_debug_counter_attribute;
        sai_generic_get_fn get = debug_counter_api.get_debug_counter_attribute;
        sai_create_debug_counter_fn cr = NULL;
        sai_remove_debug_counter_fn re = NULL;
        sai_set_debug_counter_attribute_fn se = NULL;
        sai_get_debug_counter_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_DEBUG_COUNTER] = SAI_OBJECT_TYPE_DEBUG_COUNTER;
    }
    {
        sai_port_api_t port_api = { 0 };
        sai_generic_create_fn create = port_api.create_port_connector;
        sai_generic_remove_fn remove = port_api.remove_port_connector;
        sai_generic_set_fn set = port_api.set_port_connector_attribute;
        sai_generic_get_fn get = port_api.get_port_connector_attribute;
        sai_create_port_connector_fn cr = NULL;
        sai_remove_port_connector_fn re = NULL;
        sai_set_port_connector_attribute_fn se = NULL;
        sai_get_port_connector_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_PORT_CONNECTOR] = SAI_OBJECT_TYPE_PORT_CONNECTOR;
    }
    {
        sai_port_api_t port_api = { 0 };
        sai_generic_create_fn create = port_api.create_port_serdes;
        sai_generic_remove_fn remove = port_api.remove_port_serdes;
        sai_generic_set_fn set = port_api.set_port_serdes_attribute;
        sai_generic_get_fn get = port_api.get_port_serdes_attribute;
        sai_create_port_serdes_fn cr = NULL;
        sai_remove_port_serdes_fn re = NULL;
        sai_set_port_serdes_attribute_fn se = NULL;
        sai_get_port_serdes_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_PORT_SERDES] = SAI_OBJECT_TYPE_PORT_SERDES;
    }
    {
        sai_macsec_api_t macsec_api = { 0 };
        sai_generic_create_fn create = macsec_api.create_macsec;
        sai_generic_remove_fn remove = macsec_api.remove_macsec;
        sai_generic_set_fn set = macsec_api.set_macsec_attribute;
        sai_generic_get_fn get = macsec_api.get_macsec_attribute;
        sai_create_macsec_fn cr = NULL;
        sai_remove_macsec_fn re = NULL;
        sai_set_macsec_attribute_fn se = NULL;
        sai_get_macsec_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MACSEC] = SAI_OBJECT_TYPE_MACSEC;
    }
    {
        sai_macsec_api_t macsec_api = { 0 };
        sai_generic_create_fn create = macsec_api.create_macsec_port;
        sai_generic_remove_fn remove = macsec_api.remove_macsec_port;
        sai_generic_set_fn set = macsec_api.set_macsec_port_attribute;
        sai_generic_get_fn get = macsec_api.get_macsec_port_attribute;
        sai_create_macsec_port_fn cr = NULL;
        sai_remove_macsec_port_fn re = NULL;
        sai_set_macsec_port_attribute_fn se = NULL;
        sai_get_macsec_port_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MACSEC_PORT] = SAI_OBJECT_TYPE_MACSEC_PORT;
    }
    {
        sai_macsec_api_t macsec_api = { 0 };
        sai_generic_create_fn create = macsec_api.create_macsec_flow;
        sai_generic_remove_fn remove = macsec_api.remove_macsec_flow;
        sai_generic_set_fn set = macsec_api.set_macsec_flow_attribute;
        sai_generic_get_fn get = macsec_api.get_macsec_flow_attribute;
        sai_create_macsec_flow_fn cr = NULL;
        sai_remove_macsec_flow_fn re = NULL;
        sai_set_macsec_flow_attribute_fn se = NULL;
        sai_get_macsec_flow_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MACSEC_FLOW] = SAI_OBJECT_TYPE_MACSEC_FLOW;
    }
    {
        sai_macsec_api_t macsec_api = { 0 };
        sai_generic_create_fn create = macsec_api.create_macsec_sc;
        sai_generic_remove_fn remove = macsec_api.remove_macsec_sc;
        sai_generic_set_fn set = macsec_api.set_macsec_sc_attribute;
        sai_generic_get_fn get = macsec_api.get_macsec_sc_attribute;
        sai_create_macsec_sc_fn cr = NULL;
        sai_remove_macsec_sc_fn re = NULL;
        sai_set_macsec_sc_attribute_fn se = NULL;
        sai_get_macsec_sc_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MACSEC_SC] = SAI_OBJECT_TYPE_MACSEC_SC;
    }
    {
        sai_macsec_api_t macsec_api = { 0 };
        sai_generic_create_fn create = macsec_api.create_macsec_sa;
        sai_generic_remove_fn remove = macsec_api.remove_macsec_sa;
        sai_generic_set_fn set = macsec_api.set_macsec_sa_attribute;
        sai_generic_get_fn get = macsec_api.get_macsec_sa_attribute;
        sai_create_macsec_sa_fn cr = NULL;
        sai_remove_macsec_sa_fn re = NULL;
        sai_set_macsec_sa_attribute_fn se = NULL;
        sai_get_macsec_sa_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MACSEC_SA] = SAI_OBJECT_TYPE_MACSEC_SA;
    }
    {
        sai_system_port_api_t system_port_api = { 0 };
        sai_generic_create_fn create = system_port_api.create_system_port;
        sai_generic_remove_fn remove = system_port_api.remove_system_port;
        sai_generic_set_fn set = system_port_api.set_system_port_attribute;
        sai_generic_get_fn get = system_port_api.get_system_port_attribute;
        sai_create_system_port_fn cr = NULL;
        sai_remove_system_port_fn re = NULL;
        sai_set_system_port_attribute_fn se = NULL;
        sai_get_system_port_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SYSTEM_PORT] = SAI_OBJECT_TYPE_SYSTEM_PORT;
    }
    {
        sai_hash_api_t hash_api = { 0 };
        sai_generic_create_fn create = hash_api.create_fine_grained_hash_field;
        sai_generic_remove_fn remove = hash_api.remove_fine_grained_hash_field;
        sai_generic_set_fn set = hash_api.set_fine_grained_hash_field_attribute;
        sai_generic_get_fn get = hash_api.get_fine_grained_hash_field_attribute;
        sai_create_fine_grained_hash_field_fn cr = NULL;
        sai_remove_fine_grained_hash_field_fn re = NULL;
        sai_set_fine_grained_hash_field_attribute_fn se = NULL;
        sai_get_fine_grained_hash_field_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_FINE_GRAINED_HASH_FIELD] = SAI_OBJECT_TYPE_FINE_GRAINED_HASH_FIELD;
    }
    {
        sai_switch_api_t switch_api = { 0 };
        sai_generic_create_fn create = switch_api.create_switch_tunnel;
        sai_generic_remove_fn remove = switch_api.remove_switch_tunnel;
        sai_generic_set_fn set = switch_api.set_switch_tunnel_attribute;
        sai_generic_get_fn get = switch_api.get_switch_tunnel_attribute;
        sai_create_switch_tunnel_fn cr = NULL;
        sai_remove_switch_tunnel_fn re = NULL;
        sai_set_switch_tunnel_attribute_fn se = NULL;
        sai_get_switch_tunnel_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_SWITCH_TUNNEL] = SAI_OBJECT_TYPE_SWITCH_TUNNEL;
    }
    {
        sai_srv6_api_t srv6_api = { 0 };
        typedef sai_status_t (*my_sid_entry_create_fn)(\
                _In_ const sai_my_sid_entry_t *my_sid_entry,\
                _In_ uint32_t attr_count,\
                _In_ const sai_attribute_t *attr_list);
        typedef sai_status_t (*my_sid_entry_remove_fn)(\
                _In_ const sai_my_sid_entry_t *my_sid_entry);
        typedef sai_status_t (*my_sid_entry_set_fn)(\
                _In_ const sai_my_sid_entry_t *my_sid_entry,\
                _In_ const sai_attribute_t *attr);
        typedef sai_status_t (*my_sid_entry_get_fn)(\
                _In_ const sai_my_sid_entry_t *my_sid_entry,\
                _In_ uint32_t attr_count,\
                _Inout_ sai_attribute_t *attr_list);
        my_sid_entry_create_fn create = srv6_api.create_my_sid_entry;
        my_sid_entry_remove_fn remove = srv6_api.remove_my_sid_entry;
        my_sid_entry_set_fn set = srv6_api.set_my_sid_entry_attribute;
        my_sid_entry_get_fn get = srv6_api.get_my_sid_entry_attribute;
        sai_create_my_sid_entry_fn cr = NULL;
        sai_remove_my_sid_entry_fn re = NULL;
        sai_set_my_sid_entry_attribute_fn se = NULL;
        sai_get_my_sid_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MY_SID_ENTRY] = SAI_OBJECT_TYPE_MY_SID_ENTRY;
    }
    {
        sai_my_mac_api_t my_mac_api = { 0 };
        sai_generic_create_fn create = my_mac_api.create_my_mac;
        sai_generic_remove_fn remove = my_mac_api.remove_my_mac;
        sai_generic_set_fn set = my_mac_api.set_my_mac_attribute;
        sai_generic_get_fn get = my_mac_api.get_my_mac_attribute;
        sai_create_my_mac_fn cr = NULL;
        sai_remove_my_mac_fn re = NULL;
        sai_set_my_mac_attribute_fn se = NULL;
        sai_get_my_mac_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_MY_MAC] = SAI_OBJECT_TYPE_MY_MAC;
    }
    {
        sai_next_hop_group_api_t next_hop_group_api = { 0 };
        sai_generic_create_fn create = next_hop_group_api.create_next_hop_group_map;
        sai_generic_remove_fn remove = next_hop_group_api.remove_next_hop_group_map;
        sai_generic_set_fn set = next_hop_group_api.set_next_hop_group_map_attribute;
        sai_generic_get_fn get = next_hop_group_api.get_next_hop_group_map_attribute;
        sai_create_next_hop_group_map_fn cr = NULL;
        sai_remove_next_hop_group_map_fn re = NULL;
        sai_set_next_hop_group_map_attribute_fn se = NULL;
        sai_get_next_hop_group_map_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_NEXT_HOP_GROUP_MAP] = SAI_OBJECT_TYPE_NEXT_HOP_GROUP_MAP;
    }
    {
        sai_ipsec_api_t ipsec_api = { 0 };
        sai_generic_create_fn create = ipsec_api.create_ipsec;
        sai_generic_remove_fn remove = ipsec_api.remove_ipsec;
        sai_generic_set_fn set = ipsec_api.set_ipsec_attribute;
        sai_generic_get_fn get = ipsec_api.get_ipsec_attribute;
        sai_create_ipsec_fn cr = NULL;
        sai_remove_ipsec_fn re = NULL;
        sai_set_ipsec_attribute_fn se = NULL;
        sai_get_ipsec_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_IPSEC] = SAI_OBJECT_TYPE_IPSEC;
    }
    {
        sai_ipsec_api_t ipsec_api = { 0 };
        sai_generic_create_fn create = ipsec_api.create_ipsec_port;
        sai_generic_remove_fn remove = ipsec_api.remove_ipsec_port;
        sai_generic_set_fn set = ipsec_api.set_ipsec_port_attribute;
        sai_generic_get_fn get = ipsec_api.get_ipsec_port_attribute;
        sai_create_ipsec_port_fn cr = NULL;
        sai_remove_ipsec_port_fn re = NULL;
        sai_set_ipsec_port_attribute_fn se = NULL;
        sai_get_ipsec_port_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_IPSEC_PORT] = SAI_OBJECT_TYPE_IPSEC_PORT;
    }
    {
        sai_ipsec_api_t ipsec_api = { 0 };
        sai_generic_create_fn create = ipsec_api.create_ipsec_sa;
        sai_generic_remove_fn remove = ipsec_api.remove_ipsec_sa;
        sai_generic_set_fn set = ipsec_api.set_ipsec_sa_attribute;
        sai_generic_get_fn get = ipsec_api.get_ipsec_sa_attribute;
        sai_create_ipsec_sa_fn cr = NULL;
        sai_remove_ipsec_sa_fn re = NULL;
        sai_set_ipsec_sa_attribute_fn se = NULL;
        sai_get_ipsec_sa_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_IPSEC_SA] = SAI_OBJECT_TYPE_IPSEC_SA;
    }
    {
        sai_generic_programmable_api_t generic_programmable_api = { 0 };
        sai_generic_create_fn create = generic_programmable_api.create_generic_programmable;
        sai_generic_remove_fn remove = generic_programmable_api.remove_generic_programmable;
        sai_generic_set_fn set = generic_programmable_api.set_generic_programmable_attribute;
        sai_generic_get_fn get = generic_programmable_api.get_generic_programmable_attribute;
        sai_create_generic_programmable_fn cr = NULL;
        sai_remove_generic_programmable_fn re = NULL;
        sai_set_generic_programmable_attribute_fn se = NULL;
        sai_get_generic_programmable_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_GENERIC_PROGRAMMABLE] = SAI_OBJECT_TYPE_GENERIC_PROGRAMMABLE;
    }
    {
        sai_bmtor_api_t bmtor_api = { 0 };
        sai_generic_create_fn create = bmtor_api.create_table_bitmap_classification_entry;
        sai_generic_remove_fn remove = bmtor_api.remove_table_bitmap_classification_entry;
        sai_generic_set_fn set = bmtor_api.set_table_bitmap_classification_entry_attribute;
        sai_generic_get_fn get = bmtor_api.get_table_bitmap_classification_entry_attribute;
        sai_create_table_bitmap_classification_entry_fn cr = NULL;
        sai_remove_table_bitmap_classification_entry_fn re = NULL;
        sai_set_table_bitmap_classification_entry_attribute_fn se = NULL;
        sai_get_table_bitmap_classification_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TABLE_BITMAP_CLASSIFICATION_ENTRY] = SAI_OBJECT_TYPE_TABLE_BITMAP_CLASSIFICATION_ENTRY;
    }
    {
        sai_bmtor_api_t bmtor_api = { 0 };
        sai_generic_create_fn create = bmtor_api.create_table_bitmap_router_entry;
        sai_generic_remove_fn remove = bmtor_api.remove_table_bitmap_router_entry;
        sai_generic_set_fn set = bmtor_api.set_table_bitmap_router_entry_attribute;
        sai_generic_get_fn get = bmtor_api.get_table_bitmap_router_entry_attribute;
        sai_create_table_bitmap_router_entry_fn cr = NULL;
        sai_remove_table_bitmap_router_entry_fn re = NULL;
        sai_set_table_bitmap_router_entry_attribute_fn se = NULL;
        sai_get_table_bitmap_router_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TABLE_BITMAP_ROUTER_ENTRY] = SAI_OBJECT_TYPE_TABLE_BITMAP_ROUTER_ENTRY;
    }
    {
        sai_bmtor_api_t bmtor_api = { 0 };
        sai_generic_create_fn create = bmtor_api.create_table_meta_tunnel_entry;
        sai_generic_remove_fn remove = bmtor_api.remove_table_meta_tunnel_entry;
        sai_generic_set_fn set = bmtor_api.set_table_meta_tunnel_entry_attribute;
        sai_generic_get_fn get = bmtor_api.get_table_meta_tunnel_entry_attribute;
        sai_create_table_meta_tunnel_entry_fn cr = NULL;
        sai_remove_table_meta_tunnel_entry_fn re = NULL;
        sai_set_table_meta_tunnel_entry_attribute_fn se = NULL;
        sai_get_table_meta_tunnel_entry_attribute_fn ge = NULL;
        dummy = &create;
        dummy = &remove;
        dummy = &set;
        dummy = &get;
        dummy = &cr;
        dummy = &re;
        dummy = &se;
        dummy = &ge;
        checked[(int)SAI_OBJECT_TYPE_TABLE_META_TUNNEL_ENTRY] = SAI_OBJECT_TYPE_TABLE_META_TUNNEL_ENTRY;
    }
    int index = SAI_OBJECT_TYPE_NULL;
    for (; index < SAI_OBJECT_TYPE_MAX; ++index)
    {
        printf("checking: %s checked (%d) == index (%d)\n",
             sai_metadata_enum_sai_object_type_t.valuesnames[index],
             checked[index],(sai_object_type_t)index);
        TEST_ASSERT_TRUE(checked[index] == (sai_object_type_t)index, "not all obejcts were processed");
    }
    PP(dummy);
}
void struct_list_test(void)
{
    uint32_t count;
    void *ptr;
    TEST_ASSERT_TRUE(sizeof(sai_acl_resource_list_t) == sizeof(sai_object_list_t), "struct sai_acl_resource_list_t sizeof is differenat than sai_object_list_t");
    sai_acl_resource_list_t s_sai_acl_resource_list_t;
    memset(&s_sai_acl_resource_list_t,0, sizeof(sai_acl_resource_list_t));
    count = s_sai_acl_resource_list_t.count;
    ptr   = s_sai_acl_resource_list_t.list;
    printf("sai_acl_resource_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_ip_address_list_t) == sizeof(sai_object_list_t), "struct sai_ip_address_list_t sizeof is differenat than sai_object_list_t");
    sai_ip_address_list_t s_sai_ip_address_list_t;
    memset(&s_sai_ip_address_list_t,0, sizeof(sai_ip_address_list_t));
    count = s_sai_ip_address_list_t.count;
    ptr   = s_sai_ip_address_list_t.list;
    printf("sai_ip_address_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_ip_prefix_list_t) == sizeof(sai_object_list_t), "struct sai_ip_prefix_list_t sizeof is differenat than sai_object_list_t");
    sai_ip_prefix_list_t s_sai_ip_prefix_list_t;
    memset(&s_sai_ip_prefix_list_t,0, sizeof(sai_ip_prefix_list_t));
    count = s_sai_ip_prefix_list_t.count;
    ptr   = s_sai_ip_prefix_list_t.list;
    printf("sai_ip_prefix_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_map_list_t) == sizeof(sai_object_list_t), "struct sai_map_list_t sizeof is differenat than sai_object_list_t");
    sai_map_list_t s_sai_map_list_t;
    memset(&s_sai_map_list_t,0, sizeof(sai_map_list_t));
    count = s_sai_map_list_t.count;
    ptr   = s_sai_map_list_t.list;
    printf("sai_map_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_object_list_t) == sizeof(sai_object_list_t), "struct sai_object_list_t sizeof is differenat than sai_object_list_t");
    sai_object_list_t s_sai_object_list_t;
    memset(&s_sai_object_list_t,0, sizeof(sai_object_list_t));
    count = s_sai_object_list_t.count;
    ptr   = s_sai_object_list_t.list;
    printf("sai_object_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_port_err_status_list_t) == sizeof(sai_object_list_t), "struct sai_port_err_status_list_t sizeof is differenat than sai_object_list_t");
    sai_port_err_status_list_t s_sai_port_err_status_list_t;
    memset(&s_sai_port_err_status_list_t,0, sizeof(sai_port_err_status_list_t));
    count = s_sai_port_err_status_list_t.count;
    ptr   = s_sai_port_err_status_list_t.list;
    printf("sai_port_err_status_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_port_eye_values_list_t) == sizeof(sai_object_list_t), "struct sai_port_eye_values_list_t sizeof is differenat than sai_object_list_t");
    sai_port_eye_values_list_t s_sai_port_eye_values_list_t;
    memset(&s_sai_port_eye_values_list_t,0, sizeof(sai_port_eye_values_list_t));
    count = s_sai_port_eye_values_list_t.count;
    ptr   = s_sai_port_eye_values_list_t.list;
    printf("sai_port_eye_values_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_port_lane_latch_status_list_t) == sizeof(sai_object_list_t), "struct sai_port_lane_latch_status_list_t sizeof is differenat than sai_object_list_t");
    sai_port_lane_latch_status_list_t s_sai_port_lane_latch_status_list_t;
    memset(&s_sai_port_lane_latch_status_list_t,0, sizeof(sai_port_lane_latch_status_list_t));
    count = s_sai_port_lane_latch_status_list_t.count;
    ptr   = s_sai_port_lane_latch_status_list_t.list;
    printf("sai_port_lane_latch_status_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_qos_map_list_t) == sizeof(sai_object_list_t), "struct sai_qos_map_list_t sizeof is differenat than sai_object_list_t");
    sai_qos_map_list_t s_sai_qos_map_list_t;
    memset(&s_sai_qos_map_list_t,0, sizeof(sai_qos_map_list_t));
    count = s_sai_qos_map_list_t.count;
    ptr   = s_sai_qos_map_list_t.list;
    printf("sai_qos_map_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_s16_list_t) == sizeof(sai_object_list_t), "struct sai_s16_list_t sizeof is differenat than sai_object_list_t");
    sai_s16_list_t s_sai_s16_list_t;
    memset(&s_sai_s16_list_t,0, sizeof(sai_s16_list_t));
    count = s_sai_s16_list_t.count;
    ptr   = s_sai_s16_list_t.list;
    printf("sai_s16_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_s32_list_t) == sizeof(sai_object_list_t), "struct sai_s32_list_t sizeof is differenat than sai_object_list_t");
    sai_s32_list_t s_sai_s32_list_t;
    memset(&s_sai_s32_list_t,0, sizeof(sai_s32_list_t));
    count = s_sai_s32_list_t.count;
    ptr   = s_sai_s32_list_t.list;
    printf("sai_s32_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_s8_list_t) == sizeof(sai_object_list_t), "struct sai_s8_list_t sizeof is differenat than sai_object_list_t");
    sai_s8_list_t s_sai_s8_list_t;
    memset(&s_sai_s8_list_t,0, sizeof(sai_s8_list_t));
    count = s_sai_s8_list_t.count;
    ptr   = s_sai_s8_list_t.list;
    printf("sai_s8_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_segment_list_t) == sizeof(sai_object_list_t), "struct sai_segment_list_t sizeof is differenat than sai_object_list_t");
    sai_segment_list_t s_sai_segment_list_t;
    memset(&s_sai_segment_list_t,0, sizeof(sai_segment_list_t));
    count = s_sai_segment_list_t.count;
    ptr   = s_sai_segment_list_t.list;
    printf("sai_segment_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_stat_capability_list_t) == sizeof(sai_object_list_t), "struct sai_stat_capability_list_t sizeof is differenat than sai_object_list_t");
    sai_stat_capability_list_t s_sai_stat_capability_list_t;
    memset(&s_sai_stat_capability_list_t,0, sizeof(sai_stat_capability_list_t));
    count = s_sai_stat_capability_list_t.count;
    ptr   = s_sai_stat_capability_list_t.list;
    printf("sai_stat_capability_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_system_port_config_list_t) == sizeof(sai_object_list_t), "struct sai_system_port_config_list_t sizeof is differenat than sai_object_list_t");
    sai_system_port_config_list_t s_sai_system_port_config_list_t;
    memset(&s_sai_system_port_config_list_t,0, sizeof(sai_system_port_config_list_t));
    count = s_sai_system_port_config_list_t.count;
    ptr   = s_sai_system_port_config_list_t.list;
    printf("sai_system_port_config_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_tlv_list_t) == sizeof(sai_object_list_t), "struct sai_tlv_list_t sizeof is differenat than sai_object_list_t");
    sai_tlv_list_t s_sai_tlv_list_t;
    memset(&s_sai_tlv_list_t,0, sizeof(sai_tlv_list_t));
    count = s_sai_tlv_list_t.count;
    ptr   = s_sai_tlv_list_t.list;
    printf("sai_tlv_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_u16_list_t) == sizeof(sai_object_list_t), "struct sai_u16_list_t sizeof is differenat than sai_object_list_t");
    sai_u16_list_t s_sai_u16_list_t;
    memset(&s_sai_u16_list_t,0, sizeof(sai_u16_list_t));
    count = s_sai_u16_list_t.count;
    ptr   = s_sai_u16_list_t.list;
    printf("sai_u16_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_u16_range_list_t) == sizeof(sai_object_list_t), "struct sai_u16_range_list_t sizeof is differenat than sai_object_list_t");
    sai_u16_range_list_t s_sai_u16_range_list_t;
    memset(&s_sai_u16_range_list_t,0, sizeof(sai_u16_range_list_t));
    count = s_sai_u16_range_list_t.count;
    ptr   = s_sai_u16_range_list_t.list;
    printf("sai_u16_range_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_u32_list_t) == sizeof(sai_object_list_t), "struct sai_u32_list_t sizeof is differenat than sai_object_list_t");
    sai_u32_list_t s_sai_u32_list_t;
    memset(&s_sai_u32_list_t,0, sizeof(sai_u32_list_t));
    count = s_sai_u32_list_t.count;
    ptr   = s_sai_u32_list_t.list;
    printf("sai_u32_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_u8_list_t) == sizeof(sai_object_list_t), "struct sai_u8_list_t sizeof is differenat than sai_object_list_t");
    sai_u8_list_t s_sai_u8_list_t;
    memset(&s_sai_u8_list_t,0, sizeof(sai_u8_list_t));
    count = s_sai_u8_list_t.count;
    ptr   = s_sai_u8_list_t.list;
    printf("sai_u8_list_t %p %u\n", ptr, count);
    TEST_ASSERT_TRUE(sizeof(sai_vlan_list_t) == sizeof(sai_object_list_t), "struct sai_vlan_list_t sizeof is differenat than sai_object_list_t");
    sai_vlan_list_t s_sai_vlan_list_t;
    memset(&s_sai_vlan_list_t,0, sizeof(sai_vlan_list_t));
    count = s_sai_vlan_list_t.count;
    ptr   = s_sai_vlan_list_t.list;
    printf("sai_vlan_list_t %p %u\n", ptr, count);
}
void serialize_structs(void)
{
    char buf[0x4000];
    int ret;
  {
    printf("serializing sai_acl_action_data_t ... ");
    fflush(stdout);
    sai_acl_action_data_t acl_action_data;
    memset(&acl_action_data, 0, sizeof(sai_acl_action_data_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_ACL_ENTRY, SAI_ACL_ENTRY_ATTR_ACTION_COUNTER);
    ret = sai_serialize_acl_action_data(buf, meta, &acl_action_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_action_data_t");
    printf("serialized sai_acl_action_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_acl_capability_t ... ");
    fflush(stdout);
    sai_acl_capability_t acl_capability;
    memset(&acl_capability, 0, sizeof(sai_acl_capability_t));
    ret = sai_serialize_acl_capability(buf, &acl_capability);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_capability_t");
    printf("serialized sai_acl_capability_t: %s\n", buf);
  }
  {
    printf("serializing sai_acl_field_data_t ... ");
    fflush(stdout);
    sai_acl_field_data_t acl_field_data;
    memset(&acl_field_data, 0, sizeof(sai_acl_field_data_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_ACL_ENTRY, SAI_ACL_ENTRY_ATTR_FIELD_SRC_IP);
    ret = sai_serialize_acl_field_data(buf, meta, &acl_field_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_field_data_t");
    printf("serialized sai_acl_field_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_acl_resource_list_t ... ");
    fflush(stdout);
    sai_acl_resource_list_t acl_resource_list;
    memset(&acl_resource_list, 0, sizeof(sai_acl_resource_list_t));
    ret = sai_serialize_acl_resource_list(buf, &acl_resource_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_resource_list_t");
    printf("serialized sai_acl_resource_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_acl_resource_t ... ");
    fflush(stdout);
    sai_acl_resource_t acl_resource;
    memset(&acl_resource, 0, sizeof(sai_acl_resource_t));
    ret = sai_serialize_acl_resource(buf, &acl_resource);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_resource_t");
    printf("serialized sai_acl_resource_t: %s\n", buf);
  }
  {
    printf("serializing sai_attr_capability_t ... ");
    fflush(stdout);
    sai_attr_capability_t attr_capability;
    memset(&attr_capability, 0, sizeof(sai_attr_capability_t));
    ret = sai_serialize_attr_capability(buf, &attr_capability);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_attr_capability_t");
    printf("serialized sai_attr_capability_t: %s\n", buf);
  }
  {
    printf("serializing sai_attribute_t ... ");
    fflush(stdout);
    sai_attribute_t attribute;
    memset(&attribute, 0, sizeof(sai_attribute_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_SWITCH, SAI_SWITCH_ATTR_PORT_NUMBER);
    ret = sai_serialize_attribute(buf, meta, &attribute);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_attribute_t");
    printf("serialized sai_attribute_t: %s\n", buf);
  }
  {
    printf("serializing sai_bfd_session_state_notification_t ... ");
    fflush(stdout);
    sai_bfd_session_state_notification_t bfd_session_state_notification;
    memset(&bfd_session_state_notification, 0, sizeof(sai_bfd_session_state_notification_t));
    ret = sai_serialize_bfd_session_state_notification(buf, &bfd_session_state_notification);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_bfd_session_state_notification_t");
    printf("serialized sai_bfd_session_state_notification_t: %s\n", buf);
  }
  {
    printf("serializing sai_fabric_port_reachability_t ... ");
    fflush(stdout);
    sai_fabric_port_reachability_t fabric_port_reachability;
    memset(&fabric_port_reachability, 0, sizeof(sai_fabric_port_reachability_t));
    ret = sai_serialize_fabric_port_reachability(buf, &fabric_port_reachability);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_fabric_port_reachability_t");
    printf("serialized sai_fabric_port_reachability_t: %s\n", buf);
  }
  {
    printf("serializing sai_fdb_entry_t ... ");
    fflush(stdout);
    sai_fdb_entry_t fdb_entry;
    memset(&fdb_entry, 0, sizeof(sai_fdb_entry_t));
    ret = sai_serialize_fdb_entry(buf, &fdb_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_fdb_entry_t");
    printf("serialized sai_fdb_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_fdb_event_notification_data_t ... ");
    fflush(stdout);
    sai_fdb_event_notification_data_t fdb_event_notification_data;
    memset(&fdb_event_notification_data, 0, sizeof(sai_fdb_event_notification_data_t));
    ret = sai_serialize_fdb_event_notification_data(buf, &fdb_event_notification_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_fdb_event_notification_data_t");
    printf("serialized sai_fdb_event_notification_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_hmac_t ... ");
    fflush(stdout);
    sai_hmac_t hmac;
    memset(&hmac, 0, sizeof(sai_hmac_t));
    ret = sai_serialize_hmac(buf, &hmac);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_hmac_t");
    printf("serialized sai_hmac_t: %s\n", buf);
  }
  {
    printf("serializing sai_inseg_entry_t ... ");
    fflush(stdout);
    sai_inseg_entry_t inseg_entry;
    memset(&inseg_entry, 0, sizeof(sai_inseg_entry_t));
    ret = sai_serialize_inseg_entry(buf, &inseg_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_inseg_entry_t");
    printf("serialized sai_inseg_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_ip_address_list_t ... ");
    fflush(stdout);
    sai_ip_address_list_t ip_address_list;
    memset(&ip_address_list, 0, sizeof(sai_ip_address_list_t));
    ret = sai_serialize_ip_address_list(buf, &ip_address_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ip_address_list_t");
    printf("serialized sai_ip_address_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_ip_address_t ... ");
    fflush(stdout);
    sai_ip_address_t ip_address;
    memset(&ip_address, 0, sizeof(sai_ip_address_t));
    ret = sai_serialize_ip_address(buf, &ip_address);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ip_address_t");
    printf("serialized sai_ip_address_t: %s\n", buf);
  }
  {
    printf("serializing sai_ip_prefix_list_t ... ");
    fflush(stdout);
    sai_ip_prefix_list_t ip_prefix_list;
    memset(&ip_prefix_list, 0, sizeof(sai_ip_prefix_list_t));
    ret = sai_serialize_ip_prefix_list(buf, &ip_prefix_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ip_prefix_list_t");
    printf("serialized sai_ip_prefix_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_ip_prefix_t ... ");
    fflush(stdout);
    sai_ip_prefix_t ip_prefix;
    memset(&ip_prefix, 0, sizeof(sai_ip_prefix_t));
    ret = sai_serialize_ip_prefix(buf, &ip_prefix);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ip_prefix_t");
    printf("serialized sai_ip_prefix_t: %s\n", buf);
  }
  {
    printf("serializing sai_ipmc_entry_t ... ");
    fflush(stdout);
    sai_ipmc_entry_t ipmc_entry;
    memset(&ipmc_entry, 0, sizeof(sai_ipmc_entry_t));
    ret = sai_serialize_ipmc_entry(buf, &ipmc_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ipmc_entry_t");
    printf("serialized sai_ipmc_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_ipsec_sa_status_notification_t ... ");
    fflush(stdout);
    sai_ipsec_sa_status_notification_t ipsec_sa_status_notification;
    memset(&ipsec_sa_status_notification, 0, sizeof(sai_ipsec_sa_status_notification_t));
    ret = sai_serialize_ipsec_sa_status_notification(buf, &ipsec_sa_status_notification);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ipsec_sa_status_notification_t");
    printf("serialized sai_ipsec_sa_status_notification_t: %s\n", buf);
  }
  {
    printf("serializing sai_json_t ... ");
    fflush(stdout);
    sai_json_t json;
    memset(&json, 0, sizeof(sai_json_t));
    ret = sai_serialize_json(buf, &json);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_json_t");
    printf("serialized sai_json_t: %s\n", buf);
  }
  {
    printf("serializing sai_l2mc_entry_t ... ");
    fflush(stdout);
    sai_l2mc_entry_t l2mc_entry;
    memset(&l2mc_entry, 0, sizeof(sai_l2mc_entry_t));
    ret = sai_serialize_l2mc_entry(buf, &l2mc_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_l2mc_entry_t");
    printf("serialized sai_l2mc_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_latch_status_t ... ");
    fflush(stdout);
    sai_latch_status_t latch_status;
    memset(&latch_status, 0, sizeof(sai_latch_status_t));
    ret = sai_serialize_latch_status(buf, &latch_status);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_latch_status_t");
    printf("serialized sai_latch_status_t: %s\n", buf);
  }
  {
    printf("serializing sai_map_list_t ... ");
    fflush(stdout);
    sai_map_list_t map_list;
    memset(&map_list, 0, sizeof(sai_map_list_t));
    ret = sai_serialize_map_list(buf, &map_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_map_list_t");
    printf("serialized sai_map_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_map_t ... ");
    fflush(stdout);
    sai_map_t map;
    memset(&map, 0, sizeof(sai_map_t));
    ret = sai_serialize_map(buf, &map);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_map_t");
    printf("serialized sai_map_t: %s\n", buf);
  }
  {
    printf("serializing sai_mcast_fdb_entry_t ... ");
    fflush(stdout);
    sai_mcast_fdb_entry_t mcast_fdb_entry;
    memset(&mcast_fdb_entry, 0, sizeof(sai_mcast_fdb_entry_t));
    ret = sai_serialize_mcast_fdb_entry(buf, &mcast_fdb_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_mcast_fdb_entry_t");
    printf("serialized sai_mcast_fdb_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_my_sid_entry_t ... ");
    fflush(stdout);
    sai_my_sid_entry_t my_sid_entry;
    memset(&my_sid_entry, 0, sizeof(sai_my_sid_entry_t));
    ret = sai_serialize_my_sid_entry(buf, &my_sid_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_my_sid_entry_t");
    printf("serialized sai_my_sid_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_nat_entry_data_t ... ");
    fflush(stdout);
    sai_nat_entry_data_t nat_entry_data;
    memset(&nat_entry_data, 0, sizeof(sai_nat_entry_data_t));
    ret = sai_serialize_nat_entry_data(buf, &nat_entry_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_nat_entry_data_t");
    printf("serialized sai_nat_entry_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_nat_entry_key_t ... ");
    fflush(stdout);
    sai_nat_entry_key_t nat_entry_key;
    memset(&nat_entry_key, 0, sizeof(sai_nat_entry_key_t));
    ret = sai_serialize_nat_entry_key(buf, &nat_entry_key);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_nat_entry_key_t");
    printf("serialized sai_nat_entry_key_t: %s\n", buf);
  }
  {
    printf("serializing sai_nat_entry_mask_t ... ");
    fflush(stdout);
    sai_nat_entry_mask_t nat_entry_mask;
    memset(&nat_entry_mask, 0, sizeof(sai_nat_entry_mask_t));
    ret = sai_serialize_nat_entry_mask(buf, &nat_entry_mask);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_nat_entry_mask_t");
    printf("serialized sai_nat_entry_mask_t: %s\n", buf);
  }
  {
    printf("serializing sai_nat_entry_t ... ");
    fflush(stdout);
    sai_nat_entry_t nat_entry;
    memset(&nat_entry, 0, sizeof(sai_nat_entry_t));
    ret = sai_serialize_nat_entry(buf, &nat_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_nat_entry_t");
    printf("serialized sai_nat_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_nat_event_notification_data_t ... ");
    fflush(stdout);
    sai_nat_event_notification_data_t nat_event_notification_data;
    memset(&nat_event_notification_data, 0, sizeof(sai_nat_event_notification_data_t));
    ret = sai_serialize_nat_event_notification_data(buf, &nat_event_notification_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_nat_event_notification_data_t");
    printf("serialized sai_nat_event_notification_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_neighbor_entry_t ... ");
    fflush(stdout);
    sai_neighbor_entry_t neighbor_entry;
    memset(&neighbor_entry, 0, sizeof(sai_neighbor_entry_t));
    ret = sai_serialize_neighbor_entry(buf, &neighbor_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_neighbor_entry_t");
    printf("serialized sai_neighbor_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_object_key_t ... ");
    fflush(stdout);
    sai_object_key_t object_key;
    memset(&object_key, 0, sizeof(sai_object_key_t));
    sai_object_type_t object_type;
    memset(&object_type, 0, sizeof(sai_object_type_t));
    object_type = SAI_OBJECT_TYPE_PORT;
    ret = sai_serialize_object_key(buf, object_type, &object_key);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_object_key_t");
    printf("serialized sai_object_key_t: %s\n", buf);
  }
  {
    printf("serializing sai_object_list_t ... ");
    fflush(stdout);
    sai_object_list_t object_list;
    memset(&object_list, 0, sizeof(sai_object_list_t));
    ret = sai_serialize_object_list(buf, &object_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_object_list_t");
    printf("serialized sai_object_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_object_meta_key_t ... ");
    fflush(stdout);
    sai_object_meta_key_t object_meta_key;
    memset(&object_meta_key, 0, sizeof(sai_object_meta_key_t));
    object_meta_key.objecttype = SAI_OBJECT_TYPE_PORT;
    ret = sai_serialize_object_meta_key(buf, &object_meta_key);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_object_meta_key_t");
    printf("serialized sai_object_meta_key_t: %s\n", buf);
  }
  {
    printf("serializing sai_port_err_status_list_t ... ");
    fflush(stdout);
    sai_port_err_status_list_t port_err_status_list;
    memset(&port_err_status_list, 0, sizeof(sai_port_err_status_list_t));
    ret = sai_serialize_port_err_status_list(buf, &port_err_status_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_port_err_status_list_t");
    printf("serialized sai_port_err_status_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_port_eye_values_list_t ... ");
    fflush(stdout);
    sai_port_eye_values_list_t port_eye_values_list;
    memset(&port_eye_values_list, 0, sizeof(sai_port_eye_values_list_t));
    ret = sai_serialize_port_eye_values_list(buf, &port_eye_values_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_port_eye_values_list_t");
    printf("serialized sai_port_eye_values_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_port_lane_eye_values_t ... ");
    fflush(stdout);
    sai_port_lane_eye_values_t port_lane_eye_values;
    memset(&port_lane_eye_values, 0, sizeof(sai_port_lane_eye_values_t));
    ret = sai_serialize_port_lane_eye_values(buf, &port_lane_eye_values);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_port_lane_eye_values_t");
    printf("serialized sai_port_lane_eye_values_t: %s\n", buf);
  }
  {
    printf("serializing sai_port_lane_latch_status_list_t ... ");
    fflush(stdout);
    sai_port_lane_latch_status_list_t port_lane_latch_status_list;
    memset(&port_lane_latch_status_list, 0, sizeof(sai_port_lane_latch_status_list_t));
    ret = sai_serialize_port_lane_latch_status_list(buf, &port_lane_latch_status_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_port_lane_latch_status_list_t");
    printf("serialized sai_port_lane_latch_status_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_port_lane_latch_status_t ... ");
    fflush(stdout);
    sai_port_lane_latch_status_t port_lane_latch_status;
    memset(&port_lane_latch_status, 0, sizeof(sai_port_lane_latch_status_t));
    ret = sai_serialize_port_lane_latch_status(buf, &port_lane_latch_status);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_port_lane_latch_status_t");
    printf("serialized sai_port_lane_latch_status_t: %s\n", buf);
  }
  {
    printf("serializing sai_port_oper_status_notification_t ... ");
    fflush(stdout);
    sai_port_oper_status_notification_t port_oper_status_notification;
    memset(&port_oper_status_notification, 0, sizeof(sai_port_oper_status_notification_t));
    ret = sai_serialize_port_oper_status_notification(buf, &port_oper_status_notification);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_port_oper_status_notification_t");
    printf("serialized sai_port_oper_status_notification_t: %s\n", buf);
  }
  {
    printf("serializing sai_prbs_rx_state_t ... ");
    fflush(stdout);
    sai_prbs_rx_state_t prbs_rx_state;
    memset(&prbs_rx_state, 0, sizeof(sai_prbs_rx_state_t));
    ret = sai_serialize_prbs_rx_state(buf, &prbs_rx_state);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_prbs_rx_state_t");
    printf("serialized sai_prbs_rx_state_t: %s\n", buf);
  }
  {
    printf("serializing sai_qos_map_list_t ... ");
    fflush(stdout);
    sai_qos_map_list_t qos_map_list;
    memset(&qos_map_list, 0, sizeof(sai_qos_map_list_t));
    ret = sai_serialize_qos_map_list(buf, &qos_map_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_qos_map_list_t");
    printf("serialized sai_qos_map_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_qos_map_params_t ... ");
    fflush(stdout);
    sai_qos_map_params_t qos_map_params;
    memset(&qos_map_params, 0, sizeof(sai_qos_map_params_t));
    ret = sai_serialize_qos_map_params(buf, &qos_map_params);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_qos_map_params_t");
    printf("serialized sai_qos_map_params_t: %s\n", buf);
  }
  {
    printf("serializing sai_qos_map_t ... ");
    fflush(stdout);
    sai_qos_map_t qos_map;
    memset(&qos_map, 0, sizeof(sai_qos_map_t));
    ret = sai_serialize_qos_map(buf, &qos_map);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_qos_map_t");
    printf("serialized sai_qos_map_t: %s\n", buf);
  }
  {
    printf("serializing sai_queue_deadlock_notification_data_t ... ");
    fflush(stdout);
    sai_queue_deadlock_notification_data_t queue_deadlock_notification_data;
    memset(&queue_deadlock_notification_data, 0, sizeof(sai_queue_deadlock_notification_data_t));
    ret = sai_serialize_queue_deadlock_notification_data(buf, &queue_deadlock_notification_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_queue_deadlock_notification_data_t");
    printf("serialized sai_queue_deadlock_notification_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_route_entry_t ... ");
    fflush(stdout);
    sai_route_entry_t route_entry;
    memset(&route_entry, 0, sizeof(sai_route_entry_t));
    ret = sai_serialize_route_entry(buf, &route_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_route_entry_t");
    printf("serialized sai_route_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_s16_list_t ... ");
    fflush(stdout);
    sai_s16_list_t s16_list;
    memset(&s16_list, 0, sizeof(sai_s16_list_t));
    ret = sai_serialize_s16_list(buf, &s16_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_s16_list_t");
    printf("serialized sai_s16_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_s32_list_t ... ");
    fflush(stdout);
    sai_s32_list_t s32_list;
    memset(&s32_list, 0, sizeof(sai_s32_list_t));
    ret = sai_serialize_s32_list(buf, &s32_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_s32_list_t");
    printf("serialized sai_s32_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_s32_range_t ... ");
    fflush(stdout);
    sai_s32_range_t s32_range;
    memset(&s32_range, 0, sizeof(sai_s32_range_t));
    ret = sai_serialize_s32_range(buf, &s32_range);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_s32_range_t");
    printf("serialized sai_s32_range_t: %s\n", buf);
  }
  {
    printf("serializing sai_s8_list_t ... ");
    fflush(stdout);
    sai_s8_list_t s8_list;
    memset(&s8_list, 0, sizeof(sai_s8_list_t));
    ret = sai_serialize_s8_list(buf, &s8_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_s8_list_t");
    printf("serialized sai_s8_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_segment_list_t ... ");
    fflush(stdout);
    sai_segment_list_t segment_list;
    memset(&segment_list, 0, sizeof(sai_segment_list_t));
    ret = sai_serialize_segment_list(buf, &segment_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_segment_list_t");
    printf("serialized sai_segment_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_stat_capability_list_t ... ");
    fflush(stdout);
    sai_stat_capability_list_t stat_capability_list;
    memset(&stat_capability_list, 0, sizeof(sai_stat_capability_list_t));
    ret = sai_serialize_stat_capability_list(buf, &stat_capability_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_stat_capability_list_t");
    printf("serialized sai_stat_capability_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_stat_capability_t ... ");
    fflush(stdout);
    sai_stat_capability_t stat_capability;
    memset(&stat_capability, 0, sizeof(sai_stat_capability_t));
    ret = sai_serialize_stat_capability(buf, &stat_capability);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_stat_capability_t");
    printf("serialized sai_stat_capability_t: %s\n", buf);
  }
  {
    printf("serializing sai_system_port_config_list_t ... ");
    fflush(stdout);
    sai_system_port_config_list_t system_port_config_list;
    memset(&system_port_config_list, 0, sizeof(sai_system_port_config_list_t));
    ret = sai_serialize_system_port_config_list(buf, &system_port_config_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_system_port_config_list_t");
    printf("serialized sai_system_port_config_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_system_port_config_t ... ");
    fflush(stdout);
    sai_system_port_config_t system_port_config;
    memset(&system_port_config, 0, sizeof(sai_system_port_config_t));
    ret = sai_serialize_system_port_config(buf, &system_port_config);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_system_port_config_t");
    printf("serialized sai_system_port_config_t: %s\n", buf);
  }
  {
    printf("serializing sai_timespec_t ... ");
    fflush(stdout);
    sai_timespec_t timespec;
    memset(&timespec, 0, sizeof(sai_timespec_t));
    ret = sai_serialize_timespec(buf, &timespec);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_timespec_t");
    printf("serialized sai_timespec_t: %s\n", buf);
  }
  {
    printf("serializing sai_tlv_list_t ... ");
    fflush(stdout);
    sai_tlv_list_t tlv_list;
    memset(&tlv_list, 0, sizeof(sai_tlv_list_t));
    ret = sai_serialize_tlv_list(buf, &tlv_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_tlv_list_t");
    printf("serialized sai_tlv_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_tlv_t ... ");
    fflush(stdout);
    sai_tlv_t tlv;
    memset(&tlv, 0, sizeof(sai_tlv_t));
    ret = sai_serialize_tlv(buf, &tlv);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_tlv_t");
    printf("serialized sai_tlv_t: %s\n", buf);
  }
  {
    printf("serializing sai_u16_list_t ... ");
    fflush(stdout);
    sai_u16_list_t u16_list;
    memset(&u16_list, 0, sizeof(sai_u16_list_t));
    ret = sai_serialize_u16_list(buf, &u16_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_u16_list_t");
    printf("serialized sai_u16_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_u16_range_list_t ... ");
    fflush(stdout);
    sai_u16_range_list_t u16_range_list;
    memset(&u16_range_list, 0, sizeof(sai_u16_range_list_t));
    ret = sai_serialize_u16_range_list(buf, &u16_range_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_u16_range_list_t");
    printf("serialized sai_u16_range_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_u16_range_t ... ");
    fflush(stdout);
    sai_u16_range_t u16_range;
    memset(&u16_range, 0, sizeof(sai_u16_range_t));
    ret = sai_serialize_u16_range(buf, &u16_range);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_u16_range_t");
    printf("serialized sai_u16_range_t: %s\n", buf);
  }
  {
    printf("serializing sai_u32_list_t ... ");
    fflush(stdout);
    sai_u32_list_t u32_list;
    memset(&u32_list, 0, sizeof(sai_u32_list_t));
    ret = sai_serialize_u32_list(buf, &u32_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_u32_list_t");
    printf("serialized sai_u32_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_u32_range_t ... ");
    fflush(stdout);
    sai_u32_range_t u32_range;
    memset(&u32_range, 0, sizeof(sai_u32_range_t));
    ret = sai_serialize_u32_range(buf, &u32_range);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_u32_range_t");
    printf("serialized sai_u32_range_t: %s\n", buf);
  }
  {
    printf("serializing sai_u8_list_t ... ");
    fflush(stdout);
    sai_u8_list_t u8_list;
    memset(&u8_list, 0, sizeof(sai_u8_list_t));
    ret = sai_serialize_u8_list(buf, &u8_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_u8_list_t");
    printf("serialized sai_u8_list_t: %s\n", buf);
  }
  {
    printf("serializing sai_vlan_list_t ... ");
    fflush(stdout);
    sai_vlan_list_t vlan_list;
    memset(&vlan_list, 0, sizeof(sai_vlan_list_t));
    ret = sai_serialize_vlan_list(buf, &vlan_list);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_vlan_list_t");
    printf("serialized sai_vlan_list_t: %s\n", buf);
  }
}
void serialize_unions(void)
{
    char buf[0x4000];
    int ret;
  {
    printf("serializing sai_acl_action_parameter_t ... ");
    fflush(stdout);
    sai_acl_action_parameter_t acl_action_parameter;
    memset(&acl_action_parameter, 0, sizeof(sai_acl_action_parameter_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_ACL_ENTRY, SAI_ACL_ENTRY_ATTR_ACTION_COUNTER);
    ret = sai_serialize_acl_action_parameter(buf, meta, &acl_action_parameter);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_action_parameter_t");
    printf("serialized sai_acl_action_parameter_t: %s\n", buf);
  }
  {
    printf("serializing sai_acl_field_data_data_t ... ");
    fflush(stdout);
    sai_acl_field_data_data_t acl_field_data_data;
    memset(&acl_field_data_data, 0, sizeof(sai_acl_field_data_data_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_ACL_ENTRY, SAI_ACL_ENTRY_ATTR_FIELD_SRC_IP);
    ret = sai_serialize_acl_field_data_data(buf, meta, &acl_field_data_data);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_field_data_data_t");
    printf("serialized sai_acl_field_data_data_t: %s\n", buf);
  }
  {
    printf("serializing sai_acl_field_data_mask_t ... ");
    fflush(stdout);
    sai_acl_field_data_mask_t acl_field_data_mask;
    memset(&acl_field_data_mask, 0, sizeof(sai_acl_field_data_mask_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_ACL_ENTRY, SAI_ACL_ENTRY_ATTR_FIELD_SRC_IP);
    ret = sai_serialize_acl_field_data_mask(buf, meta, &acl_field_data_mask);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_acl_field_data_mask_t");
    printf("serialized sai_acl_field_data_mask_t: %s\n", buf);
  }
  {
    printf("serializing sai_attribute_value_t ... ");
    fflush(stdout);
    sai_attribute_value_t attribute_value;
    memset(&attribute_value, 0, sizeof(sai_attribute_value_t));
    const sai_attr_metadata_t *meta;
    meta = sai_metadata_get_attr_metadata(SAI_OBJECT_TYPE_SWITCH, SAI_SWITCH_ATTR_PORT_NUMBER);
    ret = sai_serialize_attribute_value(buf, meta, &attribute_value);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_attribute_value_t");
    printf("serialized sai_attribute_value_t: %s\n", buf);
  }
  {
    printf("serializing sai_ip_addr_t ... ");
    fflush(stdout);
    sai_ip_addr_t ip_addr;
    memset(&ip_addr, 0, sizeof(sai_ip_addr_t));
    sai_ip_addr_family_t addr_family;
    memset(&addr_family, 0, sizeof(sai_ip_addr_family_t));
    ret = sai_serialize_ip_addr(buf, addr_family, &ip_addr);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_ip_addr_t");
    printf("serialized sai_ip_addr_t: %s\n", buf);
  }
  {
    printf("serializing sai_object_key_entry_t ... ");
    fflush(stdout);
    sai_object_key_entry_t object_key_entry;
    memset(&object_key_entry, 0, sizeof(sai_object_key_entry_t));
    sai_object_type_t object_type;
    memset(&object_type, 0, sizeof(sai_object_type_t));
    object_type = SAI_OBJECT_TYPE_PORT;
    ret = sai_serialize_object_key_entry(buf, object_type, &object_key_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_object_key_entry_t");
    printf("serialized sai_object_key_entry_t: %s\n", buf);
  }
  {
    printf("serializing sai_tlv_entry_t ... ");
    fflush(stdout);
    sai_tlv_entry_t tlv_entry;
    memset(&tlv_entry, 0, sizeof(sai_tlv_entry_t));
    sai_tlv_type_t tlv_type;
    memset(&tlv_type, 0, sizeof(sai_tlv_type_t));
    ret = sai_serialize_tlv_entry(buf, tlv_type, &tlv_entry);
    TEST_ASSERT_TRUE(ret > 0, "failed to serialize sai_tlv_entry_t");
    printf("serialized sai_tlv_entry_t: %s\n", buf);
  }
}
void statenum_defined(void)
{
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_BFD_SESSION.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_BFD_SESSION must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_BRIDGE_PORT.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_BRIDGE_PORT must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_BRIDGE.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_BRIDGE must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_BUFFER_POOL.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_BUFFER_POOL must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_COUNTER.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_COUNTER must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_IPSEC_PORT.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_IPSEC_PORT must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_IPSEC_SA.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_IPSEC_SA must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_MACSEC_FLOW.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_MACSEC_FLOW must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_MACSEC_PORT.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_MACSEC_PORT must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_MACSEC_SA.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_MACSEC_SA must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_MACSEC_SC.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_MACSEC_SC must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_POLICER.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_POLICER must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_PORT_POOL.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_PORT_POOL must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_PORT.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_PORT must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_QUEUE.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_QUEUE must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_ROUTER_INTERFACE.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_ROUTER_INTERFACE must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_SWITCH.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_SWITCH must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_TABLE_BITMAP_CLASSIFICATION_ENTRY.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_TABLE_BITMAP_CLASSIFICATION_ENTRY must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_TABLE_BITMAP_ROUTER_ENTRY.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_TABLE_BITMAP_ROUTER_ENTRY must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_TABLE_META_TUNNEL_ENTRY.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_TABLE_META_TUNNEL_ENTRY must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_TUNNEL.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_TUNNEL must be populated");
    TEST_ASSERT_TRUE(sai_metadata_object_type_info_SAI_OBJECT_TYPE_VLAN.statenum != NULL, "statenum field for object SAI_OBJECT_TYPE_VLAN must be populated");
}
void api_implemented(void)
{
#ifdef API_IMPLEMENTED_TEST
    sai_api_initialize_fn var_sai_api_initialize = &sai_api_initialize;
    PP(var_sai_api_initialize);
    sai_api_query_fn var_sai_api_query = &sai_api_query;
    PP(var_sai_api_query);
    sai_api_uninitialize_fn var_sai_api_uninitialize = &sai_api_uninitialize;
    PP(var_sai_api_uninitialize);
    sai_bulk_get_attribute_fn var_sai_bulk_get_attribute = &sai_bulk_get_attribute;
    PP(var_sai_bulk_get_attribute);
    sai_bulk_object_clear_stats_fn var_sai_bulk_object_clear_stats = &sai_bulk_object_clear_stats;
    PP(var_sai_bulk_object_clear_stats);
    sai_bulk_object_get_stats_fn var_sai_bulk_object_get_stats = &sai_bulk_object_get_stats;
    PP(var_sai_bulk_object_get_stats);
    sai_dbg_generate_dump_fn var_sai_dbg_generate_dump = &sai_dbg_generate_dump;
    PP(var_sai_dbg_generate_dump);
    sai_get_maximum_attribute_count_fn var_sai_get_maximum_attribute_count = &sai_get_maximum_attribute_count;
    PP(var_sai_get_maximum_attribute_count);
    sai_get_object_count_fn var_sai_get_object_count = &sai_get_object_count;
    PP(var_sai_get_object_count);
    sai_get_object_key_fn var_sai_get_object_key = &sai_get_object_key;
    PP(var_sai_get_object_key);
    sai_log_set_fn var_sai_log_set = &sai_log_set;
    PP(var_sai_log_set);
    sai_object_type_get_availability_fn var_sai_object_type_get_availability = &sai_object_type_get_availability;
    PP(var_sai_object_type_get_availability);
    sai_object_type_query_fn var_sai_object_type_query = &sai_object_type_query;
    PP(var_sai_object_type_query);
    sai_query_api_version_fn var_sai_query_api_version = &sai_query_api_version;
    PP(var_sai_query_api_version);
    sai_query_attribute_capability_fn var_sai_query_attribute_capability = &sai_query_attribute_capability;
    PP(var_sai_query_attribute_capability);
    sai_query_attribute_enum_values_capability_fn var_sai_query_attribute_enum_values_capability = &sai_query_attribute_enum_values_capability;
    PP(var_sai_query_attribute_enum_values_capability);
    sai_query_object_stage_fn var_sai_query_object_stage = &sai_query_object_stage;
    PP(var_sai_query_object_stage);
    sai_query_stats_capability_fn var_sai_query_stats_capability = &sai_query_stats_capability;
    PP(var_sai_query_stats_capability);
    sai_switch_id_query_fn var_sai_switch_id_query = &sai_switch_id_query;
    PP(var_sai_switch_id_query);
    sai_tam_telemetry_get_data_fn var_sai_tam_telemetry_get_data = &sai_tam_telemetry_get_data;
    PP(var_sai_tam_telemetry_get_data);
#endif
}
#pragma GCC diagnostic pop
int main()
{
    printf("Executing Test [1/12]: non_object_id_test\n");
    non_object_id_test();
    printf("Executing Test [2/12]: switch_id_position_test\n");
    switch_id_position_test();
    printf("Executing Test [3/12]: custom_range_test\n");
    custom_range_test();
    printf("Executing Test [4/12]: check_pointer_names_test\n");
    check_pointer_names_test();
    printf("Executing Test [5/12]: enum_size_check_test\n");
    enum_size_check_test();
    printf("Executing Test [6/12]: list_count_test\n");
    list_count_test();
    printf("Executing Test [7/12]: api_name_test\n");
    api_name_test();
    printf("Executing Test [8/12]: struct_list_test\n");
    struct_list_test();
    printf("Executing Test [9/12]: serialize_structs\n");
    serialize_structs();
    printf("Executing Test [10/12]: serialize_unions\n");
    serialize_unions();
    printf("Executing Test [11/12]: statenum_defined\n");
    statenum_defined();
    printf("Executing Test [12/12]: api_implemented\n");
    api_implemented();
    return 0;
}
