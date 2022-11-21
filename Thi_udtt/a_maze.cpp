#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20

//  Các hướng di chuyển
int direction[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
					// {NW, N, NE, W, E, SW, S, SE}

int maze[MAXN][MAXN];

int flag=0;



typedef struct Node{
    int x;
    int y;

    struct Node *next;
}Node;

typedef Node* Stack;

// Các hàm thao tác với stack

Stack createEmptyStack(){
    Stack p;
    p=(Stack)malloc(sizeof(Node));
    if(p){
        p->next=NULL;
        return p;
    }
    else{
        printf("No space!\n");
        return NULL;
    }
}

void push(int x,int y,Stack s){
    Stack p;
    p=(Stack)malloc(sizeof(Node));
    if(p){
        p->x=x;
        p->y=y;
        if(!s->next){
        	p->next=NULL;
		}
        else{
        	p->next=s->next;
		}
        s->next=p;
    }
    else{
        printf("No space!\n");
    }
}

int isEmpty(Stack s){
    if(s->next==NULL){
    	return 1;
	}
    else{
    	return 0;
	}
}

void pop(Stack s){
    Stack p;
    p=s->next;
    if(p->next){
        s->next=p->next;
        free(p);
    }
    else{
    	return;
	}
}

Node top(Stack s){
    Node t;

    t=*(s->next);
    return t;
}


void mazePath(int x,int y,int endx,int endy,int n,int m,Stack s);
void printPath(Stack s,int n,int m);

int main()
{
    int n,m,i,j,xa,xb,ya,yb;

    printf("Nhap kich thuoc me cung - (m, n):\n");
    scanf("%d%d",&n,&m);
    if(n<=20&&m<=20){
        printf("Nhap me cung: \n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
               	scanf("%d",&maze[i][j]);
            }
        }
        printf("\n");

        printf("Me cung duoc tao:\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d  ",maze[i][j]);
            }
            printf("\n");
        }

        printf("Nhap diem bat dau va diem ket thuc:\n");
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);


        maze[xa-1][ya-1]=2;


        Stack s=createEmptyStack();

        //QueueLink q=createEmptyQueue();
        mazePath(xa-1,ya-1,xb-1,yb-1,n,m,s);
        if(!flag){
        	printf("Khong co duong\n");
		}
    }
    else{
    	printf("Nhap du lieu ngoai pham vi me cung\n");
	}
}

// Đi qua mê cung bằng DFS
void mazePath(int x,int y,int endx,int endy,int n,int m,Stack s){
    int newx,newy,i;
    Node t;
    for(i=0;i<8;i++){
    	// xác định toạ độ ô kế
        newx=x+direction[i][0];
        newy=y+direction[i][1];
        //
        if(newx>=0&&newx<n&&newy>=0&&newy<m&&maze[newx][newy]==0){   // nếu hợp lệ: k quá kích cỡ mê cung và ô đc đi
            push(newx,newy,s);	// thêm ô đã đi vào s
            maze[newx][newy]=2;	// ô đi qua - đánh dấu
            if(newx==endx&&newy==endy){	// đến điểm cuối
                //flag++;					// lấy thứ tự lần duyệt
                printPath(s,n,m);
                maze[newx][newy]=0;
                pop(s);
            }
//            else{
//                mazePath(newx,newy,endx,endy,n,m,s);	// tìm trường hợp tiếp theo, nếu còn
//            }
        }
    }
    maze[x][y]=0;
    pop(s);
}

// in đường đã đi
void printPath(Stack s,int n,int m){
    int count =0; // độ dài đường dẫn
    s=s->next;
    int i=0,j=0;
    printf("\nDuong di cua cach di thu - %d: \n",flag);
    for(i=0;i<n;i++){                   // triển khai đường đi
        for(j=0;j<m;j++){
            if(maze[i][j]==2){
            	printf("*  ");
			}
            else{
            	printf("%d  ",maze[i][j]);
			}
        }
        printf("\n");
    }
    while(s->next){        		// in đường ra theo vị trí
        printf("(%d,%d)->",s->x+1,s->y+1);
        s=s->next;
        count++;
    }
    printf("(%d,%d)",s->x+1,s->y+1);
    count++;
    printf("\n");
    printf("Do dai duong di: %d\n\n",count);
}
/*
0 1 1 1
0 1 1 0
1 0 0 1
1 1 0 1
1 0 1 0
*/

/*
0 1 1 1 0
0 1 1 0 1
1 0 1 0 1
1 0 0 1 0
0 1 1 0 1
*/
