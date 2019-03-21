/*
Searching methods:
Linear search
Binary search

Sorting methods:
Bubble sort
Selection sort
Insertion sort

*/

#include<stdio.h>
struct Student
{
	char name[20];
	int rollno,divi;
	float marks;
};
typedef struct Student stud;
void accept(struct Student st[20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of Student %d\n",i+1);
		printf("\nName:\n");
		scanf("%s",st[i].name);
		printf("\nRoll No:\n");
		scanf("%d",&st[i].rollno);
		printf("\nDivision:\n");
		scanf("%d",&st[i].divi);
		printf("\nMarks:\n");
		scanf("%f",&st[i].marks);
	}
}
void display(struct Student s)
{
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("\nName : %s\n",s.name);
	printf("Roll No : %d\n",s.rollno);
	printf("Div : %d\n",s.divi);
	printf("Marks : %f\n",s.marks);
}
void linsearch(struct Student s[20],int n)
{
	int key,i;
	printf("\nEnter the roll no you want to search:\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(key==s[i].rollno)
		{
			printf("\nRecord found\n\nDetails:\n");
			display(s[i]);
			printf("\n-------------------------------------------------------------------------------------------------\n");
			break;
		}
	}
	if(i>=n)
	printf("Record not found!\n");
}
void bubblesort(struct Student s[20],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(s[j].rollno>s[j+1].rollno)
			{
				stud temp;
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
		printf("Iteration of pass %d is:\n",i+1);
		for(k=0;k<n;k++)
		{
			display(s[k]);
		}
	}
}
void binsearch(struct Student s[20],int n)
{
	int low,high,mid,key;
	printf("\nEnter the Roll no to search:\n");
	scanf("%d",&key);
	high=n-1;
	low=0;
	mid=(low+high)/2;
	while(low<=high)
	{
		if(key==s[mid].rollno)
		{
			printf("\nRecord found\n\nDetails:\n");
			display(s[mid]);
			printf("\n-------------------------------------------------------------------------------------------------\n");

			break;
		}
		else if(key<s[mid].rollno)
		{
			high=mid-1;
			mid=(high+low)/2;
		}
		else if(key>s[mid].rollno)
		{	
			low=mid+1;
			mid=(high+low)/2;
		}
	}
	if(low>high)
	printf("\nRecord not found\n");
	
}
void selectionsort(struct Student s[20],int n)
{
	int min,i,j,pos;
	for(i=0;i<n;i++)
	{
		pos=i;
		min=s[i].rollno;
		for(j=i+1;j<n;j++)
		{
			if(s[min].rollno>s[j].rollno)
			{
				min=s[j].rollno;
				pos=j;
				
			}
		}
		struct Student temp;
		temp=s[pos];
		s[pos]=s[i];
		s[i]=temp;
	}
	
}
void insertionsort(struct Student s[20],int n)
{
	int i,j;
	stud temp;
	for(i=1;i<n;i++)
	{
		temp=s[i];
		j=i-1;
		while(s[j].rollno>temp.rollno && j>=0)
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=temp;
	}
}
int main()
{
	int n,ch,i;
	stud s[20];
	printf("\nEnter the no. of Students:\n");
	scanf("%d",&n);
	accept(s,n);
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("\nStudent Details\n");
	for(i=0;i<n;i++)
	{
		display(s[i]);
	}
	printf("\n-------------------------------------------------------------------------------------------------\n");
	while(ch!=6)
	{
		printf("\n1:Linear Search\n2:Binary Search \n3:Bubble Sort\n4:Selection Sort\n5:Insertion Sort\n6:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:linsearch(s,n);
			break;
			case 2:bubblesort(s,n);
				binsearch(s,n);
			break;
			case 3:bubblesort(s,n);
				printf("\nSorted Details are:\n");
				for(i=0;i<n;i++)
				{
					display(s[i]);
				}
			break;
			case 4:selectionsort(s,n);
				for(i=0;i<n;i++)
				{
					display(s[i]);
				}
			break;
			case 5:insertionsort(s,n);
				for(i=0;i<n;i++)
				{
					display(s[i]);
				}
			break;
		}
	}
	return 0;
}
