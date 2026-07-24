#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 300005;

// Precomputed factorials for permutation counts
long long fact[MAXN];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// Dynamic Segment Tree Node
struct Node {
    int ls, rs;
    long long sum;
    long long lazy;
    Node() : ls(0), rs(0), sum(0), lazy(1) {}
};

vector<Node> tree;

// Allocate a new node from the pool
int new_node() {
    tree.push_back(Node());
    return (int)tree.size() - 1;
}

// Apply scalar multiplication to a segment tree node
void apply(int u, long long val) {
    if (!u) return;
    tree[u].sum = (tree[u].sum * val) % MOD;
    tree[u].lazy = (tree[u].lazy * val) % MOD;
}

// Push lazy multiplication tag down to children
void push(int u) {
    if (tree[u].lazy != 1) {
        if (tree[u].ls) apply(tree[u].ls, tree[u].lazy);
        if (tree[u].rs) apply(tree[u].rs, tree[u].lazy);
        tree[u].lazy = 1;
    }
}

// Point insertion: add 'val' at depth 'pos'
int insert(int u, int l, int r, int pos, long long val) {
    if (!u) u = new_node();
    if (l == r) {
        tree[u].sum = (tree[u].sum + val) % MOD;
        return u;
    }
    push(u);
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        int next_ls = insert(tree[u].ls, l, mid, pos, val);
        tree[u].ls = next_ls;
    } else {
        int next_rs = insert(tree[u].rs, mid + 1, r, pos, val);
        tree[u].rs = next_rs;
    }
    tree[u].sum = (tree[tree[u].ls].sum + tree[tree[u].rs].sum) % MOD;
    return u;
}

// Range sum query for depths in [ql, qr]
long long query(int u, int l, int r, int ql, int qr) {
    if (!u || ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[u].sum;
    push(u);
    int mid = (l + r) >> 1;
    return (query(tree[u].ls, l, mid, ql, qr) + query(tree[u].rs, mid + 1, r, ql, qr)) % MOD;
}

// Merge segment tree v into segment tree u
int merge(int u, int v) {
    if (!u || !v) return u ? u : v;
    if (!tree[u].ls && !tree[u].rs && !tree[v].ls && !tree[v].rs) {
        tree[u].sum = (tree[u].sum + tree[v].sum) % MOD;
        return u;
    }
    push(u); push(v);
    tree[u].ls = merge(tree[u].ls, tree[v].ls);
    tree[u].rs = merge(tree[u].rs, tree[v].rs);
    tree[u].sum = (tree[tree[u].ls].sum + tree[tree[u].rs].sum) % MOD;
    return u;
}

int n, k;
vector<vector<int>> adj;
vector<int> depth;
vector<int> root;

// DFS to compute Tree DP via Segment Tree Merging
void dfs(int u) {
    int m = (int)adj[u].size();
    
    // Base Case: Leaf node
    if (m == 0) {
        root[u] = insert(0, 1, n, depth[u], 1);
        return;
    }
    
    vector<long long> S(m);
    int max_allowed_depth = min(n, depth[u] + k - 1);
    
    // Step 1: Process all children and query valid prefix sums S(v)
    for (int i = 0; i < m; ++i) {
        int v = adj[u][i];
        depth[v] = depth[u] + 1;
        dfs(v);
        S[i] = query(root[v], 1, n, 1, max_allowed_depth);
    }
    
    // Step 2: Precompute prefix and suffix products of S(v) to handle zeros cleanly
    vector<long long> pref(m, 1), suff(m, 1);
    for (int i = 0; i < m; ++i) {
        pref[i] = (i > 0 ? (pref[i - 1] * S[i]) % MOD : S[i]);
    }
    for (int i = m - 1; i >= 0; --i) {
        suff[i] = (i < m - 1 ? (suff[i + 1] * S[i]) % MOD : S[i]);
    }
    
    // Step 3: Compute scalar multipliers and apply to each child's segment tree
    long long perms = fact[m - 1];
    for (int i = 0; i < m; ++i) {
        long long other_prod = 1;
        if (i > 0) other_prod = (other_prod * pref[i - 1]) % MOD;
        if (i < m - 1) other_prod = (other_prod * suff[i + 1]) % MOD;
        
        long long mult = (perms * other_prod) % MOD;
        apply(root[adj[u][i]], mult);
    }
    
    // Step 4: Merge all modified child segment trees into node u
    root[u] = 0;
    for (int i = 0; i < m; ++i) {
        root[u] = merge(root[u], root[adj[u][i]]);
    }
}

void solve() {
    cin >> n >> k;
    
    adj.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    root.assign(n + 1, 0);
    
    // Reset segment tree pool (index 0 is dummy null node)
    tree.clear();
    tree.push_back(Node());
    
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    depth[1] = 1;
    dfs(1);
    
    // The answer is the total sum of all valid ending depths in the root's segment tree
    long long ans = query(root[1], 1, n, 1, n);
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute_factorials();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}