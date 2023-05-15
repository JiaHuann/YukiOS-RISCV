set disassemble-next-line on
b _entry
b start_kernel
b switch_to
b sched_init
b schedule
target remote : 1234
c
