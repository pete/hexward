#include <hexward.h>
#include <wordlist.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
   dest is the destination, i.e., where you want this function to put the
   string.
   maxlen is the maximum size of the string.
   data is a big block of binary data that we generate the string from.
   size is how much data we have, in bytes.

   Returns dest on success, NULL on overflow or other failure.

   This is likely to change, as we'll want variable-length chunks (i.e., for a
   160-bit SHA1, you might prefer either 10 words from the long list of 65,536
   or 20 words from the short list of the 256 most frequent).  It's hard-coded
   as shorts for right now.  It may be that a macro to define the function is
   the best shot.

   The separator is hard-coded, although the work should probably be shifted off
   to a function that just produces an array of pointers into the word-list
   rather than building the string and doing the logic in the same place.

   I was pleasantly surprised that the whole function came out much simpler than
   I had expected.
*/
char *to_hexward(char *dest, size_t maxlen, char *data, size_t size)
{
	int i, len = 0, cur;
	unsigned short chunk;

	size /= sizeof(i);
	memset(dest, 0, maxlen);

	for(i = 0; i <= size; i++) {
		chunk = ((short *) data)[i];

		cur = snprintf(dest + len, maxlen - len, "%s", hexwords[chunk]);
		puts(dest);
		len += cur + 1;
		if(len >= maxlen && strlen(hexwords[chunk]) > cur)
			return NULL;
		dest[len - 1] = '-';
	}
	dest[len - 1] = 0;
	return dest;
}
