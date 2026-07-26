#include "../head/sudoku_lib.h"

int main()
{
    title();
    int inp;
    char filename[2];
    int sdk[9][9];
    while(1)
    {
        printf("Enter the Sudoku to solve: (1-34)\n");
        if (scanf("%d", &inp) != 1) {
            while (getchar() != '\n');
            printf("[ERROR]: (it is not a number)\n\n");
            continue;
        }
        if(inp>=0&&inp<35)
        {
            sprintf(filename, "%d", inp);
        parser(sdk,filename);
        stp_sdk(sdk);
        printf("\n\n═════════════════════════\n\n");     
        printf("Do you want to solve this Sudoku? (y/n)\n");

        while (getchar() != '\n');

        int c = getchar();

        if (c == '\n' || c == 'y') 
            break;
        }
        else
            printf("[ERROR]: (Enter an integer from 1 to 32.)\n\n");
    }


    int ha=0,cp_index=1;

    sit mat[9][9][9];
    init_sdk(mat);


    for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
    {
        ha=0;
        if(sdk[i][j]!=0)
        {
            mat[i][j][0].val=sdk[i][j];
            mat[i][j][0].pr=1.0;
        }
        else
        {
            for(int k=1;k<10;k++)
            {
                int n=0;
                for(int f=0;f<9;f++)
                {
                    if(f!=j)
                    {
                        if(sdk[i][f]==k){n=1;break;}
                    }
                    if(f!=i)
                    {
                        if(sdk[f][j]==k){n=1;break;}
                    }
                    for(int i1=i-i%3;i1<i-i%3+3;i1++){
                    for(int j1=j-j%3;j1<j-j%3+3;j1++)
                    {
                        if(i1!=i&&j1!=j)
                        {
                            if(sdk[i1][j1]==k){n=1;break;}
                        }
                    }}
                }
                if(n==0)
                {
                    mat[i][j][ha].val=k;
                    ha++;
                }
            }
        }
        for(int c=0;c<ha;c++)
        {
            mat[i][j][c].pr=1.0/(double)ha;
        }
    }}

    sit mat_copy[81][9][9][9];
    int sdk_copy[81][9][9];
    copy_sit(mat_copy[0],mat);
    copy(sdk_copy[0],sdk);
    int max[81][2]={{0}};

    while(check(sdk))
    {
        int ind=0;
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
        for(int k=0;k<9;k++)
        {
        if(mat[i][j][k].pr==1.0&&sdk[i][j]==0)
        {
            ind=1;
            sdk[i][j]=mat[i][j][k].val;
            for(int f=0;f<9;f++)
            {
                for(int p=0;p<9;p++)
                {
                if(f!=j)
                {
                    if(mat[i][f][p].val==sdk[i][j])
                    {
                        mat[i][f][p].pr=0.0;
                        mat[i][f][p].val=0;
                        for(int h=0;h<9;h++)
                        {
                            if(h!=p)
                                mat[i][f][h].pr=1.0/((1.0/(double)mat[i][f][h].pr)-1.0);
                        }
                    }
                }
                }
                for(int p=0;p<9;p++)
                {
                if(f!=i)
                {
                    if(mat[f][j][p].val==sdk[i][j])
                    {
                        mat[f][j][p].pr=0.0;
                        mat[f][j][p].val=0;
                        for(int h=0;h<9;h++)
                        {
                            if(h!=p)
                                mat[f][j][h].pr=1.0/((1.0/(double)mat[f][j][h].pr)-1.0);
                        }
                    }
                }
                }
            }
            for(int i1=i-i%3;i1<i-i%3+3;i1++){
            for(int j1=j-j%3;j1<j-j%3+3;j1++){
            for(int p=0;p<9;p++){
            if(i1!=i&&j1!=j)
            {
                if(mat[i1][j1][p].val==sdk[i][j])
                {
                    mat[i1][j1][p].pr=0.0;
                    mat[i1][j1][p].val=0;
                    for(int h=0;h<9;h++)
                    {
                        if(h!=p)
                            mat[i1][j1][h].pr=1.0/((1.0/(double)mat[i1][j1][h].pr)-1.0);
                    }
                }
            }
            }}}
        }}}}

        if(ind==0)
        {
            
            double maxval=0.0;
            
            for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
            for(int k=0;k<9;k++)
            {
                if(mat[i][j][k].pr>maxval&&mat[i][j][k].pr!=1.0)
                {
                    maxval=mat[i][j][k].pr;
                    max[cp_index][0]=i;
                    max[cp_index][1]=j;
                    mat[i][j][0].tent=1.0/mat[i][j][k].pr;
                }
            }}}
            for(int m=0;m<9;m++)
            {
                if(mat[max[cp_index][0]][max[cp_index][1]][m].pr!=0)
                {
                    mat[max[cp_index][0]][max[cp_index][1]][0].tent=1.0/(mat[max[cp_index][0]][max[cp_index][1]][m].pr);
                    break;
                }
            }
            copy_sit(mat_copy[cp_index],mat);
            copy(sdk_copy[cp_index],sdk);
            int n=0,c=mat[max[cp_index][0]][max[cp_index][1]][0].trial;
            for(int p=0;p<9;p++)
            {
                if(mat[max[cp_index][0]][max[cp_index][1]][p].val!=0&&c==0)
                {
                    mat[max[cp_index][0]][max[cp_index][1]][p].pr=1.0;
                    n=p;
                    break;
                }
                if(mat[max[cp_index][0]][max[cp_index][1]][p].val!=0)
                    c--;
            }
            for(int p=0;p<9;p++)
            {
                if(p!=n)
                {
                    mat[max[cp_index][0]][max[cp_index][1]][p].val=0;
                    mat[max[cp_index][0]][max[cp_index][1]][p].pr=0.0;
                }
            }
            cp_index++;
        }

        
        if(check_error(mat)==1)
        {
            for(int i=cp_index-1;i>0;i--)
            {
                if((double)mat_copy[i][max[i][0]][max[i][1]][0].trial!=mat_copy[i][max[i][0]][max[i][1]][0].tent-1.0)
                {
                    mat_copy[i][max[i][0]][max[i][1]][0].trial++;
                    copy_sit(mat,mat_copy[i]);
                    copy(sdk,sdk_copy[i]);
                    cp_index=i;
                    break;
                }
            }
        }
    }
    printf("═════════════════════════\n\n");
    stp_sdk(sdk);

    return 0;  
}
