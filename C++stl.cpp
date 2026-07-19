What is STL?

STL (Standard Template Library) is a collection of pre-written, generic classes and functions that provide commonly used data structures and algorithms.

It consists of four major components:

STL
│
├── Containers
├── Iterators
├── Algorithms
└── Function Objects (Functors)
1. Containers

Containers store data.

A. Sequence Containers
vector

Dynamic array.

vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << v[1];

Common Functions

push_back()
pop_back()
size()
capacity()
clear()
empty()
front()
back()
begin()
end()
at()
resize()
swap()

Time Complexity

Access      O(1)
Insert End  O(1) amortized
Delete End  O(1)
Insert Middle O(n)
deque

Double ended queue.

deque<int> d;

d.push_front(10);
d.push_back(20);

d.pop_front();
d.pop_back();

Time Complexity

Insert Front O(1)
Insert Back  O(1)
Random Access O(1)
list

Doubly Linked List.

list<int> l;

l.push_back(10);
l.push_front(20);

l.remove(10);

Features

No Random Access

Fast insertion

Fast deletion
forward_list

Singly Linked List.

Only Forward Traversal
array

Fixed size array.

array<int,5> arr={1,2,3,4,5};

arr.size();
arr.front();
arr.back();
Container Adaptors
stack

LIFO

push()

pop()

top()

size()

empty()
stack<int> st;

st.push(10);
st.push(20);

cout<<st.top();
queue

FIFO

push()

pop()

front()

back()
priority_queue

Heap implementation.

Default

Max Heap
priority_queue<int> pq;

Min Heap

priority_queue<
int,
vector<int>,
greater<int>
> pq;
Associative Containers
set

Stores unique elements.

Automatically sorted.

set<int> s;

s.insert(10);
s.insert(20);
s.insert(20);

Output

10 20

Functions

insert()

erase()

find()

count()

lower_bound()

upper_bound()

Complexity

Insert O(log n)

Delete O(log n)

Search O(log n)
multiset

Allows duplicates.

multiset<int> ms;

ms.insert(10);
ms.insert(10);

Output

10 10
unordered_set

Uses Hash Table.

Average O(1)
Worst O(n)

No ordering.

map

Stores

key -> value

Keys are unique.

map<string,int> mp;

mp["Ram"]=100;

mp["Shyam"]=90;

Output

Ram 100
Shyam 90

Functions

insert()

erase()

find()

count()

at()

[]

Complexity

O(log n)
multimap

Duplicate keys allowed.

unordered_map

Hash Table.

Average

O(1)
Iterators

Pointer-like objects.

vector<int> v={1,2,3};

vector<int>::iterator it;

for(it=v.begin();it!=v.end();it++)
{
    cout<<*it;
}

Modern way

for(auto it=v.begin();it!=v.end();it++)

Range Loop

for(auto x:v)
{
    cout<<x;
}
Algorithms

Need

#include<algorithm>
sort()
sort(v.begin(),v.end());

Descending

sort(v.begin(),v.end(),greater<int>());
reverse()
reverse(v.begin(),v.end());
max()
max(a,b);
min()
min(a,b);
max_element()
*max_element(v.begin(),v.end());
min_element()
*min_element(v.begin(),v.end());
accumulate()
accumulate(v.begin(),v.end(),0);

Need

#include<numeric>
count()
count(v.begin(),v.end(),5);
find()
find(v.begin(),v.end(),10);
binary_search()
binary_search(v.begin(),v.end(),5);

Array must be sorted.

lower_bound()

First element

>= x
lower_bound(v.begin(),v.end(),5);
upper_bound()

First element

> x
next_permutation()
next_permutation(v.begin(),v.end());
prev_permutation()
prev_permutation(v.begin(),v.end());
unique()

Removes consecutive duplicates.

sort(v.begin(),v.end());

v.erase(
unique(v.begin(),v.end()),
v.end());
rotate()
rotate(v.begin(),
v.begin()+2,
v.end());
nth_element()
nth_element(v.begin(),
v.begin()+k,
v.end());

Useful for kth smallest.

Function Objects

Example

greater<int>

less<int>

Used in

sort(v.begin(),v.end(),greater<int>());
Lambda Function
sort(v.begin(),v.end(),
[](int a,int b)
{
    return a>b;
});
Pair
pair<int,string> p;

p.first=1;

p.second="Anup";
Vector of Pair
vector<pair<int,int>> vp;

vp.push_back({1,2});
Pair of Pair
pair<int,pair<int,int>> p;
Useful Macros
begin()

end()

rbegin()

rend()
Common Time Complexities
Container	Insert	Delete	Search
vector	O(1) end	O(1) end	O(n)
deque	O(1)	O(1)	O(n)
list	O(1)	O(1)	O(n)
stack	O(1)	O(1)	—
queue	O(1)	O(1)	—
priority_queue	O(log n)	O(log n)	O(1) top
set	O(log n)	O(log n)	O(log n)
multiset	O(log n)	O(log n)	O(log n)
unordered_set	O(1)*	O(1)*	O(1)*
map	O(log n)	O(log n)	O(log n)
unordered_map	O(1)*	O(1)*	O(1)*
