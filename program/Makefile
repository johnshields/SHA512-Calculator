#!make
# Program Makefile
# Make executable.
sha512calculator: sha512calculator.c
	cc -o sha512calculator sha512calculator.c

# Test the programs hash value.
test: tests.sh
	./tests.sh

# Clean executable.
clean:
	rm -f sha512calculator

