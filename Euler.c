#include<stdio.h>
#include<conio.h>


//initializing adjacency matrix,a nodeStack array to stack the nodes, a eulerPath array to save the euler path and nodeNo array to store the node number
int fp=0,count, n;
int top=-1;
char adjMat[20][20];
char nodeNo[20], nodeStack[20], eularPath[20];

//put into nodeStack
void push(char val)
{
top=top+1;
nodeStack[top]=val;
}

//extract from nodeStack
char pop()
{
return nodeStack[top--];
}

//check if nodes are connected or not
int isConnected(int i)
{
    int j,connect=0;
    for(j=0;j<n;j++)
    {
      if(adjMat[i][j]=='1') connect++;
    }
    return connect;
}


/*get current index of node from nodeNo[] */
int getNode(char c)
{
    int l=0;
    while(c!=nodeNo[l])
    l++;
    return l;
}


/* find the Euler path and store in eularPath[]  */
void eularPathFind(int root)
{
     int l,j;
     //push root in nodeStack
    push(nodeNo[root]);

    //till stack is empty i.e top=-1
    while(top!=-1)
    {
      // get index of top of the nodeStack
      l=getNode(nodeStack[top]);
      
	  /*  If all adjacent nodes are visited pop up element 
	  from nodeStack and keep in eularPath[]*/
      if(visited(l))
      {
        eularPath[fp++]=pop();
        
      }
      else
      {
	        /* If any unvisited node is available it in nodeStack
			make it visited by '0' in adjMat[][] */

        for(j=0;j<n;j++)
        {
        if(adjMat[l][j]=='1')
        {

			
		
             adjMat[l][j]='0';
             adjMat[j][l]='0';
             push(nodeNo[j]);
            
             break;
           
        }
        }
       }
     }
}

/*check all adjacent nodes are visited or not */
int visited(int i)
{
    int j;
    for(j=0;j<n;j++)
    {
       if(adjMat[i][j]=='1')
       return 0;
    }
    return 1;
}




/* Display the Euler path  */
void printPath()
{
     int i;
     for(i=0;i<fp;i++)
     {
       printf("%c ->",eularPath[i]);
     }
}



//  assign the root of the graph
int findRoot()
{


 //this returns 0 if euler path not possible  or returns an array index as root
     int i,cur=1;    //Assume root as 1
     

     for(i=0;i<n;i++)
     {
        if(isConnected(i)%2!=0)
        {
           count++;
           cur=i;     //store the node which has odd edges connect to other nodes
        }
     }
	 
     /* If count is not exactly 2 then circuit not possible so return 0*/
     if(count!=0 && count!=2)
     {
        return 0;
     }
     else return cur;   /* if exactly 2 nodes have odd edges connected, 
	                    return one of those node as root otherwise return 1 as root   */
}






int main()
{
	int root;
    char v;
    int i,j,l;
    printf("Enter the number of nodes \n");
    scanf("%d",&n);

    for( i=0; i<n; i++)
    {
	   char dig = (char)(((int)'0')+i);   // type cast int to char
		nodeNo[i] = dig;                // assign i value to nodeNo[i]
   } 
    
    
   printf("\nEnter the  adjancency matrix of Graph\n\n");
    for( i=0;i<n; i++)
    {
     for( j=0; j<n; j++)
     {
      printf("%c\t",v=getch());
	  
      adjMat[i][j]=v;
     }
      printf("\n");
    }
    

// find root node value or return 0 if circuit is not possible
    if(root=findRoot())
    {
    	printf("\nEuler Path is :\n");
		eularPathFind(root);
		printPath();
    }
    else printf("\nEuler path is not available\n");
    getch();
}

