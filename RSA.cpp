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
	printf("\n<�ص���>\n%llu",y);
}

int encryption(long long int a,long long int b,long long int c,long long int d,long long int e) {
	long long int x=0,l;
	
	l=pow(a,b);
	printf("\n%lld",l);
	
	x=l%(c*d);
	printf("\n<��ȣ��>\n%lld",x);
	
	decryption(x,e,c,d);
}

int main() {
	printf("ù��° Ȧ���� �Է����ּ���: ");
	scanf("%d",&n);
	find_prime(n);
	p=n;
	//printf("ù��° �Ҽ� : %d\n",p);
	
	printf("�ι�° Ȧ���� �Է����ּ���:");
	scanf("%d",&n);
	find_prime(n);
	q=n;
	//printf("�ι�° �Ҽ� : %d\n",q);
	
	find_coprime(p-1,q-1);
	//printf("\np-1�� q-1�� ���� ���μ��� ���� : %d",e);
	
	find_d(p-1,q-1);
	printf("\n<����Űd>\n%d",d);
	
	printf("\n<����Ű>\nN : %d \ne : %d",p*q,e);
	
	int a=0;
	printf("\n��ȣȭ�� ���ڸ� �Է��ϼ���");
	scanf("%d",&a);
	
	encryption(a,e,p,q,d);
}
