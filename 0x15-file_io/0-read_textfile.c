#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor;
ssize_t bytes_read, bytes_written;
char *buffer;

	if (filename == NULL)
	return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
	close(file_descriptor);
	return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);
	if (bytes_read == -1)
	{
	free(buffer);
	close(file_descriptor);
	return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
	free(buffer);
	close(file_descriptor);
	return (0);
	}

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
