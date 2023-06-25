#ifndef WIDGET_H
#define WIDGET_H

#include<iostream>
#include <QWidget>
#include<QVector>
#include <queue>
#include <cstring>
#define	N 1000

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//定义图的结构体
struct edge{
    int v;
    int w;
    edge(int v1,int w1):v(v1),w(w1){
    }
};

typedef struct vgNode{
    QVector<edge>edges[N];
    int data[N];
    int v,e;
}vecGraph;

//实现控件的类
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton0_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton10_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

    void on_pushButton_short_clicked();

    void on_pushButton_all_clicked();

    void on_pushButton_updatelj_clicked();

    void on_pushButton_deletelj_clicked();

    void on_pushButton_addjd_clicked();

    void on_pushButton_deletejd_clicked();

    void on_pushButton_addlj_clicked();

private:
    Ui::Widget *ui;
    QString qi="";
    QString zhong="";
    QString lujing="";
    vecGraph g;     //声明图
};



//加边
inline void add_edge(vecGraph &g, int u,int v,int w){
    g.edges[u].push_back(edge(v,w));
    g.edges[v].push_back(edge(u,w));
}


//初始化图(开始时19条边，13个顶点)
inline void init(vecGraph &g){
    g.e=19;
    g.v=13;
    add_edge(g,0,4,300);
    add_edge(g,0,1,200);
    add_edge(g,1,2,580);
    add_edge(g,1,4,200);
    add_edge(g,1,9,750);
    add_edge(g,2,3,250);
    add_edge(g,3,9,740);
    add_edge(g,4,5,300);
    add_edge(g,5,6,350);
    add_edge(g,6,9,640);//10
    add_edge(g,7,8,550);
    add_edge(g,7,10,650);
    add_edge(g,7,11,630);
    add_edge(g,7,12,600);
    add_edge(g,8,9,630);
    add_edge(g,8,10,700);
    add_edge(g,8,11,700);
    add_edge(g,9,10,550);
    add_edge(g,11,12,500);
}

//最短路径求解
inline QString dijkstra(vecGraph g, int s, int t){
    QString msg1="";
    int dis[N]; //记录起点到各点的最短距离
    bool vis[N]; //标记是否已经访问
    int pre[N]; //记录最短路径的前驱节点
    std::priority_queue<std::pair<int,int>,QVector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq; //小根堆，用于实现Dijkstra算法

    memset(dis,0x3f,sizeof(dis)); //初始化距离为无穷大
    memset(vis,false,sizeof(vis)); //初始化标记为未访问
    memset(pre,-1,sizeof(pre)); //初始化前驱节点为-1

    dis[s] = 0; //起点到自己的距离为0
    pq.push(std::make_pair(0,s)); //将起点加入小根堆

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue; //如果已经访问过，则跳过
        vis[u] = true; //标记为已访问
        for(int i=0;i<g.edges[u].size();i++){
            int v = g.edges[u][i].v;
            int w = g.edges[u][i].w;
            if(dis[u] + w < dis[v]){ //如果u到v的距离小于之前的距离，则更新
                dis[v] = dis[u] + w;
                pre[v] = u;
                pq.push(std::make_pair(dis[v],v));
            }
        }
    }

    //输出结果
    if(pre[t] == -1){
        //std::cout << "没有路径可到达" << s << " to " << t;
        msg1="没有路径可到达:";
        msg1.append(QString::number(s));
        msg1.append("to");
        msg1.append(QString::number(t));
        return msg1;


    }else{

        //std::cout << "最短路径是" << s << " to " << t << ": ";
        msg1="最短路径是";
        msg1.append(QString::number(s));
        msg1.append("to");
        msg1.append(QString::number(t));
        msg1.append(":      ");

        QVector<int> path;
        int cur = t;
        while(cur != -1){
            path.push_back(cur);
            cur = pre[cur];
        }
        for(int i=path.size()-1;i>=0;i--){

            //std::cout << path[i];
            msg1.append(QString::number(path[i]));

            if(i != 0) {
                //std::cout << " -> "<<std::endl;
                msg1.append("->  ");
            }
        }
        //std::cout << ",距离= " << dis[t] << std::endl;
        msg1.append(", 距离= ");
        msg1.append(QString::number( dis[t]));
        msg1.append("米");
        return msg1;
    }
}


//求所有路径
inline void dfs(vecGraph &g, int u, int v, QVector<int> &path, QVector<QVector<int>> &paths, QVector<bool> &visited) {
    visited[u] = true;
    path.push_back(u);
    if (u == v) {
        paths.push_back(path);
    } else {
        for (int i = 0; i < g.edges[u].size(); i++) {
            int next = g.edges[u][i].v;
            if (!visited[next]) {
                dfs(g, next, v, path, paths, visited);
            }
        }
    }
    visited[u] = false;
    path.pop_back();
}

inline QVector<QVector<int>> allPaths(vecGraph &g, int u, int v) {
    QVector<int> path;
    QVector<QVector<int>> paths;
    QVector<bool> visited(g.v, false);
    dfs(g, u, v, path, paths, visited);
    return paths;
}

inline QString allroads(vecGraph g,int start,int end){
    int cnt=1;
    QString msg1="";
    QVector<QVector<int>> paths = allPaths(g, start, end);
    for (int i = 0; i < paths.size(); i++) {
        msg1.append("方案"+QString::number(cnt++)+"：");
        for (int j = 0; j < paths[i].size(); j++) {

            //std::cout << paths[i][j] << " ";
            msg1.append(QString::number(paths[i][j])+" ");
        }
        //std::cout << std::endl;
        //节省代码直接打table
       msg1.append("             ");

    }
    return msg1;
}

//更新节点路径长度
inline QString gengxin(vecGraph &g, int u, int v, int new_w){
    QString msg1;
    for(int i=0; i<g.edges[u].size(); i++){
        if(g.edges[u][i].v == v){
            g.edges[u][i].w = new_w;
            break;
        }
    }
    for(int i=0; i<g.edges[v].size(); i++){
        if(g.edges[v][i].v == u){
            g.edges[v][i].w = new_w;
            break;
        }
    }
    msg1="已完成对节点"+QString::number(u)+"——"+QString::number(v)+"的更新，更新后的路径长为:"+QString::number(new_w);
    return msg1;
}


//添加路径直接调用addedge函数


//删除路径
inline QString deleteroad(vecGraph& g, int u, int v, int w) {
    QString msg1;
    // 遍历起点u的邻接表，找到终点v并删除
    for (int i = 0; i < g.edges[u].size(); i++) {
        if (g.edges[u][i].v == v && g.edges[u][i].w == w) {
            g.edges[u].erase(g.edges[u].begin() + i);
            break;
        }
    }
    // 遍历终点v的邻接表，找到起点u并删除
    for (int i = 0; i < g.edges[v].size(); i++) {
        if (g.edges[v][i].v == u && g.edges[v][i].w == w) {
            g.edges[v].erase(g.edges[v].begin() + i);
            break;
        }
    }
    msg1="已删除节点"+QString::number(u)+"——"+QString::number(v)+"的路径";
    return msg1;
}


//添加顶点
inline QString addv(vecGraph &g){
    QString msg1;
    g.v++;
    msg1="已新增节点，当前新增节点编号为"+QString::number(g.v-1);
    return msg1;
}


//删除顶点（删除顶点时会发生顶点数的减少引发字母变化？）
inline QString deletev(vecGraph& g, int v) {
     QString msg1;
    // 遍历所有边，删除与该顶点相关的边
    for (int i = 0; i < g.v; i++) {
        if (i == v) { // 跳过该顶点
            continue;
        }
        for (int j = 0; j < g.edges[i].size(); j++) {
            if (g.edges[i][j].v == v) { // 删除与该顶点相关的边
                g.edges[i].erase(g.edges[i].begin() + j);
                break;
            }
        }
    }
    // 删除该顶点及其相关的边
    g.edges[v].clear();
    g.data[v] = 0;
    g.v--;
    // 修改与该顶点相关的边的终点编号
    for (int i = 0; i < g.v; i++) {
        for (int j = 0; j < g.edges[i].size(); j++) {
            if (g.edges[i][j].v > v) {
                g.edges[i][j].v--;
            }
        }
    }
    msg1="已删除节点"+QString::number(v);
    return msg1;
}


#endif // WIDGET_H
