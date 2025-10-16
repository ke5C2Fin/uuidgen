#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uuid.h>

#define FREE(p) { free(p); p = NULL; }

int
main(int argc, char *argv[])
{
	uuid_t uuid;
	uint32_t status;
	char *str = NULL;

	if (pledge("stdio", NULL) == -1)
		err(1, "pledge");

	if (unveil(NULL, NULL) == -1)
		err(1, "unveil");

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
