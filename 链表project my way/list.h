#include"node.h"
class list
{
	public: 
		//没有具体的对象 所以不能用普通成员函数（没有this指针指向，无法调用，因此要用的静态成员函数 声明函数为static）
		static int createlist(node*);				//创建链表				传参：头结点						返回参数：节点个数  
		static int addlist(node*,int);			    //尾部增加链表			传参：头结点 节点个数				返回参数：新的节点个数
		static int insertnode(node*,int,int);		//插入一个节点			传参：头结点 节点个数 第几个节点	返回参数：新的节点个数
		static int deletenode(node*,int,int);		//删除一个节点			传参：头结点 节点个数 第几个节点	返回参数：新的节点个数
		static void putlist(node*, int);			//输出所有节点的内容	传参：头结点 节点个数 
		static void putnode(node*,int,int);			//输出某个节点全部内容  传参：头结点 节点个数 第几个节点
		static void getnode(node*,int,int);			//输入（改变）某个节点的全部内容	传参：头结点 节点个数 第几个节点
};