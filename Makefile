


.PHONY: clean compile flash reset

all: clean compile flash reset


compile:
	make --directory=./external/configCubeMx

clean:
	make --directory=./external/configCubeMx clean

flash:
	cp ./external/configCubeMx/build/configCubeMx.bin ./flashable/flashfile.bin
	st-flash write ./flashable/flashfile.bin 0x08000000

reset:
	sleep 1
	st-flash reset

test: 
	gcc -Wall -Wextra \
	-Iproject_files/testing -Iproject_files/basics \
	-o project_files/testing/test_exme \
	project_files/testing/test_uart_handler.c \
	project_files/basics/uart_handler.c
	echo "** starting test **"
	./project_files/testing/test_exme

