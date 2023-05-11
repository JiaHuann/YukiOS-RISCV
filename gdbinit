set disassemble-next-line on
b _entry
b start_kernel
target remote : 1234
c
