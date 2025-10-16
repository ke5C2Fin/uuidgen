#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <uuid.h>

#ifdef __OpenBSD__
#include <unistd.h>
#endif

#define FREE(p) { free(p); p = NULL; }

int
main(int argc, char *argv[])
{
	uuid_t uuid;
	uint32_t status;
	char *str = NULL;

#ifdef __OpenBSD__
	if (pledge("stdio", NULL) == -1)
		err(1, "pledge");
	
	if (unveil(NULL, NULL) == -1)
		err(1, "unveil");
#endif

	(void)uuid_create(&uuid, &status);
	if (status != uuid_s_ok)
		err(1, "uuid_create");

	(void)uuid_to_string(&uuid, &str, &status);
	if (status != uuid_s_ok)
		err(1, "uuid_to_string");

	(void)printf("%s\n", str);
	FREE(str);
	return EXIT_SUCCESS;
}
