#include"node.h"
class list
{
	public: 
		//û�о���Ķ��� ���Բ�������ͨ��Ա������û��thisָ��ָ���޷����ã����Ҫ�õľ�̬��Ա���� ��������Ϊstatic��
		static int createlist(node*);				//��������				���Σ�ͷ���						���ز������ڵ����  
		static int addlist(node*,int);			    //β����������			���Σ�ͷ��� �ڵ����				���ز������µĽڵ����
		static int insertnode(node*,int,int);		//����һ���ڵ�			���Σ�ͷ��� �ڵ���� �ڼ����ڵ�	���ز������µĽڵ����
		static int deletenode(node*,int,int);		//ɾ��һ���ڵ�			���Σ�ͷ��� �ڵ���� �ڼ����ڵ�	���ز������µĽڵ����
		static void putlist(node*, int);			//������нڵ������	���Σ�ͷ��� �ڵ���� 
		static void putnode(node*,int,int);			//���ĳ���ڵ�ȫ������  ���Σ�ͷ��� �ڵ���� �ڼ����ڵ�
		static void getnode(node*,int,int);			//���루�ı䣩ĳ���ڵ��ȫ������	���Σ�ͷ��� �ڵ���� �ڼ����ڵ�
};