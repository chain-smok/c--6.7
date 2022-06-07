#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
using namespace std;
class retangle {
   protected:  
     int length;
     int width;

   public:
      retangle():length(0),width(0){};  ///retangle;
      retangle(int slength,int swidth):length(slength),width(swidth){};//retangle 
      retangle(retangle &sd){
          length=sd.length;
          width=sd.width; //this
      }
      int getLength(){return length;};
      int getwidth(){return length;};
      void setLength(int sdlength){
        length=sdlength;
      }
      void setWidth(int sdwidth){
        width=sdwidth;
      }
      int Area(int length,int width){
        return length*width;
      }
      int Volume(int length,int width){
        return length*width; 
      }
      void print(){
          cout<<"len="<<length<<" and wid= "<<width<<endl;
      }
};
class cuboid: protected retangle{
   private:
      int height;
   public:
      cuboid():retangle(),height(0){};//cuboid s1;
      cuboid(int sslength,int kkwidth,int uheight):retangle(sslength,kkwidth),height(uheight){}
      cuboid(cuboid &tj):retangle(tj.length,tj.width),height(tj.height){}
      void setH(double ukH){
          height=ukH;
      }
      int Area(int uulength,int uuwidth,int uuheight){
        return 2*(uulength*uuwidth+uuwidth*uuheight+uuheight*uulength);
      }
      int Volume(int stlength,int stwidth,int stheight){
          return (stlength*stwidth*stheight);
      }
      void print(){//volume area
          int ver=Volume(length,width,height);
          int aws=Area(length,width,height);
          //cout<<"len="<<length<<" ,wid="<<width<<" ,Hei="<<height<<endl;
          cout<<"Volume:="<<ver<<"\nSuirface="<<aws<<endl;

      }

};
int main(){
    int n,width,height;
    int length;
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
    scanf("%d",&length);
    scanf("%d",&width);
    scanf("%d",&height);
    cuboid ss(length,width,height);
    cout<<"#"<<k<<endl;
    ss.print();
    }
}
