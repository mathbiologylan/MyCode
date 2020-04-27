#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <tr1/unordered_map>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <limits.h>
#include <malloc.h>

//#include "_public.cpp"

//定义二叉树节点
struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : data(x), left(NULL), right(NULL) {} //构造函数（用于初始化）
};

//二叉树的类
//平衡二叉树参考：https://only0322.github.io/post/binarytree/
//普通二叉树参考：https://www.cnblogs.com/winslam/p/8975139.html
class BTree
{
  public:
		int root_val;
		void DestoryTree(TreeNode * &p);
		//创建平衡二叉树
    void Create(TreeNode * &p,TreeNode * &temp);
    //创建普通二叉树--不存储节点信息
		TreeNode * CreateNormalTreeNoStorage(std::map<int,int> nodeinfo,int index);
    //创建普通二叉树--存储节点信息
    TreeNode * CreateNormalTreeStorage(std::map<int,int> nodeinfo,int index,std::vector<TreeNode> nodearray,\
				std::vector<TreeNode *> nodeptrarray,int global);
		//先序遍历
		void PreOrder(TreeNode * p);
		//中序遍历
		void MidOrder(TreeNode * p);
		//后序遍历
		void PostOrder(TreeNode * p);
		//求树高
		int Depth(TreeNode *p);
		//求节点数
		int NodeNums(TreeNode *p);
		BTree();

};

//构造函数
BTree::BTree()
{
	root_val = 0;
}


//创建平衡二叉树 递归
void BTree::Create(TreeNode * &p,TreeNode * &temp)
{
  //保证二叉树满足 左子树小于根节点，右子树大于根节点
  //p是新的节点，temp是从root开始遍历的节点
	if(temp == nullptr)
	{
		temp = p;
	}
	else
	{
		//根节点有值了，判断大小
		if(temp->data == p->data )
		{
			std::cout<<"the same value is not allowed"<<std::endl;
		}
    else if(p->data < temp->data) //新节点比根节点小，就去左边递归
    {
      Create(p,temp->left);
		}
    else //p->data > root->data //反之去右边递归
	  {
      Create(p,temp->right);
		}
	}
}

//创建一棵普通二叉树--不存储节点信息
TreeNode * BTree::CreateNormalTreeNoStorage(std::map<int,int> nodeinfo,int index)
{
  if(nodeinfo.find(index) == nodeinfo.end())
	{
    return NULL;
	}
	TreeNode *node = new TreeNode(nodeinfo[index]);
	node->left = CreateNormalTreeNoStorage(nodeinfo, index * 2);
	node->right = CreateNormalTreeNoStorage(nodeinfo, index * 2 + 1);
	return node;
}

//创建一棵普通二叉树--存储节点信息
TreeNode * BTree::CreateNormalTreeStorage(std::map<int,int> nodeinfo,int index,std::vector<TreeNode> nodearray,\
		std::vector<TreeNode *> nodeptrarray,int global)
{
  if(nodeinfo.find(index) == nodeinfo.end())
	{
    return NULL;
	}

	nodeptrarray[global]->left = CreateNormalTreeStorage(nodeinfo, index * 2,nodearray,nodeptrarray,global + 1);
	nodeptrarray[global]->right = CreateNormalTreeStorage(nodeinfo, index * 2 + 1,nodearray,nodeptrarray,\
				global + 2);

	return nodeptrarray[global];
}

//先序遍历
void BTree::PreOrder(TreeNode * p)
{
	if(p!=nullptr)
	{
	  std::cout<<p->data<<' ';
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

//中序遍历
void BTree::MidOrder(TreeNode * p)
{
	if(p!=nullptr)
	{
		MidOrder(p->left);
	  std::cout<<p->data<<' ';
		MidOrder(p->right);
	}
}

//后序遍历
void BTree::PostOrder(TreeNode * p)
{
	if(p!=nullptr)
	{
		PostOrder(p->left);
		PostOrder(p->right);
		std::cout<<p->data<<' ';
	}
}

//求树高
int BTree::Depth(TreeNode * p)
{
 if ( p == nullptr )
	 return 0;
 int l_depth = Depth(p->left);
 int r_depth = Depth(p->right);
 return std::max(l_depth,r_depth) + 1;
}

//求节点数
int BTree::NodeNums(TreeNode *p)
{
  if ( p == nullptr )
		return 0;
	return NodeNums(p->left) + NodeNums(p->right) + 1;
}

//销毁二叉树--适用于逐个节点创建
void BTree::DestoryTree(TreeNode * &p)
{
	if(p != nullptr)
	{
		DestoryTree(p->left);
		DestoryTree(p->right);
		delete p;
		p = nullptr;
	}
}


int main()
{
  
  BTree tree;
 
	/*
	//####一次输入树的一个节点值创建二叉平衡树（只存储根节点）####
	std::cout<<"enter the root's value"<<std::endl;
	 
	std::cin>>tree.root_val;
	TreeNode *root = new TreeNode(tree.root_val); //动态分配根节点并初始化
  while(1)
  {
		int value;
		std::cout<<"enter the value or -999 to exit"<<std::endl;
		std::cin>>value;
    if(value == -999)
    {
      break;
    }

    TreeNode * p =new TreeNode(value);  //动态分配节点并初始化    

    tree.Create(p,root);

  }

	std::cout<<"the binary tree has been created"<<std::endl;
 
	//中序遍历
  tree.MidOrder(root); 


  TreeNode *res = ss.lowestCommonAncestor(root,ptr[0],ptr[1]);

	//销毁树--输入单个元素创建树时候使用
  tree.DestoryTree(root);	

	*/

	/*

  //####一次输入树的所有节点值创建二叉平衡树(存储各节点)####
	
  //树各个节点的值
	std::vector<int> value = {6,2,8,0,4,7,9,3,5};

	//树各个节点的指针数组
	std::vector<TreeNode *> ptr(9,NULL);

	//创建节点并初始化
  std::vector<TreeNode> tree_node = {6,2,8,0,4,7,9,3,5};

	//用创建的节点生成二叉平衡树--存储节点信息
	for ( int i = 0;i < 9;i++ )
	{
		ptr[i] = &tree_node[i];
		tree.Create(ptr[i],ptr[0]);
	}

	std::cout<<"the binary tree has been created"<<std::endl;
 
	//中序遍历
  tree.MidOrder(ptr[0]); 


	//清空元素并释放内存
	ptr.clear();
  ptr.shrink_to_fit();

	value.clear();
  value.shrink_to_fit();
  
	tree_node.clear();
  tree_node.shrink_to_fit();

	*/
	

	//创建map并初始化
  //Map参考：https://www.cnblogs.com/winslam/p/8975139.html
	std::map<int,int> normal_tree;
  normal_tree.insert(std::pair<int,int>(1,3));
  normal_tree.insert(std::pair<int,int>(2,9));
  normal_tree.insert(std::pair<int,int>(3,20));
  normal_tree.insert(std::pair<int,int>(6,15));
  normal_tree.insert(std::pair<int,int>(7,7));

	//TreeNode类型的指针数组
	std::vector<TreeNode *> ptr(5,NULL);

	//TreeNode类型的数组
	std::vector<TreeNode> tree_node = {3,9,20,15,7};

	//初始化数组指针指向数组
	for ( int i = 0;i < 5;i++ )
	{
	  ptr[i] = &tree_node[i];
	}
 
	int dr = 0;
	//存储节点信息创建一棵普通二叉树
	TreeNode *rooot = tree.CreateNormalTreeStorage(normal_tree,1,tree_node,ptr,dr);

  //不储节点信息创建一棵普通二叉树
	//TreeNode *rooot = tree.CreateNormalTreeNoStorage(normal_tree,1);
	
	//前序遍历
	printf("前序遍历序列为：\n");
	tree.PreOrder(rooot); 
	printf("\n");

	//中序遍历
	printf("中序遍历序列为：\n");
	tree.MidOrder(rooot); 
	printf("\n");

	//后序遍历
	printf("后序遍历序列为：\n");
	tree.PostOrder(rooot); 
	printf("\n");

	//求树高
	int depth = tree.Depth(rooot);
  std::cout<<"树高为："<<depth<<std::endl;

	//求节点数
	int nodenums = tree.NodeNums(rooot);
	printf("树的节点数为：%d\n",nodenums);

	//清空元素并释放内存空间
	ptr.clear();
  ptr.shrink_to_fit();

	normal_tree.clear();
	malloc_trim(0);
  
	tree_node.clear();
  tree_node.shrink_to_fit();

  

  return 0;
}

