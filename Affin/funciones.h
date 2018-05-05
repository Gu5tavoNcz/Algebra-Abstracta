#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int modulo(int a, int b){
	int q,r;
	q=a/b;
	r=a-(q*b);
	if(r<0){
		q--;
		r+=b;
	}
	return r;
}

int euclides(int a, int b){
	int r=modulo(a,b);
	while(r>0){
		a=b;
		b=r;
		r=modulo(a,b);
	}
	return b;
}

void euclides_extendido(int a,int b, int *q1, int *q2, int *q3){
    int d,x,y,x1,x2,y1,y2,q,r;
    if(b==0){
        d=a;
        x=1;
        y=0;
        //return(d);
    }
    x1=0;
    x2=1;
    y1=1;
    y2=0;
    while(b>0){
        q=a/b;
        r=a-(q*b);
        x=x2-(q*x1);
        y=y2-(q*y1);
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    *q1=d;
    *q2=x;
    *q3=y;
}


#endif // FUNCIONES_H_INCLUDED
