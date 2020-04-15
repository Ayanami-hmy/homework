# homework
程设实习hw
#include<iostream>
#include<cmath>
using namespace std;
char wall[15][15]={'\0'};
int operate[15][15]={0};
char wall_1[15][15]={'\0'};
void draw(int i,int j){//用来判断是否在墙范围内并画图
    	
    if(i>=0&&i<=14&&j>=0&&j<=14)
    {
		if(wall[i][j]=='w')
    		wall[i][j]='y';
    	else if(wall[i][j]=='y')
    		wall[i][j]='w';
    }
    
}
int operate_number(int n){//用来计算总共操作数
    int number=0;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
        	//cout<<operate[i][j];
        	//cout<<wall[i][j];
            if(operate[i][j]==1){
                number++;
            }
        }
        //cout<<endl;
    }
    return number;
}
void return_operate(){//用来归零操作
    for(int i=0;i<=14;i++){
        for(int j=0;j<=14;j++){
            operate[i][j]=0;
            wall[i][j]=wall_1[i][j];
        }
    }
}
bool judge(int n){//用来判断是否画满
    for(int i=0;i<=n-1;i++){
        if(wall[n-1][i]=='w'){
        	return false;
		}
    }
    return true;
}
void turn(int i,int n){//将十进制转二进制对应到第一行墙染色块
	
    for(int j=n-1;j>=0;j--){
        operate[0][j]=i%2;
        i/=2;
    }
}
///////////////////////
//void print_wall(int n){
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<wall[i][j];
//		}
//		cout<<endl;
//	}
//	//cout<<"---------"<<endl;
//}
//////////////////////
//void print_op(int n){
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<operate[i][j];
//		}
//		cout<<endl;
//	}
//	cout<<"----------"<<endl;
//}
//
/////////////////////
int main (){
    int n;
    int min=0;
    bool op=false; 
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>wall[i][j];
            wall_1[i][j]=wall[i][j];
        }
    }
    for(int i=0;i<pow(2,n);i++){
        turn(i,n);
        for(int j=0;j<n;j++){//根据i来画第一行
            if(operate[0][j]==1){
                draw(0,j);
                draw(0,j-1);
                draw(0,j+1);
                draw(1,j);
                
            }
        }
        for(int line=1;line<n;line++){//
            for(int row=0;row<n;row++){
                if(wall[line-1][row]=='w'){
                    draw(line-1,row);
                    draw(line,row);
                    draw(line+1,row);
                    draw(line,row-1);
                    draw(line,row+1);
                    operate[line][row]=1;
                }
            }
        }//到此一次遍历已经结束了，开始进行计算和判断
        //
//		cout<<operate_number(n)<<endl;
//		
//		print_wall(n);
//		print_op(n);
//		
//		
//		
		//
		if(judge(n)){
            if(min==0&&!op){
                min=operate_number(n);                
            }
            else
            {
                if(min>operate_number(n)){
                    min=operate_number(n);
                }
            }
            op=true;
        }
        
        return_operate();
    }
    if(min==0){
    	if(op)
        cout<<0<<endl;
        else
        cout<<"inf"<<endl;
    }
    else
    {
        cout<<min<<endl;
    }
    
    return 0;
}
