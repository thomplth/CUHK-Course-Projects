/* coord.c */
#include <stdio.h>
#include <math.h> /* needed to use sqrt() square root */

struct coord { float x,y; };
/* declare structure coord as having x and y members */
typedef struct coord COORD;
/* COORD now same as struct coord */

/* declarations above here of headers , struct coord and typedef COORD same as before so not repeated */
float distance(COORD *a, COORD *b);
/* a and b are now pointers to COORD */
void getcoord(COORD *t);
/* inputs coordinate through COORD* pointer t */
int check(COORD *a, COORD *b, COORD *c);
/* pointer of each corner */


int main(void) {
    char pass;

    while(pass != 'q') {
        // confirmation with user
        printf("Please enter three points (y) or quit (q): ");
        scanf(" %c", &pass);
        if(pass == 'q')
            break;
        else if(pass != 'y')
            continue;

        // store addresses in pointers
        COORD triA, triB, triC, *a, *b, *c;
        a=&triA; b=&triB; c=&triC;
        printf("Enter x and y coordinates of the first point\n");
        getcoord(a);
        printf("Enter x and y coordinates of the second point\n");
        getcoord(b);
        printf("Enter x and y coordinates of the third point\n");
        getcoord(c);

        // check and print result
        if(check(a, b, c))
            printf("Output: Yes, it is.\n");
        else
            printf("Output: No, it is not.\n");
    }

    return 0;
}

//int main(void) {
//    COORD origin, cursor, hi, *orig,*curs,*h;
//    orig=&origin; curs=&cursor; h=&hi;
//    /* store addresses in pointers orig and curs */
//    float separation;
//    printf("enter details for origin:\n");
//    getcoord(orig);
//    printf("enter details for cursor:\n");
//    getcoord(curs);
//    printf("enter details for cursor:\n");
//    getcoord(h);
//    separation=distance(orig,curs);
//    printf("the distance between origin and cursor %f\n" , separation);
//    return 0;
//}

float distance(COORD *a, COORD *b) {
    /* calculate distance between a and b */
    float z,vert,horiz; /* z = distance, vert = y1-y2, horiz = x1 - x2 */
    horiz=a->x - b->x; /* horizontal distance note -> pointer syntax */
    vert=a->y - b->y; /* the vertical distance */
    /* calculate z as the hypotenuese of a right angle triangle */
    z=sqrt((horiz*horiz) + (vert*vert)); /* pythagorus theorem: */
    return z; /* z*z = x*x + y*y */
}

void getcoord(COORD *t) { /* inputs x-y coordinate using pointers */
    scanf("%f%f",&t->x,&t->y); /* -> has higher precedence than & */
}

int check(COORD *a, COORD *b, COORD *c) {
    float ab = fabs(distance(a, b));
    float bc = fabs(distance(b, c));
    float ca = fabs(distance(c, a));
    
    if(ab == 0 || bc == 0 || ca == 0)
        return 0;
    else if(ab-bc < 1e-3 && bc-ca < 1e-3 && ca-ab < 1e-3)
        return 1;
    else
        return 0;
}
