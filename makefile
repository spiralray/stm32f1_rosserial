#################################################
# MAKEFILE For STM32F4xxx Devices 				#
# (c) 20120630 Nemui Trinomius					#
# http://nemuisan.blog.bai.ne.jp				#
#################################################

# Environment Dependent!!! This Environment assure under WINDOWS !!
# Throw path into YOUR environments for each Operation Systems.
ifneq (,$(filter $(shell uname),Darwin Linux))
# If Mac or Linux
else
# If Windows
export PATH = %SYSTEMROOT%;$(TOOLDIR)/bin;$(OCDIR);$(DFUDIR);$(MAKEDIR)
endif

# Toolchain prefix (i.e arm-none-eabi -> arm-none-eabi-gcc.exe)
ifneq (,$(filter $(shell uname),Darwin Linux))
TCHAIN  = /usr/local/arm-cs-tools/bin/arm-none-eabi
else
# Toolchain prefix (i.e arm-none-eabi -> arm-none-eabi-gcc.exe)
TCHAIN  = "$(GNU_ARM_PATH)/bin/arm-none-eabi"
endif

# OpenOCD prefix
OCD		= openocd
# Select OpenOCD Transport
OCDMODE = SWD
#OCDMODE = JTAG

# Select SWD Debug Adapter
DBG_ADAPTER  = STLINKV2
#DBG_ADAPTER  = JTAGKEY2_SWD
#DBG_ADAPTER  = CMSIS-DAP
#DBG_ADAPTER  = VERSALOON

# OpenOCD For FT2232 Devices Special Setting
# If u use WinUSB as Device Driver,uncomment this!
MPSSE	= ftdi
#MPSSE	= 

# Development Tools based on GNU Compiler Collection
DEVTOOL = LAUNCHPAD
#DEVTOOL = BLEEDING_EDGE
#DEVTOOL = YAGARTO
#DEVTOOL = DEVKITARM
#DEVTOOL = SOURCERY

# Check BuildTools
ifeq ($(DEVTOOL),LAUNCHPAD)
 TOOLDIR = C:/Devz/ARM/Launchpad
 NANOLIB = --specs=nano.specs
  NANOLIB += -u _printf_float
  NANOLIB += -u _scanf_float
 REMOVAL = rm
else ifeq ($(DEVTOOL),BLEEDING_EDGE)
 TOOLDIR = C:/Devz/ARM/Bleeding-edge
 REMOVAL = rm
else ifeq ($(DEVTOOL),DEVKITARM)
 TOOLDIR = C:/Devz/ARM/devkitARM
 REMOVAL = rm
else ifeq ($(DEVTOOL),YAGARTO)
 TOOLDIR = C:/Devz/ARM/Yagarto
 REMOVAL = rm
else ifeq ($(DEVTOOL),SOURCERY)
 TOOLDIR = C:/Devz/ARM/Sourcery
 REMOVAL = rm
else
 $(error SET BUILD-TOOLS AT FIRST!!)
endif

# Set UNIX-Like Tools(CoreUtils) Directory
MAKEDIR = C:/Devz/Coreutils/bin

# Set Flasher and Debugger
ifneq (,$(filter $(shell uname),Darwin Linux))
	OCDIR	= /usr/local/openocd
else
	OCDIR	= C:\openocd
endif

#OCD_DBG = -c "debug_level 3"
ifeq ($(OCDMODE),SWD)
ifeq ($(DBG_ADAPTER),VERSALOON)
OCD_ARG = -s $(OCDIR)/tcl						\
		  -f interface/vsllink_swd.cfg			\
		  -f target/stm32f1x.cfg
else ifeq ($(DBG_ADAPTER),CMSIS-DAP)
OCD_ARG = -s $(OCDIR)/tcl						\
		  -f interface/cmsis-dap.cfg			\
		  -f target/stm32f1x.cfg
else ifeq ($(DBG_ADAPTER),JTAGKEY2_SWD)
OCD_ARG = -s $(OCDIR)/tcl						\
		  -f interface/jtagkey2_swd.cfg 		\
		  -f target/stm32f1x.cfg
else
OCD_ARG = -s $(OCDIR)/tcl						\
		  -f target/stm32f1x.cfg
endif
else
OCD_ARG = -s $(OCDIR)/tcl						\
		  -f interface/$(MPSSE)/jtagkey2.cfg 	\
          -f target/stm32f1x.cfg
endif
OCD_CMD = $(OCD_DBG) $(OCD_ARG)


#Set DFUse Directory
DFUDIR	= C:/Devz/ARM/ST/DFUse/BIN
#Set Shell Definitions
WSHELL  = cmd
MSGECHO = echo
#Set GDB/Insight Directory
GDBDIR  = C:/Devz/ARM/insight/bin
INSIGHT = $(GDBDIR)/arm-none-eabi-insight
# Environment Dependent!!!


# OPTIMIZE Definition
#OPTIMIZE		= fast
OPTIMIZE		= 2

# GCC LTO Specific Option
ifneq ($(OPTIMIZE),0)
USE_LTO			= -flto-partition=none -fipa-sra
#USE_LTO			= -flto -fipa-sra
endif
# GCC Version Specific Options
ALIGNED_ACCESS	= -mno-unaligned-access
#ARMV7M_BOOST    = -mslow-flash-data

# Apprication Version
APP_VER = W.I.P

#USE_MPU = STM32F103VET6
USE_MPU = STM32F103CBT6

ifeq ($(USE_MPU),STM32F103VET6)
 MPU_CLASS			= STM32F10x
 MPU_MODEL			= STM32F10X_HD
 SUBMODEL			= STM32F103VET6
 HSE_CLOCK 			= 12000000
 USE_EXT_SRAM   	= 
 USE_TOUCH_SENCE 	=
 STM32PLUS_Fn = STM32PLUS_F1_HD

else ifeq ($(USE_MPU),STM32F103CBT6)
 MPU_CLASS			= STM32F10x
 MPU_MODEL			= STM32F10X_MD
 SUBMODEL			= STM32F103CBT6
 HSE_CLOCK 			= 12000000
 USE_EXT_SRAM   	= 
 USE_TOUCH_SENCE 	=
 STM32PLUS_Fn = STM32PLUS_F1_MD
 #USE_DFU			= USE
else
 $(error TARGET MPU IS NOT DEFINED!!)
endif
PERIF_DRIVER    = USE_STDPERIPH_DRIVER

# Use FreeRTOS?
OS_SUPPORT		= BARE_METAL
#OS_SUPPORT		= USE_FREERTOS

USE_STM32PLUS = USE

STM32PLUS_DIR = ../stm32plus
ROSLIB_DIR = ./lib/ros_lib

ifeq ($(USE_STM32PLUS),USE)
 FWLIB  			= $(STM32PLUS_DIR)/fwlib/f1/stdperiph
 ifeq ($(USE_MPU),STM32F103VET6)
   STM32PLUS_LIB_DIR = $(STM32PLUS_DIR)/build/small-f1hd-$(HSE_CLOCK)
   STATIC_LIB   	= -lstm32plus-small-f1hd-$(HSE_CLOCK)
 endif
 ifeq ($(USE_MPU),STM32F103CBT6)
   STM32PLUS_LIB_DIR = $(STM32PLUS_DIR)/build/small-f1md-$(HSE_CLOCK)
   STATIC_LIB   	= -lstm32plus-small-f1md-$(HSE_CLOCK)
 endif
else
 FWLIB  			= ./lib/stm32plus/fwlib/f1/stdperiph
endif

# Synthesis makefile Defines
DEFZ = $(MPU_CLASS) $(SUBMODEL) $(EVAL_BOARD) $(PERIF_DRIVER) $(VECTOR_START) \
	   $(USING_HOSTAGE) $(OS_SUPPORT) $(USE_EXT_SRAM) $(USE_EXT_SDRAM) $(USE_EXT_HEAP) $(UART_DEBUG) $(USE_BOARD)
		
DEFZ += $(STM32PLUS_Fn)
		
SYNTHESIS_DEFS	= $(addprefix -D,$(DEFZ)) 							\
				 -DARM_MATH_CM3										\
				 -DPACK_STRUCT_END=__attribute\(\(packed\)\) 		\
				 -DALIGN_STRUCT_END=__attribute\(\(aligned\(4\)\)\) \
				 -DMPU_SUBMODEL=\"$(SUBMODEL)\"						\
				 -DAPP_VERSION=\"$(APP_VER)\"						\
				 -DHSE_VALUE=$(HSE_CLOCK)UL

# TARGET definition
TARGET 		= main
TARGET_ELF  = $(TARGET).elf
TARGET_SREC = $(TARGET).s19
TARGET_HEX  = $(TARGET).hex
TARGET_BIN  = $(TARGET).bin
TARGET_LSS  = $(TARGET).lss
TARGET_DFU  = $(TARGET).dfu
TARGET_SYM  = $(TARGET).sym

# define CMSIS LIBRARY PATH
#FWLIB  			= ./lib/stm32plus/fwlib/f4/stdperiph
CMSISLIB 		= ./lib/CMSIS
CMSIS_DEVICE 	= $(CMSISLIB)/Device/ST/STM32F10x

#CMSIS_CORE		= $(CMSISLIB)/Include
#CMSIS_DEVICE_INC = $(CMSISLIB)/Device/ST/STM32F4xx/Include

CMSIS_CORE		= $(STM32PLUS_DIR)/fwlib/f1/cmsis/CoreSupport
CMSIS_DEVICE_INC = $(STM32PLUS_DIR)/fwlib/f1/cmsis/CM3/DeviceSupport/ST/STM32F10x

# include PATH
INCPATHS	 = 	./							\
				./inc						\
				$(FWLIB)/inc  				\
				$(CMSIS_DEVICE_INC)			\
				$(CMSIS_CORE)				\
				$(LIBINCDIRS)				\
				$(STM32PLUS_DIR)			\
				$(STM32PLUS_DIR)/include	\
				$(STM32PLUS_DIR)/include/stl\
				$(ROSLIB_DIR)
				
INCLUDES     = $(addprefix -I ,$(INCPATHS))

# Set library PATH
LIBPATHS     = $(FWLIB) $(USBLIB) $(STM32PLUS_LIB_DIR)
LIBRARY_DIRS = $(addprefix -L,$(LIBPATHS))
# if you use math-library, put "-lm" 
MATH_LIB	 =	-lm

# LinkerScript PATH
LINKER_PATH =  ./lib/linker
LINKER_DIRS = $(addprefix -L,$(LINKER_PATH)) 

# Object definition
OBJS 	 = $(CFILES:%.c=$(OUTDIR)/%.o)  $(CPPFILES:%.cpp=$(OUTDIR)/%.o) $(SFILES:%.s=$(OUTDIR)/%.o)

# C code PATH
SOURCE  = ./src
CFILES = $(wildcard $(SOURCE)/*.c) $(wildcard $(SOURCE)/utils/*.c)  $(wildcard $(SOURCE)/hardware/*.c)

# CPP code PATH
CPPFILES = $(wildcard $(SOURCE)/*.cpp) $(wildcard $(SOURCE)/utils/*.cpp)  $(wildcard $(SOURCE)/hardware/*.cpp)

CPPFILES += $(ROSLIB_DIR)/time.cpp $(ROSLIB_DIR)/duration.cpp


#/*----- STARTUP code PATH -----*/
STARTUP_DIR = ./lib/startup
ifeq ($(OS_SUPPORT),USE_FREERTOS)
SFILES += \
	$(SOURCE)/startup_$(shell echo $(MPU_MODEL)|tr "[:upper:]" "[:lower:]")_rtos.s
else
SFILES += \
	$(STARTUP_DIR)/startup_$(shell echo $(MPU_MODEL)|tr "[:upper:]" "[:lower:]").s
endif


#/*----- STM32 Debug library -----*/
ifeq ($(OPTIMIZE),0)
CFILES += \
 ./lib/IOView/stm32f4xx_io_view.c
else
endif


OUTDIR := Build
DEPS:= $(CFILES:%.c=$(OUTDIR)/%.d) $(CPPFILES:%.cpp=$(OUTDIR)/%.d)


# TOOLCHAIN SETTING
CC 			= $(TCHAIN)-gcc
CPP 		= $(TCHAIN)-g++
OBJCOPY 	= $(TCHAIN)-objcopy
OBJDUMP 	= $(TCHAIN)-objdump
SIZE 		= $(TCHAIN)-size
AR 			= $(TCHAIN)-ar
LD 			= $(TCHAIN)-g++
NM 			= $(TCHAIN)-nm
REMOVE		= $(REMOVAL) -f
REMOVEDIR 	= $(REMOVAL) -rf

# C and ASM FLAGS
C_CXXFLAGS  = -MD -mcpu=cortex-m3 -mtune=cortex-m3 -mfix-cortex-m3-ldrd
C_CXXFLAGS += -mthumb -mlittle-endian $(ALIGNED_ACCESS) $(ARMV7M_BOOST)
C_CXXFLAGS += -mapcs-frame -mno-sched-prolog -msoft-float
C_CXXFLAGS += -gdwarf-2 -O$(OPTIMIZE) $(USE_LTO) $(NANOLIB)
C_CXXFLAGS += -fno-strict-aliasing -fsigned-char
C_CXXFLAGS += -ffunction-sections -fdata-sections
C_CXXFLAGS += -fno-schedule-insns2
C_CXXFLAGS += --param max-inline-insns-single=1000
C_CXXFLAGS += -fno-common
C_CXXFLAGS += -Wall -Wno-array-bounds -Wno-unused-but-set-variable
#C_CXXFLAGS += -Wdouble-promotion
#C_CXXFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
C_CXXFLAGS += -Wa,-adhlns=$(OUTDIR)/$(subst $(suffix $<),.lst,$<) 
C_CXXFLAGS += $(SYNTHESIS_DEFS)
C_CXXFLAGS += -g3

CFLAGS = -lstdc++ -std=gnu99

CXXFLAGS = -std=gnu++11 -fpermissive -fsigned-char -fno-rtti -fexceptions -fmessage-length=0 

# Linker FLAGS
LDFLAGS  = -mcpu=cortex-m3 -mthumb -mfix-cortex-m3-ldrd
LDFLAGS += -u g_pfnVectors -Wl,-static -Wl,--gc-sections -nostartfiles
LDFLAGS += -Wl,-Map=$(TARGET).map
LDFLAGS += $(LIBRARY_DIRS) $(LINKER_DIRS) $(MATH_LIB)
ifeq ($(USE_DFU),USE)
LDFLAGS +=-T$(LINKER_PATH)/$(SUBMODEL)_DFU.ld
else
LDFLAGS +=-T$(LINKER_PATH)/$(SUBMODEL).ld
endif


# Object Copy and dfu generation FLAGS
OBJCPFLAGS = -O
OBJDUMPFLAGS = -h -S -C
DFU	  = hex2dfu
DFLAGS = -w


# Build Object
all: gccversion build buildinform sizeafter
build: $(TARGET_ELF) $(TARGET_LSS) $(TARGET_SYM) $(TARGET_HEX) $(TARGET_SREC) $(TARGET_BIN)

.SUFFIXES: .o .c .cpp .s   

$(TARGET_LSS): $(TARGET_ELF)
	@$(MSGECHO)
	@$(MSGECHO) Disassemble: $@
	$(OBJDUMP) $(OBJDUMPFLAGS) $< > $@ 
$(TARGET_SYM): $(TARGET_ELF)
	@$(MSGECHO)
	@$(MSGECHO) Symbol: $@
	$(NM) -n $< > $@
$(TARGET).hex: $(TARGET).elf
	@$(MSGECHO)
	@$(MSGECHO) Objcopy: $@
	$(OBJCOPY) $(OBJCPFLAGS) ihex $^ $@    
$(TARGET).s19: $(TARGET).elf
	@$(MSGECHO)
	@$(MSGECHO) Objcopy: $@
	$(OBJCOPY) $(OBJCPFLAGS) srec $^ $@ 
$(TARGET).bin: $(TARGET).elf
	@$(MSGECHO)
	@$(MSGECHO) Objcopy: $@
	$(OBJCOPY) $(OBJCPFLAGS) binary $< $@ 
$(TARGET).dfu: $(TARGET).hex
	@$(MSGECHO)
	@$(MSGECHO) Make STM32 dfu: $@
	$(DFU) $(DFLAGS) $< $@
	@$(MSGECHO)
$(TARGET).elf: $(OBJS)
	@$(MSGECHO) Link: $@
	$(LD) $(C_CXXFLAGS) $(LDFLAGS) $^ -o $@ $(STATIC_LIB)
	@$(MSGECHO)
$(OUTDIR)/%.o:%.c
ifneq (,$(filter $(shell uname),Darwin Linux))
	@if [ ! -e `/usr/bin/dirname $@` ]; then /bin/mkdir -p `/usr/bin/dirname $@`; fi
else
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
endif
	@$(MSGECHO) Compile: $<
	$(CC) -c -MMD -MP $(CFLAGS) $(C_CXXFLAGS) $(INCLUDES) $< -o $@
	@$(MSGECHO)
$(OUTDIR)/%.o:%.cpp
ifneq (,$(filter $(shell uname),Darwin Linux))
	@if [ ! -e `/usr/bin/dirname $@` ]; then /bin/mkdir -p `/usr/bin/dirname $@`; fi
else
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
endif
	@$(MSGECHO) Compile: $<
	$(CPP) -c -MMD -MP $(C_CXXFLAGS) $(CXXFLAGS) $(INCLUDES) $< -o $@
	@$(MSGECHO)
$(OUTDIR)/%.o:%.s
ifneq (,$(filter $(shell uname),Darwin Linux))
	@if [ ! -e `/usr/bin/dirname $@` ]; then /bin/mkdir -p `/usr/bin/dirname $@`; fi
else
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
endif
	@$(MSGECHO) Assemble: $<
	$(CC) -c $(C_CXXFLAGS) $(INCLUDES) $< -o $@
	@$(MSGECHO)

# Object Size Informations
sizeafter: $(TARGET).elf $(TARGET).hex buildinform
	@$(MSGECHO) 
	@$(MSGECHO) Built Object Informations:
	@$(MSGECHO) === Total Binary Size ===
	@$(SIZE) $(TARGET).hex
	@$(MSGECHO) === Verbose ELF Size ===
	@$(SIZE) $(TARGET).elf
	@$(SIZE) -A -x $(TARGET).elf

# Display compiler version information.
gccversion : 
	@$(CC) --version
	@$(MSGECHO) 

buildinform :
	@$(MSGECHO) 
	@$(MSGECHO) 
	@$(MSGECHO) Built Informations:
	@$(MSGECHO) TCHAIN_PATH = $(TCHAIN)
	@$(MSGECHO) EVAL_BOARD = $(EVAL_BOARD)
	@$(MSGECHO) MPU_CLASS = $(MPU_CLASS)
	@$(MSGECHO) MPU_MODEL = $(MPU_MODEL)
	@$(MSGECHO) SUBMODEL = $(SUBMODEL)
	@$(MSGECHO) HSE_CLOCK = $(HSE_CLOCK)
	@$(MSGECHO) USING_FPU = $(USING_FPU)
	@$(MSGECHO) USING_SYSTEM = $(OS_SUPPORT)

# Flash and Debug Program
debug :
	$(WSHELL) /c start /B $(INSIGHT) $(TARGET).elf
	$(OCD) $(OCD_CMD) -c "reset halt" -c"arm semihosting enable"
program :
ifneq (,$(filter $(shell uname),Darwin Linux))
#	@cp $(TARGET).elf $(OCDIR)
#	@cd $(OCDIR) && ./$(OCD) $(OCD_CMD) -c "mt_flash $(TARGET).elf"
	@$(OCDIR)/$(OCD) $(OCD_CMD) -c "mt_flash_bin $(TARGET).bin 0x08000000"
else
	$(OCD) $(OCD_CMD) -c "mt_flash $(TARGET).elf"
#	$(OCD) $(OCD_CMD) -c "eraser"
#	$(OCD) $(OCD_CMD) -c "mt_flash_bin $(TARGET).bin 0x08000000"
endif

ifndef STM32_ST_LINK_Utility_PATH
  STM32_ST_LINK_Utility_PATH = C:/ST-LINK_Utility
endif

flash :
ifneq (,$(filter $(shell uname),Darwin Linux))
	@echo "Writing $(TARGET).bin"
	@st-flash --reset write $(TARGET).bin 0x08000000
else
	@"$(STLINK_PATH)/ST-LINK_CLI.exe" -c SWD UR -P $(TARGET).hex 0x08000000
	@"$(STLINK_PATH)/ST-LINK_CLI.exe" -c SWD UR -Rst
endif

dfu:
ifeq ($(shell uname),Darwin)
	@/usr/local/bin/dfu-util -a0 -d 0x0483:0xdf11 -s 0x08003000 -D main.bin
else
# download using DFU and DFU Tools from KSK
	@DfuConvert.exe -n Internal_Flash -v 0483 -p DF11 -b 0 -ReadFileName main.hex -CreateFileName main.dfu
	@DfuUpgrade.exe -DownFileName main.dfu -TargetIdSel 0 -v 0483 -p DF11 -b 0
	@DfuVerify.exe -DownFileName main.dfu -TargetIdSel 0 -v 0483 -p DF11 -b 0
endif

# Drop files into dust-shoot
.PHONY clean:
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).bin
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).map
	$(REMOVE) $(TARGET).s19
	$(REMOVE) $(TARGET).a90
	$(REMOVE) $(TARGET).sym
	$(REMOVE) $(TARGET).lnk
	$(REMOVE) $(TARGET).lss
	$(REMOVE) $(TARGET).dfu
	$(REMOVE) $(wildcard *.stackdump)
	$(REMOVEDIR) .dep
	$(REMOVEDIR) $(OUTDIR)
	@$(MSGECHO)

-include $(DEPS)

# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex bin lss sym clean clean_list program

