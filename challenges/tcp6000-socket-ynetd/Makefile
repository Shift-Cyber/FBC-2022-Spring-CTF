# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = clean

CC = gcc                        # compiler to use

compile:
		@echo "Compiling... x86, not PIE"
		${CC} -m32 -no-pie -fno-stack-protector vuln.c -o vuln

flag:
		@echo "Generating flag..."
		echo "flag{placeholder_flag}" > flag.txt

clean:
		@echo "Cleaning up..."
		rm vuln flag.txt