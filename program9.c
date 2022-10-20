#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long int p,q,n,t,flag,e,d,temp[100],j,m[100],en[100],i;
char msg[100];
void ce();
long int cd(long int);
void encrypt();
void decrypt();
main() {
	printf("\nENTER FIRST PRIME NUMBER\n");
	scanf("%d",&p);
	printf("\nENTER ANOTHER PRIME NUMBER\n");
	scanf("%d",&q);
	printf("\nENTER MESSAGE\n");
  gets(msg);
	scanf("%[^\n]",msg);
	for (i=0;msg[i]!=NULL;i++)
	m[i]=msg[i];
	n=p*q;
	t=(p-1)*(q-1);
	ce();
	printf("\ne = %d",e);
	printf("\n d = %d ",d);
	encrypt();
	decrypt();
	system("pause");
}
void ce() {
	int k = 0;
	for (i=2;i<t;i++) {
		if(t%i==0)
	    continue;
		if(i!=p&&i!=q) { 
			e=i;
			flag=cd(e);
			if(flag>0) {
				d=flag; 
				break;
			}
		} 
	} 
}
long int cd(long int x) {
	long int k=1;
	while(1) {
		k=k+t;
		if(k%x==0)
		    return(k/x);
	}
}
void encrypt() {
	long int pt,key=e,k,len;
	i=0;
	len=strlen(msg);
	while(i!=len) {
		pt=m[i];
		pt=pt-96;
		k=1;
		for (j=0;j<key;j++) {
			k=k*pt;
			k=k%n;
		}
		temp[i]=k;
		en[i]=k+96;
		i++;
	}
	en[i]=-1;
	printf("\nTHE ENCRYPTED MESSAGE IS\n");
	for (i=0;en[i]!=-1;i++)
	printf("%c",en[i]);
}
void decrypt() {
	long int ct,key=d,k;
	i=0;
	while(en[i]!=-1) {
 	ct=temp[i];
		k=1;
		for (j=0;j<key;j++) {
			k=k*ct;
			k=k%n;
		}
		m[i]=k+96;
		i++;
	}
	m[i]=-1;
	printf("\nTHE DECRYPTED MESSAGE IS\n");
	for (i=0;m[i]!=-1;i++){
	    printf("%c",m[i]);
  }
  printf("\n");
}