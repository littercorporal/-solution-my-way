#include<iostream>
#include"list.h"
//���ü�nod.h������ ��Ϊ����list.h�����Ѿ������� �ظ������ᱨ��
using namespace std;
//ɾ������
void	deletelist(node* head,int n)
{
	node* p;
	for (int i = n+1; i >= 1; i--)
	{
		p = head;
		for (int j = 1; j < i; j++, p = p->next);
		//cout<<p->score<<endl;//����ɾ���ڴ������
		delete p;
		p = NULL;
	}
	cout<<"����ɾ���ɹ�"<<endl;
}

//ȷ���Ƿ����ִ�к��� ����flag
	//��ҪĿ�Ļ���Ϊ�˼򻯺���������������Լ����ɣ���Ȼһ��case����̫����
	//���Կ���������define����Ԥ���������ȵ��ú�����Ч�ʸ�
int isexit()
{
	int flag = 0;
	cout << "�Ƿ����ִ����������������-1�˳�����";
	cin >> flag;
	return flag;
}

//�˵��� ���ز�����
int cdl()
{
	int choose;
	cout << "�˵���ѡ�" << endl
		<< "	" << "1.����һ������" << endl
		<< "	" << "2.����������" << endl
		<< "	" << "3.�����������" << endl
		<< "	" << "4.����һ���ڵ�" << endl
		<< "	" << "5.ɾ��һ���ڵ�" << endl
		<< "	" << "6.����ڵ�����" << endl
		<< "	" << "7.���Ľڵ����" << endl
		<< "	" << "8.����ڵ����" << endl
		<< "	" << "9.����ܳɼ�" << endl
		<< "	" << "10.���ƽ���ɼ�" << endl
		<< "	" << "11.���ɼ��Ӵ�С����" << endl//����11 ��Ϊ�������ԭ��������������� �ֲܿ���
		<< "  " << "��������Ҫִ�еĲ�����";
	for (;;)
	{
		cin >> choose;
		if (choose >= 1 && choose <= 11)
			return choose;
		else
			cout << "����ѡ��Ĳ����������������룺";
	}
}

//ִ�ж�Ӧ����
int execute(node*head,int choose,int &n)//�������ã���Ϊ�޷���������ֵ ��÷���flag����ѭ��
{
	int flag=0;//�Ƿ����ִ�в����ı�־λ
	switch (choose)
	{
		case 1://����һ������
		{
			n = list::createlist(head);
			cout << "��Щѧ������Ϣ�����ǣ� "<< endl;
			list::putlist(head, n);
			{//�޷�������isexit������ϣ���Ϊisexit�������� Ҳֻ�ܷ��ص������� ���ķ���ֵ�޷����ص�������
				flag = isexit();
				if (flag == -1)	
					return 0;
				return 1;
		}
	}
		case 2://����������
		{
			n=list::addlist(head,n);
			cout << "�µ�����Ϊ��" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
		}
	}
		case 3://�����������
		{
			list::putlist(head,n);
			{
				flag = isexit();
				if (flag == -1)
				return 0;
				return 1;
			}
		}
		case 4://����һ���ڵ�
		{
			int insert;
			cout << "����������Ҫ����Ľڵ�λ�ã�(����ֵС��" << n << ")"; cin >> insert;
			n = list::insertnode(head,n,insert);
			cout << "�µ�����Ϊ��" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 5://ɾ��һ���ڵ�
		{
			int nodenum;
			cout << "����������Ҫɾ���Ľڵ�λ�ã�(����ֵС��" << n << ")"; cin >> nodenum;
			n = list::deletenode(head, n, nodenum);
			cout << "�µ�����Ϊ��" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 6://����ڵ�����
		{
			int nodenum;
			cout << "����������Ҫ������ݵĽڵ�λ�ã�(����ֵС��" << n << ")"; cin >> nodenum;
			list::putnode(head, n, nodenum);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 7://���Ľڵ����
		{	
			int nodenum;
			cout << "����������Ҫ���ĳɼ�ѧ����λ�ã�(����ֵС��" << n << ")"; cin >> nodenum;
			cout << "��" << nodenum << "��ѧ���ĳɼ���Ҫ�޸��޸����£�" << endl;
			 list::getnode(head, n, nodenum);
			 cout<<"�޸ĳɹ�"<<endl;
			 cout << "�µ�����Ϊ��" << endl;
			 list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 8://����ڵ����
		{	
			int nodenum;
			cout << "������������Ҫ����ɼ�ѧ����λ�ã�(����ֵС��" << n << ")"; cin >> nodenum;
			node::putscore(head, n, nodenum);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 9://����ܳɼ�
		{	
			node::totalscore(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 10://���ƽ���ɼ�
		{
			node::averagescore(node::totalscore(head, n), n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		case 11://���ɼ��Ӵ�С����
		{
			node::sortscore(head, n);
			cout << "����֮���µ�����˳��Ϊ��" << endl;
			list::putlist(head, n);
			{
				flag = isexit();
				if (flag == -1)
					return 0;
				return 1;
			}
		}
		default:
		{	cout << "��仰�ǲ����ܳ��ֵ� ���Բ����ܵģ�����������" << endl;
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
	int num=0,choose=0,flag=1;	//nΪ���صĽڵ���,chooseΪѡ��Ĳ��� flagΪ�Ƿ����ִ�в���
	for (int i=0; flag !=0;i++)
	{
		choose = cdl();//���ز�����
		if (i == 0 && choose != 1)
		{
			cout << "����δ�����������ȴ���һ������"<<endl;
			choose = 1;
		}
		flag=execute(head,choose,num);
		system("cls");
	}
	cout << "ллʹ��" << endl;
	deletelist(head,num);
	system("pause");
	return 0;
}
//һ��nȥ��ʾ����������Ч���� ʵ�ʽڵ㳤��Ϊn+1����Ϊ���һ���ڵ����汣���� p->next=-1 ��������ֵ
//			����ͨ�� ����һ����ʱ���� ȥ�洢cin��ֵ��Ȼ�����Ƿ�Ϊ-1������ǣ����ڴ�������������ǣ��򷵻ء�
//					���Ǳ�������ƸĶ��������޴� ����ʱ�Ȳ�����
//�����ɲ����Բ���static XX�������� �������þ�̬��Ա������ȥ�����������