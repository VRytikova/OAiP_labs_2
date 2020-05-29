#include <iostream>

using namespace std;

// Структура для представления списка смежности узла
struct AdjListNode
{
	int dest;
	int rebro;
	struct AdjListNode* next;
	struct AdjListNode* head;//указатель на головной узел списка
};
// Структура для представления графа. Граф представляет собой массив из списков смежности.
// Размер массива будет V (число вершин в графе) 
struct Graph
{
	int V;
	struct AdjListNode* mas;
};

int menu();
void instruction();
struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int, int);
struct AdjListNode* newAdjListNode(int);
void printGraph(struct Graph*);
void del_rebro(struct Graph*);
void del_vertex(struct Graph*);
void del_rebro_dest(struct Graph*);
void matrix(struct Graph*);

int matr[7][7];


void main()
{
	instruction();
}


void instruction()
{
	int x;
	int V = 8;
	struct Graph* graph = createGraph(V);

	addEdge(graph, 1, 7, 2);
	addEdge(graph, 1, 8, 4);
	addEdge(graph, 1, 2, 3);
	addEdge(graph, 2, 1, 3);
	addEdge(graph, 2, 7, 2);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 2, 1);
	addEdge(graph, 3, 4, 3);
	addEdge(graph, 3, 5, 4);
	addEdge(graph, 4, 3, 3);
	addEdge(graph, 4, 5, 2);
	addEdge(graph, 4, 6, 1);
	addEdge(graph, 5, 2, 4);
	addEdge(graph, 5, 3, 4);
	addEdge(graph, 5, 4, 2);
	addEdge(graph, 5, 6, 7);
	addEdge(graph, 5, 7, 7);
	addEdge(graph, 5, 8, 6);
	addEdge(graph, 6, 4, 1);
	addEdge(graph, 6, 5, 7);
	addEdge(graph, 6, 8, 3);
	addEdge(graph, 7, 1, 2);
	addEdge(graph, 7, 2, 2);
	addEdge(graph, 7, 5, 7);
	addEdge(graph, 7, 8, 2);
	addEdge(graph, 8, 1, 4);
	addEdge(graph, 8, 5, 6);
	addEdge(graph, 8, 6, 3);
	addEdge(graph, 8, 7, 2);
	

	do
	{
		menu();
		cin >> x;
		switch (x)
		{
		case 1: printGraph(graph);
			break;
		case 2: for (int i = 0; i < V; i++)
			del_rebro(graph);
			printGraph(graph);
			break;
		case 3: del_vertex(graph);
			printGraph(graph);
			break;
		case 4: matrix(graph);
			break;
		default: exit(1);
		}
	} while (x <= 7);
}


int menu()
{
	
	cout<<"Menu:"<<endl;
	cout << "1.enter graph" << "\n" << "2.delete edge number 2" << "\n" << "3.delete vertex 7" << "\n" << "4.show connectivity  matrix" << endl;
	cout << "Choose: ";

	return 0;
}


//Служебная функция, которая создаёт граф с V вершинами
struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V; //присваивание вершины
				  // Создание массива списков смежности. Размер массива будет V 
	graph->mas = (struct AdjListNode*) malloc(V * sizeof(struct AdjListNode)); //выделение памяти под вершины
																			   // Инициализация каждого списка смежности как пустого, сделав начало=NULL
	int i;
	for (i = 0; i < V; i++)
		graph->mas[i].head = NULL;

	return graph;
}


//Добавляет ребро неориентированного графа
void addEdge(struct Graph* graph, int src, int dest, int rebro)
{
	// Добавляет ребро из src в построение. Новый узел добавляется в список смежности
	// Список src.Узел добавляется в начале
	struct AdjListNode* newNode = newAdjListNode(dest); //выделение памяти под узел вершины
	newNode->next = graph->mas[src - 1].head;//данные помещаем в mas[src-1].head
	newNode->rebro = rebro;
	graph->mas[src - 1].head = newNode;//теперь graph->mas[src-1].head указывает на новое значение 
}


// вспомогательная функция для создания узла нового списка смежности
struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

void printGraph(struct Graph* graph)
{
	cout<<"vertex[edge]"<<endl;
	for (int v = 0; v < graph->V; v++)
	{
		struct AdjListNode* pCrawl = graph->mas[v].head;

		if (pCrawl == NULL)
		{
			if (graph->mas[v].dest == -1) cout<<"vertex "<< v+1<<" is deleted"<<endl;
			else cout<<"vertex"<< v+1<<" does not connected with others"<<endl;
		}
		else
		{
			cout<<"vertex "<<v+1<<" is connected with: ";
			while (pCrawl != NULL)
			{
				cout<< pCrawl->dest<<"["<< pCrawl->rebro<<"]  ";
				pCrawl = pCrawl->next;
			}
			printf("\n");
		}
	}
}

void del_rebro(struct Graph* graph)
{
	int v;
	int key;
	struct AdjListNode* pCrawl;
	struct AdjListNode* Prev;
	struct AdjListNode* Curr;
	struct AdjListNode* Temp;

	/*cout << "which one: ";
	cin >> key;*/
	for (v = 0; v < graph->V; v++)
	{
		pCrawl = graph->mas[v].head;

		if (pCrawl == NULL) continue;
		
		if (pCrawl->rebro == 2)
		{
			Temp = pCrawl;
			pCrawl = pCrawl->next;
			graph->mas[v].head = pCrawl;
			free(Temp);
		}
		else
		{
			Prev = pCrawl;
			Curr = pCrawl->next;

			while (Curr != NULL && Curr->rebro != 2)
			{
				Prev = Curr;
				Curr = Curr->next;
			}
			if (Curr != NULL)
			{
				Temp = Curr;
				Prev->next = Curr->next;
				free(Temp);
			}
		}
	}
}

void del_vertex(struct Graph* graph)
{
	int v;
	struct AdjListNode* Curr;
	struct AdjListNode* Temp;

	del_rebro(graph);

	Curr = graph->mas[6].head;

	while (Curr != NULL)
	{
		Temp = Curr;
		Curr = Curr->next;
		free(Temp);
	}
	graph->mas[6].head = NULL;
	graph->mas[6].dest = -1;
}

void del_rebro_dest(struct Graph* graph)
{
	int v;
	struct AdjListNode* pCrawl;
	struct AdjListNode* Prev;
	struct AdjListNode* Curr;
	struct AdjListNode* Temp;

	for (v = 0; v < graph->V; v++)
	{
		pCrawl = graph->mas[v].head;

		if (pCrawl == NULL) continue;

		if (pCrawl->dest == 7)
		{
			Temp = pCrawl;
			pCrawl = pCrawl->next;
			graph->mas[v].head = pCrawl;
			free(Temp);
		}
		else
		{
			Prev = pCrawl;
			Curr = pCrawl->next;

			while (Curr != NULL && Curr->dest != 7)
			{
				Prev = Curr;
				Curr = Curr->next;
			}
			if (Curr != NULL)
			{
				Temp = Curr;
				Prev->next = Curr->next;
				free(Temp);
			}
		}
	}
}

void matrix(struct Graph* graph)
{
	for (int i = 0; i < 8; i++)
	{
		(matr[i], 0, 8 * sizeof(int));
	}
	for (int i = 0; i < 8; i++)
	{
		struct AdjListNode* node = graph->mas[i].head;
		if (!node)  continue;
		while (node) {
			matr[i][node->dest - 1] = 1;
			node = node->next;
		}
	}

	cout<<"Connectivity matrix:"<<endl;

	for (int i = 0; i < 8; i++)
	{
		if (graph->mas[i].dest == -1) continue;
		for (int j = 0; j < 8; j++) {
			if (graph->mas[j].dest == -1) continue;
			cout<<matr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
