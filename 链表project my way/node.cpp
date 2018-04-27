#include<iostream>
#include"node.h"
using namespace std;
//输出某个节点的分数 传参：头结点，需要输出的是第几个节点的分数 （后面可能改为对应的姓名或者学号作为参数）
void node::putscore(node *head,int n,int nodenum)
{
	int i=0;
	node *p = head;
	while (nodenum>n)//检查输入是否合法
	{
		cout << "你所需要输出的节点位置，不在该链表范围内，请重新输入您的节点所需插入位置(该数值小于" << n << ")" << endl;
		cin >> nodenum;
	}
	for ( ;i < n-1; i++)
		p=p->next;
	cout <<"第"<<n<<"个学生的分数是:"
							<<p->score <<endl;
};
//改变分数 传参：第几个节点  修改的成绩为多少（后面可能改为对应的姓名或者学号作为参数）
void node::changescore(node *head, int n,int changescore)
{
	int i = 0;
	node *p = head;
	for (; i < n - 1; i++)
		p = p->next;
	p->score = changescore;
	cout << "第" << n << "个学生的分数修改后的结果为:"
									<< p->score << endl;
};
//根据成绩排序		 传参：头节点，节点个数
int node::sortscore(node* head,int n)
{
	int i, j, temp = 0;
	node *qian, *hou;
	qian = hou = head;
	for (i = 0;i<n-1;i++,qian=qian->next)
	{
		if (qian->next == NULL)	 { cout << "您输出的学生人数数目有误，请重新输入" << endl; return -1; }		
		hou=qian->next;
		for (j = i + 1; j < n; j++,hou = hou->next)
		{			
			if (qian->score < hou->score)//从大到小
			{
				temp = hou->score;
				hou->score = qian->score;
				qian->score = temp;
			}	
		}
	}
	return 0;
};
//总成绩  传参：头节点,节点个数 返回总成绩
int node::totalscore(node *head,int n)
{
	int i=0;
	int total=0;
	node *p = head;
	for (; i < n; i++)
	{
		total +=p->score;
		p = p->next;	
	}
	cout<<n<<"个学生的总成绩是："<< total<<endl;
	return total;
};
//平均成绩 传参 总成绩,节点个数 返回平均成绩
void node::averagescore(int total,int n)
{
	float average;
	average = (float)total / n;
	cout << n << "个学生的平均成绩是：" << average << endl;
};