#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>

const int OK=1;
const int ERROR=0;
const int TRUE=1;
const int FALSE=0;
const int MAX_LENGTH_INSERT_SORT=7;
const int MAXSIZE=10000;  // 用于要排序数组个数最大值，可根据需要修改

typedef int Status; 
class SqList {
    public:
        SqList(){
            int r[MAXSIZE+1]={0};
            int length=0;
        }
        void swap(int i,int j){
            int temp=this->r[i]; 
            this->r[i]=this->r[j]; 
            this->r[j]=temp; 
        }
        void print(){
            int i=0;
            for(i=1;i<this->length;++i){
                std::cout<<this->r[i]<<",";
            }
            std::cout<<this->r[i]<<"\n";
        }

    public:
        int r[MAXSIZE+1];	// 用于存储要排序数组，r[0]用作哨兵或临时变量 
        int length;			// 用于记录顺序表的长度 
};


//对顺序表L作交换排序（冒泡排序初级版）
void BubbleSort0(SqList *L){ 
    for(int i=1;i<L->length;++i){
        for(int j=i+1;j<=L->length;++j){
            if(L->r[i]>L->r[j]){
                L->swap(i,j);/* 交换L->r[i]与L->r[j]的值 */
            }
        }
    }
}

// 对顺序表L作冒泡排序 
void BubbleSort(SqList *L){ 
    for(int i=1;i<L->length;++i){
        for(int j=L->length;j>i;--j){  // 注意j是从后往前循环
            if(L->r[j]<L->r[j-1]){ 
                L->swap(j,j-1);
            }
        }
    }
}

// 对顺序表L作改进冒泡算法
void BubbleSort2(SqList *L){ 
    Status flag=TRUE;			// flag用来作为标记 
    for(int i=1;i<L->length && flag;++i){ // 若flag为true说明有过数据交换，否则停止循环 
        flag=FALSE;				// 初始为False 
        for(int j=L->length;j>i;--j){
            if(L->r[j]<L->r[j-1]){
                L->swap(j,j-1);	// 交换L->r[j]与L->r[j+1]的值 
                flag=TRUE;		// 如果有数据交换，则flag为true 
            }
        }
    }
}


// 对顺序表L作简单选择排序 
void SelectSort(SqList *L){
    for(int i=1;i<L->length;++i){ 
        int min = i;					   	//将当前下标定义为最小值下标 
        for (int j = i+1;j<L->length+1;++j){  // 循环之后的数据
            if (L->r[min]>L->r[j])	     // 如果有小于当前最小值的关键字 
                min = j;				// 将此关键字的下标赋值给min 
        }
        if(i!=min)						// 若min不等于i，说明找到最小值，交换 
            L->swap(i,min);				// 交换L->r[i]与L->r[min]的值 
    }
}

// 对顺序表L作直接插入排序 
void InsertSort(SqList *L){ 
    int j=0;
    for(int i=2;i<=L->length;++i){
        if (L->r[i]<L->r[i-1]){ // 需将L->r[i]插入有序子表 
            L->r[0]=L->r[i]; // 设置哨兵
            for(j=i-1;L->r[j]>L->r[0];--j)
                L->r[j+1]=L->r[j]; // 记录后移 
            L->r[j+1]=L->r[0]; // 插入到正确位置 
        }
    }
}


int main(){
   //int d[]={9,1,5,8,3,7,4,6,2}; 
   //int d[]={50,10,90,30,70,40,80,60,20,30};
    int d[]={9,8,7,6,5,4,3,2,1}; 
   
   int N = sizeof(d)/sizeof(int);
   SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
   
   for(int i=0;i<N;++i)
     l0.r[i+1]=d[i];

   l0.length=N;
   l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
   std::cout<<"排序前:\n";
   l0.print();

   std::cout<<"\n初级冒泡排序:\n";
   BubbleSort0(&l0);
   l0.print();
   
   std::cout<<"\n冒泡排序:\n";
   BubbleSort(&l1);
   l1.print();
   
   std::cout<<"\n改进冒泡排序:\n";
   BubbleSort2(&l2);
   l2.print();
   
   std::cout<<"\n简单选择排序:\n";
   SelectSort(&l3);
   l3.print();

   std::cout<<"\n直接插入排序:\n";
   InsertSort(&l4);
   l4.print();
/*
   printf("希尔排序:\n");
   ShellSort(&l5);
   print(l5);
	
   printf("堆排序:\n");
   HeapSort(&l6);
   print(l6);

   printf("归并排序（递归）:\n");
   MergeSort(&l7);
   print(l7);

   printf("归并排序（非递归）:\n");
   MergeSort2(&l8);
   print(l8);

   printf("快速排序:\n");
   QuickSort(&l9);
   print(l9);

   printf("改进快速排序:\n");
   QuickSort1(&l10);
   print(l10);

*/
    /*大数据排序*/
	/* 
	srand(time(0));  
	int Max=10000;
	int d[10000];
	int i;
	SqList l0;
	for(i=0;i<Max;i++)
		d[i]=rand()%Max+1;
	for(i=0;i<Max;i++)
		l0.r[i+1]=d[i];
	l0.length=Max;
	MergeSort(l0);
	print(l0);
	*/
	return 0;
}
