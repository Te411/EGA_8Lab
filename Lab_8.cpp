﻿#include <iostream>
#include <locale.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 5; // количество предметов
int main() {
	setlocale(LC_ALL, "rus");
	vector <int> S(N, 0); // набор предметов
	vector <int> C(N); // ценность предмета
	vector <int> W(N); // вес предметов
	vector <int> Y(N); // Удельная ценность
	int Q = 0; // суммарная ценность всех предметов в ранце
	int sumW = 0; // суммарный вес 
	int Wmax = 0; // весовое ограничение
	int max = -1;
	int index = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(50, 100);
	Wmax = dis(gen);
	uniform_int_distribution<> diss(2, 30);
	for (int i = 0; i < N; i++) {
		W[i] = diss(gen);
	}
	uniform_int_distribution<> disss(10, 50);
	for (int i = 0; i < N; i++) {
		C[i] = disss(gen);
	}
	for (int i = 0; i < N; i++) {
		Y[i] = round(C[i] / W[i] * 100) / 100;
	}
	cout << "Данные задачи: " << endl;
	cout << "Предмет       Цена       Вес      Удельная ценность" << endl;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << setw(9) << "|" << setw(6) << C[i] << setw(5) << "|" << setw(6) << W[i] << setw(4) << "|" << setw(11) << Y[i] << endl;
	}
	cout << "Максимальный возможный вес ранца: " << Wmax << endl << endl;
	for (int i = 0; i < N; i++) {
		cout << "Шаг " << i + 1 << endl;
		max = -1;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == 0) {
				if (Y[j] > max) {
					max = Y[j];
					index = j;
				}
			}
		}
		if (sumW + W[index] < Wmax) {
			cout << "Текущая цена ранца: " << Q << endl;
			cout << "Текущий вес ранца: " << sumW << endl;
			Q += C[index];
			sumW += W[index];
			S[index] = 1;
		}
		else {
			cout << "Рюкзак заполнен. Предметы больше не влезут" << endl;
			break;
		}
		cout << "Выбран предмет " << index + 1 << " с ценой " << C[index] << " и весом " << W[index] << " и удельной ценностью " << Y[index] << endl;
		cout << "Рюкзак заполнен на " << sumW << "/" << Wmax << endl;
	}
	cout << endl;
	cout << "Итог" << endl;
	cout << "Были выбраны следующие предметы: ";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 1) {
			cout << " " << i + 1;
		}
	}
	cout << endl;
	cout << "Итоговая цена: " << Q << endl;
	cout << "Итоговый вес ранца: " << sumW << endl;
	return 0;
}
