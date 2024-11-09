#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

//using namespace std;
class algo
{
	private:
	int x11;int y11;int x22;int y22;int icolour;
	public:
	
	int x1,y1,xc,yc,R,di,d,d1;
	void get();
	void put();
	void cir();
 
	void  DDA_line(int x11,int y11,int x22,int y22,int icolour)
		{
		int i;
		float dx,dy,steps,xinc,yinc,X,Y;
		dx=(x22-x11);
		dy=(y22-y11);
		if (abs(dx)>abs(dy))
		{
		steps=abs(dx);
		}
		else
		{
		steps=abs(dy);
		}
		xinc=dx/steps;
		yinc=dy/steps;
		X=x11;
		Y=y11;
		for (i=0;i<steps;i++)
		{
		putpixel(floor(X),floor(Y),icolour);
		X=X+xinc;
		Y=Y+yinc;
		}
		}
};

void algo::get()

{
	cout<<"enter coordinate x and y that is center:";
	cin>>xc>>yc;
	cout<<"enter radius of circle";
	cin>>R;
}
void algo::put()
{
	cout<<"center point is:"<<xc<<yc;
	cout<<"radius is"<<R;
}
void algo::cir()
{
	x1=0;
	y1=R;
	di=2*(1-R);
	int limit=0;
	while(y1>=limit)
{
	putpixel(xc+x1, yc+y1, 3);
	putpixel(xc-x1, yc+y1, 4);
	putpixel(xc-x1, yc-y1, 5);
	putpixel(xc+x1, yc-y1, 6);

	
	
	if(di<=0)
		{
				d=(2*di)-(2*y1)-1;
				if(d<=0)
					{
					
						x1=x1+1;
						di=di+(2*x1)+1;
					}
				else
				{
						
					x1=x1+1;
					y1=y1-1;
					di=di+(2*x1)-(2*y1)+2;
				}
		}
	else if(di>0)
	{
		d=(2*di)-(2*x1)-1;
		if(d<=0)
		{
					x1=x1+1;
					y1=y1-1;
					di=di+(2*x1)-(2*y1)+2;
		}
		else
		{
		y1=y1-1;
		di=di-(2*y1)+1;
		}
	}
		
	
}
}


int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
algo obj;

obj.DDA_line(120,120,240,120,RED);
algo obj1;

obj1.DDA_line(240,120,240,240,RED);
algo obj2;
obj2.DDA_line(240,240,120,240,RED);
algo obj3;
obj3.DDA_line(120,240,120,120,RED);
algo obj4;
obj.DDA_line(120,180,180,120,YELLOW);
algo obj5;
obj5.DDA_line(180,120,240,180,YELLOW);
algo obj6;
obj6.DDA_line(240,180,180,240,YELLOW);
algo obj7;
obj7.DDA_line(120,180,180,120,YELLOW);
algo obj8;
obj8.DDA_line(120,180,180,240,YELLOW);
algo obj9;
	obj9.get();
	obj9.put();
	obj9.cir();					//180,180,40

//delay(500000);
getch();
closegraph();
return 0;


}
