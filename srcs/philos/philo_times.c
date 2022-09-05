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

	start_time = current_time();
	end_time = start_time;
	while (end_time - start_time <= miliseconds)
	{
		usleep(miliseconds);
		end_time = current_time();
	}
	return (end_time - start_time);
}