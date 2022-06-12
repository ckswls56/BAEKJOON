#include <stdio.h>
int main() {

	int hour, min, plus;
	scanf("%d", &hour);
	scanf("%d\n", &min);
	scanf("%d", &plus);
	while (min + plus >= 60) {
		hour++;
		plus -= 60;
	}
	if (hour >= 24)
		hour -= 24;
	min += plus;
	printf("%d %d", hour, min);
	return 0;
}
