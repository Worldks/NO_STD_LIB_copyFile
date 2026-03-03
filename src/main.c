#include "../inc/calls.h"
#include "../inc/number_convert.h"

enum { buffer_size = 4096 };
static const char error_message[] = "\nError was appear. Error code: ";
static const char error_copy[] = "\nError during copy file.\n";
static const char error_write[] = "\nError during writing buffer to file.\n";
static const char error_not_enought_args[] = "\nNeed 2 file name.\n";

char error_code[max_number_length] = { 0 };

void copy_file(int fd_from, int fd_to, char *buffer);

int main(int argc, char **argv)
{
	char buffer[buffer_size] = { 0 };
	char error_code[max_number_length] = { 0 };
	int fd_from, fd_to;

	if(argc < 3) {
		sys_write(1, error_not_enought_args, 
						sizeof(error_not_enought_args));
		return 1;
	}
	
	fd_from = sys_open_2param(argv[1], 0); /* O_RDONLY */
	if(fd_from == -1) {
		sys_write(1, error_message, sizeof(error_message));
		number_to_str(sys_errno, error_code);
		sys_write(1, error_code, sizeof(error_code));
		sys_write(1, "\n", 1);
		sys_exit(1);
	}
	
	fd_to = sys_open_3param(argv[2], 0x241, 0666); /**/
	if(fd_to == -1) {
		sys_write(1, error_message, sizeof(error_message));
		number_to_str(sys_errno, error_code);
		sys_write(1, error_code, sizeof(error_code));
		sys_write(1, "\n", 1);
		sys_exit(1);
	}
	
	copy_file(fd_from, fd_to, buffer);

	sys_close(fd_from);
	sys_close(fd_to);
	
	return 0;
}

void copy_file(int fd_from, int fd_to, char *buffer)
{
	int is_write, is_read = 1;
	
	while(is_read) {
		is_read = sys_read(fd_from, buffer, buffer_size);
		if(is_read == 0) { /* EOF */
			break;
		} else if(is_read == -1) { /* error */
			sys_write(1, error_copy, sizeof(error_copy));
			sys_write(1, error_message, sizeof(error_message));
			number_to_str(sys_errno, error_code);
			sys_write(1, error_code, sizeof(error_code));
			sys_write(1, "\n", 1);
			sys_exit(1);
		}
		is_write = sys_write(fd_to, buffer, buffer_size);
		if(is_write == -1) {
			sys_write(1, error_write, sizeof(error_copy));
			sys_write(1, error_message, sizeof(error_message));
			number_to_str(sys_errno, error_code);
			sys_write(1, error_code, sizeof(error_code));
			sys_write(1, "\n", 1);
			sys_exit(1);
		}
	}
}
