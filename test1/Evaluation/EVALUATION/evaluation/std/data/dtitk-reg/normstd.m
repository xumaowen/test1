clear all;
clc;

[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%ATLAS
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%DTITK
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%IIT
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%NTU
[filename pathname]=uigetfile('*.mat');
load ([pathname filename]);%W

 
a=reshape(atlas_std,1,1048576)/0.3;
a=nonzeros(a);
b=reshape(dtitk_std,1,1048576)/0.3;
b=nonzeros(b);
c=reshape(W_std,1,1048576)/0.3;
c=nonzeros(c);
d=reshape(iit_std,1,16777216)/0.3;
d=nonzeros(d);
e=reshape(ntu_std,1,16777216)/0.3;
e=nonzeros(e);


[affineh affinestats]=cdfplot(a);
set(affineh,'color','b','linestyle','-','linewidth',2);
hold on;
[airh,airstats]=cdfplot(b);
set(airh,'color','g','linestyle','-','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(c);
set(bsplineh,'color','r','linestyle','-','linewidth',2);
hold on;
[blockmatchh,blockmatchstats]=cdfplot(d);
set(blockmatchh,'color','k','linestyle','--','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(e);
set(bsplineh,'color','m','linestyle','--','linewidth',2);
hold on;


xlabel('$\overline{\sigma}_{FA}$','interpreter','latex');
ylabel('WM voxels Empircial CDF ')
legend('SS1','SS2','SS3','IIT','NTU');
axis([0 1 0.73 1]);
set(gca,'xtick',[0:0.1:1]);
set(gca,'ytick',[0.73:0.027:1]);
hold off;







