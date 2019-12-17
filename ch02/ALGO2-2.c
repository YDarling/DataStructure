/* algo2-2.c 实现算法2.2的程序 */
#include<string.h>
#include<ctype.h>
#include<malloc.h>					/* malloc()等 */
#include<limits.h>					/* INT_MAX等 */
#include<stdio.h>					/* EOF(=^Z或F6),NULL */
#include<stdlib.h>					/* atoi() */
#include<io.h>						/* eof() */
#include<math.h>					/* floor(),ceil(),abs() */
#include<process.h>					/* exit() */

#include "c1.h"
#include "bo2-1.c"

/* 函数结果状态代码 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1				/* #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 */



typedef int Status;					/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean;				/* Boolean是布尔类型,其值是TRUE或FALSE */
typedef int ElemType;





void MergeList(SqList La,SqList Lb,SqList *Lc){
   int i=1,j=1,k=0;
   int La_len,Lb_len;
   ElemType ai,bj;
   InitList(Lc);								/* 创建空表Lc */
   La_len=ListLength(La);
   Lb_len=ListLength(Lb);
   while(i<=La_len&&j<=Lb_len)					/* 表La和表Lb均非空 */
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
   while(i<=La_len)							/* 表La非空且表Lb空 */
   {
     GetElem(La,i++,&ai);
     ListInsert(Lc,++k,ai);
   }
   while(j<=Lb_len){							/* 表Lb非空且表La空 */
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
	 InitList(&La);								/* 创建空表La */
	 for (j = 1; j <= 2; j++) {					/* 在表La中插入4个元素 */
		 ListInsert(&La, j, a[j - 1]);
	 }
	 printf("La= ");							/* 输出表La的内容 */
	 ListTraverse(La, print);
	 InitList(&Lb);								/* 创建空表Lb */
	 for (j = 1; j <= 4; j++) {					/* 在表Lb中插入7个元素 */
		 ListInsert(&Lb, j, b[j - 1]);
	 }
	 printf("Lb= ");							/* 输出表Lb的内容 */
	 ListTraverse(Lb, print);
	 MergeList(La, Lb, &Lc);
	 printf("Lc= ");							/* 输出表Lc的内容 */
	 ListTraverse(Lc, print);
	 return 0;
 }