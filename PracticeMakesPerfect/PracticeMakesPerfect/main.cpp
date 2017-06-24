#include <iostream>
using namespace std;

void Problem1() {	//约瑟夫环
					//初始化
	int num;
	cin >> num;
	int k;
	cin >> k;
	int *a = new int[num];
	for (int i = 0; i < num; i++) {
		a[i] = 1;
	}

	int leave_kid = -1;
	int rest = num;
	int cnt;
	while (rest > 0) {
		cnt = k;
		leave_kid = (leave_kid + 1) % num;
		while (cnt > 0) {
			if (a[leave_kid] > 0) {	//有人则计数
				cnt--;
			} else {
				leave_kid++;
			}
		}
		a[leave_kid] = 0;
		rest--;
	}
	cout << "index: " << leave_kid << endl;
	delete[] a;
}

void Problem2() {	//排序
					//初始化
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int *b = new int[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	//冒泡排序
	int bubble_temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {	//j<n-i-1
			if (b[j] > b[j + 1]) {
				bubble_temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = bubble_temp;
			}
		}
	}
	//输出
	for (int k = 0; k < n; k++) {
		cout << b[k] << "  ";
	}
	//回收
	delete[]b;
	delete[]a;
}

void Problem3() {	//按大小排列字符串并输出
					//初始化
	char c[3][80], temp[80];
	for (int i = 0; i < 3; i++) {
		gets_s(c[i]);	//这种方式可以允许输入的字符数组有空格，而cin则做不到
						//cin >> c[i];
	}

	for (int i = 0; i < 3 - 1; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (strcmp(c[i], c[j]) > 0) {
				strcpy_s(temp, c[i]);
				strcpy_s(c[i], c[j]);
				strcpy_s(c[j], temp);
			}
		}
	}

	//输出
	for (int i = 0; i < 3; i++) {
		puts(c[i]);
		//cout << c[i];
	}
}

void Problem4() {	//素数筛
	int a[1001] = { 0 };
	int endl_cnt = 0;
	for (int i = 2; i <= 1000; i++) {
		if (a[i] == 0) {
			for (int j = 2; j*i <= 1000; j++) {
				a[i*j] = 1;
			}
			cout << i << " ";
			endl_cnt++;
			if (endl_cnt == 10) {
				endl_cnt = 0;
				cout << endl;
			}
		}
	}
}

void Problem5() {	//蛇形矩阵
	int n;	//阶数
	cin >> n;
	//动态分配空间
	int** array2D;
	array2D = new int*[n];
	for (int i = 0; i < n; i++) {
		array2D[i] = new int[n];
	}
	/*
	不知道哪里错了
	int i = n - 1, j = 0,k = 1;
	while (k <= n*n) {
	while (j > 0 && i > 0) {	//左上方向
	array2D[i][j] = k;
	k++;
	i--;
	j--;
	}
	array2D[i][j] = k;
	k++;
	if (k > n*n) {
	break;
	}
	if (j == 0 && i!=0) {
	i--;
	}
	else if (i == 0) {
	j++;
	}
	while (i < n - 1 && j < n - 1) {	//右下方向
	array2D[i][j] = k;
	k++;
	i++;
	j++;
	}
	array2D[i][j] = k;
	k++;
	if (i = n - 1 && j != n - 1) {
	j++;
	}
	else if (j == n - 1) {
	i--;
	}
	}
	*/
	int row = n - 1, col = 0, num = 1;
	bool up = true;
	array2D[row][col] = num;
	while (num < n*n) {
		if (up) {
			row--;
			col--;
		} else {
			row++;
			col++;
		}
		if (row == -1) {	//超过首行
			row++;
			col = col + 2;
			up = !up;
		}
		if (col == n) {	//超过末列
			row = row - 2;
			col--;
			up = !up;
		}
		if (row == n) {	//超过末行
			row--;
			up = !up;
		}
		if (col == -1) {
			col++;
			up = !up;
		}
		num++;
		array2D[row][col] = num;
	}

	//输出
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array2D[i][j] << " ";
		}
		cout << endl;
	}
	//释放
	for (int i = 0; i < n; i++) {
		delete[] array2D[i];
	}
	delete array2D;
	//或直接"delete[] array2D;"即可全部释放 
}

void Problem6_Sub(int b[], int n);
void Problem6() {	//将整数数组内容逆序存放
	int a[10], i;
	for (i = 0; i < 10; i++) {
		cin >> a[i];
	}
	Problem6_Sub(a, 10);	//交换
//输出
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
void Problem6_Sub(int b[], int n) {
	int i, temp;
	for (i = 0; i < n / 2; i++) {
		temp = b[i];
		b[i] = b[n - 1 - i];
		b[n - 1 - i] = temp;
	}
}

int Problem7_Sub_AllEqual(int x[10]) {
	int i;
	for (i = 1; i < 10; i++) {
		if (x[i] != x[0])
			return 0;
	}
	return 1;
}
void Problem7_Sub_Supply(int x[10]) {
	for (int i = 0; i < 10; i++) {
		if (x[i] % 2 != 0) {
			x[i] = x[i]++;
		}
	}
}
void Problem7_Sub_Exchange(int x[10]) {
	int temp = x[9] / 2;
	for (int i = 9; i > 0; i--) {
		x[i] = x[i] / 2 + x[i - 1] / 2;
	}
	x[0] = x[0] / 2 + temp;
}
void Problem7() {	//分糖果
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	while (!Problem7_Sub_AllEqual(a)) {
		Problem7_Sub_Supply(a);
		Problem7_Sub_Exchange(a);
		cnt++;
	}
	//输出
	cout << "cnt : " << cnt << "  ,a[n]: " << a[0];
}

long P8(int n) {	//斐波那契数列第n项
	long int f;
	if (n <= 2)
		f = 1;
	else
		f = P8(n - 1) + P8(n - 2);
	return f;
}

void P9(int n, char a, char b, char c) {	//汉诺塔问题
	if (n == 1) {
		cout << "No." << n << ":" << a << "--->" << c << endl;
	}
	else {
		P9(n - 1, a, c, b);
		cout << "No." << n << ":" << a << "--->" << c << endl;
		P9(n - 1, b, a, c);
	}
}

unsigned int P10_Sub_Random() {	//线性同余法伪随机数
	static unsigned int seed = 1;	//重点在此处的static
	seed = (25173 * seed + 13849) % 65536;
	return seed;
}
void P10(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << P10_Sub_Random();
		if (i % 10 == 0) {
			cout << endl;
		} else {
			cout << "\t";
		}
	}
}


int main()
{
	//Problem1();
	//Problem2();
	//Problem3();
	//Problem4();
	//Problem5();
	//Problem6();
	//Problem7();
	//cout << P8(8) << endl;
	//P9(3, 'A', 'B', 'C');
	P10();
	return 0;
}

