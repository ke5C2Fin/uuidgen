#include <err.h>
#include <stdio.h>
#include <unistd.h>
#include <uuid.h>

int
main(int argc, char *argv[])
{
	uuid_t uuid;
	uint32_t status;
	char *str = NULL;

	if (pledge(NULL, NULL) == -1)
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
	return 0;
}
