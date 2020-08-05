PACKAGES = bash coreutils iputils net-tools strace util-linux iproute pciutils 
SMD = supermin.d

QEMU = qemu-system-x86_64
options = -enable-kvm -smp 4 -m 20G -s
DEBUG = -S
KERNEL = .-kernel /bzImage
KERNELU = -kernel ../linux/arch/x86/boot/bzImage
SMOptions = -initrd min-initrd.d/initrd -hda min-initrd.d/root
DISPLAY = -nodefaults -nographic -serial stdio
MONITOR = -nodefaults -nographic -serial mon:stdio
COMMANDLINE = -append "console=ttyS0 root=/dev/sda nokaslr net.ifnames=0 biosdevname=0 nopti nosmap mds=off ip=10.255.19.133:::255.255.224.0::eth0:none"
NETWORK = -device virtio-net,netdev=usernet -netdev user,id=usernet,hostfwd=tcp::5555-:5555

TARGET = min-initrd.d

.PHONY: all supermin build-package clean
all: clean $(TARGET)/root

clean:
	clear

supermin:
	@if [ ! -a $(SMD)/packages -o '$(PACKAGES) ' != "$$(tr '\n' ' ' < $(SMD)/packages)" ]; then \
	  $(MAKE) --no-print-directory build-package; \
	else \
	  touch $(SMD)/packages; \
	fi

build-package:
	supermin --prepare $(PACKAGES) -o $(SMD)

supermin.d/packages: supermin

supermin.d/init.tar.gz: init
	tar zcf $@ $^

lebench:
	gcc -o $@ OS_Eval.c -lpthread --static

LIBGCC_PATH=/root/MPC-UKL/C-Constructor/helpers/
GLIBC_CRT_PATH=/root/MPC-UKL/C-Constructor/helpers/

CRT_STARTS= $(GLIBC_CRT_PATH)/crt1.o $(GLIBC_CRT_PATH)/crti.o $(LIBGCC_PATH)/crtbeginT.o
CRT_ENDS= $(GLIBC_CRT_PATH)/crtn.o $(LIBGCC_PATH)/crtend.o

lebench-local-glibc: /root/localGlibc/glibc-build/nptl/libpthread.a  /root/localGlibc/glibc-build/libc.a
	gcc -c -o lebench.o OS_Eval.c
	ld -o $@ \
	$(CRT_STARTS) \
	-L/usr/lib/gcc/x86_64-redhat-linux/8 \
	lebench.o \
	--start-group /root/localGlibc/glibc-build/nptl/libpthread.a /root/localGlibc/glibc-build/libc.a -lgcc -lgcc_eh --end-group \
	$(CRT_ENDS)


supermin.d/lebench-lg.tar.gz: lebench-local-glibc
	tar zcf $@ $^

supermin.d/lebench.tar.gz: lebench
	tar zcf $@ $^

supermin.d/tubench.tar.gz: tubench
	tar zcf $@ $^

supermin.d/innerprod.tar.gz: innerprod_test innerprod.0.dat innerprod.1.dat
	tar zcf $@ $^

$(TARGET)/root: supermin.d/packages supermin.d/init.tar.gz supermin.d/innerprod.tar.gz supermin.d/lebench-lg.tar.gz
	supermin --build -v -v -v --size 8G --if-newer --format ext2 supermin.d -o ${@D}

runU:
	$(QEMU) $(options) $(KERNELU) $(SMOptions) $(DISPLAY) $(COMMANDLINE) $(NETWORK)

debugU: 
	$(QEMU) $(options) $(DEBUG) $(KERNELU) $(SMOptions) $(DISPLAY) $(COMMANDLINE) $(NETWORK)

runL: 
	$(QEMU) $(options) $(KERNEL) $(SMOptions) $(DISPLAY) $(COMMANDLINE) $(NETWORK)

debugL: all 
	$(QEMU) $(options) $(DEBUG) $(KERNEL) $(SMOptions) $(DISPLAY) $(COMMANDLINE) $(NETWORK)

monU:
	$(QEMU) $(options) $(KERNELU) $(SMOptions) $(MONITOR) $(COMMANDLINE) $(NETWORK)
