#include<stdio.h>
int main(){
    char input[100] = "i   like   coding";
    int len = 17;
    int size = len;
	int space = 0;
	int index;
	int flag = 0;
	int j,i;
	for (i = 0; i < len; i++){
		if (input[i] != ' ' && input[i + 1] == ' ')
			space++;
		if (input[i] == ' ' && input[i + 1] != ' ')
			index = i;
	}
	if (space != 0){
		int count = 0;
		input[len] = ' ';
		len = len + 1;
		for (j = 0; j < size; j++){
			if (input[j] != ' ' && input[j + 1] == ' ')
				count++;
			else if (count == space - 1){
				input[len] = input[j + 1];
				len++;
			}
			else{
				/*if (count == space && flag == 0){
					j = 0;
					space--;
					count = 0;
					flag = 1;

				}*/
				if (input[j] == ' '){
					input[len] = input[j];
					len++;
				}
			}
		}
		for (i = 0; input[i] != ' '; i++){
			input[len] = input[i];
			len++;
		}
		for (i = index + 1, j = 0; i < len; i++){
			input[j] = input[i];
			j++;
		}
		input[j] = '\0';
		printf("%s", input);
    }
    else{
        printf("%s", input);
    }
    return 0;
}
