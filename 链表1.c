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
}Lnode;//ͷ����ڴ�������ʱ����

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








// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
struct node* InitList1() {
	//����ͷ�ڵ�
	struct node* head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		return NULL;
	}
	else {
		//����ȥ�˴�else����head��=null������ؾ����˹���
		head->next = NULL;
		return head;
	}
}


//��������
void printlist(struct node *head) {
	if (head == NULL) {
		printf("�������ڣ�\n");
		return;
	}
	if (head->next == NULL) {
		printf("����Ϊ�գ�\n");
		return;
	}
	//struct node* p = head;//ͷ��㲻�ܸĶ�
	//�Ż�����
	struct node* p = head->next;
	
	//��Ϊ��
	while (p!= NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//��������Ԫ�ظ���
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

//������ͷ������Ԫ��elem
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

//������β�����Ԫ��elem
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

//�������������ͷ���
void clearList(struct node* head) {
	if (head == NULL) {
		printf("������!\n");
		return;
	}
	//����head->next==NULL���ô���
	struct node* p1 = head->next;
	struct node* p2;

	while (p1->next!=NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
		//p1 = p1->next;//���󣬴�ʱp1��ָ��ĵط��ڴ��Լ����ͷ�
	}
	free(p1);
}


//�����������ͷ���
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

//��ͷ���Ϊ0��Ԫ��.ʹelem��Ϊ��k��Ԫ��
void addnode(struct node* head, int k, int elem) {
	//������Ϊ�գ������������Ϊ��һ�����
	if (head == NULL) {
		InitList1();
		//struct node* p = (struct node*)malloc(sizeof(struct node));
		addnode(head, 1, elem);
		return;
	}
	if (k > NumofElem(head)+1)k = NumofElem(head) + 1;//eg����Ԫ�ؽ�3������Ҫ��ӵ���7��λ��
	//�����任��������Ϊ���ĸ�Ԫ��
	
	//struct node* p = head->next;//��Ҫ����i=1�����
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
