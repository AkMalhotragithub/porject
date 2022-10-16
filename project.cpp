#include <iostream> 
using namespace std; 
class myclass 
{ 
int *rank, *parentvar; 
int n; 
public: 
myclass(int n) 
 { 
 rank = new int[n]; 
 parentvar = new int[n]; 
this->n = n; 
sets(); 
 } 
void sets() 
 { 
for (int i = 0; i < n; i++) 
 { 
parentvar[i] = i; 
 } 
 } 
int find(int x) 
 { 
if (parentvar[x] != x) 
 { 
parentvar[x] = find(parentvar[x]); 
 } 
return parentvar[x]; 
 }
void Union(int x, int y) 
 { 
int xset = find(x); 
int yset = find(y); 
if (xset == yset) 
return; 
if (rank[xset] < rank[yset]) 
 { 
parentvar[xset] = yset; 
 } 
else if (rank[xset] > rank[yset])  { 
parentvar[yset] = xset; 
 } 
else 
 { 
parentvar[yset] = xset; 
rank[xset] = rank[xset] + 1;  } 
 } 
}; 
int main() 
{ 
 myclass obj(6); 
obj.Union(0, 1); 
obj.Union(0, 3); 
obj.Union(1, 2); 
obj.Union(4, 5); 
if (obj.find(2) == obj.find(1))  { 
 cout << "yes" << endl; 
 } 
else 
 { 
 cout << "no" << endl; 
 } 
if (obj.find(0) == obj.find(1))  {
 cout << "yes" << endl; 
 } 
else 
 { 
 cout << "no" << endl; 
 } 
if (obj.find(4) == obj.find(1)) 
 { 
 cout << "yes" << endl; 
 } 
else 
 { 
 cout << "no" << endl; 
 } 
return 0; 
} 
