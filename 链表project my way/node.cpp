#include<iostream>
#include"node.h"
using namespace std;
//���ĳ���ڵ�ķ��� ���Σ�ͷ��㣬��Ҫ������ǵڼ����ڵ�ķ��� ��������ܸ�Ϊ��Ӧ����������ѧ����Ϊ������
void node::putscore(node *head,int n,int nodenum)
{
	int i=0;
	node *p = head;
	while (nodenum>n)//��������Ƿ�Ϸ�
	{
		cout << "������Ҫ����Ľڵ�λ�ã����ڸ�����Χ�ڣ��������������Ľڵ��������λ��(����ֵС��" << n << ")" << endl;
		cin >> nodenum;
	}
	for ( ;i < n-1; i++)
		p=p->next;
	cout <<"��"<<n<<"��ѧ���ķ�����:"
							<<p->score <<endl;
};
//�ı���� ���Σ��ڼ����ڵ�  �޸ĵĳɼ�Ϊ���٣�������ܸ�Ϊ��Ӧ����������ѧ����Ϊ������
void node::changescore(node *head, int n,int changescore)
{
	int i = 0;
	node *p = head;
	for (; i < n - 1; i++)
		p = p->next;
	p->score = changescore;
	cout << "��" << n << "��ѧ���ķ����޸ĺ�Ľ��Ϊ:"
									<< p->score << endl;
};
//���ݳɼ�����		 ���Σ�ͷ�ڵ㣬�ڵ����
int node::sortscore(node* head,int n)
{
	int i, j, temp = 0;
	node *qian, *hou;
	qian = hou = head;
	for (i = 0;i<n-1;i++,qian=qian->next)
	{
		if (qian->next == NULL)	 { cout << "�������ѧ��������Ŀ��������������" << endl; return -1; }		
		hou=qian->next;
		for (j = i + 1; j < n; j++,hou = hou->next)
		{			
			if (qian->score < hou->score)//�Ӵ�С
			{
				temp = hou->score;
				hou->score = qian->score;
				qian->score = temp;
			}	
		}
	}
	return 0;
};
//�ܳɼ�  ���Σ�ͷ�ڵ�,�ڵ���� �����ܳɼ�
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
	cout<<n<<"��ѧ�����ܳɼ��ǣ�"<< total<<endl;
	return total;
};
//ƽ���ɼ� ���� �ܳɼ�,�ڵ���� ����ƽ���ɼ�
void node::averagescore(int total,int n)
{
	float average;
	average = (float)total / n;
	cout << n << "��ѧ����ƽ���ɼ��ǣ�" << average << endl;
};