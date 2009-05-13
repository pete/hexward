#include <stdio.h>
#include <hexward.h>

#define ENOUGH 0x1000

int main(int argc, char **argv)
{
	/* TODO:  You call this a test suite? */
	char output[ENOUGH];
	// This is an array of shorts equivalent to 160-bit SHA1 hashes.  Just
	// for testing; all you actually need is a big block of data.  The idea
	// here is that we want to have a more friendly representation 
	short data[40] = {
		0x9bfd,
		0xafc6,
		0xa584,
		0xb19b,
		0x1abc,
		0xa7a8,
		0x4b09,
		0xf4e1,
		0x27ac,
		0x0875,

		/* TODO:  Have a couple more tests. */
	};

	to_hexward(output, ENOUGH, (char *)data, 20);
	puts(output);

	return 0;
}
