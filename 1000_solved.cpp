#include <stdio.h>

int main() {
	int a, b;
	char ch;
	for (;;) {
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
		if ((ch = getchar()) == EOF)
			break;
	}
	return 0;
}
