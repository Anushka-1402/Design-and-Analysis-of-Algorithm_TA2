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
      - Take input for all 3 stacks in a queue, calculate and store sum of all 3 queue.<br>
      - Check if sum of all 3 queue is equal, return the sum.<br>
      - If any of the queue becomes empty, then Possible maximum sum is 0. Return 0.<br>
      - Otherwise, pop the front element of queue having maximum sum, and update sum for it.<br>
      - Repeat above steps, until sum of all 3 queue gets equal or any of the queue becomes empty. Exit.<br>

<hr>

<h3> TEST CASES </h3>

<h5> INPUT 1 : </h5> 
Stack 1 : 8 5 3 <br>
Stack 2 : 6 9 4 2 2 <br>
Stack 3 : 3 2 1 2 <br>

<h5> OUTPUT 1 : </h5>
Possible Equal Maximum Sum : 8<br>


<h5> INPUT 2 : </h5>
Stack 1 : 9 7 5 3 1 4 <br>
Stack 2 : 4 3 2 8 1 <br>
Stack 3 : 5 3 2 1 <br>

<h5> OUTPUT 2 : </h5>
Possible Equal Maximum Sum : 0<br>


<h5> INPUT 3 : </h5>
Stack 1 : 9 1 4 2 <br>
Stack 2 : 3 6 1 <br>
Stack 3 : 1 2 5 <br>

<h5> OUTPUT 3 : </h5>
Possible Equal Maximum Sum : 7<br>

