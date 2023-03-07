#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Vertex
{
    public:
        int v;
        Vertex(int vc) {v=vc;}
};

class node
{
    public:
        Vertex v;
        node* next;
        explicit node (Vertex vin): v(vin)
        {
            next=NULL;
        }
};

class Edge
{
    public:
        int v1;
        int v2;
        Edge(Vertex vc,Vertex vc2){v1=vc.v;v2=vc2.v;}
};

class Graph
{
  public:
    int numVertices;
    int numEdges;
    Graph(int nv, int ne) : numVertices(nv), numEdges(ne) { }
    virtual void addEdge(Edge e) = 0;
    virtual int OutDegree(Vertex v) = 0;
    virtual int InDegree(Vertex v) = 0;
    virtual bool reach(Vertex v1, Vertex v2) = 0;
    virtual bool detectCycle() = 0;
  /* Define virtual functions here*/ 
};

/*Define the derived classes here*/
class GraphUsingList: public Graph
{
    public:
        vector<node*> graph;
        int* indegree;
        int* outdegree;
        int* marked;
        int n;
        GraphUsingList(int nv,int ne):Graph(nv,ne)
        {
            for(int i=0;i<nv;i++)
            {
                graph.push_back(NULL);
            }
            indegree = new int[nv];
            outdegree = new int[nv];
            marked = new int[nv];
            for(int i=0;i<nv;i++)
                indegree[i]=0;
            for(int i=0;i<nv;i++)
                outdegree[i]=0;
            n = nv;
        }
        void addEdge(Edge e)
        {
            int vin= e.v1;
            int vout= e.v2;
            node* temp= new node(Vertex(vout));
            node* ptr=graph[vin];
            if(ptr==NULL)
            {
                graph[vin]= temp;
            }
            else
            {
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
            }
            
            outdegree[vin]++;
            indegree[vout]++;
        }
        int OutDegree(Vertex a)
        {
            int vc = a.v;
            return outdegree[vc];
        }
        int InDegree(Vertex a)
        {
            int vc = a.v;
            return indegree[vc];
        }
        void dfs(int v)
        {
            if(marked[v]==0)
            {
                marked[v]=1;
                node* ptr=graph[v];
                while(ptr!=NULL)
                {
                    dfs(ptr->v.v);
                    ptr=ptr->next;
                }
            }
        }
        bool reach(Vertex vin1, Vertex vin2)
        {
            int v1= vin1.v;
            int v2= vin2.v;
            for(int i=0;i<n;i++)
                marked[i]=0;
            dfs(v1);
            return (marked[v2] == 1);
        }
        bool detectCycle()
        {
           for(int i=0;i<n;i++)
                marked[i]=0;
            for(int i=0;i<n;i++)
            {
                if(marked[i]==0)
                {
                    stack<int> s;
                    int instk[n]={0};
                    s.push(i);
                    while(!s.empty())
                    {
                        int k=s.top();
                        if(marked[k]==0)
                        {
                            marked[k]=1;
                            instk[k]=1;
                        }
                        else
                        {
                            if(instk[k]==1)
                            {
                                instk[k]=0;
                            }
                            s.pop();
                        }
                
                        node* temp=graph[k];
                        while(temp!=NULL)
                        {
                            int t=temp->v.v;
                            if(marked[t] && instk[t])
                                return true;
                            else
                                s.push(t);
                            temp=temp->next;
                        }
                    }
                } 
            }
            return false;
        }
};
class GraphUsingMatrix: public Graph
{
    public:
        int ** graph;
        int* indegree;
        int* outdegree;
        int* marked;
        int n;
        GraphUsingMatrix(int nv,int ne):Graph(nv,ne)
        {
            graph = new int*[nv];
            for(int i=0;i<nv;i++)
            {
                graph[i]= new int[nv];
            }
            indegree = new int[nv];
            outdegree = new int[nv];
            for(int i=0;i<nv;i++)
                indegree[i]=0;
            for(int i=0;i<nv;i++)
                outdegree[i]=0;
            n = nv;
        }
        void addEdge(Edge e)
        {
            int vin= e.v1;
            int vout= e.v2;
            outdegree[vin]++;
            indegree[vout]++;
            graph[vin][vout]=1;
        }
        int OutDegree(Vertex a)
        {
            int vc = a.v;
            return outdegree[vc];
        }
        int InDegree(Vertex a)
        {
            int vc = a.v;
            return indegree[vc];
        }
        void dfs(int v)
        {
            if(marked[v]==0)
            {
                marked[v]=1;
                for(int i=0;i<n;i++)
                {
                    if(graph[v][i]==1)
                        dfs(i);
                }
            }
        }
        
        bool reach(Vertex vin1, Vertex vin2)
        {
            int v1= vin1.v;
            int v2= vin2.v;
            int marked[n];
            for(int i=0;i<n;i++)
                marked[i]=0;
            dfs(v1);
            return (marked[v2] == 1);
        }
        
        bool detectCycle()
        {
            for(int i=0;i<n;i++)
                marked[i]=0;
            for(int i=0;i<n;i++)
            {
                if(marked[i]==0)
                {
                    stack<int> s;
                    int instk[n]={0};
                    s.push(i);
                    while(!s.empty())
                    {
                        int k=s.top();
                        if(marked[k]==0)
                        {
                            marked[k]=1;
                            instk[k]=1;
                        }
                        else
                        {
                            if(instk[k]==1)
                            {
                                instk[k]=0;
                            }
                            s.pop();
                        }
    
                        for(int j=0;j<n;j++)
                        {
                            if(graph[k][j]==1)
                            {
                                if(marked[j] && instk[j])
                                    return true;
                                else 
                                    s.push(j);
                            }   
                        }
                    }
                } 
            }
            return false;
        }
};

/* DO NOT CHANGE THE CODE BELOW */
int main()
{
  int N;
  cin >> N;
  Graph * g;
  int command;
  const int SPARSITYRATIO = 5;
  for (int i = 0; i < N; i++)
  {
    cin>>command;
    switch (command)
    {
      case 1: /* initialize number of vertices and edges */
      {
        int nv,ne;
        cin >> nv >> ne;
        if (ne/nv > SPARSITYRATIO)
          g = new GraphUsingMatrix(nv,ne);
        else
          g = new GraphUsingList(nv,ne);
        break;
      }
      
      case 2: /* Add edge */
      {
        int v,w;
        cin >> v >> w;
        g->addEdge(Edge(Vertex(v), Vertex(w)));
        break;
      }
      
      case 3: /* Reachability query */
      {
        int v,w;
        cin >> v >> w;
        cout << g->reach(Vertex(v), Vertex(w)) << endl;
        break;
      }

      case 4: /* Detect Cycle */
      {
        cout << g->detectCycle() << endl;
        break;
      }
        
      case 5: /* In-degree */
      {
        int v;
        cin >> v;
        cout << g->InDegree(Vertex(v)) << endl;
        break;
      }

      case 6: /* Out-degree */
      {
        int v;
        cin >> v;
        cout << g->OutDegree(Vertex(v)) << endl;
        break;
      }
      
      default:
        break;
    }
  }
}