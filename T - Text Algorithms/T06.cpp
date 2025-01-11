//Code by Katarzyna Ludwa

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
 
struct Node {
    Node* fail = 0;
    Node* ch[2] = { 0, 0 };
    int vis = 0;
};
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int z; cin >> z;
    while (z--) {
        Node* root = new Node, * sroot = new Node;
        sroot->ch[0] = root;
        sroot->ch[1] = root;
        root->fail = sroot;
 
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            auto v = root;
            for (char c : s) {
                if (v->ch[c - '0'] == NULL) {
                    v->ch[c - '0'] = new Node;
                }
                v = v->ch[c - '0'];
            }
            v->vis = 2;
        }
 
        auto bfs = [&](Node* v) {
            queue<Node*> Q;
            Q.push(v);
 
            while (Q.size()) {
                Node* v = Q.front(); Q.pop();
 
                for (int a = 0; a < 2; a++) {
                    auto& w = v->ch[a];
                    if (w == NULL) w = v->fail->ch[a];
                    else {
                        w->fail = v->fail->ch[a];
                        if (w->fail->vis == 2) w->vis = 2;
                        Q.push(w);
                    }
                }
            }
        };
        bfs(root);
 
        function<bool(Node*)> dfs = [&](Node* v) {
            if (v->vis == 2) return 0;
            if (v->vis == 1) return 1;
            v->vis = 1;
 
            if (dfs(v->ch[0])) return 1;
            if (dfs(v->ch[1])) return 1;
            v->vis = 2;
 
            return 0;
        };
        bool d = dfs(root);
        cout << (d ? "TAK\n" : "NIE\n");
    }
}
