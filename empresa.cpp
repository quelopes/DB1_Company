#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"

MYSQL* connection(MYSQL *conn);

void menu_inicial(void);
void exit (void);
void back (void);

void include(void);		/*ok*/
void new_emp(void);		/*ok*/
void new_prjct(void);	/*ok*/
void new_depto(void);	/*ok*/
void new_dependent(void);	/*ok*/
void new_works_on(void);	/*ok*/

void del(void);		/*ok*/
void del_emp(void);		/*ok*/
void del_prjct(void);	/*ok*/
void del_depto(void);	/*ok*/
void del_dependent(void);	/*ok*/
void del_works_on(void);	/*ok*/

void alt(void);		/*ok*/
void alt_emp (void);		/*ok*/
void alt_emp_name(void);	/*ok*/
void alt_emp_ssn(void);	/*ok*/
void alt_emp_bdate(void);	/*ok*/
void alt_emp_add(void);	/*ok*/
void alt_emp_mny(void);	/*ok*/
void alt_emp_sex(void);	/*ok*/

void alt_prjct(void);	/*ok*/
void alt_prjct_name(void);	/*ok*/
void alt_prjct_no(void);	/*ok*/
void alt_prjct_local(void);	/*ok*/

void alt_depto (void);	/*ok*/
void alt_depto_name (void);	/*ok*/
void alt_depto_no (void);	/*ok*/
void alt_depto_local(void); /*ok*/

void alt_dependent(void);	/*ok*/
void alt_dependent_name(void);/*ok*/
void alt_dependent_bdate(void);/*ok*/
void alt_dependent_relationship(void);/*ok*/
void alt_Dependent_ssn (int new_ssn, int old_ssn);/*ok*/

void alt_works_on(void);/*ok*/

void query(char* where, char* condition);
void query_menu(void);

void report(char* info, char* table);
void report_menu();
		
int main()
{
	menu_inicial();
}

/*============================================================*/
void new_works_on(void)
{	
	MYSQL *conn;
	int res,ssn,hrs,no;
	char entry[201], name[51];
	printf("\n\n SSN do Empregado:");
	scanf("%d",&ssn);
	printf("\n\n No do Projeto:");
	scanf("%d",&no);
	printf("\n\n Horas trabalhadas:");
	scanf("%d",&hrs);
		
	sprintf(entry,"INSERT INTO WORKS_ON VALUES(%d,%d,%d)",hrs,ssn,no);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	return;
}
/*============================================================*/
void new_emp (void)
{
	char fname[21],mname[21],lname[21],st[31],cmp[11],city[21],uf[21],bdate[11],sex[2], entry[301];
	float mny;
	int ssn, no, zip, res, superSSN;
	MYSQL* conn;
		
	printf("\nINCLUIR NOVO EMPREGADO:");
	printf("\n\n Primeiro nome: ");
	scanf("%s",fname);
	printf("\n\n Nome do meio: ");
	scanf("%s",mname);
	printf("\n\n Último nome: ");
	scanf("%s",lname);
	printf("\n\n SSN: ");
	scanf("%d",&ssn);
	printf("\n\n Rua: ");
	scanf("%s",st);
	printf("\n\n No: ");
	scanf("%d",&no);
	printf("\n\n Complemento: ");
	scanf("%s",cmp);
	printf("\n\n Cidade: ");
	scanf("%s",city);
	printf("\n\n Estado: ");
	scanf("%s",uf);
	printf("\n\n ZIP Code: ");
	scanf("%d",&zip);
	printf("\n\n Sexo(m/f): ");
	scanf("%s",sex);
	printf("\n\n Salario: ");
	scanf("%f",&mny);
	printf("\n\n Data de Nascimento(aaaa/mm/dd): ");
	scanf("%s",bdate);
	printf("\n\n SSN do Supervisor: ");
	scanf("%d",&superSSN);
	
	
	sprintf(entry,"INSERT INTO EMPLOYEE VALUES (%d,'%s','%s','%s','%s','%s','%s',%d,'%s','%s',%d,'%s',%f,%d)",ssn,bdate,fname,mname,lname,sex,st,no,cmp,city,zip,uf,mny,superSSN);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	
	return;
}
/*============================================================*/
void new_dependent(void)
{
	
	char name[51], sex[1], bdate[11], rltshp[20], entry[301];
	MYSQL* conn;
	int res,ssn;
	
	printf("\nINCLUIR NOVO DEPENDENTE:");
	printf("\nSSN do Empregado:");
	scanf("%d",&ssn);
	printf("\n\n Nome: ");
	scanf("%s",name);
	printf("\n\n Sexo(m/f): ");
	scanf("%s",sex);
	printf("\n\n Relacionamento com o empregado: ");
	scanf("%s",rltshp);
	printf("\n\n Data de Nascimento(aaaa/mm/dd): ");
	scanf("%s",bdate);
	
	sprintf(entry,"INSERT INTO DEPENDENTS VALUES (%d,'%s','%s','%s','%s')",ssn,sex,bdate,rltshp,name);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void new_prjct (void)
{
	char pname[41], entry[81]; 
	int pno, dno;
	int res;
	MYSQL* conn;
		
	printf("\nINCLUIR NOVO PROJETO");
	printf("\n\n Nome do projeto: ");
	scanf("%s",pname);
	printf("\n\n Número: ");
	scanf("%d",&pno);
	printf("\n\n Localização(No do depto): ");
	scanf("%d",&dno);
	
	sprintf(entry,"INSERT INTO PROJECT VALUES (%d, '%s', %d)",pno,pname,dno);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	
	return;
}
/*============================================================*/	
void new_depto (void)
{
	char dname[31], whr[100], entry [265]; 
	int dno, res;
	MYSQL *conn;
		
	printf("\nINCLUIR NOVO DEPARTAMENTO");
	printf("\n\n Nome do departamento: ");
	scanf("%s",dname);
	printf("\n\n Número: ");
	scanf("%d",&dno);
	printf("\n\n Localização(endereço): ");
	scanf("%s",whr);
	
	sprintf(entry,"INSERT INTO DEPARTMENT VALUES (%d,'%s','%s')",dno,dname,whr);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	
	
	return;
}
/*============================================================*/
void include(void)
{
	int op;

	for(;;)
	{
		printf(" \nINCLUIR NOVO:\n\n EMPREGADO(1)\n\n PROJETO(2)\n\n DEPARTAMENTO(3)\n\n DEPENDENTE(4)\n\n TRABALHA_EM(5)\n\n RETORNAR AO MENU PRINCIPAL(6)\n\n SAIR(7)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : new_emp();
			break;
	
			case 2 :new_prjct();
			break;
			
			case 3 : new_depto();
			break;
	
			case 4 : new_dependent();
			break;
	
			case 5 : new_works_on();
			break;

			case 6 : back();
			break;
	
			case 7 : exit();
			break;

			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/

void alt_works_on (void)
{
	MYSQL *conn;
	int res1, ssn, no, hrs;
	char entry[201];
	printf("\nSSN do Empregado: ");
	scanf("%d",&ssn);
	printf("\nNo Projeto: ");
	scanf("%d",&no);
	printf("\nInforme total de horas trabalhadas: ");
	scanf("%d",&hrs);
	
	sprintf(entry,"UPDATE WORKS_ON SET HRS=%d WHERE SSN=%d AND NUMBER=%d",hrs,ssn,no);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}

/*============================================================*/
void alt_Dependent_ssn (int new_ssn, int old_ssn)
{
	MYSQL *conn;
	int res1;
	char entry[201];
	sprintf(entry,"UPDATE DEPENDENTS SET EMPLOYEE_SSN=%d WHERE EMPLOYEE_SSN=%d",new_ssn, old_ssn);
	
	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));

}
/*============================================================*/
void alt_dependent_name (void)
{
	MYSQL *conn;
	int res1, no;
	char name[46],entry[201], neo[51];
	printf("\nSSN do Empregado: ");
	scanf("%d",&no);
	printf("\nNome Antigo do Dependente: ");
	scanf("%s",name);
	printf("\nNovo nome: ");
	scanf("%s",neo);
	
	sprintf(entry,"UPDATE DEPENDENTS SET Name='%s' WHERE EMPLOYEE_SSN=%d AND Name='%s'",neo,no,name);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void alt_dependent_relationship (void)
{
	MYSQL *conn;
	int res1, no;
	char rltshp[46],entry[201], name[51];
	
	printf("\nSSN do Empregado: ");
	scanf("%d",&no);
	printf("\nNome do Dependente: ");
	scanf("%s",name);
	
	printf("\nRelacionamento: ");
	scanf("%s",rltshp);
	sprintf(entry,"UPDATE DEPENDENTS SET Relationship='%s' WHERE EMPLOYEE_SSN=%d AND Name='%s'",rltshp,no,name);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/

void alt_dependent_bdate (void)
{
	MYSQL *conn;
	int res1, no;
	char bdate[11],entry[201], name[51];
	printf("\nSSN do Empregado: ");
	scanf("%d",&no);
	printf("\nNome do Dependente: ");
	scanf("%s",name);
	
	
	printf("\nBirthdate(aaaa-mm-dd): ");
	scanf("%s",bdate);
	sprintf(entry,"UPDATE DEPENDENTS SET Birthdate='%s' WHERE EMPLOYEE_SSN=%d AND Name='%s'",bdate,no,name);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void alt_depto_name (void)
{
	MYSQL *conn;
	int res1, no;
	char name[46],entry[201];
	printf("\nNo do Departamento: ");
	scanf("%d",&no);
	
	printf("\nNovo nome: ");
	scanf("%s",name);
	sprintf(entry,"UPDATE DEPARTMENT SET Name='%s' WHERE Number=%d",name,no);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void alt_depto_local (void)
{
	MYSQL *conn;
	int res1, no;
	char whr[301],entry[401];
	printf("\nNo do Departamento: ");
	scanf("%d",&no);
	
	printf("\nNovo endereço: ");
	scanf("%s",whr);
	sprintf(entry,"UPDATE DEPARTMENT SET Location='%s' WHERE Number=%d",whr,no);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void alt_depto_no(void)
{
	MYSQL *conn;
	int res1,no1,no2;
	char entry[201];
	
	printf("\nNo antigo do Departamento: ");
	scanf("%d",&no1);
	printf("\nNo novo do Departamento: ");
	scanf("%d",&no2);
	sprintf(entry,"UPDATE DEPARTMENT SET Number=%d WHERE Number=%d",no2,no1);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));

}
/*============================================================*/
void alt_depto(void)
{
	int op;

	for(;;)
	{
		printf(" \nALTERAR DEPTO:\n\n NOME(1)\n\n NUMERO(2)\n\n LOCAL(3)\n\n RETORNAR AO MENU PRINCIPAL(4)\n\n SAIR(5)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : alt_depto_name();
			break;
	
			case 2 : alt_depto_no();
			break;
			
			case 3 : alt_depto_local();
			break;
			
			case 4 : back();
			break;
	
			case 5 : exit();
			break;
			
			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
void alt_prjct_name (void)
{
	MYSQL *conn;
	int res1, no;
	char name[41],entry[201];
	printf("\nNo do Projeto: ");
	scanf("%d",&no);
	
	printf("\nNovo nome: ");
	scanf("%s",name);
	sprintf(entry,"UPDATE PROJECT SET Name='%s' WHERE Number=%d",name,no);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void alt_prjct_no(void)
{
	MYSQL *conn;
	int res1,no1,no2;
	char entry[201];
	
	printf("\nNo antigo do Projeto: ");
	scanf("%d",&no1);
	printf("\nNo novo do Projeto: ");
	scanf("%d",&no2);
	sprintf(entry,"UPDATE PROJECT SET Number=%d WHERE Number=%d",no2,no1);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));

}
/*============================================================*/
void alt_prjct_local(void)
{	
	MYSQL *conn;
	int res1,nop,nol;
	char entry[201];
	
	printf("\nNo do Projeto: ");
	scanf("%d",&nop);
	printf("\nNo do novo Local: ");
	scanf("%d",&nol);
	sprintf(entry,"UPDATE PROJECT SET Location=%d WHERE Number=%d",nol,nop);

	conn=connection(conn);
	res1 = mysql_query(conn,entry);
	
	if (!res1) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/

void alt_emp_sex(void)
{
	MYSQL *conn;
	int res,ssn;
	char entry[151],sex[2];
	
	printf("\nInforme SSN: ");
	scanf("%d",&ssn);
	printf("\nNovo sexo: ");
	scanf("%s",sex);
				
	sprintf(entry,"UPDATE EMPLOYEE SET Sex='%s' WHERE SSN=%d",sex,ssn);
		
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));

}
/*============================================================*/
void alt_emp_mny(void)
{
	MYSQL *conn;
	int res,ssn;
	float mny;
	char entry[151];
	
	printf("\nInforme SSN: ");
	scanf("%d",&ssn);
	printf("\nNovo salario: ");
	scanf("%f",&mny);
				
	sprintf(entry,"UPDATE EMPLOYEE SET Salary=%f WHERE SSN=%d",mny,ssn);
		
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));

}
/*============================================================*/
void alt_emp_name(void)
{
	MYSQL *conn;
	int res1,res2,res3,ssn;
	char nfname[21],nmname[21],nlname[21],entry1[301],entry2[301],entry3[301];
	printf("\nInforme: SSN: ");
	scanf("%d",&ssn);
	
	printf("\nNovo Primeiro nome: ");
	scanf("%s",nfname);
	printf("\nNovo Nome do meio: ");
	scanf("%s",nmname);
	printf("\nNovo Sobrenome: ");
	scanf("%s",nlname);
				
	sprintf(entry1,"UPDATE EMPLOYEE SET Fname='%s' WHERE SSN=%d",nfname,ssn);
	sprintf(entry2,"UPDATE EMPLOYEE SET Mname='%s' WHERE SSN=%d",nmname,ssn);
	sprintf(entry3,"UPDATE EMPLOYEE SET Lname='%s' WHERE SSN=%d",nlname,ssn);
	
	conn=connection(conn);
	res1 = mysql_query(conn,entry1);
	res2 = mysql_query(conn,entry2);
	res3 = mysql_query(conn,entry3);
	
	if (!res1||!res2||!res3) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}	
/*============================================================*/
void alt_emp_ssn(void)
{
	MYSQL *conn;
	int res,ssn,nssn;
	char entry[151];
	
	printf("\nInforme Antigo SSN: ");
	scanf("%d",&ssn);
	printf("\nInforme Novo SSN: ");
	scanf("%d",&nssn);
				
	sprintf(entry,"UPDATE EMPLOYEE SET SSN=%d WHERE SSN=%d",nssn,ssn);
		
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));

	alt_Dependent_ssn(nssn,ssn);
}	
/*============================================================*/
void alt_emp_bdate(void)
{	
	MYSQL *conn;
	int res,ssn;
	char bdate[11], entry[151];
	
	printf("\nInforme SSN: ");
	scanf("%d",&ssn);
	printf("\nData de nascimento: ");
	scanf("%s",bdate);
	
	sprintf(entry,"UPDATE EMPLOYEE SET Bdate='%s' WHERE SSN=%d",bdate,ssn);
		
	conn=connection(conn);
	res = mysql_query(conn,entry);
	
	if (!res) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));


}
/*============================================================*/
void alt_emp_add(void)
{
	MYSQL *conn;
	int res1,res2,res3,res4,res5,res6,ssn,no,zip;
	char entry1[101],entry2[101],entry3[101],entry4[101],entry5[101],entry6[101],st[31],comp[11],city[21],uf[21];
	printf("\nInforme: SSN: ");
	scanf("%d",&ssn);
	
	printf("\nNovo Endereço:\n ");
	printf("\nRua: ");
	scanf("%s",st);
	printf("\nNo: ");
	scanf("%d",&no);
	printf("\nComplemento: ");
	scanf("%s",comp);
	printf("\nCidade: ");
	scanf("%s",city);
	printf("\nEstado: ");
	scanf("%s",uf);
	printf("\nZIPcode: ");
	scanf("%d",&zip);
		
	sprintf(entry1,"UPDATE EMPLOYEE SET Street='%s' WHERE SSN=%d",st,ssn);
	sprintf(entry2,"UPDATE EMPLOYEE SET Number='%d' WHERE SSN=%d",no,ssn);
	sprintf(entry3,"UPDATE EMPLOYEE SET Comp='%s' WHERE SSN=%d",comp,ssn);
	sprintf(entry4,"UPDATE EMPLOYEE SET City='%s' WHERE SSN=%d",city,ssn);
	sprintf(entry5,"UPDATE EMPLOYEE SET State='%s' WHERE SSN=%d",uf,ssn);
	sprintf(entry6,"UPDATE EMPLOYEE SET Zipcode='%d' WHERE SSN=%d",zip,ssn);
	
	conn=connection(conn);
	res1 = mysql_query(conn,entry1);
	res2 = mysql_query(conn,entry2);
	res3 = mysql_query(conn,entry3);
	res4 = mysql_query(conn,entry4);
	res5 = mysql_query(conn,entry5);
	res6 = mysql_query(conn,entry6);

	if (!res1||!res2||!res3||!res4||!res5||!res6) 
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void alt(void)
{
	int op;

	for(;;)
	{
		printf(" \nALTERAR EM:\n\n EMPREGADO(1)\n\n PROJETO(2)\n\n DEPARTAMENTO(3)\n\n DEPENDENTES(4)\n\n TRABALHA_EM(5)\n\n RETORNAR AO MENU PRINCIPAL(6)\n\n SAIR(7)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : alt_emp();
			break;
	
			case 2 : alt_prjct();
			break;
			
			case 3 : alt_depto();
			break;
	
			case 4 : alt_dependent();
			break;
			
			case 5 : alt_works_on();
			break;
				
			case 6 : back();
			break;
	
			case 7 : exit();
			break;

			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
void alt_emp(void)
{
	int op;

	for(;;)
	{
		printf(" \n\n ALTERAR:\n\n NOME(1)\n\n SSN(2)\n\n DATA_NASCIMENTO(3)\n\n ENDEREÇO(4) \n\n SALARIO(5) \n\n SEXO(6) \n\n RETORNAR AO MENU PRINCIPAL(7)\n\n SAIR(8)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : alt_emp_name();
			break;
	
			case 2 : alt_emp_ssn();
			break;
			
			case 3 : alt_emp_bdate();
			break;
			
			case 4 : alt_emp_add();
			break;
	
			case 5 : alt_emp_mny();
			break;
			
			case 6 : alt_emp_sex();
			break;
			
			case 7 : back();
			break;
	
			case 8 : exit();
			break;

			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
void alt_prjct(void)
{
	int op;

	for(;;)
	{
		printf(" \nALTERAR:\n\n NUMERO(1)\n\n NOME(2)\n\n LOCALIZACAO(3)\n\n RETORNAR AO MENU PRINCIPAL(4)\n\n SAIR(5)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : alt_prjct_no();
			break;
	
			case 2 : alt_prjct_name();
			break;
			
			case 3 : alt_prjct_local();
			break;
			
			case 4 : back();
			break;
	
			case 5 : exit();
			break;
			
			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
void alt_dependent(void)
{
	int op;

	for(;;)
	{
		printf(" \n\n ALTERAR DEPENDENTE:\n\n NOME(1)\n\n DATA DE NASCIMENTO(2)\n\n RELACIONAMENTO(3)\n\n RETORNAR AO MENU PRINCIPAL(4)\n\n SAIR(5)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : alt_dependent_name();
			break;
	
			case 2 : alt_dependent_bdate();
			break;
			
			case 3 : alt_dependent_relationship();
			break;
			
			case 4 : back();
			break;
	
			case 5 : exit();
			break;
			
			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
void del_works_on(void)
{	
		MYSQL *conn;
	int res, ssn, no;
	char entry[201], name[51];
	printf("\n\n SSN do Empregado:");
	scanf("%d",&ssn);
	printf("\n\n No do Projeto:");
	scanf("%d",&no);
	
	sprintf(entry,"DELETE FROM WORKS_ON WHERE SSN=%d AND NUMBER=%d",ssn,no);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void del(void)
{
	int op;

	for(;;)
	{
		printf(" \nDELETAR DE:\n\n EMPREGADO(1)\n\n PROJETO(2)\n\n DEPARTAMENTO(3)\n\n DEPENDENTES(4)\n\n TRABALHA_EM(5)\n\n RETORNAR AO MENU PRINCIPAL(6)\n\n SAIR(7)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : del_emp();
			break;
	
			case 2 :del_prjct();
			break;
			
			case 3 : del_depto();
			break;
	
			case 4 : del_dependent();
			break;
	
			case 5 : del_works_on();
			break;
	
			case 6 : back();
			break;
	
			case 7 : exit();
			break;

			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
void del_dependent(void)
{	
	MYSQL *conn;
	int res, ssn;
	char entry[201], name[51];
	printf("\n\n SSN do Empregado:");
	scanf("%d",&ssn);
	printf("\n\n Nome do dependente:");
	scanf("%s",name);
	
	sprintf(entry,"DELETE FROM DEPENDENTS WHERE EMPLOYEE_SSN=%d AND Name='%s'",ssn,name);
	
	conn=connection(conn);
	res = mysql_query(conn,entry);
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	
}
/*============================================================*/
void del_emp (void)
{
	int res;
	MYSQL *conn;
	int op;
	
	printf("Buscar por SSN[1] ou Nome[2]?");
	scanf("%d",&op);
	char entry[301];
	
	switch(op)
	{
		case 2:
			
			char fname[21];
			char mname[21];
			char lname[21];
			
			printf("\nDeletar: First name: ");
			scanf("%s",fname);
			printf("\nDeletar: Middle name: ");
			scanf("%s",mname);
			printf("\nDeletar: Last name: ");
			scanf("%s",lname);
			sprintf(entry,"DELETE FROM EMPLOYEE WHERE EMPLOYEE.Fname='%s' AND EMPLOYEE.Mname='%s' AND EMPLOYEE.Lname='%s'", fname,mname,lname);
			
			conn=connection(conn);
			res = mysql_query(conn, entry);
			break;
			
		case 1:
			
			int ssn;
			printf("\nDeletar: SSN: ");
			scanf("%d",&ssn);
			sprintf(entry,"DELETE FROM EMPLOYEE WHERE EMPLOYEE.SSN=%d",ssn);
						
			conn=connection(conn);
			res = mysql_query(conn,entry);
			break;
	};
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	
}
/*============================================================*/
void del_depto (void)
{
	int res;
	MYSQL *conn;
	int op;
	
	printf("Buscar por No[1] ou Nome[2]?");
	scanf("%d",&op);
	char entry[301];
	
	switch(op)
	{
		case 2:
			
			char name[21];
			
			printf("\nDeletar Depto:name: ");
			scanf("%s",name);
			sprintf(entry,"DELETE FROM DEPARTMENT WHERE DEPARTMENT.Name='%s'",name);
			
			conn=connection(conn);
			res = mysql_query(conn, entry);
			break;
			
		case 1:
			
			int no;
			printf("\nDeletar Depto: No: ");
			scanf("%d",&no);
			sprintf(entry,"DELETE FROM DEPARTMENT WHERE DEPARTMENT.Number=%d",no);
			
			conn=connection(conn);
			res = mysql_query(conn,entry);
			break;
	};
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));
}
/*============================================================*/
void del_prjct (void)
{
	int res;
	MYSQL *conn;
	int op;
	
	printf("Buscar por No[1] ou Nome[2]?");
	scanf("%d",&op);
	char entry[301];
	
	switch(op)
	{
		case 2:
			
			char name[21];
			
			printf("\nDeletar Projeto:name: ");
			scanf("%s",name);
			sprintf(entry,"DELETE FROM PROJECT WHERE PROJECT.Name='%s'",name);
			
			conn=connection(conn);
			res = mysql_query(conn, entry);
			break;
			
		case 1:
			
			int no;
			printf("\nDeletar Projeto: No: ");
			scanf("%d",&no);
			sprintf(entry,"DELETE FROM PROJECT WHERE PROJECT.Number=%d",no);
			conn=connection(conn);
			res = mysql_query(conn,entry);
			break;
	};
	if (!res)
		printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(conn));
	else 
		printf("Update error %d: %s\n", mysql_errno(conn), mysql_error(conn));}
/*============================================================*/
void query_menu(void)
{	
	int op, key;
	char entry[100];
	printf("\n\nPESQUISAR EM: \n\n [1] Empregados\n\n [2] Departamentos \n\n [3] Projetos \n\n [4] Dependentes \n\n [5] Retornar ao menu inicial \n\n [6] Sair \n\n  ");
	scanf ("%d", &op);
	
	switch (op){
		
		case 1: 
			printf("\n\n BUSCA POR EMPREGADO\n SSN: ");
			scanf("%d",&key);
			printf("\n\n\tSSN\tBdate\t\tFname\tMname\tLname\tSex\tSt.\t\tNo\tComp.\tCity\tZIP\tState\tSalary\tSuperv.SSN\n\n");
			sprintf(entry,"SSN=%d", key);
			query("EMPLOYEE",entry);
			break;
		
		case 2:
			printf("\n\n BUSCA POR DEPARTAMENTO\n No do Depto: ");
			scanf("%d",&key);
			sprintf(entry,"Number=%d", key);
			printf("\n\n\tNumber\tName\t\tLocation\n\n");
			query("DEPARTMENT", entry);
			break;
		
		case 3:
			printf("\n\n BUSCA POR PROJETO\n No do Projeto: ");
			scanf("%d",&key);
			sprintf(entry,"Number=%d", key);
			printf("\n\n\tNumber\tName\t\tLocation\n\n");
			query("PROJECT",entry);
			break;
		
		case 4:
			printf("\n\n BUSCA POR DEPENDENTES\n SSN do empregado: ");
			scanf("%d",&key);
			sprintf(entry,"EMPLOYEE_SSN=%d", key);
			printf("\n\n\tEmpSSN\tSex\tBdate\t\tRelacao\tNome\n\n");
			query("DEPENDENTS", entry);
			break;
		
		case 5: back();
		break;
		
		case 6: exit();
		break;
	}
}

/*============================================================*/
void query(char where[501], char condition[501])
{
	MYSQL my_connection;
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	int res;
	char entry[901];
				
	mysql_init(&my_connection);
	
	if (mysql_real_connect(&my_connection, "localhost", "trevizani", "cats", "dbt1", 0, NULL, 0)) 
	{
	/*printf("Connection success\n"); DEBUG TOOL*/
		
		sprintf(entry,"SELECT* from %s where %s",where,condition);
		res = mysql_query(&my_connection, entry);
		
		if (res) 
			printf("SELECT error: %s\n", mysql_error(&my_connection));
		else {
			res_ptr = mysql_store_result(&my_connection);
			
			if (res_ptr) {
				while ((sqlrow = mysql_fetch_row(res_ptr))) {
    					for (unsigned int row=0; row< mysql_field_count(&my_connection); row++) 
						printf("\t%s", sqlrow[row]);
    					printf("\n\n");
				};
				if (mysql_errno(&my_connection)) 
					printf("Retrive error: %s\n", mysql_error(&my_connection));	  
			}
			mysql_free_result(res_ptr);
		}
		mysql_close(&my_connection);
	}
	
	else 
		printf("Connection failed\n");
	if (mysql_errno(&my_connection))
		printf("Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
}
/*============================================================*/
void report_menu()
{
	int op;
	
	printf("\n\nGERAR RELATÓRIO: \n\n[1] Empregados e Salario\n\n[2] Departamentos\n\n[3] Projetos\n\n[4] Dependentes e Empregados\n\n[5] Pessoas e Departamentos por Projeto\n\n[6] Empregados do Depto\n\n[7] Empregados por Supervisor\n\n   :  ");
	scanf("%d",&op);
	printf("\n\n");
	
	switch(op)
	{
		case 1: 
			printf("\tNAME\t\t\tSALARY\n\n"); 
			report("Fname, Mname, Lname, Salary","EMPLOYEE");
			
			break;
		
		case 2: 
			printf("\tNUMBER\tNAME\tLOCATION\n\n"); 
			report("*","PROJECT");
			
			break;
		
		case 3: 
			printf("\tNUMBER\tNAME\t\tLOCATION\t\t\t\tNoEMPLOYEES\n\n"); 
			report("*","DEPARTMENT");
			
			break;
		
		case 4:
			char name_employee[31], entry[501]; 
						
			printf("\tÚLTIMO NOME DO EMPREGADO: ");
			scanf("%s",name_employee);
			sprintf(entry,"DEPENDENTS JOIN EMPLOYEE ON (EMPLOYEE.SSN=DEPENDENTS.EMPLOYEE_SSN AND EMPLOYEE.Lname='%s')",name_employee);
			printf("\n\nDEPENDENTES DE %s\n\n",name_employee);
			printf("\tNome\tRelacion.\n\n");		/*  \t 4 full names  */
			report("DEPENDENTS.Name, DEPENDENTS.Relationship", entry) ;
			
			break;
			
		case 5:
			printf("\tEmpregado\t\tProjeto\n\n\n");
			report("EMPLOYEE.Fname,EMPLOYEE.Mname, EMPLOYEE.Lname, PROJECT.Name", "EMPLOYEE,PROJECT WHERE PROJECT.Location=EMPLOYEE.Number");
			printf("\n\n");
			printf("\tDepartamento\tProjeto\n\n\n");
			report("DEPARTMENT.Name, PROJECT.Name", "DEPARTMENT,PROJECT WHERE PROJECT.Location=DEPARTMENT.Number") ;
			printf("\n\n");
			break;

		case 6:
			char name_depto[51], entry2[501]; 
						
			printf("\tNOME DO DEPARTAMENTO: ");
			scanf("%s",name_depto);
			sprintf(entry2,"EMPLOYEE,DEPARTMENT WHERE (EMPLOYEE.Number=DEPARTMENT.Number AND DEPARTMENT.Name='%s')",name_depto);
			printf("\n\n\tEmpregados de %s\n\n", name_depto);
			report("EMPLOYEE.Fname,EMPLOYEE.Mname,EMPLOYEE.Lname", entry2);
	
			break;	
		
		case 7:
			char entry3[501]; 
			int boss;			
			
			printf("\tSSN DO SUPERVISOR: ");
			scanf("%d",&boss);
			sprintf(entry3,"EMPLOYEE WHERE SUPERVISOR=%d",boss);
			printf("\n\n\tEmpregados sob supervisão\n\n");
			report("Fname,Mname,Lname", entry3);
	
			break;	
	
	}
	
}


void report(char what[301], char where[501])
{
	MYSQL my_connection;
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	int res;
	char entry[901];
				
	mysql_init(&my_connection);
	
	if (mysql_real_connect(&my_connection, "localhost", "trevizani", "cats", "dbt1", 0, NULL, 0)) 
	{
/* 		printf("Connection success\n"); DEBUG TOOL*/
		
		sprintf(entry,"SELECT %s from %s",what,where);
		res = mysql_query(&my_connection, entry);
		
		if (res) 
			printf("SELECT error: %s\n", mysql_error(&my_connection));
		else {
			res_ptr = mysql_store_result(&my_connection);
			
			if (res_ptr) {
				while ((sqlrow = mysql_fetch_row(res_ptr))) {
    					for (unsigned int row=0; row< mysql_field_count(&my_connection); row++) 
						printf("\t%s", sqlrow[row]);
    					printf("\n\n");
				};
				if (mysql_errno(&my_connection)) 
					printf("Retrive error: %s\n", mysql_error(&my_connection));	  
			}
			mysql_free_result(res_ptr);
		}
		mysql_close(&my_connection);
	}
	
	else 
		printf("Connection failed\n");
	if (mysql_errno(&my_connection))
		printf("Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
	
}
/*============================================================*/
void exit (void)
{
	printf("\nBye\n\n");
	exit(1);
}
/*============================================================*/
void back (void)
{
	menu_inicial();
	return;
}
/*============================================================*/
void menu_inicial(void)
{
	int op;
	
	for(;;)
	{
		printf(" \nO QUE FAZER?\n\n INCLUIR(1)\n\n ALTERAR(2)\n\n DELETAR(3)\n\n PESQUISAR(4)\n\n GERAR RELATÓRIO(5)\n\n SAIR(6)\n\n");
	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : include();
			break;
	
			case 2 :alt();
			break;
			
			case 3 : del();
			break;
	
			case 4 : query_menu();
			break;
	
			case 5 : report_menu();
			break;

			case 6: exit();
			break;

			default : printf("\n Ops! Opção inválida!\n");
			break;
		}
	}
	return;
}
/*============================================================*/
MYSQL* connection(MYSQL *conn)
{
	conn= mysql_init(NULL);
	if (!conn){
		fprintf(stderr, "mysql_init failed\n");
		return NULL;
	};
	
	conn = mysql_real_connect(conn, "localhost", "trevizani", "cats", "dbt1", 0, NULL, 0);
	if (conn){
		printf("Connection success\n");
	} 
	else {
		printf("Connection failed\n");
	}
	return conn;
}

