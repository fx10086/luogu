#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n;                      // 节点数
int fa[MAXN];           // 父节点
int depth[MAXN];            // 节点深度
int head[MAXN];             // 邻接表头
int edgeCnt = 0;            // 边计数器
int maxDepth = 0;           // 树的最大深度
int width = 0;              // 树的最大宽度（某一层最多的节点数）
int levelCount[MAXN];       // 每层的节点个数

struct Edge {
    int to, next;
} edges[MAXN * 2];          

void addEdge(int u, int v) {
    edges[++edgeCnt].to = v;
    edges[edgeCnt].next = head[u];
    head[u] = edgeCnt;
}

void dfs(int u, int father) {
    fa[u] = father;
    depth[u] = depth[father] + 1;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v != father) {
            dfs(v, u);
        }
    }
}

int getLCA(int x, int y) {
    while (x != y) {
        if (depth[x] >= depth[y])
            x = fa[x];
        else
            y = fa[y];
    }
    return x;
}

int getDistance(int x, int y) {
    int lca = getLCA(x, y);
    return (depth[x] - depth[lca]) * 2 + (depth[y] - depth[lca]);
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }

    dfs(1, 0); 

    for (int i = 1; i <= n; i++) {
        maxDepth = max(maxDepth, depth[i]);
        levelCount[depth[i]]++;
    }

    for (int i = 1; i <= maxDepth; i++) {
        width = max(width, levelCount[i]);
    }

    int u, v;
    cin >> u >> v;
    cout << maxDepth << endl;
    cout << width << endl;
    cout << getDistance(u, v) << endl;

    return 0;
}