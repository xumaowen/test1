clc;
clear all;
[filename pathname]=uigetfile('*.csv');
[genu_fa]=csvread([pathname filename]);%∂¡»°affine\fa_left-fiber-IFO.csv
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
set(gca,'ygrid','on');
   axis([-45 30 0.0 0.7]);
title('DTITK','Fontname','Times New Roman','Fontsize',12);
set(gca,'ygrid','on');



box on;
plot([0 0],get(gca,'YLim'),'k');
 hold off;
%text(0,0.7,'0.7000');
text(0,0.6,'0.6000');
text(0,0.5,'0.5000');
text(0,0.4,'0.4000');
text(0,0.3,'0.3000');
text(0,0.2,'0.2000');
text(0,0.1,'0.1000');
text(0,0.0,'0.0000');