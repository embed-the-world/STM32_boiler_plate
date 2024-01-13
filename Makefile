


.PHONY: clean compile flash

all: clean compile flash
	


compile:
	make --directory=./external/configCubeMx

clean:
	make --directory=./external/configCubeMx clean

flash:
	cp ./external/configCubeMx/build/configCubeMx.bin ./flashable/flashfile.bin
	st-flash write ./flashable/flashfile.bin 0x08000000

test: 
	echo hi


