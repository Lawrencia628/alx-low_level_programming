#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

/**
* create_file - creates a file with specified content
* @filename: the name of the file to create
* @text_content: NULL terminated string to write to the file
*
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, close_result;
	mode_t file_permissions = S_IRUSR | S_IWUSR;  /* rw------- */

	if (filename == NULL)
	return (-1);

	/* Create or truncate the file */
file_descriptor = open;
	if (file_descriptor == -1)
	return (-1);

	if (text_content != NULL)
	{
	/* Write content to the file */
	write_result = write(file_descriptor, text_content, strlen(text_content));
	if (write_result == -1)
	{
	close(file_descriptor);
		return (-1);
	}
	}

	/* Close the file descriptor */
	close_result = close(file_descriptor);
	if (close_result == -1)
	return (-1);

	return (1);
}
