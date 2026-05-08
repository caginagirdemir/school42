#include <unistd.h>
#include <stdio.h>
int get_digit_num(int num)
{
	int count;
	count = 0;
	while(num !=0)
	{
		count++;
		num /= 10;
	}
	return(count);
}

int *get_divide_number(int a)
{
	
}

void ft_print_combn(int n)
{
	int counter;
	int counter_2;
	int temp; //basamak kadar ekrana write icin
	int temp_2; //bolum sayisini hesaplamak icin
	int digit;
	int divide_number;

	char char_1;
	double number;
	divide_number = 1;
	printf("%d \n",n);
	temp = n;
	if(n > 0 && n <10)
	{
		while (digit < n+1)
		{
			digit = get_digit_num(counter);
			counter++;
			temp=n;
			temp_2=counter;
			while(temp>=1)
			{
				number = temp_2 / 10;
				temp_2 = temp_2 - (number * 10);

				char_1 = number + 48;
				write(1,&char_1,1);

				temp--;
			}
			printf(" ");
		}
	}
}

int main(void)
{
	ft_print_combn(2);
	return (0);
}
