#include<bits/stdc++.h>
using namespace std;

     int last[1000100];
     int A[30010];

class querynode
{
    public:
    int l,r,Q_no,ans;
    querynode()
    {
        l=0;
        r=0;
        Q_no=0;
        ans=0;
    }
};

querynode query_structure[200010];

bool compare(querynode q1,querynode q2)
{
    return q1.r<q2.r;
}

bool compare2(querynode q1,querynode q2)
{
    return q1.Q_no < q2.Q_no;
}

void update( int*tree, int ss, int se, int i, int val,int index)
{
    if(i<ss||i>se)
    {
        return;
    }
    ///means the base node has been found out which has to be updated along with the other elements too,because of which we have used while loop here.
    if(ss==se&&ss==i)
    {
        tree[index] = val;
        return ;
    }
     int mid = (ss+se)/2;
    update(tree,ss,mid,i,val,2*index);
    update(tree,mid+1,se,i,val,2*index+1);
    tree[index] = (tree[2*index]+tree[2*index+1]);
    return ;
}

 int query( int*tree, int qs, int qe, int ss, int se, int index)
{
  ///no overlap---> return inf;

    if(se<qs||ss>qe)
    {
        return 0;
    }
  ///complete overlap --->return tree[index]
    if(ss>=qs&&se<=qe)
    {
       return tree[index];
    }

     int mid=(ss+se)/2;
    return query(tree,qs,qe,ss,mid,2*index) + query(tree,qs,qe,mid+1,se,2*index+1);
}

int main()
{
     int ar[30010],tree[200010];
    memset(last,-1,sizeof(last));
    memset(A,0,sizeof(A));
    memset(tree,0,sizeof(tree));
     int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }

     int q,index=0;
    scanf("%d", &q);
     int query_hold=q;
    while(q--)
    {
         int l,r;
        scanf("%d %d",&l,&r);
        query_structure[index].l=l-1;
        query_structure[index].r=r-1;
        query_structure[index].Q_no=index;
        index++;
    }

    sort(query_structure,query_structure+query_hold,compare);



     int current_pointer=0;
    ///Now we wi iterate over a the queries..

    //cout<<query_hold<<endl;

   ///looping a over the sorted queries.
    // for(int i=0;i<query_hold;i++)
    // {
    //     cout<<query_structure[i].l<<","<< query_structure[i].r<<","<<query_structure[i].Q_no<<endl;
    // }

    for(int i=0;i<query_hold;i++)
    {

        if(current_pointer!=query_structure[i].r)
        {
            while(current_pointer<query_structure[i].r)
            {
               if(last[ar[current_pointer]]==-1)
               {
                    last[ar[current_pointer]]=current_pointer;
                    A[current_pointer]=1;
                    update(tree,0,n-1,current_pointer,1,1);

                    // for(int j=1;j<=13;j++)
                    //  {
                    //      cout<<tree[j]<<",";
                    //  }
                    //  cout<<endl;
               }
               else
               {
                   A[last[ar[current_pointer]]]=0;
                   A[current_pointer]=1;
                    update(tree,0,n-1,last[ar[current_pointer]],0,1);
                    update(tree,0,n-1,current_pointer,1,1);
                    last[ar[current_pointer]]=current_pointer;
                    // for(int j=1;j<=13;j++)
                    //  {
                    //      cout<<tree[j]<<",";
                    //  }
                    //  cout<<endl;
               }
              current_pointer++;
            }
        }

        if(current_pointer==query_structure[i].r)
           {
            if(last[ar[current_pointer]]==-1)
               {
                    last[ar[current_pointer]]=current_pointer;
                    A[current_pointer]=1;
                    update(tree,0,n-1,current_pointer,1,1);
                    // for(int j=1;j<=13;j++)
                    //  {
                    //      cout<<tree[j]<<",";
                    //  }
                    //  cout<<endl;
               }
               else
               {
                   A[last[ar[current_pointer]]]=0;
                   A[current_pointer]=1;
                    update(tree,0,n-1,last[ar[current_pointer]],0,1);
                    update(tree,0,n-1,current_pointer,1,1);
                    last[ar[current_pointer]]=current_pointer;
                    // for(int j=1;j<=13;j++)
                    //  {
                    //      cout<<tree[j]<<",";
                    //  }
                    //  cout<<endl;
               }
              current_pointer++;
           }
            query_structure[i].ans  =  query(tree , query_structure[i].l , query_structure[i].r , 0 , n-1 , 1 );

    }

    sort(query_structure , query_structure + query_hold , compare2);

    for(int i=0;i<query_hold;i++)
    {
        printf("%d\n",query_structure[i].ans);
    }

    return 0;
}
