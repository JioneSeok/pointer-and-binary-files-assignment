#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
//Sprint 1
	const float pi = 3.141592;
	char header[12];
	float dt;
	int* n;
	float* f; //frequency
	short* a; //amplitude
	short* p; //phasor

	n = (int*)header;
	*n = 150;
	f = (float*)(header + 4);
	*f = 1000;
	a = (short*)(header + 8);
	*a = 10000;
	p = (short*)(header + 10);
	*p = 12;
	dt = 1. / f[0] / 20.0;

	float* data1;
	data1 = new float[*n];
	float* data2;
	data2 = new float[*n];
	float* data3;
	data3 = new float[*n];

	for (int i = 0; i < n[0]; i++) {
		data1[i] = (float)(a[0] * sin(2.0 * pi * f[0] * i * dt + p[0]));
	}
	ofstream file1;
	file1.open("a.dat", ios::binary | ios::out);
	if (!file1) {
		cout << "File not found" << endl;
		return 1;
	}
	file1.write(header, 12 * sizeof(char));
	file1.write((char*)data1, sizeof(short) * n[0]);
	file1.close();

//Sprint2
	*f = 700.0; //frequency is changed in data2
	for (int i = 0; i < n[0]; i++) {
		data2[i] = (float)(a[0] * sin(2.0 * pi * f[0] * i * dt + p[0]));
	}
	ofstream file2;
	file2.open("b.dat", ios::binary | ios::out);
	if (!file2) {
		cout << "File not found" << endl;
		return 2;
	}
	file2.write(header, 12 * sizeof(char));
	file2.write((char*)data2, sizeof(short) * n[0]);
	file2.close();

	*a = 5000; //amplitude is changed in data3
	for (int i = 0; i < n[0]; i++) {
		data3[i] = (float)(a[0] * sin(2.0 * pi * f[0] * i * dt + p[0]));
	}
	ofstream file3;
	file2.open("d.dat", ios::binary | ios::out);
	if (!file3) {
		cout << "File not found" << endl;
		return 3;
	}
	file2.write(header, 12 * sizeof(char));
	file2.write((char*)data3, sizeof(short) * n[0]);
	file2.close();


//File check 1
	/*
	ifstream outfile1;
	outfile1.open("a.dat", ios::binary | ios::in);
	if (!outfile1) {
		return 5;
	}
	outfile1.read(header, 12 * sizeof(char));
	cout << "a.dat의 t에서의 sin값: " << endl;
	for (int i = 0; i < n[0]; i++) {
		cout << i << "번째: " << i * dt << " | " << data1[i] << endl;
	}
	cout << endl << endl << endl;
	outfile1.close();
	*/

//File check 2
	/*
	ifstream outfile2;
	outfile2.open("b.dat", ios::binary | ios::in);
	if (!outfile2) {
		return 6;
	}
	outfile2.read(header, 12 * sizeof(char));
	cout << "b.dat의 t에서의 sin값: " << endl;
	for (int i = 0; i < n[0]; i++) {
		cout << i << "번째: " << i * dt << " | " << data2[i] << endl;
	}
	cout << endl << endl << endl;
	outfile2.close();
	*/

//File check 3
	/*
	ifstream outfile3;
	outfile3.open("d.dat", ios::binary | ios::in);
	if (!outfile3) {
		return 7;
	}
	outfile3.read(header, 12 * sizeof(char));
	cout << "d.dat의 t에서의 sin값: " << endl;
	for (int i = 0; i < n[0]; i++) {
		cout << i << "번째: " << i * dt << " | " << data2[i] << endl;
	}
	cout << endl << endl << endl;
	outfile3.close();
	*/


//Sprint 4
	ofstream finalfile("c.txt");
	if (!finalfile) {
		cout << "File not found" << endl;
		return 9;
	}
	for (int i = 0; i < n[0]; i++) {
		finalfile << i * dt << " " << data1[i] << " " << data2[i] << " " << data3[i] << endl;
	}
	finalfile.close();

	return 0;

}