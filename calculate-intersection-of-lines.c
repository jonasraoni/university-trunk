/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Given two lines, it finds the point of intersection
 */

#include <stdio.h>

typedef struct {
        float x1, x2, y1, y2;
} Segment;

typedef struct {
	float x, coefLinear;
} Equation;

void fillSegment( Segment *s ){
    printf( "Input the coordinates of the segment in the format: x1,y1,x2,y2:" );
    scanf( "%f,%f,%f,%f", &s->x1, &s->y1, &s->x2, &s->y2 );
}

float getTangent( Segment *s ){
	return isInvalidTangent( s ) ? 0 : ( s->y1 - s->y2 ) / ( s->x1 - s->x2 );
}

int isInvalidTangent( Segment *s ){
	return !( s->x1 - s->x2 );
}

int main( int argc, char *argv[] ){
    Segment segA, segB;
	Equation eqA, eqB;
 	float tangentA, tangentB;
	float intersectionX, intersectionY;

	fillSegment( &segA );
	fillSegment( &segB );

    tangentA = getTangent( &segA );
	tangentB = getTangent( &segB );

	if( isInvalidTangent( &segA ) && isInvalidTangent( &segB ) ){
		printf( "The lines are parallels, so they have no intersection.");
		system( "pause" );
		return 0;
	}
	else if( isInvalidTangent( &segA ) ){
  		intersectionX = segA.x1;
		intersectionY = segB.y1 + tangentB * ( segA.x1 - segB.x1 );
	}
	else if( isInvalidTangent( &segB ) ){
		intersectionX = segB.x1;
		intersectionY = segA.y1 + tangentA * ( segB.x1 - segA.x1 );
	}
	else if( tangentA == tangentB ){
		printf( "The lines are paralles, so they have no intersection.");
		system( "pause" );
		return 0;
	} else {
		eqA.x = tangentA;
		eqA.coefLinear = tangentA * -segA.x1 + segA.y1;

		eqB.x = tangentB;
		eqB.coefLinear = tangentB * -segB.x1 + segB.y1;

	    intersectionX = ( eqB.coefLinear - eqA.coefLinear ) / ( eqA.x - eqB.x );
		intersectionY = eqA.x * intersectionX + eqA.coefLinear;
	}

	printf( "\nThe intersection point is: (%f, %f )", intersectionX, intersectionY );
	system( "pause" );
	return 0;

}
