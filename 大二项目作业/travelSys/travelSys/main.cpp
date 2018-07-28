#define SHOW_CONSOLE			//����ͼ�ο�graphics.h

#include<cstdio>
#include<cstdlib>
#include<graphics.h>
#include<cstring>
#include<conio.h>
#include<time.h>
#include<math.h>

#define MaxRoad 99999			//��ʾ·����ͨ
#define MaxRow 640				//��������������
#define MaxCol 480				//��������������
#define safeDis 10				//���Ա�ʾ����ͼ�е����֮ǰ��̾���
#define radius 5				//���Ա�ʾ����ͼ�е�뾶

typedef char* DataType;		//��������


typedef struct {
	int row;
	int col;
}Point;						//����ͼ�������ݽṹ


typedef struct {
	int row;
	int col;
	int dis;
}RCD;						

typedef struct mp{
	int row;
	int col;
	int source;
	char *name;
	struct mp *next;
}MyPoint;					//����ͼ�������ݽṹ

typedef struct mr{
	int v1;
	int v2;
	int dis;
	struct mr *next;
}MyRCD;

typedef struct {
	MyPoint *p;
	MyRCD *r;
}MyGraph;


typedef struct Node {
	int distance;
	int dest;			//���ھ���ɵ���ı�
	struct Node *next;
}Edge;

typedef struct Adjcontain {
	DataType data;
	int source;			//ÿ�������������
	Point cur;
	Edge *adj;			//�ڽӱߵ�ͷ���
	struct Adjcontain* next;
}AdjContain;

typedef struct Adj {
	AdjContain *adjG;
	int numOfVerts;			//�������
	int numOfEdge;
}AdjGraph;

AdjGraph *AdjGinit(void) {
	AdjGraph *a;
	a = (AdjGraph *)malloc(sizeof(AdjGraph));
	a->adjG = NULL;
	a->numOfEdge = 0;
	a->numOfVerts = 0;
	return a;
}

//adj��next��ֵ����
void InsertVertex(AdjGraph *a, DataType scenic,int row = -1,int col = -1) {
	AdjContain *AdjC = NULL, *temp = NULL, *prior = NULL;
	int count = 1, flag = 0,i = 0;

	AdjC = (AdjContain *)malloc(sizeof(AdjContain));
	AdjC->next = NULL;
	AdjC->adj = NULL;
	AdjC->cur.col = col;
	AdjC->cur.row = row;
	AdjC->data = (char *)malloc(sizeof(char) * sizeof(scenic));
	strcpy(AdjC->data, scenic);
	a->numOfVerts++;
	if (a->adjG == NULL) {
		a->adjG = AdjC;
		AdjC->source = 1;
	}
	else {
		temp = a->adjG;
		while (temp != NULL) {
			if (count == i)
				break;
			prior = temp;
			temp = temp->next;
			count++;
		}
		if (prior == NULL) {
			AdjC->next = temp;
			a->adjG = AdjC;
		}
		else {
			prior->next = AdjC;
			AdjC->next = temp;
		}
		temp = a->adjG;
		i = 0;
		while (temp != NULL) {
			i++;
			temp->source = i;
			temp = temp->next;
		}
	}
}


AdjContain *getVerts(AdjGraph *a, unsigned int x) {
	AdjContain *p = a->adjG;
	int size = 0;
	if (x <= 0 || x > a->numOfVerts) {
		return 0;
	}
	while (p != NULL) {
		size++;
		if (size == x)
			return p;
		p = p->next;
	}
	return 0;
}

void InsertHalfEdge(AdjGraph *a, unsigned int v1, unsigned int v2, unsigned int dis) {
	Edge *p, *temp = NULL;
	if (v1 <= 0 || v1 > a->numOfVerts || v2 <= 0 || v2 > a->numOfVerts) {
		printf("����Խ��");
		return;
	}
	temp = getVerts(a, v1)->adj;
	while (temp != NULL) {
		if (temp->dest == v2)
			break;
		temp = temp->next;
	}
	if(temp != NULL && temp->dest == v2){
		temp->distance = dis;
	}
	else {
		p = (Edge *)malloc(sizeof(Edge));
		p->dest = v2;
		p->distance = dis;
		if (getVerts(a, v1)->adj == NULL) {
			getVerts(a, v1)->adj = p;
			p->next = NULL;
		}
		else if (getVerts(a, v1)->adj->next == NULL) {
			getVerts(a, v1)->adj->next = p;
			p->next = NULL;
		}
		else {
			p->next = getVerts(a, v1)->adj->next;
			getVerts(a, v1)->adj->next = p;
		}
		a->numOfEdge++;
	}
}

void InsertEdge(AdjGraph *a, unsigned int v1, unsigned int v2, unsigned int dis) {
	InsertHalfEdge(a, v1, v2, dis);
	InsertHalfEdge(a, v2, v1, dis);
}

void DeleteHalfEdge(AdjGraph *a, unsigned int v1, unsigned int v2) {
	Edge *curr, *pre;
	if (v1 <= 0 || v1 > a->numOfVerts || v2 <= 0 || v2 > a->numOfVerts) {
		printf("����Խ��");
		return;
	}
	pre = NULL;
	curr = getVerts(a, v1)->adj;
	while (curr != NULL && curr->dest != v2) {
		pre = curr;
		curr = curr->next;
	}
	if (curr != NULL &&curr->dest == v2 && pre == NULL) {
		getVerts(a, v1)->adj = curr->next;
		free(curr);
		a->numOfEdge--;
	}
	else if (curr != NULL && curr->dest == v2 && pre != NULL) {
		pre->next = curr->next;
		free(curr);
		a->numOfEdge--;
	}
	else
		printf("��Ҫɾ���ı߲�����");
}

void DeleteEdge(AdjGraph *a, unsigned int v1, unsigned int v2) {
	DeleteHalfEdge(a, v1, v2);
	DeleteHalfEdge(a, v2, v1);
}


int GetFirstVex(AdjGraph *a, unsigned int v) {
	AdjContain *p;
	int i = 1;
	if (v < 0 || v > a->numOfVerts) {
		printf("��������");
		return -1;
	}
	p = a->adjG;
	for (i; i < v; i++) {
		p = p->next;
	}
	if (p != NULL)
		return p->adj->dest;
	return -1;
}



int GetNextVex(AdjGraph *a, unsigned int v1, unsigned int v2) {
	AdjContain *p;
	Edge *e;
	int i = 1;
	if (v1 < 0 || v1 > a->numOfVerts) {
		printf("��������");
		return -1;
	}
	p = a->adjG;
	for (i; i < v1; i++) {
		p = p->next;
	}
	e = p->adj;
	while (e != NULL) {
		if (e->dest != v2) {
			e = e->next;
			continue;
		}
		break;
	}
	e = e->next;
	if (e != NULL)return e->dest;
	return -1;
}

Edge * getVertexAdj(AdjGraph *a, unsigned int n) {
	int i = 1;
	AdjContain *p = a->adjG;
	if (n < 0 || n >= a->numOfVerts) {
		printf("��������");
		return NULL;
	}
	while (i != n) {
		p = p->next;
	}
	return p->adj;
}

void AdjDestroy(AdjGraph *a) {
	int i = 0;
	Edge *p, *q;
	AdjContain *e, *b;
	for (; i < a->numOfVerts; i++) {
		e = a->adjG;
		p = e->adj;
		while (p != NULL) {
			q = p->next;
			free(p);
			p = q;
		}
		b = e->next;
		free(e);
		e = b;
	}
}


//��ӡ��ǵ�destroy��
int **getAdjRec(AdjGraph *a) {
	unsigned int row = 0, col = 0;
	AdjContain *temp;
	Edge *e;
	int **p = (int **)malloc(sizeof(int*)*(a->numOfVerts));
	for (row = 0; row < a->numOfVerts; row++) {
		p[row] = (int *)malloc(sizeof(int)*(a->numOfVerts));
	}

	for (row = 0; row < a->numOfVerts; row++) {
		for (col = 0; col < a->numOfVerts; col++) {
			if (row == col)
				p[row][col] = 0;
			else
				p[row][col] = MaxRoad;
		}
	}


	temp = a->adjG;
	row = 0;
	while (temp != NULL) {
		e = temp->adj;
		while (e != NULL) {
			if (e->dest) {
				p[row][e->dest - 1] = e->distance;
			}
			e = e->next;
		}
		temp = temp->next;
		row++;
	}

	return p;
}


void AdjRecDestroy(int **p, unsigned int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	free(p);
}

void printAdjRec(AdjGraph *a) {
	int row, col;
	AdjContain *p = a->adjG;
	int **map = getAdjRec(a);
	printf("  ");
	for (row = 0; row < a->numOfVerts; row++) {
		printf("%5s     ", p->data);
		p = p->next;
	}
	printf("\n");
	p = a->adjG;
	for (row = 0; row < a->numOfVerts; row++) {
		printf("%s:", p->data);
		for (col = 0; col < a->numOfVerts; col++) {
			printf("%5d     ", map[row][col]);
		}
		p = p->next;
		printf("\n");
	}
	AdjRecDestroy(map, a->numOfVerts);
}

void printAdjLink(AdjGraph *a) {
	int row = 0, col = 0;
	AdjContain *temp;
	Edge *e;
	temp = a->adjG;
	while (temp != NULL) {
		e = temp->adj;
		printf("����%d:%s", temp->source, temp->data);
		while (e != NULL) {
			if (e->dest) {
				printf("->����%d����ص�%d", e->distance, e->dest);
			}
			e = e->next;
			col++;
		}
		printf("\n");
		temp = temp->next;
		row++;
	}
}



void Floyd(AdjGraph a, int **weight, int **path) {
	int i, j, k, n = a.numOfVerts;
	int **map = getAdjRec(&a);
	//����ʼֵ
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			weight[i][j] = map[i][j];
			path[i][j] = -1;
		}
	}


	//��ȡ���·������ʶ���·��ǰһ�����
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (weight[i][j] > weight[i][k] + weight[k][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int **CreatArray(AdjGraph *a) {
	int row;
	int **p = (int **)malloc(sizeof(int*)*(a->numOfVerts));
	for (row = 0; row < a->numOfVerts; row++) {
		p[row] = (int *)malloc(sizeof(int)*(a->numOfVerts));
	}
	return p;
}


//ɾ���ṹ�����ɾ�������Ѿ�����ռ������,���������ط����ù���ɾ�����ֵҲӦ�ý�������޸�
void deleteVex(AdjGraph *a, unsigned int n) {
	AdjContain *temp = a->adjG, *pre = NULL;
	int count = 1,source;
	Edge *t;
	if (n > a->numOfVerts || n <= 0)return;
	while (count != n) {
		if (count == n)
			break;
		pre = temp;
		temp = temp->next;
		count++;
	}


	t = temp->adj;
	source = temp->source;
	while (temp->adj) {
		DeleteEdge(a, source, t->dest);
		t = temp->adj;
	}
	free(temp->data);

	if (pre == NULL) {
		a->adjG = temp->next;
	}
	else {
		pre->next = temp->next;
	}

	free(temp);
	a->numOfVerts--;


	temp = a->adjG;
	while (temp != NULL) {
		t = temp->adj;
		while (t) {
			if (t->dest > n) {
				t->dest--;
			}
			t = t->next;
		}
		if (temp->source > n) {
			temp->source--;
		}
		temp = temp->next;
	}


}

void InsertScience(AdjGraph *a) {
	char name[20];
	printf("���뾰������:");
	scanf("%s", name);
	InsertVertex(a,name);
}


void inquiryOfRoute(AdjGraph *a, const unsigned int v1, const unsigned int v2, int *visited, int *saved, int *count) {
	int w, i;
	static int num = 0;
	visited[v1 - 1] = 1;
	w = GetFirstVex(a, v1);
	saved[*count] = w;
	while (w != -1) {
		if (saved[*count] == v2) {
			i = 0;
			while (saved[i] != v2) {
				i++;
			}
			if (i == *count) {
				num++;
				printf("·��%d:", num);
				for (i = 0; i < a->numOfVerts; i++) {
					if (saved[i] != v2)
						printf("%d->", saved[i]);
					else
						break;
				}
				printf("%d", v2);
				printf("\n");
			}
		}

		if (!visited[w - 1]) {
			(*count)++;
			inquiryOfRoute(a, w, v2, visited, saved, count);
		}


		if (w != -1) {
			w = GetNextVex(a, v1, w);
			saved[*count] = w;
		}
	}
	saved[*count] = 0;
	(*count)--;
}

void ShortPathCost(AdjGraph *a,const unsigned int v1, const unsigned int v2, int **weight, int **path) {
	int pointRow = v1, pointCol = v2;
		if (path[pointRow][pointCol] == -1) {
			printf("->%d", v2 + 1);
			return;
		}
		else {
			//��ȵݹ����ҳ�ͨ���õ���һ���������·����Ȼ���������õ��ظ��ù���
			pointCol = path[pointRow][pointCol];
			ShortPathCost(a, pointRow, pointCol, weight, path);
			pointRow = pointCol;
			pointCol = v2;
			ShortPathCost(a, pointRow, pointCol, weight, path);
		}
}

int getShortPathCost(AdjGraph *a, const unsigned int v1, const unsigned int v2) {
	int **weight, **path;
	int minCost = 0, row;
	int pointRow = v1 - 1,pointCol = v2 - 1;
	weight = (int **)malloc(sizeof(int*)*(a->numOfVerts));
	for (row = 0; row < a->numOfVerts; row++) {
		weight[row] = (int *)malloc(sizeof(int)*(a->numOfVerts));
	}
	path = (int **)malloc(sizeof(int*)*(a->numOfVerts));
	for (row = 0; row < a->numOfVerts; row++) {
		path[row] = (int *)malloc(sizeof(int)*(a->numOfVerts));
	}

	//��ȡ���·��ֵ�Լ�ÿ�����·��ǰһ�����
	Floyd(*a, weight, path);


	minCost = weight[pointRow][pointCol];

	printf("%d", v1);
	ShortPathCost(a, pointRow, pointCol, weight, path);


	AdjRecDestroy(weight, a->numOfVerts);
	AdjRecDestroy(path, a->numOfVerts);
	return minCost;
}



int fullOfVisited(AdjGraph *a,int *visited) {
	int i;
	for (i = 0; i < a->numOfVerts; i++) {
		if (!visited[i])
			return 0;
	}
	return 1;
}

int countCost(AdjGraph *a,int *saved) {
	int i,cost=0;
	int **map = getAdjRec(a);
	for (i = 1; i < saved[0]; i++) {
		cost += map[saved[i] - 1][saved[i + 1] - 1];
	}
	AdjRecDestroy(map, a->numOfVerts);
	return cost;
}

void copyArray(int *saved, int *truth) {
	int n;
	for (n = 0; n <= saved[0]; n++) {
		truth[n] = saved[n];
	}
}

int getCount(AdjGraph *a) {
	int i,j,sum=0;
	int **map = getAdjRec(a);
	for (i = 0; i < a->numOfVerts; i++) {
		for (j = 0; j < a->numOfVerts; j++) {
			if (map[i][j] != 0 && map[i][j] != MaxRoad)
				sum++;
		}
	}
	AdjRecDestroy(map, a->numOfVerts);
	return sum;
}

void getgetget(AdjGraph *a, const unsigned int v, int *visited, int *saved, int *count ,int *minCost, int *truth) {
	int w;
	static int num = getCount(a);
	visited[v - 1] = 1;
	w = GetFirstVex(a, v);
	saved[*count] = w;
	while (w != -1) {

		if (fullOfVisited(a,visited)) {
			if ((*minCost) > countCost(a, saved) && saved[0] == a->numOfVerts) {
				*minCost = countCost(a, saved);
				copyArray(saved, truth);
			}
		}

		if (!visited[w - 1]) {
			(*count)++;
			saved[0]++;
			getgetget(a, w, visited, saved, count, minCost,truth);
		}


		if (w != -1) {
			w = GetNextVex(a, v, w);
			saved[*count] = w;
		}
	}
	visited[v - 1] = 0;
	saved[0]--;
	saved[*count] = 0;
	(*count)--;
}



void getRoadoo(AdjGraph *a, const unsigned int v, const unsigned int v1, const unsigned int v2, int *visited, int *saved, int *count, int *minCost) {
	int w, i;
	static int num = getCount(a);
	static int sum = 0;
	//visited��ȡ�Ƿ񾭹��õ�
	visited[v - 1] = 1;
	w = GetFirstVex(a, v);
	//��ȡ�Ѿ��߹��ĵ�
	saved[*count] = w;
	while (w != -1) {
		//������Ѱ�ҵĵ㼴����Ѿ��߹��ĵ�
		if (saved[1]== v1 && saved[*count] == v2) {
			i = 1;
			while (saved[i] != v2) {
				i++;
			}
			if (i == *count) {
				sum++;
				printf("·��%d:", sum);
				for (i = 1; i < a->numOfVerts; i++) {
					if (saved[i] != v2)
						printf("%d->", saved[i]);
					else
						break;
				}
				printf("%d", v2);
				printf("\n");
			}
		}


		if (!visited[w - 1]) {
			(*count)++;
			saved[0]++;
			getRoadoo(a, w,v1,v2, visited, saved, count, minCost);
		}


		if (w != -1) {
			w = GetNextVex(a, v, w);
			saved[*count] = w;
		}
	}
	visited[v - 1] = 0;
	saved[0]--;
	saved[*count] = 0;
	(*count)--;
}



char *getPlace(AdjGraph a, int v) {
	AdjContain *p = a.adjG;
	while (v != p->source) {
		p = p->next;
	}
	return p->data;
}


void showAdjMessage(AdjGraph *a) {
	AdjContain *temp;
	temp = a->adjG;
	while (temp != NULL) {
		printf("����%d:%s", temp->source, temp->data);
		printf("\n");
		temp = temp->next;
	}
}

int getRoad(AdjGraph *a, const unsigned int v1, const unsigned int v2) {
	int **weight, **path;
	int minCost = 0, row;
	int pointRow = v1 - 1, pointCol = v2 - 1;
	if (v1 <= 0 || v2 <= 0 )
		return 0;
	weight = (int **)malloc(sizeof(int*)*(a->numOfVerts));
	for (row = 0; row < a->numOfVerts; row++) {
		weight[row] = (int *)malloc(sizeof(int)*(a->numOfVerts));
	}
	path = (int **)malloc(sizeof(int*)*(a->numOfVerts));
	for (row = 0; row < a->numOfVerts; row++) {
		path[row] = (int *)malloc(sizeof(int)*(a->numOfVerts));
	}

	Floyd(*a, weight, path);


	minCost = weight[pointRow][pointCol];
	if (minCost != 0 && minCost != MaxRoad)
		return 1;
	return 0;
}

//**************************************************************************************************\\

void printSomeLink(AdjGraph *a, int v) {
	int row = 0, col = 0;
	AdjContain *temp;
	Edge *e;
	temp = a->adjG;
	while (temp != NULL) {
		if (temp->source == v) {
			e = temp->adj;
			printf("����%d:%s", temp->source, temp->data);
			while (e != NULL) {
				if (e->dest) {
					printf("->����%d����ص�%s   ", e->distance, getPlace(*a,e->dest));
				}
				e = e->next;
				col++;
			}
			printf("\n");
		}
		temp = temp->next;
		row++;
	}
}



void copyPoint(AdjGraph *a, Point *p) {
	int i = 0;
	AdjContain *AdjC = a->adjG;
	while (AdjC != NULL) {
		p[i].col = AdjC->cur.col;
		p[i].row = AdjC->cur.row;
		i++;
		AdjC = AdjC->next;
	}
}

void randRight(const Point *pre, Point *p, unsigned int dis) {
	int temp, c = dis - 10;
	if (dis == 0 || dis == MaxRoad)
		return;
	srand(time(0));
	temp = rand() % c + 10;
	p->row = (pre->row) + temp;
	p->col = (int)sqrt((double)dis*dis - temp*temp);
}

void randLeft(const Point *pre, Point *p, unsigned int dis) {
	int temp, c = dis - 10;
	if (dis == 0 || dis == MaxRoad)
		return;
	srand(time(0));
	temp = rand() % c + 10;
	p->row = (pre->row) - temp;
	p->col = (int)sqrt((double)dis*dis - temp*temp);
}

void randBetween(const Point *p1, const Point *p2, Point *p,int dis1,int dis2){
	Point *r = new Point;
	Point *l = new Point;
	srand(time(0));
	if ((dis1 == 0 || dis1 == MaxRoad) && (dis2 != 0 && dis2 != MaxRoad)) {
		if (p2->row > 320) {
			randLeft(p2, l, dis2);
			p->row = l->row;
			p->col = l->col;
		}
		else {
			randRight(p2, r, dis2);
			p->row = r->row;
			p->col = r->col;
		}
		return;
	}
	else if ((dis2 == 0 || dis2 == MaxRoad) && (dis1 != 0 && dis1 != MaxRoad)) {
		if (p1->row > 320) {
			randLeft(p2, l, dis1);
			p->row = l->row;
			p->col = l->col;
		}
		else {
			randRight(p2, r, dis1);
			p->row = r->row;
			p->col = r->col;
		}
		return;
	}
	else if ((dis1 == 0 || dis1 == MaxRoad)&& (dis2 == 0 || dis2 == MaxRoad)) {
		p->row = rand() % (MaxRow - 200) + 200;
		p->col = rand() % (MaxCol - 200) + 200;
		return;
	}
	if (p1->row < p2->row) {
		randRight(p1, r, dis1);
		randLeft(p2, l, dis2);
	}
	else {
		randLeft(p1, l, dis1);
		randRight(p2, r, dis2);
	}
	p->row = (l->row + r->row) / 2;
	p->col = (l->col + r->col) / 2;
	free(r);
	free(l);
}


void getPoint(AdjGraph *a, int **map, Point *p, int cur) {
	int i = 0, j = 0, row = 0, col = 0;
	Point *t;
	if (cur != 0 && cur != 1)
		t = new Point[cur - 1];

	for (i = 0; i <= cur; i++) {
		if (i == cur) {
			if (i == 0) {
				p[i].col = 200;
				p[i].row = 200;
			}
		    else if (i == 1) {
				randRight(&p[0], &p[i], map[0][i]);
			}
			else {
				for (j = 0; j < cur - 1; j++) {
					randBetween(&p[j], &p[j + 1], &t[j], map[j][cur], map[j + 1][cur]);
				}
				for (j = 0; j < cur - 1; j++) {
					row += t[j].row;
					col += t[j].col;
				}
				if (cur == 2) {
					p[i].row = (int)row;
					p[i].col = (int)col;
				}
				else {
					p[i].row = (int)row / (cur - 2);
					p[i].col = (int)col / (cur - 2);
				}
			}
			break;
		}
	}
}


int pointIsExist(Point *p,const unsigned int cur) {
	int i = 0;
	int row, col;
	for (i = 0; i < cur; i++) {
		if (p[cur].row > p[i].row) {
			row = p[cur].row - p[i].row;
			if (p[cur].col > p[i].col) {
				col = p[cur].col - p[i].col;
			}
			else {
				col = p[i].col - p[cur].col;
			}
		}
		else {
			row = p[i].row - p[cur].row;
			if (p[cur].col > p[i].col) {
				col = p[cur].col - p[i].col;
			}
			else {
				col = p[i].col - p[cur].col;
			}
		}
		if (row < safeDis && col < safeDis)
			return 1;
	}
	return 0;
}


int pointIsNotOver(Point *p, const unsigned int cur) {
	if (((p[cur].row + safeDis > MaxRow) || (p[cur].row - safeDis < 0)) || ((p[cur].col + safeDis > MaxCol) || (p[cur].col - safeDis < 0)))
		return 0;
	return 1;
}


void drawLineOnAdj(AdjGraph *a,Point *p,int **map) {
	int i = 0, j = 0;
	char str[20];
	int ratio,col1,row1,col2,row2,row,col;
	for (i = 0; i < a->numOfVerts; i++) {
		for (j = 0; j < a->numOfVerts; j++) {
			if (map[i][j] != 0 && map[i][j] != MaxRoad) {
				if (p[i].row > p[j].row) {
					if (p[i].col > p[j].col) {
						row = p[i].col - p[j].col;
						col = p[i].row - p[j].row;
						ratio = sqrt(((double)pow(row, 2) + (double)pow(col, 2))) / radius;
						row1 = p[j].row + (row / ratio);
						col1 = p[j].col + (col / ratio);

						row2 = p[i].row - (row / ratio);
						col2 = p[i].col - (col / ratio);
					}
					else {
						col = p[j].col - p[i].col;
						row = p[i].row - p[j].row;
						ratio = sqrt(((double)pow(row, 2) + (double)pow(col, 2))) / radius;
						row1 = p[j].row + (row / ratio);
						col1 = p[j].col - (col / ratio);

	
						row2 = p[i].row - (row / ratio);
						col2 = p[i].col + (col / ratio);
					}
				}
				else {
					if (p[i].col > p[j].col) {
						row = p[i].col - p[j].col;
						col = p[j].row - p[i].row;
						ratio = sqrt(((double)pow(row, 2) + (double)pow(col, 2))) / radius;
						row1 = p[j].row + (row / ratio);
						col1 = p[j].col + (col / ratio);

						row2 = p[i].row - (row / ratio);
						col2 = p[i].col - (col / ratio);
					}
					else {
						col = p[j].col - p[i].col;
						row = p[j].row - p[i].row;
						ratio = sqrt(((double)pow(row, 2) + (double)pow(col, 2))) / radius;
						row1 = p[j].row + (row / ratio);
						col1 = p[j].col - (col / ratio);


						row2 = p[i].row - (row / ratio);
						col2 = p[i].col + (col / ratio);
					}
				}
				itoa(map[i][j], str, 10);
				outtextxy((p[i].row + p[j].row) /2 - 5, (p[i].col + p[j].col) / 2 - 5, str);
				line(p[i].row, p[i].col, p[j].row, p[j].col);
			}
		}
	}
}


void initPoint(AdjGraph *a, Point *p) {
	AdjContain *AdjC = a->adjG;
	int **map = getAdjRec(a);
	int i = 0;
	copyPoint(a, p);
	while (AdjC != NULL) {
		getPoint(a, map, p, i);
		AdjC->cur.col = p[i].col;
		AdjC->cur.row = p[i].row;
		if (!pointIsExist(p, i) && pointIsNotOver(p,i)) {
			AdjC = AdjC->next;
			i++;
		}
	}
}

AdjContain *getAdjPoint(AdjGraph *a,const unsigned int dest) {
	AdjContain *AdjC = a->adjG;
	if (dest <= 0 || dest > a->numOfVerts)
		return NULL;
	while (AdjC != NULL) {
		if (AdjC->source == dest)
			return AdjC;
		AdjC = AdjC->next;
	}
	return NULL;
}

void drawAdjGraph(AdjGraph *a,int flag = 0) {
	initgraph(MaxRow, MaxCol);
	//setcaption()
	int **map;
	Point *p;
	AdjContain *AdjC = a->adjG, *Atemp;
	Edge *temp;
	char str[20];
	int i = 0;
	if (!flag) {
		map = getAdjRec(a);
		p = new Point[a->numOfVerts];
		initPoint(a, p);

		setfont(18, 0, "����");
		setcolor(EGERGB(0xFF, 0xFF, 0x0));
		setfillcolor(EGERGB(0xBB, 0xBF, 0xFF));

		for (i = 0; i < a->numOfVerts; i++) {
			outtextxy(p[i].row - 2, p[i].col + 6, AdjC->data);
			circle(p[i].row, p[i].col, radius);
			floodfill(p[i].row, p[i].col, EGERGB(0xFF, 0xFF, 0x0));
			AdjC = AdjC->next;
		}
		setcolor(EGERGB(0xFF, 0xFF, 0xFF));
		drawLineOnAdj(a, p, map);
		ege::getch();
		AdjRecDestroy(map, a->numOfVerts);
		free(p);
	}
	else {
		AdjContain *AdjC = a->adjG;
		setcolor(EGERGB(0xFF, 0xFF, 0x0));
		setfillcolor(EGERGB(0xBB, 0xBF, 0xFF));
		while(AdjC != NULL) {
			outtextxy(AdjC->cur.row - 2, AdjC->cur.col + 6, AdjC->data);
			circle(AdjC->cur.row, AdjC->cur.col, radius);
			floodfill(AdjC->cur.row, AdjC->cur.col, EGERGB(0xFF, 0xFF, 0x0));
			AdjC = AdjC->next;
		}
		AdjC = a->adjG;
		while (AdjC != NULL) {
			temp = AdjC->adj;
			while (temp != NULL) {
				Atemp = getAdjPoint(a, temp->dest);
				itoa(temp->distance, str, 10);
				outtextxy((AdjC->cur.row + Atemp->cur.row) / 2 - 5, (AdjC->cur.col + Atemp->cur.col) / 2 - 5, str);
				line(AdjC->cur.row, AdjC->cur.col, Atemp->cur.row, Atemp->cur.col);
				temp = temp->next;
			}
			AdjC = AdjC->next;
		}
		ege::getch();
	}
	closegraph();
}




int myPointIsExist(MyGraph *m,const unsigned int row, const unsigned int col) {
	MyPoint  *temp = NULL;
	temp = m->p;
	while (temp != NULL) {
		if (temp->row + safeDis > row && temp->row - safeDis < row) {
			if (temp->col + safeDis > col && temp->col - safeDis < col)
				return 1;
		}
		temp = temp->next;
	}
	return 0;
}

MyPoint *getMyPoint(MyPoint *mp,const unsigned int v) {
	MyPoint *temp = mp;
	while (temp != NULL) {
		if (temp->source == v)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

MyPoint *getMyPoint2(MyPoint *mp, const unsigned int row, const unsigned int col) {
	MyPoint *temp = mp;
	while (temp != NULL) {
		if (temp->row + safeDis > row && temp->row - safeDis < row  && temp->col + safeDis > col && temp->col - safeDis < col)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void InsertMyGraph(AdjGraph *a,MyGraph *m) {
	MyPoint *mp = m->p;
	MyRCD *mr = m->r;
	while (mp != NULL) {
		InsertVertex(a, mp->name, mp->row, mp->col);
		mp = mp->next;
	}
	while (mr != NULL) {
		InsertEdge(a, mr->v1, mr->v2, mr->dis);
		mr = mr->next;
	}
}


int CreatMyGraph(MyGraph *m) {
	initgraph(MaxRow, MaxCol);
	setfont(18, 0, "����");
	int flag = 0;
	int count = 1;
	char str[100];
	MyPoint *mp = NULL, *temp = NULL, *pre = NULL,*linkPoint = NULL;
	MyRCD *mr = NULL, *rtemp = NULL,*rpre;
	mouse_msg msg = { 0 };
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	setfillcolor(EGERGB(0xBB, 0xBF, 0xFF));
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}

		cleardevice();
		if ((int)msg.is_down() && (int)msg.is_left()) {
			if (!myPointIsExist(m, msg.x, msg.y)) {
				temp = (MyPoint *)malloc(sizeof(MyPoint));
				temp->col = msg.y;
				temp->row = msg.x;
				temp->next = NULL;
				temp->source = count;
				inputbox_getline("��������", "������þ�������.���س�ȷ�ϣ�", str, 100);
				temp->name = (char *)malloc(sizeof(char) * sizeof(str));
				strcpy(temp->name, str);
			}
			if (myPointIsExist(m, msg.x,msg.y)) {
				if (flag) {
					if (linkPoint->source == getMyPoint2(m->p, msg.x, msg.y)->source)
						continue;

					rtemp = (MyRCD *)malloc(sizeof(MyRCD));
					rtemp->v1 = linkPoint->source;
					rtemp->v2 = getMyPoint2(m->p, msg.x, msg.y)->source;
					rtemp->next = NULL;
					inputbox_getline("����·����������", "��������������֮�����.���س�ȷ�ϣ�", str, 100);
					rtemp->dis = atoi(str);

					mr = m->r;
					if (mr == NULL) {
						m->r = rtemp;
					}
					else {
						while (mr != NULL) {
							rpre = mr;
							mr = mr->next;
						}
						rpre->next = rtemp;
					}
				}
				if (getMyPoint2(m->p, msg.x, msg.y)!=NULL) {
					linkPoint = getMyPoint2(m->p, msg.x, msg.y);
					flag = 1;
				}
				continue;
			}
			mp = m->p;
			if (mp == NULL) {
				m->p = temp;
			}
			else {
				while (mp != NULL) {
					pre = mp;
					mp = mp->next;
				}
				pre->next = temp;
			}
			count++;
			flag = 0;
		}


		mp = m->p;
		while (mp != NULL) {
			setcolor(EGERGB(0xBB, 0xFF, 0x0));
			outtextxy(mp->row - 2, mp->col + 6, mp->name);
			circle(mp->row, mp->col, radius);
			floodfill(mp->row, mp->col, EGERGB(0xBB, 0xFF, 0x0));
			mp = mp->next;
		}
		mr = m->r;
		while (mr != NULL) {
			if (getMyPoint(m->p, mr->v1) == NULL || getMyPoint(m->p, mr->v2) == NULL) {
				mr = mr->next;
				continue;
			}
			pre = getMyPoint(m->p, mr->v1);
			temp = getMyPoint(m->p, mr->v2);
			itoa(mr->dis, str, 10);
			setcolor(EGERGB(0xFF, 0xFF, 0x0));
			outtextxy((pre->row + temp->row) / 2 - 5, (pre->col + temp->col) / 2 - 5, str);
			line(pre->row, pre->col, temp->row, temp->col);
			mr = mr->next;
		}
		if ((int)msg.is_down() && (int)msg.is_right())
			break;
	}
	closegraph();
	return 0;
}



void CreatLocaleDefault(AdjGraph *a, DataType *name, const unsigned int locale = 10) {
	int i = 0;
	for (i = 0; i < locale; i++) {
		InsertVertex(a, name[i]);
	}
}

void CreatEdgeDefault(AdjGraph *a, RCD *rcd, const unsigned int edge = 15) {
	int i = 0;
	for (i = 0; i < edge; i++) {
		InsertEdge(a, rcd[i].row, rcd[i].col, rcd[i].dis);
	}
}


int CreatGraph(AdjGraph *a, MyGraph *mG) {
	int i = 0;
	int flag = 0;
	char c;
	int choice;
	DataType DTdefault[] = { "A","B","C" ,"D" ,"E" ,"F" ,"G" ,"H" ,"I" ,"J" };
	RCD rcdDefault[] = { { 1,2,20 },{ 1,4,30 },{ 2, 3, 40 },{ 2, 4, 50 } ,{ 4, 5, 45 },{ 3, 7, 50 },{ 3, 6, 70 },{ 5, 6, 35 },{ 6, 9, 25 },{ 9, 10, 70 },{ 10, 8, 30 },{ 7, 8, 30 },{ 8, 9, 75 },{ 7, 9, 80 },{ 2, 5, 60 } };
	c = ::getch();
	choice = (int)c - '0';
	switch (choice) {
	case 0:
		CreatLocaleDefault(a, DTdefault);
		CreatEdgeDefault(a, rcdDefault);
		flag = 0;
		break;
	case 1:
		CreatMyGraph(mG);
		InsertMyGraph(a, mG);
		flag = 1;
		break;

	}
	return flag;
}

void freeAdjGraph(AdjGraph *a) {
	int i = 0,temp=a->numOfVerts;
	for (i = 0; i < temp; i++)
		deleteVex(a, i);
}

void MyGraphInit(MyGraph *mG) {
	mG->p = NULL;
	mG->r = NULL;
}

//**************************************************************************************************\\


//a���������ˡ�
//����ͼ
void menu(void)           //�ṩѡ��Ĳ˵�����
{
	char c;
	AdjGraph *a = NULL;
	int *visit, *save,*truth;
	int choice;
	int minCost;
	int flag = 0;
	char ch;
	MyGraph *mG	= (MyGraph *)malloc(sizeof(MyGraph));
	int count = 1;
	int  v1, v2, dis, i;
	int size = 0;
	a = AdjGinit();
	MyGraphInit(mG);
	while (1) {
		printf("*******************************************************************************\n");
		printf("* [0] �˳�                    [1]  ������ͼ            [2]  ���뾰��          *\n");
		printf("* [3] ɾ������                [4]  ����·�߲�ѯ        [5]  ·���ۺϲ�ѯ      *\n");
		printf("* [6] ���ھ����ѯ            [7]  �ڽӾ���            [8]  �ڽ�ͼ            *\n");
		printf("* [9] ��ͨ����                [s]  ����չʾ            [q]  �������·��ȷ��  *\n");
		printf("* [ ] ���������Ϣ                                                            *\n");
		printf("*******************************************************************************\n");
		c = ::getch();
		choice = (int)c - '0';
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			flag = CreatGraph(a, mG);
			break;
		case 2:
			InsertScience(a);
			break;
		case 3:
			printf("������Ҫɾ�������������:");
			scanf("%d", &v1);
			deleteVex(a, v1);
			break;
		case 4:
			printf("������Ҫ��ѯ�����������:");
			scanf("%d", &v1);
			for (i = 1; i <= a->numOfVerts; i++) {
				if (i != v1) {
					printf("����%s������%s���·��Ϊ:", getPlace(*a, v1), getPlace(*a, i));
					minCost = getShortPathCost(a, v1, i);
					printf("����%d·��", minCost);
					printf("\n");
				}
			}
			break;
		case 5:
			printf("������Ҫ��ѯ����1�������:");
			scanf("%d", &v1);
			printf("������Ҫ��ѯ����2�������:");
			scanf("%d", &v2);
			visit = (int *)calloc(sizeof(int)*a->numOfVerts, sizeof(int));
			save = (int *)calloc(sizeof(int)*a->numOfVerts, sizeof(int));
			save[0] = 1;
			save[1] = v1;
			count = 2;
			minCost = MaxRoad;
			getRoadoo(a, v1,v1,v2, visit, save, &count, &minCost);
			
			printf("���·��Ϊ");
			minCost = getShortPathCost(a, v1, v2);
			printf("����%d·��", minCost);
			free(visit);
			free(save);

			break;
		case 6:
			printf("������Ҫ��ѯ�����������:");
			scanf("%d", &v1);
			printSomeLink(a, v1);
			break;
		case 7:
			printAdjRec(a);
			break;
		case 8:
			printAdjLink(a);
			break;
		case 9:
			printf("�밴Ҫ�����뾰��1�;���2֮��ľ���({1,2,20})��");
			while ((ch = getchar()) != '\n' && ch != EOF);
			scanf("{%d,%d,%d}", &v1, &v2, &dis);
			InsertEdge(a, v1, v2, dis);
			break;
		case ((int)'s' - (int)'0'):case ((int)'S' - (int)'0'):
			drawAdjGraph(a,flag);
			break;
		case ((int)'q' - (int)'0'):case ((int)'Q' - (int)'0'):
			printf("������Ҫ��ѯ�����������:");
			scanf("%d", &v1);
			visit = (int *)calloc(sizeof(int)*a->numOfVerts, sizeof(int));
			save = (int *)calloc(sizeof(int)*a->numOfVerts, sizeof(int));
			truth = (int *)calloc(sizeof(int)*a->numOfVerts, sizeof(int));
			save[0] = 1;
			save[1] = v1;
			count = 2;
			minCost = MaxRoad;
			getgetget(a, v1,visit,save,&count,&minCost,truth);
			for (i = 1; i < truth[0]; i++)
				printf("%d->", truth[i]);
			
			if (getRoad(a, truth[i], v1)) 
				getShortPathCost(a, truth[i], v1);
			
			free(visit);
			free(save);
			
			break;
		case ((int)' ' - (int)'0'):
			showAdjMessage(a);
			break;
		}
		printf("\n");
	}
}




int main(void) {
	menu();

	return 0;
}