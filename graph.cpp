#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <regex>

using namespace std;

typedef struct TAG_EDGE {
	int edge_ID;
	int vertex_u;
	int vertex_v;
	int weight;
	struct Edge* next;
}EDGE;

int main(int argc, char* argv[])
{
	const char* graph = argv[1];
	const char* direction = argv[2];

	if (strcmp(direction, "directed") != 0 && strcmp(direction, "undirected") != 0)
		throw invalid_argument("graph direction invalid or not specified\n");

	FILE* afile = fopen(graph, "r");
	if (!afile)
		throw invalid_argument("cannot open file for reading or file does not exist\n");

	int vertices, edges;
	fscanf(afile, "%d, %d", &vertices, &edges);
	
	EDGE*** arrays = new EDGE**[vertices];

	for (int i = 0; i < vertices; i++)
	{
		EDGE **array = new EDGE*[vertices];
		arrays[i] = array;
	}

	int edgeID, vertexU, vertexV;
	float weight;

	for (int i = 0; i < edges; i++)
	{
		int flag = 0;
		int flag2 = 0;
		fscanf(afile, "%d %d %d %f", &edgeID, &vertexU, &vertexV, &weight);
		EDGE* edge = (EDGE*)malloc(sizeof(EDGE));
		edge->edge_ID = edgeID;
		edge->vertex_u = vertexU;
		edge->vertex_v = vertexV;
		edge->weight = weight;
		if (strcmp(direction, "directed"))
		{
			EDGE**arrayToInsert = arrays[vertexU];
			for (int j = 0; j < vertices; j++)
			{
				if (arrayToInsert[j] == NULL && flag == 0)
				{
					arrayToInsert[j] = edge;
					flag = 1;
				}
				flag = 0;
			}
			arrays[vertexU] = arrayToInsert;
		}
		if (strcmp(direction, "undirected"))
		{
			EDGE** arrayToInsert = arrays[vertexU];
			EDGE** arrayToInsert2 = arrays[vertexV];
			for (int j = 0; j < vertices; j++)
			{
				if (arrayToInsert[j] == NULL && flag == 0)
				{
					arrayToInsert[j] = edge;
					flag = 1;
				}

				if (arrayToInsert2[j] == NULL && flag2 == 0)
				{
					edge->vertex_v = vertexU;
					edge->vertex_u = vertexV;
					arrayToInsert2[j] = edge;
					flag2 = 1;
				}
				arrays[vertexU] = arrayToInsert;
				arrays[vertexV] = arrayToInsert2;
				flag = 0;
				flag2 = 0;
			}
		}
		
	}

}
