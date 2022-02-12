#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node* InitList1();
void printlist(struct node* head);
int NumofElem(struct node* head);
void insertFront(struct node* head, int elem);
void insertBack(struct node* head, int elem);
void clearList(struct node* head);
void destoryList(struct node* head);
void addnode(struct node* head, int k, int elem);

struct node {
	int data;
	struct node* next;
}Lnode;//头结点在创建链表时创建

int main() {
	struct node* head=InitList1();
	NumofElem(head);

	printlist(head);

	insertFront(head, 5);
	insertFront(head, 4);
	insertFront(head, 3);
	
	printlist(head);

	insertBack(head, 5);

	addnode(head, 1, 10);
	

	printlist(head);

	clearList(head);

	return 0;
}








// 初始化链表LL，返回值：失败返回NULL，成功返回头结点的地址。
struct node* InitList1() {
	//分配头节点
	struct node* head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		return NULL;
	}
	else {
		//可略去此处else，若head！=null，则其必经过此过程
		head->next = NULL;
		return head;
	}
}


//遍历链表
void printlist(struct node *head) {
	if (head == NULL) {
		printf("链表不存在！\n");
		return;
	}
	if (head->next == NULL) {
		printf("链表为空！\n");
		return;
	}
	//struct node* p = head;//头结点不能改动
	//优化后有
	struct node* p = head->next;
	
	//不为空
	while (p!= NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//求链表中元素个数
int NumofElem(struct node* head) {
	if (head == NULL|| head->next == NULL) {
		
		return 0;
	}
	struct node* p = head->next;
	int sum = 1;
	while (p != NULL) {
		if (p->next != NULL) {
			p = p->next;
			sum++;
		}
		if (p->next = NULL)break;
	}
	
	return sum;
}

//在链表头部插入元素elem
void insertFront(struct node* head, int elem) {
	if (head == NULL) {
		printf("Error!\n");
	}
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->next = NULL;
	if (head->next == NULL) {
		head->next = p;
		p->data = elem;
	}
	else {
		p->next = head->next;
		head->next = p;
		p->data = elem;
	}
}

//在链表尾部添加元素elem
void insertBack(struct node* head, int elem) {
	if (head == NULL) {
		printf("Error!\n");
	}
	struct node* cp = head;
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->next = NULL;
	while (cp->next!=NULL){
		cp = cp->next;
	}
	cp->next = p;
	p->data = elem;
}

//清空链表，仅留下头结点
void clearList(struct node* head) {
	if (head == NULL) {
		printf("无链表!\n");
		return;
	}
	//对于head->next==NULL不用处理
	struct node* p1 = head->next;
	struct node* p2;

	while (p1->next!=NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
		//p1 = p1->next;//错误，此时p1所指向的地方内存以及被释放
	}
	free(p1);
}


//清空链表，包括头结点
void destoryList(struct node* head) {
	if (head == NULL) {
		return;
	}
	struct node* p1 = head;
	struct node* p2;
	while (p1->next != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	free(p1);
}

//记头结点为0号元素.使elem成为第k个元素
void addnode(struct node* head, int k, int elem) {
	//若链表为空，创建，并添加为第一个结点
	if (head == NULL) {
		InitList1();
		//struct node* p = (struct node*)malloc(sizeof(struct node));
		addnode(head, 1, elem);
		return;
	}
	if (k > NumofElem(head)+1)k = NumofElem(head) + 1;//eg：总元素仅3个，而要添加到第7个位置
	//经过变换，变成添加为第四个元素
	
	//struct node* p = head->next;//需要考虑i=1的情况
	struct node* p = head;
	int i = 1;
	while (p != NULL) {
		if (k == i) {
			struct node* new = (struct node*)malloc(sizeof(struct node));
			new->next = p->next;
			p->next = new;
			new->data = elem;
			break;
		}
		printf("??");
		i++;
		p = p->next;
	}
	
}
