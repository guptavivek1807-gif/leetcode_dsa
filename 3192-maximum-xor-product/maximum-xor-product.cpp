class Solution {
public:
    int M=1e9+7;
    typedef long long ll;

    int maximumXorProduct(long long a, long long b, int n) {
        ll xxora=0;
        ll xxorb=0;
        for(ll i=49;i>=n;i--){
            int aithbit=((a>>i)&1)>0;
            int bithbit=((b>>i)&1)>0;

            if(aithbit==true){
                xxora=(xxora^(1ll<<i));
            }
            if(bithbit==true){
                xxorb=(xxorb^(1ll<<i));
            }
        }
        for(ll i=n-1;i>=0;i--){
            bool aithbit=((a>>i)&1)>0;
            bool bithbit=((b>>i)&1)>0;

            if(aithbit==bithbit){
                xxora=(xxora^(1ll<<i));
                xxorb=(xxorb^(1ll<<i));
                continue;
            }
            if(xxora>xxorb){
                xxorb=(xxorb^(1ll<<i));
            }
            else{
                xxora=(xxora^(1ll<<i));
            }
            
        }
        xxora=(xxora%M);
            xxorb=(xxorb%M);

            return (xxora*xxorb)%M;
        
    }
};