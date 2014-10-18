#define MAXSAMPLE  50//��������
#define MAXCLUSTER 3
//#include <fstream.h>
#include <iostream>
#include <math.h>
struct cluster
{
 float x;
 float y;
};//�����ṹ
fstream infile;
int NumSample;//��������
int NumCluter;//����ĸ���
int SizeVector;//ÿ��������ά�� 
struct cluster sample[MAXSAMPLE];
struct cluster center[MAXCLUSTER];
struct cluster formercenter[MAXCLUSTER];
int centernum[MAXCLUSTER]={0};//����ÿһ���ص�������
int mincenter[MAXSAMPLE];//��סÿ���������ڵ�����
int clusterclose=0;//�㷨����
bool flag[MAXCLUSTER];//�ж����Ķ����Ƿ��б仯
/******************************************************************************
          �Ӹ����ļ��ж����������ݼ������Ϣ
********************************************************************************/
void ReadSampleFile()
{
 infile.open("KM2.DAT",ios::in);//ע��һ��Ҫ�����ļ����ļ��ĵ�һ������������������
                                //��2�����Ǵصĸ���������������ÿ��������ά��������ľ��������ˣ������д
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
          �������������ľ���
************************************************************************/
double cal_distance(struct cluster sample1, struct cluster sample2)
{
 double distanc;
 distanc=sqrt((sample1.x-sample2.x)*(sample1.x-sample2.x)+(sample1.y-sample2.y)*(sample1.y-sample2.y));
 return distanc;
}
/***************************************************************************
          ����Ƭ��
****************************************************************************/
void cluster()
{
 int i,j,k;
 double min;
 double distance[MAXSAMPLE][MAXCLUSTER];
 for(i=0;i<NumSample;i++)
 {
  for(j=0;j<NumCluter;j++)//����ÿ�����������Ķ���ľ���
   distance[i][j]=cal_distance(sample[i], center[j]);
  min=distance[i][0];
  for(k=0;k<NumCluter;k++)//�����ҳ������������
   if(distance[i][k]<=min)
   {
    mincenter[i]=k;//������С�Ĵ�������
    min=distance[i][k];
   }
  cout<<"��"<<i<<"������"<<"("<<sample[i].x <<","<<sample[i].y<<")"<<"���ڵ�"<<mincenter[i]<<"����"<<endl;
  
 }

}
/***************************************************************************
          ��һ�����ѡ���Ķ���ľ������
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
          ��ֵΪ���Ķ���ľ������
****************************************************************************/
void RunCluster()
{
 int i,j;

/*************����ֵ�㸳ֵΪ0*******************/
 for(j=0;j<NumCluter;j++)
 {
  
   center[j].x=0;
         center[j].y=0;
   centernum[j]=0;
  
 }
/*************ͳ�Ƴ�����ͬһ�ص�������Ŀ********/
 for(i=0;i<NumSample;i++)
 {
  
  for(j=0;j<NumCluter;j++)
  
   if(mincenter[i]==j)
   {
   
    center[j].x+=sample[i].x;
    center[j].y+=sample[i].y;
    centernum[j]++;//��������j�ص�������Ŀ
   }
 }
/*************�����µľ�ֵ��*********************/
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
  
 
  cout<<"��"<<i<<"���ص�����Ϊ"<<"("<<center[i].x <<","<<center[i].y<<")"<<endl;
 
 }
 
/*************���·ִ�*******************/
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
 
 while(clusterclose!=NumCluter)//��ÿ���ص����Ķ��󶼲��ٱ仯ʱֹͣ
 {
   RunCluster();
   i++;
 
 }
 cout<<"һ��������"<<i<<"�ξ���"<<endl;
}
