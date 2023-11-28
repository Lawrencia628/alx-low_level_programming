#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* append_text_to_file - appends text at the end of a file
* @filename: the name of the file
* @text_content: NULL terminated string to add at the end of the file
*
* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, close_result;

	if (filename == NULL)
	return (-1);

	if (text_content == NULL)
	return (1);  /* Nothing to add, consider it a success */

	/* Open the file in append mode */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
	return (-1);

	/* Append text to the file */
	write_result = write(file_descriptor, text_content, strlen(text_content));
	if (write_result == -1)
	{
	close(file_descriptor);
	return (-1);
	}

	/* Close the file descriptor */
	close_result = close(file_descriptor);
	if (close_result == -1)
	return (-1);

	return (1);
}
