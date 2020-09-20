#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int findSubstring(char str1[], const char str2[])
{
	int start, size;
	for (int i = 0; str1[i];)
	{
		start = i;
		for (int j = 0; str1[i] && str2[j];)
		{
			if (str1[i++] != str2[j++])
				break;
			if (!str2[j])
			{
				size = j - 1;
				int k = start;
				while (size >= 0)
				{
					if ('a' <= str1[start] && str1[start] <= 'z')
						str1[start] -= 32;
					start++;
					size--;
				}
				int b = 0;
				cout<<"\n";
				while (str1[b] != '\0')
				{
					printf("%c", str1[b]);
					b++;
				}
				return 1;
			}

		}

	}
	return 0;
}


int main()
{
	int max;
	char* mas;

	int j = 0;

	int i = 0;
	mas = (char*)calloc(1, sizeof(char));
	char c = getchar();
	while (c != '\n')
	{
		mas[i] = c;
		mas = (char*)realloc(mas, sizeof(char) * (i + 2));
		i++;
		c = getchar();
	}

	mas[i] = '\0';
	int k = 0;

	i = 0;
	int start = 0, end;
	while (mas[i] != '\0')
	{
		while (mas[i] != ' ' && mas[i] != '\0')
			i++;
		end = i - 1;
		while (start < end)
		{
			char temp = mas[start];
			mas[start] = mas[end];
			mas[end] = temp;
			start++;
			end--;
		}
		while (mas[i] == ' ')
			i++;
		start = i;
	}
	k = 0;
	printf("\n");
	while (mas[k] != '\0')
	{
		printf("%c", mas[k]);
		k++;
	}
	printf("\n");
	start = 0;
	end = k - 1;
	while (start < end)
	{
		char temp = mas[start];
		mas[start] = mas[end];
		mas[end] = temp;
		start++;
		end--;
	}
	k = 0;
	while (mas[k] != '\0')
	{
		printf("%c", mas[k]);
		k++;
	}
	findSubstring(mas, "bsuir");
	return 0;
}