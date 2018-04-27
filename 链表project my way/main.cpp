#include<iostream>
#include"list.h"
//不用加nod.h的声明 因为他在list.h里面已经声明过 重复声明会报错
using namespace std;
//删除链表
void	deletelist(node* head,int n)
{
	node* p;
	for (int i = n+1; i >= 1; i--)
	{
		p = head;
		for (int j = 1; j < i; j++, p = p->next);
		//cout<<p->score<<endl;//测试删除内存的内容
		delete p;
		p = NULL;
	}
	cout<<"链表删除成功"<<endl;
}

//确定是否继续执行函数 返回flag
	//主要目的还是为了简化函数体积，方便我自己看吧，不然一个case内容太长了
	//可以考虑他把用define进行预处理，这样比调用函数的效率高
int isexit()
{
	int flag = 0;
	cout << "是否继续执行其他操作（输入-1退出程序）";
	cin >> flag;
	return flag;
}

//菜单栏 返回操作数
int cdl()
{
	int choose;
	cout << "菜单栏选项：" << endl
		<< "	" << "1.创建一个链表" << endl
		<< "	" << "2.增加链表长度" << endl
		<< "	" << "3.输出链表内容" << endl
		<< "	" << "4.插入一个节点" << endl
		<< "	" << "5.删除一个节点" << endl
		<< "	" << "6.输出节点内容" << endl
		<< "	" << "7.更改节点分数" << endl
		<< "	" << "8.输出节点分数" << endl
		<< "	" << "9.输出总成绩" << endl
		<< "	" << "10.输出平均成绩" << endl
		<< "	" << "11.按成绩从大到小排序" << endl//慎用11 因为他会更改原来链表里面的内容 很恐怖的
		<< "  " << "请输入您要执行的操作：";
	for (;;)
	{
		cin >> choose;
		if (choose >= 1 && choose <= 11)
			return choose;
		else
			cout << "您所选择的操作有误，请重新输入：";
	}
}

//执行对应操作
int execute(node*head,int choose,int &n)//建立引用，因为无法返回两个值 你得返回flag控制循环
{
	int flag=0;//是否继续执行操作的标志位
	switch (choose)
	{
		case 1://创建一个链表
		{
			n = list::createlist(head);
			cout << "这些学生的信息依次是： "<< endl;
			list::putlist(head, n);
			{//无法把它和isexit函数结合，因为isexit函数返回 也只能返回到本函数 他的返回值无法返回到主函数
				flag = isexit();
				if (flag == -1)	
					return 0;
				return 1;
		}
	}
		case 2://增加链表长度
		{
			n=list::addlist(head,n);
			cout << "新的链表为：" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
		}
	}
		case 3://输出链表内容
		{
			list::putlist(head,n);
			{
				flag = isexit();
				if (flag == -1)
				return 0;
				return 1;
			}
		}
		case 4://插入一个节点
		{
			int insert;
			cout << "请输入你需要插入的节点位置：(该数值小于" << n << ")"; cin >> insert;
			n = list::insertnode(head,n,insert);
			cout << "新的链表为：" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 5://删除一个节点
		{
			int nodenum;
			cout << "请输入你需要删除的节点位置：(该数值小于" << n << ")"; cin >> nodenum;
			n = list::deletenode(head, n, nodenum);
			cout << "新的链表为：" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 6://输出节点内容
		{
			int nodenum;
			cout << "请输入你需要输出内容的节点位置：(该数值小于" << n << ")"; cin >> nodenum;
			list::putnode(head, n, nodenum);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 7://更改节点分数
		{	
			int nodenum;
			cout << "请输入你需要更改成绩学生的位置：(该数值小于" << n << ")"; cin >> nodenum;
			cout << "第" << nodenum << "个学生的成绩将要修改修改如下：" << endl;
			 list::getnode(head, n, nodenum);
			 cout<<"修改成功"<<endl;
			 cout << "新的链表为：" << endl;
			 list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 8://输出节点分数
		{	
			int nodenum;
			cout << "请输入你所需要输出成绩学生的位置：(该数值小于" << n << ")"; cin >> nodenum;
			node::putscore(head, n, nodenum);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 9://输出总成绩
		{	
			node::totalscore(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 10://输出平均成绩
		{
			node::averagescore(node::totalscore(head, n), n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 11://按成绩从大到小排序
		{
			node::sortscore(head, n);
			cout << "排列之后，新的链表顺序为：" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		default:
		{	cout << "这句话是不可能出现的 绝对不可能的！！！！！！" << endl;
			flag = isexit();
			if (flag == -1)
				return 0;
		}	return 1;
	}
}

int main(void)
{
	node* head = new node;
	head->next = NULL;
	int num=0,choose=0,flag=1;	//n为返回的节点数,choose为选择的操作 flag为是否继续执行操作
	for (int i=0; flag !=0;i++)
	{
		choose = cdl();//返回操作数
		if (i == 0 && choose != 1)
		{
			cout << "程序并未创建链表，请先创建一个链表"<<endl;
			choose = 1;
		}
		flag=execute(head,choose,num);
		system("cls");
	}
	cout << "谢谢使用" << endl;
	deletelist(head,num);
	system("pause");
	return 0;
}
//一、n去表示这个链表的有效长度 实际节点长度为n+1，因为最后一个节点里面保存了 p->next=-1 用来检验值
//			可以通过 先用一个临时变量 去存储cin的值，然后看其是否为-1，如果是，就在创建链表，如果不是，则返回。
//					但是本工作设计改动代码量巨大 ，暂时先不考虑
//二、可不可以不用static XX（）函数 ，即不用静态成员函数，去处理这个链表