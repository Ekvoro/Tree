/** @file tree.cpp */
#include <iostream>
using namespace std;

//! Funkcija obhoda dereva v pryamom porjadke
/**
@param node - koren'
@param n - kolichetvo uzlov
@param *pTree - ukazatel' na nachalo massiva dereva
**/

void pre_order(int node, int n, int *pTree)

{
	cout << node + 1 << " "; /// Pechat' uzla

	int *a = new int[n]; /// Sozdaem dop. massiv 
	for (int i = 0; i < n; i++) 
		a[i] = 0; ///  Zapolnyaem 0

	for (int i = 0; i< n; i++)
		if (pTree[i] == node + 1) 
			a[i] = pTree[i]; /// Esly est' potomki u elementa, zapisyvaem ih v "a"

	for (int i = 0; i < n; i++)
		if (a[i]) pre_order(i, n, pTree); /// Esly kakoi-libo element v "a" ne raven 0, 
		                                           ///to vyzyvaem "pre_order", podavaya koren' = nomery nenylevogo elementa "a"

	delete[]a;
}

//! Funkcija obhoda dereva v obratnom porjadke
/**
@param node - koren'
@param n - kolichetvo uzlov
@param *pTree - ukazatel' na nachalo massiva dereva
**/
void post_order(int node, int n, int *pTree)
{
	int *a = new int[n]; /// Takoy je algoritm, no raspechatka proishodit, esli massiv "a" tojdestvennen "0"

	for (int i = 0; i < n; i++) 
		a[i] = 0;

	for (int i = 0; i < n; i++)
		if (pTree[i] == node + 1)
			a[i] = pTree[i];

	for (int i = 0; i < n; i++)
		if (a[i]) post_order(i, n, pTree);

	cout << node + 1 << " ";

	delete[]a;
}

//! Funkcija obhoda dereva v simmetrichnom porjadke
/**
@param node - koren'
@param n - kolichetvo uzlov
@param *pTree - ukazatel' na nachalo massiva dereva
**/

void in_order(int node, int n, int *pTree)
{
	int *a = new int[n]; /// V nachale takoy je algoritm
	for (int i = 0; i < n; i++) 
		a[i] = 0;

	for (int i = 0; i < n; i++)
		if (pTree[i] == node + 1)
			a[i] = pTree[i];

	for (int i = 0; i < n; i++)
		if (a[i]) in_order(i, n, pTree); 

	int k = 0;
	for (int i = 0; i < n; i++)
		if (pTree[i] == node + 1) k++; /// Esly u elementa net potomkov, pechataem ego
	
	if (k == 0) 
		cout << node + 1 << " ";

	if ((pTree[node - 1] != pTree[node]) && (pTree[node]))
		cout << pTree[node] << " ";

	delete[]a;
}


//! Glavnaja funkcija
int main(void)
{
	int n;
	cout << "Vvedite kolichestvo uzlov dereva: "; cin >> n; /// Vvod kolichestva uzlov
	int *Tree = new int[n];
	cout << "Vvedite uzly: "; /// Vvod uzlov
	for (int i = 0; i < n; i++)
		cin >> Tree[i];
	cout << "Prjamoj obhod dereva: "; /// Vyzov funkcij obhoda dereva:
	pre_order(0, n, Tree); /// - Prjamoj obhod
	cout << "\nObratnyj obhod dereva: ";
	post_order(0, n, Tree); /// - Obratnyj obhod
	cout << "\nSimmetrichnyj obhod dereva: ";
	in_order(0, n, Tree); /// - Simmetrichnyj obhod
	cout << endl;

	delete[]Tree;
	return 0;
}