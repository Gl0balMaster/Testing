#include<iostream>

/*int** MakeSpiral(int n){
for(int i = 0; i < n ; ++i ){
        for(int m = 0; m < n; ++m )
        {
            std::cout<<i*n+m;
        }
    }
}*/

int main(int argc, char const *argv[])
{
    int size,temp;
    std::cin>>size;
    int spiral[size][size];
    int rotate=0;
    int step = 0;
    temp=0;

    for (int i = 0; i < size; ++i)
    {
        for (int m = 0; m < size; ++m)
        {
            spiral[i][m]=0;
        }
        
    }
    
    for(int i = 0; i < size*size ; ++i ){
        for(int m = 0; m < size; ++m )
        {
            
                switch (rotate%4)
                {
                case 0:
                {
                    
                
                    temp = ((spiral[step][m+step] == 0) ? temp+=1 : temp);
                    spiral[step][m+step] = (spiral[step][m+step] == 0 ? temp : spiral[step][m+step]);
                }   
                    break;

                case 1:
                {
                    temp = (spiral[m+step][size-step-1] == 0 ? temp+=1 : temp); 
                    spiral[m+step][size-step-1]=(spiral[m+step][size-step-1] == 0 ? temp : spiral[m+step][size-step-1]);
                }   
                    break;

                case 2:
                {
                    temp = (spiral[size-step-1][size-m-step-1] == 0 ? temp+=1 : temp);
                    spiral[size-step-1][size-m-step-1]=(spiral[size-step-1][size-m-step-1] == 0 ? temp : spiral[size-step-1][size-m-step-1]);
                }   
                    break;

                case 3:
                {
                    temp = (spiral[size-m-1+step][step] == 0 ? temp+=1 : temp);
                    spiral[size-m-1+step][step]=(spiral[size-m-1+step][step] == 0 ? temp : spiral[size-m-1+step][step]);
                }   
                    break;
                
                default:
                    break;

                    
                }
            
           
        }
   
        
        rotate++;
        if (rotate == 4)
        {
            step++;
            rotate = 0;
        }
        
        
       // temp;
       // std::cout<<"govno "<<temp<<" ";
        if (temp  >= size*size*size)
        {
            break;
        }
    }

    std::cout<<std::endl;


    for (int i = 0; i < size; ++i)
    {
        for (int m = 0; m < size; ++m)
        {
            (spiral[i][m] > 9 ? (std::cout<<spiral[i][m]<<"   ") : (std::cout<<spiral[i][m]<<"    "));
        }
        std::cout<<std::endl;
    }
 
    
    return 0;
}
