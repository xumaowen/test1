clc;
clear all;
[filename pathname]=uigetfile('*.xlsx');
[ATR_fa]=xlsread([pathname filename],'A2:L336');%读取affine\Genu.csv
% Arc_length vs Data	template  sub-052	sub-083	sub-328	sub-329	sub-354
% sub-383	sub-386	sub-396	sub-438	sub-439
 Arc_Length=ATR_fa(:,1); % 读取第一列数据
 template=ATR_fa(:,2);
 sub_052=ATR_fa(:,3);
 sub_083=ATR_fa(:,4);
 sub_328=ATR_fa(:,5);
 sub_329=ATR_fa(:,6);
 sub_354=ATR_fa(:,7);
 sub_383=ATR_fa(:,8);
 sub_386=ATR_fa(:,9);
 sub_396=ATR_fa(:,10);
 sub_438=ATR_fa(:,11);
 sub_439=ATR_fa(:,12);
 mean=(sub_052+sub_083+sub_328+sub_329+sub_354+sub_383+sub_386+sub_396+sub_438+sub_439)/10;
plot(Arc_Length,sub_052,'Color',[.6 .6 .3],'LineWidth',1.5); % 绘制sub052的纤维特征曲线，颜色为[.6 .6 .3]
hold on 
plot(Arc_Length,sub_083,'m-','LineWidth',1.5);
plot(Arc_Length,sub_328,'Color',[.8 .3 .3],'LineWidth',1.5);
plot(Arc_Length,sub_329,'Color',[.3 .8 .3],'LineWidth',1.5);
plot(Arc_Length,sub_354,'Color',[.3 .8 .8]','LineWidth',1.5);
plot(Arc_Length,sub_383,'Color',[.3 .3 .8],'LineWidth',1.5);
plot(Arc_Length,sub_386,'Color',[.8 .6 .3],'LineWidth',1.5);
plot(Arc_Length,sub_396,'c-','LineWidth',1.5);
plot(Arc_Length,sub_438,'Color',[.6 .3 .6],'LineWidth',1.5);
plot(Arc_Length,sub_439,'Color',[.3 .6 .6],'LineWidth',1.5);
plot(Arc_Length,template,'k-','LineWidth',4.0);
plot(Arc_Length,mean,'r-','LineWidth',4.0); % 绘制10个受试者平均纤维特征曲线，颜色为red
set(gca,'ygrid','on');
axis([-40 40 0.2 0.75]);
title('Affine','Fontname','Times New Roman','Fontsize',12); % 设置标题
% set(gca,'ygrid','on');
% axis([-40 40 0.0 0.7]);
box on;
plot([0 0],get(gca,'YLim'),'k');
h=legend('S0','S1','S2','S3','S4','S5','S6','S7','S8','S9','Template','Mean of Subjects'); % 设置图例
set(h,'Fontname','Times New Roman','FontWeight','bold','Fontsize',16); % 设置图例属性
hold off;
text(0,0.7,'0.7000'); % 设置中线轴坐标
text(0,0.6,'0.6000');
text(0,0.5,'0.5000');
text(0,0.4,'0.4000');
text(0,0.3,'0.3000');
text(0,0.2,'0.2000');
text(0,0.1,'0.1000');
text(0,0.0,'0.0000');