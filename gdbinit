set disassemble-next-line on
b _entry
b start_kernel
b switch_to
b sched_init
b schedule
b uart_init
b trap_handler
b trap_vector
target remote : 1234
c
