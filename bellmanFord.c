#include<stdio.h>
#define MAX_VERTICES 50

//Edge
typedef struct{
    int u, v, w;
}Edge;

//Graph
typedef struct{
    int n, m;
    Edge e[MAX_VERTICES];
}Graph;

void init_graph(Graph *G, int n, int m){
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w){
    G->e[G->m].u = u;
    G->e[G->m].v = v;
    G->e[G->m].w = w;
    G->m++;
}

//Global variables
int pi[MAX_VERTICES];
int p[MAX_VERTICES];
int nev_cycled = 0;

//bellManFord
void bellManFord(Graph *G, int x){
    
    p[x] = -1;
    pi[x] = 0;
    
    for (int i = 1; i <= G->n; i++){
        for (int e = 0; e < G->m; e++){
            int u = G->e[e].u;
            int v = G->e[e].v;
            int w = G->e[e].w;
            if (pi[u] + w < pi[v]){
                pi[v] = pi[u] +w;
                p[v] = u;
            }
        }
    }
    for (int e = 0; e < G->m; e++){
        int u = G->e[e].u;
        int v = G->e[e].v;
        int w = G->e[e].w;
        if (pi[u] + w < pi[v]){
            nev_cycled = 1; 
            break;
        }
    }
    
}
//main
int main(){
    int n, m;
    Graph G;

    scanf("%d %d", &n, &m);
    init_graph(&G, n, m);
    for (int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    for (int u = 1; u <= n; u++){
        pi[u] = 9999;
        p[u] = -1;
    }
    bellManFord(&G, 1);
    for (int u = 1; u <= n; u++)
        printf("pi[%d] = %d, p[%d] = %d\n", u, pi[u], u, p[u]);
    
}
