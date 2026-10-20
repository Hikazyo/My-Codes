#include<bits/stdc++.h>
#define ll int
#define fir first
#define sec second
const int M = 1e6 + 5;

using namespace std;

inline ll read(){
	char c=getchar();ll res=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c^48);
		c=getchar();
	}
	return res;
}

inline void write(ll k){
	if(k>=10)write(k/10);
	putchar((k%10)|0x30);
}

vector<ll>eg[M];
pair<ll,ll>cpo[M];

ll n,Q,B,lit,inb[M];
ll dep[M],siz[M];
ll son[M],fas[M];

void dfs_1(ll fa,ll p){
	dep[p]=dep[fa]+1;
	siz[p]=1;fas[p]=fa;
	for(ll v:eg[p]){
		if(v==fa)continue;
		dfs_1(p,v);
		siz[p]+=siz[v];
		if(siz[son[p]]<siz[v])son[p]=v;
	}
}

struct PIC{
	ll L,R,sm[M],mx[M];
	PIC(){
		memset(sm,0,sizeof(sm));
		memset(mx,0,sizeof(mx));
	}
};
struct BLK{
	ll op,len,top;
	vector<PIC>hac;
	vector<ll>pot={0};
	unordered_map<ll,ll>inw;
	void init(){
		if(pot.size() < B)op=0;
		else{
			ll p=0;
			op=1;len=pot.size()-1;
			while(1){
				PIC add;
				add.L=p+1,add.R=min(len,p+B);
				for(ll i=add.L;i<=add.R;i++){
					inw[pot[i]]=hac.size();
					add.sm[cpo[pot[i]].sec]+=cpo[pot[i]].fir;
					add.mx[cpo[pot[i]].sec]=max(add.mx[cpo[pot[i]].sec],cpo[pot[i]].fir);
				}
				hac.push_back(add);
				p=add.R;
				if(add.R==len)break;
			}
		}
	}
	void era(ll k){
		for(ll i=hac[k].L;i<=hac[k].R;i++){
			hac[k].sm[cpo[pot[i]].sec]=0;
			hac[k].mx[cpo[pot[i]].sec]=0;
		}
	}
	void add(ll k){
		for(ll i=hac[k].L;i<=hac[k].R;i++){
			hac[k].sm[cpo[pot[i]].sec]+=cpo[pot[i]].fir;
			hac[k].mx[cpo[pot[i]].sec]=max(hac[k].mx[cpo[pot[i]].sec],cpo[pot[i]].fir);
		}
	}
	void modify_1(ll p,ll k){
		if(op==1){
			era(inw[p]);
			cpo[p].fir=k;
			add(inw[p]);
		}
		else cpo[p].fir=k;
	}
	void modify_2(ll p,ll k){
		if(op==1){
			era(inw[p]);
			cpo[p].sec=k;
			add(inw[p]);
		}
		else cpo[p].sec=k;
	}
	ll pos(ll k){return lower_bound(pot.begin(),pot.end(),k)-pot.begin();}
	ll query_1(ll x,ll y,ll k){
		x=pos(x),y=pos(y);
		if(x>y)swap(x,y);
		ll res=0;
		if(op==1){
			for(PIC &it:hac){
				if(it.L>=x&&it.R<=y)res+=it.sm[k];
				else{
					for(ll i=it.L;i<=it.R;i++)
						if(i>=x&&i<=y&&cpo[pot[i]].sec==k)
							res+=cpo[pot[i]].fir;
				}
			}
		}
		else{
			for(ll i=x;i<=y;i++)
				if(cpo[pot[i]].sec==k)
					res+=cpo[pot[i]].fir;
		}
		return res;
	}
	ll query_2(ll x,ll y,ll k){
		x=pos(x),y=pos(y);
		if(x>y)swap(x,y);
		ll res=0;
		if(op==1){
			for(PIC &it:hac){
				if(it.L>=x&&it.R<=y)
					res=max(res,it.mx[k]);
				else{
					for(ll i=it.L;i<=it.R;i++)
						if(i>=x&&i<=y&&cpo[pot[i]].sec==k)
							res=max(res,cpo[pot[i]].fir);
				}
			}
		}
		else{
			for(ll i=x;i<=y;i++)
				if(cpo[pot[i]].sec==k)
					res=max(res,cpo[pot[i]].fir);
		}
		return res;
	}
}blk[M];

void dfs_2(ll p,ll opt){
	inb[p]=opt;
	blk[opt].pot.push_back(p);
	if(son[p])dfs_2(son[p],opt);
	for(ll v:eg[p]){
		if(v==fas[p]||v==son[p])continue;
		blk[++lit].top=v;
		dfs_2(v,lit);
	}
}

ll query_1(ll x,ll y,ll k){
	ll res=0;
	while(inb[x]!=inb[y]){
		if(dep[blk[inb[x]].top]<dep[blk[inb[y]].top])swap(x,y);
		res+=blk[inb[x]].query_1(blk[inb[x]].top,x,k);
		x=fas[blk[inb[x]].top];
	}
	if(dep[x]>dep[y])swap(x,y);
	res+=blk[inb[x]].query_1(x,y,k);
	return res;
}
ll query_2(ll x,ll y,ll k){
	ll res=0;
	while(inb[x]!=inb[y]){
		if(dep[blk[inb[x]].top]<dep[blk[inb[y]].top])swap(x,y);
		res=max(res,blk[inb[x]].query_2(blk[inb[x]].top,x,k));
		x=fas[blk[inb[x]].top];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=max(res,blk[inb[x]].query_2(x,y,k));
	return res;
}

signed main(){
	
	n=read(),Q=read();B=sqrt(n);
	for(ll i=1;i<=n;i++)
		cpo[i].fir=read(),cpo[i].sec=read();
	for(ll i=1;i<n;i++){
		ll x=read(),y=read();
		eg[x].push_back(y);
		eg[y].push_back(x);
	}
		
	dfs_1(0,1);
	
	blk[++lit].top=1;
	dfs_2(1,lit);
	
	for(ll i=1;i<=lit;i++)
		blk[i].init();
	
	while(Q--){
		char op;ll x,y;
		op=getchar();
		op=getchar();
		x=read(),y=read();
		if(op=='C')blk[inb[x]].modify_2(x,y);
		if(op=='W')blk[inb[x]].modify_1(x,y);
		if(op=='S')write(query_1(x,y,cpo[x].sec)),putchar('\n');
		if(op=='M')write(query_2(x,y,cpo[x].sec)),putchar('\n');
		
	}
	
	return 0;
}
