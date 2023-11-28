#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

/**
 * error_exit - Print an error message and exit with a specific code
 * @code: Exit code
 * @msg: Error message format
 * @arg: Additional argument for the error message
 */
void error_exit(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd_exit - Close a file descriptor and exit on failure
 * @fd: File descriptor to close
 * @code: Exit code
 */
void close_fd_exit(int fd, int code)
{
	if (close(fd) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(code);
	}
}

/**
 * copy_file - Copy the content of one file to another
 * @from: Source file name
 * @to: Destination file name
 */
void copy_file(const char *from, const char *to)
{
	int fd_from, fd_to, rd, wr;
	char buffer[BUF_SIZE];

	fd_from = open(from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", from);

	fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
	close_fd_exit(fd_from, 98);
	error_exit(99, "Error: Can't write to %s\n", to);
	}

	do {
	rd = read(fd_from, buffer, BUF_SIZE);
	if (rd == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
	close_fd_exit(fd_from, 98);
	close_fd_exit(fd_to, 99);
	}

	wr = write(fd_to, buffer, rd);
	if (wr == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
	close_fd_exit(fd_from, 98);
	close_fd_exit(fd_to, 99);
	}

}
	while (rd > 0);

	close_fd_exit(fd_from, 98);
	close_fd_exit(fd_to, 99);
}

/**
 * main - Entry point of the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, or exit with a specific code on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "");

	copy_file(argv[1], argv[2]);

	return (0);
}
