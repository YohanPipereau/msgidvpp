#include <stdio.h>

#include <vlibapi/api.h>
#include <vlibmemory/api.h>


int main()
{
    api_main_t *am = &api_main;
    hash_pair_t *hp;

    clib_mem_init_thread_safe(0, 128 << 20);
    // Open VPP management session under name vpp-manager
    if (vl_client_connect_to_vlib("/vpe-api", "vpp-manager", 32) < 0)
        return -1;

    printf("Connected to VPP! as client: \n");

    hash_foreach_pair (hp, am->msg_index_by_name_and_crc,
    ({
        char *key = (char *)hp->key; // key format: name_crc
        printf("index: %u \t name: %s \t handler: %p\n", (u32) hp->value[0], (char *)hp->key, am->msg_handlers[hp->value[0]]);
    }));

    vl_client_disconnect_from_vlib();
}
