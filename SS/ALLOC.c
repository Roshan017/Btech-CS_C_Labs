#include<stdio.h>
#include <stdlib.h>
void main()
{
        int choice,n,a,count,temporary;
	printf("----MENU----\n");
	printf("----____----\n");
	printf("1. Contigous allocation\n");
	printf("2. Linked allocation\n");
	printf("3. Indexed allocation\n");
	printf("CHOOSE AN OPTION:-\t");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			{
				int f;
				printf("\nEnter number of blocks:\t");
				scanf("%d",&n);
				int b[n];
				printf("\nEnter number of files:\t");
				scanf("%d",&f);
				for(int i=0;i<n;i++)
				{
					b[i]=-1;
				}
				for(int i=0;i<f;i++)
				{
					char name[10];
					int start_block;
					int len;
					printf("\nEnter file name:\t");
					scanf("%s",name);
					printf("\nEnter start block:\t");
					scanf("%d",&start_block);
					printf("\nEnter length to be allocated:\t");
					scanf("%d",&len);
					
					if(len+start_block>n || len>n || start_block>n)
					{
						printf("\nFile cannot be allocated");
						break;
					}
					else
					{
						int flag=0;
						for(int j=start_block;j<start_block+len;j++)
						{
							if(b[j]!=-1)
							{
								flag=1;
								printf("\nThis file cannot be allocated");
								break;
							}
							if(!flag)
							{
								printf("\nfile has been successfully stored frm block %d to %d\t",start_block,start_block+len); 
							for(int k=start_block;k<start_block+len;k++)
							b[k]=0;	
							break;
							}
						}
					}
				}
				
																							
			}break;
		case 2:
			{
				int n,f;
				printf("\nEnter number of blocks:\t");
				scanf("%d",&n);
				int b[n];
				printf("\nEnter number of files:\t");
				scanf("%d",&f);
				for(int i=0;i<n;i++)
				{
					b[i]=-1;
				}
				for(int i=0;i<f;i++)
				{
					char name[10];
					int start_block;
					int len;
					printf("\nEnter file name:\t");
					scanf("%s",name);
					printf("\nEnter start block:\t");
					scanf("%d",&start_block);
					printf("\nEnter length to be allocated:\t");
					scanf("%d",&len);
					if(len+start_block>n || len>n || start_block>n)
					{
						printf("\nFile cannot be allocated");
						break;
					}
					else
					{
						int size=0;
						for(int j=start_block;j<start_block+len;j++)
						{
							if(b[j]==-1)
							{
								size++;
								b[j]=0;
							}	
							else if(b[j]!=-1)
							{
								for(int k=j;k<n;k++)
								{
									if(b[k]==-1 && size<len)
									{
										size++;
										b[k]=0;
									}
										
								}
							}
						}
						if(size==len)
						{
							printf("\nfile has been successfully stored "); 	
						}
						else
						{
							printf("\nfile not saved");
						}	
					}
				}
								
			}
			break;
		case 3:
			{
				int n,f;
				printf("\nEnter number of blocks:\t");
				scanf("%d",&n);
				int b[n];
				int index[n];
				int ind=0;
				printf("\nEnter number of files:\t");
				scanf("%d",&f);
				for(int i=0;i<n;i++)
				{
					b[i]=-1;
					index[i]=0;
				}
				for(int i=0;i<f;i++)
				{
					char name[10];
					int start_block;
					int len;
					printf("\nEnter file name:\t");
					scanf("%s",name);
					printf("\nEnter start block:\t");
					scanf("%d",&start_block);
					printf("\nEnter length to be allocated:\t");
					scanf("%d",&len);
					if(len+start_block>n || len>n || start_block>n)
					{
						printf("\nFile cannot be allocated");
						break;
					}
					
					else
					{
						int size=0;
						for(int j=start_block;j<start_block+len;j++)
						{
							//index[ind]=j;
							if(b[j]==-1)
							{		
								size++;
								b[j]=0;
								if(j==start_block)
								{
									index[ind]=start_block;
									ind++;
								}
							}	
							else if(b[j]!=-1)
							{
								for(int k=j;k<n;k++)
								{
									if(b[k]==-1 && size<len)
									{
											
										size++;
										b[k]=0;
										if(j==start_block)
										{
											index[ind]=start_block;
											ind++;
										}*/
									}
										
								}
							}
						}
						if(size==len)
						{
							printf("\nfile has been successfully stored "); 	
						}
						else
						{
							printf("\nfile not saved");
						}	
					}
				}
				
				for(int j=0;j<n;j++)
				{
					printf("%d\t",index[j]);
				}					
			}break;
		default:
			{
				printf("---INVALID CHOICE---");
				exit(0);
			}
	}
}
							
