#include<conio.h>
#include<stdio.h>
#include<bits/stdc++.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;

			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){

				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};
*/

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{   Node* SortedMerge(Node *a, Node*b);
    void FrontBackSplit(Node* source,  Node** frontRef,
					 Node** backRef);
    void MergeSort(Node* head);
    struct Node* temp=root;
    struct Node* temp2=root;
    while(temp2->next!=NULL){
        while(temp->bottom!=NULL){
        temp=temp->bottom;
        }
        temp->bottom=temp2->next;
        temp2=temp2->next;
    }
    MergeSort(root);
    return root;
   //printArray(root);// Your code here
}

Node* SortedMerge(Node *a, Node*b)
{
	// Base cases
	if (a == NULL)
		return b;

	else if (b == NULL)
		return a;

	struct Node* result = NULL;

	// Pick either a or b, and recur
	if (a->data <= b->data)
	{
		result = a;
		result->bottom = SortedMerge(a->bottom, b);
	}
	else
	{
		result = b;
		result->bottom = SortedMerge(a, b->bottom);
	}

	return result;
}
void FrontBackSplit(Node* source,  Node** frontRef,
					 Node** backRef)
{
	// if length is less than 2, handle separately
	if (source == NULL || source->bottom == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
		return;
	}

	struct Node* slow = source;
	struct Node* fast = source->bottom;

	// Advance 'fast' two nodes, and advance 'slow' one node
	while (fast != NULL)
	{
		fast = fast->bottom;
		if (fast != NULL)
		{
			slow = slow->bottom;
			fast = fast->bottom;
		}
	}

	// 'slow' is before the midpoint in the list, so split it in two
	// at that point.
	*frontRef = source;
	*backRef = slow->bottom;
	slow->bottom = NULL;
}

// Sort given linked list using Merge sort algorithm
void MergeSort(Node* head)
{
	// Base case -- length 0 or 1
	if (head == NULL || (head)->bottom == NULL)
		return;

	struct Node* a;
	struct Node* b;

	// Split head into 'a' and 'b' sublists
	FrontBackSplit(head, &a, &b);

	// Recursively sort the sublists
	MergeSort(a);
	MergeSort(b);

	// answer = merge the two sorted lists together
	head = SortedMerge(a, b);
}
