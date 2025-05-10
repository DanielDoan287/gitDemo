#include<stdio.h>
#define M 50

//Graph 
typedef struct{
    int n, m;
    int A[M][M];
}Graph;

void init_graph(Graph *G, int n, int m){
    int u, v;
    G->n = n;
    G->m = m;
    for (u = 1; u <= n; u++){
        for (v = 1; v <= n; v++)
            G->A[u][v] =0;
    }
}

void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v] = w;
}

//Global variables
int pi[M];
int p[M] = {0};
int mark[M] = {0};

//dijkstra
void dijkstra (Graph *G, int s){
    int k, u, v;
    for ( u = 1; u <= G->n; u++)
        pi[u] = 99999;
    pi[s] = 0;

    for ( k = 1; k < G->n; k++){
        int minW = 99999;
        int index;
       for ( u = 1; u <= G->n; u++){
           if (pi[u] < minW && !mark[u]){
                index = u;
                minW = pi[u];
           }
       }
        mark[index] = 1;
        for ( v = 1; v <= G->n; v++){
            if (G->A[index][v] && !mark[v] && pi[index] + G->A[index][v] < pi[v]){
                pi[v] = pi[index] + G->A[index][v];
                p[v] = index;
            }
        }
    }
    
    if (pi[G->n] == 99999)
        printf("-1");
    else
        printf("Quang duong ngan nhat tu dinh 1 den dinh %d = %d\n", G->n, pi[G->n]);
}
//main
int main(){
    int n, m, i;
    Graph G;    
    
    scanf("%d %d",&n, &m);
    init_graph(&G, n, m);
    
    for (i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d",&u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    dijkstra(&G, 1);
    int path = n;
    printf("Duong di: ");
    while (path != 1){
    	printf("%d ", path);
    	path = p[path];
	}
}
