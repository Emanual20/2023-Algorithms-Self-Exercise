const int maxn = 2e5 + 10;
int n;
struct DSU{
public:
    int f[maxn], sz[maxn];
    // remember to call init
    void init(){
        for (int i = 1; i <= n; i++)
            f[i] = i, sz[i] = 1;
    }
    int find(int k){
        if(f[k] == k)
            return k;
        return f[k] = find(f[k]);
    }
    void merge(int dst, int src){
        int ds = find(dst), sr = find(src);
        f[sr] = ds;
        if(ds != sr) sz[ds] += sz[sr];
    }
};