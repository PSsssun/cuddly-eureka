#include <stdio.h>

typedef struct point3d
{
    float x;
    float y;
    float z;
} Point3d;

void Print3d_print(const Point3d *pd)
{
    printf("(%g, %g, %g )", pd->x, pd->y, pd->z);
}

//or more efficient
// #define Point3d_print( pd ) \
//  printf("(%g, %g, %g )", pd->x, pd->y, pd->z);
//


//or use a function instead
/**
  void my_foo()
  {
    Point3d *pd = get_a_point();
    ...
    printf("(%g, %g, %g )", pd->x, pd->y, pd->z)l;
  }

  */

#define X( p, xval ) (p.x) = (xval);

int main()
{

    {
        Point3d pt;
        pt.x = 0.0;
        Point3d* ppt = &pt;
        Print3d_print(ppt);
    }

    {
        Point3d pt;
        X( pt, 0.0);

        Point3d* ppt = &pt;
        Print3d_print(ppt);
    }
}

