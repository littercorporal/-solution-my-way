//有没有可能实现sortscore 不改变原链表的情况下输出排序
class node
{
	public:
		int score;
		 node *next;
		//static int total;          //编译器不给过  在链接时 obj文件说啥子无法解析外部符号 可参照下面的网页，反正我暂时是看不懂的
//https://docs.microsoft.com/zh-cn/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev15.query%3FappId%3DDev15IDEF1%26l%3DZH-CN%26k%3Dk(LNK2001)%26rd%3Dtrue
		//static float average;

		static void putscore(node*,int,int);		//输出某个节点的分数 传参：头结点，节点个数 需要输出的是第几个节点的分数（后面可能改为对应的姓名或者学号作为参数）
		static void changescore(node*, int,int);	//改变分数			 传参：头节点，第几个节点  修改的成绩为多少		（后面可能改为对应的姓名或者学号作为参数）	
		static int sortscore(node*, int);			//根据成绩排序		 传参：头节点，节点个数	
		static int totalscore(node*,int);			//总成绩			 传参：头节点，节点个数							返回总成绩
		static void averagescore(int, int);			//平均成绩			 传参：总成绩，节点个数							返回平均成绩
	
		friend class list;
};