/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests the download speed in megabits per second (Mbs) and the size of a file in megabytes (MB). The program should calculate the download time for the file. Note that in this context one byte is eight bits. Use type  float , and use  /for division. The program should report all three values (download speed, file size, and download time) showing two digits to the right of the decimal point, as in the following:
 * At 18.12 megabits per second, a file of 2.20 megabytes
  downloads in 0.97 seconds
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int main()
{
	float download_speed, file_size;
	printf("Please input the download speed in megabits per second (Mbs) and the size of a file in megabytes (MB):");
	if (scanf("%f %f", &download_speed, &file_size) == -1)
	{
		return -1;
	}
	printf("At %.2f megabits per second, a file of %.2f megabytes\n", download_speed, file_size);
	printf("downloads in %.2f seconds\n", file_size * 8 / download_speed);
	return 0;
}