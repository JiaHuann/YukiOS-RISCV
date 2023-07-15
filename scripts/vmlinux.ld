ENTRY(_entry)

JUMP_ADDRESS = 0x80200000;

SECTIONS
{
        . = JUMP_ADDRESS;
        PROVIDE(kernels = .);

        . = ALIGN(4096);
        PROVIDE(texts = .);
        .text : {
                *(.boot)
                *(.text .text.*)
                . = ALIGN(4096);
                PROVIDE(_texte = .);
        }

        . = ALIGN(4096);
        PROVIDE(_rodatas = .);
        .rodata : {
                *(.rodata .rodata.*)
                PROVIDE(_rodatae = .);
        }

        . = ALIGN(4096);
        PROVIDE(_datas = .);
        .data : {
                *(.data .data.*)
                . = ALIGN(4096);
                PROVIDE(_stacks = .);
                *(.stack)
                PROVIDE(_datae = .);
        }

        . = ALIGN(4096);
        PROVIDE(_bsss = .);
        .bss : {
                *(.bss .bss.* .sbss .sbss*)
                . = ALIGN(4096);
                PROVIDE(_bsse = .);
        }

        . = ALIGN(4096);
        PROVIDE(kernele = .);
}