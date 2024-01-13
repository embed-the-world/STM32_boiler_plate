


.PHONY: clean compile flash

all: clean compile flash
	


compile:
	make --directory=./external/configCubeMx

clean:
	make --directory=./external/configCubeMx clean

flash:
	st-flash write ./external/configCubeMx/build/configCubeMx.bin 0x08000000

test: 
	echo hi


