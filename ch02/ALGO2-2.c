/* algo2-2.c ʵ���㷨2.2�ĳ��� */
#include<string.h>
#include<ctype.h>
#include<malloc.h>					/* malloc()�� */
#include<limits.h>					/* INT_MAX�� */
#include<stdio.h>					/* EOF(=^Z��F6),NULL */
#include<stdlib.h>					/* atoi() */
#include<io.h>						/* eof() */
#include<math.h>					/* floor(),ceil(),abs() */
#include<process.h>					/* exit() */

#include "c1.h"
#include "bo2-1.c"

/* �������״̬���� */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1				/* #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ */



typedef int Status;					/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean;				/* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
typedef int ElemType;





void MergeList(SqList La,SqList Lb,SqList *Lc){
   int i=1,j=1,k=0;
   int La_len,Lb_len;
   ElemType ai,bj;
   InitList(Lc);								/* �����ձ�Lc */
   La_len=ListLength(La);
   Lb_len=ListLength(Lb);
   while(i<=La_len&&j<=Lb_len)					/* ��La�ͱ�Lb���ǿ� */
   {
     GetElem(La,i,&ai);
     GetElem(Lb,j,&bj);
     if(ai<=bj)
     {
       ListInsert(Lc,++k,ai);
       ++i;
     }
     else
     {
       ListInsert(Lc,++k,bj);
       ++j;
     }
   }
   printf("i=%d \n", i);
   printf("j=%d \n", j);
   while(i<=La_len)							/* ��La�ǿ��ұ�Lb�� */
   {
     GetElem(La,i++,&ai);
     ListInsert(Lc,++k,ai);
   }
   while(j<=Lb_len){							/* ��Lb�ǿ��ұ�La�� */
    GetElem(Lb,j++,&bj);
	printf("j=%d \n", j);
    ListInsert(Lc,++k,bj);
  }
}

void print(ElemType *c){
	printf("%d ",*c);
}


 int main() {
	 SqList La, Lb, Lc;
	 int j;
	 int a[2] = {1,2}, b[4] = {3,4,5,6};
	 InitList(&La);								/* �����ձ�La */
	 for (j = 1; j <= 2; j++) {					/* �ڱ�La�в���4��Ԫ�� */
		 ListInsert(&La, j, a[j - 1]);
	 }
	 printf("La= ");							/* �����La������ */
	 ListTraverse(La, print);
	 InitList(&Lb);								/* �����ձ�Lb */
	 for (j = 1; j <= 4; j++) {					/* �ڱ�Lb�в���7��Ԫ�� */
		 ListInsert(&Lb, j, b[j - 1]);
	 }
	 printf("Lb= ");							/* �����Lb������ */
	 ListTraverse(Lb, print);
	 MergeList(La, Lb, &Lc);
	 printf("Lc= ");							/* �����Lc������ */
	 ListTraverse(Lc, print);
	 return 0;
 }