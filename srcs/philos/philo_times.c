#include <structs.h>
#include <sys/time.h>

size_t current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

size_t my_sleep(size_t miliseconds)
{
	size_t end_time;
	size_t start_time;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	start_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	end_time = start_time;
	while (end_time - start_time < miliseconds)
	{
		usleep(miliseconds/1000);
		gettimeofday(&tv, NULL);
		end_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	}
	return (end_time - start_time);
}