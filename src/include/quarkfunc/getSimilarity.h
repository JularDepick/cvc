double getSimilarity(string a, string b) {
    if(a.empty() && b.empty()) {
        return -1;
    }
    const string& longer=((a.size()>=b.size())? a:b);
    const string& shorter=((a.size()<b.size())? a:b);
    const int m=longer.size();
    const int n=shorter.size();
    vector<int> prev(n+1);
    vector<int> curr(n+1);
    for(int i=0;i<=n;i++) {
        prev[i]=i;
    }
    for(int i=1;i<=m;i++) {
        curr[0]=i;
        for(int j=1;j<=n;j++) {
            int cost=((longer[i-1]==shorter[j-1])? 0:1);
            curr[j]=min( min(prev[j]+1,curr[j-1]+1), prev[j-1]+cost);
        }
        prev.swap(curr);
    }
    return (1.0-static_cast<double>(prev.back())/max(a.size(), b.size()));
}
