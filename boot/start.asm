.set ALIGN_, 1<<0
.set MEMINFO, 1<<1
.set FLAGS_, ALIGN_ | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS_)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS_
.long CHECKSUM

.section .bss
.align 16
stackBottom:
.skip 16384 # 16 KiB
stackTop:

.section .text
.global _start
.type _start, @function
_start:
    mov $stackTop, %esp
    cli
1:  hlt
    jmp 1b

.size _start, . - _start # useful for debugging
