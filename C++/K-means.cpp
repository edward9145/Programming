#define MAXSAMPLE  50//样本个数
#define MAXCLUSTER 3
//#include <fstream.h>
#include <iostream>
#include <math.h>
struct cluster
{
 float x;
 float y;
};//样本结构
fstream infile;
int NumSample;//样本个数
int NumCluter;//聚类的个数
int SizeVector;//每个样本的维数 
struct cluster sample[MAXSAMPLE];
struct cluster center[MAXCLUSTER];
struct cluster formercenter[MAXCLUSTER];
int centernum[MAXCLUSTER]={0};//属于每一个簇的样本数
int mincenter[MAXSAMPLE];//记住每个样本属于的类名
int clusterclose=0;//算法结束
bool flag[MAXCLUSTER];//判断中心对象是否有变化
/******************************************************************************
          从给定文件中读入样本数据及相关信息
********************************************************************************/
void ReadSampleFile()
{
 infile.open("KM2.DAT",ios::in);//注意一定要读入文件，文件的第一个数据是样本个数，
                                //第2个数是簇的个数，第三个数是每个样本的维数，其余的就是数据了，可随便写
 if(!infile)
  cout<<"Can't open infile,please check!"<<endl;
 else
  cout<<"Can open infile,you can come to next step."<<endl;
 
 int i=0;
 infile>>NumSample;
 infile>>NumCluter;
    infile>>SizeVector;
  
 for(i=0;i<NumSample;i++)
    {
  
  infile >> sample[i].x;
        infile >> sample[i].y;
  
 }
 
 
    for( int j=0;j<NumSample;j++)
 { 
   cout<<sample[j].x;
   cout<<"\t";
      cout<<sample[j].y;
   cout<<endl;
   
 }
}
/***********************************************************************
          计算两个向量的距离
************************************************************************/
double cal_distance(struct cluster sample1, struct cluster sample2)
{
 double distanc;
 distanc=sqrt((sample1.x-sample2.x)*(sample1.x-sample2.x)+(sample1.y-sample2.y)*(sample1.y-sample2.y));
 return distanc;
}
/***************************************************************************
          聚类片段
****************************************************************************/
void cluster()
{
 int i,j,k;
 double min;
 double distance[MAXSAMPLE][MAXCLUSTER];
 for(i=0;i<NumSample;i++)
 {
  for(j=0;j<NumCluter;j++)//计算每个样本和中心对象的距离
   distance[i][j]=cal_distance(sample[i], center[j]);
  min=distance[i][0];
  for(k=0;k<NumCluter;k++)//从中找出距离最近的来
   if(distance[i][k]<=min)
   {
    mincenter[i]=k;//记下最小的簇类名来
    min=distance[i][k];
   }
  cout<<"第"<<i<<"个样本"<<"("<<sample[i].x <<","<<sample[i].y<<")"<<"属于第"<<mincenter[i]<<"个簇"<<endl;
  
 }

}
/***************************************************************************
          第一次随机选中心对象的聚类分析
****************************************************************************/
void RunFirstCluster()
{
 int i;
 for(i=0;i<NumCluter;i++)
 {
  center[i].x=sample[i].x;
  center[i].y=sample[i].y;
  formercenter[i].x=center[i].x;
        formercenter[i].y=center[i].y;
  mincenter[i]=i;
 }
 
 cluster();

}
/***************************************************************************
          均值为中心对象的聚类分析
****************************************************************************/
void RunCluster()
{
 int i,j;

/*************将均值点赋值为0*******************/
 for(j=0;j<NumCluter;j++)
 {
  
   center[j].x=0;
         center[j].y=0;
   centernum[j]=0;
  
 }
/*************统计出属于同一簇的样本数目********/
 for(i=0;i<NumSample;i++)
 {
  
  for(j=0;j<NumCluter;j++)
  
   if(mincenter[i]==j)
   {
   
    center[j].x+=sample[i].x;
    center[j].y+=sample[i].y;
    centernum[j]++;//计算属于j簇的样本数目
   }
 }
/*************计算新的均值点*********************/
 for(i=0;i<NumCluter;i++)
 {
  center[i].x /=centernum[i];
  center[i].y/=centernum[i];
  if((abs(formercenter[i].x-center[i].x)<0.0001)&&(abs(formercenter[i].y-center[i].y)<0.0001))
   flag[i]=true;
  else
  {
   formercenter[i].y=center[i].y;
   formercenter[i].x=center[i].x;
   flag[i]=false;
  }
  
 
  cout<<"第"<<i<<"个簇的坐标为"<<"("<<center[i].x <<","<<center[i].y<<")"<<endl;
 
 }
 
/*************重新分簇*******************/
 clusterclose=0;
 for(i=0;i<NumCluter;i++)
 {
  if(flag[i]==true)
   clusterclose+=1;
  
 }
 if(clusterclose!=NumCluter)
         cluster(); 
}
void main()
{
 ReadSampleFile();
 RunFirstCluster();
 int i=0;
 
 while(clusterclose!=NumCluter)//当每个簇的中心对象都不再变化时停止
 {
   RunCluster();
   i++;
 
 }
 cout<<"一共进行了"<<i<<"次聚类"<<endl;
}
