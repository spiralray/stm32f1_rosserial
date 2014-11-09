/* Linker script Lowerside for STM32F1 Series! 			*/
/* (c) Nemui Trinomius (http://nemuisan.blog.bai.ne.jp) */
/* Based on Mathin' Thomas's sample thanks !			*/

/* Sections And Definitions */
SECTIONS
{
	/* the program code is stored in the .text section, which goes to Flash */
    .text :
    {
	    . = ALIGN(4);
		/* for Cortex devices, the beginning of the startup code is stored in the 
									.isr_vector section, which goes to FLASH */
	    KEEP(*(.isr_vector))	   	/* Startup code */
	    . = ALIGN(4);
        *(.text .text.*)          	/* remaining code */
		KEEP(*(.init))
		KEEP(*(.fini))
        *(.gnu.linkonce.t.*)
        *(.glue_7)					/* glue arm to thumb code */
        *(.glue_7t)					/* glue thumb to arm code */
		*(.vfp11_veneer)
		*(.janus_2cc_veneer)
		*(.v4_bx)
        *(.gcc_except_table)
        *(.rodata .rodata.*)        /* read-only data (constants) */
		KEEP(*(.ioview .ioview.*))	/* I/O View */
        *(.gnu.linkonce.r.*)
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	    . = ALIGN(4);
        
    } >ROM

	/* .ctors .dtors are used for c++ constructors/destructors */
	/* added by Martin Thomas 4/2005 based on Anglia Design example */
	.ctors :
	{
		PROVIDE(__ctors_start__ = .);
		KEEP(*(SORT(.ctors.*)))
		KEEP(*(.ctors))
		. = ALIGN(4);
		PROVIDE(__ctors_end__ = .);
		. = ALIGN(4);
	} >ROM
	
	.dtors :
	{
		PROVIDE(__dtors_start__ = .); 
		KEEP(*(SORT(.dtors.*)))
		KEEP(*(.dtors))
		. = ALIGN(4);
		PROVIDE(__dtors_end__ = .);
		. = ALIGN(4);
	} >ROM
    
    . = ALIGN(4);
	/* mthomas - end */
 
	/* .eh_frame_hdr is sorted, so has to go in its own output section.  */
	.eh_frame_hdr : ALIGN (4)
	{
		KEEP (*(.eh_frame_hdr))
	} >ROM
	.eh_frame : ALIGN (4)
	{
		KEEP (*(.eh_frame))
	} >ROM

	/* .ARM.exidx is sorted, so has to go in its own output section.  */
	PROVIDE_HIDDEN (__exidx_start = .);
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} >ROM
	PROVIDE_HIDDEN (__exidx_end = .);

	. = ALIGN(4);
	/* nemui - end */
	
	/* This is used by the startup in order to initialize the .data secion */
    _etext = . ;
    PROVIDE (etext = .);
    _sidata = _etext;
    
    /* This is the initialized data section
    The program executes knowing that the data is in the RAM
    but the loader puts the initial values in the FLASH (inidata).
    It is one task of the startup to copy the initial values from FLASH to RAM. */
    .data  : AT ( _sidata )
    {
	    . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _sdata = . ;
        _data = .;
		*(.data .data.*)
		*(.gnu.linkonce.d*)
	
		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);


		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		KEEP(*(.jcr*))
	
        . = ALIGN(4); 	/* 20090714 Nemui */
        *(.ramfunc*) 	/* 20090714 Nemui */
        . = ALIGN(4); 	/* 20090714 Nemui */

        *(.RAMtext)
	    . = ALIGN(4);
	    /* This is used by the startup in order to initialize the .data secion */
   	 _edata = . ;
    } >RAM1
		

    /* This is the uninitialized data section */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _sbss = .;
        __bss_start = . ;
        __bss_start__ = . ;
        *(.bss .bss.*)
        *(.gnu.linkonce.b*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = . ;
    } >RAM1
    __bss_end__ = _end ;
    PROVIDE (__bss_end = _end);
  
    /* This is the heap data section */
	/* stack bottom is at end of RAM. */
	.heap (NOLOAD) :
	{
		_end = . ;					/* This is used by the syscalls */
		end = _end ;				/* This is used by the syscalls */
		PROVIDE (_end = .);			/* This is used by the syscalls */
		PROVIDE (end = _end);		/* This is used by the syscalls */
		PROVIDE (_heap = .);
		*(.heap .heap.*)  
		*(.HEAP)
		. = ALIGN(4);
	} >RAM1
	. = ALIGN(4);
	__heap_end = . ;
	PROVIDE (__heap_end = .);

    /* This is the Stack section */
	/* .stack section which is used for auto variable */
	.stack (NOLOAD) :
	{
		_stack_top = . ;
		PROVIDE (_stack_top = .);
		*(.stack .stack.*)  
		*(.STACK)
		_stack = . ;
		PROVIDE (_stack = .);
	} >RAM1
	. = ALIGN(8);
	_stack_end = _estack;
	PROVIDE (_stack_end = _estack);


    /* This is the External RAM section */
	.extram (NOLOAD) :
	{
		_extram = . ;
		extram = . ;
		PROVIDE (extram = .);
		PROVIDE (_extram = .);
		*(.extram .extram.*)  
		*(.EXTRAM)
		. = ALIGN(4);
	} >RAM5


    /* after that it's only debugging information. */
    /* remove the debugging information from the standard libraries */
	
    /DISCARD/ :
    {
		libc.a ( * )
		libm.a ( * )
		libgcc.a ( * )
    }

    /* Stabs debugging sections.  */
    .stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /* DWARF debug sections.
       Symbols in the DWARF debugging sections are relative to the beginning
       of the section so we begin them at 0.  */
    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }

	.note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
	.ARM.attributes 	0 : { KEEP (*(.ARM.attributes)) }
	/DISCARD/ : { *(.note.GNU-stack) }
	/DISCARD/ : { *(.gnu.lto*) }			/* Need after GCC4.5.x by nemui-san */

}
