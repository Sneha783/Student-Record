#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct std
{
int rl;
char name[15];
float mrk;
struct std *nwad;
}SR;
SR *hp=0;
void name();
void roll();
void marks();
void menu(void);
void add_rec(void);
void exit_fun(void);
void save(void);
void rev(void);
void del_all(void);
void sort(void);
void modify(void);
void show(void);
void del();
int count();
char pas[10]="sneha31",id[15]="sneha_shinde";
main()
{
char ch,ch3;
int chance=0,chance2=0;
l:chance++;
system("clear");
printf("\t\t\t _______________________________________________________________________\n");
printf("\t\t\t|      ****************** STUDENT RECORD MENU ********************      |\n");
printf("\t\t\t|  -------------------------------------------------------------------  |\n");
printf("\t\t\t|  a/A : Add new record                                                 |\n");
printf("\t\t\t|  d/D : Delete a record					        |\n"); 
printf("\t\t\t|  s/S : show the list					       	        |\n");
printf("\t\t\t|  m/M : Modify a record					        |\n");	
printf("\t\t\t|  v/V : Save							        |\n"); 
printf("\t\t\t|  e/E : Exit 							        |\n");
printf("\t\t\t|  t/T : Sort the list						        |\n");
printf("\t\t\t|  l/L : Delete all records					        |\n"); 
printf("\t\t\t|  r/R : Reverse the list					        |\n");
printf("\t\t\t|_______________________________________________________________________|\n\n");
printf("\n\t\t\t  Enter your choice   : ");
scanf(" %c",&ch);
switch(ch)
{
case 'a' :add_rec();     
          break;
case 'A' :add_rec();
	  break;
case 'd' :del();
	break;
case 'D' :del();
	break;
case 's' :show();
	break;
case 'S' :show();
	break;
case 'm' :modify();
	break;
case 'M' :modify();
	break;
case 'v' :save();
	break;
case 'V' :save();
	break;
case 'e' :exit_fun();
	goto e;
	break;
case 'E' :exit_fun();
	goto e;
	break;
case 't' :sort();
	break;
case 'T' :sort();
	break;
case 'l' :del_all();
	break;
case 'L' :del_all();
	break;
case 'r' :rev();
	break;
case 'R' :rev();
	break;
default:printf("Enter valied choice \n");
        if(chance<3)
        goto l;
}
lk:chance2++;
printf("\n\t\t\t\t\t\tBack or Exit (b/e) : ");
scanf(" %c",&ch3);
switch(ch3)
{
case 'b' :goto l;
	break;
case 'e' :goto e;
	break;
default :printf("\n\t\t\tEnter valied option \n");
	if(chance2<2)
	goto lk;
}
e:system("clear");
printf("\n\t\t---------------------------------------------------------------------------------------------------------");
printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s\n\n",__DATE__,__TIME__);
printf("\n\n\t\t\t\t\t\t' HAVE A GOOD DAY ! '\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\tCopyRight:@sneha_shinde\n\n\n\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void exit_fun()
{
return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void save()
{
FILE *fp;
SR *tmp;
tmp=hp;
fp=fopen("STDREC","w+");
fprintf(fp,"___________________________________________________________________\n");
fprintf(fp,"\tRoll no.\t Name\t Marks\n");
fprintf(fp,"___________________________________________________________________\n");
while(tmp)
{
fprintf(fp,"\t %d\t\t%s\t\t%f%%\n",tmp->rl,tmp->name,tmp->mrk);
tmp=tmp->nwad;
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rev()
{
SR *tmp=hp;
int c,m,n;
c=count();
system("clear");
printf("\n\t\t---------------------------------------------------------------------------------------------------------");
printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s\n\n",__DATE__,__TIME__);
printf("\t\t_______________________________________________________________________________________\n");
printf("\t\t  Roll No.\t\tName\t\t\tMarks\n");
printf("\t\t_______________________________________________________________________________________\n");

while(tmp)
{
printf("\t\t    %d\t\t\t%s\t\t\t%f%% \n",tmp->rl,tmp->name,tmp->mrk);
printf("\t\t_______________________________________________________________________________________\n");
tmp=tmp->nwad;
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void del_all()
{
SR *tmp,*t;
int n;
tmp=hp;
hp=0;
while(tmp)
{
t=tmp;
free(tmp);
tmp=t->nwad;
}
printf("\n\n\n\t\t\t\t\t\tWait");
for(n=0;n<3;n++)
{
printf(".");
sleep(1);
fflush(stdout);
}
printf("Data deleted successfully........\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort()
{
int op;
SR *tmp;
tmp=hp;
system("clear");
printf("\n\t\t---------------------------------------------------------------------------------------------------------");
printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s",__DATE__,__TIME__);
printf("\n\n\t\t\t\t\t--------MENU------- \n\n");
printf("\t\t\t\t*******************************************************\n\n");
printf("\t\t\tSort by :\n\t\t\t1) Name\n\t\t\t2) Rollno.\n\t\t\t3) Marks\n");
printf("\n\t\t\tEnter option : ");
scanf("%d",&op);
switch(op)
{
case 1:name();
	break;
case 2:roll();
	break;
case 3:marks();
	break;
default :printf("\t\t\tEnter valied option !!!!!!!\n");	
}
}

//------------------------------name--------------------------------
void name()
{
         SR *sw=hp,*lsw,*p=hp,t;
         int m,n,tmp,c;
         c=count();
 
for(m=0;m<c;m++)
{
lsw=hp;
for(n=0;n<c-1;n++)
{
if(strcmp(lsw->name,sw->name)<0)
{ 
strcpy(t.name,sw->name);
strcpy(sw->name,lsw->name);
strcpy(lsw->name,t.name);
//---------rl.no
t.rl=sw->rl;
sw->rl=lsw->rl;
lsw->rl=t.rl;
//----------mark
t.mrk=sw->mrk;
sw->mrk=lsw->mrk;
lsw->mrk=t.mrk;
}
lsw=lsw->nwad;
}
sw=sw->nwad;
}

}
//-----------------------------roll no-------------------------------
void roll()
{

SR *sw=hp,*lsw,*p=hp,t;
int m,n,tmp,c;
c=count(); 
for(m=0;m<c;m++)
{
lsw=hp;
for(n=0;n<c-1;n++)
{
if(lsw->rl<sw->rl)
{ 
strcpy(t.name,sw->name);
strcpy(sw->name,lsw->name);
strcpy(lsw->name,t.name);
//---------rl.no
t.rl=sw->rl;
sw->rl=lsw->rl;
lsw->rl=t.rl;
//----------mark
t.mrk=sw->mrk;
sw->mrk=lsw->mrk;
lsw->mrk=t.mrk;
}
lsw=lsw->nwad;
}
sw=sw->nwad;
}

}
//--------------------------marks-------------------------------------
void marks()
{

SR *sw=hp,*lsw,*p=hp,t;
         int m,n,tmp,c;
         c=count();
 
for(m=0;m<c;m++)
{
lsw=hp;
for(n=0;n<c-1;n++)
{
if(lsw->mrk>sw->mrk)
{ 
strcpy(t.name,sw->name);
strcpy(sw->name,lsw->name);
strcpy(lsw->name,t.name);
//---------rl.no
t.rl=sw->rl;
sw->rl=lsw->rl;
lsw->rl=t.rl;
//----------mark
t.mrk=sw->mrk;
sw->mrk=lsw->mrk;
lsw->mrk=t.mrk;
}
lsw=lsw->nwad;
}
sw=sw->nwad;
}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modify()
{
	SR *tmp=hp;
	int m,num,n;
	char *p,ps[10]="sneha31",t[15],id[15]="sneha_shinde";

	system("clear");
ppp:
	printf("\n\t\t---------------------------------------------------------------------------------------------------------");
	printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s",__DATE__,__TIME__);
	printf("\n\n\n\t\t\t\t\tEnter Admin ID : ");
	scanf("%s",t);
	p=getpass("\n\t\t\t\t\tEnter password : ");

	printf("\n\n\n\t\t\t\t\t\tLoading");
	for(n=0;n<3;n++)
	{
		printf(".");
		sleep(1);
		fflush(stdout);
	}
	if((strstr(ps,p)!=0) && (strstr(id,t)!=0))
	{
		printf("\n\t\t---------------------------------------------------------------------------------------------------------");
		printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s",__DATE__,__TIME__);
		printf("\n\n\t\t\t\t\tEnter roll no to modify : ");
		scanf("%d",&num);
		while(tmp)
		{
			if(tmp->rl==num)
			{
				printf("Enter Name : ");
				scanf("%s",tmp->name);
				printf("Enter Marks : ");
				scanf("%f",&tmp->mrk);
			}
			tmp=tmp->nwad;
		}
	}
	else
	{
		printf("Invalied username or password\n");
		goto ppp;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void del()
{
	SR *tmp=hp,*t;
	int num,n;
	printf("Enter roll no to delete : ");
	scanf("%d",&num);
	while(tmp)
	{
		if(tmp->rl==num)
		{
			if(tmp==hp)
			{
				hp=tmp->nwad;
			}
			else
			{
				t->nwad=tmp->nwad;
			}
			free(tmp);
			goto last;
}
t=tmp;
tmp=tmp->nwad;
}

last: printf("\n\n\n\t\t\t\t\t\tWait");
for(n=0;n<3;n++)
{
printf(".");
sleep(1);
fflush(stdout);
}
printf("\n\t\t\t\t\t\tData deleted successfully........\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_rec()
{
char ch2,*p,t[15];
int m=0,n,k;
SR *tmp;
passwrd:m++;
system("clear");
printf("\n\t\t---------------------------------------------------------------------------------------------------------");
printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s",__DATE__,__TIME__);
printf("\n\n\n\t\t\t\t\tEnter Admin ID : ");
scanf("%s",t);
p=getpass("\n\t\t\t\t\tEnter password : ");

printf("\n\n\n\t\t\t\t\t\tLoading");
for(n=0;n<3;n++)
{
printf(".");
sleep(1);
fflush(stdout);
}
printf("\n\n\n");
if((strstr(p,pas)!=0) && (strstr(t,id)!=0))
{
system("clear");
printf("\n\t\t---------------------------------------------------------------------------------------------------------");
printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s\n\n",__DATE__,__TIME__);
do
{
SR *mp=malloc(sizeof(SR));
rlno:
printf("\t\t\t\t_____________________________________________\n\n");
printf("\t\t\t\t\t\tRoll no. : ");
scanf("%d",&mp->rl);
tmp=hp;

if(tmp==0)
{
if(mp->rl<0)
{
printf("\t\t\t\t\tRoll no. can not be negative...\n");
goto rlno;
}
}
while(tmp)
{
if(tmp->rl==mp->rl)
{
printf("\t\t\t\t\tRoll no. is repeated enter valied.....\n\n");
goto rlno;
}
if(mp->rl<0)
{
printf("\t\t\t\t\tRoll no. can not be negative...\n");
goto rlno;
}
tmp=tmp->nwad;
}
printf("\n\t\t\t\t\t\tEnter Name : ");
scanf("%s",mp->name);
printf("\n\t\t\t\t\t\tEnter Marks : ");
scanf("%f",&mp->mrk);
printf("\n\t\t\t\t___________________________________________\n");
mp->nwad=hp;
hp=mp;
printf("\n\n\t\t\tWant to enter another rec (y/n) : ");                 
scanf(" %c",&ch2);
}while(ch2=='y' || ch2=='Y');
}
else 
{
printf("\n\n\t\t\t\tWrong ID or password !!!\n");
if(m<3)
goto passwrd;
return;
}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        	
void show()
{
SR *tmp=hp;
int c,m,n;
c=count();
system("clear");
printf("\n\t\t---------------------------------------------------------------------------------------------------------");
printf("\n\n\n\t\t\t%s\t\t\t\t\t\t\t%s\n\n",__DATE__,__TIME__);
printf("\t\t_______________________________________________________________________________________\n");
printf("\t\t  Roll No.\t\tName\t\t\tMarks\n");
printf("\t\t_______________________________________________________________________________________\n");

for(m=0;m<c;m++)
{
tmp=hp;
for(n=0;n<c-1-m;n++)
tmp=tmp->nwad;
printf("\t\t    %d\t\t\t%s\t\t\t%f%% \n",tmp->rl,tmp->name,tmp->mrk);
printf("\t\t_______________________________________________________________________________________\n");
}
}
#if 0
while(tmp)
{
printf("\t\t    %d\t\t\t%s\t\t\t%f%% \n",tmp->rl,tmp->name,tmp->mrk);
printf("\t\t_______________________________________________________________________________________\n");
tmp=tmp->nwad;
}
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int count()
{
SR *tmp=hp;
int c=0;
while(tmp)
{
c++;
tmp=tmp->nwad;
}
return c;
}
