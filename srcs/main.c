#include <structs.h>

int main(int argc, char *argv[])
{
	t_input	input;

	if (!basic_error(argc))
		return (1);
	if (!input_error(argc, argv, &input))
		return (1);
}
