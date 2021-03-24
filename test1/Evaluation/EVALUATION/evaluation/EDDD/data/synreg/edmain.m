%clear all;
%clc


[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%ATLAS_ALPHA
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%DTITK_ALPHA
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%IIT_ALPHA
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%NTU_ALPHA
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%W
 

a=reshape(atlas_ed_dist,1,1048576)/6;
a=nonzeros(a);
b=reshape(dtitk_ed_dist,1,1048576)/6;
b=nonzeros(b);
c=reshape(W_ed_dist,1,1048576)/6;
c=nonzeros(c);
d=reshape(IIT_ed_dist,1,16777216)/6;
d=nonzeros(d);
e=reshape(NTU_ed_dist,1,16777216)/6;
e=nonzeros(e);


[affineh affinestats]=cdfplot(a);
set(affineh,'color','b','linestyle','-','linewidth',2);
hold on;
[airh,airstats]=cdfplot(b);
set(airh,'color','g','linestyle','-','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(e);
set(bsplineh,'color','r','linestyle','-','linewidth',2);
hold on;
[blockmatchh,blockmatchstats]=cdfplot(d);
set(blockmatchh,'color','k','linestyle','--','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(c);
set(bsplineh,'color','m','linestyle','--','linewidth',2);
hold on;


xlabel('Average ED to the template ');
ylabel('WM voxels Empirical CDF');
legend('SS1','SS2','SS3','IIT','NTU');
axis([0 1 0.85 1]);
set(gca,'xtick',[0:0.1:1]);
set(gca,'ytick',[0.85:0.015:1]);
hold off;



 
 