#include <stdio.h>

#define MAX_VERTICES 100

struct Graph
{
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void addEdge(struct Graph *graph, int u, int v)
{
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void welshPowell(struct Graph *graph)
{
    int degree[MAX_VERTICES] = {0};
    int i, j, k;

    // Calculate the degree of each vertex
    for (i = 0; i < graph->vertices; i++)
    {
        for (j = 0; j < graph->vertices; j++)
        {
            if (graph->adjMatrix[i][j] == 1)
                degree[i]++;
        }
    }

    int sorted_vertices[MAX_VERTICES];

    // Initialize vertices in sorted order of degrees
    for (i = 0; i < graph->vertices; i++)
        sorted_vertices[i] = i;

    // Sort vertices in decreasing order of degree using bubble sort
    for (i = 0; i < graph->vertices - 1; i++)
    {
        for (j = 0; j < graph->vertices - i - 1; j++)
        {
            if (degree[sorted_vertices[j]] < degree[sorted_vertices[j + 1]])
            {
                int temp = sorted_vertices[j];
                sorted_vertices[j] = sorted_vertices[j + 1];
                sorted_vertices[j + 1] = temp;
            }
        }
    }

    // Initialisation de toutes les couleurs
    int color[MAX_VERTICES];
    for (i = 0; i < graph->vertices; i++)
        color[i] = -1; // Properly initialize all vertices as uncolored

    int current_color = 0;

    // pour colorier tous les sommets non adjacents avant d’incrémenter la couleur
    for (i = 0; i < graph->vertices; i++)
    {
        int vertex = sorted_vertices[i];
        if (color[vertex] == -1)
        {
            color[vertex] = current_color; // Color the first uncolored vertex

            // Colorier les autres sommets qui ne sont pas adjacents
            for (j = i + 1; j < graph->vertices; j++)
            {
                int other = sorted_vertices[j];
                if (color[other] == -1)
                {
                    int canColor = 1;

                    // Vérifier l’adjacence avec les sommets déjà colorés avec la couleur courante
                    for (k = 0; k < graph->vertices; k++)
                    {
                        if (graph->adjMatrix[other][k] == 1 && color[k] == current_color)
                        {
                            canColor = 0;
                            break;
                        }
                    }

                    if (canColor)
                        color[other] = current_color;
                }
            }

            current_color++; // Incrémenter la couleur seulement après avoir colorié tous les sommets possibles
        }
    }

    printf("Graph colored using %d colors:\n", current_color);
    for (i = 0; i < graph->vertices; i++)
        printf("Vertex %d: Color %d\n", i, color[i]);
}

int main()
{
    struct Graph graph;
    graph.vertices = 5;

    // Initialser la matrice d'adjacence
    for (int i = 0; i < graph.vertices; i++)
        for (int j = 0; j < graph.vertices; j++)
            graph.adjMatrix[i][j] = 0;

    // Add edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    welshPowell(&graph);

    return 0;
}
