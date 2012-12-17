#include<cstdio>
#include<cstring>
FILE *fi=fopen("buylow.in","r"),*fo=fopen("buylow.out","w");
const int MAXn=5000+9,INF=0x7fffffff;
struct bign
{
        char n[500];
            int len;
                bign():len(1)
                        {
                                    memset(n,0,sizeof(n));
                                        }
                    void operator += (const bign &rhs)
                            {
                                        if(rhs.len>len)
                                                        len=rhs.len;
                                                for(int i=0;i<len;++i)
                                                            {
                                                                            n[i]+=rhs.n[i];
                                                                                        if(n[i]>9)
                                                                                                        {
                                                                                                                            ++n[i+1];
                                                                                                                                            n[i]-=10;
                                                                                                                                                        }
                                                                                                }
                                                        if(n[len])
                                                                        ++len;
                                                            }
                        void print()
                                {
                                            for(int i=len-1;i>=0;--i)
                                                            fprintf(fo,"%d",n[i]);
                                                    fputc(10,fo);
                                                        }
}cnt[MAXn],cntans;
int f[MAXn],a[MAXn];
int main()
{
        int n,i,j;
            fscanf(fi,"%d",&n);
                for(i=1;i<=n;++i)
                            fscanf(fi,"%d",a+i);
                    a[0]=INF,cnt[0].len=cnt[0].n[0]=1;
                        ++n;
                            for(i=1;i<=n;++i)
                                        for(j=i-1;j>=0 && a[j]!=a[i];--j)
                                                        if(a[j]>a[i])
                                                                        {
                                                                                            if(f[j]+1>f[i])
                                                                                                                    f[i]=f[j]+1,cnt[i]=cnt[j];
                                                                                                            else if(f[j]+1==f[i])
                                                                                                                                    cnt[i]+=cnt[j];
                                                                                                                        }
                                fprintf(fo,"%d ",f[n]-1);
                                    cnt[n].print();
                                        fclose(fi);
                                            fclose(fo);
                                                return 0;
}

