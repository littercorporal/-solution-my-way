//��û�п���ʵ��sortscore ���ı�ԭ�����������������
class node
{
	public:
		int score;
		 node *next;
		//static int total;          //������������  ������ʱ obj�ļ�˵ɶ���޷������ⲿ���� �ɲ����������ҳ����������ʱ�ǿ�������
//https://docs.microsoft.com/zh-cn/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev15.query%3FappId%3DDev15IDEF1%26l%3DZH-CN%26k%3Dk(LNK2001)%26rd%3Dtrue
		//static float average;

		static void putscore(node*,int,int);		//���ĳ���ڵ�ķ��� ���Σ�ͷ��㣬�ڵ���� ��Ҫ������ǵڼ����ڵ�ķ�����������ܸ�Ϊ��Ӧ����������ѧ����Ϊ������
		static void changescore(node*, int,int);	//�ı����			 ���Σ�ͷ�ڵ㣬�ڼ����ڵ�  �޸ĵĳɼ�Ϊ����		��������ܸ�Ϊ��Ӧ����������ѧ����Ϊ������	
		static int sortscore(node*, int);			//���ݳɼ�����		 ���Σ�ͷ�ڵ㣬�ڵ����	
		static int totalscore(node*,int);			//�ܳɼ�			 ���Σ�ͷ�ڵ㣬�ڵ����							�����ܳɼ�
		static void averagescore(int, int);			//ƽ���ɼ�			 ���Σ��ܳɼ����ڵ����							����ƽ���ɼ�
	
		friend class list;
};