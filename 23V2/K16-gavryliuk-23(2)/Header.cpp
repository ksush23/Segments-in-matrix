#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Header.h"

using namespace std;

Matrix::Matrix() : n(0), m(0)
{
}
Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
		delete[]p[i];
	delete[]p;
}
bool Matrix::get_matrix(const int N)
{
	char filename[30];

	cout << "Enter filename you want to have values from: " << endl;
	cin >> filename;

	ifstream fin(filename);

	if (!fin)
	{
		cout << "Problems with file!" << endl;

		return 0;
	}
	else
	{
		if (fin >> n >> m)
		{

			if (n != m || n > N || n < 3)
			{
				cout << "Incorrect range of matrix" << endl;
				return 0;
			}

			p = new int *[n];
			for (int i = 0; i < n; i++)
				p[i] = new int[m];

			int i = 0, j = 0;

			while (fin >> p[i][j])
			{
				if (fin.fail() && !fin.eof())
				{
					cout << "Wrong input! " << endl;
					fin.close();
					return 0;
				}
				j++;
				if (j == n)
				{
					j = 0;
					i++;
				}
			}

			fin.close();

			if (i != n && j != n)
			{
				cout << "<<<K16-gavryliuk-23/" << filename << ": INPUT ERROR>>> " << endl;
				return 0;
			}

			return 1;
		}
		else
		{
			cout << "File is empty! " << endl;
			return 0;
		}
	}
}
void Matrix::max ()
{
	int r = n - 1, s = 0;
	int j = 0, newj = 0;
	m--;

	for (int i = n - 1; i >= (n / 2); i--)
	{
		while (j <= m)
		{
			if ((abs(p[i][j]) > abs(p[r][s])) || (abs(p[i][j]) == abs(p[r][s]) && i < r))
			{
				r = i;
				s = j;
			}
			j++;
		}
		m--; newj++; 
		j = newj;
	}
	m = n;
	change(r, s);
}
void Matrix::change(int r, int s)
{
	n--;
	m--;

	int **newp = new int *[n];
	for (int i = 0; i < n; i++)
		newp[i] = new int[m];

	for (int i = 0, k = 0; k < n + 1; i++, k++)
	{
		if (i == r)
			k++;
		if (k != n + 1)
			for (int j = 0, l = 0; l < m + 1; j++, l++)
			{
				if (j == s)
					l++;
				if (l != m + 1)
					newp[i][j] = p[k][l];
			}
	}

	for (int i = 0; i < n; i++)
		delete[]p[i];
	delete[]p;

	p = newp;
}
void Matrix::out_matrix()
{
	char filename[30];

	cout << "Enter filename you want to have results in: " << endl;
	cin >> filename;

	ofstream fout(filename);

	fout << n << ' ' << m << endl;
	fout << right;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fout << setw(15) << setfill(' ') << p[i][j];
		fout << endl;
	}
}