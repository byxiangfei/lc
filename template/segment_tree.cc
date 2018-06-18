#include <iostream>

using namespace std;

#define maxn 20000;

int tree[maxn]

// x means the key point you want to update
void update(int x, int pos, int l, int r, int val) {
	if(l == r) {
		tree[pos] += val;
		return;
	}

	int mid = (l + r) >> 1;
	if(x <= mid) update(x, pos << 1, l, mid);
	else update(x, pos << 1 | 1,  mid + 1, r);
	tree[pos] = max(tree[pos<<1], tree[pos<<1|1]);
}

//[x,y] means the internal you want to update
// A[L,R] += C
void Update(int L,int R,int C,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号   
    if(L <= l && r <= R){//如果本区间完全在操作区间[L,R]以内   
        Sum[rt]+=C*(r-l+1);//更新数字和，向上保持正确  
        Add[rt]+=C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整  
        return ;   
    }  
    int m=(l+r)>>1;  
    PushDown(rt, m-l+1, r-m);//下推标记  
    //这里判断左右子树跟[L,R]有无交集，有交集才递归   
    if(L <= m) Update(L,R,C,l,m,rt<<1);  
    if(R >  m) Update(L,R,C,m+1,r,rt<<1|1);   
    PushUp(rt);//更新本节点信息   
}   

void PushDown(int rt,int ln,int rn){  
    //ln,rn为左子树，右子树的数字数量。   
    if(Add[rt]){  
        //下推标记   
        Add[rt<<1]+=Add[rt];  
        Add[rt<<1|1]+=Add[rt];  
        //修改子节点的Sum使之与对应的Add相对应   
        Sum[rt<<1]+=Add[rt]*ln;  
        Sum[rt<<1|1]+=Add[rt]*rn;  
        //清除本节点标记   
        Add[rt]=0;  
    }  
}  

int Query(int L,int R,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号  
    if(L <= l && r <= R){  
        //在区间内，直接返回   
        return Sum[rt];  
    }  
    int m=(l+r)>>1;  
    //下推标记，否则Sum可能不正确  
    PushDown(rt,m-l+1,r-m);   
      
    //累计答案  
    int ANS=0;  
    if(L <= m) ANS+=Query(L,R,l,m,rt<<1);  
    if(R > m) ANS+=Query(L,R,m+1,r,rt<<1|1);  
    return ANS;  
}   
