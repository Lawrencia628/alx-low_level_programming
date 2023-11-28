#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * create_file - creates a file with specific content
 * @filename: the name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wr, cl;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	if (text_content)
	{
	wr = write(fd, text_content, strlen(text_content));
	if (wr == -1)
	{
		close(fd);
	return (-1);
	}
	}
	cl = close(fd);
	if (cl == -1)
		return (-1);
	return (1);
}
