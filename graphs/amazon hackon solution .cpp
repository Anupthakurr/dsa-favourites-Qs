



qs --> 1 solution

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto &it : edges)
  {
    cin >> it.first >> it.second;
  }
  int k;
  cin >> k;
  vector<int> v(k);
  for (auto &it : v)
  {
    cin >> it;
  }
  vector<vector<int>> adj(n);
  for (auto &it : edges)
  {
    adj[it.first - 1].push_back(it.second - 1);
  }

  int ans = 0;
  bool flag = true;

  vector<int> dist(n, 1e7);
  dist[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});
  while (!pq.empty())
  {
    auto temp = pq.top();
    pq.pop();
    int node = temp.second;
    int d = temp.first;
    for (auto it : adj[node])
    {
      if (dist[it] > d + 1)
      {
        dist[it] = d + 1;
        pq.push({d + 1, it});
      }
    }
  }
  for (int j = 0; j < k; j++)
  {
    ans += dist[v[j] - 1];
  }

  //    now shortest dist from mountain to  city 1

  for (int m = 0; m < k; m++)
  {
    vector<int> dist(n, 1e7);
    dist[v[m] - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, v[m] - 1});
    while (!pq.empty())
    {
      auto temp = pq.top();
      pq.pop();
      int node = temp.second;
      int d = temp.first;
      for (auto it : adj[node])
      {
        if (dist[it] > d + 1)
        {
          dist[it] = d + 1;
          pq.push({d + 1, it});
        }
      }
    }
    ans += dist[0];
    if (dist[0] == 1e7)
    {
      flag = false;
    }
  }
  for (int l = 0; l < k; l++)
  {
    if (dist[v[l] - 1] == 1e7)
    {
      flag = false;
    }
  }
  if (flag == false)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}



------------------------------------------*------*---------------------------------------------------------------------->
qs 2 -----> solution


 #include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t; // number of test cases

  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int b_val;
    cin >> b_val;
    set<int> b = {b_val};

    sort(a.begin(), a.end());

    long long ans = 0;

    for (int val : a)
    {
      if (b.count(val - 1) && b.count(1))
      {
        ans += 3 * (val - 1);
      }
      else if (b.count(val - 1) || b.count(1))
      {
        if (b.count(val - 1))
        {
          b.insert(1);
        }
        else
        {
          b.insert(val - 1);
        }
        ans += 2 * (val - 1);
      }
      else
      {
        b.insert(1);
        b.insert(val - 1);
        ans += (val - 1);
      }
    }

    cout << ans << endl;
  }

  return 0;
}

