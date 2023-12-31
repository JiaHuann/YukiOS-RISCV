#ifndef MEMORY_CONFIG_H
#define MEMORY_CONFIG_H

#define VIRT_OFFSET             0x3F00000000L
#define UART                    0x10000000L
#define UART_V                  (UART + VIRT_OFFSET)

#define VIRTIO0                 0x10001000
#define VIRTIO0_V               (VIRTIO0 + VIRT_OFFSET)

#define CLINT                   0x02000000L
#define CLINT_V                 (CLINT + VIRT_OFFSET)

#define PLIC                    0x0c000000L
#define PLIC_V                  (PLIC + VIRT_OFFSET)

#define PLIC_PRIORITY           (PLIC_V + 0x0)
#define PLIC_PENDING            (PLIC_V + 0x1000)
#define PLIC_MENABLE(hart)      (PLIC_V + 0x2000 + (hart) * 0x100)
#define PLIC_SENABLE(hart)      (PLIC_V + 0x2080 + (hart) * 0x100)
#define PLIC_MPRIORITY(hart)    (PLIC_V + 0x200000 + (hart) * 0x2000)
#define PLIC_SPRIORITY(hart)    (PLIC_V + 0x201000 + (hart) * 0x2000)
#define PLIC_MCLAIM(hart)       (PLIC_V + 0x200004 + (hart) * 0x2000)
#define PLIC_SCLAIM(hart)       (PLIC_V + 0x201004 + (hart) * 0x2000)


#define PHYSICAL_ADDRESS_BASE 0x80000000UL
#define PHYSICAL_MEMORY_SIZE 0x08000000UL
#define PHYSICAL_MEMORY_TOP (PHYSICAL_ADDRESS_BASE + PHYSICAL_MEMORY_SIZE)
#define KERNEL_STACK_SIZE 0x10000

#define PAGE_SHIFT 12
#define PAGE_SIZE (1 << PAGE_SHIFT)
#define PHYSICAL_PAGE_NUM (PHYSICAL_MEMORY_SIZE >> PAGE_SHIFT)

#define PV_OFFSET 0xFFFFFFFF00000000

#define KERNEL_ADDRESS_TOP (1L << 38)

#endif
