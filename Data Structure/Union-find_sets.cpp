/*--waltz26--*/


//带路径压缩的并查集+计算最大联通数
int fa[100005];    //存储祖先
int connected[100005];    //以下标为祖先的联通数，在main函数中将其初始化为1
int ans;    //存储最大联通数

int check_anc(int x)    //寻找祖先
{
    if (fa[x]) return fa[x]=check_anc(fa[x]);    //路径压缩
    return x;
}
void union_anc(int x,int y)    //合并
{
    x=check_anc(x); y=check_anc(y);
    if (x!=y)
    fa[x]=y;
}
bool is_same_anc(int x,int y)    //是否有相同祖先
{
    if (check_anc(x)==check_anc(y)) return 1;
    else return 0;
}
void union_anc_2(int x,int y)    //合并并且计算最大联通数
{
    x=check_anc(x); y=check_anc(y);
    if (x!=y)
    {
	    fa[x]=y;
	    connected[y]+=connected[x];
        if (connected[y]>ans)
            ans=connected[y];
    }
}
