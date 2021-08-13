/*CONSTANT_TEMPLATE*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fastio() ios::sync_with_stdio(0); cin.tie(0);
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long int
#define ld long double
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll mod = 1000000007;
#define pb push_back
#define inc(i,x,n) for(ll i=x;i<n;i++)
#define dec(i,x,n) for(ll i=x;i>=n;i--)
#define step(TC) ll TC;cin>>TC;while(TC--)
mt19937 rng;
int getRandomNumber(int l, int r)
{uniform_int_distribution<int> dist(l, r); return dist(rng);}
#define v(x,name) vector<x> name
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define reverse(v) reverse(v.begin(),v.end())
#define sort(v) sort(v.begin(),v.end())
#define digits(n) floor(log10(n)) + 1
#define printv(ar) for(auto x:ar){cout<<x<<" ";}cout<<endl;
template<typename T>
void printa(T arr[],ll n){inc(i,0,n){cout<<arr[i]<<" ";}cout<<"\n";}
#define one_built_ll(n) __builtin_popcountll(n)
#define one_built_int(n) __builtin_popcount(n)
int __lcm(int a, int b){return (a * b) / __gcd(a, b);}

/*TEMPLATE_START*/

struct node
{
    int data;
    node *left;
    node *right;
    node *next;
    node(int x)
    {
        this->data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

int findHeight(node *root)
{
    if (root == NULL)
        return -1;
    int heightOfLeftSubtree = findHeight(root->left);
    int heightOfRightSubtree = findHeight(root->right);
    return max(heightOfLeftSubtree, heightOfRightSubtree) + 1;
}
/*______________________________________________________________________________________________________________*/

/*TRAVERSALS RECURSIVE*/

void preorder(node *root)
{
    // <data> <left> <right>
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    //  <left> <data> <right>
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    // <left> <right> <data>
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
/*______________________________________________________________________________________________________________*/
/*PREDORDER ITERATIVE*/

void preorderIterative(node *t)
{
    stack<node *> st;

    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            cout << t->data << " ";
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            t = t->right;
        }
    }
    cout << "\n";
}

/*ITERATIVE INORDER*/

void iterativeInorder(node *t) 
{
    stack<node *> st;
    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            cout << (*t).data << " ";
            t = t->right;
        }
    }
    cout << "\n";
}

/*LEVEL ORDER TRAVERSAL*/

void levelOrder(node *head)
{
    if (head == NULL)
        return;

    queue<node *> q;
    q.push(head);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}

/*K LEVEL SUM*/

int levelSum(node *head, int k)
{
    if (head == NULL)
        return 0;

    queue<node *> q;
    q.push(head);
    int level = 0;
    int sum = 0;
    while (!q.empty())
    {
        int n = q.size();
        level++;
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (level == k)
            {
                sum += temp->data;
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    return sum;
}

/*LEFT VIEW*/

vector<int> leftView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        /*iterating over nodes in level with n nodes*/
        for (int i = 1; i <= n; i++)
        {
            node *tmp = q.front();
            q.pop();
            if (i == 1)
            {
                ans.push_back(tmp->data);    
            }
            if (tmp->left != NULL)
            {
                q.push(tmp->left);
            }
            if (tmp->right != NULL)
            {
                q.push(tmp->right);
            }
        }
    }
    return ans;
}

/*CREATE BINARY TREE*/

void Treecreate(node *&root)
{
    queue<node *> q;
    struct node *tmp, *newnode;

    //creating root node
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new node(x);

    //pushing address of root node in queue
    q.push(root);

    while (!q.empty())
    {
        /*which ever is in front of queue(here tmp),input there left and right*/
        tmp = q.front();
        q.pop();
        cout << "Enter left child of " << tmp->data << ": ";
        cin >> x;

        if (x != -1)
        {
            /*creating left node with data x*/
            newnode = new node(x);
            tmp->left = newnode;

            /*pushing address of left node in queue for later taking input of its left and right child*/
            q.push(newnode);
        }
        cout << "Enter right child of " << tmp->data << ": ";
        cin >> x;
        if (x != -1)
        {
            /*creating right node with data x*/
            newnode = new node(x);
            tmp->right = newnode;

            /*pushing address of right node in queue for later taking input of its left and right child*/
            q.push(newnode);
        }
    }
}

/*INVERT TREE*/

node *binInvert(node *head)
{
    if (head == nullptr)
        return NULL;

    binInvert(head->left);
    binInvert(head->right);
    swap(head->left, head->right);
    return head;
}

/*FORGOT*/

node *connect(node *root)
{
    if (root == NULL)
        return NULL;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 1; i <= sz; i++)
        {
            node *tmp;
            if (i == sz)
            {
                tmp = q.front();

                q.front()->next = NULL;
                q.pop();
                if (tmp->left != NULL)
                {
                    q.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    q.push(tmp->right);
                }
            }
            else
            {
                tmp = q.front();
                q.pop();
                tmp->next = q.front();
                if (tmp->left != NULL)
                {
                    q.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    q.push(tmp->right);
                }
            }
        }
    }
    return root;
}

/*DIAMETER (unoptimized)*/

int diameter(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int d1 = diameter(head->left);
    int d2 = diameter(head->right);
    int dMain = 1 + findHeight(head->left) + findHeight(head->right);

    int ans = max(d1, d2);
    int ans1 = max(ans, dMain);
    return ans1;
}

/*DIAMETER (optimized)*/

int ans=INT_MIN;
auto optimized_hieght(node *root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int lh=optimized_hieght(root->left);
    int rh=optimized_hieght(root->right);
    /*calulating diam. during calc hieght and leave rest of hieght func. same*/
    ans=max(ans,lh+rh+1);
    return 1+max(lh,rh);
}
auto optimized_diameter(node* root) 
{
    int temp=optimized_hieght(root);
    return ans;
}

/*ZIGZAG TRAVERSAL*/
vector<int> zigzag(node *head)
{
    vector<int> vec;
    if (head == NULL)
        return vec;

    queue<node *> q;
    q.push(head);
    bool level = 0;

    while (!q.empty())
    {
        if (level == 0)
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                node *temp = q.front();
                q.pop();
                vec.push_back(temp->data);
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
        }
        else
        {
            int len = q.size();
            int len2 = vec.size();

            for (int i = 0; i < len; i++)
            {
                node *temp = q.front();
                q.pop();
                vec.insert(vec.begin() + len2, temp->data);

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
        }
        level = !level;
    }
    return vec;
}

/*SUM GENERATE*/

void sumRep(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumRep(root->left);
    sumRep(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

/*LOWEST COMMON ANCESTOR*/

node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p->data || root->data == q->data)
    {
        return root;
    }
    node *lefty = lowestCommonAncestor(root->left, p, q);
    node *righty = lowestCommonAncestor(root->right, p, q);
    if (lefty != NULL and righty != NULL)
    {
        return root;
    }
    else if (lefty != NULL)
    {
        return lefty;
    }
    else if (righty != NULL)
    {
        return righty;
    }
    else
    {
        return NULL;
    }
}

/*VERTICAL TRAVERSAL*/

void solve(node *root,map<int,map<int,vector<int>>> &m,int shift,int level)
{
    if(root==nullptr){return;}
    m[shift][level].push_back(root->data);
    if(root->left != NULL){solve(root->left,m,shift-1,level+1);}
    if(root->right != NULL){solve(root->right,m,shift+1,level+1);}
}
vector<int> verticalOrder(node *root)
{
    //Your code here
    map<int,map<int,vector<int>>> m;
    vector<int> ans;
    solve(root,m,0,0);
    for(auto x:m)
    {
        for(auto y:x.second)
        {
           ans.push_back(y.second[0]);
        }
    }
    return ans;
}

/*TOP VIEW*/
void solve_t(node *root,map<int,map<int,vector<int>>> &m,int shift,int level)
{
    if(root==nullptr){return;}
    m[shift][level].push_back(root->data);
    if(root->left != NULL){solve_t(root->left,m,shift-1,level+1);}
    if(root->right != NULL){solve_t(root->right,m,shift+1,level+1);}
}
vector<int> topView(node *root)
{
    //Your code here
    map<int,map<int,vector<int>>> m;
    vector<int> ans;
    solve_t(root,m,0,0);
    for(auto x:m)
    {
        for(auto y:x.second)
        {
            ans.push_back(y.second[0]);
            break;
        }
    }
    return ans;
}

/*MAIN*/

int main()
{
    fastio();
    
    node *rootptr = new node(1);
    rootptr->left = new node(2);
    rootptr->right = new node(3);
    rootptr->left->left = new node(4);
    rootptr->left->right = new node(5);
    rootptr->right->left = new node(6);
    rootptr->right->right = new node(7);
    cout << diameter(rootptr);
}

/*


 preorderIterative(rootptr);
1 2 4 5 3 6 7
iterativeInorder(rootptr);
4 2 5 1 6 3
node *rootptr = new node(1);
rootptr->left = new node(2);
rootptr->right = new node(3);
rootptr->left->left = new node(4);
rootptr->left->right = new node(5);
rootptr->right->left = new node(6);
rootptr->right->right = new node(7);
         1
      /    \
     2      3
   /  \   /   \
  4    5 6    7      


*/