#include "list.h"
#include<iostream>
using namespace std;

//创建链表				传参：头结点				返回参数为节点个数  
int list::createlist(node *head)//待解决：会多生成一个节点 存放一个分数-1 因为判断该值是否未-1的时候 会调用该节点 虽然没啥用
{
	node *p,*q;
	p = q = head; 
	cout << "正在创建您的链表，请依次输入学生信息：（按-1结束）" << endl;
	for(int i = 1;  ;i++)
	{
		cout << "第" << i << "个学生的成绩是：";
		cin >> p->score;
		//跳出循环,返回输入学生的个数
		if (p->score == -1)
		{
			if (i == 1)		{  cout << "链表创建失败" << endl; return -1;	}
			cout << "输入完成，您一共成功输入了" << i-1 << "个学生的成绩"<<endl;
			return i-1; 
		}		
		q= new node;//以前的节点尾部指向 新节点
		if (q == NULL) { cout << "内存不足，节点申请失败！" << endl; return -1; }
		p->next = q;
		q->next = NULL;	//新节点尾部至空
		p = q;//p此时指向新节点
			  //就是这一个地方 卡了我半个小时 因为无论执行多少次循环 你的p的值还是没有改变 还是head
			//p只是个临时中转的变量 q为新建变量 
	}
	return 0;
}

//链表尾部增加节点		传参：头结点 节点个数				返回参数为新的节点个数
int list::addlist(node *head, int	n)
{
	node  *p,*q;
	p = head;
	int i = 1;
	for (; i < n;i++,p=p->next);//使p指向尾节点 此时i=n
	cout << "请输入你需要添加的信息（输入-1结束输入）" << endl;
	for (;; i++)//由于一开始就多一个节点 去存储-1，所以可以直接改值
	{
		cout << "请输入您所添加的第"<<n-i+1<<"个学生的成绩";	 cin >> p->score;
		if (p->score == -1)
		{
			if (n == i) { cout << "您的节点未成功添加" << endl; }
			else
			{
				cout << "您之前一共有" << n << "个节点，"
					<< "刚刚输入了" << i - n << "个节点，"
					<< "您现在一共有" << i << "个节点" << endl;
				cout << "输入完成，谢谢使用！" << endl;				
			}
			return i;
		}
		q = new node;
		if (q == NULL) { cout << "内存不足，节点申请失败！" << endl; return -1; }
		p->next = q;
		q->next = NULL;
		p = q;		
	}

}

//插入一个节点			传参：头结点 节点个数 第几个节点	返回参数：新的节点个数
//	注意调用的时候 n值发生了改变 要用这个函数去给n赋值  即n=list::insertlist(node *head, int n, int	nodenum)
int list::insertnode(node *head, int n, int	nodenum)
{
	while(nodenum>n)//检查输入是否合法
	{ 
		cout << "你所需要插入的节点位置，不在该链表范围内，请重新输入您的节点所需插入位置"<< endl;
		cin >> nodenum;
	}
	node*p,*q;
	p = q = head;
	for (int i = 1; i <nodenum-1; i++, p = p->next);//p指向要插入位置前一个节点
	for (int i = 1; i <nodenum;   i++, q = q->next);//q指向要插入位置后一个节点
	node *newinsert = new node;
	if (newinsert == NULL) { cout << "内存不足，节点申请失败！" << endl; return -1; }
	cout << "请输入您要插入的内容：" << endl
			<< "您要插入的学生成绩是："  ;
	cin>>newinsert->score;
	p ->next = newinsert;
	newinsert->next = q;
	return n+1;
}

//删除一个节点			传参：头结点 节点个数 第几个节点	返回参数：新的节点个数
//	注意调用的时候 n值发生了改变 要用这个函数去给n赋值  即n=list::deletelist(node *head, int n, int	nodenum)
int list::deletenode(node *head, int n, int nodenum)
{
	while (nodenum>n)//检查输入是否合法
	{
		cout << "你所需要删除的节点位置，不在该链表范围内，请重新输入您的节点所需插入位置(该数值小于" << n << ")" << endl;
		cin >> nodenum;
	}
	node*p, *q,*deletenode;
	p = deletenode = q = head;
	for (int i = 1; i <nodenum - 1; i++, p = p->next);					//p指向要删除位置前一个节点
	for (int i = 1; i <nodenum	  ; i++, deletenode = deletenode->next);//deletenode指向要删除的节点
	for (int i = 1; i <nodenum + 1; i++, q = q->next);					//q指向要删除位置后一个节点
	cout << "您要删除第" << nodenum << "学生的信息是：" << endl
			<< "		" << "成绩：" << deletenode->score << endl;
	p->next = q;
	delete deletenode;	deletenode = NULL;//防止野指针出现
	cout << "已成功删除该学生信息" << endl;
	return n-1;
}

//输出所有节点的内容    传参：头结点  节点个数
void list::putlist(node*head,int n)
{
	node*p = head;
	int i = 1;
	for (; i <n; i++,p=p->next)
		cout << "第"<<i<< "个学生的成绩是：" << p->score << endl;
	cout << "第" << i << "个学生的成绩是：" << p->score << endl;
	cout << "输出完毕！"<<endl;
}

//输出某个节点全部内容  传参：头结点 第几个节点
void list::putnode(node* head,int n,int nodenum)
{
	node* p = head;
	int i = 1;
	while (nodenum>n)//检查输入是否合法
	{
		cout << "你所需要输出的节点位置，不在该链表范围内，请重新输入您的节点所需插入位置(该数值小于" << n << ")" << endl;
		cin >> nodenum;
	}
	for (; i < nodenum; i++,p = p->next);
	cout <<"第"<<i<<"个节点里面的内容是："
				<<"成绩为："<<p->score << endl;
}

//输入某个节点全部内容  传参：头结点 第几个节点
void list::getnode(node *head, int n,int nodenum)
{
	node* p = head;	
	int i = 1;
	while (nodenum>n)//检查输入是否合法
	{
		cout << "你所需要输入的节点位置，不在该链表范围内，请重新输入您的节点所需插入位置(该数值小于" << n << ")" << endl;
		cin >> nodenum;
	}
	for (; i < n; i++, p = p->next);

	cout <<"请依次输入第"<<nodenum<<"个学生的以下信息:"
			<< "		" << "成绩："; cin >> p->score;
}
