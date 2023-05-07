#include<stdio.h>
#include<string.h>
int pro_no,i,j,k;


//structure
struct processes
{
    char name[20];
    int arriving_time;
    int waiting_time;
    int burst_time;  
    int turn_around_time;
}process[20],temp;

//gantt chart sturcture
struct  gantt
{
    char name[20];
     int completion_time;
}g[20];


//sorting algorithm 
void sort()
{
    for(i=0; i<pro_no; i++)
    {
        for(j=0; j<pro_no-1-i; j++)
        {
            if(process[j].arriving_time > process[j+1].arriving_time )
            {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1]= temp;
            }
        }
    }
   
   
}

//table of data
int ganttchart()
{
   
    int complete= 0, idle=0;
    for(i=0;i<pro_no;i++)
    {
        if(complete < process[i].arriving_time)
        {
            idle = process[i].arriving_time - complete ; 
            strcpy(g[k].name, "idle");
            g[k].completion_time = complete+idle;
             k++;
            complete = complete + idle +process[i].burst_time;
            process[i].waiting_time = 0;
            strcpy(g[k].name,process[i].name);
            g[k].completion_time=complete;
            process[i].turn_around_time = process[i].burst_time+process[i].waiting_time;
            k++;
            

        }
        else
        {
            
            process[i].waiting_time = complete - process[i].arriving_time;
            complete = complete + process[i].burst_time;
            strcpy(g[k].name, process[i].name);
            g[k].completion_time = complete;
            process[i].turn_around_time = process[i].waiting_time+process[i].burst_time;
            k++;
        }
    } 

    //printing the table of data
   
        printf("process name\t arriving time \t burst time \t waiting time \t turn around time \t\n\n");
       
     for( i = 0; i <pro_no ; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n\n", process[i].name, process[i].arriving_time,process[i].burst_time,process[i].waiting_time,process[i].turn_around_time);
    }
    
    //printing the gannt chart
    printf("\n\n");
    printf("Gantt chart \n");
    printf("|");
    for(i=0;i<k;i++)
    {
    	
    	printf("\t%s\t|",g[i].name);
    	
    }
    printf("\n");
    printf("0");
    for(i=0;i<k;i++)
    {
    	
    	printf("\t\t%d",g[i].completion_time);
    	
    }
      

    
}




//main function
int main()
{
   
    printf("enter the no of process:");
    scanf("%d",&pro_no );
     
    for( i=0; i<pro_no; i++)
    {
        printf("\nEnter the name of the process: ");
        scanf("%s", process[i].name);

        printf("\nEnter the arriving time");
        scanf("%d", &process[i].arriving_time);

        printf("\nEnter the burst time ");
        scanf("%d", &process[i].burst_time);
    }

    sort();
    ganttchart();
    printf("\n");
  


}