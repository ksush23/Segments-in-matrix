#pragma once

class Matrix
{
private:
	int n;
	int m;
	int **p;
public:
	Matrix();
	~Matrix();
	bool get_matrix(const int N);
	void out_matrix();
	void max();
	void change(int r, int s);
};