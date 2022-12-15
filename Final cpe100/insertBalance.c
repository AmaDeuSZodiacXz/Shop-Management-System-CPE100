#include "insertBalance.h"
int insertBalance(int value){
	FILE *fp;
	int balance=getBalance();
	fp=fopen("balance.txt","w");
	fprintf(fp,"%d",balance+value);
	fclose(fp);
}
