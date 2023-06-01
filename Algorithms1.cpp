#include <iostream>
using namespace std;
int tab = 0;
int kolychestvo = 0;	
struct Vetka
{
	int Data;
	Vetka* LeftVetka;
	Vetka* RightVetka;
};
void Add(int aData, Vetka*& aVetka)
{
	if (!aVetka)
	{ 
		aVetka = new Vetka;
		aVetka->Data = aData;
		aVetka->LeftVetka = 0;
		aVetka->RightVetka = 0;
		return;
	}
	else
		if (aVetka->Data > aData)
		{ 
			Add(aData, aVetka->LeftVetka);
		}
		else
		{
			Add(aData, aVetka->RightVetka);
		};
}
void print(Vetka* aVetka)
{
	if (!aVetka) return;
	tab += 5;
	

	print(aVetka->LeftVetka);

	for (int i = 0; i < tab; i++) cout << " ";
	cout << aVetka->Data << endl;


	print(aVetka->RightVetka);

	tab -= 5;
	return;
}
void pr_obh(Vetka*& aVetka)
{
	if (NULL == aVetka)    return;

	cout << aVetka->Data << endl;
	pr_obh(aVetka->LeftVetka);  
	pr_obh(aVetka->RightVetka);
}
int kol_ch(Vetka*& aVetka)
{
	if (NULL == aVetka)    return 0;

	if (aVetka->Data % 2 == 0)
	{
		kolychestvo++;
	}
	kol_ch(aVetka->LeftVetka);  
	kol_ch(aVetka->RightVetka);
	return kolychestvo;
}
int summ_k(Vetka*& aVetka, int k) {
	int sum = 0;
	if ((aVetka != NULL) && (k > 0)) {
		sum += summ_k(aVetka->LeftVetka, k - 1);
		sum += aVetka->Data;
		sum += summ_k(aVetka->RightVetka, k - 1);
	}
	return sum;
}
void add_elem(int aData, Vetka*& aVetka)
{
	if (!aVetka)
	{
		aVetka = new Vetka;
		aVetka->Data = aData;
		aVetka->LeftVetka = 0;
		aVetka->RightVetka = 0;
		return;
	}
	else
	{
		if (aData < aVetka->Data) {
			add_elem(aData, aVetka->LeftVetka);
		}
		else if (aData > aVetka->Data) {
			add_elem(aData, aVetka->RightVetka);
		}
	}
}
void is_Empty(Vetka*& aVetka)
{
	if (!aVetka)
	{
		cout << "Дерево пустое...";
	}
	else
	{
		cout << "Дерево не пустое...";
	}
}
void FreeTree(Vetka* aVetka)
{
	if (!aVetka) return;
	FreeTree(aVetka->LeftVetka);
	FreeTree(aVetka->RightVetka);
	delete aVetka;
	return;
}
Vetka* del_elem(Vetka*& aVetka, int aData) {
	if (aVetka == NULL)
		return aVetka;

	if (aData == aVetka->Data) {

		Vetka* tmp;
		if (aVetka->RightVetka == NULL)
			tmp = aVetka->LeftVetka;
		else {

			Vetka* ptr = aVetka->RightVetka;
			if (ptr->LeftVetka == NULL) {
				ptr->LeftVetka = aVetka->LeftVetka;
				tmp = ptr;
			}
			else {

				Vetka* pmin = ptr->LeftVetka;
				while (pmin->LeftVetka != NULL) {
					ptr = pmin;
					pmin = ptr->LeftVetka;
				}
				ptr->LeftVetka = pmin->RightVetka;
				pmin->LeftVetka = aVetka->LeftVetka;
				pmin->RightVetka = aVetka->RightVetka;
				tmp = pmin;
			}
		}

		delete aVetka;
		return tmp;
	}
	else if (aData < aVetka->Data)
		aVetka->LeftVetka = del_elem(aVetka->LeftVetka, aData);
	else
		aVetka->RightVetka = del_elem(aVetka->RightVetka, aData);
	return aVetka;
}
int find(Vetka* r, int d)
{
	if (r == NULL)
	{
		return NULL;
	}
	if (r->Data == d)
	{
		return d;
	}

	if (d <= r->Data)
	{
		if (r->LeftVetka != NULL)
			return find(r->LeftVetka, d);
		else
		{
			return NULL;
		}
	}
	else
	{
		if (r->RightVetka)
			return find(r->RightVetka, d);
		else
		{
			return NULL;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	Vetka* Root = 0;
	int kolvo;
	int EL;
	int k;
	Vetka* r;
	int d;
	cout << "Введите кол-во элементов для будущего дерева: ";
	cin >> kolvo;
	cout << endl;
	cout << "Проверим дерево на пустоту до его заполнения: " << endl;
	is_Empty(Root);
	cout << endl;
	for (int i = 0; i < kolvo; i++)
	{
		Add(rand() % 100, Root);
	}
	cout << "Проверим дерево на пустоту после его заполнения: " << endl;
	is_Empty(Root);
	cout << endl;
	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;
	cout << "Прямой обход бинарного дерева: " << endl;
	pr_obh(Root);
	cout << endl;
	cout << "Добавим новый элемент в бинарное дерево:" << endl;
	cout << "Введите новый элемент: ";
	cin >> EL;
	add_elem(EL, Root);
	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;
	cout << "Удалим элемент из бинарного дерева:" << endl;
	cout << "Введите элемент: ";
	cin >> EL;
	del_elem(Root, EL);
	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;
	cout << "Посчитаем кол-во четных элементов в дереве: ";
	cout << kol_ch(Root) << endl;
	cout << "Посчитаем сумму элементов в дереве на уровне ";
	cin >> k;
	cout << summ_k(Root, k) << endl;
	cout << "Поиск элемента: ";
	cin >> d;
	int f;
	f = find(Root, d);
	cout << f << endl;
	FreeTree(Root);
	cout << "Динамическая память очищена..." << endl;
	return 0;
}