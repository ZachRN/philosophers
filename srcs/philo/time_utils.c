#include <sys/time.h>
#include <unistd.h>

size_t	time_in_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	my_sleep(size_t miliseconds)
{
	size_t start_time;
	size_t end_time;

	start_time = time_in_ms();
	end_time = start_time;
	while (end_time - start_time < miliseconds)
	{
		usleep(1000);
		end_time = time_in_ms;
	}
}