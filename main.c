#include<stdio.h>
#include<stdlib.h>
#include"fatal.h"
#include"linklist.h"

void
PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%d\t", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n\n" );
    }
}

int main( void )
{
    List L;
    Position P;

    L = MakeEmpty( NULL );
    P = Header( L );

    FILE *fp;
    fp = fopen( "data 100.txt" , "r" );

    if ( fp == NULL )
    {
        printf( "The file is not assist.\n" );
        exit( -1 );
    }

    int array[100];
    int counter , check;

    for( counter = 0 ; counter < 100 ; counter++ )
    {
        check = fscanf( fp , "%d" , &array[ counter ] );
        if( check == 0 )
        {
            printf( "Error input!!!\n" );
            exit( -1 );
        }
        else
        {
            Insert( array[ counter ] , L , P );
            P = Advance( P );
        }
    }

    PrintList( L );

    P = Header( L );
    for( counter = 1 ; counter < 100 ; counter ++ )
    {
        if( counter % 2 == 0 )
        {
            P = Advance( P );
        }
        else if( counter % 2 == 1 )
        {
            Delete( Retrieve( P ) , L );
            P = Advance( P );
        }
    }

    PrintList( L );

    for( counter = 0 ; counter < 100 ; counter++ )
    {
        if( Retrieve( P ) != 100 )
        {
            check = 0;
        }
        else
        {
            check = 1;
            break;
        }
        P = Advance( P );
    }

    if( check == 1 )
    {
        printf( "Number 100 is in the list.\n\n" );
    }
    else
    {
        printf( "Number 100 is not in the list.\n\n" );
    }

    P = Header( L );
    for( counter = 0 ; counter < 100 ; counter += 2 )
    {
        printf( "%d\t" , Retrieve( P ) );
        P = Advance( P );
    }

    printf( "\n" );

    return( 0 );
}
