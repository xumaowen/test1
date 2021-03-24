clear all
clc

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

a=reshape(atlas2_alpha1,1,1048576);
a=nonzeros(a);
b=reshape(dtitk_alpha1,1,1048576);
b=nonzeros(b);
c=reshape(W_alpha1,1,1048576);
c=nonzeros(c);
d=reshape(IIT_alpha1,1,16777216);
d=nonzeros(d);
e=reshape(NTU_alpha1,1,16777216);
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
[blockmatchh,blockmatchstats]=cdfplot(c);
set(blockmatchh,'color','k','linestyle','--','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(d);
set(bsplineh,'color','m','linestyle','--','linewidth',2);
hold on;



legend('SS1','SS2','SS3','IIT','NTU');
xlabel('Angle of eigenvalue-eigenvector pairs \alpha_1');
ylabel('WM voxels Empircial CDF');
axis([0,3,0,1]);
hold off;

