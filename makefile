CC=avr-gcc
PROG=avrdude
DEBUG=-Wall -g
MMCU=-mmcu=avrxmega2
CFLAGS=$(DEBUG) $(MMCU) -std=c11 -c
LFLAGS=$(DEBUG) $(MMCU)
SRC=quadcopter

help:
	@echo 'clean   - Delete all files generated from compilation'
	@echo 'object  - Compile .o   files'
	@echo 'elf     - Compile .elf files'
	@echo 'hex     - Create  .hex files'
	@echo 'flash   - Program the MCU flash memory'

clean:
	rm $(SRC).o $(SRC).elf $(SRC).hex

object:
	$(CC) $(CFLAGS) $(SRC).c

elf: object
	$(CC) $(LFLAGS) -o $(SRC).elf $(SRC).o

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(SRC).elf $(SRC).hex

flash: hex
	$(PROG) -p x32c4 -c avrispmkII -U flash:w:$(SRC).hex -F

