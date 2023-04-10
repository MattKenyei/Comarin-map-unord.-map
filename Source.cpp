#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
void Insert(map<unsigned long long, unsigned long long>& m, unordered_map<unsigned long long, unsigned long long> &u, unsigned long long n)
{
	unsigned long long* a;
	a = new unsigned long long[n];
	for (unsigned long long i = 0; i < n; i++)
		a[i] = rand() % 10000;
	auto start = chrono::high_resolution_clock::now();
	for (unsigned long long i = 0; i < n; i++)
		m.insert({i, a[i]});
	auto end = chrono::high_resolution_clock::now();
	cout << "map insert() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	start = chrono::high_resolution_clock::now();
	for (unsigned long long i = 0; i < n; i++)
		u.insert({ i, a[i]});
	end = chrono::high_resolution_clock::now();
	cout << "unordered_map insert() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	delete[] a;
}
void Emplace(map<unsigned long long, unsigned long long>& m, unordered_map<unsigned long long, unsigned long long>& u, unsigned long long n)
{
	auto start = chrono::high_resolution_clock::now();
	for (unsigned long long i = 0; i < n; i++)
		m.emplace(m[i], 111);
	auto end = chrono::high_resolution_clock::now();
	cout << "map emplace() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	start = chrono::high_resolution_clock::now();
	for (unsigned long long i = 0; i < n; i++)
		u.emplace(u[i], 111);
	end = chrono::high_resolution_clock::now();
	cout << "unordered_map emplace() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
}
void Clear(map<unsigned long long, unsigned long long>& m, unordered_map<unsigned long long, unsigned long long>& u)
{
	auto start = chrono::high_resolution_clock::now();
	m.clear();
	auto end = chrono::high_resolution_clock::now();
	cout << "map clear() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	start = chrono::high_resolution_clock::now();
	u.clear();
	end = chrono::high_resolution_clock::now();
	cout << "unordered_map clear() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
}
void Erase(map<unsigned long long, unsigned long long>& m, unordered_map<unsigned long long, unsigned long long>& u, unsigned long long n)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
		m.erase(m[i]);
	auto end = chrono::high_resolution_clock::now();
	cout << "map erase() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
		u.erase(u[i]);
	end = chrono::high_resolution_clock::now();
	cout << "unordered_map erase() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
}
void EH(map<unsigned long long, unsigned long long>& m, unordered_map<unsigned long long, unsigned long long>& u, unsigned long long n)
{
	auto it = m.end();
	auto start = chrono::high_resolution_clock::now();
	for (unsigned long long i = 0; i < n; i++)
		m.emplace_hint(it, 12, m[i]);
	auto end = chrono::high_resolution_clock::now();
	cout << "map emplace_hint() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	auto it2 = u.end();
	start = chrono::high_resolution_clock::now();
	for (unsigned long long i = 0; i < n; i++)
		u.emplace_hint(it2, 12, u[i]);
	end = chrono::high_resolution_clock::now();
	cout << "unordered_map emplace_hint() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
}
void Find(map<unsigned long long, unsigned long long>& m, unordered_map<unsigned long long, unsigned long long>& u, unsigned long long n)
{
	auto start = chrono::high_resolution_clock::now();
	int s;
	for (int i = 0; i < 1000000; i++)
	{
		s = rand() * rand() * rand() % int(1.5*n);
		m.find(s);
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "map find() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		s = rand() * rand() * rand() % int(1.5*n);
		u.find(s);
	}
	end = chrono::high_resolution_clock::now();
	cout << "unordered_map find() time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << endl;
}
int main()
{
	srand(time(NULL));
	map<unsigned long long, unsigned long long> Map;
	unordered_map<unsigned long long, unsigned long long> unMap;
	unsigned long long n;
	cin >> n;
	Insert(Map, unMap, n);
	Find(Map, unMap, n);
	Emplace(Map, unMap, n);
	EH(Map, unMap, n);
	Erase(Map, unMap, n);
	Insert(Map, unMap, n);
	Clear(Map, unMap);
	return 0;
}