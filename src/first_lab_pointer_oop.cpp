/** DIAGONALY*/

#include <iostream>
#include <cstdlib>

#define M 1
#define N 1

using namespace std;

int main()
{
	srand(time(0));
	unsigned char **byte = new unsigned char* [200];

	for (int i = 0; i < N; i++) {
		*(byte + i) = new unsigned char[200];
		for (int j = 0; j < M; j++) {
			byte[i][j] = (unsigned char) rand() % 5;

		}
	}

	unsigned char *q1 = new unsigned char[M * N];
	unsigned char *q2 = new unsigned char[M * N];
	unsigned char *q3 = new unsigned char[M * N];
	unsigned char *q4 = new unsigned char[M * N];
	int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;


	// output massiv
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << (int) byte[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;


	// ++ //
	for (int lim_i = 0, start_j = M - 1; lim_i < N; lim_i++, start_j--) {
		for (int i = 0, j = start_j; i <= lim_i; i++, j++) {
			// cout << (int) byte[i][j] << " ";
			q1[pos1] = byte[i][j];
			pos1++;
		}

	}

	for (int start_i = 1; start_i < N; start_i++) {
		for (int i = start_i, j = 0; i < N; i++, j++) {
			// cout << (int) byte[i][j] << " ";
			q1[pos1] = byte[i][j];
			pos1++;
		}
	}
	// ++ //

	cout << endl;


	// -- //
	for (int start_j = 0, lim_i = 0; lim_i < N; start_j++, lim_i++) {
		for (int i = 0, j = start_j; i <= lim_i; i++, j--) {
			// cout << (int) byte[i][j] << " ";;
			q2[pos2] = byte[i][j];
			pos2++;
		}
	}

	for (int start_i = 1, lim_j = 1; start_i < N; start_i++, lim_j++) {
		for (int i = start_i, j = M - 1; i < N; i++, j--) {
			// cout << (int) byte[i][j] << " ";
			q2[pos2] = byte[i][j];
			pos2++;
		}
	}
	// -- //

	cout << endl;


	// ~~ //
	int visited[N][M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
	int _i = (N / 2),
		_j = (M / 2);
	if(N%2==0) --_i;
	if(M%2==0) --_j;
	visited[_i][_j] = 1;
	q3[pos3] = byte[_i][_j];
	pos3++;
	while (true) {
		if (pos3 == N * M) break;
		do { // to right
			_j++;
			visited[_i][_j] = 1;
			// cout << (int) byte[_i][_j] << " ";
			q3[pos3] = byte[_i][_j];
			pos3++;


		} while (visited[_i + 1][_j] && (pos3 != N * M));
		if (pos3 == N * M) break;
		do { // down
			_i++;
			visited[_i][_j] = 1;
			// cout << (int) byte[_i][_j] << " ";
			q3[pos3] = byte[_i][_j];
			pos3++;

		} while (visited[_i][_j - 1] && (pos3 != N * M));
		if (pos3 == N * M) break;
		do { // left
			_j--;
			visited[_i][_j] = 1;
			// cout << (int) byte[_i][_j] << " ";
			q3[pos3] = byte[_i][_j];
			pos3++;
		} while (visited[_i - 1][_j] && (pos3 != N * M));
		if (pos3 == N * M) break;
		do { // up
			_i--;
			visited[_i][_j] = 1;
			// cout << (int) byte[_i][_j] << " ";
			q3[pos3] = byte[_i][_j];
			pos3++;

		} while (visited[_i][_j + 1] && (pos3 != N * M));
		if (pos3 == N * M) break;
	}
	// ~~ //

	for (int i = 0; i < N; i++) {
		for (int j =0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
	
	// @@ //
	_i = 0, _j = (M - 1);
	q4[pos4] = byte[_i][_j];
	visited[_i][_j] = 1;
	pos4++;
	
	while (true) {

		while (visited[_i][_j - 1] == 0 && (_j != 0)) { // left
			_j--;
			q4[pos4] = byte[_i][_j];
			visited[_i][_j] = 1;
			pos4++;
		}

		while (visited[_i + 1][_j] == 0 && (_i != (M - 1))) { // down
			_i++;
			q4[pos4] = byte[_i][_j];
			pos4++;
			visited[_i][_j] = 1;
			
		}

		while (visited[_i][_j + 1] == 0 && (_j != (M - 1))) { // right
			_j++;
			q4[pos4] = byte[_i][_j];
			pos4++;
			visited[_i][_j] = 1;
		}

		while (visited[_i - 1][_j] == 0 && (_i != 0)) { // up
			_i--;
			q4[pos4] = byte[_i][_j];
			pos4++;
			visited[_i][_j] = 1;
		}
		if (pos4 == N * M) break;
	}
	// @@ //

	for (int i = 0; i < M * N; i++) {
		cout << (int) q1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < M * N; i++) {
		cout << (int) q2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < M * N; i++) {
		cout << (int) q3[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < M * N; i++) {
		cout << (int) q4[i] << " ";
	}
	for (int i = 0; i < 200; i++) {
		delete byte[i];
	}
	delete byte;

	return 0;
}
