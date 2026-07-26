#include "../head/sudoku_lib.h"


void title() 
{
    printf("╔═══════════════════════════════════════════════════════╗\n");
    printf("║  ███████╗██╗   ██╗██████╗  ██████╗ ██╗  ██╗██╗   ██╗  ║\n");
    printf("║  ██╔════╝██║   ██║██╔══██╗██╔═══██╗██║ ██╔╝██║   ██║  ║\n");
    printf("║  ███████╗██║   ██║██║  ██║██║   ██║█████╔╝ ██║   ██║  ║\n");
    printf("║  ╚════██║██║   ██║██║  ██║██║   ██║██╔═██╗ ██║   ██║  ║\n");
    printf("║  ███████║╚██████╔╝██████╔╝╚██████╔╝██║  ██╗╚██████╔╝  ║\n");
    printf("║  ╚══════╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝   ║\n");
    printf("║                                                       ║\n");
    printf("║   ███████╗ ██████╗ ██╗     ██╗   ██╗███████╗██████╗   ║\n");
    printf("║   ██╔════╝██╔═══██╗██║     ██║   ██║██╔════╝██╔══██╗  ║\n");
    printf("║   ███████╗██║   ██║██║     ██║   ██║█████╗  ██████╔╝  ║\n");
    printf("║   ╚════██║██║   ██║██║     ██║   ██║██╔══╝  ██╔══██╗  ║\n");
    printf("║   ███████║╚██████╔╝███████╗╚██████╔╝███████╗██║  ██║  ║\n");
    printf("║   ╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝  ║\n");
    printf("╚═══════════════════════════════════════════════════════╝\n\n\n");
}

void parser(int sdk[9][9], char filename[])
{
    char path[100];
    char line[100];
    snprintf(path, sizeof(path), "collection/puzzle%s.sdk", filename);
    FILE *f = fopen(path, "r"); 
    
    int i=0;
    while (fgets(line, sizeof(line), f) != NULL) 
    {
        if (isdigit((unsigned char)line[0])&&isdigit((unsigned char)line[8]))
        i++;
    }
    if(i!=9)
    {
        fprintf(stderr, "[ERROR]: incompatible file\n");
        exit(-1);
    }
    i=0;
    
    rewind(f);
    while(i<9)
    {
        fgets(line,sizeof(line),f);
        if(line[0]!='#')
        {
            for(int j=0;j<9;j++)
            {
                sdk[i][j]=line[j]-'0';
            }
            i++;
        }
    }
    fclose(f);
}

void init_sdk(sit m[9][9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                m[i][j][k].val=0;
                m[i][j][k].pr=0.0;
            }
            m[i][j][0].trial=0;
        }
    }
}

int check(int sdk[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int k=0;k<9;k++)
        {
            if(sdk[i][k]==0)
            return 1;
        }
    }
    return 0;
}

void copy(int a[9][9], int b[9][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
        {
            a[i][j]=b[i][j];
        }}
    }
    
    void copy_sit(sit a[9][9][9], sit b[9][9][9])
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                a[i][j][0].trial=b[i][j][0].trial;
                a[i][j][0].tent=b[i][j][0].tent;
                for(int k=0;k<9;k++)
                {
                    a[i][j][k].val=b[i][j][k].val;
                    a[i][j][k].pr=b[i][j][k].pr;
                }}}
            }
            
            int check_error(sit m[9][9][9])
            {
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9;j++)
                    {
                        int n=1;
                        for(int k=0;k<9;k++)
                        {
                            if(m[i][j][k].val!=0)
                            {
                                n=0;
                                break;
                            }
                        }
                        if(n==1)
                        return 1;
                    }
                }
                return 0;
            }
            
            
            
            void stp_sdk(int m[9][9]) 
            {
                
                for (int i = 0; i < 9; i++) {
                    
                    // Riga superiore o separatori 3x3
                    if (i % 3 == 0) {
                        if (i == 0)
                        printf("┏━━━━━━━┳━━━━━━━┳━━━━━━━┓\n");
                        else
                        printf("┣━━━━━━━╋━━━━━━━╋━━━━━━━┫\n");
                    }
                    
                    for (int j = 0; j < 9; j++) {
                        
                        // Separatori verticali
                        if (j % 3 == 0) {
                            if (j == 0)
                            printf("┃ ");
                            else
                            printf("┃ ");
                        }
                        
                        if (m[i][j] == 0)
                        printf(". ");
                        else
                        printf("%d ", m[i][j]);
                    }
                    
                    printf("┃\n");
                }
                
                // Riga finale
                printf("┗━━━━━━━┻━━━━━━━┻━━━━━━━┛\n");
            }