clc;
clear all;
[filename pathname]=uigetfile('*.csv');
[ATR_fa]=csvread([pathname filename]);%读取affine\Genu.csv
% Arc_length vs Data	template  sub-052	sub-083	sub-328	sub-329	sub-354
% sub-383	sub-386	sub-396	sub-438	sub-439
tem=ATR_fa(3:64,2); %读取第一列数据（template）
s0=ATR_fa(3:64,3);
s1=ATR_fa(3:64,4);
s2=ATR_fa(3:64,5);
s3=ATR_fa(3:64,6);
s4=ATR_fa(3:64,7);
s5=ATR_fa(3:64,8);
s6=ATR_fa(3:64,9);
s7=ATR_fa(3:64,10);
s8=ATR_fa(3:64,11);
s9=ATR_fa(3:64,12);
S=[s0 s1 s2 s3 s4 s5 s6 s7 s8 s9];
S0=corrcoef(s0,tem); %计算subject052与template之间的相关系数
S1=corrcoef(s1,tem);
S2=corrcoef(s2,tem);
S3=corrcoef(s3,tem);
S4=corrcoef(s4,tem);
S5=corrcoef(s5,tem);
S6=corrcoef(s6,tem);
S7=corrcoef(s7,tem);
S8=corrcoef(s8,tem);
S9=corrcoef(s9,tem);
% Tem=[tem tem tem tem tem tem tem tem tem tem];
% Sa=corrcoef(S,Tem)
% Cor=[S0 S1 S2 S3 S4 S5 S6 S7 S8 S9];
Me=mean(s0+s1+s2+s3+s4+s5+s6+s7+s8+s9)/10; %计算均值
Sd=std((s0+s1+s2+s3+s4+s5+s6+s7+s8+s9)/10); %计算标准差
Corr=(S0+S1+S2+S3+S4+S5+S6+S7+S8+S9)/10; %计算平均相关系数
RES=[Me Sd Corr(2,1)];
RE=RES' %获得均值、标准差以及平均相关系数