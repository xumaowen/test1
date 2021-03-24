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
load ([pathname filename]);%NTU

 

[affineh affinestats]=cdfplot(reshape(ATLAS_dycoh,1,1048576));
set(affineh,'color','b','linestyle','-','linewidth',2);
 hold on;
[airh,airstats]=cdfplot(reshape(DTITK_dycoh,1,1048576));
set(airh,'color','g','linestyle','-','linewidth',2);
hold on;
[blockmatchh,blockmatchstats]=cdfplot(reshape(IIT_dycoh,1,16777216));
set(blockmatchh,'color','r','linestyle','-','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(reshape(NTU_dycoh,1,16777216));
set(bsplineh,'color','c','linestyle','-','linewidth',2);
hold on;
[bsplineh,bsplinestats]=cdfplot(reshape(W_dycoh,1,1048576));
set(bsplineh,'color','y','linestyle','-','linewidth',2);
hold on;

legend('SS1','SS2','IIT','NTU','SS3');
xlabel('Dyadic Coherence \kappa ');
ylabel('WM voxels Empircial CDF ')
% axis([0 1 0 1]);
% legend('affine','air','blockmatch','bspline','demons','dtitk','elastic','fsl','linear','rigid','syn');
hold off;



