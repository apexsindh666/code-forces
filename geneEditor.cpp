#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAX_STATES = 5000;

int parent_state[MAX_STATES];
int next_state[MAX_STATES][2];
int num_states;

// DSU find representative state
int find_state(int u) {
    if (u == -1) return -1;
    if (parent_state[u] == u) return u;
    return parent_state[u] = find_state(parent_state[u]);
}

// Get transition with automatic path compression
int get_next(int u, int c) {
    u = find_state(u);
    if (u == -1) return -1;
    if (next_state[u][c] != -1) {
        next_state[u][c] = find_state(next_state[u][c]);
    }
    return next_state[u][c];
}

// Merge two equivalent group states and recursively unify their transitions
void merge_states(int a, int b) {
    a = find_state(a);
    b = find_state(b);
    if (a == b || a == -1 || b == -1) return;
    if (a > b) swap(a, b); // Keep smaller ID as representative
    parent_state[b] = a;
    for (int c = 0; c < 2; ++c) {
        if (next_state[b][c] != -1) {
            if (next_state[a][c] == -1) {
                next_state[a][c] = find_state(next_state[b][c]);
            } else {
                merge_states(next_state[a][c], next_state[b][c]);
            }
        }
    }
}

// Check all group relators and merge states if loops are found
bool check_relators(const vector<string>& relators) {
    bool merged_any = false;
    for (int i = 0; i < num_states; ++i) {
        if (find_state(i) != i) continue;
        for (const string& R : relators) {
            int curr = i;
            bool ok = true;
            for (char ch : R) {
                int c = ch - 'A';
                curr = get_next(curr, c);
                if (curr == -1) {
                    ok = false;
                    break;
                }
            }
            if (ok && find_state(curr) != find_state(i)) {
                merge_states(curr, i);
                merged_any = true;
            }
        }
    }
    return merged_any;
}

// Build the Cayley graph automaton using Todd-Coxeter coset enumeration
void build_automaton(const string& s) {
    vector<string> relators = {"AA", "BBB", s};
    for (int i = 0; i < MAX_STATES; ++i) {
        parent_state[i] = i;
        next_state[i][0] = next_state[i][1] = -1;
    }
    num_states = 1;

    int idx = 0;
    while (idx < num_states) {
        if (find_state(idx) != idx) {
            idx++;
            continue;
        }
        for (int c = 0; c < 2; ++c) {
            int u = find_state(idx);
            if (u != idx) break;
            if (get_next(u, c) == -1) {
                if (num_states >= MAX_STATES) break;
                int v = num_states++;
                next_state[u][c] = v;
                if (c == 0) {
                    // Since A^2 = 1, A is its own inverse: u -> v implies v -> u
                    if (next_state[v][0] == -1) {
                        next_state[v][0] = u;
                    } else {
                        merge_states(next_state[v][0], u);
                    }
                }
                while (check_relators(relators));
            }
        }
        idx++;
    }
}

struct Matrix {
    int size;
    vector<vector<long long>> mat;
    Matrix(int s) : size(s), mat(s, vector<long long>(s, 0)) {}
};

Matrix multiply(const Matrix& A, const Matrix& B) {
    int s = A.size;
    Matrix C(s);
    for (int i = 0; i < s; ++i) {
        for (int k = 0; k < s; ++k) {
            if (A.mat[i][k] == 0) continue;
            for (int j = 0; j < s; ++j) {
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, long long p) {
    int s = A.size;
    Matrix res(s);
    for (int i = 0; i < s; ++i) res.mat[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

void solve() {
    string s, t;
    long long n;
    if (!(cin >> s >> t >> n)) return;

    build_automaton(s);

    // Compress active state IDs to 0 ... K-1
    vector<int> active_states;
    vector<int> state_to_id(num_states, -1);
    for (int i = 0; i < num_states; ++i) {
        if (find_state(i) == i) {
            state_to_id[i] = active_states.size();
            active_states.push_back(i);
        }
    }

    int K = active_states.size();

    // Trace target string t in the group automaton
    int curr = find_state(0);
    for (char ch : t) {
        curr = get_next(curr, ch - 'A');
    }
    int target_id = state_to_id[curr];

    // Construct adjacency matrix for string growth
    Matrix M(K);
    for (int i = 0; i < K; ++i) {
        int u = active_states[i];
        int nxtA = state_to_id[get_next(u, 0)];
        int nxtB = state_to_id[get_next(u, 1)];
        M.mat[nxtA][i] = (M.mat[nxtA][i] + 1) % MOD;
        M.mat[nxtB][i] = (M.mat[nxtB][i] + 1) % MOD;
    }

    Matrix Mn = power(M, n);
    int start_id = state_to_id[find_state(0)];
    long long ans = Mn.mat[target_id][start_id];
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}