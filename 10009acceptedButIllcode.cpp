#include<bits/stdc++.h>
#define MAXDEGREE    500   /**Maximum vertex outdegree **/
#define MAXV         1000   /**Maximum number of vertices**/
using namespace std;

class Queue{
	public:
		char *data;
		int MAX;
		int font,rear;
		Queue(int x){
			MAX = x;
			data = new char[x];
			font = rear = -1;
		}
		void enqueue(int x){                       ///MAX = 3
			if(font == -1 && rear == -1){          ///rear = 0 ///false                     ///false                ///false
				font = rear = 0;                   ///font = 0
			}
			else if(((rear+1) % MAX) == font){                 /// (0+1) % 3 = 1 ,font = 0  ///(1+1)%3=2            ///(2+1)%3 = 0 true
				cout<<"overflow"<<endl;
				return;
			}
			else{
				rear = (rear + 1) % MAX;         ///rear = 0  /// rear = (0+1)%3 = 1       ///rear = (1+1)%3 = 2    ///false
			}
			data[rear] = x;
		}
		char dequeue(){
			if(font == rear && (font != (-1))){
				int i;
				i = data[font];
				font = rear = -1;
				return i;
			}
			else if((font == (-1))&&(rear ==(-1))){
				cout<<"unerflow"<<endl;
				exit(1);
			}
			else {
				int i;
				i = data[font];
				font = (font + 1)%MAX;
				return i;
			}
		}
		int isempty(){
            if(font==-1 && rear == -1){
                return 1;
            }
            return 0;
		}
};


class grph{
    public:
    int totalvertices;              /**number of vertices**/
    int totaledges;                 /**Number of edges**/
    char first[MAXV][2];
    char vertices[MAXV];
    char edges[MAXV][MAXDEGREE];
    int degree[MAXV+1];

    bool discovered[MAXV];
    char parent[MAXV];


    grph(){
            int i; ///counter
            totalvertices = 0;
            totaledges = 0;
            for(i=0;i<MAXV;i++){
                degree[i]=0;///set all vertices degree to zero
                parent[i]= '&';
                discovered[i] = false;
            }
    }
    void init(){
		int i= 0;
		for(i=0;i<MAXV;i++){
			parent[i]= '&';
            discovered[i] = false;
		}
	}

    int removeDuplicates(char arr[], int n){
        if (n==0 || n==1)
            return n;
        int j = 0;
        for (int i=0; i < n-1; i++)
            if (arr[i] != arr[i+1])
                arr[j++] = arr[i];

        arr[j++] = arr[n-1];

        return j;
    }
    void read(bool directed,int m){
        totaledges = m;
        int i;
        for(i=0;i<m;i++){
            string x;
            string y;
            cin>>x>>y;
            char c1,c2;
            c1 = x[0];
            c2 = y[0];
            first[i][0] = c1;
            first[i][1] = c2;
            insert_edge(first[i][0],first[i][1],directed);
        }
        int j;

        /*cout<<"taken input"<<endl;
        for(i=0;i<m;i++){
            for(j=0;j<2;j++){
                cout<<first[i][j]<<' ';
            }
            cout<<endl;
        }*/
        int k = 0;
        for(i=0;i<m;i++){
            for(j=0;j<2;j++){
                vertices[k++] = first[i][j];
            }
        }
        /*
        cout<<endl;
        */
        /*
        cout<<"before Sorting them"<<endl;
        for(i=0;i<2*m;i++){
			cout<<vertices[i]<<' ';
		}
		cout<<endl;
		*/

        sort(vertices,vertices+2*m);


        /*cout<<"after Sorting them"<<endl;
        for(i=0;i<2*m;i++){
			cout<<vertices[i]<<' ';
		}
		cout<<endl;*/


        totalvertices = removeDuplicates(vertices,2*m);

        /*
        for(i=0;i<totalvertices;i++){
			cout<<vertices[i]<<' ';
		}
		cout<<endl;
		*/
    }
    void insert_edge(char x,char y,bool directed){
            /*if(degree[x] > MAXDEGREE){
                cout<<"warning"<<endl;
            }*/

            edges[x][degree[x]] = y;
            degree[x]++;
            if(directed == false){
                insert_edge(y,x,true);
            }
            else{
                totaledges++;
            }
    }
    void bfs(char x){
        char v;
        int i;
        Queue *q=new Queue( MAXV);
        q->enqueue(x);
        discovered[x] = true;

        while(!q->isempty()){
                v = q->dequeue();
                for(i=0;i<degree[v];i++){
                    if(discovered[edges[v][i]] == false){
                        q->enqueue(edges[v][i]);
                        discovered[edges[v][i]] = true;
                        parent[edges[v][i]] = v;
                    }
                }
        }

    }/*
    void print(){
        int i,j;
        for(i=0;i<totalvertices;i++){
            cout<<vertices[i]<<" : ";
            for(j=0;j<degree[vertices[i]];j++){
                cout<<edges[vertices[i]][j]<<' ';
            }
            cout<<endl;
        }
    }*/
    void find_path(char start ,char end){
        if((start == end) || (end == '&')){
            cout<<start;
        }
        else{
            find_path(start,parent[end]);
            cout<<end;
        }
    }
};


int main(){
/*
Rome Turin
Turin Venice
Turin Genoa
Rome Pisa
Pisa Florence
Venice Athens
Turin Milan
Turin Pisa
Milan Florence
Athens Genoa
*/

    int tt;
    cin>>tt;
    while(tt--){
		int m,n;
		//cout<<endl;
		cin>>m>>n;
		grph g;
		g.read(false,m);
		//g.print();
		int count = 0;
		while(n--){
			string x,y;
			cin>>x>>y;
			g.init();
			g.bfs(x[0]);
			g.find_path(x[0],y[0]);
			count++;
			if(tt == 0 && n == 0){
                continue;
            }
		    cout<<endl;
        }
        cout<<endl;
	}
}
