obj-m := scullToy.o

KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build	# shell
PWD := $(shell pwd)

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

Info:
	echo $(KERNEL_DIR)
	echo $(PWD)

# ==========================================================================
# 1. 在Makefile下，<Tab> 會被視為shell Command
# 2. make -C <Dir>: 指定Kernel Module Include 目錄位址
# 3. make M=$(PWD): 指定要編譯的目錄位址
