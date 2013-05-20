//
//  main.c
//  UltimateTest
//
//  Created by 王选易 on 13-5-4.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include<stdio.h>

int main()
{
    int test[2][2] = {1, 2};
    FILE *read;
    FILE *write;
    char *filename = "myfile.txt";
    read = fopen( filename, "r" );
//    if( read == NULL )
//    {
        //File doesn't exist. Have to write something
        write = fopen( filename, "w" );
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        fprintf( write, "%d", test[i][j] );
        fclose( write );
//    }
//    else
//    {
//        //File exists. Read data from the file
//        char somedata[ 20 ];
//        fscanf( read, "%s", somedata );
//        printf( "%s\n", somedata );
//        fclose( read );
//    }
    return 0;
}

