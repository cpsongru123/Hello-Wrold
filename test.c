#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
char dic[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
bool k,z;
typedef struct SqStack{   //顺序栈
	int *base;   //栈底
	int *top;  //栈顶
	int stacksize;  //容量
}SqStack;
bool InitStack(SqStack &S){   //初始化
	S.base=new int[MAXSIZE];   //分配数组空间
	if(!S.base) exit(OVERFLOW);    //分配失败 推出
	S.top=S.base;   //初始为空栈 top=base
	S.stacksize=MAXSIZE;   //存储容量大小数据
	return OK;   //初始化成功
}
bool Push(SqStack &S,int e){   //入栈
	if(S.top-S.base==S.stacksize) return ERROR;  //判断栈满
	*S.top++=e;   //压入栈顶
	return OK;
}
bool Pop(SqStack &S,int &e){   //出栈
	if(S.base==S.top) return ERROR;   //栈空
	e=*--S.top;   //取出栈顶
	return OK;
}
int GetTop(SqStack S){   //取栈顶元素
	if(S.top!=S.base) return *(S.top-1);   //返回栈顶元素
}
int i=1;
void TraverseList(SqStack S){   //遍历栈
	if((S.top-i)==(S.base-1)) return;   //递归终止
	cout<<"The "<<i<<" elem is: "<<*(S.top-i)<<endl;
	i++;
	TraverseList(S);   //递归
}
typedef struct StackNode{   //链栈
	int data;   //元素数据
	struct StackNode *next;   //下个元素指针
}StackNode,*LinkStack;
bool InitStack2(LinkStack &S){   //初始化
	S=NULL;
	return OK;
}
bool Push2(LinkStack &S,int e){   //入栈
	LinkStack p=new StackNode;   //为新建结点指针建立新结点空间
	p->data=e;   //添加新结点数据
	p->next=S;   //新结点的下一结点为S
	S=p;   //头指针指向新结点
	return OK;
}
bool Pop2(LinkStack &S,int &e){   //出栈
	if(S==NULL) return ERROR;   //判断栈空
	LinkStack p;   //建立临时结点指针
	e=S->data;   //将元素数据赋给e
	p=S;   //将结点S临时赋给指针p 以备释放
	S=S->next;   //头指针指向下一元素
	delete p;   //释放 原栈顶
	return OK;
}
int GetTop2(LinkStack S){   //取栈顶元素
	if(S!=NULL) return S->data;   //判断空栈
}
void TraverseList2(LinkStack p){   //遍历栈
	if(p==NULL) return;   //递归终止
	cout<<p->data<<endl;   //输出数据
	TraverseList2(p->next);   //递归
}
void PopAll(SqStack &T){
	int e;
	while(Pop(T,e));
}
void PopAll(LinkStack &S){
	int e;
	while(Pop2(S,e));
}
void M();
void Menu(){
	int i;
	k=0;
	z=0;
	cout<<"Welcome to test the Stack!\n"
		<<"1.Creat a new InitStack\n"
		<<"2.Creat a new LinkStack\n"
		<<"3.Exit\n"
		<<"Please input the Key: ";
	cin>>i;
	switch(i){
	case 1:
		k=0;
		M();
		break;
	case 2:
		k=1;
		M();
		break;
	case 3:
		return;
		break;
	default:
		cout<<"Please input a correct Key!"<<endl;
		break;
	}
	Menu();
}
SqStack x;
LinkStack y=new StackNode;
void M(){
	int i,e=0;
	if(!z){
		if(!k){
			if(!InitStack(x)){
				cout<<"Created Failed!\n";
				Menu();
			}
			cout<<"InitStack succeed!"<<endl;
		}
		else{
			if(!InitStack2(y)){
				cout<<"Created Failed!\n";
				Menu();
			}
			cout<<"InitStack succeed!"<<endl;
		}
	}
	z=1;
	cout<<"1.Push\n"
		<<"2.Pop\n"
		<<"3.GetTop\n"
		<<"4.TraverseList\n"
		<<"5. 10->8\n"
		<<"6. 10->16\n"
		<<"7.Return main Menu\n"
		<<"Please input the Key: ";
	cin>>i;
	switch(i){
	case 1:
		cout<<"Please input the Elem: ";
		cin>>e;
		if(!k){
			if(Push(x,e)) cout<<"Push success!"<<endl;
			else cout<<"Push failed!"<<endl;
		}
		else{
			if(Push2(y,e)) cout<<"Push success!"<<endl;
			else cout<<"Push failed!"<<endl;
		}
		M();
		break;
	case 2:
		if(!k){
			if(Pop(x,e)) cout<<"The elem which Pop is "<<e<<"."<<endl;
			else cout<<"Pop failed!"<<endl;
		}
		else{
			if(Pop2(y,e)) cout<<"The elem which Pop is "<<e<<"."<<endl;
			else cout<<"Pop failed!"<<endl;
		}
		M();
		break;
	case 3:
		if(!k) cout<<"The top elem is "<<GetTop(x)<<"."<<endl;
		else cout<<"The top elem is "<<GetTop2(y)<<"."<<endl;
		M();
		break;
	case 4:
		if(!k) TraverseList(x);
		else TraverseList2(y);
		M();
		break;
	case 5:
		int p;
		cout<<"Please input the number: ";
		cin>>p;
		if(!k){
			while(p>=8){
				Push(x,p%8);
				p/=8;
			}
			cout<<"10->8: "<<p;
			while(Pop(x,e)) cout<<e;
			cout<<endl;
		}
		else{
			while(p>=8){
				Push2(y,p%8);
				p/=8;
			}
			cout<<"10->8: "<<p;
			while(Pop2(y,e)) cout<<e;
			cout<<endl;
		}
		M();
		break;
	case 6:
		int q;
		cout<<"Please input the number: ";
		cin>>q;
		if(!k){
			while(q>=16){
				Push(x,q%16);
				q/=16;
			}
			cout<<"10->16: "<<dic[q];
			while(Pop(x,e)) cout<<dic[e];
			cout<<endl;
		}
		else{
			while(q>=16){
				Push2(y,q%16);
				q/=16;
			}
			cout<<"10->16: "<<dic[q];
			while(Pop2(y,e)) cout<<dic[e];
			cout<<endl;
		}
		M();
		break;
	case 7:
		if(!k) PopAll(x);
		else PopAll(y);
		Menu();
		break;
	default:
		cout<<"Please input a correct Key!"<<endl;
		M();
		break;
	}
}
void main(){
	Menu();
}
