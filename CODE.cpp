
 
if(pid>0)
{
   int arr2[size];
   for(int i=1;i<argc;i++)
   {
     arr2[i-1]=atoi(argv[i]);
   }
   
   
   write(fd[1],arr2,size*sizeof(arr2));
   close(fd[1]);
   
   
   wait();
   
   
   
   int arr3[size];
   read(fd[0],arr3,size*sizeof(arr3));
   close(fd[0]);
   
   printf("Sorted Array   : ");
   for(int i=0;i<size;i++)
   {
     printf("%d ",arr3[i]);
   }
   printf("\n");
  
  
}
else
{
 
    int arr[size];
    read(fd[0],arr,size*sizeof(arr));
    close(fd[0]);
    
    printf("Unsorted Array : ");
    for(int i=0;i<size;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
    
    
    
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
      {
      
        if(arr[i]<arr[j])
        { 
          int temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
      }
    }
    
    write(fd[1],arr,size*sizeof(arr));
    close(fd[1]);
}
}
