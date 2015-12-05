#include <assert.h>
#include <math.h>

#include "temp_multivector.h"

void*
hypre_TempMultiVectorCreateFromSampleVector( void* ii_, int n, void* sample ) { 

  int i;
  hypre_TempMultiVector* x;
  HYPRE_InterfaceInterpreter* ii = (HYPRE_InterfaceInterpreter*)ii_;

  x = (hypre_TempMultiVector*) malloc(sizeof(hypre_TempMultiVector));
  assert( x != NULL );
  
  x->interpreter = ii;
  x->numVectors = n;
  
  x->vector = (void**) calloc( n, sizeof(void*) );
  assert( x->vector != NULL );

  x->ownsVectors = 1;
  x->mask = NULL;
  x->ownsMask = 0;

  for ( i = 0; i < n; i++ )
    x->vector[i] = (ii->CreateVector)(sample);

  return x;

}

void*
hypre_TempMultiVectorCreateCopy( void* src_, int copyValues ) {

  int i, n;

  hypre_TempMultiVector* src;
  hypre_TempMultiVector* dest;

  src = (hypre_TempMultiVector*)src_;
  assert( src != NULL );

  n = src->numVectors;

  dest = hypre_TempMultiVectorCreateFromSampleVector( src->interpreter, 
						      n, src->vector[0] );
  if ( copyValues )
    for ( i = 0; i < n; i++ ) {
      (dest->interpreter->CopyVector)(src->vector[i],dest->vector[i]);
  }

  return dest;
}

void 
hypre_TempMultiVectorDestroy( void* x_ ) {

  int i;
  hypre_TempMultiVector* x = (hypre_TempMultiVector*)x_;

  if ( x == NULL )
    return;

  if ( x->ownsVectors && x->vector != NULL ) {
    for ( i = 0; i < x->numVectors; i++ )
      (x->interpreter->DestroyVector)(x->vector[i]);
    free(x->vector);
  }
  if ( x->mask && x->ownsMask )
    free(x->mask);
  free(x);
}

int
hypre_TempMultiVectorWidth( void* x_ ) {

  hypre_TempMultiVector* x = (hypre_TempMultiVector*)x_;

  if ( x == NULL )
    return 0;

  return x->numVectors;
}

int
hypre_TempMultiVectorHeight( void* x_ ) {

  return 0; 
}

/* this shallow copy of the mask is convenient but not safe;
   a proper copy should be considered */
void
hypre_TempMultiVectorSetMask( void* x_, int* mask ) {

  hypre_TempMultiVector* x = (hypre_TempMultiVector*)x_;

  assert( x != NULL );
  x->mask = mask;
  x->ownsMask = 0;
}

void
hypre_TempMultiVectorClear( void* x_ ) {

  int i;
  hypre_TempMultiVector* x = (hypre_TempMultiVector*)x_;

  assert( x != NULL );

  for ( i = 0; i < x->numVectors; i++ )
    if ( x->mask == NULL || (x->mask)[i] )
      (x->interpreter->ClearVector)(x->vector[i]);
}

void
hypre_TempMultiVectorSetRandom( void* x_, int seed ) {

  int i;
  hypre_TempMultiVector* x = (hypre_TempMultiVector*)x_;

  assert( x != NULL );

  srand( seed );
  for ( i = 0; i < x->numVectors; i++ ) {
    if ( x->mask == NULL || (x->mask)[i] ) {
      /*      seed = rand();*/
      (x->interpreter->SetRandomValues)(x->vector[i], seed+i);
    }
  }
}

void
hypre_collectVectorPtr( int* mask, hypre_TempMultiVector* x, void** px ) {

  int ix, jx;

  if ( mask != NULL ) {
    for ( ix = 0, jx = 0; ix < x->numVectors; ix++ )
      if ( mask[ix] )
	px[jx++] = x->vector[ix];
  }
  else
    for ( ix = 0; ix < x->numVectors; ix++ )
      px[ix] = x->vector[ix];

}

void 
hypre_TempMultiVectorCopy( void* src_, void* dest_ ) {

  int i, ms, md;
  void** ps;
  void** pd;
  hypre_TempMultiVector* src = (hypre_TempMultiVector*)src_;
  hypre_TempMultiVector* dest = (hypre_TempMultiVector*)dest_;

  assert( src != NULL && dest != NULL );

  ms = aux_maskCount( src->numVectors, src->mask );
  md = aux_maskCount( dest->numVectors, dest->mask );
  assert( ms == md );
	
  ps = (void**) calloc( ms, sizeof(void*) );
  assert( ps != NULL );
  pd = (void**) calloc( md, sizeof(void*) );
  assert( pd != NULL );

  hypre_collectVectorPtr( src->mask, src, ps );
  hypre_collectVectorPtr( dest->mask, dest, pd );

  for ( i = 0; i < ms; i++ )
    (src->interpreter->CopyVector)(ps[i],pd[i]);

  free(ps);
  free(pd);
}

void 
hypre_TempMultiVectorAxpy( double a, void* x_, void* y_ ) { 
	
  int i, mx, my;
  void** px;
  void** py;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  mx = aux_maskCount( x->numVectors, x->mask );
  my = aux_maskCount( y->numVectors, y->mask );
  assert( mx == my );

  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );

  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  for ( i = 0; i < mx; i++ )
    (x->interpreter->Axpy)(a,px[i],py[i]);

  free(px);
  free(py);
}

void 
hypre_TempMultiVectorByMultiVector( void* x_, void* y_,
				     int xyGHeight, int xyHeight, 
				     int xyWidth, double* xyVal ) { 
/* xy = x'*y */	

  int ix, iy, mx, my, jxy;
  double* p;
  void** px;
  void** py;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  mx = aux_maskCount( x->numVectors, x->mask );
  assert( mx == xyHeight );

  my = aux_maskCount( y->numVectors, y->mask );
  assert( my == xyWidth );

  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );

  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  jxy = xyGHeight - xyHeight;
  for ( iy = 0, p = xyVal; iy < my; iy++ ) {
    for ( ix = 0; ix < mx; ix++, p++ )
      *p = (x->interpreter->InnerProd)(px[ix],py[iy]);
    p += jxy;
  }

  free(px);
  free(py);

}

void 
hypre_TempMultiVectorByMultiVectorDiag( void* x_, void* y_,
					 int* mask, int n, double* diag ) {
/* diag = diag(x'*y) */	

  int i, mx, my, m;
  void** px;
  void** py;
  int* index;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  mx = aux_maskCount( x->numVectors, x->mask );
  my = aux_maskCount( y->numVectors, y->mask );
  m = aux_maskCount( n, mask );
  assert( mx == my && mx == m );

  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );

  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  index = (int*)calloc( m, sizeof(int) );
  aux_indexFromMask( n, mask, index );

  for ( i = 0; i < m; i++ )
    *(diag+index[i]-1) = (x->interpreter->InnerProd)(px[i],py[i]);
  
  free(index);
  free(px);
  free(py);

}

void 
hypre_TempMultiVectorByMatrix( void* x_, 
			       int rGHeight, int rHeight, 
			       int rWidth, double* rVal,
			       void* y_ ) {

  int i, j, jump;
  int mx, my;
  double* p;
  void** px;
  void** py;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  mx = aux_maskCount( x->numVectors, x->mask );
  my = aux_maskCount( y->numVectors, y->mask );

  assert( mx == rHeight && my == rWidth );
  
  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );
  
  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  jump = rGHeight - rHeight;
  for ( j = 0, p = rVal; j < my; j++ ) {
    (x->interpreter->ClearVector)( py[j] );
    for ( i = 0; i < mx; i++, p++ )
      (x->interpreter->Axpy)(*p,px[i],py[j]);
    p += jump;
  }

  free(px);
  free(py);
}

void 
hypre_TempMultiVectorXapy( void* x_, 
			   int rGHeight, int rHeight, 
			   int rWidth, double* rVal,
			   void* y_ ) {

  int i, j, jump;
  int mx, my;
  double* p;
  void** px;
  void** py;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  mx = aux_maskCount( x->numVectors, x->mask );
  my = aux_maskCount( y->numVectors, y->mask );

  assert( mx == rHeight && my == rWidth );
  
  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );
  
  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  jump = rGHeight - rHeight;
  for ( j = 0, p = rVal; j < my; j++ ) {
    for ( i = 0; i < mx; i++, p++ )
      (x->interpreter->Axpy)(*p,px[i],py[j]);
    p += jump;
  }

  free(px);
  free(py);
}

void 
hypre_TempMultiVectorByDiagonal( void* x_, 
				 int* mask, int n, double* diag,
				 void* y_ ) {

  int j;
  int mx, my, m;
  void** px;
  void** py;
  int* index;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  mx = aux_maskCount( x->numVectors, x->mask );
  my = aux_maskCount( y->numVectors, y->mask );
  m = aux_maskCount( n, mask );
	
  assert( mx == m && my == m );

  if ( m < 1 )
    return;

  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );

  index = (int*)calloc( m, sizeof(int) );
  aux_indexFromMask( n, mask, index );

  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  for ( j = 0; j < my; j++ ) {
    (x->interpreter->ClearVector)(py[j]);
    (x->interpreter->Axpy)(diag[index[j]-1],px[j],py[j]);
  }

  free(px);
  free(py);
  free( index );
}

void 
hypre_TempMultiVectorEval( void (*f)( void*, void*, void* ), void* par,
			   void* x_, void* y_ ) {

  long i, mx, my;
  void** px;
  void** py;
  hypre_TempMultiVector* x;
  hypre_TempMultiVector* y;

  x = (hypre_TempMultiVector*)x_;
  y = (hypre_TempMultiVector*)y_;
  assert( x != NULL && y != NULL );

  if ( f == NULL ) {
    hypre_TempMultiVectorCopy( x, y );
    return;
  }

  mx = aux_maskCount( x->numVectors, x->mask );
  my = aux_maskCount( y->numVectors, y->mask );
  assert( mx == my );

  px = (void**) calloc( mx, sizeof(void*) );
  assert( px != NULL );
  py = (void**) calloc( my, sizeof(void*) );
  assert( py != NULL );

  hypre_collectVectorPtr( x->mask, x, px );
  hypre_collectVectorPtr( y->mask, y, py );

  for ( i = 0; i < mx; i++ )
    f( par, (void*)px[i], (void*)py[i] );

  free(px);
  free(py);
}

int
hypre_TempMultiVectorPrint( void* x_, const char* fileName ) {

  int i, ierr;
  hypre_TempMultiVector* x;
  char fullName[128];
  
  x = (hypre_TempMultiVector*)x_;
  assert( x != NULL );
  if ( x->interpreter->PrintVector == NULL )
    return 1;

  ierr = 0;
  for ( i = 0; i < x->numVectors; i++ ) {
    sprintf( fullName, "%s.%d", fileName, i ); 
    ierr = ierr || 
      (x->interpreter->PrintVector)( x->vector[i], fullName );
  }
  return ierr;
}
							
void* 
hypre_TempMultiVectorRead( MPI_Comm comm, void* ii_, const char* fileName ) {

  int i, n, id;
  FILE* fp;
  char fullName[128];
  hypre_TempMultiVector* x;
  HYPRE_InterfaceInterpreter* ii = (HYPRE_InterfaceInterpreter*)ii_;
  
  if ( ii->ReadVector == NULL )
    return NULL;

  MPI_Comm_rank( comm, &id );
  
  n = 0;
  do {
    sprintf( fullName, "%s.%d.%d", fileName, n, id ); 
    if ( (fp = fopen(fullName, "r")) ) {
	  n++;
      fclose( fp );
	}
  } while ( fp );

  if ( n == 0 )
    return NULL;

  x = (hypre_TempMultiVector*) malloc(sizeof(hypre_TempMultiVector));
  assert( x != NULL );
  
  x->interpreter = ii;

  x->numVectors = n;
  
  x->vector = (void**) calloc( n, sizeof(void*) );
  assert( x->vector != NULL );

  x->ownsVectors = 1;

  for ( i = 0; i < n; i++ ) {
    sprintf( fullName, "%s.%d", fileName, i ); 
    x->vector[i] = (ii->ReadVector)( comm, fullName );
  }

  x->mask = NULL;
  x->ownsMask = 0;

  return x;
}
							
int
aux_maskCount( int n, int* mask ) {

  int i, m;

  if ( mask == NULL )
    return n;

  for ( i = m = 0; i < n; i++ )
    if ( mask[i] )
      m++;

  return m;
}

void
aux_indexFromMask( int n, int* mask, int* index ) {

  long i, j;
  
  if ( mask != NULL ) {
    for ( i = 0, j = 0; i < n; i++ )
      if ( mask[i] )
	index[j++] = i + 1;
  }
  else
    for ( i = 0; i < n; i++ )
      index[i] = i + 1;

}


