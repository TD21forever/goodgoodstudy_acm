#include<iostream>
#include<algorithm>
using namespace std;
struct Points {
	int X, Y;
};
struct Pipes {
	Points Point[101];
	int Num;
}Pipe[35];
long long Matrix(Points a,Points b,Points c) {//叉乘
	int x1 = c.X - a.X;
	int y1 = c.Y - a.Y;
	int x2 = b.X - a.X;
	int y2 = b.Y - a.Y;

	return x1*y2 - x2*y1;
}
bool OnSegment(Points a, Points b, Points c) {//判断当叉乘=0时，点是否在线段上
	int MinX = min(a.X, b.X);
	int MaxX = max(a.X, b.X);
	int MinY = min(a.Y, b.Y);
	int MaxY = max(a.Y, b.Y);

	if (c.X >= MinX&&c.X <= MaxX&&c.Y >= MinY&&c.Y <= MaxY) {
		return true;
	}
	return false;
}

bool Interset(Points a, Points b, Points c, Points d) {//判断是否相交
	long long d1 = Matrix(c, d, a);
	long long d2 = Matrix(c, d, b);
	long long d3 = Matrix(a, b, c);
	long long d4 = Matrix(a, b, d);

	if (d1*d2 < 0 && d3*d4 < 0) {
		return true;
	}
	else if (d1 == 0 && OnSegment(c,d,a)) {
		return true;
	}
	else if (d2 == 0 && OnSegment(c, d, b)) {
		return true;
	}
	else if (d3 == 0 && OnSegment(a, b, c)) {
		return true;
	}
	else if (d4 == 0 && OnSegment(a, b, d)) {
		return true;
	}
	else
		return false;

}
void Printf(int N) {

	for (int i = 0; i < N; i++) {
		for (int l = 0; l < Pipe[i].Num-1; l++) {
			for (int j = i + 1; j < N; j++) {
				for (int g = 0; g < Pipe[j].Num-1; g++) {
					if (Interset(Pipe[i].Point[l], Pipe[i].Point[l + 1], Pipe[j].Point[g], Pipe[j].Point[g + 1])) {
						printf("Yes\n");
						return;
					}
				}
			}
		}	
	}
	printf("No\n");
}
int main() {
	int N;
	while (scanf("%d", &N) == 1) {

		for (int i = 0; i < N; i++) {
			scanf("%d", &Pipe[i].Num);
			for (int j = 0; j < Pipe[i].Num; j++) {
				scanf("%d%d", &Pipe[i].Point[j].X, &Pipe[i].Point[j].Y);
			}
		}
		Printf(N);
	}
	return 0;
}