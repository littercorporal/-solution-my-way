#include "list.h"
#include<iostream>
using namespace std;

//��������				���Σ�ͷ���				���ز���Ϊ�ڵ����  
int list::createlist(node *head)//��������������һ���ڵ� ���һ������-1 ��Ϊ�жϸ�ֵ�Ƿ�δ-1��ʱ�� ����øýڵ� ��Ȼûɶ��
{
	node *p,*q;
	p = q = head; 
	cout << "���ڴ���������������������ѧ����Ϣ������-1������" << endl;
	for(int i = 1;  ;i++)
	{
		cout << "��" << i << "��ѧ���ĳɼ��ǣ�";
		cin >> p->score;
		//����ѭ��,��������ѧ���ĸ���
		if (p->score == -1)
		{
			if (i == 1)		{  cout << "������ʧ��" << endl; return -1;	}
			cout << "������ɣ���һ���ɹ�������" << i-1 << "��ѧ���ĳɼ�"<<endl;
			return i-1; 
		}		
		q= new node;//��ǰ�Ľڵ�β��ָ�� �½ڵ�
		if (q == NULL) { cout << "�ڴ治�㣬�ڵ�����ʧ�ܣ�" << endl; return -1; }
		p->next = q;
		q->next = NULL;	//�½ڵ�β������
		p = q;//p��ʱָ���½ڵ�
			  //������һ���ط� �����Ұ��Сʱ ��Ϊ����ִ�ж��ٴ�ѭ�� ���p��ֵ����û�иı� ����head
			//pֻ�Ǹ���ʱ��ת�ı��� qΪ�½����� 
	}
	return 0;
}

//����β�����ӽڵ�		���Σ�ͷ��� �ڵ����				���ز���Ϊ�µĽڵ����
int list::addlist(node *head, int	n)
{
	node  *p,*q;
	p = head;
	int i = 1;
	for (; i < n;i++,p=p->next);//ʹpָ��β�ڵ� ��ʱi=n
	cout << "����������Ҫ��ӵ���Ϣ������-1�������룩" << endl;
	for (;; i++)//����һ��ʼ�Ͷ�һ���ڵ� ȥ�洢-1�����Կ���ֱ�Ӹ�ֵ
	{
		cout << "������������ӵĵ�"<<n-i+1<<"��ѧ���ĳɼ�";	 cin >> p->score;
		if (p->score == -1)
		{
			if (n == i) { cout << "���Ľڵ�δ�ɹ����" << endl; }
			else
			{
				cout << "��֮ǰһ����" << n << "���ڵ㣬"
					<< "�ո�������" << i - n << "���ڵ㣬"
					<< "������һ����" << i << "���ڵ�" << endl;
				cout << "������ɣ�ллʹ�ã�" << endl;				
			}
			return i;
		}
		q = new node;
		if (q == NULL) { cout << "�ڴ治�㣬�ڵ�����ʧ�ܣ�" << endl; return -1; }
		p->next = q;
		q->next = NULL;
		p = q;		
	}

}

//����һ���ڵ�			���Σ�ͷ��� �ڵ���� �ڼ����ڵ�	���ز������µĽڵ����
//	ע����õ�ʱ�� nֵ�����˸ı� Ҫ���������ȥ��n��ֵ  ��n=list::insertlist(node *head, int n, int	nodenum)
int list::insertnode(node *head, int n, int	nodenum)
{
	while(nodenum>n)//��������Ƿ�Ϸ�
	{ 
		cout << "������Ҫ����Ľڵ�λ�ã����ڸ�����Χ�ڣ��������������Ľڵ��������λ��"<< endl;
		cin >> nodenum;
	}
	node*p,*q;
	p = q = head;
	for (int i = 1; i <nodenum-1; i++, p = p->next);//pָ��Ҫ����λ��ǰһ���ڵ�
	for (int i = 1; i <nodenum;   i++, q = q->next);//qָ��Ҫ����λ�ú�һ���ڵ�
	node *newinsert = new node;
	if (newinsert == NULL) { cout << "�ڴ治�㣬�ڵ�����ʧ�ܣ�" << endl; return -1; }
	cout << "��������Ҫ��������ݣ�" << endl
			<< "��Ҫ�����ѧ���ɼ��ǣ�"  ;
	cin>>newinsert->score;
	p ->next = newinsert;
	newinsert->next = q;
	return n+1;
}

//ɾ��һ���ڵ�			���Σ�ͷ��� �ڵ���� �ڼ����ڵ�	���ز������µĽڵ����
//	ע����õ�ʱ�� nֵ�����˸ı� Ҫ���������ȥ��n��ֵ  ��n=list::deletelist(node *head, int n, int	nodenum)
int list::deletenode(node *head, int n, int nodenum)
{
	while (nodenum>n)//��������Ƿ�Ϸ�
	{
		cout << "������Ҫɾ���Ľڵ�λ�ã����ڸ�����Χ�ڣ��������������Ľڵ��������λ��(����ֵС��" << n << ")" << endl;
		cin >> nodenum;
	}
	node*p, *q,*deletenode;
	p = deletenode = q = head;
	for (int i = 1; i <nodenum - 1; i++, p = p->next);					//pָ��Ҫɾ��λ��ǰһ���ڵ�
	for (int i = 1; i <nodenum	  ; i++, deletenode = deletenode->next);//deletenodeָ��Ҫɾ���Ľڵ�
	for (int i = 1; i <nodenum + 1; i++, q = q->next);					//qָ��Ҫɾ��λ�ú�һ���ڵ�
	cout << "��Ҫɾ����" << nodenum << "ѧ������Ϣ�ǣ�" << endl
			<< "		" << "�ɼ���" << deletenode->score << endl;
	p->next = q;
	delete deletenode;	deletenode = NULL;//��ֹҰָ�����
	cout << "�ѳɹ�ɾ����ѧ����Ϣ" << endl;
	return n-1;
}

//������нڵ������    ���Σ�ͷ���  �ڵ����
void list::putlist(node*head,int n)
{
	node*p = head;
	int i = 1;
	for (; i <n; i++,p=p->next)
		cout << "��"<<i<< "��ѧ���ĳɼ��ǣ�" << p->score << endl;
	cout << "��" << i << "��ѧ���ĳɼ��ǣ�" << p->score << endl;
	cout << "�����ϣ�"<<endl;
}

//���ĳ���ڵ�ȫ������  ���Σ�ͷ��� �ڼ����ڵ�
void list::putnode(node* head,int n,int nodenum)
{
	node* p = head;
	int i = 1;
	while (nodenum>n)//��������Ƿ�Ϸ�
	{
		cout << "������Ҫ����Ľڵ�λ�ã����ڸ�����Χ�ڣ��������������Ľڵ��������λ��(����ֵС��" << n << ")" << endl;
		cin >> nodenum;
	}
	for (; i < nodenum; i++,p = p->next);
	cout <<"��"<<i<<"���ڵ�����������ǣ�"
				<<"�ɼ�Ϊ��"<<p->score << endl;
}

//����ĳ���ڵ�ȫ������  ���Σ�ͷ��� �ڼ����ڵ�
void list::getnode(node *head, int n,int nodenum)
{
	node* p = head;	
	int i = 1;
	while (nodenum>n)//��������Ƿ�Ϸ�
	{
		cout << "������Ҫ����Ľڵ�λ�ã����ڸ�����Χ�ڣ��������������Ľڵ��������λ��(����ֵС��" << n << ")" << endl;
		cin >> nodenum;
	}
	for (; i < n; i++, p = p->next);

	cout <<"�����������"<<nodenum<<"��ѧ����������Ϣ:"
			<< "		" << "�ɼ���"; cin >> p->score;
}
