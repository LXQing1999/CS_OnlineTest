#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};
struct QueueNode // 队列里的结点格式
{
    TreeNode *parent; // 存储了父节点的地址
    bool isLeftIn;
};
void insertTreeNode(TreeNode *&root, queue<QueueNode> &myQueue, char data)
{ // 引用的根节点和队列都涉及了修改，所以要加&
    if (data != '#')
    {
        // 因为是在被调函数内创建结点，所以要申请堆空间
        // 创建一个二叉树结点
        // 注意不能设置成局部变量，跳出后会销毁
        TreeNode *pTreeNode = new TreeNode; // 新建二叉树结点
        //(*pTreeNode).data = data;
        //(*p).member 和p->member 等价
        pTreeNode->data = data;
        QueueNode *pQueueNode = new QueueNode; // 新建队列结点
        // 指向地址的数据类型* 指针变量名 指向 创建新结点 结点类型
        // 入队  把刚刚创建好的二叉树结点，把其地址和是否插过左孩子的信息加入到队列中
        pQueueNode->parent = pTreeNode;
        pQueueNode->isLeftIn = false;
        // myQueue.push(pQueueNode);
        //  然后这个地方，push操作本来就是压入一个变量，不管是内置类型（你知道啥是内置类型吗）
        //  还是用户自定义类型（比如struct还是class），它们被压入的实际上是地址没错，但是你传参的时候不能直接传地址
        //  下面的报错写的很明白了，no matching function for call to ‘std::queue<QueueNode>::push(QueueNode*&)
        //  这个参数按照你原来的传参过程，传入的是一个地址
        myQueue.push(*pQueueNode); // 修改以后，*在地址（也就是指针）之前，表示取地址操作，这样他就是一整个变量（不是内置类型，而是你自定义的struct了）

        //  插入的操作
        if (root == NULL)
        {
            // 说明插入的是第一个结点
            root = pTreeNode;
        }
        else
        {
            // 说明插入的不是根
            // pParent 用来定位插入结点的父亲的位置
            QueueNode *pParent = &myQueue.front(); // myQueue.front()返回的是一个左值，需要取左值的地址（用&符号），把这个地址给新变量pParent，为了标记这个新变量是个地址，在pParent之前加上*号，再往前面QueueNode是告诉编译器，这个地址指向的内存空间存储的是用户自定义类型
            // myQueue里存的是队列结点QueueNode  它不能转变为指针，所以我引用了它的地址
            if (pParent->isLeftIn == false) // 左边
            {
                pParent->parent->leftChild = pTreeNode;
                pParent->isLeftIn = true;
            }
            else // 右边
            {
                pParent->parent->rightChild = pTreeNode;
                myQueue.pop(); // 出队
                // delete pParent; // 出队后，原来的队首无用了，释放堆空间
            }
        }
    }
    else // 当插入的为#,也就是插入空结点时
    {
        // 是#  插入空
        if (root != NULL)
        {
            QueueNode *pParent = &myQueue.front();
            if (pParent->isLeftIn == false)
            { // 左孩子为空
                pParent->parent->leftChild = NULL;
                // 左孩子标记为空
                pParent->isLeftIn = true;
                // 左孩子标记为true
            }
            else
            {
                pParent->parent->rightChild = NULL;
                myQueue.pop();
                // 左右孩子都遍历过后可以出队了
                // delete pParent; //这里delete操作，需要考虑是否删除了不存在的指针指向的空间，
                // 直接问chatgpt，然后我对你的要求是，这本书的第七章，你得一句句让chatgpt讲给你听
            }
        } // 如果root为空，插入也为空，整体为空，不用管他
    }
    return;
}
void InOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->leftChild);
    printf("%c ", root->data);
    InOrder(root->rightChild);
}
int main(int argc, char const *argv[])
{
    TreeNode *root = NULL; // 根节点
    char charList[101];
    // string charlist;
    // 字符串既可以用string 来遍历 for(auto i:s);也可以用数组来遍历
    // 同理数组也可以用%s传进去
    while (scanf("%s", charList) != EOF)
    {
        queue<QueueNode> myQueue; // 队列的每个元素存储了新结点的父亲的位置，以及是否有左孩子
        // 定义队列的类型是QueueNode（自己定义的结构体），名字叫myQueue
        for (int i = 0; charList[i] != '\0'; i++)
        // for中间的这个是判断语句
        {
            // printf("%d\n", i);
            insertTreeNode(root, myQueue, charList[i]);
        }
        InOrder(root);
        printf("\n");
    }
    return 0;
}
// 假设传进去的例子：abc##de#g##f###
