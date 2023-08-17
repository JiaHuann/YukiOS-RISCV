#include "kernel/os.h"
#include "vdisk.h"
#include "mem_config.h"
#include "kernel/string.h"
// #include "mm.h"
// #include "spinlock.h"
// #include "panic.h"
// #include "string.h"
// #include "plic.h"
#define R(r) (volatile uint32_t *)(VIRTIO0_V + (r))

#define PGSIZE  4096
#define PGSHIFT 12
#define BSIZE   512

static struct disk {
    // memory for virtio descriptors &c for queue 0.
    // this is a global instead of allocated because it must
    // be multiple contiguous pages, which kalloc()
    // doesn't support, and page aligned.
    char pages[2*PGSIZE];
    // the following three pointers will point to pages[]
    vring_desc_t *desc;
    vring_avail_t *avail;
    vring_used_t *used;
    // our own book-keeping.
    char free[NUM];  // is a descriptor free?
    char status[NUM];
    int idx[NUM];
    //spinlock vdisk_lock;
} disk;

int vdisk_init(void)
{
    uart_puts("in vdisk_init now \n");
    uint32_t status = 0;

    //init_spinlock(&disk.vdisk_lock, "virtio_disk");
    *(volatile uint32_t *)(VIRTIO0_V + (VIRTIO_MMIO_MAGIC_VALUE_OFFSET));
    
    uart_puts("[r]VIRTIO_MMIO_MAGIC_VALUE_OFFSET \n");
    // if (*R(VIRTIO_MMIO_MAGIC_VALUE_OFFSET) != 0x74726976 ||
    //     *R(VIRTIO_MMIO_VERSION_OFFSET) != 1 ||
    //     *R(VIRTIO_MMIO_DEVICE_ID_OFFSET) != 2 ||
    //     *R(VIRTIO_MMIO_VENDOR_ID_OFFSET) != 0x554d4551)
    // {

    //     uart_puts("virtio blk info wrong!\n");

    //     return 1;
    // }
    uart_puts("hi!\n");
    status |= VIRTIO_CONFIG_S_ACKNOWLEDGE;
    *R(VIRTIO_MMIO_STATUS_OFFSET) = status;

    status |= VIRTIO_CONFIG_S_DRIVER;
    *R(VIRTIO_MMIO_STATUS_OFFSET) = status;

    // negotiate features
    uint64_t features = *R(VIRTIO_MMIO_DEVICE_FEATURES_OFFSET);
    features &= ~(1 << VIRTIO_BLK_F_RO);
    features &= ~(1 << VIRTIO_BLK_F_SCSI);
    features &= ~(1 << VIRTIO_BLK_F_CONFIG_WCE);
    features &= ~(1 << VIRTIO_BLK_F_MQ);
    features &= ~(1 << VIRTIO_F_ANY_LAYOUT);
    features &= ~(1 << VIRTIO_RING_F_EVENT_IDX);
    features &= ~(1 << VIRTIO_RING_F_INDIRECT_DESC);
    *R(VIRTIO_MMIO_DRIVER_FEATURES_OFFSET) = features;

    // tell device that feature negotiation is complete.
    status |= VIRTIO_CONFIG_S_FEATURES_OK;
    *R(VIRTIO_MMIO_STATUS_OFFSET) = status;

    // tell device we're completely ready.
    status |= VIRTIO_CONFIG_S_DRIVER_OK;
    *R(VIRTIO_MMIO_STATUS_OFFSET) = status;

    *R(VIRTIO_MMIO_GUEST_PAGE_SIZE_OFFSET) = PGSIZE;

    // initialize queue 0.
    *R(VIRTIO_MMIO_QUEUE_SEL_OFFSET) = 0;
    uint32_t max = *R(VIRTIO_MMIO_QUEUE_NUM_MAX_OFFSET);
    if(max == 0)
        return 1;
    if(max < NUM)
        return 1;
    *R(VIRTIO_MMIO_QUEUE_NUM_OFFSET) = NUM;
    memset(disk.pages, 0, sizeof(disk.pages));
    *R(VIRTIO_MMIO_QUEUE_PFN_OFFSET) = (((uint64_t)disk.pages) - PV_OFFSET) >> PGSHIFT;

    // desc = pages -- num * VRingDesc
    // avail = pages + 0x40 -- 2 * uint16, then num * uint16
    // used = pages + 4096 -- 2 * uint16, then num * vRingUsedElem
    // disk.desc = (vring_desc_t *) disk.pages;
    // disk.avail = (uint16_t*)(((char*)disk.desc) + NUM*sizeof(vring_desc_t));
    // disk.used = (vring_used_t *) (disk.pages + PGSIZE);
    // for(int i = 0; i < NUM; i++)
    //     disk.free[i] = 1;
    uart_puts("vdisk init success\n");
    return 0;
}



