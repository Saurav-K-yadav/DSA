#include <bits/stdc++.h>
using namespace std;

void pairs()
{
    pair<int, int> a = {1, 2};
    cout << "First part : " << a.first << "\nSecond part : " << a.second << endl;

    pair<int, pair<int, int>> b = {1, {3, 4}};
    cout << "First : " << b.first << endl
         << "second :" << b.second.first << " and " << b.second.second << endl;

    pair<int, int> c[2] = {{0, 0}, {1, 1}};
    cout << "First sub-array : " << c[0].first << "\nSecond part : " << c[0].second << endl;
    cout << "second sub-array : " << c[1].first << "\nSecond part : " << c[1].second << endl;
}

void vectors()
{
    vector<int> a;
    a.push_back(1);
    a.emplace_back(2); // O(1) "FASTER"
    vector<pair<int, int>> b;
    b.emplace_back(0, 1);

    vector<int> c(5, 0); // size 5 intialize with 0
    vector<int> d(c);    // Copy c into d

    // Iterators
    vector<int> e = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator i = c.begin();
    // cout << *i;
    // c.end() -->points after the last element
    vector<int>::iterator j = e.end();
    // cout << *(j-1);

    // cout << e.back(); // Prints last element
    // cout << e.at(2);//Element at position 2
    for (vector<int>::iterator it = e.begin(); it < e.end(); it++)
    {
        // cout << *(it);
    }
    // To erase
    //  e.erase(e.begin()+3);//Delete the forth element

    e.erase(e.begin() + 2, e.begin() + 5); // Delete the third to Fifth(N-1) element
    e.insert(e.begin() + 2, 2);            // Insert 2 at third palace
    e.insert(e.begin() + 3, 2, 3);         // Insert 2 threes from fourth position

    vector<int> f = {1, 2};
    // Insert a pat of an vectorn in anoter vector
    f.insert(f.end(), e.begin(), e.end());

    // cout << "The size of vector is " << e.size()<<endl;
    // After poping the last element
    e.pop_back();
    // Simpler Method to iterate
    for (auto itr = e.begin(); itr < e.end(); itr++)
    {
        cout << *itr;
    }
    cout << endl;
    vector<int> g = {1};
    cout << "Is vector g empty ? " << g.empty() << endl;
    // clearing the vector g
    g.clear();
    cout << "Is vector g empty ? " << g.empty();
}

void lists()
{
    list<int> a;
    a = {1, 2, 3, 4, 5};
    a.push_front(0); // Faster than that of vectors as in vectors insert is used
    a.emplace_front(0);
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        cout << *itr;
    }
    cout << endl;
}

void deques()
{
    // Like the list
}

void stacks()
{
    // ALL operations in O(1)
    stack<int> a;
    a.push(1);
    cout << a.top();
    a.emplace(0);
    a.pop();
    cout << a.size();
}

void queues()
{

    queue<int> a;
    a.push(0);
    // cout << a.back();
    a.emplace(1);
    // cout << a.front() << a.back();
    a.pop(); // Delete first element

    cout << a.front();
}

void pqueue()
{
    priority_queue<char> a;
    // Maximum stays at the top
    // Inside a tree data structure is maintained
    // Max_heap
    a.push('b');
    a.push('c');
    a.push('z');
    a.push('e');
    a.push('a');
    // cout << a.top();
    a.pop();
    // cout << a.top();

    // Priority queue with minimum at top
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> b;
    b.emplace(3);
    b.emplace(0);
    b.emplace(10);
    cout << b.top();
}

void sets()
{
    // LOG(N)
    // Unique and Sorted order
    set<int> a;
    a.insert(5);
    a.insert(4);
    a.insert(1);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    auto itr = a.find(2);
    // cout << *(itr);
    a.erase(2);
    // elememt not present return set.end()
    auto i = a.find(2);
    // cout << *(i);
    // As unique only 0 or 1 count is present
    // cout << a.count(1);

    multiset<int> b = {4, 4, 4, 1, 2, 4, 6, 8, 9};
    cout << b.count(4);
    // b.erase(4);
    // cout << b.count(4);
    auto j = b.find(4);
    b.erase(j);
    cout << b.count(4);
}

void maps()
{
    // Sorted order key-value pair
    map<char, int> a;
    a['a'] = 2;
    a.insert({'z', 10});
    a.insert({'b', 2});
    for (auto itr : a)
    {
        cout << itr.first << itr.second;
    }
}

// User defined comparision function
// lets take two pairs as input as we are sorting pairs
bool comp(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.second < p2.second)
    {
        // If second element is less than first then placement is true don't sort
        return true;
    }
    if (p1.second > p2.second)
    {
        // If second element is greater than first then placement is false ,sort
        return false;
    }
    // If they are equal sorted on basis of first part
    if (p1.first > p2.first)
    {
        return false;
        // Placement is false-->sort
    }
return true;
}

void sorts()
{
    vector<int> a = {2, 9, 3, 5, 0, 3, 5, 1, 4, 1};
    // To sort the vector
    sort(a.begin(), a.end());
    // To sort in decreasing order
    sort(a.begin(), a.end(), greater<int>()); // O(NlogN)
    // Sort only a part of vector
    sort(a.begin() + 3, a.end());
    for (auto itr : a)
    {
        // cout << itr << " ";
    }
    cout << endl;

    pair<int, int> b[] = {{1,3}, {2,2}, {1,1}, {3,1}};
    // Sort the pair based on second element
    // If the second element is same then sort based on first element
    // using user defined comparision for the same
    sort(b, b+4, comp);
    for (auto it : b)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
}

int main()
{
    //  pairs();
    // vectors();
    // lists();
    // deques();
    // stacks();
    // queues();
    // pqueue();
    // sets();
    // maps();
    sorts();
    return 0;
}