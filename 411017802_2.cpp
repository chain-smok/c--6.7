#include <iostream>
#include <cctype>   // for isdigit()

using namespace std;

#define max 10000
class BigInt {
    friend ostream& operator<<(ostream& , const BigInt&);
    private:              // encaptulation
      short num[max];   
    public:
      BigInt(long value=0) {   // default constructor but also constructor with long int paarameter
          for(int i=0; i<max; i++)
             num[i]=0;
          for(int i=max-1; i>=0 && value!=0; i--){
              num[i]= value % 10;
              value = value / 10;
          }
      }
      BigInt(string str) {    // constructor with a pointer to string parameter
          for(int i=0; i<max; i++)
             num[i]=0;
          int len = str.length();
          for(int j=max-len, k=0; j<max; j++,k++){
              if (isdigit(str[k])) num[j]=str[k] - '0';//str[k]=0~9
          }
      }
      BigInt operator+(const BigInt &op2) const {   // b1=b2+b3;  b3 is parameter object 
            BigInt temp;
            int carry=0;
            for(int i=(max-1); i>=0; i--)  {             // b2 is host object
                 int tnum = num[i] + op2.num[i] + carry;
                 if (tnum>9) {
                     temp.num[i]=tnum % 10;
                     carry=1;
                 }
                 else {
                     temp.num[i]= tnum;
                     carry=0;
                 }
            }
            return temp;
      }            
};


ostream& operator<<(ostream& out, const BigInt & n){  // cout << b1;
    int i;                                  
    for(i=0; (n.num[i]==0) && (i<=(max-1)); i++); 
    
    if (i==max) out << 0;//一直都找不到不等於0的char
    else  {
        for(; i<max; i++)
            out << n.num[i];
    }
    return out;
}

int main(){
    int i;
    char c;
    string a,b;
    BigInt b3(23);
    while(cin>>c){
    if(c=='#')break;
    cin>>a>>b;
    if(c=='+'){
        if(a.length()<b.length()){
            for(i=0;i<b.length()-a.length();i++){
                a+='0';
            }
            a+='\0';
        }
     BigInt b1(a), b2(b);
     b3=b1+b2;
     //cout<<"a="<<b1<<endl;
     cout<<b3<<endl;
    }
    }
}