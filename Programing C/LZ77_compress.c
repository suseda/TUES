#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

unsigned char* lz77_compress(unsigned char* data, unsigned short window_size, unsigned short lookahead_size)
{
	int size = strlen((char*)data);
	unsigned char* output = (char*)calloc(size + 1, sizeof(char*));
	int i = 0;
	unsigned char* new_data = malloc(sizeof(char*) * 6);
	sprintf(output, "(0,0)%c", data[i]);
	i++;
	int index, len = 0, loops_cnt = 0;
	while (i < size)
	{
		index = i - 1;
		while (index >= 0 && loops_cnt < window_size)
		{
			if (data[index] == data[i])
			{
				int k = i, w = i - index;
				while (data[index] == data[k] && len <= lookahead_size)
				{
					index++;
					k++;
					len++;
				}
				if (w <= 0)
					w = 1;
				sprintf(new_data, "(%d,%d)", w, len);
				i = i + len;
				len = 0;
				index = -2;
			}
			if (index != -2)
			{
				index--;
				loops_cnt++;
			}
		}

		if (index != -2)
		{
			sprintf(new_data, "(0,0)%c", data[i]);
			i++;
		}
		loops_cnt = 0;
		strcat((char*)output, (char*)new_data);
		memset(new_data, 0, 6);
	}

	puts("Compressed:");
	puts(output);

	return output;
}

unsigned char* lz77_decompress(unsigned char* data)
{
	int size = strlen((char*)data);
	unsigned char* output = (char*)calloc(size, sizeof(char*));
	for (int i = 0; i < size;)
	{
		if (data[i] == '(')
		{
			int P = data[i + 1] - '0';
			int L = data[i + 3] - '0';

			if (P == 0 && L == 0)
			{

				strncat((char*)output, &(data[i + 5]), 1);
				i = i + 6;
			}
			else
			{
				unsigned char* new_symbols = (char*)calloc(L, sizeof(char*));
				int len_of_output_string = strlen(output);
				for (int j = 0; j < L; j++)
				{
					new_symbols[j] = output[len_of_output_string - P];
					P--;
				}
				strcat(output, new_symbols);
				i = i + 5;
			}
		}
	}

	puts("Decompressed:");
	puts(output);

	return output;
}


/*int main()
{

	unsigned char buffer[100] = "ABCABCD";
	unsigned char* compressed_data = lz77_compress(buffer, 3, 3);
	unsigned char* decompressed_data = lz77_decompress(compressed_data);

	return 0;
}*/

int main(int argc, char** argv)
{
	int flag;
	if (!strcmp(argv[1], "compress"))
		flag = 0;
	if (!strcmp(argv[1], "decompress"))
		flag = 1;
	FILE* input_file = fopen(argv[2], "r");
	FILE* output_file = fopen(argv[3], "w");
	unsigned char data[255], * result;
	fgets(data, 255, input_file);
	if (!flag)
	{
		int window_size = atoi(argv[4]);
		int lookahead_size = atoi(argv[5]);
		result = lz77_compress(data, window_size, lookahead_size);
	}
	else
		result = lz77_decompress(data);
	printf("%s\n", result);
	fputs(result, output_file);
	fclose(input_file);
	fclose(output_file);
	return 0;
}