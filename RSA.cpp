#include<stdio.h>
#include<math.h>
int n,p,q,e,d;

int find_prime(int a) {
	int cnt=0;
	while(1) {
		cnt=0;
		for(int i=2;i<=a;i++) {
			if(a%i==0) cnt++;
		}
		if(cnt==1) {
			n=a;
			return(n); 
		}
		else a=a+2;
	}
}

int find_coprime(int a, int b) {
	int m[100]={}, n[100]={}, cnt=0, max=0;
	
	if(a>=b) max=a;
	else max=b;
	
	for(int i=1;i<=a;i++) {
		if(a%i==0) {
			m[cnt]=i;
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++) printf("%d ",m[i]);
	cnt=0;
	for(int i=1;i<=b;i++) {
		if(b%i==0) {
			n[cnt]=i;
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++) printf("%d ",n[i]);
	
	e=max-1;
	while(1) {
		for(int i=0;i<e;i++) {
			if(e==m[i]||e==n[i]) e=e-1;
			else return(e);
		}
	}
}

int find_d(int a,int b) {
	int c=a*b;
	
	for(int i=1;i<c;i++) {
		if ((e*i)%c==1) d=i;
	}
}
int decryption(unsigned long long int a,unsigned long long int b,unsigned long long int c,unsigned long long int d) {
	unsigned long long int y=0,l;
	
	l=pow(a,b);
	printf("\n%llu",l);
	
	y=l%(c*d);
	printf("\n<해독문>\n%llu",y);
}

int encryption(long long int a,long long int b,long long int c,long long int d,long long int e) {
	long long int x=0,l;
	
	l=pow(a,b);
	printf("\n%lld",l);
	
	x=l%(c*d);
	printf("\n<암호문>\n%lld",x);
	
	decryption(x,e,c,d);
}

int main() {
	printf("첫번째 홀수를 입력해주세요: ");
	scanf("%d",&n);
	find_prime(n);
	p=n;
	//printf("첫번째 소수 : %d\n",p);
	
	printf("두번째 홀수를 입력해주세요:");
	scanf("%d",&n);
	find_prime(n);
	q=n;
	//printf("두번째 소수 : %d\n",q);
	
	find_coprime(p-1,q-1);
	//printf("\np-1과 q-1의 각각 서로소인 정수 : %d",e);
	
	find_d(p-1,q-1);
	printf("\n<개인키d>\n%d",d);
	
	printf("\n<공개키>\nN : %d \ne : %d",p*q,e);
	
	int a=0;
	printf("\n암호화할 숫자를 입력하세요");
	scanf("%d",&a);
	
	encryption(a,e,p,q,d);
}
