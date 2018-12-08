#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct str
{
    char s[50 + 10];
};

struct Node
{
    bool isend;
    Node * left,* right;
    Node()
    {
        isend = false;
        left = right = NULL;
    }
};

bool cmp(str a,str b)
{
    if(strlen(a.s) < strlen(b.s))
        return true;
    else
        return false;
}

str buf[100 + 10];

void free(Node * root)
{
    if(root -> right)
    {
        free(root -> right);
    }
    if(root -> left)
    {
        free(root -> left);
    }
    delete root;
}

int main()
{
    int t,n,p;
    scanf("%d",&t);
    for(int ics = 1;ics <= t;ics ++)
    {
        scanf("%d%d",&n,&p);
        //char buf[50 + 10];
        for(int i = 0;i < p;i ++)
        {
            scanf("%s",buf[i].s);
        }
        sort(buf,buf + p,cmp);
        
        long long ans = pow(2,n);
        //cout << ans << endl;
        Node * root = new Node;
        for(int i = 0;i < p;i ++)
        {
            Node * now = root;
            int len = strlen(buf[i].s);
            //cout << "len = " << len << endl;
            for(int j = 0;j < len;j ++)
            {
                if(buf[i].s[j] == 'R')
                {
                    if(now -> right == NULL)
                    {
                        now -> right = new Node;
                        if(j == len - 1)
                        {
                            now -> right -> isend = true;
                            ans -= pow(2,n - j - 1);
                            
                          /*  cout <<"j = " <<  j  << endl;
                            cout << "ansleft = " << ans << endl;
                        */
                        }
                    }
                    else
                    {
                        if(now -> right -> isend)
                            break;
                    }
                    now = now -> right;
                }
                else
                {
                    if(now -> left == NULL)
                    {
                        now -> left = new Node;
                        if(j == len - 1)
                        {
                            now -> left -> isend = true;
                            ans -= pow(2,n - j  - 1);
                            //cout << n - j + 1 << endl;
                            /*cout << "j = " << j << endl;
                            cout << "ansright = " << ans  << endl;
                        */
                        }
                    }
                    else
                    {
                        if(now -> left -> isend)
                            break;
                    }

                    now = now -> left;
                }
            }
            
        }
        free(root);
        printf("Case #%d: ",ics);
        printf("%lld\n",ans);
    }
}