#include<stdio.h>
void main()
{
	struct index
	{
		int page;
		int frame;
	};
	int offset,page_size,p_no,addrs_frame,i,no_pages,physical_addrs;
	printf("Enter the page size :");
	scanf("%d",&page_size);
	printf("Enter number of paages:");
	scanf("%d",&no_pages);
	
	struct index table[no_pages];
	
	for(int i=0;i<no_pages;i++)
	{
		table[i].page=i;
		printf("\n Enter the frame number of page %d :",i);
		scanf("%d",&table[i].frame); 
	}
	printf("Page No.\tFrame No.");
	for(int i=0;i<no_pages;i++)
	{
		printf("\n%d\t%d",table[i].page,table[i].frame);
	}
	printf("\nEnter PageNo. and offset");
	scanf("%d\t%d",&p_no,&offset);
	if(offset>page_size-1)
	{
		printf("\nOffset greater than page size");
		//continue;
	}
	else if(p_no>no_pages-1)
	{
		printf("Page not Found");
		//continue;
	}
	else
	{
		addrs_frame=table[p_no].frame;
		physical_addrs=addrs_frame*page_size+offset;
		printf("\nPhysical address : %d",physical_addrs);
	}
}						
