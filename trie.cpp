#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


using namespace std;

#define int         long long
#define ld          double
#define vi          vector <int>
#define vp          vector <pair<int,int>>
#define vvi         vector <vector <int>>
#define pb          push_back
#define mp          make_pair
#define pi          pair<int,int>
#define all(a)      a.begin(),a.end()
#define sz(a)       a.size()
#define sl(a)       a.length()
#define rev(a)      sort(all(a),greater<int>())
#define ff          first
#define ss          second
#define minel(a)	*min_element(all(a))
#define maxel(a)	*max_element(all(a))
#define Mod         1000000007
#define deb(x)      cout << x << endl;
#define o(x)        for(auto a:x)cout << a <<" ";cout << endl;
#define o2(x,n,m)   for(int i =0;i<n;i++){for(int j=0;j<m;j++)cout << x[i][j] << " ";cout << endl; } 
#define i(x,n)      for(int i=0;i<n;i++)cin >> x[i];
#define i2(x,n,m)   for(int i =0;i<n;i++){for(int j=0;j<m;j++)cin >> x[i][j]; }
int inf = 1e18;


struct node
{
    struct node* a[26];
    bool valid;
};

struct node* root;

node* MakeNode(void)
{
    struct node* p;
    p = new node;

    for(int i=0;i<26;i++)p->a[i] = NULL;
    p->valid = false;

    return p;
}

void insert(string s)
{
    struct node* temp;
    temp = root;
    int n = sl(s);
    for(int i=0;i<n;i++)
    {
        int x = s[i] - 'a';
        if(temp->a[x] == NULL)
            temp->a[x] = MakeNode();
        temp = temp->a[x];
    }

    temp->valid = true;
}

bool search(string s)
{
    struct node* temp;
    temp = root;
    int n = sl(s);

    for(int i=0;i<n;i++)
    {
        int x = s[i] - 'a';
        if(temp->a[x] == NULL)
        {
            return false;
        }
        temp = temp->a[x];
    }

    if(temp!= NULL && temp->valid)return true;
    else return false;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    root = MakeNode();

    int queries;
    cin >> queries;

    while(queries--)
    {
        int t;string s;
        cin >>t >>s;

        if(t==1)insert(s);
        else cout << (search(s)?"YES":"NO") << endl;
    }



    
}

