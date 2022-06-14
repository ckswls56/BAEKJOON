#include <stdio.h>
#include <string.h>

int main(void) {
	int count = 0, len;
	char str[1000000];

	scanf("%[^\n]s", str);
	//아주 중요함!! 엔터 나오기까지 문자열 받겠다는 뜻! 이거 안 써주면 공백에서 문자 짤림
	len = strlen(str);
	if (len == 1000020 || len == 1 && str[0]==' ')
		printf("0");
	else {
		for (int i = 1; i<len - 1; i++) {
			if (str[i] == ' ') {
				count++;
			}
		}
		printf("%d", count + 1);
	}

	return 0;
}
