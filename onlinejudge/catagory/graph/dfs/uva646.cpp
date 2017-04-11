#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N = 25;
char str[N][N];
int g[N][N], sn, tmp[N], tn;

void build(int i) {
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
			g[str[i][j] - 'A'][str[i][k] - 'A'] = g[str[i][k] - 'A'][str[i][j] - 'A'] = 1;
}

bool check1(int i, int j) {
	int num = 0;
	if (g[j][i]) return false;
	for (int k = 0; k < 16; k++)
		if (g[i][k] + g[j][k] == 0) {
			str[12][num + 2] = k + 'A';
			num++;
		}
	return num == 2;
}

bool check2(int num) {
	tn = 0;
	for (int i = 0; i < 16; i++) {
		if (g[num][i]) continue;
		tmp[tn++] = i;
	}
	return tn == 3;
}

bool solve() {
	int i;
	for (i = 1; i < 16; i++) {
		if (g[0][i]) continue;
		if (!check1(0, i)) return false;
		str[12][0] = 'A'; str[12][1] = i + 'A';
		build(sn); sn++;
		break;
	}
	for (i = 0; i < 4; i++) {
		if (!check2(str[12][i] - 'A')) return false;
		str[16 + i][0] = str[12][i];
		for (int j = 0; j < tn; j++)
			str[16 + i][1 + j] = tmp[j] + 'A';
		build(16 + i);
		sn++;
	}
	for (i = 1; i < 4; i++) {
		if (!check2(str[16][i] - 'A')) return false;
		str[12 + i][0] = str[16][i];
		for (int j = 0; j < tn; j++)
			str[12 + i][1 + j] = tmp[j] + 'A';
		build(12 + i);
		sn++;
	}
	return true;
}

int main() {
	int bo = 0, i;
	memset(str, 0, sizeof(str));
	while (~scanf("%s", str[0])) {
		memset(g, 0, sizeof(g));
		for (i = 0; i < 16; i++)
			g[i][i] = 1;
		build(0); sn = 12;
		for (i = 1; i < 12; i++) {
			scanf("%s", str[i]);
			build(i);
		}
		if (!solve()) printf("It is not possible to complete this schedule.\n");
		else {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 4; j++)
					printf("%c", str[i][j]);
				if ((i + 1) % 4 == 0)
					printf("\n");
				else printf("\t");
			}
		}
		printf("\n");
	}
	return 0;
}
