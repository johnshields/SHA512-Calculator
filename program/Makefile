# Program Makefile
# Make executable.
sha512calculator: main.c
	cc -o sha512calculator main.c

# Test the programs hash value.
test: tests.sh
	./tests.sh

# Clean executable.
clean:
	rm -f sha512calculator

