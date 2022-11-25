#include <bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>

int cost1 = 0 ;


void mst(vector<vector<int>> &G , int V)
{
    int no_edge , cost = 0 , count=0;
    int selected[V];
    memset(selected, false, sizeof(selected));
    cout<<selected[3];
    no_edge = 0;
    selected[0] = true;
    int x; // row number
    int y; // col number

    while (no_edge < V - 1) {
             int min = 9999;
    int x = 0;
    int y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) { // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
              count++;
            }
          }
        }
      }
    }
    if(count == 0)
      cout <<x<< " - " << y;
    else
      cout<< " - " << y;
    cost+=G[x][y];
    selected[y] = true;
    no_edge++;
  }
  cout<<endl<<"Cost is : "<<cost<<endl;
}


void pathMatrix(vector<vector<int>> adj,vector<int> parent[],int n, int start)
{

    vector<int> dist(n, INT_MAX);
    queue<int> q;

    q.push(start);
    parent[start] = { -1 };
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {


                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[v] == dist[u] + 1) {


                parent[v].push_back(u);
            }
        }
    }

    for(int i = 0 ; i < dist.size() ; i++)
    {
        cost1+=dist[i];
    }

}


void findPaths(vector<vector<int> >& paths,vector<int>& path,vector<int> parent[],int n, int u)
{

    if (u == -1) {
        paths.push_back(path);
        return;
    }

    for (int par : parent[u]) {

        path.push_back(u);

        findPaths(paths, path, parent,n, par);

        path.pop_back();
    }

}


void st(vector<vector<int>> adj,int n, int start, int end)
{
    cout<<endl;
    vector<vector<int> > paths;
    vector<int> path;
    vector<int> parent[n];


   pathMatrix(adj, parent, n, start);


    findPaths(paths, path, parent, n, end);
    for (auto v : paths) {


        reverse(v.begin(), v.end());

        for (int u : v)
            cout <<u<<" - ";
        //cout << endl;
    }
    cout<<endl<<"Cost is : "<<cost1<<endl;
}


int main()
{
    //Step 1

    int n=0;
    cout<<"Enter Input Size : ";
    cin>>n;

    //Step 2,3

    vector<vector<int>> adjaMatrix(n, vector<int> (n, 0)) ;

    //creating undirected graph with random values between 0 and 10
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            int random_number = (rand() % 10) + 1;
            adjaMatrix[i][j] = random_number;
            adjaMatrix[j][i] = random_number;
        }
    }

    //doing conditional randomization by setting 40% of elements such that a[i,j]=a[j,i] to zero
    int per = (((n*n)*0.01)*40)/2;
    for(int k = 0 ; k < per ; k++)
    {
        int i = (rand() % (n-1)) + 1;
        int j = (rand() % (n-1)) + 1;

        if(i==j || adjaMatrix[i][j] == 0 )
        {
            k--;
        }

        adjaMatrix[i][j] = 0 ;
        adjaMatrix[j][i] = 0 ;
    }


    cout<<"Adjacancy Matrix after Conditional Randomization: "<<endl;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
             cout<<adjaMatrix[i][j];
             cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    

    //Step 4

    //converting adjacency matrix to list
    vector<vector<int>> AdjList(adjaMatrix.size());
    for (int i = 0; i < adjaMatrix.size(); i++)
    {

        for (int j = 0; j < adjaMatrix[i].size(); j++)
        {
            if (adjaMatrix[i][j] > 0)
            {
                AdjList[i].push_back(j);
            }
        }

    }
    cout<<" Minimum cost Spanning Tree : "<<endl;
    mst(adjaMatrix,n);
    cout<<endl;

    //Step 5

    cout<<" Spanning tree between source and destination: "<<endl;
    int v1 , v2;
    cout<<"Enter source Node :";
    cin>>v1;
    cout<<"Enter destination Node :";
    cin>>v2;
    st(AdjList , n ,v1, v2 );
 
    //Step 6

    cout<<"Insertion and Deletion Operations"<<endl;
    int q;
    int in;
    cout<<"Enter number of operations: ";
    cin>>q;

    do{
            //Step 7

            cout<<"1.Insert"<<endl<<"2.Delete"<<endl<<"3:Exit"<<endl;
            cin>>in;
            switch(in)
            {
               case 1:
                      int s , d , cost;
                      cout<<"Enter v1 :";
                      cin>>s;
                      cout<<endl<<"Enter v2 :";
                      cin>>d;
                      cout<<"Enter their Cost :";
                      cin>>cost;
                      adjaMatrix[s][d] = cost;
                      cout<<"Value Inserted"<<endl;
                      
                break;

                case 2:
                      int s1 , d1;
                      cout<<"Enter v1:";
                      cin>>s1;
                      cout<<endl<<"Enter v2 :";
                      cin>>d1;
                      adjaMatrix[s1][d1] = 0;
                      cout<<"Path Deleted"<<endl;
                     
                break;
                
                case 3:
                    exit(0);
                break;
            }
            q--;

    }while(q>0);

  
    cout<<" Spanning tree between source and destination after operations: "<<endl;
  
    //Step 8

    st(AdjList , n ,v1, v2 );

    return 0;
}














