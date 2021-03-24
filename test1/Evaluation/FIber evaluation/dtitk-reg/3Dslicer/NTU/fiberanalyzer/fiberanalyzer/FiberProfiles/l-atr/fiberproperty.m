clc;
clear all;
[filename pathname]=uigetfile('*.csv');
[genu_fa]=csvread([pathname filename]);%读取affine\fa_left-fiber-IFO.csv
% Arc_length vs Data	template  sub-052	sub-083	sub-328	sub-329	sub-354
% sub-383	sub-386	sub-396	sub-438	sub-439
Arc_Length=genu_fa(:,1);
 template=genu_fa(:,2);
 sub_052=genu_fa(:,3);%012
 sub_083=genu_fa(:,4);
 sub_328=genu_fa(:,5);
 sub_329=genu_fa(:,6);
 sub_354=genu_fa(:,7);
 sub_383=genu_fa(:,8);
 sub_386=genu_fa(:,9);
 sub_396=genu_fa(:,10);
 sub_438=genu_fa(:,11);
 sub_439=genu_fa(:,12);
 mean=(sub_052+sub_083+sub_328+sub_329+sub_354+sub_383+sub_386+sub_396+sub_438+sub_439)/10;
 
 [filename pathname]=uigetfile('*.csv');
[genu_fa1]=csvread([pathname filename]);%读取affine\fa_left-fiber-IFO.csv
% Arc_length vs Data	template  sub-052	sub-083	sub-328	sub-329	sub-354
% sub-383	sub-386	sub-396	sub-438	sub-439
% template=genu_fa1(:,2);
sub1_052=genu_fa1(:,3);%012
sub1_083=genu_fa1(:,4);
sub1_328=genu_fa1(:,5);
sub1_329=genu_fa1(:,6);
sub1_354=genu_fa1(:,7);
sub1_383=genu_fa1(:,8);
sub1_386=genu_fa1(:,9);
sub1_396=genu_fa1(:,10);
sub1_438=genu_fa1(:,11);
sub1_439=genu_fa1(:,12);
 mean1=(sub1_052+sub1_083+sub1_328+sub1_329+sub1_354+sub1_383+sub1_386+sub1_396+sub1_438+sub1_439)/10;
%plot(Arc_Length,sub_052,'b-','LineWidth',2.5);
hold on 
%plot(Arc_Length, sub_083,'m-','LineWidth',2.5);
%plot(Arc_Length,sub_328,'g-','LineWidth',2.5);
%plot(Arc_Length,sub_329,'k-','LineWidth',2.5);
%plot(Arc_Length,sub_354,'r-','LineWidth',2.5);
%plot(Arc_Length,sub_383,'b:','LineWidth',2.5);
%plot(Arc_Length,sub_386,'m:','LineWidth',2.5);
%plot(Arc_Length,sub_396,'g:','LineWidth',2.5);
%plot(Arc_Length,sub_438,'k:','LineWidth',2.5);
%plot(Arc_Length,sub_439,'r:','LineWidth',2.5);
plot(Arc_Length,template,'r-','LineWidth',2.5);
plot(Arc_Length,mean,'g-','LineWidth',2.5);
plot(Arc_Length,mean1,'b-','LineWidth',2.5);
set(gca,'ygrid','on');
   axis([-40 25 0.0 0.8]);
title('NTU','Fontname','Times New Roman','Fontsize',12);
set(gca,'ygrid','on');
%legend('template','mean subjects(DTITK-reg)','mean subjects(SyN-reg)') 
xlabel('纤维束长度（mm）');
ylabel('FA');

box on;
plot([0 0],get(gca,'YLim'),'k');
 hold off;
%text(0,0.8,'0.8000');
text(0,0.7,'0.7000');
text(0,0.6,'0.6000');
text(0,0.5,'0.5000');
text(0,0.4,'0.4000');
text(0,0.3,'0.3000');
text(0,0.2,'0.2000');
text(0,0.1,'0.1000');
text(0,0.0,'0.0000');