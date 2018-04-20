#include<bits/stdc++.h>

using namespace std;

#define all(v)              v.begin(),v.end()
#define allr(v)             v.rbegin(),v.rend()
#define sz(v) (int)         v.size()
#define loop(i,from,to)     for(int i=from;i<=to;i++)
#define loopr(i,from,to)    for(int i=from;i>=to;i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;


void dance()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
vector<int> factor;

//n-> height m-> width
//v-> grid
//track-> the right track to solve the problem
vector<vector<bool> > v;
vector<pair<char,int> > track;
int n,m;

//function to check if the position in or out the grid
bool right(int x,int y)
{
    bool f=(n>x&&m>y&&x>=0&&y>=0);
    return f;
}

//function get the grid and find the longest path passes all nodes
int sol(int x,int y,vector<vector<char> > graph,int step)
{

    if(!right(x,y))
        return 0;
    if(v[x][y])
        return 0;
    if(graph[x][y]=='#')
        return 0;


    int mx=0,Recieved=0;
    char c='a';
    v[x][y]=true;
    Recieved=sol(x,y+1,graph,step+1);
    if(Recieved>mx)
    {
        mx=Recieved;
        c='R';
    }
    Recieved=sol(x,y-1,graph,step+1);
    if(Recieved>mx)
    {
        mx=Recieved;
        c='L';
    }
    Recieved=sol(x-1,y,graph,step+1);
    if(Recieved>mx)
    {
        mx=Recieved;
        c='U';
    }
    Recieved=sol(x+1,y,graph,step+1);
    if(Recieved>mx)
    {
        mx=Recieved;
        c='D';
    }
    //compare the current step with the sored
    if(c!='a'&&mx>track[step].second)
        {
            track[step].first=c;
            track[step].second=mx;
        }
    v[x][y]=false;
    return mx+1;


}
int main()
{
    dance();
    int x,y;
    cin>>n>>m;
    v=vector<vector<bool> >(n,vector<bool>(m,false));
    vector<vector<char> > board(n,vector<char>(m));
    int sz=n*m-1;
    //input the grid
    //calculate number of nodes in variable sz
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='O')
                {
                    x=i;
                    y=j;
                }
                if(board[i][j]=='#')
                    sz--;

        }
        //set the size of the track
        track=vector<pair<char,int> >(sz);
        int len=sol(x,y,board,0);
        cout<<len<<endl;//the length of the track len
        //printing the track
    for(int i=0;i<track.size();i++)
        cout<<track[i].first<<' ';
    cout<<endl;
	return 0;
}
