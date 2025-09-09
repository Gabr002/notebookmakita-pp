#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

long long vet[MAXN];
long long tree[4 * MAXN];


void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = vet[start];
        return;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    build(left_child, start, mid);
    build(right_child, mid + 1, end);

    tree[node] = tree[left_child] + tree[right_child];
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        tree[node] = val;
        vet[idx] = val;
        return;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    if (idx <= mid)
    {
        update(left_child, start, mid, idx, val);
    }
    else
    {
        update(right_child, mid + 1, end, idx, val);
    }

    tree[node] = tree[left_child] + tree[right_child];
}

long long query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
    {
        return 0;
    }

    if (l <= start && r >= end)
    {
        return tree[node];
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    long long p1 = query(left_child, start, mid, l, r);
    long long p2 = query(right_child, mid + 1, end, l, r);
    return p1 + p2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    build(0, 0, n - 1);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, v;
            cin >> idx >> v;
            update(0, 0, n - 1, idx, v);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            long long result = query(0, 0, n - 1, l, r - 1);
            cout << result << endl;
        }
    }

    return 0;
}
