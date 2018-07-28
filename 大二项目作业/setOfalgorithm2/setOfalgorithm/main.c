#include<stdio.h>
#include<malloc.h>
typedef int DataType;
#define union 0
#define minus 1
#define mix 2
typedef struct LNode {
	DataType data;
	struct LNode *next;
}Node;

typedef struct SNode {
	Node *Nhead;
	struct SNode *Shead;
	struct SNode *next;
	int Nsize;
}Set;


Set *init_Set(void) {
	Set *s;
	s = (Set *)malloc(sizeof(Set));
	s->Nhead = NULL;
	s->Shead = NULL;
	s->next = NULL;
	s->Nsize = 0;
	return s;
}

Set *Creat_Set(Set **s, int *size) {
	if ((*s) == NULL) {
		*s = (Set *)malloc(sizeof(Set));
		(*s)->Shead = (*s);
		(*s)->Nhead = (Node*)malloc(sizeof(Node));
		(*s)->Nhead->next = (*s)->Nhead;
		(*s)->next = NULL;
		(*s)->Nsize = 0;
		return *s;
	}
	else {
		Set *p = (*s)->Shead;
		Set *temp= (Set *)malloc(sizeof(Set));
		temp->Shead = p;
		temp->Nsize = 0;
		while (p -> next != NULL) {
			p = p->next;
		}
		temp->Nhead = (Node*)malloc(sizeof(Node));
		temp->Nhead->next = temp->Nhead;
		p->next = temp;
		temp->next = NULL;
		return temp;
	}
	(*size)++;
}

//非递减且无重复。采用尾插法(传参时需判断count是否大于总size）
int INSERT_SET(Set *s, int count, DataType x) {
	Set *sss = s->Shead;
	Node *p, *q, *temp=NULL;
	int i = 1;
	for (; i < count; i++) {
		sss = sss->next;
	}
	if (sss->Nhead->next == NULL) {
		q = (Node *)malloc(sizeof(Node));
		q->data = x;
		q->next = q;
		sss->Nhead->next = q;
	}
	else {
		temp = sss->Nhead->next;
		p = temp;
		while (temp!= sss->Nhead) {
			if (temp->data == x)
				return 0;
			else {
				p = temp;
				temp = temp->next;
			}
		}
		q = (Node *)malloc(sizeof(Node));
		q->data = x;
		q->next = temp;
		p->next = q;
	}
	sss->Nsize++;
		return 1;
}

void printElement(Node *head) {
	Node *temp;
	if (head == NULL || head->next == NULL || head->next == head) {
		printf("%s", "空集");
		return;
	}
	temp = head->next;
	printf("{");
	while (temp != head) {
		if (temp->next == head) {
			printf("%d", temp->data);
		}
		else
			printf("%d,", temp->data);
		temp = temp->next;
	}
	printf("}");
}

int IN_SET(Node *head, DataType check) {
	Node *p=head->next;
	int i = 1;
	if (p == NULL)
		return 0;
	else {
		while (p != head) {
			if (p->data == check) {
				return 1;
			}
			p = p->next;
		}
		return 0;
	}
}

Node *mixU(Set *s1, Set *s2) {
	Node *p = NULL, *temp = NULL,*q = NULL,*head, *t = NULL;
	int i, j;
	if (s1 == NULL || s2 == NULL||s1->Nsize==0 || s2->Nsize == 0) {
		return 0;
	}
	head = (Node *)malloc(sizeof(Node));
	p = s1->Nhead->next;
	q = s2->Nhead->next;
	head->next = NULL;
	for (i = 0; i < s1->Nsize; i++) {
		for (j = 0; j < s2->Nsize; j++) {
			if(p->data == q->data){
				if (head->next == NULL) {
					temp = (Node *)malloc(sizeof(Node));
					temp->data = p->data;
					temp->next = head;
					head->next = temp;
					t = temp;
				}
				else {
					temp = (Node *)malloc(sizeof(Node));
					temp->data = p->data;
					temp->next = head;
					t->next = temp;
					t = temp;
				}
			}
			q = q->next;
		}
		p = p->next;
		q = s2->Nhead->next;
	}
	return head;
}

Node *unionU(Set *s1, Set *s2) {
	Node *p = NULL, *temp = NULL, *q = NULL, *head, *t = NULL;
	int i;
	int size=0;
	if (s1 == NULL && s2 == NULL) {
		return 0;
	}
	if (s1 == NULL ||  s1->Nsize == 0 ) {
		return s2->Nhead;
	}
	if (s2 == NULL || s2->Nsize == 0) {
		return s1->Nhead;
	}
	head = (Node *)malloc(sizeof(Node));
	p = s1->Nhead->next;
	q = s2->Nhead->next;

	head = mixU(s1, s2);
	temp = head ->next;
	if (temp == NULL)
		t = temp = head;
	while (temp != head) {
		t = temp;
		temp = temp->next;
		size++;
	}

	for (i = 0; i < s1->Nsize; i++) {
		if (!IN_SET(head, p->data)) {
			temp = (Node *)malloc(sizeof(Node));
			temp->data = p->data;
			temp->next = head;
			t->next = temp;
			t = temp;
		}
		p = p->next;
	}

	for (i = 0; i < s2->Nsize; i++) {
		if (!IN_SET(head,q->data)) {
			temp = (Node *)malloc(sizeof(Node));
			temp->data = q->data;
			temp->next = head;
			t->next = temp;
			t = temp;
		}
		q = q->next;
	}
	return head;
}


Node *AminusB(Set *s1, Set *s2) {
	Node  *temp, *head,*t,*p,*q;
	int i, size = 0;

	if (s1==NULL||s2==NULL||s1->Nsize == 0 || s2->Nsize == 0) {
		return 0;
	}
	temp = (Node *)malloc(sizeof(Node));
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	temp = mixU(s1, s2);

	p = s1->Nhead->next;
	for (i = 0; i < s1->Nsize; i++) {
			if (!IN_SET(temp, p->data)) {
				if (head->next == NULL) {
					q = (Node *)malloc(sizeof(Node));
					q->data = p->data;
					q->next = head;
					head->next = q;
					t = q;
				}
				else {
					q = (Node *)malloc(sizeof(Node));
					q->data = p->data;
					q->next = head;
					t->next = q;
					t = q;
				}
			}
		p = p->next;
	}
	return head;
}

Set *change(Node *n) {
	Set *temp = init_Set();
	Node *p;
	int size = 0;
	if (n == NULL || n->next == NULL || n->next == n) {
		return 0;
	}
	temp->Nhead = n;
	temp->Nsize = countNode(n);
	p = temp->Nhead->next;
	while (p!=temp->Nhead) {
		size++;
		p = p->next;
	}
	return temp;
}

void show_Set(Set *s) {
	int i=1;
	Set *p= s;
	if(s==NULL){
		printf("暂无集合.\n");
	}
	else {
		while (p != NULL) {
			printf("集合%d:", i);
			printElement(p->Nhead);
			printf("\n");
			i++;
			p = p->next;
		}
	}
}

int countNode(Node *head) {
	Node *temp;
	int i=0;
	if (head == NULL || head->next == NULL || head->next == head) {
		return 0;
	}
	temp = head->next;
	while (temp != head) {
		i++;
		temp = temp->next;
	}
	return i;
}

int countSNode(Set *head) {
	Set *temp;
	int i=0;
	if (head != NULL) {
		temp = head;
		while (temp != NULL) {
			i++;
			temp = temp->next;
		}
	}
	else {
		i = -1;
	}
	return i;
}


void menu(void)           //提供选项的菜单函数
{
	char c;
	int choice;
	int num,c1,c2,i,j;
	char x;
	Node *head;
	int size = 0,Ssize;
	Set *s = NULL,*temp=NULL,*p,*temp1,*temp2,*emmm;

	while (1) {
		printf("***************************************************************************\n");
		printf("* [0] 退出             [1] 创建集合                          [2] 打印集合 *\n");
		printf("* [3] 添加集合元素     [4] 交集运算                          [5] 并集运算 *\n");
		printf("* [6] 集合对称差       [7] 集合运算结果添加到已有集合组中                 *\n");
		printf("***************************************************************************\n");
		c = getch();
		choice = (int)c - '0';
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			temp=Creat_Set(&s, &size);
			printf("创建成功.");
			break;
		case 2:
			show_Set(s);
			break;
		case 3:
			printf("添加元素集合为(1,2,3…):");
			scanf("%d", &num);
			printf("\n");
			Ssize = countSNode(s);
			if (num > Ssize || num <= 0) {
				printf("该集合不存在.");
				break;
			}
			printf("输入添加的元素(要求为整数,q退出输入):");
			while(1){
				while (getchar() != '\n');
				x = getchar();
				if (x == 'q' || x == '\n' || x == '\r')
					break;
				INSERT_SET(s, num, x - '0');
			} 
			break;
		case 4:
			printf("要比较的集合1为(1,2,3…):");
			scanf("%d", &c1);
			printf("要比较的集合2为(1,2,3…):");
			scanf("%d", &c2);
			Ssize = countSNode(s);
			emmm = s->Shead;
			if (c1 > Ssize || c2 > Ssize || c1 <= 0 || c2 <= 0) {
				printf("不存在输入集合.");
				break;
			}
			for (i = 1; i < c1; i++)
				emmm = emmm->next;
			temp1 = emmm;
			emmm = s->Shead;
			for (i = 1; i < c2; i++)
				emmm = emmm->next;
			temp2 = emmm;
			head = mixU(temp1, temp2);
			printElement(head);
			break;
		case 5:
			printf("要比较的集合1为(1,2,3…):");
			scanf("%d", &c1);
			printf("要比较的集合2为(1,2,3…):");
			scanf("%d", &c2);
			Ssize = countSNode(s);
			emmm = s->Shead;
			if (c1 > Ssize || c2 > Ssize || c1 <= 0 || c2 <= 0)
				break;
			for (i = 1; i < c1; i++)
				emmm = emmm->next;
			temp1 = emmm;
			emmm = s->Shead;
			for (i = 1; i < c2; i++)
				emmm = emmm->next;
			temp2 = emmm;
			head = unionU(temp1, temp2);
			printElement(head);
			break;
		case 6:
			printf("要比较的集合1为(1,2,3…):");
			scanf("%d", &c1);
			printf("要比较的集合2为(1,2,3…):");
			scanf("%d", &c2);
			Ssize = countSNode(s);
			emmm = s->Shead;
			if (c1 > Ssize || c2 > Ssize || c1 <= 0 || c2 <= 0)
				break;
			for (i = 1; i < c1; i++)
				emmm = emmm->next;
			temp1 = emmm;
			emmm = s->Shead;
			for (i = 1; i < c2; i++)
				emmm = emmm->next;
			temp2 = emmm;
			head = unionU(change(AminusB(temp1, temp2)), change(AminusB(temp2, temp1)));
			printElement(head);
			break;
		case 7:
			p = (Set *)malloc(sizeof(Set));
			p = change(head);
			temp->next = p;
			p->next = NULL;
			p->Nsize = countNode(p->Nhead);
			break;
		}
		printf("\n");
	}
}

int main(void) {
	menu();
	return 0;
}