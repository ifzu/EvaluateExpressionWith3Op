/*
	Evaluating Expression
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//maxim 3 operanzi Eval 
void evaluateExpr(char* expr){
	
	//expr
	char finalexpr[16];

	//maxim 3 operanzi
	char operatori[2] = {0};
	float operanzi[3];
	unsigned k = 0;
	unsigned nrop = 0;
	float rez = 0;
	float aux = 0;
	char* expresie = expr;
	char* p;
	int i;
	

	while (*expresie != '\0'){

		if (!isdigit(*expresie))
			operatori[nrop++] = *expresie;
		++expresie;
	}


	p = strtok(expr, "/+-*");
	
	while (p!=NULL){
		
		operanzi[k]= strtod(p,NULL);
		printf("%.3f\n", operanzi[k]);
		k++;
		p = strtok(NULL, "/+-*");

	}
	

	//daca avem un operator
	//avem 2 operanzi 
	if (nrop == 1){

		switch (operatori[0]){
		case '+':
			rez = operanzi[0] + operanzi[1];
			break;

		case '-':
			rez = operanzi[0] - operanzi[1];
			break;

		case '*':
			rez = operanzi[0] * operanzi[1];
			break;

		case '/':
			rez = operanzi[0] / operanzi[1];
			break;

		default:
			break;
			
		}

	//2 operatori => 3 operanzi 
	}else if ((operatori[1] == '*' || operatori[1] == '/' )&& (operatori[0] == '+' || operatori[0] == '-')){  //tratam cazul exceptional

		switch (operatori[1]){
		case '*':
			aux = operanzi[1] * operanzi[2];
			break;
		case '/':
			aux = operanzi[1] / operanzi[2];
			break;

		}

		switch (operatori[0]){
		case '+':
			rez = aux + operanzi[0];
			break;
		case '-':
			rez = aux - operanzi[0];
			break;

		}

		printf("%.3f", rez);

	}
	else{
		switch (operatori[0]){
		case '*':
			aux = operanzi[0] * operanzi[1];
			break;
		case '/':
			aux = operanzi[0] / operanzi[1];
			break;
		case '+':
			aux = operanzi[0] + operanzi[1];
			break;
		case '-':
			aux = operanzi[0] - operanzi[1];
			break;

		}

		switch (operatori[1]){
		case '+':
			rez = aux + operanzi[2];
			break;
		case '-':
			rez = aux - operanzi[2];
			break;
		case '*':
			rez = aux * operanzi[2];
			break;
		case '/':
			rez = aux / operanzi[2];
			break;

		}
		

	}


	//printf("%.3f", rez);
	sprintf(finalexpr, "%.2f", rez);
	printf("%s", finalexpr);
}


int main(){

	//operatori=operanzi-1
	char expr[] = "30+40";
	
	evaluateExpr(expr);


	return 0;
}