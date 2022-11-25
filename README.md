# Design-and-Analysis-of-Algorithm_TA2

<h2> TA: Programming Assignment </h2>

Name : Anushka Shukla <br>
Sec  : 5-A <br>
Roll : 03 <br>

<hr>

<h3> Topic : <u>Greedy Algorithms</u> </h3>

<b>Step 1:</b> Input “n” from user<br>
<b>Step 2:</b> Create a “nxn” matrix and populate the matrix using i>=0 values such that (0<=i<=10).  Ensure minimum 40% of elements such that a[i,j]=a[j,i] must be “zero”. This is called as “Conditional Randomization”.<br>
<b>Step 3:</b> Restructure the matrix and replace all the diagonal elements to “zero”<br>
<b>Step 4:</b> Create a minimum cost spanning tree using the matrix<br>
<b>Step 5:</b> Accept V1 and V2 as two vertices and print the spanning tree between two vertices.<br>
<b>Step 6:</b> The user is allowed to enter input “q”, for example q=3, then perform step 7 for “q” number of times. For example “q=3”, then step 7 will be performed for three times.<br>
<b>Step 7:</b> The user is allowed to add and delete the edges in the existing graph, using indicator: “0” or “1”.<br>
If user enters “0”, [2,5]: then the edge between vertex 2 and vertex 5, is deleted.<br>
If user enters “1” [3,5,7]: then an edge is added between vertex 3 and vertex 5 with cost <br>
<b>Step 8:</b> Repeat step 5 for the same vertices V1 and V2. <br>
<b>Step 9:</b> Comment on the cost of minimum cost spanning tree [cost increased/cost decreased]<br>




<h3>Code functionality :</h3>
First we will generate a random undirected-graph matrix of nxn size as per given constraints<br>
Then using MST logic, find Minimum cost spanning tree of graph<br>
Logic for MST :<br>
Initialize list of unvisited vertices with UV = {V1, V2, V3, . . . , Vn}<br>

        1. Select any arbitrary vertex from input graph G, call that subgraph as partial MST. Remove selected vertex from UV

        2. Form a set NE – a set of unvisited neighbour edges of all vertices present in partial MST

        3. Select an edge e = (u, v) from NE with minimum weight, and add it to partial MST if it does not form a cycle and it is not already added

        If the addition of edge e forms a cycle, then skip that edge and select next minimum weight edge from NE. Continue this procedure until we get an edge e which does not form a cycle. Remove corresponding added vertices u and v from UV

        4. Go to step 2 and repeat the procedure until UV is empty
<br>

For Finding MST between 2 user given points V1 and V2, select an edge which contains v1 as a node and has minimum of all such possible edges, similarly chose one for V2. This will assure that atleast there is one path which contains v1 & one which contains V2.<br>
Now, make a copy of graph matrix and in that copy matrix, delete all remaining edges from v1 & v2 so that v1 & v2 are the starting and ending points of MST.<br>
Run MST function for remaining graph available, if all nodes are covered in mst, then print it otherwise chose another edge from v1 & v2 until either we found valid MST or all the edges are chosen.<br>
If all the edges are chosen and even after that we are unable to find valid MST, then print "NOT POSSIBLE", as it is not possible to make MST with starting and ending point as v1 & v2.<br>
After inserting and deleting some edges in graph as per test cases, aplly above logic again.<br>

<hr>

<h3> TEST CASES </h3>

<h4> TEST CASE 1 : </h4> 
Enter Input Size : 6<br>
Adjacancy Matrix after Conditional Randomization: <br>
0 5 0 0 0 0 <br>
5 0 7 0 0 0 <br>
0 7 0 2 0 0 <br>
0 0 2 0 4 0 <br>
0 0 0 4 0 8 <br>
0 0 0 4 8 0 <br>
<br>
 Minimum cost Spanning Tree : <br>
0 - 1 - 2 - 3 - 4 - 5<br>
Cost is : 26<br>
<br>
 Spanning tree between source and destination: <br>
Enter source Node :1<br>
Enter destination Node :5<br>
<br>
1 - 2 - 3 - 4 - 5 <br>
Cost is : 21<br>
<br>
Insertion and Deletion Operations<br>
Enter number of operations: 2<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
1<br>
Enter v1 :2<br>
Enter v2 :4<br>
Enter their Cost :2<br>
Value Inserted<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
1<br>
Enter v1 :1<br>
Enter v2 :3<br>
Enter their Cost :1<br>
Value Inserted<br>
<br>
 Spanning tree between source and destination after operations: <br>
1 - 3 - 2 - 4 - 5  <br>
Cost is : 13<br>


<h4> TEST CASE 2 : </h4> 
Enter Input Size : 4<br>
Adjacancy Matrix after Conditional Randomization: <br>
0 3 0 5  <br>
3 0 2 4  <br>
0 2 0 1  <br>
5 4 1 0 <br>
<br>
 Minimum cost Spanning Tree : <br>
0 - 1 - 2 - 3<br>
Cost is : 6<br>
<br>
 Spanning tree between source and destination: <br>
Enter source Node :0<br>
Enter destination Node :2<br>
<br>
0 - 1 - 2 <br>
Cost is : 5<br>
<br>
Insertion and Deletion Operations<br>
Enter number of operations: 1<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
2<br>
Enter v1 :0<br>
Enter v2 :1<br>
Path Deleted
<br>
Spanning tree between source and destination after operations: <br>
0 - 3 - 1 - 2  <br>
Cost is : 11<br>


<h4> TEST CASE 2 : </h4> 
Enter Input Size : 6<br>
Adjacancy Matrix after Conditional Randomization: <br>
0 4 7 6 7 3 <br>
4 0 0 0 3 0 <br>
7 0 0 0 10 1 <br>
6 0 0 0 0 0 <br>
7 3 10 0 0 0 <br>
3 0 1 0 0 0 <br>
<br>
 Minimum cost Spanning Tree : <br>
0 - 5 - 2 - 1 - 4 - 3<br>
Cost is : 17<br>
<br>
 Spanning tree between source and destination: <br>
Enter source Node :2<br>
Enter destination Node :5<br>
2 - 5 - <br>
Cost is : 7<br>
<br>
Insertion and Deletion Operations<br>
Enter number of operations: 4<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
1<br>
Enter v1 :1<br>
Enter v2 :3<br>
Enter their Cost :2<br>
Value Inserted<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
1<br>
Enter v1 :2<br>
Enter v2 :4<br>
Enter their Cost :3<br>
Value Inserted<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
2<br>
Enter v1:1<br>
Enter v2 :5<br>
Path Deleted<br>
1.Insert<br>
2.Delete<br>
3:Exit<br>
2<br>
Enter v1:2<br>
Enter v2 :5<br>
Path Deleted<br>
<br>
Spanning tree between source and destination after operations: <br>
2 - 5 - <br>
Cost is : 14<br>

<hr>

<h3> OBSERVATION </h3>

<b>Insertion :</b><br>
While inserting any new edge, MST cost either remains same or decrease but it never increases.<br>
Reason being MST itself has lowest possible cost and adding extra edge wotn ever increase cost.<br>

<b>Deletion:</b><br>
While deleting any edge, MST cost either remains same or increases but it never decreases.<br>
Reason being if we are deleting edge which contributes in making of lowest MST, this will always increase its cost, otherwise there will be no change in cost if deleted edge is not a part of MST.<br>

