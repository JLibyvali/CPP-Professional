//
// Created by jlibyvali on 24-4-7.
//
#include<bits/stdc++.h>

using namespace std;

// forward chain star
struct edge {
    int v;
    int next;
} e[100010];

int HEAD[100010], len ;

void insert(int u, int v) {   // use for tree, 'u' is 'v' father node.
    e[len].v = v;
    e[len].next = HEAD[u];
    HEAD[u] = len;

    len++;
}

// question
int n, f[100010][2], u, v;  // f[i][2]: storage one Tree happiness-value base on root 'i' , [2]: 0 wasn't get in, 1 was;
bool vis[100010], is_leave[100010];

void calcu(int node) {

    vis[node] = true;

    for (int i = HEAD[node]; ~i; i = e[i].next)   // traverse all sub node
    {
        if (vis[ e[i].v ]) continue;

        calcu(e[i].v);

        f[node][0] += max(f[e[i].v][0], f[e[i].v][1]);   // When return , calculate root node's value
        f[node][1] += f[e[i].v][0];
    }

    return;
}

int main() {

    ios::sync_with_stdio, cin.tie(0), cout.tie(0);

    memset(HEAD, -1, sizeof(HEAD));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i][1];
    }

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        insert(v, u);
        is_leave[u] = true;
    }


    for (int i = 1; i <= n; i++) {
        if (!is_leave[i]) {
            calcu(i);
            cout << max(f[i][0], f[i][1]);
        }
    }

    return 0;
}
