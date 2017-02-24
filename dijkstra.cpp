#include<iostream>
#include <cstdlib>
    using namespace std;

 
   //  * Adjacency List Node
    struct adjlistnode
    {
        int dest;
		int weight;
        struct adjlistnode* next;
    };
     //* Adjacency List
    struct adjlist
    {
     struct adjlistnode *head;
    };

    //struct Graph
    struct Graph
    {
    
            int V;
            struct adjList* array;
	};
           
	struct graph* creategraph(int v)
            {   graph* grapp = new Graph;
                grapp->V = v;
                grapp->array = new AdjList [V];
                for (int i = 0; i < V; ++i)
                    grapp->array[i].head = NULL;
				
				return grapp;
				
            }
              //Creating New Adjacency List Node
  adjlistnode* newadjlistnode(int dest, int weight)
   {
               adjlistnode* newnode = new adjlistnode;
               newnode->dest = dest;
			   newnode->weight=weight;
                newnode->next = NULL;
               return newnode;

    }
            //Adding Edge to Graph
            void addEdge(int src, int weight, int dest)
            {
                adjlistnode* newnode = newadjlistnode(dest,weight);
                newnode->next = grapp->array[src].head;
                grapp->array[src].head = newnode;
                newnode = newadjlistnode(src,weight);
                newnode->next = grapp->array[dest].head;
                grapp->array[dest].head = newnode;
            }
//Print the graph
         /*   void printGraph()
            {
                int v;
                for (v = 0; v < V; ++v)
                {
                    adjlistnode* pCrawl = array[v].head;
                    cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                    while (pCrawl)
                    {
                       cout<<"-> "<<pCrawl->dest<<"("<<pCrawl->weight<<")";
                        pCrawl = pCrawl->next;
                    }
                    cout<<endl;
                }
            }
		 */
    
	// Structure to represent a min heap node
struct MinHeapNode
{
    int x; 
    int dist;
};
 
// Structure to represent a min heap
struct MinHeap
{
    int size;      // Number of heap nodes present currently
    int capacity;  // Capacity of min heap
    int *pos;     // This is needed for decreaseKey()
    struct MinHeapNode **array;
};
 
// A utility function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int x, int dist)
{
    struct MinHeapNode* minHeapNode =
           (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->x = x;
    minHeapNode->dist = dist;
    return minHeapNode;
}
 
// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
 
// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
      smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
      smallest = right;
 
    if (smallest != idx)
    {
        // The nodes to be swapped in min heap
struct        MinHeapNode *smallestNode = minHeap->array[smallest];
struct        MinHeapNode *idxNode = minHeap->array[idx];
 
        // Swap positions
        minHeap->pos[smallestNode->x] = idx;
        minHeap->pos[idxNode->x] = smallest;
 
        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}
 
// A utility function to check if the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}
 
// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
 
    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];
 
    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 
    // Update position of last node
    minHeap->pos[root->x] = minHeap->size-1;
    minHeap->pos[lastNode->x] = 0;
 
    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}
	void decreaseKey(struct MinHeap* minHeap, int x, int dist)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[x];
 
    // Get the node and update its dist value
    minHeap->array[i]->dist = dist;
 
    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->x] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->x] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
 
        // move to parent index
        i = (i - 1) / 2;
    }
}
 
// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int x)
{
   if (minHeap->pos[x] < minHeap->size)
     return true;
   return false;
}
	// dijkstras algo
	void dijkstra(int V){
		for (int i=0; i<V; i++)
		{
			mark[i]=0;
			dist[i]=8000;
		}
		mark [0]=1 ; dist[0]=0;
		
	}
	
	void printArr(int dist[], int n)
{
int i;    
//printf("Vertex   Distance from Source\n");
    //for ( i = 0; i < n; ++i)
if(dist[n]==INT_MAX)
printf("NO\n");
else
{       
printf("YES\n");
printf("%d\n",dist[n]);
}
}



//Dijkstras function
// vertices. It is a O(ELogV) function
void dijkstra(struct graph* grapp, int src,int node2)
{
    int V = grapp->v;// Get the number of vertices in graph
    int dist[V],v;      // dist values used to pick minimum weight edge in cut
 
    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);
 
    // Initialize min heap with all vertices. dist value of all vertices 
    for ( v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
 
    // Make dist value of src vertex as 0 so that it is extracted first
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
 
    // Initially size of min heap is equal to V
    minHeap->size = V;
 
    // In the followin loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum distance value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->x; // Store the extracted vertex number
 
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        struct adjlistnode* pCrawl = grapp->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
 
            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
                                          pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
 
                // update distance value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
 
    // print the calculated shortest distances
    printArr(dist, node2);
}

//main
    int main()
    { int M,A,B;
	  int srcM, weightM, destM;
	cin>>M>>A>>B;
	if (M>4000000)
	{cout<<"Abort";
	 exit(0);
	}
	
	Graph gh(B-A+1);//B-A+1 numbr of vertices present in graph
	for(M;M>0;M--){
		cin>>srcM>>weightM>>destM;
        gh.addEdge(srcM, weightM, destM);
	}
    dijkstra(grapp,A,B);

    // print the adjacency list representation of the above graph
       //gh.printGraph();
     
  return 0;

    }
